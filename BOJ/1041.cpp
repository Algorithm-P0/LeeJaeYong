#include <iostream>
#include <algorithm>
using namespace std;
int dice[6];

int main(void) {
    long long int n;
    cin >> n;
    int minOne = 0, minTwo = 0, minThree = 0;
    long long int sum = 0;
    for (int i = 0; i < 6; i++) {
        cin >> dice[i];
    }
    if (n == 1) {
        sort(dice,dice+6);
        for (int i = 0 ; i < 5; i++) {
            sum += dice[i];
        }
        cout << sum;
    } else {
        dice[0] = min(dice[0], dice[5]);
        dice[1] = min(dice[1], dice[4]);
        dice[2] = min(dice[2], dice[3]);
        sort(dice, dice+3);
        minOne = dice[0];
        minTwo = dice[0] + dice[1];
        minThree = dice[0] + dice[1] + dice[2];

        sum += minOne * ((n-2) * (n-2) + (n-2) * (n-1) * 4);
        sum += minTwo * ((n - 1) * 4 + (n - 2) * 4);
        sum += minThree * 4;
        cout << sum;
    }

    return 0;
}



