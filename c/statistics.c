#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

double calculate_mean(int *arr, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum / n;
}

double calculate_median(int *arr, int n) {
    int *sorted = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        sorted[i] = arr[i];
    qsort(sorted, n, sizeof(int), compare);

    double median;
    if (n % 2 == 0)
        median = (sorted[n / 2 - 1] + sorted[n / 2]) / 2.0;
    else
        median = sorted[n / 2];

    free(sorted);
    return median;
}

void calculate_mode(int *arr, int n) {
    int *sorted = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        sorted[i] = arr[i];
    qsort(sorted, n, sizeof(int), compare);

    int max_count = 0;
    int current_count = 1;

    // First pass: find the maximum frequency
    for (int i = 1; i < n; i++) {
        if (sorted[i] == sorted[i - 1])
            current_count++;
        else
            current_count = 1;
        if (current_count > max_count)
            max_count = current_count;
    }
    if (max_count == 0) max_count = 1;

    // Second pass: print all values with max frequency
    printf("Mode: ");
    current_count = 1;
    int printed = 0;
    for (int i = 1; i <= n; i++) {
        if (i < n && sorted[i] == sorted[i - 1]) {
            current_count++;
        } else {
            if (current_count == max_count) {
                if (printed) printf(", ");
                printf("%d", sorted[i - 1]);
                printed = 1;
            }
            current_count = 1;
        }
    }
    printf("\n");

    free(sorted);
}

int main() {
    int data[] = {4, 7, 2, 7, 1, 3, 4, 7, 2, 9};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Data: ");
    for (int i = 0; i < n; i++)
        printf("%d ", data[i]);
    printf("\n");

    printf("Mean: %.2f\n", calculate_mean(data, n));
    printf("Median: %.2f\n", calculate_median(data, n));
    calculate_mode(data, n);

    return 0;
}
