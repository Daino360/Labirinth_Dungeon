cmake_minimum_required(VERSION 3.7)
project(PlatformDungeon)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES main.cpp GameCharacter.cpp GameCharacter.h Hero.cpp Hero.h)
add_executable(PlatformDungeon ${SOURCE_FILES} Hero.cpp Hero.h Equipment.cpp Equipment.h Strategy.cpp Strategy.h AttackStrategy.cpp AttackStrategy.h Enemy.cpp Enemy.h MovementStrategy.cpp MovementStrategy.h Store.cpp Store.h EnumFile.h)

add_library(core ${SOURCE_FILES} Weapon.cpp Weapon.h Equipment.cpp Equipment.h Strategy.cpp Strategy.h AttackStrategy.cpp AttackStrategy.h Enemy.cpp Enemy.h MovementStrategy.cpp MovementStrategy.h Store.cpp Store.h Map.cpp Map.h EnumFile.h)
target_link_libraries(PlatformDungeon core)


# Define sources and executable

set(EXECUTABLE_NAME "myproject")
add_executable(${EXECUTABLE_NAME} main.cpp)

# Detect and add SFML

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()