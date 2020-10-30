---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_rectangle_sum.test.cpp
    title: test/yosupo/point_add_rectangle_sum.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/quadtree.md
    document_title: Quadtree
    links: []
  bundledCode: "#line 2 \"data-structure/quadtree.cpp\"\n#include <memory>\n#include\
    \ <vector>\n\n/*\n * @brief Quadtree\n * @docs docs/data-structure/quadtree.md\n\
    \ */\ntemplate <typename M>\nclass Quadtree {\n    using T = typename M::T;\n\n\
    public:\n    Quadtree() = default;\n    Quadtree(int n) : root(std::make_unique<Node>())\
    \ {\n        size = 1;\n        while (size < n) size <<= 1;\n    }\n\n    T get(int\
    \ x, int y) const { return fold(x, x + 1, y, y + 1); }\n\n    void update(int\
    \ x, int y, const T& val) const { update(x, y, val, root, 0, 0, size); }\n\n \
    \   T fold(int l, int r, int b, int t) const { return fold(l, r, b, t, root, 0,\
    \ 0, size); }\n\nprivate:\n    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\
    \n    struct Node {\n        T val;\n        node_ptr ch[4];\n        Node() :\
    \ val(M::id) {}\n    };\n\n    const node_ptr root;\n    int size;\n\n    void\
    \ update(int x, int y, const T& val, const node_ptr& n, int p, int q, int len)\
    \ const {\n        if (len == 1) {\n            n->val = val;\n            return;\n\
    \        }\n        len /= 2;\n        for (int i = 3; i >= 0; --i) {\n      \
    \      if (x >= p + len * (i >> 1) && y >= q + len * (i & 1)) {\n            \
    \    if (!n->ch[i]) n->ch[i] = std::make_unique<Node>();\n                update(x,\
    \ y, val, n->ch[i], p + len * (i >> 1), q + len * (i & 1), len);\n           \
    \     break;\n            }\n        }\n        n->val = M::id;\n        for (int\
    \ i = 0; i < 4; ++i) {\n            if (n->ch[i]) n->val = M::op(n->val, n->ch[i]->val);\n\
    \        }\n    }\n\n    T fold(int l, int r, int b, int t, const node_ptr& n,\
    \ int p, int q, int len) const {\n        if (!n) return M::id;\n        if (p\
    \ + len <= l || r <= p || q + len <= b || t <= q) {\n            return M::id;\n\
    \        }\n        if (l <= p && p + len <= r && b <= q && q + len <= t) {\n\
    \            return n->val;\n        }\n        len /= 2;\n        T val = M::id;\n\
    \        for (int i = 0; i < 4; ++i) {\n            if (n->ch[i]) val = M::op(val,\
    \ fold(l, r, b, t, n->ch[i], p + len * (i >> 1), q + len * (i & 1), len));\n \
    \       }\n        return val;\n    }\n};\n"
  code: "#pragma once\n#include <memory>\n#include <vector>\n\n/*\n * @brief Quadtree\n\
    \ * @docs docs/data-structure/quadtree.md\n */\ntemplate <typename M>\nclass Quadtree\
    \ {\n    using T = typename M::T;\n\npublic:\n    Quadtree() = default;\n    Quadtree(int\
    \ n) : root(std::make_unique<Node>()) {\n        size = 1;\n        while (size\
    \ < n) size <<= 1;\n    }\n\n    T get(int x, int y) const { return fold(x, x\
    \ + 1, y, y + 1); }\n\n    void update(int x, int y, const T& val) const { update(x,\
    \ y, val, root, 0, 0, size); }\n\n    T fold(int l, int r, int b, int t) const\
    \ { return fold(l, r, b, t, root, 0, 0, size); }\n\nprivate:\n    struct Node;\n\
    \    using node_ptr = std::unique_ptr<Node>;\n\n    struct Node {\n        T val;\n\
    \        node_ptr ch[4];\n        Node() : val(M::id) {}\n    };\n\n    const\
    \ node_ptr root;\n    int size;\n\n    void update(int x, int y, const T& val,\
    \ const node_ptr& n, int p, int q, int len) const {\n        if (len == 1) {\n\
    \            n->val = val;\n            return;\n        }\n        len /= 2;\n\
    \        for (int i = 3; i >= 0; --i) {\n            if (x >= p + len * (i >>\
    \ 1) && y >= q + len * (i & 1)) {\n                if (!n->ch[i]) n->ch[i] = std::make_unique<Node>();\n\
    \                update(x, y, val, n->ch[i], p + len * (i >> 1), q + len * (i\
    \ & 1), len);\n                break;\n            }\n        }\n        n->val\
    \ = M::id;\n        for (int i = 0; i < 4; ++i) {\n            if (n->ch[i]) n->val\
    \ = M::op(n->val, n->ch[i]->val);\n        }\n    }\n\n    T fold(int l, int r,\
    \ int b, int t, const node_ptr& n, int p, int q, int len) const {\n        if\
    \ (!n) return M::id;\n        if (p + len <= l || r <= p || q + len <= b || t\
    \ <= q) {\n            return M::id;\n        }\n        if (l <= p && p + len\
    \ <= r && b <= q && q + len <= t) {\n            return n->val;\n        }\n \
    \       len /= 2;\n        T val = M::id;\n        for (int i = 0; i < 4; ++i)\
    \ {\n            if (n->ch[i]) val = M::op(val, fold(l, r, b, t, n->ch[i], p +\
    \ len * (i >> 1), q + len * (i & 1), len));\n        }\n        return val;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/quadtree.cpp
  requiredBy: []
  timestamp: '2020-10-27 21:47:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/point_add_rectangle_sum.test.cpp
documentation_of: data-structure/quadtree.cpp
layout: document
redirect_from:
- /library/data-structure/quadtree.cpp
- /library/data-structure/quadtree.cpp.html
title: Quadtree
---
# Quadtree

四分木は，二次元領域を扱うデータ構造である．

この実装では，モノイドの一点更新と長方形領域取得を扱う．

一点更新は高速だが，長方形領域取得は最悪計算量が悪い．実用上は愚直よりは高速であると思われる．

空間計算量: $O(m\lg n)$, $m$ は点の数

## Template parameters

- `M`
    - 可換モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的かつ可換な二項演算 $\cdot: T \times T \rightarrow T$

## Constructor

- `Quadtree(int n)`
    - $n \times n$ の領域を扱う四分木を構築する．
    - 時間計算量: $O(\lg n)$

## Member functions

- `T get(int x, int y)`
    - 点 $(x, y)$ の値を返す
    - 時間計算量: $O(\lg n)$
- `void update(int x, int y, T val)`
    - 点 $(x, y)$ の値を `val` に更新する
    - 時間計算量: $O(\lg n)$
- `T fold(int l, int r, int b, int t)`
    - 領域 ${(x, y) | x \in [l, r),\ y \in [b, t)}$ 内の点を fold した値を返す
    - 時間計算量: $O(m\lg n)$