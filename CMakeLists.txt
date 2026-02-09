cmake_minimum_required(VERSION 3.10)

# Имя проекта
project(MyApp)

# Стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

# Добавляем исполняемый файл и исходники
add_executable(app
    src/main.cpp
    src/menu.cpp
    src/arrays.cpp
    utils/reader.cpp
)
