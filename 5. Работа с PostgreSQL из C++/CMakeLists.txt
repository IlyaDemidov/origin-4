cmake_minimum_required(VERSION 3.2)

set(PostgreSQL_ADDITIONAL_VERSIONS "15")

project(Task_5)

add_executable(Task_5 main.cpp "sql.cpp" "sql.h")

add_subdirectory("D:\\libpqxx-7.8.1" libpqxx-build)

target_compile_features(Task_5 PRIVATE cxx_std_17)

target_link_libraries(Task_5 PRIVATE pqxx)