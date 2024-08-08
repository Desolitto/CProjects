/*!
 * \mainpage
 * \author calamarp
 * \version 1.0
 * \section Calculator_v1.0 was done with
 * 1. C language \n
 * 2. Qt Creator, Qt \n
 * 3. Qcustomplot \n
 * 4. Qmake6 \n
 * 5. Doxygen
 */
#ifndef SMART_CALC_H
#define SMART_CALC_H

#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "modules/my_calc.h"
#include "modules/my_finance.h"
#include "modules/my_polish.h"
#include "modules/my_stack.h"
#include "modules/my_valid.h"

// define commonly used data types for convenience
#define PERMITTED_SYMBOLS "1234567890()+-*/^mcstalx.e"
#define NUMBERS "1234567890"
#define REAL_NUMBS "1234567890.e"
#define OPERANDS "1234567890mcstalx.("
#define OPERATORS "+-*/^"
#define BRACKETS "()"
#define FUNCS "cstCSTqlL"             // m
#define FUNCS_BKT_OP "cstaql()+-*/^"  // m

#define MAX_LEN 255

//! Error codes
#define OK 0
#define CALCULATION_ERROR 1
#define MEMORY_ERROR 2
#define INCORRECT_INPUT 3
#define DIV_BY_ZERO 4
#define NAN_OR_INF 5
#define SORRY_CANT_CALC_WITH_E 6

#endif
