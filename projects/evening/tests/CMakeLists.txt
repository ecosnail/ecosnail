add_executable (evening_test_basic
    container.cpp
    main.cpp
    subscriber.cpp
    subscription.cpp
)
target_link_libraries(evening_test_basic PRIVATE evening)
add_test (NAME evening_test_basic COMMAND evening_test_basic)
