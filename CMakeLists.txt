# CMakeList.txt : CMake project for ProjectENT, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.28)
set(CMAKE_CXX_STANDARD 20)
project ("ProjectEntertain")
add_definitions(-DSOURCE_DIR="${CMAKE_SOURCE_DIR}")


file(GLOB_RECURSE SOURCES_ACTIVE
    ${CMAKE_SOURCE_DIR}/src/*.cpp
    ${CMAKE_SOURCE_DIR}/src/*.c
    ${CMAKE_SOURCE_DIR}/src/*.h
)
message(STATUS "Active Sources: ${SOURCES_ACTIVE}")
add_executable(ProjectEntertain ${SOURCES_ACTIVE})
set_target_properties(ProjectEntertain PROPERTIES LINKER_LANGUAGE CXX)


find_package(Vulkan REQUIRED)
target_link_libraries(ProjectEntertain  Vulkan::Vulkan )


# Define the base directory (in this case "dd")
set(spirDir "${CMAKE_SOURCE_DIR}/external/spirvCross")
# Add the include directory
#include_directories("${spirDir}/include/spirv_cross")
target_include_directories(ProjectEntertain PRIVATE "${spirDir}/include/spirv_cross")
# Add the library directory
link_directories("${spirDir}/lib")
# Specify the binary directory (optional, for executables)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${spirDir}/bin")
# Link against a specific library (for example: spirv-cross-reflect)
#  linking multiple SPIRV-Cross libraries (spirv-cross-c-shared.lib, spirv-cross-c.lib, etc.). Some of these may overlap in functionality, leading to symbol redefinitions or other compatibility issues.
#target_link_libraries(ProjectEntertain "${spirDir}/lib/spirv-cross-c-shared.lib")
target_link_libraries(ProjectEntertain "${spirDir}/lib/spirv-cross-c.lib")
target_link_libraries(ProjectEntertain "${spirDir}/lib/spirv-cross-core.lib")
target_link_libraries(ProjectEntertain "${spirDir}/lib/spirv-cross-cpp.lib")
target_link_libraries(ProjectEntertain "${spirDir}/lib/spirv-cross-glsl.lib")
target_link_libraries(ProjectEntertain "${spirDir}/lib/spirv-cross-hlsl.lib")
target_link_libraries(ProjectEntertain "${spirDir}/lib/spirv-cross-msl.lib")
target_link_libraries(ProjectEntertain "${spirDir}/lib/spirv-cross-reflect.lib")
target_link_libraries(ProjectEntertain "${spirDir}/lib/spirv-cross-util.lib")



if(Vulkan_FOUND)
    message(STATUS "Vulkan found")
else()
    message(FATAL_ERROR "Vulkan not found")
endif()

# Check if SPIRV-Tools is found
if(Vulkan_SPIRV-Tools_FOUND)
    message(STATUS "SPIRV-Tools found")
else()
    message(WARNING "SPIRV-Tools not found")
endif()
# Include GLFW files
# Download them
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

# Set the GLFW source directory
set(GLFW_SOURCE_DIR "${CMAKE_SOURCE_DIR}/external/glfw")

# Download GLFW if it doesn't exist
if (NOT EXISTS ${GLFW_SOURCE_DIR})
    message(STATUS "GLFW not found. Downloading...")
    file(DOWNLOAD https://github.com/glfw/glfw/archive/refs/heads/master.zip
         ${CMAKE_SOURCE_DIR}/external/glfw.zip
         SHOW_PROGRESS)
    message(STATUS "Extracting GLFW...")
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E tar xf ${CMAKE_SOURCE_DIR}/external/glfw.zip
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/external
    )
    file(RENAME ${CMAKE_SOURCE_DIR}/external/glfw-master ${GLFW_SOURCE_DIR})
endif()

# Add subdirectory for GLFW
add_subdirectory(${GLFW_SOURCE_DIR})

# Link GLFW libraries
target_link_libraries(ProjectEntertain glfw)


# include glm

# Add the GLM library directory
set(GLM_DIR "${CMAKE_SOURCE_DIR}/external/glm")
if(NOT EXISTS "${GLM_DIR}/CMakeLists.txt")
    message(FATAL_ERROR "GLM not found at ${GLM_DIR}")
endif()

# Add GLM as a subdirectory
add_subdirectory(${GLM_DIR})
target_include_directories(ProjectEntertain PRIVATE ${GLM_DIR})
