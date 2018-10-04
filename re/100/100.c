#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

// --- HELPER ---

#define WHITESPACE 64
#define EQUALS     65
#define INVALID    66

static const unsigned char d[] = {
    66,66,66,66,66,66,66,66,66,66,64,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
    66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,62,66,66,66,63,52,53,
    54,55,56,57,58,59,60,61,66,66,66,65,66,66,66, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
    10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,66,66,66,66,66,66,26,27,28,
    29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,66,66,
    66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
    66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
    66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
    66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
    66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,66,
    66,66,66,66,66,66
};

int just_another_random_fFfff (char *in, unsigned char *out) { 
    char *end = in + strlen(in);
    char iter = 0;
    uint32_t buf = 0;
    size_t len = 0;
    
    while (in < end) {
        unsigned char c = d[*in++];
        
        switch (c) {
        case WHITESPACE: continue;
        case INVALID:    return 1;
        case EQUALS:
            in = end;
            continue;
        default:
            buf = buf << 6 | c;
            iter++;
            if (iter == 4) {
                *(out++) = (buf >> 16) & 255;
                *(out++) = (buf >> 8) & 255;
                *(out++) = buf & 255;
                buf = 0; iter = 0;

            }   
        }
    }
   
    if (iter == 3) {
        *(out++) = (buf >> 10) & 255;
        *(out++) = (buf >> 2) & 255;
    }
    else if (iter == 2) {
        *(out++) = (buf >> 4) & 255;
    }

    *(out++) = '\x00';
    return 0;
}

void unhex(char* hex) {
	size_t len = strlen(hex);
	for (size_t i = 0, j = 0; j < len / 2; i += 2, j++)
		hex[i / 2] = (hex[i] % 32 + 9) % 25 * 16 + (hex[i+1] % 32 + 9) % 25;
		hex[len / 2] = '\0';
}



// --- PROGRAM ---

int bBbbb = 252;
char *cCccc = "\xf8\x59\x76\xae\x51\xd2\x7b\x15\x47\xff\xb1\x6f\x79\x5d\x5f\x7c\x94\xdc\xbd\x2a\x45\x4f\x46\x41\x82\xe6\x83\x14\x9e\xf1\xb1\xab\x6f\xa7\x84\xd0\x6f\x0d\xf0\x5e\xbd\xee\x2d\x89\xf4\x5d\xea\xc5\x11\x9b\xab\xda\x05\x13\xf4\x12\xbf\x4a\xa2\x67\x7d\xdc\x94\x0e\x2a\xc1\xf5\xa7\xc8\x23\x5c\x45\xef\x90\xa5\x2e\x13\xeb\x6f\x7b\x6b\xa5\x3b\x18\xff\x88\xff\xe9\x8b\xac\xd1\x23\xb7\x88\x7d\xe2\x9d\x7d\x1d\xdf\x5b\xca\x38\x6d\x9f\xcb\x67\x09\x7d\x0b\x29\x42\xc0\xd7\x55\x95\x3f\xf4\xa4\x26\xa9\x95\xfc\x8f\x12\x03\xf3\xe8\x23\x24\xc5\x99\x9e\x93\xa0\x2c\x7c\xc4\x3c\x42\x8c\xa9\x77\x45\xff\xb8\x9c\x20\x34\x0a\x8f\xfd\xa3\x4f\x43\x73\x7c\x5b\x06\x7a\x71\x62\x83\x6a\xdd\xa4\xa1\x3e\x38\xbe\x12\x5f\xbf\x83\x85\x20\x29\xe7\x5b\xb6\x50\xf2\x51\x5b\xe4\x94\xd9\x0a\x82\x43\x24\xb8\x0e\x69\xa0\x67\x2e\xd2\xe3\x15\x7a\xfc\xa4\xc1\x44\x47\x61\x31\x49\xca\xaa\x93\x51\x9d\xef\x0b\x47\x46\x62\x23\x2a\xa2\x5a\x12\xa0\xeb\x7b\x36\xfb\x1b\x60\x5c\x14\x8f\xed\xce\xe0\x7c\x70\xd7\x70\x0c\x08\x15\x69\xd3\x43\x67\x96\x6d\xb6\x57";

long dDddd[100];
char aAaaa[512];

int eEeee(char a, char b, char c, char d) {
	if (((a + c) ^ d) == b) {
		bBbbb--;
		return 1;
	}
	return 0;
}

