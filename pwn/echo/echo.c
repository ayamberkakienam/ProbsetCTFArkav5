#include <stdio.h>
#include <stdlib.h>

void hoho() {
	system("/bin/sh");
}

void vuln() {
	char buf[24];

	read(0, buf, 0x21);

	// asm (
	// 	"mov %rax, %rbx;"
	// 	"add %rbx, (%rbp);"
	// );

	printf(buf);
}

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);

	vuln();

	return 0;
}