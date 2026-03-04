// 12S25007 - Tongam Prozona Manurung

#include <stdio.h>    // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h>   // Untuk INT_MAX dan INT_MIN (nilai integer maksimum dan minimum)
#include <stdlib.h>   // Untuk fungsi malloc dan free
#include <float.h>    // Untuk DBL_MAX dan DBL_MIN (nilai double terbesar dan terkecil)

// Fungsi untuk membaca N bilangan bulat, menghitung nilai min, max,
// rata-rata terendah, dan rata-rata tertinggi dari dua bilangan berturut-turut.
// Mengembalikan jumlah bilangan yang dibaca (N).
int processInputNumbers(int* min_val_ptr, int* max_val_ptr, double* lowest_avg_ptr, double* highest_avg_ptr) {
    int n; // Variabel untuk menyimpan jumlah baris angka
    scanf("%d", &n); // Menerima input N

    // Inisialisasi nilai min, max, rata-rata terendah, dan rata-rata tertinggi
    *min_val_ptr = INT_MAX;
    *max_val_ptr = INT_MIN;
    *lowest_avg_ptr = DBL_MAX;   // Inisialisasi dengan nilai double terbesar
    *highest_avg_ptr = DBL_MIN;  // Inisialisasi dengan nilai double terkecil

    // Jika N kurang dari atau sama dengan 0, tidak ada angka yang perlu diproses
    if (n <= 0) {
        return n;
    }

    // Alokasikan memori secara dinamis untuk menyimpan N bilangan bulat
    int* numbers = (int*) malloc(n * sizeof(int));
    if (numbers == NULL) {
        // Penanganan error jika alokasi memori gagal
        fprintf(stderr, "Gagal mengalokasikan memori!\n");
        exit(EXIT_FAILURE);
    }

    // Loop untuk menerima N buah bilangan bulat dan menemukan nilai min/max
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]); // Menerima bilangan bulat
        
        // Membandingkan untuk menemukan nilai terkecil
        if (numbers[i] < *min_val_ptr) {
            *min_val_ptr = numbers[i];
        }
        
        // Membandingkan untuk menemukan nilai terbesar
        if (numbers[i] > *max_val_ptr) {
            *max_val_ptr = numbers[i];
        }
    }

    // Hitung rata-rata terendah dan tertinggi dari dua nilai yang dimasukkan berturut-turut
    // Hanya jika ada setidaknya dua bilangan untuk membentuk pasangan
    if (n >= 2) {
        for (int i = 0; i < n - 1; i++) {
            double current_avg = (double)(numbers[i] + numbers[i+1]) / 2.0;
            
            // Perbarui rata-rata terendah
            if (current_avg < *lowest_avg_ptr) {
                *lowest_avg_ptr = current_avg;
            }
            
            // Perbarui rata-rata tertinggi
            if (current_avg > *highest_avg_ptr) {
                *highest_avg_ptr = current_avg;
            }
        }
    }
    // Jika n < 2, *lowest_avg_ptr akan tetap DBL_MAX, dan *highest_avg_ptr akan tetap DBL_MIN
    // Ini akan ditangani di fungsi displayResults

    // Bebaskan memori yang telah dialokasikan
    free(numbers);
    
    return n; // Mengembalikan jumlah bilangan yang dibaca
}

// Fungsi untuk menampilkan nilai terkecil, terbesar, rata-rata terendah, dan rata-rata tertinggi
void displayResults(int n_val, int min_val, int max_val, double lowest_avg, double highest_avg) {
    // Menampilkan nilai terkecil dan terbesar hanya jika N > 0
    if (n_val > 0) {
        printf("%d\n", min_val);
        printf("%d\n", max_val);
    }
    
    // Menampilkan rata-rata terendah hanya jika N >= 2
    if (n_val >= 2 && lowest_avg != DBL_MAX) {
        printf("%.2f\n", lowest_avg); // Format output dengan 2 digit presisi
    }

    // Menampilkan rata-rata tertinggi hanya jika N >= 2
    if (n_val >= 2 && highest_avg != DBL_MIN) {
        printf("%.2f\n", highest_avg); // Format output dengan 2 digit presisi
    }
}

int main() {
    int min_val_result;
    int max_val_result;
    double lowest_avg_result;
    double highest_avg_result; // Variabel baru untuk rata-rata tertinggi
    int n_input; // Untuk menyimpan nilai N yang dibaca

    // Memanggil fungsi untuk memproses input dan mendapatkan hasilnya
    n_input = processInputNumbers(&min_val_result, &max_val_result, &lowest_avg_result, &highest_avg_result);

    // Memanggil fungsi untuk menampilkan hasil
    displayResults(n_input, min_val_result, max_val_result, lowest_avg_result, highest_avg_result);

    return 0; // Menandakan program berakhir dengan sukses
}
