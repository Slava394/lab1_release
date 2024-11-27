include(CTest)

set(TEST_FILES
    unit_test/shared_test.hpp
    unit_test/weak_test.hpp
    unit_test/unique_test.hpp
)

find_program(CXXTESTGEN_EXECUTABLE cxxtestgen REQUIRED)

if(NOT CXXTESTGEN_EXECUTABLE)
    message(FATAL_ERROR "Install CxxTest!")
endif()

set(TEST_TARGETS)

foreach(TEST_FILE IN LISTS TEST_FILES)
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    set(GENERATED_FILE ${CMAKE_CURRENT_BINARY_DIR}/${TEST_NAME}.cpp)
    add_custom_command(
        OUTPUT ${GENERATED_FILE}
        COMMAND ${CXXTESTGEN_EXECUTABLE} --error-printer -o ${GENERATED_FILE} ${CMAKE_CURRENT_SOURCE_DIR}/${TEST_FILE}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${TEST_FILE}
        COMMENT "Generation ${TEST_NAME}.cpp"
    )
    add_executable(${TEST_NAME} ${GENERATED_FILE})
    target_include_directories(${TEST_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    list(APPEND TEST_TARGETS ${TEST_NAME})
    add_test(NAME ${TEST_NAME} COMMAND ${CMAKE_CURRENT_BINARY_DIR}/${TEST_NAME})
endforeach()
#типо крутая фича
add_custom_target(run_all_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS ${TEST_TARGETS}
    COMMENT "Run all tests"
)

add_executable(load_test load_test/load_test.cpp)

find_package(Boost REQUIRED COMPONENTS iostreams)

if(Boost_FOUND)
    target_include_directories(load_test PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(load_test PRIVATE ${Boost_LIBRARIES})
else()
    message(FATAL_ERROR "Install Boost!")
endif()