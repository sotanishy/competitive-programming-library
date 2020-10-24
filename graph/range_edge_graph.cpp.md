---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.cpp
    title: Dijkstra's Algorithm
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/graph/range_edge_graph.md
    document_title: Range Edge Graph
    links: []
  bundledCode: "#line 1 \"graph/range_edge_graph.cpp\"\n#include <bits/stdc++.h>\n\
    #line 3 \"graph/edge.cpp\"\n\ntemplate <typename T>\nstruct Edge {\n    int from,\
    \ to;\n    T weight;\n    Edge(int to, T weight) : from(-1), to(to), weight(weight)\
    \ {}\n    Edge(int from, int to, T weight) : from(from), to(to), weight(weight)\
    \ {}\n};\n#line 3 \"graph/dijkstra.cpp\"\n\n/*\n * @brief Dijkstra's Algorithm\n\
    \ * @docs docs/graph/dijkstra.md\n */\ntemplate <typename T>\nstd::vector<T> dijkstra(const\
    \ std::vector<std::vector<Edge<T>>>& G, int s) {\n    std::vector<T> dist(G.size(),\
    \ std::numeric_limits<T>::max());\n    dist[s] = 0;\n    using P = std::pair<T,\
    \ int>;\n    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;\n   \
    \ pq.emplace(0, s);\n\n    while (!pq.empty()) {\n        T weight;\n        int\
    \ v;\n        std::tie(weight, v) = pq.top();\n        pq.pop();\n        if (dist[v]\
    \ < weight) continue;\n        for (auto& e : G[v]) {\n            if (dist[e.to]\
    \ > dist[v] + e.weight) {\n                dist[e.to] = dist[v] + e.weight;\n\
    \                pq.emplace(dist[e.to], e.to);\n            }\n        }\n   \
    \ }\n\n    return dist;\n}\n#line 4 \"graph/range_edge_graph.cpp\"\n\n/*\n * @brief\
    \ Range Edge Graph\n * @docs docs/graph/range_edge_graph.md\n */\ntemplate <typename\
    \ T>\nclass RangeEdgeGraph {\npublic:\n    RangeEdgeGraph() = default;\n    explicit\
    \ RangeEdgeGraph(int n) {\n        size = 1;\n        while (size < n) size <<=\
    \ 1;\n        G.resize(4 * size);\n        for (int i = 1; i < size; ++i) {\n\
    \            int l = 2 * i, r = 2 * i + 1;\n            G[i].emplace_back(l, 0);\n\
    \            G[i].emplace_back(r, 0);\n            G[l + 2 * size].emplace_back(i\
    \ + 2 * size, 0);\n            G[r + 2 * size].emplace_back(i + 2 * size, 0);\n\
    \        }\n        for (int i = size; i < 2 * size; ++i) G[i].emplace_back(i\
    \ + 2 * size, 0);\n    }\n\n    void add_edge(int l1, int r1, int l2, int r2,\
    \ T w) {\n        int idx = G.size();\n        for (l1 += size, r1 += size; l1\
    \ < r1; l1 >>= 1, r1 >>= 1) {\n            if (l1 & 1) G[l1 + 2 * size].emplace_back(idx,\
    \ 0), ++l1;\n            if (r1 & 1) --r1, G[r1 + 2 * size].emplace_back(idx,\
    \ 0);\n        }\n        std::vector<Edge<T>> node;\n        for (l2 += size,\
    \ r2 += size; l2 < r2; l2 >>= 1, r2 >>= 1) {\n            if (l2 & 1) node.emplace_back(l2++,\
    \ w);\n            if (r2 & 1) node.emplace_back(--r2, w);\n        }\n      \
    \  G.push_back(node);\n    }\n\n    std::vector<T> dist(int s) const {\n     \
    \   std::vector<T> dist = dijkstra(G, s + size);\n        return std::vector<T>(dist.begin()\
    \ + size, dist.begin() + 2 * size);\n    }\n\nprivate:\n    int size;\n    std::vector<std::vector<Edge<T>>>\
    \ G;\n};\n\n\n/*\nImplementation with a sparse table\n\ntemplate <typename T>\n\
    class RangeEdgeGraph {\npublic:\n    RangeEdgeGraph() = default;\n    explicit\
    \ RangeEdgeGraph(int n) : n(n) {\n        b = 0;\n        while ((1 << b) <= n)\
    \ ++b;\n        G.resize(2 * n * b);\n        for (int i = 1; i < b; ++i) {\n\
    \            for (int j = 0; j + (1 << i) <= n; ++j) {\n                int k\
    \ = n * i + j;\n                int l = n * (i - 1) + j;\n                int\
    \ r = l + (1 << (i - 1));\n                G[k].emplace_back(l, 0);\n        \
    \        G[k].emplace_back(r, 0);\n                G[n * b + l].emplace_back(n\
    \ * b + k, 0);\n                G[n * b + r].emplace_back(n * b + k, 0);\n   \
    \         }\n        }\n        for (int j = 0; j < n; ++j) G[j].emplace_back(n\
    \ * b + j, 0);\n    }\n\n    void add_edge(int l1, int r1, int l2, int r2, T w)\
    \ {\n        int idx = G.size();\n        std::vector<Edge<T>> node;\n       \
    \ int i = 31 - __builtin_clz(r1 - l1);\n        G[n * b + n * i + l1].emplace_back(idx,\
    \ 0);\n        G[n * b + n * i + r1 - (1 << i)].emplace_back(idx, 0);\n\n    \
    \    i = 31 - __builtin_clz(r2 - l2);\n        node.emplace_back(n * i + l2, w);\n\
    \        node.emplace_back(n * i + r2 - (1 << i), w);\n        G.push_back(node);\n\
    \    }\n\n    std::vector<T> dist(int s) const {\n        std::vector<T> dist\
    \ = dijkstra(G, s);\n        return std::vector<T>(dist.begin(), dist.begin()\
    \ + n);\n    }\n\nprivate:\n    int n, b;\n    std::vector<std::vector<Edge<T>>>\
    \ G;\n};\n\n*/\n"
  code: "#include <bits/stdc++.h>\n#include \"edge.cpp\"\n#include \"dijkstra.cpp\"\
    \n\n/*\n * @brief Range Edge Graph\n * @docs docs/graph/range_edge_graph.md\n\
    \ */\ntemplate <typename T>\nclass RangeEdgeGraph {\npublic:\n    RangeEdgeGraph()\
    \ = default;\n    explicit RangeEdgeGraph(int n) {\n        size = 1;\n      \
    \  while (size < n) size <<= 1;\n        G.resize(4 * size);\n        for (int\
    \ i = 1; i < size; ++i) {\n            int l = 2 * i, r = 2 * i + 1;\n       \
    \     G[i].emplace_back(l, 0);\n            G[i].emplace_back(r, 0);\n       \
    \     G[l + 2 * size].emplace_back(i + 2 * size, 0);\n            G[r + 2 * size].emplace_back(i\
    \ + 2 * size, 0);\n        }\n        for (int i = size; i < 2 * size; ++i) G[i].emplace_back(i\
    \ + 2 * size, 0);\n    }\n\n    void add_edge(int l1, int r1, int l2, int r2,\
    \ T w) {\n        int idx = G.size();\n        for (l1 += size, r1 += size; l1\
    \ < r1; l1 >>= 1, r1 >>= 1) {\n            if (l1 & 1) G[l1 + 2 * size].emplace_back(idx,\
    \ 0), ++l1;\n            if (r1 & 1) --r1, G[r1 + 2 * size].emplace_back(idx,\
    \ 0);\n        }\n        std::vector<Edge<T>> node;\n        for (l2 += size,\
    \ r2 += size; l2 < r2; l2 >>= 1, r2 >>= 1) {\n            if (l2 & 1) node.emplace_back(l2++,\
    \ w);\n            if (r2 & 1) node.emplace_back(--r2, w);\n        }\n      \
    \  G.push_back(node);\n    }\n\n    std::vector<T> dist(int s) const {\n     \
    \   std::vector<T> dist = dijkstra(G, s + size);\n        return std::vector<T>(dist.begin()\
    \ + size, dist.begin() + 2 * size);\n    }\n\nprivate:\n    int size;\n    std::vector<std::vector<Edge<T>>>\
    \ G;\n};\n\n\n/*\nImplementation with a sparse table\n\ntemplate <typename T>\n\
    class RangeEdgeGraph {\npublic:\n    RangeEdgeGraph() = default;\n    explicit\
    \ RangeEdgeGraph(int n) : n(n) {\n        b = 0;\n        while ((1 << b) <= n)\
    \ ++b;\n        G.resize(2 * n * b);\n        for (int i = 1; i < b; ++i) {\n\
    \            for (int j = 0; j + (1 << i) <= n; ++j) {\n                int k\
    \ = n * i + j;\n                int l = n * (i - 1) + j;\n                int\
    \ r = l + (1 << (i - 1));\n                G[k].emplace_back(l, 0);\n        \
    \        G[k].emplace_back(r, 0);\n                G[n * b + l].emplace_back(n\
    \ * b + k, 0);\n                G[n * b + r].emplace_back(n * b + k, 0);\n   \
    \         }\n        }\n        for (int j = 0; j < n; ++j) G[j].emplace_back(n\
    \ * b + j, 0);\n    }\n\n    void add_edge(int l1, int r1, int l2, int r2, T w)\
    \ {\n        int idx = G.size();\n        std::vector<Edge<T>> node;\n       \
    \ int i = 31 - __builtin_clz(r1 - l1);\n        G[n * b + n * i + l1].emplace_back(idx,\
    \ 0);\n        G[n * b + n * i + r1 - (1 << i)].emplace_back(idx, 0);\n\n    \
    \    i = 31 - __builtin_clz(r2 - l2);\n        node.emplace_back(n * i + l2, w);\n\
    \        node.emplace_back(n * i + r2 - (1 << i), w);\n        G.push_back(node);\n\
    \    }\n\n    std::vector<T> dist(int s) const {\n        std::vector<T> dist\
    \ = dijkstra(G, s);\n        return std::vector<T>(dist.begin(), dist.begin()\
    \ + n);\n    }\n\nprivate:\n    int n, b;\n    std::vector<std::vector<Edge<T>>>\
    \ G;\n};\n\n*/\n"
  dependsOn:
  - graph/edge.cpp
  - graph/dijkstra.cpp
  isVerificationFile: false
  path: graph/range_edge_graph.cpp
  requiredBy: []
  timestamp: '2020-10-06 11:51:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/range_edge_graph.cpp
