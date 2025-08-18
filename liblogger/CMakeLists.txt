set(SOURCES src/Logger.cpp src/LoggerFile.cpp src/LoggerSocket.cpp)
set(HEADERS include/Logger.h include/LoggerFile.h include/LoggerSocket.h include/Severity.h)

add_library(library ${SOURCES})
target_include_directories(library PUBLIC include)