# Brainduck [Hard]

## File yang diberikan ke peserta
Semua file `.php` pada folder [challenge](challenge/) **kecuali**:
- [flag.php](challenge/flag.php)
- [config.php](challenge/config.php)

## Build
Edit port pada file [.env](.env) menjadi port yang ingin diforward ke host. Lalu jalankan:
```
docker-compose up
```
atau sebagai daemon
```
docker-compose up -d
```

## Vulnerability
Saat melakukan upload file, string `.php` pada nama file akan di-filter. Akan tetapi, filter tidak dilakukan secara rekursif. Hal ini menyebabkan string `.p.phphp` akan diubah menjadi `.php`.

Selanjutnya, web akan melakukan pengecekan isi file yang diupload. File Brainduck tidak boleh mengandung karakter alfanumerik ataupun whitespace. Nyatanya, PHP membolehkan short open tag secara default, yaitu `<?=` untuk menandakan kode PHP dimulai. Hal ini menyebabkan kita dapat membuat webshell hanya dengan karakter-karakter simbol. Salah satu webshell yang dapat digunakan adalah: [1](https://gist.github.com/mvisat/03592a5ab0743cd43c2aa65bf45fef21), [2](https://securityonline.info/bypass-waf-php-webshell-without-numbers-letters/).

## Proof Of Concept
- Registrasi dan login user
- Upload file [webshell](solver/webshell.p.phphp)
- Akses http://server.ip/uploads/nama_file.php?_=system&__=cat%20../flag.php

## Flag
`Arkav5{b1b1t_unGGul_C4n_3X3cute_PHP_w1th_symb0ls}`
