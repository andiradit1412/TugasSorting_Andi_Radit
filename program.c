#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Implementasi Bubble Sort
void bubble_sort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Implementasi Selection Sort
void selection_sort(float arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            float temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

// Implementasi Insertion Sort
void insertion_sort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void print_array(float arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    // Memeriksa argumen baris perintah
    if (argc < 2) {
        printf("Penggunaan: %s <ukuran_problem>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    
    // Alokasi memori dinamis
    float *original = (float*)malloc(n * sizeof(float));
    float *temp = (float*)malloc(n * sizeof(float));

    if (original == NULL || temp == NULL) {
        printf("Gagal mengalokasikan memori.\n");
        return 1;
    }

    // Mengisi array dengan nilai acak
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        original[i] = ((float)rand() / (float)(RAND_MAX)) * 100.0;
    }

    clock_t start, end;
    double cpu_time_used;

    printf("Mengurutkan %d elemen data acak...\n\n", n);

    // 1. Eksekusi Bubble Sort pada salinan data
    memcpy(temp, original, n * sizeof(float));
    start = clock();
    bubble_sort(temp, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Waktu Bubble Sort    : %f detik\n", cpu_time_used);

    // 2. Eksekusi Selection Sort pada salinan data
    memcpy(temp, original, n * sizeof(float));
    start = clock();
    selection_sort(temp, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Waktu Selection Sort : %f detik\n", cpu_time_used);

    // 3. Eksekusi Insertion Sort pada salinan data
    memcpy(temp, original, n * sizeof(float));
    start = clock();
    insertion_sort(temp, n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Waktu Insertion Sort : %f detik\n", cpu_time_used);

    // Dealokasi memori
    free(original);
    free(temp);

    return 0;
}