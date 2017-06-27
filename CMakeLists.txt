cmake_minimum_required(VERSION 3.7)
project(data_structures)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)
set(CMAKE_BUILD_TYPE Debug)

set(SOURCE_FILES test/main.cpp include/DataStructure.hpp include/DynamicQueue.hpp include/DynamicStack.hpp include/LinkedList.hpp include/Node.hpp include/StaticQueue.hpp include/StaticStack.hpp include/ProtectedLinkedList.hpp include/Queue.hpp include/Stack.hpp include/OrderedList.hpp)

add_library(structures SHARED ${SOURCE_FILES})
add_executable(structures ${SOURCE_FILES})
