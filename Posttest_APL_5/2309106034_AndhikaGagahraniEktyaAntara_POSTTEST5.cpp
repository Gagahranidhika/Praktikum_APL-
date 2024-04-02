#include <iostream>
#include <conio.h>
using namespace std;

struct History {
    string manhwa;
    string chapter;
};

struct Bookmark {
    string judul;
    string chapter;
};

struct userdata {
    string user = "Andhika";
    string nim = "2309106034";
};

struct alldata {
    History history[100];
    Bookmark bookmark[20];
    userdata userlp;
};

alldata data;
int indeks = 0;
int indeks2 = 0;
char delay;
int i = 0;

bool login(userdata *user) {
    string userlog, nimlog;
    cout << "\n\tSILAHKAN LOGIN\t\n";
    cout << "Masukkan Username: ";
    getline(cin, userlog);
    cout << "Masukkan NIM: ";
    getline(cin, nimlog);

    if (i == 2) {
        return false;
    }

    if (userlog == user->user && nimlog == user->nim) {
        return true;
    }

    cout << "\n\tNama Atau NIM Salah! Silakan coba lagi.\n";
    i++;
    return login(user);
}

void tampilkanHistory(alldata *data, int *indeks2) {
    string hasil = "";
    if (*indeks2 == 0) {
        cout << "\n\tAnda Belum Menambahkan History\n";
    } else {
        cout << "History Anda: " << endl;
        cout << "Manhwa\t\t\t\t" << "Chapter\n";
        for (int i = *indeks2 - 1; i >= 0; i--) {
            cout << data->history[i].manhwa << "\t\t\t\t" << data->history[i].chapter << "\n";
        }
    }
    cout << "Masukkan Apa Saja Untuk Kembali: ";
}

void tambahhistory(alldata *data, int *indeks2) {
    string namaManhwa, chapterTerakhir;
    while (true) {
        cout << "Masukkan Nama Manhwa: ";
        getline(cin, namaManhwa);
        if (!namaManhwa.empty()) {
            break;
        }
        cout << "Nama Manhwa tidak boleh kosong. Silakan masukkan kembali." << endl;
    }
    while (true) {
        cout << "Masukkan Chapter Terakhir Dibaca: ";
        getline(cin, chapterTerakhir);
        if (!chapterTerakhir.empty()) {
            break;
        }
        cout << "Chapter tidak boleh kosong. Silakan masukkan kembali." << endl;
    }
    data->history[*indeks2].manhwa = namaManhwa;
    data->history[*indeks2].chapter = chapterTerakhir;
    for (int i = 0; i < *indeks2; i++) {
        if (data->history[*indeks2].manhwa == data->bookmark[i].judul) {
            data->bookmark[i].chapter = data->history[*indeks2].chapter;
        }
    }
    for (int i = 0; i < *indeks2; i++) {
        if (data->history[*indeks2].manhwa == data->history[i].manhwa) {
            for (int j = i; j < *indeks2; j++) {
                data->history[j].manhwa = data->history[j + 1].manhwa;
                data->history[j].chapter = data->history[j + 1].chapter;
            }
            (*indeks2)--;
        }
        break;
    }
    (*indeks2)++;
}


void lihatBookmark(alldata *data, int &indeks) {
    if (indeks == 0) {
        cout << "\n\tBookmark Anda Kosong Saat ini\n";
    } else {
        cout << "Manhwa Yang Anda Bookmark: \n";
        cout << " \t" << "Judul\t\tChapter\n";
        for (int i = 0; i < indeks; i++) {
            cout << i + 1 << "\t" << data->bookmark[i].judul << "\t\t" << data->bookmark[i].chapter << endl;
        }
    }
}

