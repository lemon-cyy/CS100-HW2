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
    /* TODO: your code here */
    (void)argc;
    (void)argv;
    for (int i = 1; i < argc; i++) {
        char *arg = argv[i];
        if (strcmp(arg, "-Wall") == 0) {
            printf("-Wall: Enable all the warnings about constructions that some users consider questionable, and that are easy to avoid (or modify to prevent the warning).\n");
        } 
        else if (strcmp(arg, "-Wpedantic") == 0) {
            printf("-Wpedantic: Issue all the warnings demanded by strict ISO C and ISO C++ and reject all programs that use forbidden extensions.\n");
        } 
        else if (strcmp(arg, "-Wextra") == 0) {
            printf("-Wextra: Enable some extra warning flags that are not enabled by -Wall.\n");
        } 
        else if (strcmp(arg, "-Werror") == 0) {
            printf("-Werror: Make all warnings into errors.\n");
        } 
        else if (strcmp(arg, "-o") == 0) {
            if (i + 1 < argc) {
                i++; 
                printf("-o %s: Place the primary output in file %s.\n", argv[i], argv[i]);
            }
        } 
        else if (strcmp(arg, "-I") == 0) {
            if (i + 1 < argc) {
                i++; // Advance to the directory parameter
                printf("-I %s: Add the directory %s to the list of directories to be searched for header files during preprocessing.\n", argv[i], argv[i]);
            }
        } 
        else if (strncmp(arg, "-std=", 5) == 0) {
            char *std = arg + 5;
            if (strncmp(std, "c++", 3) == 0) {
                printf("-std=%s: Set the language standard to ISO C++%s.\n", std, std + 3);
            } 
            else if (strncmp(std, "gnu++", 5) == 0) {
                printf("-std=%s: Set the language standard to GNU dialect of C++%s.\n", std, std + 5);
            } 
            else if (strncmp(std, "gnu", 3) == 0) {
                printf("-std=%s: Set the language standard to GNU dialect of C%s.\n", std, std + 3);
            } 
            else if (std[0] == 'c') {
                printf("-std=%s: Set the language standard to ISO C%s.\n", std, std + 1);
            }
        } 
        else {
            char *ext = strrchr(arg, '.'); 
            if (ext != NULL) {
                if (strcmp(ext, ".c") == 0) {
                    printf("%s: C source code as input file.\n", arg);
                } 
                else if (strcmp(ext, ".h") == 0) {
                    printf("%s: C/C++ header file as input file.\n", arg);
                } 
                else if (strcmp(ext, ".cpp") == 0 || strcmp(ext, ".C") == 0 || 
                         strcmp(ext, ".cc") == 0  || strcmp(ext, ".cxx") == 0) {
                    printf("%s: C++ source code as input file.\n", arg);
                } 
                else if (strcmp(ext, ".hpp") == 0 || strcmp(ext, ".hxx") == 0) {
                    printf("%s: C++ header file as input file.\n", arg);
                }
            }
        }
    }

    return 0;
}
