# cariuang [Easy]

## File

Upload file [cariuang](cariuang) dan [cariuang.c](cariuang.c).

## Build

Build `cariuang`:
```sh
gcc -o cariuang cariuang.c
```

## Solve

Program akan memberikan flag apabila variabel `uang` lebih besar atau sama dengan `4.29 milyar`.
Pada program ini, untuk setiap penambahan uang, program akan melakukan `sleep`.
Terdapat vulnerability pada line 51, yaitu `waktu *= 5`.
Karena `waktu` merupakan `signed integer`, maka apabila terjadi overflow `waktu` dapat menjadi bilangan negatif.

## PoC

```sh
python solver.py
```

## Deploy

Program ini tidak membutuhkan hal spesifik pada deployment. Contoh konfigurasi dapat dilihat pada [Dockerfile](Dockerfile). 

## Flag
`Arkav5{k3rja_l3mbur_b4ga1_b3b3k}`