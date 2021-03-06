#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../../tree/euler_tour.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct AddMonoid {
    using T = ll;
    static constexpr T id = 0;
    static T op(T a, T b) { return a + b; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    vector<vector<int>> G(N);
    for (int i = 1; i < N; ++i) {
        int p;
        cin >> p;
        G[p].push_back(i);
    }
    EulerTour<AddMonoid> et(G, 0);
    for (int i = 0; i < N; ++i) et.update(i, a[i]);
    for (int i = 0; i < Q; ++i) {
        int t, u;
        cin >> t >> u;
        if (t == 0) {
            int x;
            cin >> x;
            et.update(u, et.get(u) + x);
        } else {
            cout << et.subtree_fold(u) << "\n";
        }
    }
}