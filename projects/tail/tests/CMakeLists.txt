link_libraries (tail)

add_executable (iterator_test iterator_test.cpp)
add_test (NAME iterator_test COMMAND iterator_test)

add_executable (range_test range_test.cpp)
add_test (NAME range_test COMMAND range_test)

add_executable (traits_test traits_test.cpp)

#add_executable (vector_test vector_test.cpp)
#add_test (NAME vector_test COMMAND vector_test)
