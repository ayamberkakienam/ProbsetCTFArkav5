import os, random

tipu = ['Arkav{hoho}', 'ArkavX{eaaa}', 'ArkavLima{kenadeh}', 'arkv5{bukaniniflagnya}', '4rk4v5{hehe}', 'ARKAV5{huhu}', 'arkav5{hihi}', 'Arkav2019{bukanflag}', 'Lorem', 'ipsum', 'dolor', 'sit', 'amet', 'consectetur', 'adipiscing', 'elit', 'Etiam', 'commodo', 'sodales', 'vestibulum', 'ante', 'Quisque', 'Morbi', 'iaculis', 'justo', 'auctor', 'fringilla', 'tristique', 'ArkaV5{bukanflag}', 'Praesent', 'euismod', 'finibus', 'tincidunt', 'Arkav6{tahundepan}', 'Arkav5Arkav5Arkav5', 'Arkav5[hee]', 'rutrum', 'flagflagflag', 'lololololol', 'NurhadiAldo', 'McQueenYaQueen', 'Arkav55{upskenadeh}', 'dictum', 'Arkav{halo}', 'Arkavidia{c00l}', 'Arkavidia5{noooootflag}']

last_choice = ''

for i in range(1, 731):
	if i == 666:
		os.system('echo "Arkav5{git_s4ve_y0uR_h1st0ri3s}" > flag')
	else:
		choice = random.choice(tipu)
		while last_choice == choice:
			choice = random.choice(tipu)
		os.system('echo "'+ choice +'" > flag')
		last_choice = choice
	os.system('git add flag')
	os.system('git commit -m "'+ str(i) +'"')

os.system('echo "Nyari ape gan?" > flag')
os.system('git add flag')
os.system('git commit -m "731"')