layout: document
redirect_from:
- /library/graph/range_edge_graph.cpp
- /library/graph/range_edge_graph.cpp.html
title: Range Edge Graph
---
# Range Edge Graph

セグメント木と同様の構造を用いることで，効率的に区間に辺を張ることができる．

空間計算量: $O(n + m\lg n)$, $m$ は張った辺の数

## Template parameter

- `T`
    - 重みの型

## Constructor

- `RangeEdgeGraph(int n)`
    - グラフを $n$ 頂点で初期化する
    - 時間計算量: $O(n)$

## Member functions

- `void add_edge(int l1, int r1, int l2, int r2, T w)`
    - 区間 $[l_1, r_1)$ から区間 $[l_2, r_2)$ に重み $w$ の辺を張る
    - 時間計算量: $O(\lg n)$
- `vector<T> dist(int s)`
    - 始点 $s$ から各頂点への最短距離を Dijkstra 法で求める
    - 時間計算量: $O((n + m\lg n) \lg (n + m))$

## Note

セグメント木ではなく sparse table の構造を用いて区間に辺を張ることもできる．この場合空間計算量は $O(n\lg n + m)$，時間計算量は構築 $O(n\lg n)$，辺の追加 $O(1)$，Dijkstra 法 $O((n\lg n + m) \lg (n\lg n + m)))$ となる．特に辺が多いときに高速であるという利点があるが，空間計算量が大きくなるので注意が必要である．

## Reference

- [区間に辺を貼る一般的なテクニック](https://www.slideshare.net/secret/r8gjH9xYxFR0Fu)
- [区間に辺を張るテクの実装例（Dijkstra法セット）と使用例](https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656)