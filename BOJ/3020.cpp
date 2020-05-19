#include <iostream>
#include <algorithm>
using namespace std;
int b[100001];
int t[100001];
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,h;
    cin >> n >> h;
    for (int i = 0; i < n/2; i++) {
        cin >> b[i] >> t[i];
    }
    sort(t,t+n/2);
    sort(b,b+n/2);
    int size = n/2;
    int height = 500000, cnt = 0;
    for (int i = 1; i <= h; i++) {
        int bot = size - (lower_bound(b, b+size, i) - b);
        int top = size - (upper_bound(t, t+size, h-i) - t);
        if (bot + top < height) {
            height = bot + top;
            cnt = 1;
        } else if (bot + top == height) {
            cnt++;
        }
    }
    cout << height << " " << cnt;
    return 0;
}
