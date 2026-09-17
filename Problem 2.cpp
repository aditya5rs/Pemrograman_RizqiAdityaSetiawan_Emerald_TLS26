#include <iostream>

using namespace std;

// Fungsi buatan manual untuk menghitung panjang karakter array 
int hitungPanjang(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Fungsi buatan manual untuk mengubah huruf kecil ke kapital 
char keKapital(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 32;
    }
    return c;
}

// Fungsi buatan manual untuk proses enkripsi
void enkripsiSandi(char pesan[], char hasil[]) {
    int len = hitungPanjang(pesan);
    int prev_shift = 0;

    for (int i = 0; i < len; i++) {
        char c = keKapital(pesan[i]);

        if (c >= 'A' && c <= 'Z') {
            int pos_asli = c - 'A' + 1; // A=1, B=2, dst.
            int pos_baru = pos_asli + prev_shift;

            // Penanganan jika melewati Z (posisi > 26)
            while (pos_baru > 26) {
                pos_baru -= 26;
            }

            hasil[i] = (char)('A' + pos_baru - 1);
            
            // Pergeseran huruf berikutnya ditentukan oleh nilai asli huruf sebelumnya
            prev_shift = pos_asli; 
        } else {
            hasil[i] = c; // Jika ada karakter selain alfabet
        }
    }
    hasil[len] = '\0'; // Penanda akhir string
}

int main() {
    char pesan[1000];
    char hasilEnkripsi[1000];

    cout << "Masukkan pesan rahasia: ";
    cin >> pesan;

    enkripsiSandi(pesan, hasilEnkripsi);

    cout << "Pesan terenkripsi: " << hasilEnkripsi << endl;

    return 0;
}