#include <bits/stdc++.h>

using namespace std;

const int N = 10005;
const int L = 22;

vector<int> g[N];

int tin[N];
int tout[N];
int timer = 0;
int par[N][L];
int l;

void dfs(int v, int parent) {
    tin[v] = ++timer;

    par[v][0] = parent;
    for (int k = 1; k <= l; k++) {
        par[v][k] = par[par[v][k-1]][k-1];
    }

    for (int next : g[v]) {
        if (next == parent) {
            continue;
        }
        dfs(next, v);
    }
    tout[v] = ++timer;
}

bool is_ancestor(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
    if (is_ancestor(a, b)) return a;
    if (is_ancestor(b, a)) return b;

    for (int k = l; k >= 0; k--) {
        if (!is_ancestor(par[a][k], b)) {
            a = par[a][k];
        }
    }
    return par[a][0];
}

void precalc(int n, int root) {
    l = 1;
    while( (1 << l) <= n) {
        l++;
    }

    dfs(root, root);
}

void solve() {
    for (int i = 0; i < N; i++) {
        g[i].clear();
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            x--;
            g[i].push_back(x);
            g[x].push_back(i);
        }
    }
    int root = 0;

    precalc(n, root);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << lca(a, b) + 1 << "\n";
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cout << "Case " << (i+1) << ":\n";
        solve();
    }
    return 0;
}
