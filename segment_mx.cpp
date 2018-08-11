#include <bits/stdc++.h>

using namespace std;

int n;
const int MAXN = 100002;
int t[4*MAXN];

int mx(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return max(mx(v*2, tl, tm, l, min(r,tm)),
        mx(v*2+1, tm+1, tr, max(l,tm+1), r));
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(v*2, tl, tm, pos, new_val);
        } else {
            update(v*2+1, tm+1, tr, pos, new_val);
        }
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

int main() {
    memset(t, 0, sizeof(t));
    n = 5;
    update(1, 0, n-1, 2, 228);
    update(1, 0, n-1, 4, 322);
    update(1, 0, n-1, 1, 1337);
    cout << mx(1, 0, n-1, 0, 4) << endl;
    cout << mx(1, 0, n-1, 3, 3) << endl;
    cout << mx(1, 0, n-1, 2, 3) << endl;
    cout << mx(1, 0, n-1, 2, 4) << endl;
    return 0;
}
