#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

char flag[30];

int main() {
	FILE* fin;

	setvbuf(stdout, NULL, _IONBF, 0);

	fin = fopen("flag", "r");
	fgets(flag, 27, fin);
	fclose(fin);

	puts("Enter your Shellcode : \n");

	char *mem = mmap(0, 20, PROT_READ|PROT_WRITE|PROT_EXEC, MAP_SHARED|MAP_ANONYMOUS, -1, 0);

	fgets(mem, 20, stdin);

	mprotect(mem, 20, PROT_READ|PROT_EXEC);

	for (int i=0; i<19; i++) {
		if (mem[i] == 0x0f && mem[i+1] == 0x05) {
			puts("Gak boleh syscall gan!\n");
			exit(0);
		}
	}

	(*(void(*)()) mem)();

	return 0;
}