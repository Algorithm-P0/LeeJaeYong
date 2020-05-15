#include <iostream>
#include <algorithm>
using namespace std;
int number[1000000];

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
// 선택정렬
void selectionSort(int *array, int n) {
    for (int i = n - 1; i > 0; i--) {
        int maxIndex = 0;
        for (int j = 0; j <= i; j++) {
            if (array[maxIndex] < array[j]) {
                maxIndex = j;
            }
        }
        swap(array[maxIndex], array[i]);
    }
}
// 버블정렬
void bubbleSort(int *array, int n) {
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (array[j] > array[j+1]) {
                swap(array[j], array[j+1]);
            }
        }
    }
}

// 삽입정렬
void insertSort(int *array, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (array[j-1] > array[j]) {
                swap(array[j-1], array[j]);
            }
        }
    }
}

int main(void) {
    int n;
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        cin >> number[i];
    }
//    selectionSort(number, n);
//    bubbleSort(number, n);
//    insertSort(number, n);
    for (int i = 0 ;i < n; i++) {
        cout << number[i] << "\n";
    }
    return 0;
}
