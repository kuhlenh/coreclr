cmake_minimum_required(VERSION 2.8.12.2)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCES
  virtualalloc.c
)

add_executable(paltest_virtualalloc_test20
  ${SOURCES}
)

add_dependencies(paltest_virtualalloc_test20 CoreClrPal)

target_link_libraries(paltest_virtualalloc_test20
  pthread
  m
  CoreClrPal
)
