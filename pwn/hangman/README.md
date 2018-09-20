# hangman [Medium]

## File

Upload file [hangman](hangman).

## Build

Build `hangman`:
```sh
gcc -o hangman hangman.c
```

## Solve

Program akan memberikan flag apabila pengguna masuk Hall of Fame.
Dibutuhkan nilai `1000000` untuk memasuki Hall of Fame.
Terdapat vulnerability off by one byte pada pembacaan string (fungsi `read_string()` line 26: `while i <= len`).
Hal tersebut menyebabkan pengguna dapat menulis nama (`name`) melebihi ukuran sebenarnya dengan penambahan 1 karakter setiap kali melakukan `change_name()`.
Dengan memanfaatkan vulnerability tersebut, skor Hall of Fame dapat dibuat menjadi `0` serta word_list diganti menjadi string yang telah diketahui.

## PoC

```sh
python solver.py
```

## Deploy

Program ini tidak membutuhkan hal spesifik pada deployment. Contoh konfigurasi dapat dilihat pada [Dockerfile](Dockerfile). 

## Flag
`Arkavidia{0ff_13y_0n3_3xpl01t3d}`