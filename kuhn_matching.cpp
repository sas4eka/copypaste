#include <bits/stdc++.h>

using namespace std;

const int N = 1001;
vector<int> g[N];

int p[N];
int used[N];

bool try_kuhn(int v) {
    used[v] = 1;
    for (int j = 0; j < g[v].size(); j++) {
        int next = g[v][j];
        int w = p[next];
        if (w == -1 || (used[w] == 0 && try_kuhn(w))) {
            p[next] = v;
            return true;
        }
    }
    return false;
}

int main() {
    int n = 4;
    g[0].push_back(0);
    g[0].push_back(1);
    g[1].push_back(2);
    g[2].push_back(2);
    g[2].push_back(3);
    g[3].push_back(3);

    printf("  0   1   2   3\n");
    printf(" / \\   \\ / \\ /\n");
    printf("0   1   2   3\n");

    memset(p, 255, sizeof(p));
    int size = 0;
    for (int i = 0; i < n; i++) {
        memset(used, 0, sizeof(used));
        if (try_kuhn(i)) {
            size++;
        }
    }

    printf("Matching size: %d\n", size);
    return 0;
}
