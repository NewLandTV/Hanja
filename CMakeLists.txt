cmake_minimum_required(VERSION 3.25)
project(Hanja)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")

add_executable(Hanja Hanja.c Main.c)
