#include <iostream>
#include <algorithm>
using namespace std;
int A[50];
int B[50];
bool compare(int a, int b) {
    return a > b;
}
int main(void) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    sort(A, A+n, compare);
    sort(B, B+n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i]*B[i];
    }

    cout << sum;
    return 0;
}
