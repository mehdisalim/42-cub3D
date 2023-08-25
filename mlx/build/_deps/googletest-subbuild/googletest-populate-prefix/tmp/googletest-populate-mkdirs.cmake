# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/esalim/Desktop/42cursus/42-cub3D/mlx/build/_deps/googletest-src"
  "/Users/esalim/Desktop/42cursus/42-cub3D/mlx/build/_deps/googletest-build"
  "/Users/esalim/Desktop/42cursus/42-cub3D/mlx/build/_deps/googletest-subbuild/googletest-populate-prefix"
  "/Users/esalim/Desktop/42cursus/42-cub3D/mlx/build/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/Users/esalim/Desktop/42cursus/42-cub3D/mlx/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/Users/esalim/Desktop/42cursus/42-cub3D/mlx/build/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/Users/esalim/Desktop/42cursus/42-cub3D/mlx/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/esalim/Desktop/42cursus/42-cub3D/mlx/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/esalim/Desktop/42cursus/42-cub3D/mlx/build/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
