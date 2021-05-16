cmake_minimum_required(VERSION 3.9)
project(Asteroidy)

set(CMAKE_CXX_STANDARD 11)

set(DSFML_STATIC)
set(SFML_ROOT E:/BIBLIOTEKI/SFML/)
set(SFML_STATIC_LIBRARIES TRUE)

add_executable(Asteroidy main.cpp  Asteroid.cpp Asteroid.h Level.cpp Level.h Game.cpp Game.h ParametryOkna.h Bullet.cpp Bullet.h Spaceship.cpp Spaceship.h Menu.cpp Menu.h)


set(CMAKE_MODULE_PATH "E:/BIBLIOTEKI/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})

find_package(SFML 2 REQUIRED graphics window system)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Asteroidy ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()