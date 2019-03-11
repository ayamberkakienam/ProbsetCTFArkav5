# shellcode [Medium]

## File

Upload file [shellcode](shellcode).

## Build

Build `shellcode`:
```sh
gcc shellcode.c -o shellcode -pie -s -fPIC
```

## Solve

Ketika dijalankan program akan membaca file flag dan menyimpan isinya di variabel global. Setelah itu, Program meminta sebuah input yang akan dijalankan sebagai sebuah fungsi.
Program dicompile dengan flag `-pie` sehingga address dari string flag harus dihitung berdasarkan base address dari binary.
Base address dari binary bisa didapatkan dengan menjalankan instruksi `pop` yang akan mengembalikan return address dari shellcode. Sehingga dapat dihitung offset ke puts plt dan string flag.

## PoC

```sh
python solver.py
```

## Deploy

Program ini tidak membutuhkan hal spesifik pada deployment. Contoh konfigurasi dapat dilihat pada [Dockerfile](Dockerfile). 

## Flag
`Arkav5{n1ce_sh3llcode_g4n}`