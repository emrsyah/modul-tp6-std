#include "dll.h"
#include <iostream>
#include <string>

void cetakDaftar(List L) {
    address P = first(L);
    while (P != NULL) {
        cout << info(P).band << " - " << info(P).lagu << endl;
        P = next(P);
    }
    cout << endl;
}

void masukkanData(infotype &X) {
    cout << "Masukkan nama band (satu kata): ";
    cin >> X.band;
    cout << "Masukkan judul lagu (satu kata): ";
    cin >> X.lagu;
}

int main() {
    List L1, L2, L3;
    address P;
    infotype X;

    // Uji createList
    createList_103012300339(L1);
    createList_103012300339(L2);

    // Uji isEmpty
    cout << "Apakah L1 kosong? " << (isEmpty_103012300339(L1) ? "Ya" : "Tidak") << endl;

    // Uji insertFirst
    cout << "\nMemasukkan elemen pertama:" << endl;
    masukkanData(X);
    createNewElmt_103012300339(X, P);
    insertFirst_103012300339(L1, P);

    cout << "\nMemasukkan elemen kedua:" << endl;
    masukkanData(X);
    createNewElmt_103012300339(X, P);
    insertFirst_103012300339(L1, P);

    cout << "Setelah insertFirst:" << endl;
    cetakDaftar(L1);

    // Uji insertLast
    cout << "\nMemasukkan elemen terakhir:" << endl;
    masukkanData(X);
    createNewElmt_103012300339(X, P);
    insertLast_103012300339(L1, P);

    cout << "Setelah insertLast:" << endl;
    cetakDaftar(L1);

    // Uji insertAfter
    cout << "\nMemasukkan setelah elemen pertama:" << endl;
    masukkanData(X);
    createNewElmt_103012300339(X, P);
    insertAfter_103012300339(L1, first(L1), P);

    cout << "Setelah insertAfter:" << endl;
    cetakDaftar(L1);

    // Uji findLagu
    string cariLagu;
    cout << "\nMasukkan judul lagu untuk dicari (satu kata): ";
    cin >> cariLagu;
    P = findLagu_103012300339(cariLagu, L1);
    if (P != NULL) {
        cout << "Ditemukan: " << info(P).band << " - " << info(P).lagu << endl;
    } else {
        cout << "Lagu tidak ditemukan." << endl;
    }

    // Uji removeLagu
    cout << "\nMasukkan judul lagu untuk dihapus (satu kata): ";
    cin >> cariLagu;
    removeLagu_103012300339(cariLagu, L1);
    cout << "Setelah menghapus '" << cariLagu << "':" << endl;
    cetakDaftar(L1);

    // Uji deleteFirst
    address dihapus;
    deleteFirst_103012300339(L1, dihapus);
    cout << "Setelah deleteFirst:" << endl;
    cetakDaftar(L1);

    // Uji deleteLast
    deleteLast_103012300339(L1, dihapus);
    cout << "Setelah deleteLast:" << endl;
    cetakDaftar(L1);

    // Persiapkan L2 untuk concat
    cout << "\nMempersiapkan L2 untuk penggabungan:" << endl;
    cout << "Masukkan elemen pertama untuk L2:" << endl;
    masukkanData(X);
    createNewElmt_103012300339(X, P);
    insertFirst_103012300339(L2, P);

    cout << "Masukkan elemen kedua untuk L2:" << endl;
    masukkanData(X);
    createNewElmt_103012300339(X, P);
    insertLast_103012300339(L2, P);

    cout << "L2:" << endl;
    cetakDaftar(L2);

    // Uji concat
    concat_103012300339(L1, L2, L3);
    cout << "L3 setelah penggabungan:" << endl;
    cetakDaftar(L3);

    return 0;
}
