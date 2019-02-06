from PIL import Image
from numpy import array

d2 = []
for i in range(625):
    im = Image.open('data/um_' + str(i+1) + '.jpg')
    r, g, b = im.getpixel((3,3))
    d2.append(r)
img = Image.new("L", (25, 25))
img.putdata(d2)
new_width  = 420
new_height = 420
img = img.resize((new_width, new_height))

# https://stackoverflow.com/questions/11142851/adding-borders-to-an-image-using-python
old_size = img.size
new_size = (500, 500)
new_im = Image.new("RGB", new_size, "white")   ## luckily, this is already black!
new_im.paste(img, ((new_size[0]-old_size[0])/2,
                      (new_size[1]-old_size[1])/2))

new_im.show()
# Scan the QR and get the flag