#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "../../graph/two_edge_connected_components.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    TwoEdgeConnectedComponents comp(G);
    vector<vector<int>> ans(comp.count());
    for (int i = 0; i < N; ++i) ans[comp[i]].push_back(i);
    cout << ans.size() << "\n";
    for (auto& v : ans) {
        cout << v.size();
        for (int u : v) cout << " " << u;
        cout << "\n";
    }
}