void tambahBookmark(alldata *data, int *indeks, int *indeks2) {
    string calon;
    while (true) {
        cout << "Masukkan Judul Manhwa: ";
        getline(cin, calon);
        if (!calon.empty()) {
            break;
        }
        cout << "Judul Manhwa tidak boleh kosong. Silakan masukkan kembali.\n";
    }
    bool cek = false;
    for (int j = 0; j < *indeks2; j++) {
        if (calon == data->history[j].manhwa) {
            cek = true;
            break;
        }
    }
    if (cek) {
        for (int j = 0; j < *indeks2; j++) {
            if (calon == data->history[j].manhwa) {
                string yakin;
                cout << "\nAnda Telah Membaca Manhwa ini hingga chapter: " << data->history[j].chapter;
                cout << "\nApakah Anda Yakin untuk Mendaftarkan ke Bookmark? (Ya untuk menerima)";
                cin >> yakin;
                if (yakin == "ya" || yakin == "Ya" || yakin == "YA") {
                    data->bookmark[*indeks].judul = calon;
                    data->bookmark[*indeks].chapter = data->history[j].chapter;
                    cout << "\n\tManhwa: " << data->bookmark[*indeks].judul << " berhasil ditambahkan ke daftar bookmark\n";
                    (*indeks)++;
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
            data->bookmark[*indeks].judul = calon;
            data->bookmark[*indeks].chapter = "New";
            cout << "\n\tManhwa: " << data->bookmark[*indeks].judul << " berhasil ditambahkan ke daftar bookmark\n";
            (*indeks)++;
        } else {
            cout << "\n\tAnda Telah Menolak\n";
        }
    }
    cin.ignore();
}

void ubahBookmark(alldata *data, int *indeks, int *indeks2) {
    if (*indeks == 0) {
        cout << "\n\tBookmark Anda Kosong Saat Ini\n";
    } else {
        lihatBookmark(data, *indeks); 
        int indeks3;
        try {
            while (true) {
                cout << "\nMasukkan Nomor Yang Ingin Diubah: ";
                if (!(cin >> indeks3)) {
                    cout << "Error: " << "Harap Masukkan Dalam Bentuk Angka" << endl;
                    cin.clear();
                    cin.ignore();
                    continue;
                }

                if (indeks3 < 1 || indeks3 > *indeks) {
                    cout << "Error: " << "Nomor Bookmark Tidak Valid" << endl;
                    cin.clear();
                    cin.ignore();
                    continue;
                }

                else {
                    for (int i = 0; i < *indeks; i++) {
                        if (data->bookmark[i].judul == data->bookmark[indeks3 - 1].judul) {
                            cout << "Masukkan Judul Manhwa Baru: ";
                            cin.ignore();
                            getline(cin, data->bookmark[i].judul);
                            cout << "\n\tManhwa Berhasil Diubah Menjadi " << data->bookmark[i].judul << "\n";
                            for (int j = 0; j < *indeks2; j++) {
                                if (data->bookmark[i].judul == data->history[j].manhwa) {
                                    data->bookmark[i].chapter = data->history[j].chapter;
                                    break;
                                } else {
                                    data->bookmark[i].chapter = "New";
                                }
                            }
                        }
                    }
                    throw indeks3;
                }
            }
        } catch (int a) {
        }

    }
}

void hapusBookmark(alldata *data, int &indeks) {
    if (indeks == 0) {
        cout << "\n\tBookmark Anda Kosong Saat Ini\n";
    } else {
        lihatBookmark(data, indeks); 
        int indeks3;
        try {
            while (true) {
                cout << "\nMasukkan Nomor Yang Ingin Dihapus: ";
                if (!(cin >> indeks3)) {
                    cout << "Error: " << "Harap Masukkan Dalam Bentuk Angka" << endl;
                    cin.clear();
                    cin.ignore();
                    continue;
                }

                if (indeks3 < 1 || indeks3 > indeks) {
                    cout << "Error: " << "Nomor Bookmark Tidak Valid" << endl;
                    cin.clear();
                    cin.ignore();
                    continue;
                }

                else {
                    cout << "\tManhwa " << data->bookmark[indeks3 - 1].judul << " Telah Dihapus Dari Bookmark\n";
                    for (int j = indeks3 - 1; j < indeks - 1; j++) {
                        data->bookmark[j].judul = data->bookmark[j + 1].judul;
                        data->bookmark[j].chapter = data->bookmark[j + 1].chapter;
                    }
                    indeks--;
                    cin.ignore();
                    break;
                    throw indeks3;
                }
            }
        } catch (int a) {
        }
    }
}

void menuHistory(alldata *data, int *indeks2) {
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
            tampilkanHistory(data, indeks2);
            delay = getch();
        } else if (menuhs == "2") {
            tambahhistory(data, indeks2);
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

void menuBookmark(alldata *data, int *indeks, int *indeks2) {
    while (true) {
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
            tambahBookmark(data, indeks, indeks2);
            cout << "Masukkan apa saja untuk kembali: ";
            delay = getch();
        } else if (menu == "2") {
            ubahBookmark(data, indeks, indeks2);
            cout << "Masukkan apa saja untuk kembali: ";
            delay = getch();
        } else if (menu == "3") {
            hapusBookmark(data, *indeks); 
            cout << "Masukkan apa saja untuk kembali: ";
            delay = getch();
        } else if (menu == "4") {
            lihatBookmark(data, *indeks); 
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


void menuUtama(alldata *data, int *indeks, int *indeks2) {
    while (true) {
        string pilih;
        cout << "\n\nMENU UTAMA\n";
        cout << "1. HISTORY\n";
        cout << "2. BOOKMARK\n";
        cout << "0. EXIT\n";
        cout << "Masukkan Pilihan Anda: ";
        getline(cin, pilih);
        if (pilih == "1") {
            menuHistory(data, indeks2);
        } else if (pilih == "2") {
            menuBookmark(data, indeks, indeks2);
            cout << "Masukkan Apa Saja Untuk Kembali: ";
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
    while (true) {
        if (login(&data.userlp)) {
            cout << "\n\tSelamat Datang Di Program Bookmark!!!\n";
            menuUtama(&data, &indeks, &indeks2);
        } else {
            cout << "\n\tAnda Telah Mencoba Sebanyak 3 Kali ";
            return 0;
        }
    }
    return 0;
}
