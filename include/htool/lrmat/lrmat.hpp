#ifndef HTOOL_LRMAT_HPP
#define HTOOL_LRMAT_HPP

#include "../clustering/cluster.hpp"
#include "../types/matrix.hpp"
#include <cassert>
#include <vector>

namespace htool {

template <typename T>
class LowRankMatrix {

  protected:
    // Data member
    int rank, nr, nc;
    Matrix<T> U, V;
    std::vector<int> ir;
    std::vector<int> ic;
    int offset_i;
    int offset_j;
    double epsilon;
    unsigned int ndofperelt;

  public:
    // Constructors
    LowRankMatrix() = delete;
    LowRankMatrix(const std::vector<int> &ir0, const std::vector<int> &ic0, int rank0 = -1, double epsilon0 = 1e-3) : rank(rank0), nr(ir0.size()), nc(ic0.size()), U(ir0.size(), 1), V(1, ic0.size()), ir(ir0), ic(ic0), offset_i(0), offset_j(0), epsilon(epsilon0), ndofperelt(1) {}
    LowRankMatrix(const std::vector<int> &ir0, const std::vector<int> &ic0, int offset_i0, int offset_j0, int rank0 = -1, double epsilon0 = 1e-3) : rank(rank0), nr(ir0.size()), nc(ic0.size()), U(ir0.size(), 1), V(1, ic0.size()), ir(ir0), ic(ic0), offset_i(offset_i0), offset_j(offset_j0), epsilon(epsilon0), ndofperelt(1) {}

    // VIrtual function
    virtual void build(const IMatrix<T> &A, const VirtualCluster &t, const double *const xt, const int *const tabt, const VirtualCluster &s, const double *const xs, const int *const tabs) = 0;

    // Getters
    int nb_rows() const { return this->nr; }
    int nb_cols() const { return this->nc; }
    int rank_of() const { return this->rank; }
    std::vector<int> get_ir() const { return this->ir; }
    std::vector<int> get_ic() const { return this->ic; }
    int get_offset_i() const { return this->offset_i; }
    int get_offset_j() const { return this->offset_j; }
    T get_U(int i, int j) const { return this->U(i, j); }
    T get_V(int i, int j) const { return this->V(i, j); }
    std::vector<int> get_xr() const { return this->xr; }
    std::vector<int> get_xc() const { return this->xc; }
    std::vector<int> get_tabr() const { return this->tabr; }
    std::vector<int> get_tabc() const { return this->tabc; }
    double get_epsilon() const { return this->epsilon; }
    int get_ndofperelt() const { return this->ndofperelt; }

    void set_epsilon(double epsilon0) { this->epsilon = epsilon0; }
    void set_ndofperelt(unsigned int ndofperelt0) { this->ndofperelt = ndofperelt0; }

    std::vector<T> operator*(const std::vector<T> &a) const {
        return this->U * (this->V * a);
    }
    void mvprod(const T *const in, T *const out) const {
        if (rank == 0) {
            std::fill(out, out + nr, 0);
        } else {
            std::vector<T> a(this->rank);
            V.mvprod(in, a.data());
            U.mvprod(a.data(), out);
        }
    }

    void add_mvprod_row_major(const T *const in, T *const out, const int &mu, char transb = 'T', char op = 'N') const {
        if (rank != 0) {
            std::vector<T> a(this->rank * mu);
            if (op == 'N') {
                std::cout << "BOUH1" << std::endl;
                V.mvprod_row_major(in, a.data(), mu, transb, op);
                std::cout << "BOUH2" << std::endl;
                for (int i = 0; i < nr; i++) {
                    std::cout << out[i] << " ";
                }
                U.add_mvprod_row_major(a.data(), out, mu, transb, op);
                std::cout << "BOUH3" << std::endl;
            } else if (op == 'C' || op == 'T') {
                U.mvprod_row_major(in, a.data(), mu, transb, op);
                V.add_mvprod_row_major(a.data(), out, mu, transb, op);
            }
        }
    }

    void get_whole_matrix(T *const out) const {
        char transa = 'N';
        char transb = 'N';
        int M       = U.nb_rows();
        int N       = V.nb_cols();
        int K       = U.nb_cols();
        T alpha     = 1;
        int lda     = U.nb_rows();
        int ldb     = V.nb_rows();
        T beta      = 0;
        int ldc     = U.nb_rows();

        Blas<T>::gemm(&transa, &transb, &M, &N, &K, &alpha, &(U(0, 0)), &lda, &(V(0, 0)), &ldb, &beta, out, &ldc);
    }

    double compression() const {
        return (1 - (this->rank * (1. / double(this->nr) + 1. / double(this->nc))));
    }

    friend std::ostream &operator<<(std::ostream &os, const LowRankMatrix &m) {
        os << "rank:\t" << m.rank << std::endl;
        os << "nr:\t" << m.nr << std::endl;
        os << "nc:\t" << m.nc << std::endl;
        os << "U:\n";
        os << m.U << std::endl;
        os << m.V << std::endl;

        return os;
    }
};

template <typename T>
double Frobenius_relative_error(const LowRankMatrix<T> &lrmat, const IMatrix<T> &ref, int reqrank = -1) {
    assert(reqrank <= lrmat.rank_of());
    if (reqrank == -1) {
        reqrank = lrmat.rank_of();
    }
    T norm              = 0;
    T err               = 0;
    std::vector<int> ir = lrmat.get_ir();
    std::vector<int> ic = lrmat.get_ic();

    for (int j = 0; j < lrmat.nb_rows(); j++) {
        for (int k = 0; k < lrmat.nb_cols(); k++) {
            T aux;
            ref.copy_submatrix(1, 1, &(ir[j]), &(ic[k]), &aux);
            norm += std::pow(std::abs(aux), 2);
            for (int l = 0; l < reqrank; l++) {
                aux = aux - lrmat.get_U(j, l) * lrmat.get_V(l, k);
            }
            err += std::pow(std::abs(aux), 2);
        }
    }
    err = err / norm;
    return std::sqrt(err);
}

template <typename T>
double Frobenius_absolute_error(const LowRankMatrix<T> &lrmat, const IMatrix<T> &ref, int reqrank = -1) {
    assert(reqrank <= lrmat.rank_of());
    if (reqrank == -1) {
        reqrank = lrmat.rank_of();
    }
    T err               = 0;
    std::vector<int> ir = lrmat.get_ir();
    std::vector<int> ic = lrmat.get_ic();

    for (int j = 0; j < lrmat.nb_rows(); j++) {
        for (int k = 0; k < lrmat.nb_cols(); k++) {
            T aux;
            ref.copy_submatrix(1, 1, &(ir[j]), &(ic[k]), &aux);
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
