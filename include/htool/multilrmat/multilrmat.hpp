#ifndef HTOOL_MULTI_LRMAT_HPP
#define HTOOL_MULTI_LRMAT_HPP

#include "../clustering/cluster.hpp"
#include "../lrmat/barelrmat.hpp"
#include "../types/multimatrix.hpp"
#include <vector>
namespace htool {

template <typename T>
class MultiLowRankMatrix {

  protected:
    // Data member
    int rank, nr, nc, nm;
    // Matrix<T>  U,V;
    std::vector<bareLowRankMatrix<T>> LowRankMatrices;
    std::vector<int> ir;
    std::vector<int> ic;
    int offset_i;
    int offset_j;

    double epsilon;
    unsigned int ndofperelt;

  public:
    // Constructors
    MultiLowRankMatrix() = delete;
    MultiLowRankMatrix(const std::vector<int> &ir0, const std::vector<int> &ic0, int nm0, int rank0 = -1, double epsilon0 = 1e-3) : rank(rank0), nr(ir0.size()), nc(ic0.size()), nm(nm0), ir(ir0), ic(ic0), offset_i(0), offset_j(0), epsilon(epsilon0), ndofperelt(1) {
        for (int l = 0; l < nm; l++) {
            LowRankMatrices.emplace_back(ir, ic, offset_i, offset_j, rank0, epsilon);
        }
    }
    MultiLowRankMatrix(const std::vector<int> &ir0, const std::vector<int> &ic0, int nm0, int offset_i0, int offset_j0, int rank0 = -1, double epsilon0 = 1e-3) : rank(rank0), nr(ir0.size()), nc(ic0.size()), nm(nm0), ir(ir0), ic(ic0), offset_i(offset_i0), offset_j(offset_j0), epsilon(epsilon0), ndofperelt(1) {
        for (int l = 0; l < nm; l++) {
            LowRankMatrices.emplace_back(ir, ic, offset_i, offset_j, rank0, epsilon);
        }
    }

    // VIrtual function
    virtual void build(const MultiIMatrix<T> &A, const VirtualCluster &t, const double *const xt, const int *const tabt, const VirtualCluster &s, const double *const xs, const int *const tabs) = 0;

    // Getters
    int nb_rows() const { return this->nr; }
    int nb_cols() const { return this->nc; }
    int nb_lrmats() const { return this->nm; }
    int rank_of() const { return this->rank; }
    std::vector<int> get_ir() const { return this->ir; }
    std::vector<int> get_ic() const { return this->ic; }
    int get_offset_i() const { return this->offset_i; }
    int get_offset_j() const { return this->offset_j; }
    double get_epsilon() const { return this->epsilon; }
    int get_ndofperelt() const { return this->ndofperelt; }

    void set_epsilon(double epsilon0) { this->epsilon = epsilon0; }
    void set_ndofperelt(unsigned int ndofperelt0) { this->ndofperelt = ndofperelt0; }

