cmake_minimum_required(VERSION 3.13)
project(amuse1)

set(CMAKE_CXX_STANDARD 14)

add_executable(amuse1 Admin.h Application.h CircularQueue.h DoublySortedLinkedList.h DoublyIterator.h Queue.h Ride.cpp Ride.h SortedList.h Stack.h UnsortedList.h User.cpp User.h AppScreen.cpp)