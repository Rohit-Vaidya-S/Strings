#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// finding duplicate strings and discarding it. 


int main() {
    char *storeData;
    int maxLen = 100; // maximum length of input string
    storeData = (char *)malloc(maxLen * sizeof(char));
    scanf("%[^\n]s", storeData);

    char *token = strtok(storeData, " "); // tokenize the input string using space as a delimiter
    char *words[100]; // an array to store unique words
    int i, j, count = 0;

    while (token != NULL) {
        // check if the current token is already in the words array
        for (i = 0; i < count; i++) {
            if (strcmp(words[i], token) == 0) {
                break;
            }
        }

        // if the token is not already in the words array, add it
        if (i == count) {
            words[count++] = token;
        }

        token = strtok(NULL, " ");
    }

    // print the unique words
    for (j = 0; j < count; j++) {
        printf("%s ", words[j]);
    }
    
    free(storeData);
    return 0;
}
