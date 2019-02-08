# Arkavidia Cipher [Medium]

## File

Upload file [arkavidiaCipher.py](arkavidiaCipher.py) dan [a3VuY2lueWEgbWlnb3JlbmdwYWtldGVsdXIK.txt](a3VuY2lueWEgbWlnb3JlbmdwYWtldGVsdXIK.txt).

## Solve

Program sebenarnya merupakan variant dari vigenere cipher yaitu Full Vigenere Cipher, ([Kriptografi Klasik, [Rinaldi Munir]](http://informatika.stei.itb.ac.id/~rinaldi.munir/Kriptografi/2018-2019/Kriptografi-Klasik-Bagian2(2019).pdf)).
Enkripsi dilakukan mirip seperti vigenere cipher namun matriks yang digunakan berbeda. Matriks dibentuk dengan fungsi random dengan seed yaitu kunci dari enkripsi itu juga. Kunci didapatkan dari nama file a3VuY2lueWEgbWlnb3JlbmdwYWtldGVsdXIK.txt dengan `base64decode`. Selanjutnya diperlukan implementasi dari fungsi dekripsi.

## PoC

Get Kunci

```sh
echo 'a3VuY2lueWEgbWlnb3JlbmdwYWtldGVsdXIK' | base64 -d
```

Implentasi fungsi dekripsi

```py
r.append(chr(S[ord(q[i % len(q)].upper())-65].index(ord(ch.upper())-64)+65))
```

Jalankan program dengan cipherteks dan kunci yang sudah ada

## Flag
`AKRAV5{INDOMIIIISELEERAKU}`

Note: flag incase-sensitive
