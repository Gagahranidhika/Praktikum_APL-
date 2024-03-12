#include <iostream>
using namespace std;

int main(){
    string user = "Andhika Gagahrani Ektya Antara";
    string nim = "2309106034";
    string userlog;
    string nimlog;
    int i = 0;
    int indeks = 0;
    string bookmark[20];
    int indeks2 = 0;
    string history[1][100];
    while (true){
        cout << "\n\tSILAHKAN LOGIN\t\n";
        cout << "Masukkan Username: ";
        getline(cin,userlog);
        cout << "Masukkan NIM: ";cin>>nimlog;
        cin.ignore();
        if (userlog == user && nimlog == nim){
            cout<<"\n\tSelamat Datang Di Program Bookmark!!!\n";
            while(true){
                string pilih;
                cout<<"\nMENU UTAMA\n";
                cout<<"1. HISTORY\n";
                cout<<"2. BOOKMARK\n";
                cout<<"0. EXIT\n";
                cout<<"Masukkan Pilihan Anda: ";
                getline(cin, pilih);
                if (pilih=="1"){
                    string menuhs;
                    while(true){
                        cout<<"\nMenu History\n";
                        cout<<"1. Lihat History\n";
                        cout<<"2. Tambah History\n";
                        cout<<"0. Kembali ke Menu Utama\n";
                        cout<<"Silahkan Pilih Menu: ";
                        getline(cin, menuhs);
                        if(menuhs=="1"){
                            if (indeks2==0){
                                cout<<"\n\tAnda Belum Menambahkan History\n";
                            }else{
                                cout<<"History Anda: ";
                                cout<<"Manhwa\t"<<"Chapter\n";
                                for (int i = indeks2 - 1 ;i>=0 ;i--){
                                    cout<<"\t\t"<<history[0][i]<<"\t"<<history[1][i]<<endl;
                                }
                            }
                            char konfir;
                            cout<<"Masukkan Apa Saja Untuk Kembali: ";cin>>konfir;
                            cin.ignore();
                        }else if(menuhs=="2"){
                            cout<<"Masukkan Nama Manhwa: ";
                            getline(cin, history[0][indeks2]);
                            cout<<"Masukkan Chapter Terakhir Dibaca: ";cin>>history[1][indeks2];
                            char konfir;
                            cout<<"Masukkan Apa Saja Untuk Kembali: ";cin>>konfir;
                            cin.ignore();
                            indeks2++;
                        }else if(menuhs=="0"){
                            char konfir;
                            cout<<"Masukkan Apa Saja Untuk Kembali: ";cin>>konfir;
                            cin.ignore();
                            break;
                        }else{
                            cout<<"\n\tPilihan Tidak Valid!!!\n";
                        }
                    }
                }else if(pilih=="2"){
                    string menu;
                    while(true){
                        cout<<"\nMenu Bookmark\n";
                        cout<<"1. Tambah Bookmark\n";
                        cout<<"2. Ubah Bookmark\n";
                        cout<<"3. Hapus Bookmark\n";
                        cout<<"4. Lihat Bookmark\n";    
                        cout<<"0. Kembali Ke Menu Utama\n";                        
                        cout<<"Masukkan Pilihan: ";
                        getline(cin, menu);
                        if (menu=="1"){
                            if (indeks == 20){
                                cout<<"\nAnda Telah Mencapai Batas Maksimum Manhwa Yang Dapat Di Bookmark Harap Hapus Salah Satu Terlebih Dahulu\n";
                            }else{
                                string calon;
                                cout<<"Masukkan Judul Manhwa: ";
                                getline(cin, calon);
                                bool cek = false;
                                for(int i=0;i<indeks2;i++){
                                    if(calon==history[0][i]){
                                        cek = true;
                                        break;
                                    }
                                }
                                if (cek){
                                    string yakin;
                                    cout<<"\nAnda Telah Membaca Manhwa ini hingga chapter: "<<history[1][i];
                                    cout<<"\nApakah Anda Yakin untuk Mendaftarkan ke Bookmark? (Ya untuk menerima)";cin>>yakin;
                                    if (yakin=="ya" ||yakin == "Ya" || yakin == "YA"){
                                        bookmark[indeks] = calon;
                                        cout<<"\n\tManhwa: "<<bookmark[indeks]<<" berhasil ditambahkan ke daftar bookmark\n";
                                        indeks++;
                                    }else{
                                        cout<<"\n\tAnda Telah Menolak\n";
                                    }
                                }else{
                                    string yakin;
                                    cout<<"Anda Belum Pernah Membaca Manhwa"<<calon;
                                    cout<<"\nApakah Anda Yakin Untuk Mendaftarkan Dalam Bookmark? (Ya untuk menerima)";cin>>yakin;
                                    if (yakin=="ya" ||yakin == "Ya" || yakin == "YA"){
                                        bookmark[indeks] = calon;
                                        cout<<"\n\tManhwa: "<<bookmark[indeks]<<" berhasil ditambahkan ke daftar bookmark\n";
                                        indeks++;
                                    }else{
                                        cout<<"\n\tAnda Telah Menolak\n";
                                    }
                                }
                            }
                            char konfir;
                            cout<<"Masukkan apa saja untuk kembali: ";cin>>konfir;
                            cin.ignore();
                        }else if(menu=="2"){
                            if (indeks==0){
                                cout<<"\n\tBookmark Anda Kosong Saat Ini\n"; 
                            }else{                     
                                int indeks3;
                                cout<<"Masukkan Nomor Bookmark Yang ingin Diubah: ";cin>>indeks3;
                                cin.ignore();
                                for (int i = 0 ; i < indeks; i++){
                                    if(bookmark[i]==bookmark[indeks3-1]){
                                        cout<<"Masukkan Judul Manhwa: ";
                                        getline(cin,bookmark[i]); 
                                    }
                                }
                            }
                            char konfir;
                            cout<<"Masukkan apa saja untuk kembali: ";cin>>konfir;        
                            cin.ignore();                    
                        }else if(menu=="3"){
                            if (indeks==0){
                                cout<<"\n\tBookmark Anda Kosong Saat Ini\n";
                            }else{                      
                                int indeks3;
                                cout<<"Masukkan Nomor Yang Ingin Dihapus: ";cin>>indeks3;
                                for (int i = 0 ; i < indeks; i++){
                                    if(bookmark[i]==bookmark[indeks3-1]){
                                        cout<<"\tManhwa "<<bookmark[i]<<" Telah Dihapus Dari Bookmark\n";
                                        for(int j = i; j<indeks;j++){
                                            bookmark[j]=bookmark[j+1];
                                        }
                                        indeks--;                                    
                                        }
                                    break;
                                }
                            char konfir;
                            cout<<"Masukkan apa saja untuk kembali: ";cin>>konfir;
                            cin.ignore();
                            }
                        }else if(menu=="4"){
                            if (indeks==0){
                                cout<<"Bookmark Anda Kosong Saat ini\n";
                            }else{
                                cout<<"Manhwa Yang Anda Bookmark: \n";
                                for (int i = 0 ; i<indeks;i++){
                                    cout<<i+1<<"\t"<<bookmark[i]<<endl;
                                }
                            }
                            char konfir;
                            cout<<"Masukkan apa saja untuk kembali: ";cin>>konfir;
                            cin.ignore();
                        }else if(menu=="0"){
                            char konfir;
                            cout<<"Masukkan apa saja untuk kembali: ";cin>>konfir;
                            cin.ignore();
                            break;
                        }else{
                            cout<<"\n\tPilihan Tidak Valid!!!\n";
                        }
                    }

                }else if(pilih == "0"){
                    cout<<"\n\tAnda Telah Memilih keluar\n";
                    return 0;
                }else{
                    cout<<"\n\tPilihan Tidak Valid!!!\n";

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