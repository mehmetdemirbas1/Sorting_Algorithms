cmake_minimum_required(VERSION 3.15)
project(SortingAlgorithms C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Eğer include/ klasörün varsa aç
include_directories(${CMAKE_SOURCE_DIR}/include)

# KÖK KLASÖRDEKİ tüm .c dosyalarını bul (senin yapına göre en garanti bu)
file(GLOB PROGRAMS "${CMAKE_SOURCE_DIR}/*.c")

# Her .c dosyasından ayrı exe üret
foreach(file ${PROGRAMS})
    get_filename_component(name ${file} NAME_WE)
    add_executable(${name} ${file})
endforeach()
