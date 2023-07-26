#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
char *convert_to_binary(unsigned int num)
{
	int i = 0;
	int len, j;
	char *binary = (char *) malloc(33 * sizeof(char));

    if (num == 0) {
        char *binary = (char *) malloc(2 * sizeof(char));
        sprintf(binary, "0");
        return binary;
    }

    while (num > 0) {
        binary[i++] = num % 2 + '0';
        num /= 2;
    }
    binary[i] = '\0';
    len = strlen(binary);
    for (j = 0; j < len / 2; j++) {
        char temp = binary[j];
        binary[j] = binary[len - j - 1];
        binary[len - j - 1] = temp;
    }
    return binary;
}
