cmake_minimum_required(VERSION 4.2)
project(PixelEngine C)

set(CMAKE_C_STANDARD 23)

# 1. Point CMake to your 64-bit MinGW folder inside your SDL3 path
list(APPEND CMAKE_PREFIX_PATH "D:/Codex/C/Pixel_Level_Programming/SDL3-devel-3.4.14-mingw/SDL3-3.4.14/x86_64-w64-mingw32")

# 2. Locate the official SDL3 package target
find_package(SDL3 REQUIRED)

# 3. Find all .c source files in your project directory
file(GLOB ALL_C_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

# 4. Loop through every .c file and automatically create a separate executable
foreach(SOURCE_FILE ${ALL_C_FILES})
    # Extract filename without extension (e.g., "demo1.c" becomes target "demo1")
    get_filename_component(TARGET_NAME ${SOURCE_FILE} NAME_WE)

    # Automatically declare executable for this file
    add_executable(${TARGET_NAME} ${SOURCE_FILE})

    # Link SDL3 automatically
    target_link_libraries(${TARGET_NAME} PRIVATE SDL3::SDL3)

    # Automatically copy SDL3.dll to output folder for each generated target
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "$<TARGET_FILE_DIR:SDL3::SDL3>/SDL3.dll"
            "$<TARGET_FILE_DIR:${TARGET_NAME}>"
    )
endforeach()