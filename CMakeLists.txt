cmake_minimum_required(VERSION 3.26)

project(Informatics_CPP CXX)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE TASK_FILES
        "Week */problem*.cpp"
)

foreach(task ${TASK_FILES})
    get_filename_component(exec_name ${task} NAME_WE)
    string(REPLACE " " "_" exec_name ${exec_name})
    add_executable(${exec_name} ${task})
endforeach()