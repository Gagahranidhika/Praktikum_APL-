#include <iostream>
#include <conio.h>
using namespace std;

struct History {
    string manhwa;
    int chapter;
};

struct Bookmark {
    string judul;
    int chapter;
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
    string namaManhwa;
    int chapterTerakhir;

    while (true) {
        cout << "Masukkan Nama Manhwa: ";
        getline(cin >> ws, namaManhwa);
        if (!namaManhwa.empty()) {
            break;
        }
        cout << "Nama Manhwa tidak boleh kosong. Silakan masukkan kembali." << endl;
    }

    while (true) {
        cout << "Masukkan Chapter Manhwa: ";
        if (!(cin >> chapterTerakhir)) {
            cin.clear();
            cin.ignore();
            cout << "Error: Harap Masukkan Dalam Bentuk Angka" << endl;
            break;
        } else if (chapterTerakhir < 0) {
            cout << "Error: Chapter Tidak Valid" << endl;
        } else {
            data->history[*indeks2].manhwa = namaManhwa;
            data->history[*indeks2].chapter = chapterTerakhir;

            for (int i = 0; i < *indeks2; i++) {
                if (data->history[*indeks2].manhwa == data->bookmark[i].judul) {
                    data->bookmark[i].chapter = data->history[*indeks2].chapter;
                }
            }

            (*indeks2)++;

            for (int i = 0; i < *indeks2 - 1; i++) {
                if (data->history[i].manhwa == namaManhwa && i != *indeks2 - 1) {
                    for (int j = i; j < *indeks2 - 1; j++) {
                        data->history[j].manhwa = data->history[j + 1].manhwa;
                        data->history[j].chapter = data->history[j + 1].chapter;
                    }
                    (*indeks2)--;
                    break;
                }
            }

            break;
        }
    }
    cin.ignore();
}

void bubblesort_ascend(Bookmark *data, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j].judul > data[j + 1].judul) {
                Bookmark temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void selection_descend(Bookmark *data, int size) {
    for (int i = 0; i < size - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (data[j].judul > data[max_idx].judul) {
                max_idx = j;
            }
        }
        Bookmark temp = data[max_idx];
        data[max_idx] = data[i];
        data[i] = temp;
    }
}

void shell_ascend(Bookmark *data, int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        // Lakuk
        for (int i = gap; i < size; i += 1) {
            Bookmark temp = data[i];
            int j;
            for (j = i; j >= gap && data[j - gap].chapter > temp.chapter; j -= gap) {
                data[j] = data[j - gap];
            }
            data[j] = temp;
        }
    }
}

int binary_search(Bookmark *data, int size, string key) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (data[mid].judul == key) {
            return mid; 
        } else if (data[mid].judul < key) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }
    }
    return -1; 
}

int interpolation_search(Bookmark *data, int size, int keyChapter) {
    int low = 0, high = size - 1;
    while (low <= high && keyChapter >= data[low].chapter && keyChapter <= data[high].chapter) {
        if (low == high) {
            if (data[low].chapter == keyChapter) return low;
            return -1; 
        }
        double fraction = (double)(keyChapter - data[low].chapter) / (data[high].chapter - data[low].chapter);
        int pos = low + (int)((high - low) * fraction);
        if (data[pos].chapter == keyChapter) {
            return pos; 
        } else if (data[pos].chapter < keyChapter) {
            low = pos + 1; 
        } else {
            high = pos - 1; 
        }
    }
    return -1; 
}

void lihatBookmark(alldata *data, int &indeks) {
    if (indeks == 0) {
        cout << "\n\tBookmark Anda Kosong Saat ini\n";
    } else {
        string pilih;
        cout<<"\nMenu Urutan\n";
        cout<<"\n1. Judul A-Z\n";
        cout<<"\n2. Judul Z-A\n";
        cout<<"\n3. Chapter \n";
        cout<<"\nPilih: ";cin>>pilih;
        
        if (pilih == "1"){
            bubblesort_ascend(data->bookmark, indeks);
            cout << "Manhwa Yang Anda Bookmark: \n";
            cout << " \t" << "Judul\t\tChapter\n";
            for (int i = 0; i < indeks; i++) {
                cout << i + 1 << "\t" << data->bookmark[i].judul << "\t\t" << data->bookmark[i].chapter << endl;
            }
            string key;
            cout << "Masukkan judul yang ingin dicari: ";
            cin >> key;
            int result = binary_search(data->bookmark, indeks, key);
            if (result != -1) {
                cout << "Judul ditemukan di indeks: " <<endl;
                cout << "\tJudul\t\tChapter\n"<< data->bookmark[result].judul << "\t\t" << data->bookmark[result].chapter << endl;
            } else {
                cout << "Judul tidak ditemukan." << endl;
            }
        } else if (pilih == "2"){
            selection_descend(data->bookmark, indeks);
            cout << "Manhwa Yang Anda Bookmark: \n";
            cout << " \t" << "Judul\t\tChapter\n";
            for (int i = 0; i < indeks; i++) {
                cout << i + 1 << "\t" << data->bookmark[i].judul << "\t\t" << data->bookmark[i].chapter << endl;
            }
        } else if (pilih == "3"){
            shell_ascend(data->bookmark, indeks);
            cout << "Manhwa Yang Anda Bookmark: \n";
            cout << " \t" << "Judul\t\tChapter\n";
            for (int i = 0; i < indeks; i++) {
                cout << i + 1 << "\t" << data->bookmark[i].judul << "\t\t" << data->bookmark[i].chapter << endl;
            }
            int keyChapter;
            cout << "Masukkan chapter yang ingin dicari: ";
            cin >> keyChapter;
            int result = interpolation_search(data->bookmark, indeks, keyChapter);
            if (result != -1) {
                cout << "Chapter ditemukan  " << endl;
                cout << "\tJudul\t\tChapter\n"<< data->bookmark[result].judul << "\t\t" << data->bookmark[result].chapter << endl;
            } else {
                cout << "Chapter tidak ditemukan." << endl;
            }
        } else {
            cout<<"\n\tPilihan Tidak Valid\n";
        }
    }
    cin.ignore();
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
        cout << "Anda Belum Pernah Membaca Manhwa " << calon;
        cout << "\nApakah Anda Yakin Untuk Mendaftarkan Dalam Bookmark? (Ya untuk menerima)";
        cin >> yakin;
        if (yakin == "ya" || yakin == "Ya" || yakin == "YA") {
            data->bookmark[*indeks].judul = calon;
            data->bookmark[*indeks].chapter = 0;
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
        cout << " \t" << "Judul\t\tChapter\n";
        for (int i = 0; i < *indeks; i++) {
            cout << i + 1 << "\t" << data->bookmark[i].judul << "\t\t" << data->bookmark[i].chapter << endl;
        }
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
                                    data->bookmark[i].chapter = 0;
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
        cout << " \t" << "Judul\t\tChapter\n";
        for (int i = 0; i < indeks; i++) {
            cout << i + 1 << "\t" << data->bookmark[i].judul << "\t\t" << data->bookmark[i].chapter << endl;
        }
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
