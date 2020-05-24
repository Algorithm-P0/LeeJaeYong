#include <iostream>
#include <algorithm>
using namespace std;
int wifi[200000];

bool possible(int dis, int n, int c) {
    int cnt = 1;
    int tmp = wifi[0];
    for (int i = 1; i < n; i++) {
        if (wifi[i] - tmp >= dis) {
            cnt++;
            tmp = wifi[i];
        }
    }
    if (cnt >= c) {
        return true;
    } else {
        return false;
    }
}
void binarySearch(int n, int c) {
    int start = 1;
    int end = wifi[n-1] - wifi[0];
    int mid, result = 0;
    while(start <= end) {
        mid = (start + end) / 2;
        if (possible(mid, n, c)) {
            result = max(mid, result);
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << result << "\n";
}
int main(void) {
    int n,c;
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> wifi[i];
    }
    sort(wifi, wifi+n);
    binarySearch(n, c);
    
    return 0;
}
