# nini-chan [Hard]

## File

Upload file [nini-chan](nini-chan).

## Build

Jika diperlukan suatu waktu, seperti flag bocor dan ingin mengganti flag, maka lakukan build ulang.

### Prerequisites
- Go 1.6+
- Make

Edit flag di file [hasher.go](hasher/hasher.go).

Build `hasher`:
```sh
cd hasher && make & cd ..
```
Copy output ke variabel `flagHash` di source code [nini-chan.go](nini-chan.go).

Build `nini-chan`:
```sh
make
```

Lakukan pengujian:
```sh
./nini-chan <flag>
```

Jika benar, program akan mengeluarkan flag dengan `exit code = 0`.

## Solve

Karena dibuat dengan Go, program akan sulit dilakukan reversing.
Namun, challenge ini dapat diselesaikan dengan *side-channel attack*.
Hal ini disebabkan program melakukan pengecekan input secara sekuensial.
Jika input di indeks `i` tidak sesuai, program akan langsung exit.
Logikanya, semakin banyak karakter input dari depan yang benar, otomatis jumlah instruksi yang dijalankan akan semakin banyak.
Kita dapat menghitung jumlah instruksi tersebut dengan `pintools` dan modul `inscount`.
Alternatif yang lebih mudahnya, kita dapat menggunakan `gdb` dan memasang breakpoint saat melakukan perbandingan yang membuat programnya exit.
Lalu, lakukan bruteforce karakter satu per satu hingga mendapatkan flag.

## PoC

Edit path pada file [solver.py](solver.py), lalu jalankan:
```sh
python3 solver.py
```

## Flag
`Arkav5{g0_RE_h4rd}`