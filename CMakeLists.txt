cmake_minimum_required(VERSION 3.12)

project(iqp)
option(DEBUG "Debug" ON)

# Set stuff.
if(DEBUG)
    add_compile_definitions(_DEBUG)

    if(MSVC)
        add_compile_options(/W4 /WX /Od)
    else()
        add_compile_options(-Wall -Wextra -pedantic -Werror -Og)
    endif()
endif()

add_subdirectory(MaintenanceWorkflow)