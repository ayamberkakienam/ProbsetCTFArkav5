data = raw_input('Flag:')
data = data[14:] + data[:14]
if (len(data) != 28):
	print "Incorrect!"
	exit()
if (data[-2] != 'n'):
	print "Incorrect!"
	exit()
if (data[10] != '3'):
	print "Incorrect!"
	exit()
if (data[::-2] != '_otp5ar}3l3333'):
	print "Incorrect!"
	exit()
if (data[::-3] != '_hpvrtls3r'):
	print "Incorrect!"
	exit()
if (data[::-5] != '_yat3v'):
	print "Incorrect!"
	exit()
if (data[::-7] != '_{}s'):
	print "Incorrect!"
	exit()
if (data[::4] != 'rr_tk{h'):
	print "Incorrect!"
	exit()
if (data[::7] != 'r3Ap'):
	print "Incorrect!"
	exit()
print "Correct!"