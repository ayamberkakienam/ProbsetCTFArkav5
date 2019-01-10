# 100 [Medium]

## File

Upload file [100](100).

## Build

Build `100`:
```sh
gcc -no-pie 100.c -o 100
```

## Solve

Program akan memberikan flag apabila input pengguna sama dengan fungsi(data).
Namun, pada soal ini, terdapat 100 buah fungsi yang berbeda-beda. Selain itu, setiap fungsi tersebut menggunakan `rand()` untuk perhitungan.
Walaupun diberikan `srand(1337)`, melakukan reversing terhadap binary sulit.
Berbeda dengan soal reversing pada umumnya, pada soal ini flag merupakan hasil fungsi(data) dan bukan input. Untuk itu, apabila kita menipu program seakan-akan input kita benar, flag akan didapat. Penyelesaian soal ini dilakukan dengan mengubah fungsi `eEeee`, yaitu fungsi pembanding, agar selalu dianggap benar. `cmp edx, eax (39 C2)` diubah menjadi `cmp eax, eax (39 C0)`. Selain itu, karena input seharusnya 504 byte, untuk mendapatkan flag digunakan 504 byte asal.

## PoC

```sh
python -c "print 'a' * 504" | ./patched
```

## Flag
`Arkav5{m4k3_17_4lw4Y5_tRU3}`