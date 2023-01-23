#ifndef TOKEN_H
#define TOKEN_H

typedef enum token_type {
    // Types
    TOKEN_IDENTIFIER,
    TOKEN_INT,
    TOKEN_FUN,
    TOKEN_FLOAT,
    TOKEN_STRING,
    
    // ( and )
    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,
    
    // { and }
    TOKEN_LEFT_CURLY_BRACKETS,
    TOKEN_RIGHT_CURLY_BRACKETS, 

    // [ and ]
    TOKEN_LEFT_BLOCK_BRACKETS,
    TOKEN_RIGHT_BLOCK_BRACKETS,

    // Operators
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_MODULUS,

    // Assigment operators
    TOKEN_ASSIGNMENT,
    TOKEN_ADD_ASSIGNMENT,
    TOKEN_SUBSTRACT_ASSIGNMENT,
    TOKEN_MULTIPLY_ASSIGNMENT,
    TOKEN_DIVIDE_ASSIGNMENT,
    TOKEN_MODULUS_ASSIGNMENT,

    // Increment and decrement operators
    TOKEN_INCREMENT,
    TOKEN_DECREMENT,

    // Condition operators
    TOKEN_BIGGER_THAN,
    TOKEN_LESS_THAN,
    TOKEN_EQUALS,
    TOKEN_NOTEQUALS,
    TOKEN_BIGGERTHANOREQUALS,
    TOKEN_LESSTHANOREQUALS,

    // Other operators
    TOKEN_OR,
    TOKEN_AND,
    TOKEN_BANG,
    TOKEN_QUESTION_MARK,
    TOKEN_COLON,
    TOKEN_DOT,
    TOKEN_COMMA,
    TOKEN_ARROW,

    // Other things
    TOKEN_EOF,
    TOKEN_NONE
} token_type;

/*
fun
import
match
while
loop
for
if

i8, i16, i32, i64, int (int wil be this same as i32)
u8, u16, u32, u64

char (char will be this same as i8)
byte (byte will be this same as u8)
bool 
*/

typedef struct token_t
{
    char *src;
    char **args;

    unsigned int args_size;

    token_type type;
} token_t;

token_t *token_initialize(char *src, token_type type);

#endif