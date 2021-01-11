---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/segment_tree.cpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: tree/hld.cpp
    title: Heavy-Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/yosupo/vertex_add_path_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#line 2 \"data-structure/segtree/segment_tree.cpp\"\
    \n#include <algorithm>\n#include <vector>\n\n/*\n * @brief Segment Tree\n * @docs\
    \ docs/data-structure/segtree/segment_tree.md\n */\ntemplate <typename M>\nclass\
    \ SegmentTree {\n    using T = typename M::T;\n\npublic:\n    SegmentTree() =\
    \ default;\n    explicit SegmentTree(int n): SegmentTree(std::vector<T>(n, M::id))\
    \ {}\n    explicit SegmentTree(const std::vector<T>& v) {\n        size = 1;\n\
    \        while (size < (int) v.size()) size <<= 1;\n        node.resize(2 * size,\
    \ M::id);\n        std::copy(v.begin(), v.end(), node.begin() + size);\n     \
    \   for (int i = size - 1; i > 0; --i) node[i] = M::op(node[2 * i], node[2 * i\
    \ + 1]);\n    }\n\n    T operator[](int k) const {\n        return node[k + size];\n\
    \    }\n\n    void update(int k, const T& x) {\n        k += size;\n        node[k]\
    \ = x;\n        while (k >>= 1) node[k] = M::op(node[2 * k], node[2 * k + 1]);\n\
    \    }\n\n    T fold(int l, int r) const {\n        T vl = M::id, vr = M::id;\n\
    \        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n            if\
    \ (l & 1) vl = M::op(vl, node[l++]);\n            if (r & 1) vr = M::op(node[--r],\
    \ vr);\n        }\n        return M::op(vl, vr);\n    }\n\n    template <typename\
    \ F>\n    int find_first(int l, F cond) const {\n        T vl = M::id;\n     \
    \   int r = size;\n        for (l += size, r += size; l < r; l >>= 1, r >>= 1)\
    \ {\n            if (l & 1) {\n                T nxt = M::op(vl, node[l]);\n \
    \               if (cond(nxt)) {\n                    while (l < size) {\n   \
    \                     nxt = M::op(vl, node[2 * l]);\n                        if\
    \ (cond(nxt)) l = 2 * l;\n                        else vl = nxt, l = 2 * l + 1;\n\
    \                    }\n                    return l - size;\n               \
    \ }\n                vl = nxt;\n                ++l;\n            }\n        }\n\
    \        return -1;\n    }\n\n    template <typename F>\n    int find_last(int\
    \ r, F cond) const {\n        T vr = M::id;\n        int l = 0;\n        for (l\
    \ += size, r += size; l < r; l >>= 1, r >>= 1) {\n            if (r & 1) {\n \
    \               --r;\n                T nxt = M::op(node[r], vr);\n          \
    \      if (cond(nxt)) {\n                    while (r < size) {\n            \
    \            nxt = M::op(node[2 * r + 1], vr);\n                        if (cond(nxt))\
    \ r = 2 * r + 1;\n                        else vr = nxt, r = 2 * r;\n        \
    \            }\n                    return r - size;\n                }\n    \
    \            vr = nxt;\n            }\n        }\n        return -1;\n    }\n\n\
    private:\n    int size;\n    std::vector<T> node;\n};\n#line 4 \"tree/hld.cpp\"\
    \n\n/*\n * @brief Heavy-Light Decomposition\n * @docs docs/tree/hld.md\n */\n\
    template <typename M>\nclass HLD {\n    using T = typename M::T;\n\npublic:\n\
    \    HLD() = default;\n    HLD(const std::vector<std::vector<int>>& G, bool edge)\n\
    \        : G(G), size(G.size()), depth(G.size()), par(G.size(), -1),\n       \
    \   in(G.size()), out(G.size()), head(G.size()), heavy(G.size(), -1), edge(edge)\
    \ {\n        dfs(0);\n        decompose(0, 0);\n    }\n\n    template <typename\
    \ F>\n    void update(int v, const T& x, const F& f) const {\n        f(in[v],\
    \ x);\n    }\n\n    template <typename E, typename F>\n    void update(int u,\
    \ int v, const E& x, const F& f) const {\n        while (head[u] != head[v]) {\n\
    \            if (in[head[u]] > in[head[v]]) std::swap(u, v);\n            f(in[head[v]],\
    \ in[v] + 1, x);\n            v = par[head[v]];\n        }\n        if (in[u]\
    \ > in[v]) std::swap(u, v);\n        f(in[u] + edge, in[v] + 1, x);\n    }\n\n\
    \    template <typename F>\n    T path_fold(int u, int v, const F& f) const {\n\
    \        T res = M::id;\n        while (head[u] != head[v]) {\n            if\
    \ (in[head[u]] > in[head[v]]) std::swap(u, v);\n            T val = f(in[head[v]],\
    \ in[v] + 1);\n            res = M::op(val, res);\n            v = par[head[v]];\n\
    \        }\n        if (in[u] > in[v]) std::swap(u, v);\n        T val = f(in[u]\
    \ + edge, in[v] + 1);\n        return M::op(val, res);\n    }\n\n    template\
    \ <typename F>\n    T subtree_fold(int v, const F& f) const {\n        return\
    \ f(in[v] + edge, out[v]);\n    }\n\n    int lca(int u, int v) const {\n     \
    \   while (true) {\n            if (in[u] > in[v]) std::swap(u, v);\n        \
    \    if (head[u] == head[v]) return u;\n            v = par[head[v]];\n      \
    \  }\n    }\n\n    int dist(int u, int v) const {\n        return depth[u] + depth[v]\
    \ - 2 * depth[lca(u, v)];\n    }\n\nprivate:\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<int> size, depth, par, in, out, head, heavy;\n    bool edge;\n\
    \    int cur_pos = 0;\n\n    void dfs(int v) {\n        size[v] = 1;\n       \
    \ int max_size = 0;\n        for (int c : G[v]) {\n            if (c == par[v])\
    \ continue;\n            par[c] = v;\n            depth[c] = depth[v] + 1;\n \
    \           dfs(c);\n            size[v] += size[c];\n            if (size[c]\
    \ > max_size) {\n                max_size = size[c];\n                heavy[v]\
    \ = c;\n            }\n        }\n    }\n\n    void decompose(int v, int h) {\n\
    \        head[v] = h;\n        in[v] = cur_pos++;\n        if (heavy[v] != -1)\
    \ decompose(heavy[v], h);\n        for (int c : G[v]) {\n            if (c !=\
    \ par[v] && c != heavy[v]) decompose(c, c);\n        }\n        out[v] = cur_pos;\n\
    \    }\n};\n#line 5 \"test/yosupo/vertex_add_path_sum.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\nstruct AddMonoid {\n    using T\
    \ = ll;\n    static constexpr T id = 0;\n    static T op(T a, T b) {\n       \
    \ return a + b;\n    }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<ll> a(N);\n\
    \    for (int i = 0; i < N; ++i) cin >> a[i];\n    vector<vector<int>> G(N);\n\
    \    for (int i = 0; i < N - 1; ++i) {\n        int u, v;\n        cin >> u >>\
    \ v;\n        G[u].push_back(v);\n        G[v].push_back(u);\n    }\n    HLD<AddMonoid>\
    \ hld(G, false);\n    SegmentTree<AddMonoid> st(N);\n    auto update = [&](int\
    \ k, ll x) {\n        st.update(k, st[k] + x);\n    };\n    auto fold = [&](int\
    \ l, int r) {\n        return st.fold(l, r);\n    };\n    for (int i = 0; i <\
    \ N; ++i) hld.update(i, a[i], update);\n    for (int i = 0; i < Q; ++i) {\n  \
    \      int t;\n        cin >> t;\n        if (t == 0) {\n            int p, x;\n\
    \            cin >> p >> x;\n            hld.update(p, x, update);\n        }\
    \ else {\n            int u, v;\n            cin >> u >> v;\n            cout\
    \ << hld.path_fold(u, v, fold) << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../../data-structure/segtree/segment_tree.cpp\"\n#include \"../../tree/hld.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    struct AddMonoid {\n    using T = ll;\n    static constexpr T id = 0;\n    static\
    \ T op(T a, T b) {\n        return a + b;\n    }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<ll> a(N);\n\
    \    for (int i = 0; i < N; ++i) cin >> a[i];\n    vector<vector<int>> G(N);\n\
    \    for (int i = 0; i < N - 1; ++i) {\n        int u, v;\n        cin >> u >>\
    \ v;\n        G[u].push_back(v);\n        G[v].push_back(u);\n    }\n    HLD<AddMonoid>\
    \ hld(G, false);\n    SegmentTree<AddMonoid> st(N);\n    auto update = [&](int\
    \ k, ll x) {\n        st.update(k, st[k] + x);\n    };\n    auto fold = [&](int\
    \ l, int r) {\n        return st.fold(l, r);\n    };\n    for (int i = 0; i <\
    \ N; ++i) hld.update(i, a[i], update);\n    for (int i = 0; i < Q; ++i) {\n  \
    \      int t;\n        cin >> t;\n        if (t == 0) {\n            int p, x;\n\
    \            cin >> p >> x;\n            hld.update(p, x, update);\n        }\
    \ else {\n            int u, v;\n            cin >> u >> v;\n            cout\
    \ << hld.path_fold(u, v, fold) << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/segtree/segment_tree.cpp
  - tree/hld.cpp
  isVerificationFile: true
  path: test/yosupo/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2020-11-09 16:11:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_add_path_sum.test.cpp
- /verify/test/yosupo/vertex_add_path_sum.test.cpp.html
title: test/yosupo/vertex_add_path_sum.test.cpp
---