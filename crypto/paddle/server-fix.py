import base64, os, sys
from Crypto.Cipher import AES

BLOCK_SIZE = 16
FLAG = 'REDACTED'
KEY = os.urandom(16)

class Unbuffered(object):
    def __init__(self, stream):
        self.stream = stream
    def write(self, data):
        self.stream.write(data)
        self.stream.flush()
    def writelines(self, datas):
        self.stream.writelines(datas)
        self.stream.flush()
    def __getattr__(self, attr):
        return getattr(self.stream, attr)

sys.stdout = Unbuffered(sys.stdout)

def menu():
	print '-------Menu-------'
	print '1. Test Decrypt'
	print '2. Print Flag'
	print '3. Exit'

def pad(msg):
	return msg + chr((BLOCK_SIZE - (len(msg) % BLOCK_SIZE)) + 20) * (BLOCK_SIZE - (len(msg) % BLOCK_SIZE))

def unpad(msg):
	padding_length = ord(msg[-1]) - 20
	if padding_length < 1 or padding_length > BLOCK_SIZE:
		raise
	if msg[-padding_length:] != (padding_length * chr(padding_length + 20)):
		raise
	return msg[:-ord(msg[-1]) - 20]

def gen_flag():
	global FLAG
	iv = os.urandom(16)
	aes = AES.new(KEY, AES.MODE_CBC, iv)
	FLAG = base64.b64encode(iv+aes.encrypt(pad(FLAG)))

def decrypt():
	msg = raw_input('String to decrypt : ')
	try:
		msg = base64.b64decode(msg)
	except:
		print 'incorrect padding'
		return
	t_iv = msg[:BLOCK_SIZE]
	msg = msg[BLOCK_SIZE:]
	aes = AES.new(KEY, AES.MODE_CBC, t_iv)
	msg = aes.decrypt(msg)
	try:
		unpad(msg)
		print 'Good'
	except:
		print 'Bad'

def handle():
	print 'Crypto Service 1.0'
	menu()
	iv = os.urandom(16)
	gen_flag()

	while (True):
		try:
			cmd = raw_input('>')
			if (cmd == '1'):
				decrypt()
			elif (cmd == '2'):
				print FLAG
			elif (cmd == '3'):
				break
			else:
				print 'Command not Found'
		except KeyboardInterrupt:
			break

if __name__ == '__main__':
	handle()