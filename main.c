/*
 * Erly Lang Copyright (c) 2023
 *  - CodeSploit <samuelthart@pm.me>
 *  - SolindekDev <soindeklive.biznes@gmail.pl>
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "lexer.h"

#define HELP() \
    printf("Erly help\nFlags:\n\t- help / h - Show this message\n\t- version / v - Show actuall version of compiler\n"); 

#if defined(__x86_64__) || defined(_M_X64) 
# define VERSION()               \
    printf("Erly compiler (");   \
    printf("x86_64");            \
    printf(") 1.0.0v\n");          
#else
# define VERSION()               \
    printf("Erly compiler (");   \
    printf("Unknown arch");      \
    printf(") 1.0.0v\n");
#endif
    
int argument_is_flag(char* argument)
{
    if      (argument[0] == '-' && argument[1] != '\0') return 1;
    else if (argument[0] == '-' && argument[1] == '-') return 1;
    else return 0;
}

char *read_file(char *filename)
{
    FILE *f = fopen(filename, "r");

    if (!f)
    {
        return NULL;
    }

    char *contents = calloc(1, sizeof(char));

    char *line;

    size_t length;
    ssize_t read;

    while ((read = getline(&line, &length, f)) != -1)
    {
        contents = realloc(contents, (strlen(contents) + strlen(line) + 2));

        strcat(contents, line);
    }
    
    return contents;
}

int file_exist(char* filename)
{
    FILE* f = fopen(filename, "r");
    if (f == NULL)
        return 0;
    return 1;
}

void compilation_process(char* filename)
{
    if (filename == NULL)
        exit(0);

    if (!file_exist(filename))
    {
        printf("\"%s\" does not exist\n", filename);
        exit(1);
    }

    char* file_value = read_file(filename);
#ifdef DEBUG
    printf("Compilation process with file %s\n", filename);
    printf("Reading file named %s, file value:\n%s\n", filename, file_value);
    printf("Starting lexer process\n");
#endif

    lexer_t* lexer = lexer_initialize(file_value);

}

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("Expected more arguments, example use: erly [filename | flags]\n");
        return 1;
    }

    (void)*argv++;   

    int help_flag = 0;
    int version_flag = 0;
    char* filename = NULL;

    while (*argv != NULL)
    {
        if (argument_is_flag(*argv))
        {
            if (strcmp(*argv, "--help") == 0 || strcmp(*argv, "-h") == 0)
                help_flag = 1;
            else if (strcmp(*argv, "--version") == 0 || strcmp(*argv, "-v") == 0)
                version_flag = 1;
        }
        else
        {
            filename = *argv;
        }
        (void)*argv++;
    }

    if (help_flag == 1) { HELP(); }
    else if (version_flag == 1) { VERSION(); }
    else { compilation_process(filename); }
        

    return 0;
}