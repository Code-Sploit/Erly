/*
 * Erly Lang Copyright (c) 2023
 *  - CodeSploit <samuelthart@pm.me>
 *  - SolindekDev <soindeklive.biznes@gmail.pl>
 */

// code-sploit: https://i.imgur.com/3nGxdLS.jpg
// i will kill my fucking keyboard tbh i hate these builit in binds bruh

#include <string.h>
#include <stdio.h>

#include "lexer.h"

#define HELP() \
    printf("Erly help\nFlags:\n\t- help / h - Show this message\n\t- version / v - Show actuall version of compiler"); 

#ifdef x86_64
# define VERSION()               \
    printf("Erly compiler (");   \
    printf("x86_64");            \
    printf(") 1.0.0v");          
#else
# define VERSION()               \
    printf("Erly compiler (");   \
    printf("Unknown arch");      \
    printf(") 1.0.0v");
#endif
    
int argument_is_flag(char* argument)
{
    if      (argument[0] == '-' && argument[1] != '\0') return 1;
    else if (argument[0] == '-' && argument[1] == '-') return 1;
    else return 0;
}

int flag_equal(char* flag, char* flag_name)
{
    if      (flag[0] == '-' && flag[1] != '\0') flag += 1;
    else if (flag[0] == '-' && flag[1] == '-') flag += 2;

    return strcmp(flag, flag_name) == 0;
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

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("Expected more arguments, example use: erly [filename | flags]\n");
        return 1;
    }

    *argv++;   

    int help_flag, version_flag;
    char* filename;

    while (*argv != NULL)
    {
        if (argv_is_flag(*argv))
        {
            if (flag_equal(*argv, "help") || flag_equal(*argv, "h"))
                help_flag = 1;
            else if (flag_equal(*argv, "version") || flag_equal(*argv, "v"))
                version_flag = 1;
        }
        else
        {
            filename = *argv;
        }
        *argv++;
    }

    if (help_flag) 
    {
        HELP();
        return 0;
    }
    else if (version_flag)
    {
        VERSION();
        return 0;
    }
    
    printf("Compilation process with file %s", filename);
}