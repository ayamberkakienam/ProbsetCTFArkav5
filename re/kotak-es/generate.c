#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *flag = "SB0x_r3ver5ing_50_ez";

int main() {
    srand(16051995);

    printf("unsigned char sbox[%ld][256] = {\n", strlen(flag));
    unsigned char *sbox[strlen(flag)];
    for (int i = 0; i < strlen(flag); i++) {
        sbox[i] = malloc(sizeof(unsigned char) * 256);
        for (int j = 0; j < 256; j++) {
            sbox[i][j] = j;
        }
        for (int j = 0; j < 256; j++) {
            unsigned char r = (unsigned char)rand();
            unsigned char temp = sbox[i][j];
            sbox[i][j] = sbox[i][r];
            sbox[i][r] = temp;
        }
        printf("{");
        for (int j = 0; j < 256; j++) {
            printf("0x%x,", sbox[i][j]);
        }
        printf("},\n");
    }
    printf("};\n\n");

    printf("unsigned char flag[] = {\n");
    int len = strlen(flag);
    for (int i = 0; i < len; i++) {
        unsigned char last = flag[i];
        for (int j = 0; j < len; j++) {
            last = sbox[j][last];
        }
        printf("0x%x,", last);
    }
    printf("\n};\n");

    for (int i = 0; i < len; i++) {
        free(sbox[i]);
    }
}