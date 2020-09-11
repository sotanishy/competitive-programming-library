#include <bits/stdc++.h>
#include "../graph/edge.cpp"
using namespace std;

struct TreeDiameter {

    static pair<int, int> dfs(vector<vector<int>>& G, int v, int p) {
        pair<int, int> ret(0, v);
        for (int c : G[v]) {
            if (c == p) continue;
            auto cost = dfs(G, c, v);
            cost.first++;
            ret = max(ret, cost);
        }
        return ret;
    }

    static pair<int, int> dfs(vector<vector<Edge<int>>>& G, int v, int p) {
        pair<int, int> ret(0, v);
        for (auto& e : G[v]) {
            if (e.to == p) continue;
            auto cost = dfs(G, e.to, v);
            cost.first += e.cost;
            ret = max(ret, cost);
        }
        return ret;
    }

    template <class T>
    static int diameter(vector<vector<T>>& G) {
        auto p = dfs(G, 0, -1);
        auto q = dfs(G, p.second, -1);
        return q.first;
    }
};