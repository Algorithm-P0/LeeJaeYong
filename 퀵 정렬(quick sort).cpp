#include <iostream>
#include <algorithm>
using namespace std;
int number[1000000];

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int *array, int p, int r) {
    int i = p - 1, j = p;
    while(j <= r) {
        if (array[j] >= array[r]) {
            j++;
        } else {
            i++;
            swap(array[i], array[j]);
            j++;
        }
    }
    swap(array[++i], array[r]);
    return i;
}

void quickSort(int *array, int p, int r) {
    if (p < r) {
        int q = partition(array, p, r);     // 분할
        quickSort(array, p, q - 1);         // 왼쪽 부분 정렬
        quickSort(array, q + 1, r);         // 오른쪽 부분 정렬
    }
}

int main(void) {
    int n;
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        cin >> number[i];
    }
    quickSort(number, 0, n-1);
    for (int i = 0 ;i < n; i++) {
        cout << number[i] << "\n";
    }
    return 0;
}
