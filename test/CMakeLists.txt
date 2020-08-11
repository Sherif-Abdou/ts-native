# see https://cmake.org/cmake/help/latest/module/FindBoost.html
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

include_directories(${Boost_INCLUDE_DIR}
        ${TLIB_INCLUDE_DIR}
        )
# Note: a target should be already defined using 'add_executable' or 'add_library'
add_executable(typescript_native_tests lexer_tests.cpp parser_tests.cpp main.cpp)
target_link_libraries(typescript_native_tests TLIB
        ${Boost_LIBRARIES}
        )
