#include <iostream>
#include <algorithm>
using namespace std;
int number[1000000];

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


// 합병정렬
void merge(int *array, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1], R[n2];
    
    for (int i = 0 ; i < n1; i++) {
        L[i] = array[p + i];
    }
    for (int i = 0 ; i < n2; i++) {
        R[i] = array[q + 1 + i];
    }
    
    int i = 0, j = 0, k = p;
    while(i < n1 && j < n2) {
        if (L[i] < R[i]) {
            array[k++] = L[i++];
        } else {
            array[k++] = R[j++];
        }
    }
    
    while(i < n1) {
        array[k++] = L[i++];
    }
    while(j < n2) {
        array[k++] = R[j++];
    }
}
void mergeSort(int *array, int p, int r) {
    if (p < r) {// p>=r일 경우 정렬할 필요가 없기 때문
        int q = (p + r) / 2;
        mergeSort(array, p, q);
        mergeSort(array, q+1, r);
        merge(array, p, q, r);
    }
}

int main(void) {
    int n;
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        cin >> number[i];
    }
    
    mergeSort(number, 0, n - 1);
    
    for (int i = 0 ;i < n; i++) {
        cout << number[i] << "\n";
    }
    return 0;
}
