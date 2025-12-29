cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME "")

# Set up root path
cmake_path(GET CMAKE_CURRENT_SOURCE_DIR PARENT_PATH ROOT_DIR)
cmake_path(GET CMAKE_CURRENT_SOURCE_DIR FILENAME PROJECT_DIR_NAME)

if(PROJECT_DIR_NAME STREQUAL "zzz-template")
    message(FATAL_ERROR "\nThis CMake project is only a template.\nOnly use to copy into a new project as a starting point.")
endif()

if(PROJECT_NAME STREQUAL "")
    message(FATAL_ERROR "\nPROJECT_NAME is not set.")
endif()

project(${PROJECT_NAME} LANGUAGES C)

#set(CMAKE_VERBOSE_MAKEFILE ON)

# Set C flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wall -Wextra -pedantic -Werror -std=c2x -Wno-gnu-binary-literal -std=c99 -fPIE -m64")

# Platform-specific assembler setup
if(MSVC)
    # Use MASM for Windows/MSVC
    set(ASM_SRC "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.asm")
    set(ASM_OBJ "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.obj")
    add_custom_command(
        OUTPUT ${ASM_OBJ}
        COMMAND ml64 /Fo ${ASM_OBJ} /c ${ASM_SRC}
        DEPENDS ${ASM_SRC}
        COMMENT "Assembling ${PROJECT_NAME}.asm with MASM"
    )
else()
    # Use NASM for Unix-like systems
    if(APPLE)
        if(CMAKE_SYSTEM_PROCESSOR STREQUAL "arm64")
            set(CMAKE_OSX_ARCHITECTURES x86_64)
            set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -target x86_64-apple-darwin")
        endif()

        set(NASM_FORMAT macho64)
        set(NASM_PREFIX --prefix _)
        #set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-pie")
    elseif(UNIX)
        set(NASM_FORMAT elf64)
        set(NASM_PREFIX)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pie -Wl,--fatal-warnings")
    endif()

    set(ASM_SRC "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}.asm")
    set(ASM_OBJ "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.o")
    add_custom_command(
        OUTPUT ${ASM_OBJ}
        COMMAND nasm -f ${NASM_FORMAT} ${NASM_PREFIX} -g -F dwarf -Werror -o ${ASM_OBJ} ${ASM_SRC}
        DEPENDS ${ASM_SRC}
        COMMENT "Assembling ${PROJECT_NAME}.asm with NASM"
    )
endif()

add_custom_target(asm_objects DEPENDS ${ASM_OBJ})

# Add executable and output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(tests
    tests.c
    ${ROOT_DIR}/vendor/unity.c
)

add_dependencies(tests asm_objects)
target_include_directories(tests PRIVATE ${ROOT_DIR})
target_link_options(tests PRIVATE ${CMAKE_EXE_LINKER_FLAGS})

# Link the assembly object file
if(MSVC)
    target_link_libraries(tests PRIVATE ${ASM_OBJ})
else()
    target_link_libraries(tests PRIVATE ${ASM_OBJ})
endif()
