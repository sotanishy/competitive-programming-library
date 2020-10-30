---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_7_A.test.cpp
    title: test/aoj/GRL_7_A.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/bipartite_matching.md
    document_title: Bipartite Matching
    links: []
  bundledCode: "#line 2 \"flow/bipartite_matching.cpp\"\n#include <algorithm>\n#include\
    \ <vector>\n\n/*\n * @brief Bipartite Matching\n * @docs docs/flow/bipartite_matching.md\n\
    \ */\nclass BipartiteMatching {\npublic:\n    BipartiteMatching() = default;\n\
    \    explicit BipartiteMatching(int n) : G(n), used(n), match(n) {}\n\n    void\
    \ add_edge(int u, int v) {\n        G[u].push_back(v);\n        G[v].push_back(u);\n\
    \    }\n\n    int bipartite_matching() {\n        int res = 0;\n        std::fill(match.begin(),\
    \ match.end(), -1);\n        for (int v = 0; v < (int) G.size(); ++v) {\n    \
    \        if (match[v] == -1) {\n                std::fill(used.begin(), used.end(),\
    \ false);\n                if (dfs(v)) ++res;\n            }\n        }\n    \
    \    return res;\n    }\n\n    std::vector<std::pair<int, int>> get_edges() {\n\
    \        std::vector<std::pair<int, int>> ret;\n        for (int i = 0; i < (int)\
    \ G.size(); ++i) {\n            if (i < match[i]) ret.emplace_back(i, match[i]);\n\
    \        }\n        return ret;\n    }\n\nprivate:\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<bool> used;\n    std::vector<int> match;\n\n    bool dfs(int\
    \ u) {\n        used[u] = true;\n        for (int v : G[u]) {\n            int\
    \ w = match[v];\n            if (w == -1 || (!used[w] && dfs(w))) {\n        \
    \        match[u] = v;\n                match[v] = u;\n                return\
    \ true;\n            }\n        }\n        return false;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\n/*\n * @brief Bipartite\
    \ Matching\n * @docs docs/flow/bipartite_matching.md\n */\nclass BipartiteMatching\
    \ {\npublic:\n    BipartiteMatching() = default;\n    explicit BipartiteMatching(int\
    \ n) : G(n), used(n), match(n) {}\n\n    void add_edge(int u, int v) {\n     \
    \   G[u].push_back(v);\n        G[v].push_back(u);\n    }\n\n    int bipartite_matching()\
    \ {\n        int res = 0;\n        std::fill(match.begin(), match.end(), -1);\n\
    \        for (int v = 0; v < (int) G.size(); ++v) {\n            if (match[v]\
    \ == -1) {\n                std::fill(used.begin(), used.end(), false);\n    \
    \            if (dfs(v)) ++res;\n            }\n        }\n        return res;\n\
    \    }\n\n    std::vector<std::pair<int, int>> get_edges() {\n        std::vector<std::pair<int,\
    \ int>> ret;\n        for (int i = 0; i < (int) G.size(); ++i) {\n           \
    \ if (i < match[i]) ret.emplace_back(i, match[i]);\n        }\n        return\
    \ ret;\n    }\n\nprivate:\n    std::vector<std::vector<int>> G;\n    std::vector<bool>\
    \ used;\n    std::vector<int> match;\n\n    bool dfs(int u) {\n        used[u]\
    \ = true;\n        for (int v : G[u]) {\n            int w = match[v];\n     \
    \       if (w == -1 || (!used[w] && dfs(w))) {\n                match[u] = v;\n\
    \                match[v] = u;\n                return true;\n            }\n\
    \        }\n        return false;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: flow/bipartite_matching.cpp
  requiredBy: []
  timestamp: '2020-10-24 20:53:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_7_A.test.cpp
documentation_of: flow/bipartite_matching.cpp
layout: document
redirect_from:
- /library/flow/bipartite_matching.cpp
- /library/flow/bipartite_matching.cpp.html
title: Bipartite Matching
---
# Bipartite Matching

Ford-Fulkerson のアルゴリズムを用いて二部グラフの最大マッチングを計算する．

## Constructor

- `BipartiteMatching(int n)`‘
    - 二部グラフを $n$ 頂点で初期化する
    - 時間計算量: $O(n)$

## Member functions

- `void add_edge(int u, int v)`
    - 辺 $(u, v)$ を追加する
    - 時間計算量: $O(1)$
- `int bipartite_matching()`
    - 二部グラフの最大マッチングを計算する
    - 時間計算量: $O(VE)$