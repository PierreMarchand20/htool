import numpy as np
from htool_ import ComplexHMatrix
from scipy.sparse.linalg import gmres
from mpi4py import MPI
import math
import struct
import os

def python_gmres_get_coef():

    comm = MPI.COMM_WORLD
    size = comm.Get_size()
    rank = comm.Get_rank()

    # Matrix
    with open(os.path.join(os.path.dirname(__file__)+"/../data/data_test/SPD_mat_example.bin"), "rb" ) as input:
        data=input.read()
        (m, n) = struct.unpack("@II", data[:8])
        # print(m,n)
        A=np.frombuffer(data[8:],dtype=np.dtype('complex128'))
        A=np.transpose(A.reshape((m,n)))


    # Right-hand side
    with open(os.path.join(os.path.dirname(__file__)+"/../data/data_test/rhs.bin"), "rb" ) as input:
        data=input.read()
        l = struct.unpack("@I", data[:4])
        f=np.frombuffer(data[4:],dtype=np.dtype('complex128'))

    # mesh
    p=np.zeros((n,3))
    with open(os.path.join(os.path.dirname(__file__)+"/../data/data_test/gmsh_mesh.msh"), "r" ) as input:
        check=False
        count=0
        for line in input:
            print(line,check)

            if line=="$EndNodes\n":
                break

            if check and len(line.split())==4:
                print(line.split())
                tab_line=line.split()
                p[count][0]=tab_line[1]
                p[count][1]=tab_line[2]
                p[count][2]=tab_line[3]
                count+=1

            if line=="$Nodes\n":
                check=True


    # Hmatrix
    def get_coef(i, j, coef):
        coef[0] = A[i][j].real
        coef[1] = A[i][j].imag

    H = ComplexHMatrix.from_coefs(p, get_coef, epsilon=1e-6, eta=0.1, minclustersize=1)

    # Global vectors
    with open(os.path.join(os.path.dirname(__file__)+"/../data/data_test/sol.bin"), "rb" ) as input:
        data=input.read()
        x_ref=np.frombuffer(data[4:],dtype=np.dtype('complex128'))

    # Solve
    x, _ = gmres(H, f,tol=1e-6)

    # Output
    H.print_infos()

    # Error on inversions
    inv_error = np.linalg.norm(f-A.dot(x))/np.linalg.norm(f)
    error     = np.linalg.norm(x-x_ref)/np.linalg.norm(x_ref)

    if (rank==0):
        print("error on inversion : ",inv_error)
        print("error on solution : ",error)

    assert(inv_error<1e-6)
    assert(error<1e-5)


def test_python_gmres():
    python_gmres_get_coef()
