add_executable(workflow Data.cpp Instance.cpp main.cpp)
target_include_directories(workflow PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})