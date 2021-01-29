---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/lca.cpp
    title: Lowest Common Ancestor
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/yosupo/lca.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n\n#line 2 \"tree/lca.cpp\"\n#include <algorithm>\n#include <vector>\n\nclass\
    \ LCA {\npublic:\n    LCA() = default;\n    LCA(const std::vector<std::vector<int>>&\
    \ G, int root) : G(G), LOG(32 - __builtin_clz(G.size())), depth(G.size()) {\n\
    \        int V = G.size();\n        table.assign(LOG, std::vector<int>(V, -1));\n\
    \n        dfs(root, -1, 0);\n\n        for (int k = 0; k < LOG - 1; ++k) {\n \
    \           for (int v = 0; v < V; ++v) {\n                if (table[k][v] >=\
    \ 0) {\n                    table[k + 1][v] = table[k][table[k][v]];\n       \
    \         }\n            }\n        }\n    }\n\n    int query(int u, int v) const\
    \ {\n        if (depth[u] > depth[v]) std::swap(u, v);\n\n        // go up to\
    \ the same depth\n        for (int k = 0; k < LOG; ++k) {\n            if ((depth[v]\
    \ - depth[u]) >> k & 1) {\n                v = table[k][v];\n            }\n \
    \       }\n        if (u == v) return u;\n\n        for (int k = LOG - 1; k >=\
    \ 0; --k) {\n            if (table[k][u] != table[k][v]) {\n                u\
    \ = table[k][u];\n                v = table[k][v];\n            }\n        }\n\
    \        return table[0][u];\n    }\n\n    int dist(int u, int v) const {\n  \
    \      return depth[u] + depth[v] - 2 * depth[query(u, v)];\n    }\n\nprivate:\n\
    \    const std::vector<std::vector<int>>& G;\n    const int LOG;\n    std::vector<std::vector<int>>\
    \ table;\n    std::vector<int> depth;\n\n    void dfs(int v, int p, int d) {\n\
    \        table[0][v] = p;\n        depth[v] = d;\n        for (int c : G[v]) {\n\
    \            if (c != p) dfs(c, v, d + 1);\n        }\n    }\n};\n#line 4 \"test/yosupo/lca.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    int main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n\
    \    int N, Q;\n    cin >> N >> Q;\n    vector<vector<int>> G(N);\n    for (int\
    \ i = 1; i < N; ++i) {\n        int p;\n        cin >> p;\n        G[p].push_back(i);\n\
    \    }\n    LCA lca(G, 0);\n    for (int i = 0; i < Q; ++i) {\n        int u,\
    \ v;\n        cin >> u >> v;\n        cout << lca.query(u, v) << \"\\n\";\n  \
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../tree/lca.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    int main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n\
    \    int N, Q;\n    cin >> N >> Q;\n    vector<vector<int>> G(N);\n    for (int\
    \ i = 1; i < N; ++i) {\n        int p;\n        cin >> p;\n        G[p].push_back(i);\n\
    \    }\n    LCA lca(G, 0);\n    for (int i = 0; i < Q; ++i) {\n        int u,\
    \ v;\n        cin >> u >> v;\n        cout << lca.query(u, v) << \"\\n\";\n  \
    \  }\n}\n"
  dependsOn:
  - tree/lca.cpp
  isVerificationFile: true
  path: test/yosupo/lca.test.cpp
  requiredBy: []
  timestamp: '2021-01-17 17:56:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/lca.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/lca.test.cpp
- /verify/test/yosupo/lca.test.cpp.html
title: test/yosupo/lca.test.cpp
---