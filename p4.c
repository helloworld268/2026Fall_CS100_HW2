/* CS100 Fall 2026 - HW2 Problem 4: GCC argument descriptor
 *
 * Read GCC-style command-line arguments (argv) and print a description
 * for each of them, in order. No standard input in this problem.
 * Do not rename this file.
 */
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        char *arg = argv[i];
        if (strcmp(arg, "-Wall") == 0)
        {
            printf("-Wall: Enable all the warnings about constructions that some users consider questionable, and that are easy to avoid (or modify to prevent the warning).\n");
        }
        else if (strcmp(arg, "-Wpedantic") == 0)
        {
            printf("-Wpedantic: Issue all the warnings demanded by strict ISO C and ISO C++ and reject all programs that use forbidden extensions.\n");
        }
        else if (strcmp(arg, "-Wextra") == 0)
        {
            printf("-Wextra: Enable some extra warning flags that are not enabled by -Wall.\n");
        }
        else if (strcmp(arg, "-Werror") == 0)
        {
            printf("-Werror: Make all warnings into errors.\n");
        }
        else if (strcmp(arg, "-o") == 0)
        {
            char *name = argv[++i];
            printf("-o %s: Place the primary output in file %s.\n", name, name);
        }
        else if (strcmp(arg, "-I") == 0)
        {
            char *name = argv[++i];
            printf("-I %s: Add the directory %s to the list of directories to be searched for header files during preprocessing.\n", name, name);
        }
        else if (strncmp(arg, "-std=", 5) == 0)
        {
            char *standard = arg + 5;
            printf("%s: Set the language standard to ", arg);
            if (strncmp(standard, "gnu++", 5) == 0)
            {
                printf("GNU dialect of C++%s.\n", standard + 5);
            }
            else if (strncmp(standard, "gnu", 3) == 0)
            {
                printf("GNU dialect of C%s.\n", standard + 3);
            }
            else if (strncmp(standard, "C++", 3) == 0)
            {
                printf("ISO C++%s.\n", standard + 3);
            }
            else
            {
                printf("ISO C%s.\n", standard + 1);
            }
        }
        else
        {
            char *other = strrchr(arg, '.');
            char *type;
            if (strcmp(other, ".c") == 0)
            {
                type = "C source code";
            }
            else if (strcmp(other, ".h") == 0)
            {
                type = "C/C++ header file";
            }
            else if (strcmp(other, ".cpp") == 0 || strcmp(other, ".C") == 0 || strcmp(other, ".cc") == 0 || strcmp(other, ".cxx") == 0)
            {
                type = "C++ source code";
            }
            else
            {
                type = "C++ header file";
            }
            printf("%s: %s as input file.\n", arg, type);
        }
    }
    (void)argc;
    (void)argv;
    return 0;
}
