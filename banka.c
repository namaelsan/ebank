#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//#include <windows.h>
#include <unistd.h>
#define true 1
#define false 0

struct kullanici{
        int bakiye,limit;
        char tc[12];
    };

int giris(struct kullanici *kullanici){
    char tc[12];
    int i,flag;
    while (true){
        flag=0;
        system("clear");//SONDA BU KISMI WİNDOWS İÇİNDE DÜZELT
        printf("\t\tEBANK\n\n");
        printf("Hesabiniza giris icin TCnizi giriniz:\n");
        scanf("%s",tc);
        if (strlen(tc)!=11){
            printf("TCniz 11 sayidan olusmalidir.\n");
            sleep(1);
            flag=1;
        }
        for (i=0;i<11;i++){
            if (47>=tc[i] || tc[i]>=58){
                printf("TCniz rakamlardan olusmalidir.\n");
                sleep(1);
                flag=1;
                break;
            }
        }
        
        if (flag==0){
            kullanici->bakiye=(rand()%10000);
            kullanici->limit=(rand()%10000);
            return 0;
        }
    }
}

int parayatirma(struct kullanici *kullanici){
    system("clear");//SONDA BU KISMI WİNDOWS İÇİNDE DÜZELT
    int yatirilanpara,islem,cekilenpara;

    
    while (true){
        system("clear");//SONDA BU KISMI WİNDOWS İÇİNDE DÜZELT
        printf("\t\tEBANK\n");
        printf("\tBakiye:%dTL\n\tKredi Limiti:%dTL\n\n",kullanici->bakiye,kullanici->limit);
        printf("Para yatirmak icin:1\nPara Cekmek icin:2\nCikis Yapmak:3\nİslem:\n");
        scanf("%d",&islem);
        if(islem==1){
            printf("Yatirmak istediginiz TL miktarini girin:\n");
            scanf("%d",&yatirilanpara);
            printf("Kullanmak istediginiz karti secin.");
            printf("Banka Karti:1\nKredi Karti:2");
            scanf("%d",&islem);
            if (islem==1)
            kullanici->bakiye+=yatirilanpara;
            else if (islem==2)
            kullanici->limit+=yatirilanpara;
            else {
                printf("Gecerli bir islem numarasi girmediniz.");
                sleep(1);
                continue;
            }
            break;
        }
        else if(islem==2){
            printf("Hesabinizdan cekmek istediginiz miktari girin:\n");
            scanf("%d",&cekilenpara);
            printf("Kullanmak istediginiz karti secin.\n");
            printf("Banka Karti:1\nKredi Karti:2\nIslem:");
            scanf("%d",&islem);
            if (islem==1){
                if (cekilenpara> kullanici->bakiye){
                    printf("Bakiyenizden fazla miktarda para cekemezsiniz. Gecerli bir miktar giriniz.\n");
                    sleep(1);
                    continue;
            }
                kullanici->bakiye-=cekilenpara;
            }
            else if (islem==2){
                if (cekilenpara> kullanici->limit){
                    printf("Limitinizden fazla miktarda para cekemezsiniz. Gecerli bir miktar giriniz.\n");
                    sleep(1);
                    continue;
                }
                kullanici->limit-=cekilenpara;
            }
            else {
                printf("Gecerli bir islem numarasi girmediniz.");
                sleep(1);
                continue;
            }

            break;
        }
        else if(islem==3){
            return 0;
        }
        else{
            printf("Yanlis bir islem girdiniz.");
            sleep(1);
        }
    }
}


int efthavale(struct kullanici *kullanici){
    system("clear");//SONDA BU KISMI WİNDOWS İÇİNDE DÜZELT
    int para,islem;
    char iban[27],adsoyad[31];

    
    while (true){
        system("clear");//SONDA BU KISMI WİNDOWS İÇİNDE DÜZELT
        printf("\t\tEBANK\n");
        printf("\tBakiye:%dTL\n\tKredi Limiti:%dTL\n\n",kullanici->bakiye,kullanici->limit);
        printf("Baska Bir Bankaya Para Gondermek (EFT):1\nEBANK Musterilerine Para Gondermek (Havale):2\nCikis Yapmak:3\nİslem:");
        scanf("%d",&islem);
        if(islem==1 || islem==2){
            printf("Gondermek istediginiz miktari girin:");
            scanf("%d",&para);
            printf("Gondereceginiz kisinin IBAN adresini girin:");
            scanf("%s",iban);
            if (strlen(iban)!=26){
                printf("Gecerli bir iban giriniz.");
                continue;
            }
            printf("Gondereceginiz kisinin ad soyadini girin:");
            scanf("%s",adsoyad);
            printf("Kullanmak istediginiz karti secin.\n");
            printf("Banka Karti:1\nKredi Karti:2\nIslem:");
            scanf(" %d",&islem);
            if (islem==1){
                if (para> kullanici->bakiye){
                    printf("Bakiyenizden fazla miktarda para gonderemezsiniz. Gecerli bir miktar giriniz.\n");
                    sleep(1);
                    continue;
            }
                kullanici->bakiye-=para;
                return 0;
            }
            else if (islem==2){
                if (para> kullanici->limit){
                    printf("Limitinizden fazla miktarda para gonderemezsiniz. Gecerli bir miktar giriniz.\n");
                    sleep(1);
                    continue;
                }
                kullanici->limit-=para;
                return 0;
            }
            else {
                printf("Gecerli bir islem numarasi girmediniz.");
                sleep(1);
                continue;
            }

            break;
        }
        else if(islem==3){
            return 0;
        }
        else{
            printf("Yanlis bir islem girdiniz.");
            sleep(1);
        }
    }
}

int borcodeme(struct kullanici *kullanici){
    int islem,borc=10000-kullanici->limit;
    system("clear");
    printf("\t\tEBANK\n");
    printf("\tBakiye:%dTL\n\tKredi Limiti:%dTL\n\n",kullanici->bakiye,kullanici->limit);
    printf("%dTL borcunuz bulunmakta.\nOdemek icin:1\nCikis yapmak icin:2\nIslem:",borc);
    scanf("%d",&islem);
    if (islem==1){
        if (kullanici->bakiye <borc){
            kullanici->limit+=kullanici->bakiye;
            kullanici->bakiye=0;
        }
        else {
            kullanici->bakiye-=borc;
            kullanici->limit=10000;
        }
    }

    return 0;
}

int main(){

    int i,bakiye,islem;
    struct kullanici kullanici;
    srand(time(0));
    giris(&kullanici);

    while (true){
        system("clear");
        printf("\t\tEBANK\n");
        printf("\tBakiye:%dTL\n\tKredi Limiti:%dTL\n\n",kullanici.bakiye,kullanici.limit);
        printf("Para Yatirma/Cekme:1\n");
        printf("EFT/Havale Islemleri:2\n");
        printf("Borc Odemek:3\n");
        printf("Cikis Yapmak:4\n");
        printf("İslem:");
        scanf("%d",&islem);

        switch(islem){
            case 1: parayatirma(&kullanici);
                break;
            case 2: efthavale(&kullanici);
                break;
            case 3: borcodeme(&kullanici);
                break;
            case 4: return 0;
            default: printf("Gecerli bir sayi giriniz.\n");
            sleep(1);
        }
    }
    return 0;
}

