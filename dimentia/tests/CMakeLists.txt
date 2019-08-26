link_libraries (dimentia)

add_executable (dimentia_test_basic basic.cpp)
add_test (NAME dimentia_test_basic COMMAND dimentia_test_basic)

add_executable (dimentia_test_result_types result_types.cpp)
add_test (NAME dimentia_test_result_types COMMAND dimentia_test_result_types)
