from pwn import *
import pickle

block = []

p = remote("localhost", 10003)

def test_decrypt(ct):
	p.sendline('1')
	p.recvuntil(':')
	p.sendline(b64e(ct))
	msg = p.recvuntil('>')
	return msg

def solver(cipher, iv_start):
	iv = [0 for i in range(16)]
	for idx in range(16):
		for c in range(256):
			intermediate = pickle.loads(pickle.dumps(iv))
			intermediate[-(idx+1)] = c
			for i in range(idx+1):
				intermediate[-(i+1)] ^= idx+21
			ct = ""
			for i in intermediate:
				ct += chr(i)
			ct += cipher
			msg = test_decrypt(ct)
			if ("Good" in msg):
				print "found", c
				iv[-(idx+1)] = c
				break
	z = []
	for i in range(16):
		z.append(chr(ord(iv_start[i]) ^ iv[i]))
	return "".join(z)

p.recvuntil('>')
p.sendline('2')
data = p.recvuntil('>')[:-2]
data = b64d(data)

l = len(data) / 16

flag = []
for i in range(l-1):
	flag.append(solver(data[16*(i+1):16*(i+2)], data[16*i:16*(i+1)]))

print "".join(flag)