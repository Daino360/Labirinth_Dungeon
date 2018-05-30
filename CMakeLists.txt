cmake_minimum_required(VERSION 3.7)
project(PlatformDungeon)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES main.cpp GameCharacter.cpp GameCharacter.h Hero.cpp Hero.h)
add_executable(PlatformDungeon ${SOURCE_FILES} Hero.cpp Hero.h Warrior.cpp Warrior.h Mage.cpp Mage.h Archer.cpp Archer.h Equipment.cpp Equipment.h Strategy.cpp Strategy.h AttackStrategy.cpp AttackStrategy.h Enemy.cpp Enemy.h MovementStrategy.cpp MovementStrategy.h)

add_library(core ${SOURCE_FILES} Weapon.cpp Weapon.h Warrior.cpp Warrior.h Mage.cpp Mage.h Archer.cpp Archer.h Equipment.cpp Equipment.h Strategy.cpp Strategy.h AttackStrategy.cpp AttackStrategy.h Enemy.cpp Enemy.h MovementStrategy.cpp MovementStrategy.h)
target_link_libraries(PlatformDungeon core)