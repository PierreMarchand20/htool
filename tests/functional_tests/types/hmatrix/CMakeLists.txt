#=============================================================================#
#=========================== Executables =====================================#
#=============================================================================#

add_executable(Test_hmat_cluster test_hmat_cluster.cpp)
target_link_libraries(Test_hmat_cluster htool)
add_dependencies(build-tests Test_hmat_cluster)
add_test(NAME Test_hmat_cluster_1 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 1 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_cluster)
add_test(NAME Test_hmat_cluster_2 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 2 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_cluster)
add_test(NAME Test_hmat_cluster_4 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 4 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_cluster)

#=== hmat_vec_prod
add_executable(Test_hmat_vec_prod test_hmat_vec_prod.cpp)
target_link_libraries(Test_hmat_vec_prod htool)
add_dependencies(build-tests Test_hmat_vec_prod)
add_test(NAME Test_hmat_vec_prod_1 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 1 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_vec_prod)
add_test(NAME Test_hmat_vec_prod_2 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 2 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_vec_prod)
add_test(NAME Test_hmat_vec_prod_3 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 3 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_vec_prod)
add_test(NAME Test_hmat_vec_prod_4 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 4 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_vec_prod)

add_executable(Test_hmat_symmetry_double_vec_prod test_hmat_symmetry_double_vec_prod.cpp)
target_link_libraries(Test_hmat_symmetry_double_vec_prod htool)
add_dependencies(build-tests Test_hmat_symmetry_double_vec_prod)
add_test(NAME Test_hmat_symmetry_double_vec_prod_1 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 1 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_symmetry_double_vec_prod)
add_test(NAME Test_hmat_symmetry_double_vec_prod_2 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 2 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_symmetry_double_vec_prod)
add_test(NAME Test_hmat_symmetry_double_vec_prod_3 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 3 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_symmetry_double_vec_prod)
add_test(NAME Test_hmat_symmetry_double_vec_prod_4 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 4 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_symmetry_double_vec_prod)

add_executable(Test_hmat_symmetry_complex_vec_prod test_hmat_symmetry_complex_vec_prod.cpp)
target_link_libraries(Test_hmat_symmetry_complex_vec_prod htool)
add_dependencies(build-tests Test_hmat_symmetry_complex_vec_prod)
add_test(NAME Test_hmat_symmetry_complex_vec_prod_1 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 1 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_symmetry_complex_vec_prod)
add_test(NAME Test_hmat_symmetry_complex_vec_prod_2 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 2 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_symmetry_complex_vec_prod)
add_test(NAME Test_hmat_symmetry_complex_vec_prod_3 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 3 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_symmetry_complex_vec_prod)
add_test(NAME Test_hmat_symmetry_complex_vec_prod_4 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 4 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_symmetry_complex_vec_prod)

add_executable(Test_hmat_hermitian_vec_prod test_hmat_hermitian_vec_prod.cpp)
target_link_libraries(Test_hmat_hermitian_vec_prod htool)
add_dependencies(build-tests Test_hmat_hermitian_vec_prod)
add_test(NAME Test_hmat_hermitian_vec_prod_1 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 1 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_hermitian_vec_prod)
add_test(NAME Test_hmat_hermitian_vec_prod_2 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 2 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_hermitian_vec_prod)
add_test(NAME Test_hmat_hermitian_vec_prod_3 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 3 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_hermitian_vec_prod)
add_test(NAME Test_hmat_hermitian_vec_prod_4 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 4 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_hermitian_vec_prod)

#=== hmat_mat_prod
add_executable(Test_hmat_mat_prod test_hmat_mat_prod.cpp)
target_link_libraries(Test_hmat_mat_prod htool)
add_dependencies(build-tests Test_hmat_mat_prod)
add_test(NAME Test_hmat_mat_prod_1 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 1 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_mat_prod)
add_test(NAME Test_hmat_mat_prod_2 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 2 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_mat_prod)
add_test(NAME Test_hmat_mat_prod_3 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 3 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_mat_prod)
add_test(NAME Test_hmat_mat_prod_4 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 4 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_mat_prod)

add_executable(Test_hmat_symmetry_double_mat_prod test_hmat_symmetry_double_mat_prod.cpp)
target_link_libraries(Test_hmat_symmetry_double_mat_prod htool)
add_dependencies(build-tests Test_hmat_symmetry_double_mat_prod)
add_test(NAME Test_hmat_symmetry_double_mat_prod_1 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 1 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_symmetry_double_mat_prod)
add_test(NAME Test_hmat_symmetry_double_mat_prod_2 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 2 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_symmetry_double_mat_prod)
add_test(NAME Test_hmat_symmetry_double_mat_prod_3 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 3 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_symmetry_double_mat_prod)
add_test(NAME Test_hmat_symmetry_double_mat_prod_4 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 4 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_symmetry_double_mat_prod)

