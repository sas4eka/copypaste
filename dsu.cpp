#include <bits/stdc++.h>

using namespace std;

const int N = 100002;
int parent[N];
int size[N];

int get_parent(int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = get_parent(parent[v]);
}

bool union_sets(int a, int b) {
    a = get_parent(a);
    b = get_parent(b);
    if (a != b) {
        if (size[a] < size[b]) {
            swap(a, b);
        }
        parent[b] = a;
        size[a] += size[b];
        return true;
    }
    return false;
}

void init_dsu(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

int main() {
    int n = 6;
    init_dsu(n);
    union_sets(0, 3);
    union_sets(2, 4);
    union_sets(2, 3);
    for (int i = 0; i < n; i++) {
        cout << i << " " << get_parent(i) << endl;
    }
    return 0;
}
