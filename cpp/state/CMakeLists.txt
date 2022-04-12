CMAKE_MINIMUM_REQUIRED(VERSION 3.21)

PROJECT(state)

ADD_EXECUTABLE(${PROJECT_NAME} Test.cpp State.cpp State.h StateFrame.cpp StateFrame.h)
