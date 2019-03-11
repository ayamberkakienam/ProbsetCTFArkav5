# vault [Easy]

## File

Upload file [vault](vault).

## Build

Build `vault`:
```sh
gcc vault.c -o vault -fno-stack-protector -m32
```

## Solve

Program memiliki vulnerability pada input index array.
Namun, input maupun output yang diterima berupa float. Sehingga untuk membuat payload diperlukan converter dari float ke long. Attack dilakukan dengan melakukan ke one gadget dengan melakukan leak libc_main_ret terlebih dahulu.

## PoC

```sh
python solver.py
```

## Deploy

Program ini tidak membutuhkan hal spesifik pada deployment. Contoh konfigurasi dapat dilihat pada [Dockerfile](Dockerfile). 

## Flag
`Arkav5{Wr1t3_d4ta_us1ng_fl0at}`