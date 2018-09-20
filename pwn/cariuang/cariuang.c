#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

unsigned int sukses = 0;
unsigned int uang = 0;

void cek_uang() {
	if (uang / 1000 == 0) {
		printf("Uang kamu sekarang %u rupiah.\n\n", uang);
	} else if (uang / 1000000 == 0) {
		printf("Uang kamu sekarang sekitar %u ribu rupiah.", uang / 1000);
		printf(" Tepatnya %u rupiah.\n\n", uang);
	} else if (uang / 1000000000 == 0) {
		printf("Uang kamu sekarang sekitar %u juta rupiah.", uang / 1000000);
		printf(" Tepatnya %u rupiah.\n\n", uang);
	} else if (uang / 1000000000000 == 0) {
		printf("Uang kamu sekarang sekitar %u milyar rupiah.", uang / 1000000000);
		printf(" Tepatnya %u rupiah.\n\n", uang);
	} else {
		puts("Uang kamu banyak.\n");
	}
}

void siapsiap() {
	setvbuf(stdout, NULL, _IONBF, 0);

	char jawaban[16];
	puts("Apakah kamu pengusaha sukses?");  
	fgets(jawaban, 16, stdin);

	if (strncmp(jawaban, "Iya", 3) == 0) {
		sukses = 1;
		uang = 100000000;
	} else if (strncmp(jawaban, "Tidak", 5) == 0) {
		uang = 5000;
	} else {
		puts("Maksudnya?");
		exit(0);
	}
	cek_uang();
}

void kerja(int waktu) {
	if (sukses) {
		uang += waktu * 500;
		waktu /= 500;
	} else {
		uang += waktu / 5;
		waktu *= 5;
	}

	while (waktu > 0) {
		sleep(1);
		waktu -= 1;
	}
}

void iklan() {
	puts("Dapatkan flag jika uang anda melebihi 4.29 milyar rupiah di akhir bulan!");
}

int main() {
	int i;
	iklan();
	siapsiap();
	for (i = 1; i < 31; i++) {
		int waktu = 0;
		printf("%d Juni 2019.\n", i);
		printf("Mau kerja berapa lama?\n");
		printf("Waktu: ");
		scanf("%d", &waktu);
		if (waktu < 0) {
			waktu = 0;
			puts("Jangan curang!");
			exit(0);
		}
		kerja(waktu);
		cek_uang();
	}
	if (uang >= 4290000000) {
		printf("Selamat! Flag: ");
		system("cat flag");
	} else {
		puts("Belum sampai 4.29 milyar rupiah.");
	}
}