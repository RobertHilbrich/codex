cmake_minimum_required(VERSION 3.16)
project(prime_generator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(primes src/primes.cpp)
target_include_directories(primes PUBLIC src)

add_executable(test_primes tests/test_primes.cpp)
target_link_libraries(test_primes PRIVATE primes)
