cmake_minimum_required(VERSION 4.0)
project(Finans_Asistani)

set(CMAKE_CXX_STANDARD 26)

add_executable(Finans_Asistani main.cpp
        Transaction.cpp
        Transaction.h
        FinanceManager.cpp
        FinanceManager.h
        menu.cpp
        menu.h)
