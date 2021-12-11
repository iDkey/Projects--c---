cmake_minimum_required(VERSION 3.21)
project(Projects_c___)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Calculator)
include_directories(Ciba)
include_directories(Course)
include_directories(Learning)
include_directories(Learning/dinamic_mark)
include_directories(Learning/Dinamic_massive)
include_directories(Learning/Padenie)
include_directories(Learning/Reseto_Eratocfena)
include_directories("Learning/sort()")
include_directories(Learning/TellMeYourNumber)
include_directories("Some Projects")

add_executable(Projects_c___
        Calculator/main.cpp
        Ciba/pr8/1.cpp
        Ciba/pr8/2.1.cpp
        Ciba/pr8/2.2.cpp
        Ciba/pr8/2.3.cpp
        Ciba/pr8/2.4.cpp
        Ciba/pr8/2.5.cpp
        Ciba/pr8/2.cpp
        Ciba/pr8/3.cpp
        "Course/Module 10/10.4/10.4.cpp"
        "Course/Module 11/11.6.1/Caesar_cipher.cpp"
        "Course/Module 11/11.6.2/Correct_email.cpp"
        "Course/Module 11/11.6.3/Check_IP.cpp"
        "Course/Module 11/11.6.4/Float_comparison.cpp"
        "Course/Module 11/11.6.5/TicTacToe.cpp"
        "Course/Module 12/12.4.1/Apartment_house.cpp"
        "Course/Module 12/12.4.2/RowOfNumbers.cpp"
        "Course/Module 12/12.4.3/SortingDay.cpp"
        "Course/Module 13/13.6.1/VectorInt.cpp"
        "Course/Module 13/13.6.2/TotalPrice.cpp"
        "Course/Module 13/13.6.3/DataBase.cpp"
        "Course/Module 14/14.6.1/BanquetTable.cpp"
        "Course/Module 14/14.6.2/TicTacToeMass.cpp"
        "Course/Module 14/14.6.3/SnakeMas.cpp"
        "Course/Module 14/14.6.4/EqualityOfMatrices.cpp"
        "Course/Module 14/14.6.5/DiagonalMatrix.cpp"
        "Course/Module 14/14.6.6/matrix_multiplication.cpp"
        "Course/Module 14/14.6.7/Pypirka.cpp"
        "Course/Module 14/14.6.8/Minecraft.cpp"
        "Course/Module 14/14.6.9/SeaBattle.cpp"
        "Course/Module 15/15.6.1/Task1.cpp"
        "Course/Module 15/15.6.2/Task2.cpp"
        "Course/Module 15/15.6.3/Task3.cpp"
        "Course/Module 15/15.6.4/Task4.cpp"
        "Course/Module 16/16.4.1/Speedometer.cpp"
        "Course/Module 16/16.4.2/Stapler.cpp"
        "Course/Module 16/16.4.3/Calculator.cpp"
        "Course/Module 16/16.4.4/Piano.cpp"
        "Course/Module 16/16.4.5/Smart_House.cpp"
        "Course/Module 17/Task 1/Task1.cpp"
        "Course/Module 17/Task 2/Task2.cpp"
        "Course/Module 17/Task 3/Task3.cpp"
        "Course/Module 18/Task 1/Task1.cpp"
        "Course/Module 18/Task 2/Task2.cpp"
        "Course/Module 18/Task 3/Task3.cpp"
        "Course/Module 18/Task 4/Task4.cpp"
        "Course/Module 19/Task 1/Task1.cpp"
        "Course/Module 19/Task 2/Task2.cpp"
        "Course/Module 19/Task 3/Task3.cpp"
        "Course/Module 19/Task 4/Task4.cpp"
        "Course/Module 19/Task 5/WhatWhereWhen.cpp"
        "Course/Module 20/Task 1/Task1.cpp"
        "Course/Module 20/Task 2/Pic.cpp"
        "Course/Module 20/Task 3/fishing.cpp"
        "Course/Module 20/Task 4/ATM.cpp"
        "Course/Module 21/Task 1/Task1.cpp"
        "Course/Module 21/Task 2/Task2.cpp"
        "Course/Module 21/Task 3/Task3.cpp"
        "Course/Module 21/Task 4/Task4.cpp"
        "Course/Module 22/Task 1/Task1.cpp"
        "Course/Module 22/Task 2/Task2.cpp"
        "Course/Module 22/Task3/Task3.cpp"
        "Course/Module 23/Task 1/Task1.cpp"
        "Course/Module 23/Task 1/Task11.cpp"
        "Course/Module 23/Task 2/Task2.cpp"
        Learning/dinamic_mark/main.cpp
        Learning/Dinamic_massive/dinamic_massive.cpp
        Learning/Padenie/main.cpp
        Learning/Padenie/myConstant.h
        Learning/Reseto_Eratocfena/main.cpp
        "Learning/sort()/1.cpp"
        Learning/TellMeYourNumber/main.cpp
        "Some Projects/Bubble_Sort/Bubble_Sort.cpp"
        "Some Projects/Sort_by_selection/Sort_by_selection.cpp"
        test.cpp)
