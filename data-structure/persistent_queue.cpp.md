---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent_array.cpp
    title: Persistent Array
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_queue.test.cpp
    title: test/yosupo/persistent_queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/persistent_queue.md
    document_title: Persistent Queue
    links: []
  bundledCode: "#line 2 \"data-structure/persistent_queue.cpp\"\n#include <cassert>\n\
    #line 2 \"data-structure/persistent_array.cpp\"\n#include <memory>\n#include <vector>\n\
    \n/*\n * @brief Persistent Array\n * @docs docs/data-structure/persistent_array.md\n\
    \ */\ntemplate <typename T, int B = 2>\nclass PersistentArray {\npublic:\n   \
    \ PersistentArray() = default;\n    explicit PersistentArray(const std::vector<T>&\
    \ v) {\n        for (int i = 0; i < (int) v.size(); ++i) root = set(root, i, v[i]);\n\
    \    }\n\n    T get(int k) const {\n        return get(root, k);\n    }\n\n  \
    \  PersistentArray set(int k, const T& x) const {\n        return PersistentArray(set(root,\
    \ k, x));\n    }\n\nprivate:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    struct Node {\n        T val;\n        node_ptr ch[B];\n    };\n\n    node_ptr\
    \ root = nullptr;\n\n    explicit PersistentArray(const node_ptr& root) : root(root)\
    \ {}\n\n    T get(const node_ptr& t, int k) const {\n        if (k == 0) return\
    \ t->val;\n        return get(t->ch[k % B], k / B);\n    }\n\n    node_ptr set(const\
    \ node_ptr& t, int k, const T& x) const {\n        node_ptr res = t ? std::make_shared<Node>(*t)\
    \ : std::make_shared<Node>();\n        if (k == 0) {\n            res->val = x;\n\
    \        } else {\n            res->ch[k % B] = set(res->ch[k % B], k / B, x);\n\
    \        }\n        return res;\n    }\n};\n#line 4 \"data-structure/persistent_queue.cpp\"\
    \n\n/*\n * @brief Persistent Queue\n * @docs docs/data-structure/persistent_queue.md\n\
    \ */\ntemplate <typename T>\nclass PersistentQueue {\npublic:\n    PersistentQueue()\
    \ : first(0), last(0) {}\n\n    int size() const {\n        return last - first;\n\
    \    }\n\n    bool empty() const {\n        return size() == 0;\n    }\n\n   \
    \ T front() const {\n        assert(!empty());\n        return pa.get(first);\n\
    \    }\n\n    T back() const {\n        assert(!empty());\n        return pa.get(last\
    \ - 1);\n    }\n\n    PersistentQueue push(const T& val) const {\n        return\
    \ PersistentQueue(pa.set(last, val), first, last + 1);\n    }\n\n    PersistentQueue\
    \ pop() const {\n        assert(!empty());\n        return PersistentQueue(pa,\
    \ first + 1, last);\n    }\n\nprivate:\n    PersistentArray<T> pa;\n    int first,\
    \ last;\n\n    PersistentQueue(const PersistentArray<T>& pa, int first, int last)\n\
    \        : pa(pa), first(first), last(last) {}\n};\n"
  code: "#pragma once\n#include <cassert>\n#include \"persistent_array.cpp\"\n\n/*\n\
    \ * @brief Persistent Queue\n * @docs docs/data-structure/persistent_queue.md\n\
    \ */\ntemplate <typename T>\nclass PersistentQueue {\npublic:\n    PersistentQueue()\
    \ : first(0), last(0) {}\n\n    int size() const {\n        return last - first;\n\
    \    }\n\n    bool empty() const {\n        return size() == 0;\n    }\n\n   \
    \ T front() const {\n        assert(!empty());\n        return pa.get(first);\n\
    \    }\n\n    T back() const {\n        assert(!empty());\n        return pa.get(last\
    \ - 1);\n    }\n\n    PersistentQueue push(const T& val) const {\n        return\
    \ PersistentQueue(pa.set(last, val), first, last + 1);\n    }\n\n    PersistentQueue\
    \ pop() const {\n        assert(!empty());\n        return PersistentQueue(pa,\
    \ first + 1, last);\n    }\n\nprivate:\n    PersistentArray<T> pa;\n    int first,\
    \ last;\n\n    PersistentQueue(const PersistentArray<T>& pa, int first, int last)\n\
    \        : pa(pa), first(first), last(last) {}\n};"
  dependsOn:
  - data-structure/persistent_array.cpp
  isVerificationFile: false
  path: data-structure/persistent_queue.cpp
  requiredBy: []
  timestamp: '2020-11-03 02:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_queue.test.cpp
documentation_of: data-structure/persistent_queue.cpp
layout: document
redirect_from:
- /library/data-structure/persistent_queue.cpp
- /library/data-structure/persistent_queue.cpp.html
title: Persistent Queue
---
## Description

永続キューは，過去のバージョンを保持するキューである．この実装では内部で永続配列を用いている．

空間計算量: $O(m \log n)$, $m$ は変更の数

## Operations

- `int size()`
    - キューの要素数を返す
    - 時間計算量: $O(1)$
- `bool empty()`
    - 時間計算量: $O(1)$
- `T front()`
    - 先頭の要素を返す
    - 時間計算量: $O(1)$
- `T back()`
    - 末尾の要素を返す
    - 時間計算量: $O(1)$
- `PersistentQueue push(T val)`
    - `val` をキューの末尾に追加する
    - 時間計算量: $O(\log n)$
- `PersistentQueue pop()`
    - キューの先頭要素を削除する
    - 時間計算量: $O(1)$

## TODO

- ダブリングによる実装
- [これ](https://www.cs.cmu.edu/~rwh/theses/okasaki.pdf) 読む