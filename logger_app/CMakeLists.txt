add_executable(logger main.cpp src/Application.cpp src/Console.cpp)
include_directories("include")
target_link_libraries(logger PRIVATE library)