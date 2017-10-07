#include <bits/stdc++.h>

using namespace std;

const int SZ = 2;
long long MOD = 1000000007;

struct Matrix {
    int n, m;
    long long a[SZ][SZ];
    Matrix(int n, int m): n(n), m(m) {
        memset(a, 0, sizeof(a));
    }

    long long * operator [] (int i) {
        return a[i];
    }

    const long long * operator [] (int i) const {
        return a[i];
    }

    Matrix operator * (const Matrix & other) {
        Matrix res(n, other.m);
        if (m != other.n) {
            cerr << "Can't multiply: " << m << " != " << other.n << endl;
            return res;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < other.m; j++) {
                for (int k = 0; k < m; k++) {
                    res[i][j] += a[i][k] * other[k][j];
                    res[i][j] %= MOD;
                }
            }
        }
        return res;
    }
};

Matrix binpow(Matrix a, long long x) {
    if (x == 0) {
        Matrix res(a.n, a.n);
        for (int i = 0; i < a.n; i++) {
            res[i][i] = 1;
        }
        return res;
    }
    if (x % 2 == 0) {
        Matrix t = binpow(a, x/2);
        return t * t;
    } else {
        return a * binpow(a, x-1);
    }
}

int main() {
    Matrix row(1, 2);
    row[0][0] = 1;
    Matrix f(2, 2);
    f[0][0] = f[0][1] = f[1][0] = 1;
    printf("Fibonacci sequence: ");
    for (long long n = 0; n < 10; n++) {
        Matrix res = row * binpow(f, n);
        printf("%lld ", res[0][0]);
    }
    printf("\n");
    return 0;
}
