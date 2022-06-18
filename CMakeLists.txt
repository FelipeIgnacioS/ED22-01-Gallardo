cmake_minimum_required(VERSION 3.0.0)
project(ProyectoDePruebas VERSION 0.1.0)

include(CTest)
enable_testing()
include_directories("src")
add_executable(ED22-01-GALLARDO src/main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
