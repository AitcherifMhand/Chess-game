# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.10)

# nom du projet
project(chess)

# fichiers source
set(SOURCES main.cpp view.cpp mask.cpp board.cpp game.cpp historique.cpp)

# options de compilation
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")

# création de l'exécutable
add_executable(mon_executable ${SOURCES} ${HEADERS types.hpp view.hpp board.hpp mask.hpp game.hpp historique.hpp})

# Make sure generated files use the same clang-tidy checks (none).
configure_file(.clang-tidy .clang-tidy COPYONLY)
