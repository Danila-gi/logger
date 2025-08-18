include_directories("include")

add_executable(logger src/main.cpp src/Application.cpp src/Console.cpp)
target_link_libraries(logger PRIVATE library)

add_executable(logger_test test/test_main.cpp src/Application.cpp src/Console.cpp test/Test.cpp)
target_link_libraries(logger_test PRIVATE library)

add_executable(server src/server.cpp)