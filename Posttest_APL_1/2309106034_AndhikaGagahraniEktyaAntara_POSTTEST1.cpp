#include <iostream>
using namespace std;

int main(){

    string nama = "Andhika Gagahrani Ektya Antara";
    string nim = "2309106034";
    string logNIM;
    string user;
    int i = 0;
    string pilihan;
    double nominal;
    while (true){
        cout << "\n\tSILAHKAN LOGIN\t\n";
        cout << "Masukkan Username: ";
        getline(cin,user);
        cout << "Masukkan NIM: ";cin>>logNIM;
        cin.ignore();
        if (user == nama && logNIM == nim){
            cout<<"\n\tSelamat Datang Di Program Konversi Mata Uang!!!\n";
            while(true){
                cout<<"\n\tPilih Jenis Mata Uang Sebelum Di Konversi: \n";
                cout<<"1. Rupiah\n";
                cout<<"2. Dollar\n";
                cout<<"3. Euro\n";
                cout<<"4. Yen\n";
                cout<<"0. Keluar Dari Program\n";
                cout<<"Silahkan Pilih: ";cin>>pilihan;
                if (pilihan == "1"){
                    cout<<"Masukkan Nominal Yang ingin Di Konversi: ";cin>>nominal;
                    if (nominal==isdigit(nominal)) {
                        cout << "\nNominal harus berupa angka.\n";
                        cin.clear(); 
                        while (cin.get() != '\n');
                    }else{
                        cout<< nominal <<"Rupiah = "<< nominal*0.000064 <<" USDollar\n";
                        cout<< nominal <<"Rupiah = "<< nominal*0.000059 <<" Euro\n";
                        cout<< nominal <<"Rupiah = "<< nominal*0.0096 <<" Yen\n";
                    }
                }else if(pilihan =="2"){
                    cout << "Masukkan Nominal Yang ingin Di Konversi: ";cin>>nominal;
                    if (nominal==isdigit(nominal)) {
                        cout << "\nNominal harus berupa angka.\n";
                        cin.clear(); 
                        while (cin.get() != '\n');
                    }else{
                        cout<< nominal <<"USDollar = "<< nominal*15720.35 <<" Rupiah\n";
                        cout<< nominal <<"USDollar = "<< nominal*0.92 <<" Euro\n";
                        cout<< nominal <<"USDollar = "<< nominal*150.41 <<" Yen\n";
                    }

                }else if(pilihan =="3"){
                    cout<<"Masukkan Nominal Yang ingin Di Konversi: ";cin>>nominal;
                    if (nominal==isdigit(nominal)) {
                        cout << "\nNominal harus berupa angka.\n";
                        cin.clear(); 
                        while (cin.get() != '\n');
                    }else{
                        cout<< nominal <<"Euro = "<< nominal*17016.58 <<" Rupiah\n";
                        cout<< nominal <<"Euro = "<< nominal*1.08 <<" USDollar\n";
                        cout<< nominal <<"Euro = "<< nominal*162.82 <<" Yen\n";
                    }

                }else if (pilihan =="4"){
                    cout<<"Masukkan Nominal Yang ingin Di Konversi: ";cin>>nominal;
                    if (nominal==isdigit(nominal)) {
                        cout << "\nNominal harus berupa angka.\n";
                        cin.clear(); 
                        while (cin.get() != '\n');
                    }else{
                        cout<< nominal <<"Yen = "<< nominal*104.50 <<" Rupiah\n";
                        cout<< nominal <<"Yen = "<< nominal*0.0066 <<" USDollar\n";
                        cout<< nominal <<"Yen = "<< nominal*0.0061 <<" Yen\n";
                    }
                }else if (pilihan =="0"){
                    cout<<"\n\tAnda Telah Memilih Keluar Dari Program";
                    return 0 ;
                }else{
                    cout<<"\n\tPilihan Tidak Valid\n";
                }

            }
            
        } else if(i==2){

            cout<<"\n\tAnda Telah Mencoba Sebanyak 3 Kali ";
            break;
        } else{
            cout<<"\tUsername atau NIM salah Harap Coba Lagi\n\n";
            i=i+1;
            
        }
    }
    return 0;
}