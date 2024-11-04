cmake_minimum_required(VERSION 3.29)
project(Assignment)

set(CMAKE_CXX_STANDARD 20)

add_executable(Assignment main.cpp
        Area.cpp
        Area.h
        Road.h
        TrafficLight.h
        Road.cpp
        BillboardSign.h
        Citizen.h
        TrafficLight.cpp
        Roadsign.h
        Transport.h
        Transport.cpp
        Timer.h
        Taxi.h
        Train.h
        PrivateTransport.h
        Plane.h
        TrafficCommand.h
        SetRedLightsCommand.h
        SetRedLightsCommand.cpp
        PublicTransport.h
        PublicTransport.cpp
        Sign.cpp
        Building.cpp
        Citizen.cpp
        Plane.cpp
        Taxi.cpp
        Train.cpp
        PrivateTransport.cpp
        BillboardSign.h)
