---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.range_fenwick_tree.test.cpp
    title: test/aoj/DSL_2_G.range_fenwick_tree.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/range_fenwick_tree.md
    document_title: Fenwick Tree with Range Update
    links: []
  bundledCode: "#line 1 \"data-structure/range_fenwick_tree.cpp\"\n#include <bits/stdc++.h>\n\
    \n/*\n * @brief Fenwick Tree with Range Update\n * @docs docs/data-structure/range_fenwick_tree.md\n\
    \ */\ntemplate <typename T>\nclass RangeFenwickTree {\npublic:\n    RangeFenwickTree()\
    \ = default;\n    explicit RangeFenwickTree(int n) : n(n), data0(n + 1), data1(n\
    \ + 1) {}\n\n    T prefix_sum(int i) const {\n        return prefix_sum(data0,\
    \ i) * (i - 1) + prefix_sum(data1, i);\n    }\n\n    void add(int l, int r, T\
    \ x) {\n        add(data0, l, x);\n        add(data0, r, -x);\n        add(data1,\
    \ l, -x * (l - 1));\n        add(data1, r, x * (r - 1));\n    }\n\nprivate:\n\
    \    int n;\n    std::vector<T> data0, data1;\n\n    T prefix_sum(const std::vector<T>&\
    \ data, int i) const {\n        T ret = 0;\n        for (; i > 0; i -= i & -i)\
    \ ret += data[i];\n        return ret;\n    }\n\n    void add(std::vector<T>&\
    \ data, int i, T x) {\n        for (++i; i <= n; i += i & -i) data[i] += x;\n\
    \    }\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Fenwick Tree with Range Update\n\
    \ * @docs docs/data-structure/range_fenwick_tree.md\n */\ntemplate <typename T>\n\
    class RangeFenwickTree {\npublic:\n    RangeFenwickTree() = default;\n    explicit\
    \ RangeFenwickTree(int n) : n(n), data0(n + 1), data1(n + 1) {}\n\n    T prefix_sum(int\
    \ i) const {\n        return prefix_sum(data0, i) * (i - 1) + prefix_sum(data1,\
    \ i);\n    }\n\n    void add(int l, int r, T x) {\n        add(data0, l, x);\n\
    \        add(data0, r, -x);\n        add(data1, l, -x * (l - 1));\n        add(data1,\
    \ r, x * (r - 1));\n    }\n\nprivate:\n    int n;\n    std::vector<T> data0, data1;\n\
    \n    T prefix_sum(const std::vector<T>& data, int i) const {\n        T ret =\
    \ 0;\n        for (; i > 0; i -= i & -i) ret += data[i];\n        return ret;\n\
    \    }\n\n    void add(std::vector<T>& data, int i, T x) {\n        for (++i;\
    \ i <= n; i += i & -i) data[i] += x;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/range_fenwick_tree.cpp
  requiredBy: []
  timestamp: '2020-10-03 00:05:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_G.range_fenwick_tree.test.cpp
documentation_of: data-structure/range_fenwick_tree.cpp
layout: document
redirect_from:
- /library/data-structure/range_fenwick_tree.cpp
- /library/data-structure/range_fenwick_tree.cpp.html
title: Fenwick Tree with Range Update
---
# Fenwick Tree with Range Update

接頭辞和を扱う Fenwick tree を2つ使うことで，区間加算を実現できる．

空間計算量: $O(n)$

## Template parameters

- `RangeFenwickTree(int n)`
    - サイズ`n`で要素がすべて $0$ の区間更新 Fenwick tree を構築する
    - 時間計算量: $O(n)$

## Member functions

- `T prefix_sum(int i)`
    - $a_0 + a_1 + \dots + a_{i-1}$ を計算する
    - 時間計算量: $O(\lg n)$
- `void add(int l, int r, T x)`
    - $i \in [l, r)$ について $a_i$ を $a_i \cdot x$ に更新する
    - 時間計算量: $O(\lg n)$