cmake_minimum_required(VERSION 3.12)
project(book)



set(MYSQL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/thirth/MySQL Server 8.0")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${MYSQL_DIR}/include
)

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(main1 ${MY_SOURCES})

target_link_directories(main1 PRIVATE ${MYSQL_DIR}/lib)
target_link_libraries(main1
    PRIVATE
   libmysql
    ws2_32
    crypt32
    advapi32
)