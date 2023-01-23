/*
 * Erly Lang Copyright (c) 2023
 *  - CodeSploit <samuelthart@pm.me>
 *  - SolindekDev <soindeklive.biznes@gmail.pl>
 */
 
#include "lexer.h"
#include "token.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <ctype.h>

#define ASSERT_OVERFLOW(__lexer) \
    (__lexer->i + 1) > lexer->size

#define ASSERT_OVERFLOW_N(__lexer, __n) \
    (__lexer->i + __n) > lexer->size

lexer_t *lexer_initialize(char *src)
{
    lexer_t *lexer = calloc(1, sizeof(lexer_t));
    
    lexer->src = src;
    lexer->size = strlen(lexer->src);
    lexer->i = 0;

    lexer->c = lexer->src[lexer->i];

    return lexer;
}

void lexer_advance(lexer_t *lexer)
{
    if (ASSERT_OVERFLOW(lexer))
    {
        lexer->i = lexer->size;
        lexer->c = lexer->src[lexer->i];

        return;
    }

    lexer->i++;

    lexer->c = lexer->src[lexer->i];
}

char lexer_peek(lexer_t *lexer)
{
    return lexer->src[lexer->i];
}

char lexer_peek_offset(lexer_t *lexer, unsigned int offset)
{
    if (ASSERT_OVERFLOW_N(lexer, offset))
    {
        return lexer->src[lexer->size];
    }

    return lexer->src[lexer->i + offset];
}

void lexer_skip_whitespace(lexer_t *lexer)
{
    while (isspace(lexer->c))
    {
        lexer_advance(lexer);
    }
}

token_t *lexer_next(lexer_t *lexer)
{
    lexer_skip_whitespace(lexer);

    char *token = calloc(1, sizeof(char));

    while (!isspace(lexer->c))
    {
        token = realloc(token, (strlen(token) + 2));

        strcat(token, (char[]) {lexer_peek(lexer), 0});

        lexer_advance(lexer);
    }

    return token_initialize(token, TOKEN_IDENTIFIER);
}