#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <math.h>
#include <conio.h>

int main() {
    int cluster, maks_itr, n, m, p, i;
    float w[50][50], lrate, dt[50][50], dtmin[10], dtmax[10],data[50][50], l_rate[100], fpem, sigma[50], nilai_terkecil, cls[50];

    gotoxy(25,2); cout<<"TUGAS AKHIR JARINGAN SYARAF TIRUAN "<<endl<<endl;
    gotoxy(10,3);cout<<" Implementasi SOM untuk Pengelompokkan Kabupaten/Kota di Jawa Tengah"<<endl;
    gotoxy(25,4);cout<<" Berdasarkan Indikator pendidikan "<<endl<<endl<<endl;
    gotoxy(7,5);cout<<"Kelompok 6 : "<<endl;
    gotoxy(10,6);cout<<" Rima Chusnul M.    (081911233039)"<<endl;
    gotoxy(10,7);cout<<" Soufi Ramadhani I. (081911233055) "<<endl<<endl;
    gotoxy(10,8);cout<<" -------------------------------------------------------------------- "<<endl<<endl;

    ifstream data_wilayah;
    data_wilayah.open("DATA SOM.txt");

    cluster=2;
    cout<<" Inputkan nilai dari parameter yang akan digunakan : "<<endl;
    cout<<" Maksimal iterasi: ";
    cin>>maks_itr;
    cout<<" Learning rate: ";
    cin>>lrate;
    cout<<endl<<endl;

   /* n = jml data =35
      m = inputan = 6
      p= jml kluster = 2
   */
   cout<<" Data yang akan digunakan berdasarkan ... "<<endl;
   for(n=1;n<=35;n++) {
        for(m=1; m<=6; m++) {
            data_wilayah>>data[n][m];
            cout<<"| "<<setw(4)<<data[n][m]<<"|";
        }
        cout<<endl;
   }
    cout<<"----------------------------------------------------------"<<endl;

    	dtmax[m]=0;

    //mencari nilai min max tiap variabel inputan
    for(m=1;m<=6;m++) {
    	for (n=1;n<=35;n++) {
      	if (n==1) {
         		dtmin[m]=data[n][m];
         }else if (data[n][m]> dtmax[m]){
         		dtmax[m]=data[n][m];
         } else if (data[n][m]<dtmin[m]){
         		dtmin[m]= data[n][m];
         }else {}
      }
      cout<<" data min dari kolom ke- "<<m<<" adalah "<<dtmin[m]<<endl;
      cout<<" data max dari kolom ke- "<<m<<" adalah "<<dtmax[m]<<endl<<endl;

    }

    cout<<" Data yang telah dinormalisasi"<<endl;
    for(n=1; n<=35; n++) {
         for(m=1; m<=6; m++){

            /*Normalisasi Data*/

            dt[n][m]= ((0.8*(data[n][m]-dtmin[m]))/(dtmax[m]-dtmin[m]))+0.1;
            cout<<"| "<<setw(4)<<dt[n][m]<<"|";
        }
        cout<<endl;
    }
    cout<<"----------------------------------------------------------"<<endl;

    cout<<"BOBOT AWAL (W) :"<<endl;

    for(m=1; m<=6; m++) {
        for(p=1; p<=cluster; p++) {

              /*Random Nilai w*/

            w[m][p] = ((double) rand() / RAND_MAX);
            cout<<setw(4)<<w[m][p]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<" akan dihitung nilai euclid"<<endl;

    for(i=1; i<=maks_itr; i++) {
        cout<<"iterasi ke- "<<i<<endl;

        /*Perhitungan Learning Rate*/
        //fpem=0.5*lrate;
        if(i==1) {
            l_rate[i]=lrate;
        } else {
            l_rate[i]=l_rate[(i-1)];
            l_rate[i]=l_rate[i]*(0.5);
        }
        cout<<"LEARNING RATE : "<<l_rate[i]<<endl<<endl;

        for(n=1; n<=35; n++) {
            m=1;
            cout<<" Untuk data ke-"<<n<<" dengan nilai Xi sbb ["<<dt[n][m]<<" "<<dt[n][(m+1)]<<"  "<<dt[n][(m+2)]<<" "<<dt[n][(m+3)]<<"  "<<dt[n][(m+4)]<<"  "<<dt[n][(m+5)]<<" ]"<<endl;
            for(p=1; p<=cluster; p++) {

            	 /*Rumus Euclidean Distance*/
                sigma[p]= sqrt(pow((w[m][p]-dt[n][m]), 2) + pow((w[m+1][p]-dt[n][m+1]), 2)+ pow((w[m+2][p]-dt[n][m+2]), 2)+ pow((w[m+3][p]-dt[n][m+3]), 2)+ pow((w[m+4][p]-dt[n][m+4]), 2)+ pow((w[m+5][p]-dt[n][m+5]), 2));
                cout<<" nilai dari d"<<p<<" adalah "<<sigma[p]<<endl;
            }
            int cls=0;
            p=1;
            if(sigma[p]<sigma[(p+1)]) {
                		nilai_terkecil = sigma[p];
                     cls = 1;
                     cout<<" nilai paling kecil "<<nilai_terkecil<<" ada pada d"<<cls<<" sehingga w"<<cls<<" akan diperbarui"<<endl;
            }
            else {
                		nilai_terkecil = sigma[(p+1)];
                     cls = 2;
                     cout<<" nilai paling kecil "<<nilai_terkecil<<" ada pada d"<<cls<<" sehingga w"<<cls<<" akan diperbarui"<<endl;
            }

            cout<<endl<<"BOBOT BARU : "<<endl;
            for(m=1; m<=6; m++) {
            			p=1;
                     if(sigma[p]<sigma[(p+1)]) {
                      		w[m][p]=w[m][p];
                           /*Rumus Bobot Baru untuk d1 berubah*/
                           w[m][p]=w[m][p]+(l_rate[i]*(dt[n][m]-w[m][p]));
                           cout<<setw(4)<<w[m][p]<<" "<<w[m][p+1];
                     }
                     else {
                             /*Rumus Bobot Baru untuk d2 berubah*/
                           w[m][(p+1)]= w[m][(p+1)]+(l_rate[i]*(dt[n][m]-w[m][(p+1)]));
                           cout<<setw(4)<<w[m][p]<<" "<<w[m][p+1];
                     }
                     p++;
                     cout<<endl;
            }
            cout<<endl;
        }
    }
    cout<<" Nilai w optimal adalah "<<endl;
    for(m=1; m<=6; m++) {
         p=1;
         cout<<setw(4)<<w[m][p]<<" "<<w[m][p+1]<<endl;
    }

    cout<<endl;
    cout<<" Akan dilakukan proses pengelompokkan data "<<endl;
    //proses pengelompokkan
    for(n=1; n<=35; n++) {
            m=1;
            cout<<" Untuk data ke-"<<n<<"\t";
            for(p=1; p<=cluster; p++) {

            	 /*Rumus Euclidean Distance*/
                sigma[p]= sqrt(pow((w[m][p]-dt[n][m]), 2) + pow((w[m+1][p]-dt[n][m+1]), 2)+ pow((w[m+2][p]-dt[n][m+2]), 2)+ pow((w[m+3][p]-dt[n][m+3]), 2)+ pow((w[m+4][p]-dt[n][m+4]), 2)+ pow((w[m+5][p]-dt[n][m+5]), 2));
                cout<<" d"<<p<<" = "<<sigma[p]<<"\t";
            }
            cls[0]=0;
            p=1;
            if(sigma[p]<sigma[(p+1)]) {
                		nilai_terkecil = sigma[p];
                     cls[n]= 1;
                     cout<<" Cluster "<<cls[n]<<endl;
            }
            else {
                		nilai_terkecil = sigma[(p+1)];
                     cls[n]= 2;
                     cout<<" Cluster "<<cls[n]<<endl;
            }
            cout<<endl;
    }

    cout<<endl;
    cout<<" Hasilnya adalah sebagai berikut :"<<endl;
    //dilist bersadarkan klaster 1 dan 2
    cout<<" klaster 1 "<<endl;
    for(n=1; n<=35; n++) {
      if(cls[n]==1)
      	cout<<" data ke- "<<n<<endl;
    }
    cout<<endl<<endl;
    cout<<" klaster 2"<<endl;
    for(n=1; n<=35; n++) {
      if(cls[n]==2)
      	cout<<" data ke-"<<n<<endl;
    }



    data_wilayah.close();

    getch();
}
