cmake_minimum_required(VERSION 3.30)
project(unit_test)

set(CMAKE_CXX_STANDARD 17)

# Incluir los archivos de cabecera

include_directories(${CMAKE_SOURCE_DIR})

set(SOURCES
        main.cpp
        MetodosTest.h

)


# Crear el ejecutable para tu código principal

add_executable(main ${SOURCES})


# Opciones
option(ENABLE_TESTING "Enable a Unit Testing build." ON)

# Descarga GoogleTest usando FetchContent
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

# Si se habilitan las pruebas, agrega GoogleTest y las pruebas unitarias
if(ENABLE_TESTING)
    enable_testing()

    # Archivos de pruebas
    set(TEST_SOURCES
        tests/test.cpp

    )

# Crear ejecutable de pruebas

    add_executable(test_suite ${TEST_SOURCES})

    # Enlazar GoogleTest

    target_link_libraries(test_suite PRIVATE gtest gtest_main)

    # Registrar pruebas con CTest

    add_test(NAME AllTests COMMAND test_suite)

endif()