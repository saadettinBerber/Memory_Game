#include <stdio.h>
#include <stdlib.h>

int main()
{
    char confirm, information, devam;
    serhat:
    printf("\tHosgeldinizzz\n");
    printf("Zeka Oyunu: Es Karti Bulma\n");
    main:
    printf("Bilgilendirme almak ister misiniz?\nAlmak istiyorsaniz e harfini tuslayiniz.\n");
    scanf("%s", &information);
    if(information == 'e'){
        printf("Oyun es karti bulma oyunu. Belli sayida kartlar var. Bu kartlarin icinde ikiserli sekilde es kartlar var.\n");
        printf("Biraz da oynanistan bahsedelim. Sutun ve satirlardan olusan matriksimiz(sayilardan olusuyor) var. Basta 2 tane koordinat giriyoruz. Yani oncelikle satir numarasini girerek. Satir ve sutun numaralarimizi belirleyip matristeki sayiyi acmis oluyoruz.\n");
        printf("Eger girdiginiz 2 koordinat ayni ise 1 kere daha koordinat girme hakki kazaniyorsunuz. Eger bilemezsen bilgisayara geciyor sira. Bilgisayar yapiyor tahminini.\n");
        printf("Kolay mod secerseniz toplamda 16 kart olacak. Yani 8 tane farkli sayi var demek. 5 tane es karti bulursaniz oyunu kazaniyorsunuz\n");
        printf("Orta mod secerseniz toplamda 36 kart olacak. Yani 18 tane farkli sayi var demek. 10 tane es karti bulursaniz oyunu kazaniyorsunuz\n");
        printf("Zor mod secerseniz toplamda 64 kart olacak. Yani 32 tane farkli sayi var demek. 18 tane es karti bulursaniz oyunu kazaniyorsunuz\n");}
    printf("Oyunun zorluk seviyesini ne istersiniz?\nKolaysa: k\nOrta: o\nZor: z\nHarflerini giriniz.");
    scanf("%s", &confirm);
    if(confirm == 'k'){
    int i, j, e, x, q, koorSatir1, koorSutun1, koorSatir2, koorSutun2, show, show2, top, top2, hak1, hak2, kontrol, kontrol2, temp1, temp2;
    int sayac, sayac2, sayac3, sayac4;
    srand(time(NULL));
    int view[4][4] = {};
    char view2[4][4] = {};
    int memory[2] = {0, 0};
    int dizi[100];
    char matriks[4][4] = {};
    show2 = 0;
    koorSatir1 = 1; koorSatir2 = 1; koorSutun1 = 1; koorSutun2 = 1;
    kontrol = 1;
    kontrol2= 1;
    temp1 = 0;
// Dizinin içine 1-8 aralýðýndaki rakamlarýndan ikiþer tane toplamda 16 sayýlýk dizi tanýmlýyoruz.
    i = 1;
        for(j = 0; j <16 ; j++){
            dizi[j] = i;
            i++;
            if(i == 9)
                i = 1;
        }
        // Oyunumuza random þekilde sayilari oluþturuyoruz.
    int game[4][4] = {};
    int hile[4][4] = {};
    e = 0;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            x = (rand() % (16 - e));
            game[i][j] = dizi[x];
            hile[i][j] = dizi[x];
            e++;
            for(x; x<16; x++){
                dizi[x] = dizi[x + 1];
            }
        }
    }
    for(i = 0; i < 4; i++){
            for(j = 0; j<4; j++){
                printf("%d\t", game[i][j]);
        }
        printf("\n");
    }
    //Satýr ve sütun yazýlarý yazacak þekilde tablomuzu yazýyoruz.
    printf("         ");
    for(i = 1; i<= 4; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 4; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<4; j++){
                matriks[i][j] = '*';
                printf("%c\t", matriks[i][j]);
        }
        printf("\n");
    }
    show = 0;
    show2 = 0;
    top = 0;
    top2 = 0;
    //Oyun baslangici
    while(show < 10 && show2 < 10 && kontrol && kontrol2){
    do{
    xx:
    ss:
    printf("Oyuncu sirasi: 1. oyuncu\n");
    printf("1. koordinat degerlerinizi giriniz.\n");
    printf("1. satir: ");
    scanf("%d", &koorSatir1);
    printf("1. sutun: ");
    scanf("%d", &koorSutun1);
    printf("koordinat(%d, %d) = %d\n", koorSatir1, koorSutun1, game[koorSatir1 - 1][koorSutun1 - 1]);
    printf("2. koordinat degerlerinizi giriniz.\n");
    printf("2. satir: ");
    scanf("%d", &koorSatir2);
    printf("2. sutun: ");
    scanf("%d", &koorSutun2);
        if(0>=koorSatir1 || koorSatir1>=5 || 0>=koorSatir2 || koorSatir2>=5 || 0>=koorSutun1 || koorSutun1>=5 || 0>=koorSutun2 || koorSutun2>=5){
            printf("1-4 arasinda sayi giriniz.\n");
            goto xx;
            }
    koorSatir1--;
    koorSatir2--;
    koorSutun1--;
    koorSutun2--;
    printf("koordinat(%d, %d) = %d\n",koorSatir2 + 1, koorSutun2 + 1, game[koorSatir2][koorSutun2]);
    if(koorSatir1 == koorSatir2 && koorSutun1 == koorSutun2){
        printf("Ayni koordinatlari girdiniz. Tekrar giriniz\n");
        goto ss;
    }

    top++;
    hak1 = 0;
    if(game[koorSatir1][koorSutun1] == game[koorSatir2][koorSutun2]){
        matriks[koorSatir1][koorSutun1] = '-';
        matriks[koorSatir2][koorSutun2] = '-';
        game[koorSatir1][koorSutun1] = temp1;
        temp1--;
        game[koorSatir2][koorSutun2] = temp1;
        temp1--;
        show = show + 2;
        hak1 = 1;
        printf("\tBildinizz\n\a");
// Tabloyu ekrana yazdýrýyoruz.TAbi ki deðiþmiþ halleriyle.
        printf("         ");
    for(i = 1; i<= 4; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 4; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<4; j++){
                printf("%c\t", matriks[i][j]);
        }
        printf("\n");
    }
    getch();

    }
    else{
        printf("\tBilemediniz\a\n");
        // Sayiyi bulamadýnýz ama hangi sayilari tahmin ettiniz onu tablo þeklinde gösterir.
        printf("         ");
    for(i = 1; i<= 4; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 4; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<4; j++){
                if(koorSatir1 == i && koorSutun1 == j){
                    view[i][j] = game[koorSatir1][koorSutun1];
                    printf("%d\t", view[i][j]);}
                else if(koorSatir2 == i && koorSutun2 == j){
                    view[i][j] = game[koorSatir2][koorSutun2];
                    printf("%d\t", view[i][j]);}
                else{
                    view2[i][j] = '*';
                    printf("%c\t", view2[i][j]);}
        }
        printf("\n");

    }
    }
    getch();
    if(show == 10)
        kontrol = 0;
    } while( hak1 == 1 && show < 10 && kontrol);
    //Oyuncu hakkýný kaybettikten sonra sýra artik bilgisayara geçer ve yine tabloyu yazdýrdým.
    printf("         ");
    for(i = 1; i<= 4; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 4; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<4; j++){
                printf("%c\t", matriks[i][j]);
        }
        printf("\n");
    }
    //Bilgisayar oynamaya baþlar.
    if(kontrol){
    do{
    sayac = -1;
    sayac2= -2;
    sayac3 = -1;
    sayac4 = -2;
    while(sayac == sayac3 && sayac2 == sayac4){
    sayac = (rand() % 4);
    sayac2 = (rand() % 4);
    sayac3 = (rand() % 4);
    sayac4 = (rand() % 4);
    }
    memory[0] = game[koorSatir1][koorSutun1];
    memory[1] = game[koorSatir2][koorSutun2];
    if(game[sayac][sayac2] == game[koorSatir1][koorSutun1] && sayac != koorSatir1 && sayac2 != koorSutun1){
        sayac3 = koorSatir1;
        sayac4 = koorSutun1;}
    if(game[sayac3][sayac4] == game[koorSatir2][koorSutun2] && sayac3 != koorSatir2 && sayac4 != koorSutun2){
        sayac = koorSatir2;
        sayac2 = koorSutun2;}
    if(game[sayac3][sayac4] == game[koorSatir1][koorSutun1] && sayac3 != koorSatir1 && sayac4 != koorSutun1){
        sayac = koorSatir1;
        sayac2 = koorSutun1;}
    if(game[sayac][sayac2] == game[koorSatir2][koorSutun2]&& sayac != koorSatir2 && sayac2 != koorSutun2){
        sayac3 = koorSatir2;
        sayac4 = koorSutun2;}


    printf("Bilgisayarin girdigi koordinat: (%d, %d) = %d\n", sayac +1, sayac2 + 1, game[sayac][sayac2]);
    printf("Bilgisayarin girdigi koordinat: (%d, %d) = %d\n", sayac3 + 1, sayac4 + 1, game[sayac3][sayac4]);
    top2++;
    hak2 = 0;
    if(game[sayac][sayac2] == game[sayac3][sayac4]){
        matriks[sayac][sayac2] = '-';
        matriks[sayac3][sayac4] = '-';
        game[sayac][sayac2] = temp1;
        temp1--;
        game[sayac3][sayac4] = temp1;
        temp1--;
        show2 = show2 + 2;
        hak2 = 1;
        printf("\tBilgisayar bildi.\n\a");
        memory[0] = 0;
        memory[1] = 0;
        printf("         ");
    for(i = 1; i<= 4; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 4; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<4; j++){
                if(sayac == i && sayac2 == j){
                    view[i][j] = hile[sayac][sayac2];
                    printf("%d\t", view[i][j]);}
                else if(sayac3 == i && sayac4 == j){
                    view[i][j] = hile[sayac3][sayac4];
                    printf("%d\t", view[i][j]);}
                else{
                    view2[i][j] = '*';
                    printf("%c\t", view2[i][j]);}
        }
        printf("\n");
    }
    getch();
    }
    else{
        printf("\tBilgisayar bilemedi\a\n");
        printf("         ");
    for(i = 1; i<= 4; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 4; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<4; j++){
                if(sayac == i && sayac2 == j){
                    view[i][j] = game[sayac][sayac2];
                    printf("%d\t", view[i][j]);}
                else if(sayac3 == i && sayac4 == j){
                    view[i][j] = game[sayac3][sayac4];
                    printf("%d\t", view[i][j]);}
                else{
                    view2[i][j] = '*';
                    printf("%c\t", view2[i][j]);}
        }
        printf("\n");
    }
    getch();
    }
    if(show2 == 10)
        kontrol2 = 0;

    } while( hak2 == 1 && show2 < 10 && kontrol2);}
    printf("         ");
    for(i = 1; i<= 4; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 4; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<4; j++){
                printf("%c\t", matriks[i][j]);
        }
        printf("\n");}

}
        if(show2<show)
            printf("Oyunu bitirdiniz.\n%d hak kullandiniz\n",top);
        else
            printf("Bilgisayar kazandi.\n%d hak kullandi\n",top2);
    }

    else if(confirm == 'o'){
    int i, j, e, x, q, koorSatir1, koorSutun1, koorSatir2, koorSutun2, show, show2, top, top2, hak1, hak2, kontrol, kontrol2, don, gosterim1, gosterim2, bilemedi1, bilemedi2;
    int sayac, sayac2, sayac3, sayac4, sayac123, negatif, permission, deger1, deger2;
    int bildi1, bildi2, temp, temp2, tek, cift;
    srand(time(NULL));
    int view[6][6] = {};
    char view2[6][6] = {};
    int memory[6] = {0};
    int dizi[100];
    char matriks[6][6] = {};
    koorSatir1 = 1; koorSatir2 = 1; koorSutun1 = 1; koorSutun2 = 1;
    bildi1 = 1;
    bildi2 = 1;
    sayac123 = 0;
    negatif = -1;
    // Dizinin içine 1-16 aralýðýndaki rakamlardan ikiþer tane toplamda 32 sayýlýk dizi tanýmlýyoruz
    i = 1;
        for(j = 0; j < 36 ; j++){
            dizi[j] = i;
            i++;
            if(i == 19)
                i = 1;}
    // Oyunumuza random þekilde sayilari oluþturuyoruz.
    int game[6][6] = {};
    int trick[6][6] = {};
    e = 0;
    for(i = 0; i < 6; i++){
        for(j = 0; j < 6; j++){
            x = (rand() % (36 - e));
            game[i][j] = dizi[x];
            trick[i][j] = game[i][j];
            e++;
            for(x; x<36; x++){
                dizi[x] = dizi[x + 1];}
        }
    }
    //Random oluşturulan matriksi gösterdik
    for(i = 0; i < 6; i++){
            for(j = 0; j < 6; j++){
                printf("%d\t", game[i][j]);}
        printf("\n");}
    //Satır ve sütun yazýlarý yazacak þekilde tablomuzu yazýyoruz.
    printf("         ");
    for(i = 1; i<= 6; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 6; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<6; j++){
                matriks[i][j] = '*';
                printf("%c\t", matriks[i][j]);
        }
        printf("\n");
    }
    show = 0;
    show2 = 0;
    top = 0;
    top2 = 0;
    //Oyun baslangici
    while(show < 20 && show2 < 20 && bildi1 && bildi2){
    do{
    xxx:
    sas:
    printf("Oyuncu sirasi: 1. oyuncu\n");
    printf("1. koordinat degerlerinizi giriniz.\n");
    printf("1. satir: ");
    scanf("%d", &koorSatir1);
    printf("1. sutun: ");
    scanf("%d", &koorSutun1);
    printf("koordinat(%d, %d) = %d\n", koorSatir1, koorSutun1, game[koorSatir1 - 1][koorSutun1 - 1]);
    printf("2. koordinat degerlerinizi giriniz.\n");
    printf("2. satir: ");
    scanf("%d", &koorSatir2);
    printf("2. sutun: ");
    scanf("%d", &koorSutun2);
        if(0>koorSatir1 || koorSatir1>6 || 0>koorSatir2 || koorSatir2>6 || 0>koorSutun1 || koorSutun1>6 || 0>koorSutun2 || koorSutun2>6){
            printf("1-6 arasinda sayi giriniz.\n");
            goto xxx;
            }
    koorSatir1--;
    koorSatir2--;
    koorSutun1--;
    koorSutun2--;
    printf("koordinat(%d, %d) = %d\n",koorSatir2 + 1, koorSutun2 + 1, game[koorSatir2][koorSutun2]);
    if(koorSatir1 == koorSatir2 && koorSutun1 == koorSutun2){
        printf("Ayni koordinatlari girdiniz. Tekrar giriniz\n");
        goto sas;
    }

    top++;
    hak1 = 0;
    if(game[koorSatir1][koorSutun1] == game[koorSatir2][koorSutun2]){
        matriks[koorSatir1][koorSutun1] = '-';
        matriks[koorSatir2][koorSutun2] = '-';
        game[koorSatir1][koorSutun1] = negatif;
        negatif--;
        game[koorSatir2][koorSutun2] = negatif;
        negatif--;
        show = show + 2;
        hak1 = 1;
        printf("\tBildinizz\n\a");
// Tabloyu ekrana yazdýrýyoruz.TAbi ki deðiþmiþ halleriyle.
        printf("         ");
    for(i = 1; i<= 6; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 6; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<6; j++){
                printf("%c\t", matriks[i][j]);
        }
        printf("\n");
    }
    getch();

    }
    else{
        printf("\tBilemediniz\a\n");
        // Sayiyi bulamadýnýz ama hangi sayilari tahmin ettiniz onu tablo þeklinde gösterir.
        printf("         ");
    for(i = 1; i<= 6; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 6; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<6; j++){
                if(koorSatir1 == i && koorSutun1 == j){
                    view[i][j] = game[koorSatir1][koorSutun1];
                    printf("%d\t", view[i][j]);}
                else if(koorSatir2 == i && koorSutun2 == j){
                    view[i][j] = game[koorSatir2][koorSutun2];
                    printf("%d\t", view[i][j]);}
                else{
                    view2[i][j] = '*';
                    printf("%c\t", view2[i][j]);}
        }
        printf("\n");

    }
    }
    getch();
    if(show == 20)
        bildi1 = 0;
    }while( hak1 == 1 && show < 20 && bildi1);
    //Oyuncu hakkýný kaybettikten sonra sonra artik bilgisayara geçer ve yine tabloyu yazdýrdým.
    printf("         ");
    for(i = 1; i<= 6; i++){
        printf("%d.S\t", i);}
    printf("\n");
    for(i = 0; i < 6; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<6; j++){
                printf("%c\t", matriks[i][j]);}
        printf("\n");}
    //Kullanıcının girdiği koordinatları hafızayı atar.
    kontrol = 1;
    kontrol2 = 1;
    x = 1;
    i = 0;
    while(x && i < 6){
        if(memory[i] == 0){
            memory[i] = game[koorSatir1][koorSutun1];
            x = 0;
            kontrol = 0;}
        i++;}
    while(x == 0 && i < 6){
        if(memory[i] == 0){
            memory[i] = game[koorSatir2][koorSutun2];
            x = 1;
            kontrol2 = 0;}
        i++;}
    if(i == 6)
        i = 0;
    if(sayac123 == 6)
        sayac123 = 0;
    if (kontrol){
        memory[sayac123] = game[koorSatir1][koorSutun1];
        sayac123++;}
    if(sayac123 == 6)
        sayac123 = 0;
    if(kontrol2){
        memory[sayac123] = game[koorSatir2][koorSutun2];
        sayac123++;}

    //for(j = 0; j < 6; j++){
    //    printf("%d. eleman: %d\n", j, memory[j]);}
    //Bilgisayarda sıra
    do{
    sayac = -1;
    sayac2= -2;
    sayac3 = -1;
    sayac4 = -2;

    while(sayac == sayac3 && sayac2 == sayac4){
    sayac = (rand() % 6);
    sayac2 = (rand() % 6);
    sayac3 = (rand() % 6);
    sayac4 = (rand() % 6);
    }
    //
    //
    // Bilgisayar tahminlerini gösterir
    top2++;
    hak2 = 0;
    //printf("1.koordinat (%d, %d) ,2. koordinat(%d, %d) \n", sayac + 1, sayac2 + 1, sayac3 + 1, sayac4 + 1); // Kontrol amaçlı
    if(game[sayac][sayac2] == game[sayac3][sayac4]){
        printf("Bilgisayarin girdigi koordinat: (%d, %d) : %d\n", sayac +1, sayac2 + 1, game[sayac][sayac2]);
        printf("Bilgisayarin girdigi koordinat: (%d, %d) : %d\n", sayac3 + 1, sayac4 + 1, game[sayac3][sayac4]);
        matriks[sayac][sayac2] = '-';
        matriks[sayac3][sayac4] = '-';
        game[sayac][sayac2] = negatif;
        negatif--;
        game[sayac3][sayac4] = negatif;
        negatif--;
        show2 = show2 + 2;
        hak2 = 1;
        printf("\tBilgisayar bildi.\n\a");
        printf("         ");
    for(i = 1; i<= 6; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 6; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<6; j++){
                if(sayac == i && sayac2 == j){
                    view[i][j] = trick[sayac][sayac2];
                    printf("%d\t", view[i][j]);}
                else if(sayac3 == i && sayac4 == j){
                    view[i][j] = trick[sayac3][sayac4];
                    printf("%d\t", view[i][j]);}
                else{
                    view2[i][j] = '*';
                    printf("%c\t", view2[i][j]);}
        }
        printf("\n");
    }
    getch();
    }
    else{
        don = 1;
        gosterim1 = 1;
        permission = 0;
        tek = 1;
        for(i = 0; i < 6; i++){
            //while(tek){
            if(memory[i] == game[sayac][sayac2] && tek){
                //while(tek){
                memory[i] = 0;
                tek = 0;
                for(j = 0; j < 6; j++){
                    for(x = 0; x<6; x++){
                    if(trick[sayac][sayac2] == trick[j][x]){
                        matriks[j][x] = '-';
                        game[j][x] = negatif;
                        negatif--;
                        show2++;
// Buradaki if bloğuna girmiyor. Neden olduğunu anlayamadım bir türlü. Buradaki amacım da kart oyunu bu her sayidan ikişer tane var.
//Ben de o ikinciyi bulmak için böyle bir şey yazdım
                        if(sayac != j && sayac2 != x){
                            sayac3 = j;
                            sayac4 = x;
                            //printf("Deger1: %d, temp: %d temp2: %d\n", trick[sayac3][sayac4], sayac3 + 1, sayac4 + 1);
                            }
                                }
                            }
                        }
                    don = 0;
                    gosterim1 = 0;
                    hak2 = 1;
            //}
                        }//  en dıştaki if bloğu
        //}
                    }
    if(don == 0){
        printf("Bilgisayarin girdigi koordinat: (%d, %d) : %d\n", sayac +1, sayac2 + 1, trick[sayac][sayac2]);
        printf("Bilgisayarin girdigi koordinat: (%d, %d) : %d\n", sayac3 + 1, sayac4 + 1, trick[sayac3][sayac4]);
        printf("\tBilgisayar bildi.\n");
        printf("         ");
    for(i = 1; i<= 6; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 6; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<6; j++){
                if(sayac == i && sayac2 == j){
                    view[i][j] = trick[sayac][sayac2];
                    printf("%d\t", view[i][j]);}
                else if(sayac3 == i && sayac4 == j){
                    view[i][j] = trick[sayac3][sayac4];
                    printf("%d\t", view[i][j]);}
                else{
                    view2[i][j] = '*';
                    printf("%c\t", view2[i][j]);}
        }
        printf("\n");
    }
    getch();
    }
    if(don){
        cift = 1;
        for(x = 0; x < 6; x++){
            //while(cift){
            if(memory[x] == game[sayac3][sayac4] && cift){
               // while(cift){
                memory[x] = 0;
                cift = 0;
                for(i = 0; i < 6; i++){
                for(j = 0; j < 6; j++){
                    if(trick[sayac3][sayac4] == trick[i][j]){
                        matriks[i][j] = '-';
                        game[i][j] = negatif;
                        negatif--;
                        show2++;
// Buradaki if bloğuna girmiyor. Neden olduğunu anlayamadım bir türlü. Buradaki amacım da kart oyunu bu her sayidan ikişer tane var.
//Ben de o ikinciyi bulmak için böyle bir şey yazdım
                        if(sayac3 != i && sayac4 != j){
                            sayac = i;
                            sayac2 = j;
                            //printf("Deger2: %d, temp: %d temp2: %d\n", trick[sayac][sayac2], sayac + 1, sayac2 + 1);
                            }
                        }
                            }
                            }
                        gosterim1 = 0;
                        hak2 = 1;
                        memory[i] = 0;
                        permission = 1;
           // }
            }
       // }
                        } // en dıştaki for
                    } // en dıştaki if
    if(permission){
        printf("Bilgisayarin girdigi koordinat: (%d, %d) : %d\n", sayac3 +1, sayac4 + 1, trick[sayac3][sayac4]);
        printf("Bilgisayarin girdigi koordinat: (%d, %d) : %d\n", sayac + 1, sayac2 + 1, trick[sayac][sayac2]);
        printf("\tBilgisayar bildi.\n");
        printf("         ");
    for(i = 1; i<= 6; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 6; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<6; j++){
                if(sayac == i && sayac2 == j){
                    view[i][j] = trick[sayac][sayac2];
                    printf("%d\t", view[i][j]);}
                else if(sayac3 == i && sayac4 == j){
                    view[i][j] = trick[sayac3][sayac4];
                    printf("%d\t", view[i][j]);}
                else{
                    view2[i][j] = '*';
                    printf("%c\t", view2[i][j]);}
        }
        printf("\n");
    }
    getch();
    }
        if(gosterim1){
            hak2 = 0;
            printf("Bilgisayarin girdigi koordinat: (%d, %d) : %d\n", sayac +1, sayac2 + 1, trick[sayac][sayac2]);
            printf("Bilgisayarin girdigi koordinat: (%d, %d) : %d\n", sayac3 + 1, sayac4 + 1, trick[sayac3][sayac4]);
            printf("\tBilgisayar bilemedi\a\n");
            printf("         ");
        for(i = 1; i<= 6; i++){
            printf("%d.S\t", i);}
            printf("\n");
        for(i = 0; i < 6; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<6; j++){
                if(sayac == i && sayac2 == j){
                    view[i][j] = trick[sayac][sayac2];
                    printf("%d\t", view[i][j]);}
                else if(sayac3 == i && sayac4 == j){
                    view[i][j] = trick[sayac3][sayac4];
                    printf("%d\t", view[i][j]);}
                else{
                    view2[i][j] = '*';
                    printf("%c\t", view2[i][j]);}
        }
        printf("\n");
    }
    getch();

        }
    } // else ifadesinin süslü paranyezi
    printf("         ");
    for(i = 1; i<= 6; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 6; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<6; j++){
                printf("%c\t", matriks[i][j]);
        }
        printf("\n");
    }
    getch();
    if(show2 == 20)
        bildi2 = 0;
    }while( hak2 == 1 && show2 < 20 && bildi2);
    // Bilgisayarın hafızası
    kontrol = 1;
    kontrol2 = 1;
    x = 1;
    i = 0;
    while(x && i < 6){
        if(memory[i] == 0){
            memory[i] = game[sayac][sayac2];
            x = 0;
            kontrol = 0;}
        i++;}
    while(x == 0 && i < 6){
        if(memory[i] == 0){
            memory[i] = trick[sayac3][sayac4];
            x = 1;
            kontrol2 = 0;}
        i++;}
    if(i == 6)
        i = 0;
    if(sayac123 == 6)
        sayac123 = 0;
    if (kontrol){
        memory[sayac123] = game[sayac][sayac2];
        sayac123++;}
    if(sayac123 == 6)
        sayac123 = 0;
    if(kontrol2){
        memory[sayac123] = trick[sayac3][sayac4];
        sayac123++;}

    //for(j = 0; j < 6; j++){
    //    printf("%d. eleman: %d\n", j, memory[j]);}
} // en dıştaki while süslü parantezi
        if(show2<show)
            printf("Oyunu bitirdiniz.\n%d hak kullandiniz\n",top);
        else
            printf("Bilgisayar kazandi.\n%d hak kullandi\n",top2);
    }
    else if(confirm == 'z'){
    int i, j, e, x, q, koorSatir1, koorSutun1, koorSatir2, koorSutun2, show, show2, top, top2, hak1, hak2, kontrol, kontrol2, don, gosterim1, gosterim2, bilemedi1, bilemedi2;
    int sayac, sayac2, sayac3, sayac4, sayac123, negatif, permission, deger1, deger2;
    int bildi1, bildi2, temp, temp2, tek, cift;
    srand(time(NULL));
    int view[8][8] = {};
    char view2[8][8] = {};
    int memory[16] = {0};
    int dizi[500];
    char matriks[8][8] = {};
    koorSatir1 = 1; koorSatir2 = 1; koorSutun1 = 1; koorSutun2 = 1;
    bildi1 = 1;
    bildi2 = 1;
    sayac123 = 0;
    negatif = -1;
    // Dizinin içine 1-16 aralýðýndaki rakamlardan ikiþer tane toplamda 32 sayýlýk dizi tanýmlýyoruz
    i = 1;
        for(j = 0; j < 64 ; j++){
            dizi[j] = i;
            i++;
            if(i == 33)
                i = 1;}
    // Oyunumuza random þekilde sayilari oluþturuyoruz.
    int game[8][8] = {};
    int trick[8][8] = {};
    e = 0;
    for(i = 0; i < 8; i++){
        for(j = 0; j < 8; j++){
            x = (rand() % (64 - e));
            game[i][j] = dizi[x];
            trick[i][j] = game[i][j];
            e++;
            for(x; x<64; x++){
                dizi[x] = dizi[x + 1];}
        }
    }
    //Random oluşturulan matriksi gösterdik
    for(i = 0; i < 8; i++){
            for(j = 0; j < 8; j++){
                printf("%d\t", game[i][j]);}
        printf("\n");}
    //Satır ve sütun yazýlarý yazacak þekilde tablomuzu yazýyoruz.
    printf("         ");
    for(i = 1; i<= 8; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 8; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<8; j++){
                matriks[i][j] = '*';
                printf("%c\t", matriks[i][j]);
        }
        printf("\n");
    }
    show = 0;
    show2 = 0;
    top = 0;
    top2 = 0;
    //Oyun baslangici
    while(show < 34 && show2 < 34 && bildi1 && bildi2){
    do{
    xxxxxxxxx:
    sssssssssssssssssssssss:
    printf("Oyuncu sirasi: 1. oyuncu\n");
    printf("1. koordinat degerlerinizi giriniz.\n");
    printf("1. satir: ");
    scanf("%d", &koorSatir1);
    printf("1. sutun: ");
    scanf("%d", &koorSutun1);
    printf("koordinat(%d, %d) = %d\n", koorSatir1, koorSutun1, game[koorSatir1 - 1][koorSutun1 - 1]);
    printf("2. koordinat degerlerinizi giriniz.\n");
    printf("2. satir: ");
    scanf("%d", &koorSatir2);
    printf("2. sutun: ");
    scanf("%d", &koorSutun2);
        if(0>koorSatir1 || koorSatir1>8 || 0>koorSatir2 || koorSatir2>8 || 0>koorSutun1 || koorSutun1>8 || 0>koorSutun2 || koorSutun2>8){
            printf("1-8 arasinda sayi giriniz.\n");
            goto xxxxxxxxx;
            }
    koorSatir1--;
    koorSatir2--;
    koorSutun1--;
    koorSutun2--;
    printf("koordinat(%d, %d) = %d\n",koorSatir2 + 1, koorSutun2 + 1, game[koorSatir2][koorSutun2]);
    if(koorSatir1 == koorSatir2 && koorSutun1 == koorSutun2){
        printf("Ayni koordinatlari girdiniz. Tekrar giriniz\n");
        goto sssssssssssssssssssssss;
    }

    top++;
    hak1 = 0;
    if(game[koorSatir1][koorSutun1] == game[koorSatir2][koorSutun2]){
        matriks[koorSatir1][koorSutun1] = '-';
        matriks[koorSatir2][koorSutun2] = '-';
        game[koorSatir1][koorSutun1] = negatif;
        negatif--;
        game[koorSatir2][koorSutun2] = negatif;
        negatif--;
        show = show + 2;
        hak1 = 1;
        printf("\tBildinizz\n\a");
// Tabloyu ekrana yazdýrýyoruz.TAbi ki deðiþmiþ halleriyle.
        printf("         ");
    for(i = 1; i<= 8; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 8; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<8; j++){
                printf("%c\t", matriks[i][j]);
        }
        printf("\n");
    }
    getch();

    }
    else{
        printf("\tBilemediniz\a\n");
        // Sayiyi bulamadýnýz ama hangi sayilari tahmin ettiniz onu tablo þeklinde gösterir.
        printf("         ");
    for(i = 1; i<= 8; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 8; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<8; j++){
                if(koorSatir1 == i && koorSutun1 == j){
                    view[i][j] = game[koorSatir1][koorSutun1];
                    printf("%d\t", view[i][j]);}
                else if(koorSatir2 == i && koorSutun2 == j){
                    view[i][j] = game[koorSatir2][koorSutun2];
                    printf("%d\t", view[i][j]);}
                else{
                    view2[i][j] = '*';
                    printf("%c\t", view2[i][j]);}
        }
        printf("\n");

    }
    }
    getch();
    if(show == 34)
        bildi1 = 0;
    }while( hak1 == 1 && show < 20 && bildi1);
    //Oyuncu hakkýný kaybettikten sonra sonra artik bilgisayara geçer ve yine tabloyu yazdýrdým.
    printf("         ");
    for(i = 1; i<= 8; i++){
        printf("%d.S\t", i);}
    printf("\n");
    for(i = 0; i < 8; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<8; j++){
                printf("%c\t", matriks[i][j]);}
        printf("\n");}
    //Kullanıcının girdiği koordinatları hafızayı atar.
    kontrol = 1;
    kontrol2 = 1;
    x = 1;
    i = 0;
    while(x && i < 16){
        if(memory[i] == 0){
            memory[i] = game[koorSatir1][koorSutun1];
            x = 0;
            kontrol = 0;}
        i++;}
    while(x == 0 && i < 16){
        if(memory[i] == 0){
            memory[i] = game[koorSatir2][koorSutun2];
            x = 1;
            kontrol2 = 0;}
        i++;}
    if(i == 16)
        i = 0;
    if(sayac123 == 16)
        sayac123 = 0;
    if (kontrol){
        memory[sayac123] = game[koorSatir1][koorSutun1];
        sayac123++;}
    if(sayac123 == 16)
        sayac123 = 0;
    if(kontrol2){
        memory[sayac123] = game[koorSatir2][koorSutun2];
        sayac123++;}
    //Bilgisayarda sıra
    do{
    sayac = -1;
    sayac2= -2;
    sayac3 = -1;
    sayac4 = -2;

    while(sayac == sayac3 && sayac2 == sayac4){
    sayac = (rand() % 8);
    sayac2 = (rand() % 8);
    sayac3 = (rand() % 8);
    sayac4 = (rand() % 8);
    }
    //
    //
    // Bilgisayar tahminlerini gösterir
    top2++;
    hak2 = 0;
    //printf("1.koordinat (%d, %d) ,2. koordinat(%d, %d) \n", sayac + 1, sayac2 + 1, sayac3 + 1, sayac4 + 1); // Kontrol amaçlı
    if(game[sayac][sayac2] == game[sayac3][sayac4]){
        printf("Bilgisayarin girdigi koordinat: (%d, %d) : %d\n", sayac +1, sayac2 + 1, game[sayac][sayac2]);
        printf("Bilgisayarin girdigi koordinat: (%d, %d) : %d\n", sayac3 + 1, sayac4 + 1, game[sayac3][sayac4]);
        matriks[sayac][sayac2] = '-';
        matriks[sayac3][sayac4] = '-';
        game[sayac][sayac2] = negatif;
        negatif--;
        game[sayac3][sayac4] = negatif;
        negatif--;
        show2 = show2 + 2;
        hak2 = 1;
        printf("\tBilgisayar bildi.\n\a");
        printf("         ");
    for(i = 1; i<= 8; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 8; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<8; j++){
                if(sayac == i && sayac2 == j){
                    view[i][j] = trick[sayac][sayac2];
                    printf("%d\t", view[i][j]);}
                else if(sayac3 == i && sayac4 == j){
                    view[i][j] = trick[sayac3][sayac4];
                    printf("%d\t", view[i][j]);}
                else{
                    view2[i][j] = '*';
                    printf("%c\t", view2[i][j]);}
        }
        printf("\n");
    }
    getch();
    }
    else{
        don = 1;
        gosterim1 = 1;
        permission = 0;
        tek = 1;
        for(i = 0; i < 8; i++){
            if(memory[i] == game[sayac][sayac2] && tek){
                memory[i] = 0;
                tek = 0;
                for(j = 0; j < 8; j++){
                    for(x = 0; x<8; x++){
                    if(trick[sayac][sayac2] == trick[j][x]){
                        matriks[j][x] = '-';
                        game[j][x] = negatif;
                        negatif--;
                        show2++;
// Buradaki if bloğuna girmiyor. Neden olduğunu anlayamadım bir türlü. Buradaki amacım da kart oyunu bu her sayidan ikişer tane var.
//Ben de o ikinciyi bulmak için böyle bir şey yazdım
                        if(sayac != j && sayac2 != x){
                            sayac3 = j;
                            sayac4 = x;
                            //printf("Deger1: %d, temp: %d temp2: %d\n", trick[sayac3][sayac4], sayac3 + 1, sayac4 + 1);
                            }
                                }
                            }
                        }
                    don = 0;
                    gosterim1 = 0;
                    hak2 = 1;
                        }
                    }
    if(don == 0){
        printf("Bilgisayarin girdigi koordinat: (%d, %d) : %d\n", sayac +1, sayac2 + 1, trick[sayac][sayac2]);
        printf("Bilgisayarin girdigi koordinat: (%d, %d) : %d\n", sayac3 + 1, sayac4 + 1, trick[sayac3][sayac4]);
        printf("\tBilgisayar bildi.\n");
        printf("         ");
    for(i = 1; i<= 8; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 8; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<8; j++){
                if(sayac == i && sayac2 == j){
                    view[i][j] = trick[sayac][sayac2];
                    printf("%d\t", view[i][j]);}
                else if(sayac3 == i && sayac4 == j){
                    view[i][j] = trick[sayac3][sayac4];
                    printf("%d\t", view[i][j]);}
                else{
                    view2[i][j] = '*';
                    printf("%c\t", view2[i][j]);}
        }
        printf("\n");
    }
    getch();
    }
    if(don){
        cift = 1;
        for(x = 0; x < 8; x++){
            if(memory[x] == game[sayac3][sayac4] && cift){
                cift = 0;
                memory[x] = 0;
                for(i = 0; i < 8; i++){
                for(j = 0; j < 8; j++){
                    if(trick[sayac3][sayac4] == trick[i][j]){
                        matriks[i][j] = '-';
                        game[i][j] = negatif;
                        negatif--;
                        show2++;
// Buradaki if bloğuna girmiyor. Neden olduğunu anlayamadım bir türlü. Buradaki amacım da kart oyunu bu her sayidan ikişer tane var.
//Ben de o ikinciyi bulmak için böyle bir şey yazdım
                        if(sayac3 != i && sayac4 != j){
                            sayac = i;
                            sayac2 = j;
                            //printf("Deger2: %d, temp: %d temp2: %d\n", trick[sayac][sayac2], sayac + 1, sayac2 + 1);
                            }
                        }
                            }
                            }
                        gosterim1 = 0;
                        hak2 = 1;
                        memory[i] = 0;
                        permission = 1;
                        }
                        }
                    }
    if(permission){
        printf("Bilgisayarin girdigi koordinat: (%d, %d) : %d\n", sayac3 +1, sayac4 + 1, trick[sayac3][sayac4]);
        printf("Bilgisayarin girdigi koordinat: (%d, %d) : %d\n", sayac + 1, sayac2 + 1, trick[sayac][sayac2]);
        printf("\tBilgisayar bildi.\n");
        printf("         ");
    for(i = 1; i<= 8; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 8; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<8; j++){
                if(sayac == i && sayac2 == j){
                    view[i][j] = trick[sayac][sayac2];
                    printf("%d\t", view[i][j]);}
                else if(sayac3 == i && sayac4 == j){
                    view[i][j] = trick[sayac3][sayac4];
                    printf("%d\t", view[i][j]);}
                else{
                    view2[i][j] = '*';
                    printf("%c\t", view2[i][j]);}
        }
        printf("\n");
    }
    getch();
    }
        if(gosterim1){
            hak2 = 0;
            printf("Bilgisayarin girdigi koordinat: (%d, %d) : %d\n", sayac +1, sayac2 + 1, trick[sayac][sayac2]);
            printf("Bilgisayarin girdigi koordinat: (%d, %d) : %d\n", sayac3 + 1, sayac4 + 1, trick[sayac3][sayac4]);
            printf("\tBilgisayar bilemedi\a\n");
            printf("         ");
        for(i = 1; i<= 8; i++){
            printf("%d.S\t", i);}
            printf("\n");
        for(i = 0; i < 8; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<8; j++){
                if(sayac == i && sayac2 == j){
                    view[i][j] = trick[sayac][sayac2];
                    printf("%d\t", view[i][j]);}
                else if(sayac3 == i && sayac4 == j){
                    view[i][j] = trick[sayac3][sayac4];
                    printf("%d\t", view[i][j]);}
                else{
                    view2[i][j] = '*';
                    printf("%c\t", view2[i][j]);}
        }
        printf("\n");
    }
    getch();

        }
    } // else ifadesinin süslü paranyezi
    printf("         ");
    for(i = 1; i<= 8; i++){
        printf("%d.S\t", i);
    }
    printf("\n");
    for(i = 0; i < 8; i++){
            printf("%d. satir  ", i + 1);
            for(j = 0; j<8; j++){
                printf("%c\t", matriks[i][j]);
        }
        printf("\n");
    }
    getch();
    if(show2 == 34)
        bildi2 = 0;
    }while( hak2 == 1 && show2 < 34 && bildi2);
    // Bilgisayarın hafızası
    kontrol = 1;
    kontrol2 = 1;
    x = 1;
    i = 0;
    while(x && i < 16){
        if(memory[i] == 0){
            memory[i] = game[sayac][sayac2];
            x = 0;
            kontrol = 0;}
        i++;}
    while(x == 0 && i < 16){
        if(memory[i] == 0){
            memory[i] = trick[sayac3][sayac4];
            x = 1;
            kontrol2 = 0;}
        i++;}
    if(i == 16)
        i = 0;
    if(sayac123 == 16)
        sayac123 = 0;
    if (kontrol){
        memory[sayac123] = game[sayac][sayac2];
        sayac123++;}
    if(sayac123 == 16)
        sayac123 = 0;
    if(kontrol2){
        memory[sayac123] = trick[sayac3][sayac4];
        sayac123++;}

    //for(j = 0; j < 16; j++){
    //    printf("%d. eleman: %d\n", j, memory[j]);}
} // en dıştaki while süslü parantezi
        if(show2<show)
            printf("Oyunu bitirdiniz.\n%d hak kullandiniz\n",top);
        else
            printf("Bilgisayar kazandi.\n%d hak kullandi\n",top2);
    }
    else{
        printf("Zorluk seviyesi secmediniz.\nOyuna devam etmek istiyorsaniz d harfine basiniz.\nCikmak istiyorsaniz d disinda bir karakter giriniz.");
        scanf("%s", &confirm);
        if(confirm == 'd')
            goto main;

    }
    printf("Oyuna devam etmek ister misiniz?\nDevam etmek istiyorsaniz e harfini giriniz.");
    scanf("%s", &devam);
    if(devam == 'e')
        goto serhat;
    return 0;
}
