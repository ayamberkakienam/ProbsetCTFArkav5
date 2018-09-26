from pwn import *

r = process('./cariuang')

r.recvuntil('Apakah kamu pengusaha sukses?')
r.sendline('Tidak')

for i in range(14):
	r.recvuntil('Waktu: ')
	r.sendline('1533000000')

r.sendline('junk')

r.recvuntil('Selamat! Flag: ')
print r.recvline()