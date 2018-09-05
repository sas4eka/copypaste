#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    map<int, int> mp;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (!mp.count(v[i])) {
            mp[v[i]] = cnt++;
        }
        v[i] = mp[v[i]];
    }

    int q;
    cin >> q;
    vector<pair<int, int> > queries(q);
    vector<int> ans(q);
    int sz = 1 + (int)sqrt(n);
    int k = (n + sz - 1) / sz;
    vector<vector<pair<int, int> > > buckets(k);
    for (int j = 0; j < q; j++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        queries[j] = {a, b};
        buckets[a/sz].push_back({b, j});
    }

    for (int bi = 0; bi < k; bi++) {
        vector<pair<int, int> > & bucket = buckets[bi];
        sort(bucket.begin(), bucket.end());
        int from = 0;
        int to = 0;
        vector<int> nums(n);
        nums[0] = 1;
        int tot = 1;
        for (auto e : bucket) {
            int j = e.second;
            int a = queries[j].first;
            int b = queries[j].second;
            while(to < b) {
                to++;
                if (++nums[v[to]] == 1) {
                    tot++;
                }
            }
            while(from > a) {
                from--;
                if (++nums[v[from]] == 1) {
                    tot++;
                }
            }
            while(from < a) {
                if (--nums[v[from]] == 0) {
                    tot--;
                }
                from++;
            }
            ans[j] = tot;
        }
    }

    for (int j = 0; j < q; j++) {
        cout << ans[j] << "\n";
    }

    return 0;
}
