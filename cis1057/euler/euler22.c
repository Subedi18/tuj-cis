#include <stdlib.h>
#include <stdio.h>
#include "utils/files.h"

/**
 * PROJECT EULER #22
 * Names Scores
 *
 * Using data/euler22.txt, a 46K text file containing over five-thousand
 * first names, begin by sorting it into alphabetical order. Then working
 * out the alphabetical value for each name, multiply this value by its
 * alphabetical position in the list to obtain a name score.
 *
 * For example, when the list is sorted into alphabetical order, COLIN,
 * which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the
 * list. So, COLIN would obtain a score of 938 x 53 = 49714.
 *
 * What is the total of all the name scores in the file?
 */

#define INPUT_FILE "data/euler22.txt"
#define BUFFER_SIZE (1<<16)
#define NAME_LIMIT 60000

int main(int argc, char *argv[]) {
    FILE *file = open_file(INPUT_FILE);
    char buffer[BUFFER_SIZE] = {0};
    char *name[NAME_LIMIT] = {0};

    int c, b = 0, n = 0;
    while((c = fgetc(file)) != EOF) {
        if (name[n]) {
            if(c == '"') {
                buffer[b] = '\0';
                n++;
            } else {
                buffer[b++] = c;
            }
        } else if (c == '"') {
            name[n] = &buffer[b];
        }
    }
    
    for (int i = 0; i < NAME_LIMIT && name[i]; i++) {
        puts(name[i]);
    }
    
    fclose(file);
    return EXIT_SUCCESS;
}