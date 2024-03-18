#include <iostream>
#include <conio.h>
using namespace std;

string user = "Andhika";
string nim = "2309106034";
int indeks = 0;
string bookmark[2][21];
int indeks2 = 0;
string history[2][100];
char delay;
int i = 0;

bool login() {
    string userlog, nimlog;
    cout << "\n\tSILAHKAN LOGIN\t\n";
    cout << "Masukkan Username: ";
    getline(cin, userlog);
    cout << "Masukkan NIM: ";
    getline(cin, nimlog);

    if (i == 2) {
        return false;
    }

    if (userlog == user && nimlog == nim) {
        return true;
    }

    cout << "\n\tNama Atau NIM Salah! Silakan coba lagi.\n";
    i++;
    return login();
}

string tampilkanHistory() {
    string hasil = "";
    if (indeks2 == 0) {
        cout<< "\n\tAnda Belum Menambahkan History\n";
    } else {
        cout<< "History Anda: "<<endl;
        cout<< "Manhwa\t\t\t\t" << "Chapter\n";
        for (int i = indeks2 - 1; i >= 0; i--) {
            cout<< history[0][i] << "\t\t\t\t" << history[1][i] << "\n";
        }
    }
    cout<< "Masukkan Apa Saja Untuk Kembali: ";
}
string tambahhistory(){
    cout << "Masukkan Nama Manhwa: ";
    getline(cin, history[0][indeks2]);
    cout << "Masukkan Chapter Terakhir Dibaca: "; 
    getline(cin , history[1][indeks2]);
    for(int i=0;i<indeks;i++){
        if (history[0][indeks2]==bookmark[0][i]){
            bookmark[1][i]=history[1][indeks2];
        }
    }
    for(int i=0;i<indeks2;i++){
        if(history[0][indeks2]==history[0][i]){
            for (int j = i; j < indeks2; j++) {
                history[0][j] = history[0][j + 1];
                history[1][j] = history[1][j + 1];
            }
            indeks2--;
        }
        break;
    }
    indeks2++;
}
string menuHistory() {
    string menuhs;
    string hasil;
    while (true) {
        cout << "\n\nMenu History\n";
        cout << "1. Lihat History\n";
        cout << "2. Tambah History\n";
        cout << "0. Kembali ke Menu Utama\n";
        cout << "Silahkan Pilih Menu: ";
        getline(cin, menuhs);
        if (menuhs == "1") {
            tampilkanHistory();
            delay = getch();
        } else if (menuhs == "2") {
            tambahhistory();
            cout << "Masukkan Apa Saja Untuk Kembali: ";
            delay = getch();
        } else if (menuhs == "0") {
            cout << "Masukkan Apa Saja Untuk Kembali: ";
            delay = getch();
            break;
        } else {
            cout << "\n\tPilihan Tidak Valid!!!\n";
        }
    }
}

void lihatBookmark() {
    if (indeks == 0) {
        cout << "\n\tBookmark Anda Kosong Saat ini\n";
    } else {
        cout << "Manhwa Yang Anda Bookmark: \n";
        cout<<" \t"<<"Judul\t\tChapter\n";
        for (int i = 0; i < indeks; i++) {
            cout << i + 1 << "\t" << bookmark[0][i]<<"\t\t"<<bookmark[1][i] << endl;
        }
    }
}

void tambahBookmark() {
    string calon;
    cout << "Masukkan Judul Manhwa: ";
    getline(cin, calon);
    bool cek = false;
    for (int j = 0; j < indeks2; j++) {
        if (calon == history[0][j]) {
            cek = true;
            break;
        }
    }
    if (cek) {
        for (int j = 0; j < indeks2; j++) {
            if (calon == history[0][j]) {
                string yakin;
                cout << "\nAnda Telah Membaca Manhwa ini hingga chapter: " << history[1][j];
                cout << "\nApakah Anda Yakin untuk Mendaftarkan ke Bookmark? (Ya untuk menerima)";
                cin >> yakin;
                if (yakin == "ya" || yakin == "Ya" || yakin == "YA") {
                    bookmark[0][indeks] = calon;
                    bookmark[1][indeks] = history[1][j];
                    cout << "\n\tManhwa: " << bookmark[0][indeks] << " berhasil ditambahkan ke daftar bookmark\n";
                    indeks++;
                    } else {
                        cout << "\n\tAnda Telah Menolak\n";
            }
            break;
        }
    }
    } else {
        string yakin;
        cout << "Anda Belum Pernah Membaca Manhwa" << calon;
        cout << "\nApakah Anda Yakin Untuk Mendaftarkan Dalam Bookmark? (Ya untuk menerima)";
        cin >> yakin;
        if (yakin == "ya" || yakin == "Ya" || yakin == "YA") {
            bookmark[0][indeks] = calon;
            bookmark[1][indeks] = "New";
            cout << "\n\tManhwa: " << bookmark[0][indeks] << " berhasil ditambahkan ke daftar bookmark\n";
            indeks++;
        } else {
            cout << "\n\tAnda Telah Menolak\n";
        }
    }
    cin.ignore();
}

