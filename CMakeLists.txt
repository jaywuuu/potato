cmake_minimum_required(VERSION 3.10)

# set the project name
project(potato)
set (CMAKE_CXX_STANDARD 20)

# Set path to LLVM and MLIR build
set (LLVM_BUILD_DIR ${CMAKE_BINARY_DIR}/llvm/lib/cmake/llvm)
set (MLIR_BUILD_DIR ${CMAKE_BINARY_DIR}/llvm/lib/cmake/mlir)

if (EXISTS ${LLVM_BUILD_DIR})
  message(STATUS "LLVM_BUILD_DIR " ${LLVM_BUILD_DIR})
else ()
  message(FATAL_ERROR "Path in LLVM_BUILD_DIR does not exist: " ${LLVM_BUILD_DIR})
endif ()

if (EXISTS ${MLIR_BUILD_DIR})
  message(STATUS "MLIR_BUILD_DIR " ${MLIR_BUILD_DIR})
else ()
  message(FATAL_ERROR "Path in MLIR_BUILD_DIR does not exist: " ${MLIR_BUILD_DIR})
endif ()

find_package(LLVM REQUIRED CONFIG HINTS ${LLVM_BUILD_DIR})
find_package(MLIR REQUIRED CONFIG HINTS ${MLIR_BUILD_DIR})

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "Using MLIRConfig.cmake in: ${MLIR_DIR}")

message(STATUS "LLVM_INCLUDE_DIRS: " ${LLVM_INCLUDE_DIRS})
message(STATUS "MLIR_INCLUDE_DIR: " ${MLIR_INCLUDE_DIR})
message(STATUS "MLIR_INCLUDE_DIRS: " ${MLIR_INCLUDE_DIRS})

include_directories(${LLVM_INCLUDE_DIRS})
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})

include_directories(${MLIR_INCLUDE_DIRS})

add_executable(potatoc
    src/potatoc.cpp
)

target_link_directories(potatoc
  PRIVATE
    ${CMAKE_BINARY_DIR}/llvm/lib
)

llvm_map_components_to_libnames(llvm_libs support)
message(STATUS "llvm_libs: " ${llvm_libs})

# Link against LLVM libraries
target_link_libraries(potatoc
  PRIVATE
    ${llvm_libs}
    #MLIRSupport 
    #MLIRParser
)

set_target_properties(potatoc
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)