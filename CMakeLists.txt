cmake_minimum_required(VERSION 3.13)
project(GoFish_EE312)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(GoFish_EE312
        card.cpp
        card.h
        card_demo.cpp
        deck.cpp
        deck.h
        driver.cpp
        go_fish.cpp
        player.cpp
        player.h
        tempCodeRunnerFile.cpp)
