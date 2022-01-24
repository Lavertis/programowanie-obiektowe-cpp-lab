cmake_minimum_required(VERSION 3.20)
project(sem5-cpp)

set(CMAKE_CXX_STANDARD 23)

#find_package(Boost)
#include_directories(${Boost_INCLUDE_DIRS})

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable(lab_01 lab_1/main.cpp lab_1/task_2/Animal.hpp lab_1/task_2/Animal.cpp lab_1/task_2/Dog.hpp lab_1/task_2/Dog.cpp lab_1/task_2/Cat.hpp lab_1/task_2/Cat.cpp)
add_executable(lab_02 lab_2/main.cpp lab_2/task_2/Employee.cpp lab_2/task_2/Employee.hpp lab_2/task_2/Developer.cpp lab_2/task_2/Developer.hpp lab_2/task_2/TeamLeader.cpp lab_2/task_2/TeamLeader.hpp lab_2/task_3/Buffer.cpp lab_2/task_3/Buffer.hpp lab_2/task_3/MeanBuffer.cpp lab_2/task_3/MeanBuffer.hpp lab_2/task_3/MaxBuffer.cpp lab_2/task_3/MaxBuffer.hpp)
add_executable(lab_03 lab_3/main.cpp lab_3/task_3.hpp lab_3/task_1/Adding.hpp lab_3/task_1/Student.hpp)
add_executable(lab_04 lab_4/main.cpp lab_4/task_3/Citizen.cpp lab_4/task_3/Citizen.hpp lab_4/task_3/City.cpp lab_4/task_3/City.hpp)
add_executable(lab_05 lab_5/main.cpp lab_5/Dictionary.cpp lab_5/Dictionary.hpp)
add_executable(lab_06_boost_multi_index lab_6/example/boost_multi_index.cpp lab_6/example/Person.hpp)
add_executable(lab_06_boost_fusion lab_6/example/boost_fusion.cpp)
add_executable(lab_06_boost_bind lab_6/example/boost_bind.cpp)
add_executable(lab_06 lab_6/main.cpp lab_6/task_2/Contact.hpp lab_6/task_2/Contacts.hpp lab_6/task_2/Contacts.cpp)
add_executable(lab_12 lab_12/main.cpp lab_12/Car.cpp lab_12/Car.hpp)
add_executable(kolokwium_1_mb kolokwium_1/mb/main.cpp kolokwium_1/mb/Dziecko.cpp kolokwium_1/mb/Dziecko.h kolokwium_1/mb/Prezent.cpp kolokwium_1/mb/Prezent.h)
add_executable(kolokwium_1_mk kolokwium_1/mk.cpp)
add_executable(lab_09 lab_9/main.cpp lab_9/task_3/StudentRecord.cpp lab_9/task_3/StudentRecord.h lab_9/task_3/StudentRecords.cpp lab_9/task_3/StudentRecords.h)
add_executable(lab_10 lab_10/main.cpp lab_10/task_3/AddressValidator.cpp lab_10/task_3/AddressValidator.h lab_10/task_4/CardIndexValidator.cpp lab_10/task_4/CardIndexValidator.h lab_10/task_5/User.cpp lab_10/task_5/User.h)
add_executable(lab_11 lab_11/main.cpp lab_11/task_1/Buffer.cpp lab_11/task_1/Buffer.h lab_11/task_1/BufferArr.cpp lab_11/task_1/BufferArr.h lab_11/task_1/BufferFile.cpp lab_11/task_1/BufferFile.h lab_11/task_2/Warehouse.cpp lab_11/task_2/Warehouse.h lab_11/task_2/Shop.cpp lab_11/task_2/Shop.h lab_11/task_3/BidirectionalList.h)
add_executable(kolokwium_2_mk kolokwium_2/mk/main.cpp kolokwium_2/mk/Animal.h)
add_executable(kolokwium_2_mb kolokwium_2/mb/main.cpp)
add_executable(lab_13 lab_13/tests/example/FunctionsTests.cpp lab_13/example/functions.cpp lab_13/example/Number.cpp lab_13/tests/example/NumberClassTests.cpp lab_13/tests/task_1_tests.cpp lab_13/tests/task_2_tests.cpp lab_13/task_3/BankAccount.cpp lab_13/tests/task_3_tests.cpp)
