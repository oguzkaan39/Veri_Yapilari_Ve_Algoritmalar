//
//  main.c
//  VeriYapilariOdev
//
//  Created by Oğuzkaan Gündüz on 03.12.2017.
//  Copyright © 2017 Oğuzkaan Gündüz. All rights reserved.
//
//https://www.youtube.com/watch?v=r3uOBb3BM-0
//http://www.sadievrenseker.com/datastr/linkedlist2.cpp
//https://stackoverflow.com/questions/24881/how-do-i-fix-for-loop-initial-declaration-used-outside-c99-mode-gcc-error
//http://web.karabuk.edu.tr/hakankutucu/BLM227/VERİ%20YAPILARI%20v.6.3.pdf
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
};
struct node2
{
  int data2;
  struct node2 *next2;
};
void ekle(){
  struct node *ilkDugum=NULL;//struct tipinde ilkDugum pointeri olustur ve degerini NULL yap.
  struct node *sonDugum=NULL;//struct tipinde sonDugum pointeri olustur ve degerini NULL yap.
  struct node *yeniDugum;    //struct tipinde yeniDugum pointeri olustur.
  struct node *gecici;       //struct tipinde gecici pointeri olustur.
  struct node *pozisyonDugumu;//struct tipinde pozisyonDugumu olustur.

  int elemanSayisi;
  int i;
  int hangiPozisyon;
  int veri;
  int eleman;

  printf("Kac eleman eklemek istiyorsunuz = ");//Listenin eleman sayısı bilgisi
  scanf("%d",&elemanSayisi);

  for(i=0;i<elemanSayisi;i++){//Eleman sayısı kadar düğüm oluştur ve data değerlerini al
    printf("%d.ci elemani giriniz : ",i+1);
    scanf("%d",&veri);

    yeniDugum = (struct node *)malloc(sizeof(struct node));//yeni düğüm oluştur
    yeniDugum->data = veri;//yeni düğümün data değeri girilen değerdir.
    yeniDugum->next=NULL;//yeni düğümün sonraki değeri NULL 

    if (ilkDugum==NULL){//Eğer ilk düğüm boş ise;
      ilkDugum = yeniDugum;
      sonDugum = ilkDugum;
      printf("Eklediginiz dugum birinci listenin ilk dugumudur\n");
      }
    else{//Eğer ilk düğüm dolu ise
      sonDugum->next=yeniDugum;
      sonDugum = sonDugum->next;
      printf("Eklenilen yeni dugum birinci listenin sonuna eklenmistir\n");
      }
  }

  gecici = (struct node*)malloc(sizeof(struct node));//gecici düğümü oluştur
  gecici = ilkDugum;

  
  for(i=0;i<elemanSayisi;i++){//listeyi ekrana yazdır
    printf("%d\n",gecici->data);
    gecici=gecici->next;
  }

  gecici=ilkDugum;//gecici düğümü ilk düğümü gösterir

  printf("Hangi pozisyona eleman eklemek istiyorsunuz ?");//Pozisyon Bilgisi Al
  scanf("%d",&hangiPozisyon);

  printf("Eklemek istediginiz elemanı giriniz = ");//Eleman al.
  scanf("%d",&eleman);


  for(i=0;i<hangiPozisyon-2;i++){//girilen pozisyona gösterici ile git
    gecici=gecici->next;
  }

  pozisyonDugumu = (struct node *)malloc(sizeof(struct node));//yeni eklenecek düğümü oluştur.
  pozisyonDugumu->data=eleman;//pozisyonDugumu'nun datası yeni eklenen elemana eşittir.
  pozisyonDugumu->next=gecici->next;
  gecici->next=pozisyonDugumu;

  gecici=ilkDugum;

  printf("\nListenin Son Hali = ");
  for(i=0;i<elemanSayisi+1;i++){//Listenin yeni halini ekrana yazdır.
    printf("%d -> ",gecici->data);
    gecici=gecici->next;
  }
  printf("NULL\n");
}
void maxElemanBul(){
  struct node *ilkDugum=NULL; 
  struct node *sonDugum=NULL; 
  struct node *yeniDugum;     
  struct node *gecici;        

  int elemanSayisi;
  int i,x;
  
  int veri;
  

  printf("Kac eleman eklemek istiyorsunuz = ");//Listenin eleman sayısı bilgisi
  scanf("%d",&elemanSayisi);

  for(i=0;i<elemanSayisi;i++){//Eleman sayısı düğüm oluştur ve data değerlerini al
    printf("%d.ci elemani giriniz : ",i+1);
    scanf("%d",&veri);

    yeniDugum = (struct node *)malloc(sizeof(struct node));//yeni düğüm oluştur
    yeniDugum->data = veri;//yeni düğümün data değeri girilen değerdir.
    yeniDugum->next=NULL;//yeni düğümün sonraki değeri NULL 

    if (ilkDugum==NULL){//Eğer ilk düğüm boş ise;
      ilkDugum = yeniDugum;
      sonDugum = ilkDugum;
      printf("Eklediginiz dugum birinci listenin ilk dugumudur\n");
      }
    else{//Eğer ilk düğüm dolu ise
      sonDugum->next=yeniDugum;
      sonDugum = sonDugum->next;
      printf("Eklenilen yeni dugum birinci listenin sonuna eklenmiştir\n");
      }
  }

  gecici = (struct node*)malloc(sizeof(struct node));//gecici düğümü oluştur
  gecici = ilkDugum;

  x=gecici->data;//integer x değişkeni ilk düğümün datasına eşittir

  for (i = 0; i < elemanSayisi-1; i++)
  {
    if(gecici->next->data>x){//ilk düğümün nexti'nin datası x'ten büyük ise bu değeri x'e eşitle.
      x=gecici->next->data;
    }
    gecici=gecici->next;//geçici düğümüne bir sonraki düğümü göstert.
  }
  printf("\nListenin en buyuk degeri = %d\n",x);//listenin en büyük değerini yazdır.
}
void listeBirlestir(){
  struct node *ilkDugum=NULL; 
  struct node *sonDugum=NULL; 
  struct node *yeniDugum;     
  struct node *gecici;        
  

  struct node *ilkDugum2=NULL; 
  struct node *sonDugum2=NULL; 
  struct node *yeniDugum2;     
  struct node *gecici2;        

  struct node *gecici3;

  int elemanSayisi,elemanSayisi2;
  int i;
  int veri;
  int eleman;
  int hangiListe;

  printf("Hangi listeye eleman eklemek istiyorsunuz?(1-2)");
  scanf("%d",&hangiListe);
  if(hangiListe==1){
    printf("Kac eleman eklemek istiyorsunuz = ");//Listenin eleman sayısı bilgisi
    scanf("%d",&elemanSayisi);

    for(i=0;i<elemanSayisi;i++){//Eleman sayısı düğüm oluştur ve data değerlerini al
      printf("%d.ci elemani giriniz : ",i+1);
      scanf("%d",&veri);

    yeniDugum = (struct node *)malloc(sizeof(struct node));//yeni düğüm oluştur
    yeniDugum->data = veri;//yeni düğümün data değeri girilen değerdir.
    yeniDugum->next=NULL;//yeni düğümün sonraki değeri NULL 

    if (ilkDugum==NULL){//Eğer ilk düğüm boş ise;
      ilkDugum = yeniDugum;
      sonDugum = ilkDugum;
      printf("Eklediginiz dugum birinci listenin ilk dugumudur\n");
      }
    else{//Eğer ilk düğüm dolu ise
      sonDugum->next=yeniDugum;
      sonDugum = sonDugum->next;
      printf("Eklenilen yeni dugum birinci listenin sonuna eklenmistir\n");
      }
    }

    gecici = (struct node*)malloc(sizeof(struct node));//gecici düğümü oluştur
    gecici = ilkDugum;
  }
  hangiListe=2;
  if(hangiListe==2){
    printf("İkinci Listeye Eleman Ekleniyor...\n");
    printf("İkinci listeye Kac Eleman Eklemek İstiyorsunuz = ");//Listenin eleman sayısı bilgisi
    scanf("%d",&elemanSayisi2);

    for(i=0;i<elemanSayisi2;i++){//Eleman sayısı düğüm oluştur ve data değerlerini al
      printf("%d.ci elemani giriniz : ",i+1);
      scanf("%d",&veri);

    yeniDugum2 = (struct node *)malloc(sizeof(struct node));//yeni düğüm oluştur
    yeniDugum2->data = veri;//yeni düğümün data değeri girilen değerdir.
    yeniDugum2->next=NULL;//yeni düğümün sonraki değeri NULL 

    if (ilkDugum2==NULL){//Eğer ilk düğüm boş ise;
      ilkDugum2 = yeniDugum2;
      sonDugum2 = ilkDugum2;
      printf("Eklediginiz dugum birinci listenin ilk dugumudur\n");
      }
    else{//Eğer ilk düğüm dolu ise
      sonDugum2->next=yeniDugum2;
      sonDugum2 = sonDugum2->next;
      printf("Eklenilen yeni dugum birinci listenin sonuna eklenmistir\n");
      }
    }

    gecici2 = (struct node*)malloc(sizeof(struct node));//gecici düğümü oluştur
    gecici2 = ilkDugum2;

    printf("İkinci liste = ");
    for(i=0;i<elemanSayisi2;i++){//listeyi ekrana yazdır
      printf("%d  ",gecici2->data);
      gecici2=gecici2->next;
    }
    printf("\n");
  }
  sonDugum->next=ilkDugum2;

  gecici3 = (struct node*)malloc(sizeof(struct node));//gecici düğümü oluştur
  gecici3 = ilkDugum;

  printf("Birlesmis liste = ");
  for(i=0;i<elemanSayisi+elemanSayisi2;i++){//Birleşmiş listeyi ekrana yazdır
      printf("%d  ",gecici3->data);
      gecici3=gecici3->next;
    }
}
int main(int argc, char const *argv[]){
  int secim;
    do{
      printf("\n\n");
      printf("---------------SECIM EKRANI---------------\n");
      printf("i.ci Pozisyona eleman eklemek icin (1) \n");
      printf("Listedeki Maximum elemani bulmak icin (2) \n");
      printf("Girilen iki listeyi birlestirmek icin (3) \n");
      printf("Programdan Cikis İcin (0)\n\n");
      printf("Secim = ");
     
      scanf("%d",&secim);
      if(secim==1){
      ekle();
      }
      else if(secim==2){
        maxElemanBul();
      }
      else if(secim==3){
        listeBirlestir();
      }
      else if(secim==0){
        printf("Cikis Yapiliyor...Yapildi!\n");
        break;
      }
    }while(secim!=0);
return 0;
}
