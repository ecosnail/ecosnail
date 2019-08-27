macro(ecosnail_project)
    set(options HEADER_ONLY)
    set(oneValueArgs CXX)
    set(multiValueArgs DEPENDS SOURCES)
    cmake_parse_arguments(
        ARGS
        "${options}"
        "${oneValueArgs}"
        "${multiValueArgs}"
        ${ARGN}
    )

    get_filename_component(ARGS_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
    project(${ARGS_NAME})

    if(ARGS_UNPARSED_ARGUMENTS)
        message(SEND_ERROR "Unrecognized arguments to ecosnail_project() in '${ARGS_NAME}' project: ${ARGS_UNPARSED_ARGUMENTS}")
    endif()

    if(ARGS_CXX)
        set(CMAKE_CXX_STANDARD ${ARGS_CXX})
        set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
    endif()

    if(ARGS_SOURCES)
        add_library(${ARGS_NAME} ${ARGS_SOURCES})
        target_include_directories(${ARGS_NAME} PUBLIC include)
        if(ARGS_DEPENDS)
            target_link_libraries(${ARGS_NAME} PUBLIC ${ARGS_DEPENDS})
        endif()
    elseif(ARGS_HEADER_ONLY)
        add_library(${ARGS_NAME} INTERFACE)
        target_include_directories(${ARGS_NAME} INTERFACE include)
        if(ARGS_DEPENDS)
            target_link_libraries(${ARGS_NAME} INTERFACE ${ARGS_DEPENDS})
        endif()
    else()
        message(SEND_ERROR "Specify either SOURCES or HEADER_ONLY in ecosnail_project()")
    endif()

    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/examples)
        add_subdirectory(examples)
    else()
        message(AUTHOR_WARNING "Project '${ARGS_NAME}' has no examples")
    endif()

    if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests)
        add_subdirectory(tests)
    else()
        message(AUTHOR_WARNING "Project '${ARGS_NAME}' has no tests")
    endif()
endmacro()

macro(ecosnail_test NAME)
    set(test_name ecosnail_${PROJECT_NAME}_test_${NAME})
    add_executable(${test_name} ${NAME}.cpp)
    target_link_libraries(${test_name} PRIVATE ${PROJECT_NAME})
    add_test(NAME ${test_name} COMMAND ${test_name})
endmacro()

macro(ecosnail_example NAME)
    set(example_name ecosnail_${PROJECT_NAME}_example_${NAME})
    add_executable(${example_name} ${NAME}.cpp)
    target_link_libraries(${example_name} PRIVATE ${PROJECT_NAME})
endmacro()
