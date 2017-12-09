//
//  main.c
//  VeriYapilariOdev
//
//  Created by Oğuzkaan Gündüz on 11.10.2017.
//  Copyright © 2017 Oğuzkaan Gündüz. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int dizi[3][3][3];
    int vizeNotu,finalNotu,ogrSec,ogrDers;
    float ortalama;
    for(int i = 0;i<3;i++){
        for (int j=0; j<3; j++) {
            printf("%d.ci öğrencinin %d.ci dersinin Vize Notu = ",i+1,j+1);
            scanf("%d",&vizeNotu);
            printf("%d.ci öğrencinin %d.ci dersinin Final Notu = ",i+1,j+1);
            scanf("%d",&finalNotu);
            ortalama=(vizeNotu*0.4)+(finalNotu*0.6);
            dizi[i][j][0]=ortalama;
        }
    }
    printf("Hangi öğrenciyle ilgili işlem yapmak istiyorsunuz (1-2-3)");
    scanf("%d",&ogrSec);
    printf("%d.ci öğrencinin kaçıncı dersin ortalamasını istersiniz (1-2-3)",ogrSec);
    scanf("%d",&ogrDers);
    printf("%d.ci öğrencinin %d.ci Ders Ortalaması = %d\n",ogrSec,ogrDers,dizi[ogrSec-1][ogrDers-1][0]);
    
    return 0;
}
