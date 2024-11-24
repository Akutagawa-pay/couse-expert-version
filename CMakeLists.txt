cmake_minimum_required(VERSION 3.10)

# Устанавливаем название проекта
project(GraphicPrimitives)

# Указываем, где искать заголовочные файлы
include_directories(${PROJECT_SOURCE_DIR}/include)

# Указываем все исходные файлы для библиотеки
set(SOURCES
    src/snape.h
    src/Circle.h
    src/Line.h
    src/ShapeSet.h
    src/Point.h
)

# Создаем статическую библиотеку
add_library(GraphicPrimitives STATIC ${SOURCES})

# Указываем директории, где будут искать файлы при сборке
# (например, если это нужно для тестов или других проектов, которые будут использовать эту библиотеку)
target_include_directories(GraphicPrimitives PUBLIC ${PROJECT_SOURCE_DIR}/include)
