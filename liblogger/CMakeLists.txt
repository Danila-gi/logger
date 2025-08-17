set(SOURCES src/Logger.cpp)
set(HEADERS include/Logger.h include/Logger.h)

add_library(library ${SOURCES})
target_include_directories(library PUBLIC include)