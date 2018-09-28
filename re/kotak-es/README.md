# Kotak Es [Easy]

## File

Upload file [kotak-es](kotak-es).

## Build

Jika diperlukan suatu waktu, seperti flag bocor dan ingin mengganti flag, maka lakukan build ulang.

### Prerequisites
- GCC
- Make

Edit flag di file [generate.c](generate.c).

Lalu build dan jalankan:
```sh
make generate && ./generate
```

Copy output yang dihasilkan ke file [kotak-es.c](kotak-es.c).

Build `kotak-es`:
```sh
make
```

Lakukan pengujian:
```sh
./kotak-es <flag>
```

Jika benar, program akan mengeluarkan flag dengan `exit code = 0`.

## Solve

Diberikan S-Box yang berjumlah 256. Program hanya mengikuti nilai S-Box dari pertama hingga terakhir. Jika hasil runutan S-Box ke-i sama dengan nilai variabel flag ke-i, maka karakter ke-i benar. Peserta tinggal melakukan bruteforce pada tiap karakternya.

## Proof of Concept

Edit variabel S-Box dan flag jika diperlukan, lalu jalankan:
```sh
python3 solver.py
```

## Flag
`Arkav5{SB0x_r3ver5ing_50_ez}`