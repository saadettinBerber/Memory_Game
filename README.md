# Eş Kartı Bulma Oyunu

Bu proje, BLM1011 Bilgisayar Bilimlerine Giriş dersi kapsamında verilen zeka oyunu projesidir. Oyunda, bir oyuncunun bilgisayara karşı oynadığı, eş kartın yerini hatırlama oyunu gerçekleştirilmektedir.

## Açıklama

Oyunda, oyuncu ve bilgisayar sırayla kartları açarak eş kartları bulmaya çalışırlar. Bilgisayar, en son açılan N adet kartın koordinatlarını hatırlayabilmektedir. Oyunda üç seviye bulunmaktadır: kolay, orta ve zor. Her seviyede oyun alanı ve bilgisayarın hatırlama miktarı artmaktadır.

- **Kolay:** 4x4 alan, 16 kart (8 eş kart), bilgisayar 2 kart hatırlar.
- **Orta:** 6x6 alan, 36 kart (18 eş kart), bilgisayar 6 kart hatırlar.
- **Zor:** 8x8 alan, 64 kart (32 eş kart), bilgisayar 16 kart hatırlar.

### Oyun Kuralları

- Oyuncu, rasgele seçtiği iki kartı açarak oyuna başlar.
- Eşleşirse, iki kart açma hakkı daha bulunmaktadır. Eşleşmezse, sıra bilgisayara geçer.
- Bilgisayar, hafızasında tuttuğu kartları açarak eş kart bulmaya çalışır.
- Oyunun başında eş kartlar oyun alanına rasgele olarak dağıtılmaktadır.
## Kullanım
1)Oyunu başlatın ve seviye seçin (Kolay, Orta, Zor).
2)Oyuncu olarak, tahmin yaparken 1. kartın satır ve sütununu, sonrasında 2. kartın satır ve sütununu girdi olarak verin.
3)Bilgisayarın yaptığı tahminler her turda ekrana yazdırılacaktır.
4)Tüm kartlar açılmadan kazanan taraf belirtilir ve oyun sonlandırılır.

## Gereksinimler
C programlama dili ile uyumlu bir derleyici (örn. GCC)
Temel bilgisayar bilgisi ve terminal/komut satırı kullanımı
