project(bootstrappercpp)

add_definitions(-DCPPCODEGEN)

set(SOURCES
    ../main.cpp
    ../common.cpp
)

if(CLR_CMAKE_PLATFORM_UNIX)
    list(APPEND SOURCES
        ../platform.unix.cpp)
endif()

add_library(bootstrappercpp STATIC ${SOURCES})

# Install the static bootstrappercpp library
install (TARGETS bootstrappercpp DESTINATION lib)
