// 12S25007 - Tongam Prozona Manurung


#include <stdio.h>    // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h>   // Untuk INT_MAX dan INT_MIN (nilai integer maksimum dan minimum)
#include <stdlib.h>   // Untuk fungsi malloc dan free

// Fungsi untuk menerima N bilangan bulat dan menemukan nilai min/max
// Mengembalikan pointer ke array yang berisi min dan max
// Ukuran array yang dikembalikan adalah 2: result[0] = min, result[1] = max
int* getInputNumbers() {
    int n; // Variabel untuk menyimpan jumlah baris angka
    int num; // Variabel untuk menyimpan setiap bilangan yang diinput
    int min_val = INT_MAX; // Inisialisasi min_val dengan nilai integer terbesar
    int max_val = INT_MIN; // Inisialisasi max_val dengan nilai integer terkecil

    // Menerima input n sebagai jumlah baris angka
    scanf("%d", &n);

    // Loop untuk menerima n buah bilangan bulat
    for (int i = 0; i < n; i++) {
        scanf("%d", &num); // Menerima bilangan bulat
        
        // Membandingkan dengan nilai terkecil yang sudah ada
        if (num < min_val) {
            min_val = num;
        }
        
        // Membandingkan dengan nilai terbesar yang sudah ada
        if (num > max_val) {
            max_val = num;
        }
    }

    // Alokasikan memori untuk menyimpan min_val dan max_val
    int* result = (int*) malloc(sizeof(int) * 2);
    if (result == NULL) {
        // Handle error jika alokasi memori gagal
        fprintf(stderr, "Gagal mengalokasikan memori!\n");
        exit(EXIT_FAILURE);
    }
    result[0] = min_val;
    result[1] = max_val;
    
    return result; // Mengembalikan pointer ke array hasil
}

// Fungsi untuk menampilkan nilai terkecil dan terbesar
void displayMinMax(int min_val, int max_val) {
    // Menampilkan nilai terkecil pada baris pertama
    printf("%d\n", min_val);
    
    // Menampilkan nilai terbesar pada baris kedua
    printf("%d\n", max_val);
}

int main() {
    int* results; // Pointer untuk menyimpan hasil dari fungsi getInputNumbers

    // Memanggil fungsi untuk mendapatkan nilai min dan max
    results = getInputNumbers();

    // Memanggil fungsi untuk menampilkan nilai min dan max
    displayMinMax(results[0], results[1]);

    // Penting: Bebaskan memori yang dialokasikan oleh malloc
    free(results);
    results = NULL; // Hindari dangling pointer

    return 0; // Menandakan program berakhir dengan sukses
}
