cmake_minimum_required(VERSION 3.20)
project(programowanie_obiektowe_cpp_lab)

set(CMAKE_CXX_STANDARD 23)

#add_executable(programowanie_obiektowe_cpp_lab lab_1/main.cpp lab_1/task_2/Animal.hpp lab_1/task_2/Animal.cpp lab_1/task_2/Dog.hpp lab_1/task_2/Dog.cpp lab_1/task_2/Cat.hpp lab_1/task_2/Cat.cpp)
add_executable(programowanie_obiektowe_cpp_lab lab_2/main.cpp lab_2/task_2/Employee.cpp lab_2/task_2/Employee.hpp lab_2/task_2/Developer.cpp lab_2/task_2/Developer.hpp lab_2/task_2/TeamLeader.cpp lab_2/task_2/TeamLeader.hpp lab_2/task_3/Buffer.cpp lab_2/task_3/Buffer.hpp lab_2/task_3/MeanBuffer.cpp lab_2/task_3/MeanBuffer.hpp lab_2/task_3/MaxBuffer.cpp lab_2/task_3/MaxBuffer.hpp)