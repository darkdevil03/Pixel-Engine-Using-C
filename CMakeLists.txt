cmake_minimum_required(VERSION 3.20)
project(PixelEngine C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 1. Path to SDL3
set(SDL3_ROOT "D:/Codex/C/Pixel_Level_Programming/SDL3-devel-3.4.14-mingw/SDL3-3.4.14/x86_64-w64-mingw32")

# 2. Recursively find all .c files, excluding build directories
file(GLOB_RECURSE ALL_C_FILES CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
)
list(FILTER ALL_C_FILES EXCLUDE REGEX "${CMAKE_CURRENT_SOURCE_DIR}/cmake-build-.*")

# 3. Create one executable per source file
foreach(SOURCE_FILE ${ALL_C_FILES})
    # Get path relative to project root
    file(RELATIVE_PATH REL_FILE "${CMAKE_CURRENT_SOURCE_DIR}" "${SOURCE_FILE}")

    # Build a unique target name (e.g., "Pixel_Manipulation_ex01_pixel_manipulation_library")
    string(REGEX REPLACE "\\.c$" "" TARGET_NAME "${REL_FILE}")
    string(REGEX REPLACE "[/\\\\]" "_" TARGET_NAME "${TARGET_NAME}")

    # Create executable using relative path
    add_executable(${TARGET_NAME} "${REL_FILE}")

    # FIX: Force include path directly onto the target as a SYSTEM include
    target_include_directories(${TARGET_NAME} SYSTEM PRIVATE "${SDL3_ROOT}/include")
    target_link_directories(${TARGET_NAME} PRIVATE "${SDL3_ROOT}/lib")

    # Link SDL3
    target_link_libraries(${TARGET_NAME} PRIVATE SDL3)

    # Copy SDL3.dll next to executable after build
    add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SDL3_ROOT}/bin/SDL3.dll"
            "$<TARGET_FILE_DIR:${TARGET_NAME}>"
            COMMENT "Copying SDL3.dll to ${TARGET_NAME} output"
    )
endforeach()