add_executable(Test_hmat_symmetry_complex_mat_prod test_hmat_symmetry_complex_mat_prod.cpp)
target_link_libraries(Test_hmat_symmetry_complex_mat_prod htool)
add_dependencies(build-tests Test_hmat_symmetry_complex_mat_prod)
add_test(NAME Test_hmat_symmetry_complex_mat_prod_1 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 1 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_symmetry_complex_mat_prod)
add_test(NAME Test_hmat_symmetry_complex_mat_prod_2 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 2 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_symmetry_complex_mat_prod)
add_test(NAME Test_hmat_symmetry_complex_mat_prod_3 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 3 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_symmetry_complex_mat_prod)
add_test(NAME Test_hmat_symmetry_complex_mat_prod_4 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 4 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_symmetry_complex_mat_prod)

add_executable(Test_hmat_hermitian_mat_prod test_hmat_hermitian_mat_prod.cpp)
target_link_libraries(Test_hmat_hermitian_mat_prod htool)
add_dependencies(build-tests Test_hmat_hermitian_mat_prod)
add_test(NAME Test_hmat_hermitian_mat_prod_1 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 1 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_hermitian_mat_prod)
add_test(NAME Test_hmat_hermitian_mat_prod_2 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 2 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_hermitian_mat_prod)
add_test(NAME Test_hmat_hermitian_mat_prod_3 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 3 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_hermitian_mat_prod)
add_test(NAME Test_hmat_hermitian_mat_prod_4 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 4 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_hermitian_mat_prod)

#=== hmat_to_dense
add_executable(Test_hmat_to_dense test_hmat_to_dense.cpp)
target_link_libraries(Test_hmat_to_dense htool)
add_dependencies(build-tests Test_hmat_to_dense)
add_test(NAME Test_hmat_to_dense_1 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 1 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_to_dense)
add_test(NAME Test_hmat_to_dense_2 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 2 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_to_dense)
add_test(NAME Test_hmat_to_dense_3 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 3 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_to_dense)
add_test(NAME Test_hmat_to_dense_4 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 4 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_to_dense)

add_executable(Test_hmat_to_dense_perm test_hmat_to_dense_perm.cpp)
target_link_libraries(Test_hmat_to_dense_perm htool)
add_dependencies(build-tests Test_hmat_to_dense_perm)
add_test(NAME Test_hmat_to_dense_perm_1 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 1 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_to_dense_perm)
add_test(NAME Test_hmat_to_dense_perm_2 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 2 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_to_dense_perm)
add_test(NAME Test_hmat_to_dense_perm_3 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 3 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_to_dense_perm)
add_test(NAME Test_hmat_to_dense_perm_4 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 4 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_to_dense_perm)

#=== hmat_save
add_executable(Test_hmat_save test_hmat_save.cpp)
target_link_libraries(Test_hmat_save htool)
add_dependencies(build-tests Test_hmat_save)
add_test(NAME Test_hmat_save COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 1 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_save)

#=== local get
add_executable(Test_hmat_local_get test_hmat_local_get.cpp)
target_link_libraries(Test_hmat_local_get htool)
add_dependencies(build-tests Test_hmat_local_get)
add_test(NAME Test_hmat_local_get_1 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 1 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_local_get)
add_test(NAME Test_hmat_local_get_2 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 2 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_local_get)
add_test(NAME Test_hmat_local_get_3 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 3 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_local_get)
add_test(NAME Test_hmat_local_get_4 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 4 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_local_get)

#=== local get
add_executable(Test_hmat_permutation test_hmat_permutation.cpp)
target_link_libraries(Test_hmat_permutation htool)
add_dependencies(build-tests Test_hmat_permutation)
add_test(NAME Test_hmat_permutation_1 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 1 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_permutation)
add_test(NAME Test_hmat_permutation_2 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 2 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_permutation)
add_test(NAME Test_hmat_permutation_3 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 3 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_permutation)
add_test(NAME Test_hmat_permutation_4 COMMAND ${MPIEXEC} ${MPIEXEC_NUMPROC_FLAG} 4 ${MPIEXEC_PREFLAGS} ${CMAKE_CURRENT_BINARY_DIR}/Test_hmat_permutation)
