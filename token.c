/*
 * Erly Lang Copyright (c) 2023
 *  - CodeSploit <samuelthart@pm.me>
 *  - SolindekDev <soindeklive.biznes@gmail.pl>
 */
 
#include "token.h"

#include <stdlib.h>

token_t *token_initialize(char *src, token_type type)
{
    token_t *t = calloc(1, sizeof(token_t));

    t->src  = src;
    t->type = type;
    
    return t;
}