void fFfff0(char a, char b, int i) {
	b = (((((b - (rand() % 256)) - (rand() % 256)) - (rand() % 256)) - (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff1(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff2(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) + (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff3(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) - (rand() % 256)) + (rand() % 256)) ^ (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff4(char a, char b, int i) {
	b = (((((b - (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff5(char a, char b, int i) {
	b = (((((b - (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff6(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) + (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff7(char a, char b, int i) {
	b = (((((b + (rand() % 256)) - (rand() % 256)) - (rand() % 256)) - (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff8(char a, char b, int i) {
	b = (((((b - (rand() % 256)) - (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff9(char a, char b, int i) {
	b = (((((b + (rand() % 256)) + (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff10(char a, char b, int i) {
	b = (((((b + (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) - (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff11(char a, char b, int i) {
	b = (((((b - (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) - (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff12(char a, char b, int i) {
	b = (((((b + (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) - (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff13(char a, char b, int i) {
	b = (((((b + (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff14(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff15(char a, char b, int i) {
	b = (((((b - (rand() % 256)) - (rand() % 256)) + (rand() % 256)) + (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff16(char a, char b, int i) {
	b = (((((b + (rand() % 256)) + (rand() % 256)) ^ (rand() % 256)) + (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff17(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) - (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff18(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff19(char a, char b, int i) {
	b = (((((b - (rand() % 256)) - (rand() % 256)) + (rand() % 256)) - (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff20(char a, char b, int i) {
	b = (((((b - (rand() % 256)) ^ (rand() % 256)) + (rand() % 256)) - (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff21(char a, char b, int i) {
	b = (((((b - (rand() % 256)) + (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff22(char a, char b, int i) {
	b = (((((b + (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) - (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff23(char a, char b, int i) {
	b = (((((b - (rand() % 256)) ^ (rand() % 256)) + (rand() % 256)) + (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff24(char a, char b, int i) {
	b = (((((b - (rand() % 256)) + (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff25(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) + (rand() % 256)) + (rand() % 256)) - (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff26(char a, char b, int i) {
	b = (((((b - (rand() % 256)) + (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff27(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) + (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff28(char a, char b, int i) {
	b = (((((b + (rand() % 256)) - (rand() % 256)) - (rand() % 256)) - (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff29(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) - (rand() % 256)) - (rand() % 256)) - (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff30(char a, char b, int i) {
	b = (((((b + (rand() % 256)) + (rand() % 256)) ^ (rand() % 256)) + (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff31(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) - (rand() % 256)) + (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff32(char a, char b, int i) {
	b = (((((b - (rand() % 256)) - (rand() % 256)) - (rand() % 256)) - (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff33(char a, char b, int i) {
	b = (((((b + (rand() % 256)) + (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff34(char a, char b, int i) {
	b = (((((b - (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) + (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff35(char a, char b, int i) {
	b = (((((b + (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff36(char a, char b, int i) {
	b = (((((b - (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff37(char a, char b, int i) {
	b = (((((b - (rand() % 256)) ^ (rand() % 256)) + (rand() % 256)) + (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff38(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) + (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff39(char a, char b, int i) {
	b = (((((b + (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff40(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) + (rand() % 256)) + (rand() % 256)) ^ (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff41(char a, char b, int i) {
	b = (((((b - (rand() % 256)) - (rand() % 256)) + (rand() % 256)) + (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff42(char a, char b, int i) {
	b = (((((b - (rand() % 256)) - (rand() % 256)) - (rand() % 256)) + (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff43(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) ^ (rand() % 256)) + (rand() % 256)) - (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff44(char a, char b, int i) {
	b = (((((b - (rand() % 256)) - (rand() % 256)) + (rand() % 256)) - (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff45(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) + (rand() % 256)) ^ (rand() % 256)) + (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff46(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) + (rand() % 256)) ^ (rand() % 256)) + (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff47(char a, char b, int i) {
	b = (((((b + (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff48(char a, char b, int i) {
	b = (((((b + (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) + (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff49(char a, char b, int i) {
	b = (((((b + (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff50(char a, char b, int i) {
	b = (((((b + (rand() % 256)) - (rand() % 256)) + (rand() % 256)) + (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff51(char a, char b, int i) {
	b = (((((b + (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff52(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) + (rand() % 256)) + (rand() % 256)) ^ (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff53(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) + (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff54(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) + (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff55(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) - (rand() % 256)) + (rand() % 256)) - (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff56(char a, char b, int i) {
	b = (((((b + (rand() % 256)) - (rand() % 256)) - (rand() % 256)) - (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff57(char a, char b, int i) {
	b = (((((b - (rand() % 256)) - (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff58(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff59(char a, char b, int i) {
	b = (((((b + (rand() % 256)) + (rand() % 256)) - (rand() % 256)) + (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff60(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) - (rand() % 256)) - (rand() % 256)) - (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff61(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) ^ (rand() % 256)) + (rand() % 256)) - (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff62(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) - (rand() % 256)) + (rand() % 256)) + (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff63(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) ^ (rand() % 256)) + (rand() % 256)) + (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff64(char a, char b, int i) {
	b = (((((b + (rand() % 256)) - (rand() % 256)) + (rand() % 256)) - (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff65(char a, char b, int i) {
	b = (((((b - (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff66(char a, char b, int i) {
	b = (((((b + (rand() % 256)) + (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff67(char a, char b, int i) {
	b = (((((b - (rand() % 256)) - (rand() % 256)) + (rand() % 256)) ^ (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff68(char a, char b, int i) {
	b = (((((b - (rand() % 256)) + (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff69(char a, char b, int i) {
	b = (((((b + (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) - (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff70(char a, char b, int i) {
	b = (((((b - (rand() % 256)) + (rand() % 256)) + (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff71(char a, char b, int i) {
	b = (((((b - (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) - (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff72(char a, char b, int i) {
	b = (((((b - (rand() % 256)) - (rand() % 256)) + (rand() % 256)) + (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff73(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) - (rand() % 256)) + (rand() % 256)) ^ (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff74(char a, char b, int i) {
	b = (((((b - (rand() % 256)) - (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff75(char a, char b, int i) {
	b = (((((b - (rand() % 256)) - (rand() % 256)) + (rand() % 256)) + (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff76(char a, char b, int i) {
	b = (((((b - (rand() % 256)) ^ (rand() % 256)) + (rand() % 256)) + (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff77(char a, char b, int i) {
	b = (((((b - (rand() % 256)) - (rand() % 256)) - (rand() % 256)) - (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff78(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff79(char a, char b, int i) {
	b = (((((b + (rand() % 256)) - (rand() % 256)) - (rand() % 256)) - (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff80(char a, char b, int i) {
	b = (((((b + (rand() % 256)) ^ (rand() % 256)) + (rand() % 256)) + (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff81(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) + (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff82(char a, char b, int i) {
	b = (((((b + (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) - (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff83(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) - (rand() % 256)) - (rand() % 256)) + (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff84(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff85(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) + (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff86(char a, char b, int i) {
	b = (((((b - (rand() % 256)) - (rand() % 256)) - (rand() % 256)) - (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff87(char a, char b, int i) {
	b = (((((b ^ (rand() % 256)) - (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff88(char a, char b, int i) {
	b = (((((b + (rand() % 256)) + (rand() % 256)) + (rand() % 256)) - (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff89(char a, char b, int i) {
	b = (((((b + (rand() % 256)) + (rand() % 256)) + (rand() % 256)) - (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff90(char a, char b, int i) {
	b = (((((b + (rand() % 256)) + (rand() % 256)) + (rand() % 256)) - (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff91(char a, char b, int i) {
	b = (((((b + (rand() % 256)) - (rand() % 256)) - (rand() % 256)) + (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff92(char a, char b, int i) {
	b = (((((b + (rand() % 256)) - (rand() % 256)) - (rand() % 256)) - (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff93(char a, char b, int i) {
	b = (((((b - (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) - (rand() % 256)) - (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff94(char a, char b, int i) {
	b = (((((b - (rand() % 256)) ^ (rand() % 256)) + (rand() % 256)) - (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff95(char a, char b, int i) {
	b = (((((b - (rand() % 256)) + (rand() % 256)) - (rand() % 256)) - (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff96(char a, char b, int i) {
	b = (((((b - (rand() % 256)) - (rand() % 256)) + (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff97(char a, char b, int i) {
	b = (((((b - (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff98(char a, char b, int i) {
	b = (((((b + (rand() % 256)) + (rand() % 256)) - (rand() % 256)) ^ (rand() % 256)) ^ (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void fFfff99(char a, char b, int i) {
	b = (((((b + (rand() % 256)) + (rand() % 256)) - (rand() % 256)) - (rand() % 256)) + (rand() % 256));
	if (eEeee(a, b, rand() % 256, rand() % 256)) {
		aAaaa[i] = b ^ a;
	}
}

void prepare() {
	srand(1337);
	dDddd[0] = fFfff0;
	dDddd[1] = fFfff1;
	dDddd[2] = fFfff2;
	dDddd[3] = fFfff3;
	dDddd[4] = fFfff4;
	dDddd[5] = fFfff5;
	dDddd[6] = fFfff6;
	dDddd[7] = fFfff7;
	dDddd[8] = fFfff8;
	dDddd[9] = fFfff9;
	dDddd[10] = fFfff10;
	dDddd[11] = fFfff11;
	dDddd[12] = fFfff12;
	dDddd[13] = fFfff13;
	dDddd[14] = fFfff14;
	dDddd[15] = fFfff15;
	dDddd[16] = fFfff16;
	dDddd[17] = fFfff17;
	dDddd[18] = fFfff18;
	dDddd[19] = fFfff19;
	dDddd[20] = fFfff20;
	dDddd[21] = fFfff21;
	dDddd[22] = fFfff22;
	dDddd[23] = fFfff23;
	dDddd[24] = fFfff24;
	dDddd[25] = fFfff25;
	dDddd[26] = fFfff26;
	dDddd[27] = fFfff27;
	dDddd[28] = fFfff28;
	dDddd[29] = fFfff29;
	dDddd[30] = fFfff30;
	dDddd[31] = fFfff31;
	dDddd[32] = fFfff32;
	dDddd[33] = fFfff33;
	dDddd[34] = fFfff34;
	dDddd[35] = fFfff35;
	dDddd[36] = fFfff36;
	dDddd[37] = fFfff37;
	dDddd[38] = fFfff38;
	dDddd[39] = fFfff39;
	dDddd[40] = fFfff40;
	dDddd[41] = fFfff41;
	dDddd[42] = fFfff42;
	dDddd[43] = fFfff43;
	dDddd[44] = fFfff44;
	dDddd[45] = fFfff45;
	dDddd[46] = fFfff46;
	dDddd[47] = fFfff47;
	dDddd[48] = fFfff48;
	dDddd[49] = fFfff49;
	dDddd[50] = fFfff50;
	dDddd[51] = fFfff51;
	dDddd[52] = fFfff52;
	dDddd[53] = fFfff53;
	dDddd[54] = fFfff54;
	dDddd[55] = fFfff55;
	dDddd[56] = fFfff56;
	dDddd[57] = fFfff57;
	dDddd[58] = fFfff58;
	dDddd[59] = fFfff59;
	dDddd[60] = fFfff60;
	dDddd[61] = fFfff61;
	dDddd[62] = fFfff62;
	dDddd[63] = fFfff63;
	dDddd[64] = fFfff64;
	dDddd[65] = fFfff65;
	dDddd[66] = fFfff66;
	dDddd[67] = fFfff67;
	dDddd[68] = fFfff68;
	dDddd[69] = fFfff69;
	dDddd[70] = fFfff70;
	dDddd[71] = fFfff71;
	dDddd[72] = fFfff72;
	dDddd[73] = fFfff73;
	dDddd[74] = fFfff74;
	dDddd[75] = fFfff75;
	dDddd[76] = fFfff76;
	dDddd[77] = fFfff77;
	dDddd[78] = fFfff78;
	dDddd[79] = fFfff79;
	dDddd[80] = fFfff80;
	dDddd[81] = fFfff81;
	dDddd[82] = fFfff82;
	dDddd[83] = fFfff83;
	dDddd[84] = fFfff84;
	dDddd[85] = fFfff85;
	dDddd[86] = fFfff86;
	dDddd[87] = fFfff87;
	dDddd[88] = fFfff88;
	dDddd[89] = fFfff89;
	dDddd[90] = fFfff90;
	dDddd[91] = fFfff91;
	dDddd[92] = fFfff92;
	dDddd[93] = fFfff93;
	dDddd[94] = fFfff94;
	dDddd[95] = fFfff95;
	dDddd[96] = fFfff96;
	dDddd[97] = fFfff97;
	dDddd[98] = fFfff98;
	dDddd[99] = fFfff99;
}

int main() {
	prepare();

	char buf[512];
	char input[512];
	fgets(input, 512, stdin);
	int len = strlen(input) / 2;
	unhex(input);

	int i;
	for (i = 0; i < len; i++) {
		int a = rand() % 100;
		void (*fFfff)() = dDddd[a];
		fFfff(input[i], cCccc[i], i);
	}

	for (i = bBbbb; i < len; i++) {
		aAaaa[i] ^= input[i];
	}

	for (i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			just_another_random_fFfff(aAaaa, buf);
		} else {
			just_another_random_fFfff(buf, aAaaa);
		}
	}

	if (bBbbb == 0) {
		printf("Arkav5{%s}\n", aAaaa);
	} else {
		puts("Try again.");
	}
	return 0;
}