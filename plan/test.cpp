#include <iostream>

// 基数排序
void radixSort(int *arr, int n) {

    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int exp = 1;
    while (max / exp > 0) {
        int bucket[10] = {0};
        for (int i = 0; i < n; i++) {
            bucket[(arr[i] / exp) % 10]++;
        }

        for (int i = 1; i < 10; i++) {
            bucket[i] += bucket[i - 1];
        }

        int output[n];
        for (int i = n - 1; i >= 0; i--) {
            output[--bucket[(arr[i] / exp) % 10]] = arr[i];
        }

        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }

        exp *= 10;
    }
}


int main()
{
    // 测试
    int arr[] = {122, 1121, 13, 5, 61};
    int n = sizeof(arr) / sizeof(arr[0]);
    radixSort(arr, n);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}