import random
import sys

def encrypt(word):
	num = random.randint(733, 3331)

	multiplier = []
	for j in range(num):
		multiplier.append(random.randint(1337, 13337))

	encrypted = []
	for j in range(len(word)):
		encrypted.append(ord(word[j]))
		for k in range(num):
			encrypted[-1] *= multiplier[k]+j

	return encrypted

with open("flag","r") as f:
	FLAG = f.read()

print "Welcome to 'The Encryption Game'!\n"
print "Choose your difficulty."
print "1. Easy"
print "2. Medium"
print "3. Hard"
sys.stdout.write("Your choice: ")
sys.stdout.flush()

difficulty = input()

if (difficulty == 1):
	with open("easy", "r") as f:
		words = f.read().strip().split('\n')
	print "\nDecrypt 10 5-letter encrypted words or sentences."
	sys.stdout.flush()
	loop = 10
elif (difficulty == 2):
	with open("medium", "r") as f:
		words = f.read().strip().split('\n')
	print "\nDecrypt 8 10-letter encrypted words or sentences."
	sys.stdout.flush()
	loop = 8
elif (difficulty == 3):
	with open("hard", "r") as f:
		words = f.read().strip().split('\n')
	print "\nDecrypt 5 40-letter encrypted words or sentences."
	sys.stdout.flush()
	loop = 5


for i in range(loop):

	word = words[random.randint(0, len(words)-1)]
	encrypted = encrypt(word)
	print encrypted
	sys.stdout.flush()

	sys.stdout.write("Decrypted: ")
	sys.stdout.flush()

	decrypted = raw_input()
	if (decrypted == word):
		print 'Nice!'
		sys.stdout.flush()
	else:
		print 'Nope.'
		print 'Bye!'
		sys.stdout.flush()
		break

if (i == loop - 1):
	print 'Here is the encrypted FLAG.'
	print encrypt(FLAG)
	sys.stdout.flush()
