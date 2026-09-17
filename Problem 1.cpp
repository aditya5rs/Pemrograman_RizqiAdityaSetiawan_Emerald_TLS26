#include <iostream>

using namespace std;

// Fungsi buatan manual untuk menghapus elemen array dengan pergeseran
void hapusElemen(int arr[], int &sisa, int idx) {
    for (int i = idx; i < sisa - 1; i++) {
        arr[i] = arr[i + 1];
    }
    sisa--;
}

int main() {
    int N, K;

    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai awal K: ";
    cin >> K;

    // Menyiapkan array astronot secara manual
    int astronot[1000];
    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
    }

    int sisa = N;
    int idx_sekarang = 0;

    cout << "\nUrutan astronot yang dieliminasi: ";

    // Perulangan sampai tersisa 1 astronot
    while (sisa > 1) {
        idx_sekarang = (idx_sekarang + K - 1) % sisa;
        int tereliminasi = astronot[idx_sekarang];

        cout << tereliminasi << (sisa == 2 ? "" : ", ");

        // Hapus elemen secara manual
        hapusElemen(astronot, sisa, idx_sekarang);

        // Update nilai K sesuai aturan
        if (tereliminasi % 2 == 0) {
            K += 2; // Genap: bertambah 2
        } else {
            K -= 1; // Ganjil: berkurang 1
        }

        // Batas minimal K adalah 2
        if (K < 2) {
            K = 2;
        }
    }

    cout << "\nAstronot terakhir yang bertahan: " << astronot[0] << endl;

    return 0;
}