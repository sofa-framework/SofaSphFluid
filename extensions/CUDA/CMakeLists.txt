cmake_minimum_required(VERSION 3.12)
project(SofaSphFluid.CUDA)

set(HEADER_FILES
    src/SofaSphFluid/CUDA/init.h
    src/SofaSphFluid/CUDA/config.h.in
)

set(SOURCE_FILES
    src/SofaSphFluid/CUDA/init.cpp
)

sofa_find_package(SofaSphFluid REQUIRED)
sofa_find_package(SofaCUDA REQUIRED)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} SofaSphFluid)
target_link_libraries(${PROJECT_NAME} SofaCUDA)

sofa_create_package_with_targets(
    PACKAGE_NAME ${PROJECT_NAME}
    PACKAGE_VERSION ${Sofa_VERSION}
    TARGETS ${PROJECT_NAME} AUTO_SET_TARGET_PROPERTIES
    INCLUDE_SOURCE_DIR "src"
    INCLUDE_INSTALL_DIR "${PROJECT_NAME}"
    RELOCATABLE "plugins"
)
