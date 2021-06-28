#include <iostream>
using namespace std;

int main() {
    int n, i;
    int sum = 0;
    cin >> n;
    for (i = 0; ; i++) {
        sum += i;
        if (sum >= n) {
            break;
        }
    }
    cout << i << endl;

    return 0;
}