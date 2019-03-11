# paddle [Medium]

## File

Upload file [server-fix.py](server-fix.py).

## Solve

Program akan melakukan enkripsi pada flag dengan menggunakan AES-CBC dengan menggunakan padding.
Padding yang digunakan pada umumnya menggunakan `chr(len) * len` dengan len merupakan panjang yang dibutuhkan agar sesuai blok.
Namun padding yang digunakan pada program ini ialah `chr(len + 20) * len`.
User dapat melakukan decrypt terhadap ciphertext dan mengembalikan `Good` jika padding sesuai. Untuk mendapatkan flag yang diencrypt dapat dilakukan Padding Oracle Attack untuk merecover flag yang diberikan namun dengan padding yang dicustom.

## PoC

```sh
python solver.py
```

## Flag
`Arkav5{p4dd1ng_0r4cle_AeS}`