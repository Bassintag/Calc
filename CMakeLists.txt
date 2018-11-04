# cmake_minimum_required(VERSION <specify CMake version here>)
project(Bistro C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_executable(Bistro main.c
        include/bistro.h
        include/lists.h
        src/list_create.c
        src/list_append.c
        src/calc.c
        src/token_create.c
        src/expr_tokenize.c
        src/tokens_eval.c
        src/tokens_value.c
        src/tokens_type.c src/bigint_invert.c src/bigint_parse.c src/bigint_add.c src/bigint_sub.c src/bigint_mul.c src/bigint_div.c src/bigint_mod.c src/tokens_advance.c src/bigint_create.c src/bigint_print.c src/bigint_compare.c src/bigint_simplify_neg.c src/bigint_zero.c)