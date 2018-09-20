#include <bits/stdc++.h>

using namespace std;

long long C(int n, int k) {
    long double res = 1;
    for (int i = 1; i <= k; i++) {
        res = res * (n-k+i) / i;
    }
    return (long long) (res + 0.01);
}

int main() {
    int n = 6;
    int k = 3;
    cout << C(n, k) << endl;
    return 0;
}
