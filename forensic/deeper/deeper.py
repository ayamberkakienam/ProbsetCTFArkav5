from PIL import Image

img = Image.open('download.png')

pix = img.load()

for i in range(25):
	for j in range(25):
		r, g, b, a = pix[j,i]
		if r == 255: # putih
			new_img = Image.new("RGB", (11, 11), "white")
		else:
			new_img = Image.new("RGB", (11, 11))
		new_img.save('um_' + str(i*25 + (j+1)) + '.jpg')