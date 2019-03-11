#include <stdio.h>
#include <stdlib.h>

void print_menu() {
	printf("List perintah\n");
	printf("1. Baca isi kotak\n");
	printf("2. Tulis ke kotak\n");
	printf("3. Keluar\n");
}

void chall() {
	int token = 3;
	int idx, option;
	float storage[20];

	while (token > 0) {
		print_menu();
		printf("Banyak perintah tersisa : %d\n", token);
		printf("> ");
		scanf("%d", &option);

		switch (option) {
			case 0x1: {
				printf("Masukkan no kotak : ");
				scanf("%d", &idx);
				printf("Kotak-%d : %f\n", idx, storage[idx]);
				token--;
				break;
			}
			case 0x2: {
				printf("Masukkan no kotak : ");
				scanf("%d", &idx);
				printf("Masukkan isi baru : ");
				scanf("%f", &storage[idx]);
				token--;
				break;
			}
			case 0x3: {
				exit(0);
			}
			default: {
				printf("Perintah tidak ditemukan.\n");
			}
		}
	}
}

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);

	chall();

	return 0;
}