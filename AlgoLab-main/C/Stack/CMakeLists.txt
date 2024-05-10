cmake_minimum_required(VERSION 3.25)
project(Stack C)

set(CMAKE_C_STANDARD 23)

add_executable(Stack main.c Stack_Operations.c Stack_Operations.h Arithmethic_Expression_Checker/arithmetic_expression.c Arithmethic_Expression_Checker/arithmetic_expression.h Infix_to_Postfix.c Infix_to_Postfix.h)
