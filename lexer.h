#ifndef LEXER_H
#define LEXER_H

#include "token.h"

typedef struct lexer_t
{
    char *src;
    char c;

    unsigned int i;

    int size;
} lexer_t;

lexer_t *lexer_initialize(char *src);

void lexer_advance(lexer_t *lexer);
void lexer_peek(lexer_t *lexer);
void lexer_peek_offset(lexer_t *lexer, unsigned int offset);

char *lexer_advance_id(lexer_t *lexer);
char *lexer_advance_digit(lexer_t *lexer);

token_t lexer_next(lexer_t *lexer);

#endif