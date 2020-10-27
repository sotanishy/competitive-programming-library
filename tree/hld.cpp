#pragma once
#include <algorithm>
#include <vector>
#include "../data-structure/segtree/segment_tree.cpp"

/*
 * @brief Heavy-Light Decomposition
 * @docs docs/tree/hld.md
 */
template <typename M>
class HLD {
    using T = typename M::T;

public:
    HLD() = default;
    explicit HLD(const std::vector<std::vector<int>>& G) : HLD(G, std::vector<T>(G.size(), M::id)) {}
    HLD(const std::vector<std::vector<int>>& G, const std::vector<T>& val)
        : G(G), size(G.size()), depth(G.size()), par(G.size(), -1), pos(G.size()), head(G.size()), heavy(G.size(), -1) {
        dfs(0);
        decompose(0, 0);
        std::vector<T> val_ordered(val.size());
        for (int i = 0; i < (int) val.size(); ++i) val_ordered[pos[i]] = val[i];
        st = SegmentTree<M>(val_ordered);
    }

    T operator[](int v) const {
        return st[pos[v]];
    }

    void update(int v, const T& x) {
        st.update(pos[v], x);
    }

    T fold(int u, int v) const {
        T res = M::id;
        while (head[u] != head[v]) {
            if (pos[head[u]] > pos[head[v]]) std::swap(u, v);
            T val = st.fold(pos[head[v]], pos[v] + 1);
            res = M::op(val, res);
            v = par[head[v]];
        }
        if (pos[u] > pos[v]) std::swap(u, v);
        T val = st.fold(pos[u], pos[v] + 1);
        return M::op(val, res);
    }

    int lca(int u, int v) const {
        while (true) {
            if (pos[u] > pos[v]) std::swap(u, v);
            if (head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }

    int dist(int u, int v) const {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

private:
    std::vector<std::vector<int>> G;
    std::vector<int> size, depth, par, pos, head, heavy;
    int cur_pos = 0;
    SegmentTree<M> st;

    void dfs(int v) {
        size[v] = 1;
        int max_size = 0;
        for (int c : G[v]) {
            if (c == par[v]) continue;
            par[c] = v;
            depth[c] = depth[v] + 1;
            dfs(c);
            size[v] += size[c];
            if (size[c] > max_size) {
                max_size = size[c];
                heavy[v] = c;
            }
        }
    }

    void decompose(int v, int h) {
        head[v] = h;
        pos[v] = cur_pos++;
        if (heavy[v] != -1) decompose(heavy[v], h);
        for (int c : G[v]) {
            if (c != par[v] && c != heavy[v]) decompose(c, c);
        }
    }
};
