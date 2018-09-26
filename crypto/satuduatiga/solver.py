from pwn import *

def find_fix(num, l):
	tnum = num
	valid = True
	for n in l:
		if (n % tnum != 0):
			valid = False
			break
		tnum += 1
	
	if (valid):
		tl = []
		tnum = num
		for n in l:
			tl.append(n / tnum)
			tnum += 1
		l = tl

	return l, valid

def solve(n):
	sols = []
	i = 13337
	while (i > 0):
		n, valid = find_fix(i, n)
		if (not valid):
			i -= 1
		else:
			sols.append(i)
	return sols

r = remote('localhost', 2323)

r.recvuntil('Your choice: ')
r.sendline('3')

r.recvuntil("Decrypt 5 40-letter encrypted words or sentences.\n")

for tc in range(5):
	n = eval(r.recvuntil(']'))

	sols = solve(n)

	word = ''
	for i in range(len(n)):
		mult = 1
		for s in sols:
			mult *= s + i
		word += chr(n[i] / mult)

	r.recvuntil("Decrypted: ")
	r.sendline(word)
	r.recvuntil("Nice!")
	print word


r.recvuntil("Here is the encrypted FLAG.")
n = eval(r.recvuntil(']'))

sols = solve(n)

flag = ''
for i in range(len(n)):
	mult = 1
	for s in sols:
		mult *= s + i
	flag += chr(n[i] / mult)

print 'FLAG: ' + flag