void ubahBookmark() {
    if (indeks == 0) {
        cout << "\n\tBookmark Anda Kosong Saat Ini\n";
    } else {
        lihatBookmark();
        int indeks3;
        cout << "Masukkan Nomor Bookmark Yang ingin Diubah: ";
        cin >> indeks3;
        cin.ignore();
        for (int i = 0; i < indeks; i++) {
            if (bookmark[0][i] == bookmark[0][indeks3 - 1]) {
                cout << "Masukkan Judul Manhwa: ";
                getline(cin, bookmark[0][i]);
                cout<<"\n\tManhwa Berhasil Diubah Menjadi "<<bookmark[0][i]<<"\n";
                for (int j = 0; j < indeks2; j++) {
                    if (bookmark[0][i] == history[0][j]) {
                        bookmark[1][i] = history[i][j];
                        break;
                    }else{
                        bookmark[1][i] = "New";
                    }
                }
            }
        }
    }
    cin.ignore();
}

void hapusBookmark() {
    if (indeks == 0) {
        cout << "\n\tBookmark Anda Kosong Saat Ini\n";
    } else {
        lihatBookmark();
        int indeks3;
        cout << "\nMasukkan Nomor Yang Ingin Dihapus: ";
        cin >> indeks3;
        for (int i = 0; i < indeks; i++) {
            if (bookmark[0][i] == bookmark[0][indeks3 - 1]) {
                cout << "\tManhwa " << bookmark[0][i] << " Telah Dihapus Dari Bookmark\n";
                for (int j = i; j < indeks; j++) {
                    bookmark[0][j] = bookmark[0][j + 1];
                    bookmark[1][j] = bookmark[1][j + 1];
                }
                indeks--;
            }
            break;
        }
    }
    cin.ignore();
}

void menuBookmark() {
    while(true){
        string menu;
        cout << "\n\nMenu Bookmark\n";
        cout << "1. Tambah Bookmark\n";
        cout << "2. Ubah Bookmark\n";
        cout << "3. Hapus Bookmark\n";
        cout << "4. Lihat Bookmark\n";
        cout << "0. Kembali Ke Menu Utama\n";
        cout << "Masukkan Pilihan: ";
        getline(cin, menu);
        if (menu == "1") {
            tambahBookmark();
            cout << "Masukkan apa saja untuk kembali: ";
            delay = getch();
        } else if (menu == "2") {
            ubahBookmark();
            cout << "Masukkan apa saja untuk kembali: ";
            delay = getch();
        } else if (menu == "3") {
            hapusBookmark();
            cout << "Masukkan apa saja untuk kembali: ";
            delay = getch();
        } else if (menu == "4") {
            lihatBookmark();
            cout << "Masukkan apa saja untuk kembali: ";
            delay = getch();
        } else if (menu == "0") {
            cout << "\tAnda Telah Memilih Kembali\n ";
            break;
        } else {
            cout << "\n\tPilihan Tidak Valid!!!\n";
            
        }
    }
}
void menuUtama() {
    while (true) {
        string pilih;
        cout << "\n\nMENU UTAMA\n";
        cout << "1. HISTORY\n";
        cout << "2. BOOKMARK\n";
        cout << "0. EXIT\n";
        cout << "Masukkan Pilihan Anda: ";
        getline(cin, pilih);
        if (pilih == "1") {
            menuHistory();
        } else if (pilih == "2") {
            menuBookmark();
            cout<<"Masukkan Apa Saja Untuk Kembali: ";
            delay = getch();
        } else if (pilih == "0") {
            cout << "\n\tAnda Telah Memilih keluar\n";
            exit(0);
        } else {
            cout << "\n\tPilihan Tidak Valid!!!\n";
        }
    }
}

int main() {
    while (true){
        if (login()) {
            cout << "\n\tSelamat Datang Di Program Bookmark!!!\n";
            menuUtama();
        } else{
            cout << "\n\tAnda Telah Mencoba Sebanyak 3 Kali ";
            return 0;
        } 
    }
    return 0;
}
