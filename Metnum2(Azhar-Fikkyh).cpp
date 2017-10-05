#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#define Nmax 8

int main() {
	int x[Nmax+1];
   	int x2[Nmax+1];
   	int y[Nmax+1];
   	int y2[Nmax+1];
   	int xy[Nmax+1];
   	int n, i, data;
   	int sigmax=0, sigmay=0, sigmax2=0, sigmaxy=0;
   	float prediksi[Nmax+1];
   	float nyata[Nmax+1];
   	float m, c, eror, sigmapre=0, sigmanya=0;
   
   	Home:
   	system("cls");
   	printf("Menghitung Perkiraan Waktu Antar Makanan Bahari Cibeber \n");
   	printf("\n Masukan Jumlah Orderan : "); scanf("%d", &n);
   	if(n<2) {
   		printf("--data kurang dari 2--");
      	getch();
      	goto Home;
   	}
   	else if (n>Nmax) {
   		printf("Orderan Melampaui Batas!!(silahkan order minimal dibawah 8 pcs)");
   		getch();
   		goto Home;
   	}
   	else {
   		for(i=1; i<=n; i++) {
      		printf("Jarak Pegawai ke Pelanggan %d = ",i); scanf("%d", &data);
      		x[i]=data;
      		sigmax=sigmax+x[i];
      		x2[i]=x[i]*x[i];
      		sigmax2=sigmax2+x2[i];
   		}
   		printf("\n");
   	
		for(i=1; i<=n; i++) {
    		printf("Waktu yang dapat Ditempuh Pegawai ke Pelanggan %d = ", i); scanf("%d", &data);
    		y[i]=data;
    		sigmay=sigmay+y[i];
    		y2[i]=y[i]*y[i];
    		xy[i]=x[i]*y[i];
    		sigmaxy=sigmaxy+xy[i];
   		}
	
		m=((n*sigmaxy)-(sigmax * sigmay))/((n*sigmax2)-pow(sigmax,2));
   		c=((sigmay*sigmax2)-(sigmax*sigmaxy))/((n*sigmax2)-pow(sigmax,2));
   		for(i=1; i<=n; i++) {
      		prediksi[i]=(m*x[i])+c;
      		sigmapre=sigmapre+prediksi[i];
      		nyata[i]=y[i]-prediksi[i];
      		if(nyata[i]<0 ) {
      			nyata[i]=prediksi[i]-y[i];
      		}
      	sigmanya=sigmanya+nyata[i];
   		}
   	
		printf("\nJarak dari Pegawai ke pelanggan\n");
   		for(i=1; i<=n; i++) {
   			printf("%d satuan waktu|", x[i]);
   		}

   		printf("\n\nKira-kira waktu yang di Tempuh Pegawai ke Pelanggan\n");
   		for(i=1; i<=n; i++) {
   			printf("%d satuan waktu|", y[i]);
   		}
   		
		printf("\n\nPrediksi waktu\n");
   		for(i=1; i<=n; i++) {
   			printf("%.2f satuan waktu|", prediksi[i]);
   		}

   		printf("\n\nSelisih waktu perkiraan-prediksi\n");
   		for(i=1; i<=n; i++) {
   			printf("%.2f/menit|", nyata[i]);
   		}

   		eror=sigmanya/n;
   		printf("\n\nError: %.2f/menit", eror);
   		getch();
   	}
	return 0;
}
