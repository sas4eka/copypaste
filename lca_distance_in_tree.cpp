#include <bits/stdc++.h>

using namespace std;

const int N = 50005;
const int L = 20;

vector<pair<int, int> > g[N];

int d[N];
int tin[N];
int tout[N];
int timer = 0;
int par[N][L];
int l;

void dfs(int v, int dist, int parent) {
    tin[v] = ++timer;
    d[v] = dist;

    par[v][0] = parent;
    for (int k = 1; k <= l; k++) {
        par[v][k] = par[par[v][k-1]][k-1];
    }

    for (int j = 0; j < g[v].size(); j++) {
        pair<int, int> next = g[v][j];
        if (next.first == parent) {
            continue;
        }
        dfs(next.first, dist + next.second, v);
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

void precalc(int n) {
    l = 1;
    while( (1 << l) <= n) {
        l++;
    }

    dfs(0, 0, 0);
}

int get_dist(int a, int b) {
    int ca = lca(a, b);
    return d[a] + d[b] - 2*d[ca];
}

int main() {
    int n = 5;
    g[0].push_back(make_pair(1, 1));
    g[1].push_back(make_pair(0, 1));
    g[0].push_back(make_pair(2, 1));
    g[2].push_back(make_pair(0, 1));
    g[2].push_back(make_pair(3, 1));
    g[3].push_back(make_pair(2, 1));
    g[2].push_back(make_pair(4, 1));
    g[4].push_back(make_pair(2, 1));

    printf("   0    \n");
    printf("  / \\  \n");
    printf(" 1   2  \n");
    printf("    / \\\n");
    printf("   3   4\n");

    precalc(n);

    printf("dist(0, 1): %d\n", get_dist(0, 1));
    printf("dist(0, 4): %d\n", get_dist(0, 4));
    printf("dist(1, 3): %d\n", get_dist(1, 3));
    printf("dist(3, 4): %d\n", get_dist(3, 4));

    return 0;
}