    bareLowRankMatrix<T> &operator[](int j) { return LowRankMatrices[j]; };
    const bareLowRankMatrix<T> &operator[](int j) const { return LowRankMatrices[j]; };
};

template <typename T>
std::vector<double> Frobenius_absolute_error(const MultiLowRankMatrix<T> &lrmat, const MultiIMatrix<T> &ref, int reqrank = -1) {
    assert(reqrank <= lrmat[0].rank_of());
    if (reqrank == -1) {
        reqrank = lrmat[0].rank_of();
    }
    std::vector<T> err(lrmat.nb_lrmats(), 0);
    std::vector<int> ir = lrmat.get_ir();
    std::vector<int> ic = lrmat.get_ic();
    std::vector<T> aux(lrmat.nb_lrmats());

    for (int j = 0; j < lrmat.nb_rows(); j++) {
        for (int k = 0; k < lrmat.nb_cols(); k++) {
            aux = ref.get_coefs(ir[j], ic[k]);
            for (int l = 0; l < lrmat.nb_lrmats(); l++) {
                for (int r = 0; r < reqrank; r++) {
                    aux[l] = aux[l] - lrmat[l].get_U(j, r) * lrmat[l].get_V(r, k);
                }
                err[l] += std::pow(std::abs(aux[l]), 2);
            }
        }
    }

    std::transform(err.begin(), err.end(), err.begin(), (double (*)(double))sqrt);
    return err;
}

template <typename T>
std::vector<double> Frobenius_absolute_error(const MultiLowRankMatrix<std::complex<T>> &lrmat, const MultiIMatrix<std::complex<T>> &ref, int reqrank = -1) {
    assert(reqrank <= lrmat[0].rank_of());

    std::vector<T> err(lrmat.nb_lrmats(), 0);
    std::vector<int> ir = lrmat.get_ir();
    std::vector<int> ic = lrmat.get_ic();
    std::vector<std::complex<T>> aux(lrmat.nb_lrmats());
    for (int j = 0; j < lrmat.nb_rows(); j++) {
        for (int k = 0; k < lrmat.nb_cols(); k++) {
            aux = ref.get_coefs(ir[j], ic[k]);
            for (int l = 0; l < lrmat.nb_lrmats(); l++) {
                if (reqrank == -1) {
                    reqrank = lrmat.rank_of();
                }
                for (int r = 0; r < reqrank; r++) {
                    aux[l] = aux[l] - lrmat[l].get_U(j, r) * lrmat[l].get_V(r, k);
                }
                err[l] += std::pow(std::abs(aux[l]), 2);
            }
        }
    }

    std::transform(err.begin(), err.end(), err.begin(), (double (*)(double))sqrt);
    return err;
}

template <typename T>
double Frobenius_absolute_error(const LowRankMatrix<std::complex<T>> &lrmat, const IMatrix<std::complex<T>> &ref, int reqrank = -1) {
    assert(reqrank <= lrmat.rank_of());
    if (reqrank == -1) {
        reqrank = lrmat.rank_of();
    }
    T err               = 0;
    std::vector<int> ir = lrmat.get_ir();
    std::vector<int> ic = lrmat.get_ic();

    for (int j = 0; j < lrmat.nb_rows(); j++) {
        for (int k = 0; k < lrmat.nb_cols(); k++) {
            std::complex<T> aux = ref.get_coef(ir[j], ic[k]);
            for (int l = 0; l < reqrank; l++) {
                aux = aux - lrmat.get_U(j, l) * lrmat.get_V(l, k);
            }
            err += std::pow(std::abs(aux), 2);
        }
    }
    return std::sqrt(err);
}

template <typename T>
double Frobenius_absolute_error(const LowRankMatrix<T> &lrmat, const MultiIMatrix<T> &ref, int l, int reqrank = -1) {
    assert(reqrank <= lrmat.rank_of());
    if (reqrank == -1) {
        reqrank = lrmat.rank_of();
    }
    T err               = 0;
    std::vector<int> ir = lrmat.get_ir();
    std::vector<int> ic = lrmat.get_ic();

    for (int j = 0; j < lrmat.nb_rows(); j++) {
        for (int k = 0; k < lrmat.nb_cols(); k++) {
            T aux = ref.get_coefs(ir[j], ic[k])[l];
            for (int l = 0; l < reqrank; l++) {
                aux = aux - lrmat.get_U(j, l) * lrmat.get_V(l, k);
            }
            err += std::pow(std::abs(aux), 2);
        }
    }
    return std::sqrt(err);
}

template <typename T>
double Frobenius_absolute_error(const LowRankMatrix<std::complex<T>> &lrmat, const MultiIMatrix<std::complex<T>> &ref, int l, int reqrank = -1) {
    assert(reqrank <= lrmat.rank_of());
    if (reqrank == -1) {
        reqrank = lrmat.rank_of();
    }
    T err               = 0;
    std::vector<int> ir = lrmat.get_ir();
    std::vector<int> ic = lrmat.get_ic();

    for (int j = 0; j < lrmat.nb_rows(); j++) {
        for (int k = 0; k < lrmat.nb_cols(); k++) {
            std::complex<T> aux = ref.get_coefs(ir[j], ic[k])[l];
            for (int l = 0; l < reqrank; l++) {
                aux = aux - lrmat.get_U(j, l) * lrmat.get_V(l, k);
            }
            err += std::pow(std::abs(aux), 2);
        }
    }
    return std::sqrt(err);
}

} // namespace htool

#endif
