# create library "libtools"
#add_library(tools src/queue.cpp) # add executable main
add_executable(main main.cpp)
# tell the linker to bind these objects together 
#target_link_libraries(main tools)