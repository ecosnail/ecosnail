link_libraries (evening)

add_executable (evening_test_basic
    container.cpp
    main.cpp
    subscriber.cpp
    subscription.cpp
)
add_test (NAME evening_test_basic COMMAND evening_test_basic)
