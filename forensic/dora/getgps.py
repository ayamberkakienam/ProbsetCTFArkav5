import os

for i in range(133):
	# https://github.com/bennoleslie/pexif
	os.system('python scripts/getgps.py out/' + str(i+1) + '.jpg')