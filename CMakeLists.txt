cmake_minimum_required(VERSION 3.13)
project(amusement)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(amusement
        Admin.h
        Application.cpp
        Application.h
#        AppScreen.cpp
#        CircularQueue.h
        DoublyIterator.h
        DoublySortedLinkedList.h
        main.cpp
        Queue.h
        Ride.cpp
        Ride.h
#        Screen.cpp
        SortedList.h
        Stack.h
        UnsortedList.h
        User.cpp
        User.h
        queue1.h)
