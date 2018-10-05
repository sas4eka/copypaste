#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<
int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
    ordered_set;

int main() {
    ordered_set s;

    int q;
    cin >> q;
    for (int t = 0; t < q; t++) {
        char op;
        cin >> op;
        int x;
        cin >> x;
        if (op == 'I') {
            s.insert(x);
        } else if (op == 'D') {
            s.erase(x);
        } else if (op == 'K') {
            auto it = s.find_by_order(x-1);
            if (it == s.end()) {
                cout << "invalid\n";
            } else {
                cout << *it << "\n";
            }
        } else if (op == 'C') {
            cout << s.order_of_key(x) << "\n";
        }
    }

    return 0;
}
