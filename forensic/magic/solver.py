file = open('magic.png', 'r')
file_one = open('megic.png', 'w')

key = "arvy"

data = file.read()

for i in range(len(data)):
    hasil = ord(data[i]) ^ ord(key[i % len(key)])
    file_one.write(chr(hasil))

file.close()
file_one.close()