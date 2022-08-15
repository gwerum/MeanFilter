# create library "filter"
# add_library(filter filter.cpp) 

# add executable main
add_executable(main main.cpp)
# tell the linker to bind these objects together 
# target_link_libraries(main filter)