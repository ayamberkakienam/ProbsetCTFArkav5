# satuduatiga [Medium]

## File

Upload file [satuduatiga.py](satuduatiga.py).

## Solve

Program akan melakukan enkripsi per-huruf dari kata atau kalimat.
Enkripsi dilakukan dengan mengalikan tiap karakter dengan angka `1337 - 13337` sebanyak `733 - 3331` kali.
Untuk setiap karakter ke-n, tiap pengali bernilai `pengali += 1`.
Dekripsi dapat dilakukan dengan mencoba membagi setiap hasil enkripsi huruf dengan nilai `13337 - 1337` mengurut mengecil.
Apabila pembagian tidak bersisa untuk setiap huruf, maka angka tersebut merupakan salah satu pengali.
Contoh apabila pengali adalah 37 dan terdapat 3 huruf, maka huruf pertama akan dicoba dibagi 37, huruf kedua dicoba dibagi 38, dan huruf ketiga dicoba dibagi 39. 
Adapun hal tersebut dapat dinyatakan valid hanya jika terdapat 2 pembagian dengan bilangan prima. Hal tersebut dikarenakan bilangan non-prima dapat dihasilkan dari faktor-faktor pengali lain.
Karena nilai pengali besar perlu jumlah karakter yang besar agar terdapat minimal 2 pembagian prima. Untuk itu, agar dekripsi reliable, harus digunakan difficulty Hard pada program. 

## PoC

```sh
python solver.py
```

## Flag
`Arkav5{s4tuduatig4_s4yangs3emua4ny4a}`