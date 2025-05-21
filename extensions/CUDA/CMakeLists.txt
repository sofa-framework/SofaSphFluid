cmake_minimum_required(VERSION 3.12)
project(SofaSphFluid.CUDA CUDA CXX)

set(HEADER_FILES
    src/SofaSphFluid/CUDA/init.h
    src/SofaSphFluid/CUDA/config.h.in

    src/SofaSphFluid/CUDA/CudaParticleSource.h
    src/SofaSphFluid/CUDA/CudaParticleSource.inl
    src/SofaSphFluid/CUDA/CudaSPHFluidForceField.h
    src/SofaSphFluid/CUDA/CudaSPHFluidForceField.inl
    src/SofaSphFluid/CUDA/CudaParticlesRepulsionForceField.h
    src/SofaSphFluid/CUDA/CudaParticlesRepulsionForceField.inl
    src/SofaSphFluid/CUDA/CudaSpatialGridContainer.h
    src/SofaSphFluid/CUDA/CudaSpatialGridContainer.inl
)

set(SOURCE_FILES
    src/SofaSphFluid/CUDA/init.cpp

    src/SofaSphFluid/CUDA/CudaParticleSource.cpp
    src/SofaSphFluid/CUDA/CudaSPHFluidForceField.cpp
    src/SofaSphFluid/CUDA/CudaParticlesRepulsionForceField.cpp
    src/SofaSphFluid/CUDA/CudaSpatialGridContainer.cpp
)

set(CUDA_SOURCES
    src/SofaSphFluid/CUDA/CudaParticleSource.cu
    src/SofaSphFluid/CUDA/CudaSPHFluidForceField.cu
    src/SofaSphFluid/CUDA/CudaParticlesRepulsionForceField.cu
    src/SofaSphFluid/CUDA/CudaSpatialGridContainer.cu
)

sofa_find_package(SofaSphFluid REQUIRED)
sofa_find_package(SofaCUDA REQUIRED)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${CUDA_SOURCES})
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
