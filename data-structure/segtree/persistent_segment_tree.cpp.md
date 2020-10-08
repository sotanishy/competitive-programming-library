---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Persistent Segment Tree
    links: []
  bundledCode: "#line 1 \"data-structure/segtree/persistent_segment_tree.cpp\"\n#include\
    \ <bits/stdc++.h>\n\n/*\n * @brief Persistent Segment Tree\n */\ntemplate <typename\
    \ M>\nclass PersistentSegmentTree {\n    using T = typename M::T;\n\npublic:\n\
    \    PersistentSegmentTree() = default;\n    explicit PersistentSegmentTree(int\
    \ n): PersistentSegmentTree(std::vector<T>(n, M::id)) {}\n    explicit PersistentSegmentTree(const\
    \ std::vector<T>& v) : root(std::make_shared<Node>()) {\n        size = 1;\n \
    \       while (size < (int) v.size()) size <<= 1;\n        build(v, root, 0, size);\n\
    \    }\n\n    T operator[](int k) const {\n        return fold(k, k + 1);\n  \
    \  }\n\n    PersistentSegmentTree update(int k, const T& x) const {\n        return\
    \ PersistentSegmentTree(update(k, x, root, 0, size));\n    }\n\n    T fold(int\
    \ l, int r) const {\n        return fold(l, r, root, 0, size);\n    }\n\nprivate:\n\
    \    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\n    struct Node\
    \ {\n        T val;\n        node_ptr left, right;\n        Node() : val(M::id),\
    \ left(nullptr), right(nullptr) {}\n        Node(const T& val, const node_ptr&\
    \ left, const node_ptr& right) : val(val), left(left), right(right) {}\n    };\n\
    \n    const node_ptr root;\n    int size;\n\n    explicit PersistentSegmentTree(const\
    \ node_ptr& root) : root(root) {}\n\n    void build(const std::vector<T>& v, const\
    \ node_ptr& n, int l, int r) const {\n        if (r - l == 1) {\n            n->val\
    \ = l < (int) v.size() ? v[l] : M::id;\n        }\n        int m = (l + r) / 2;\n\
    \        n->left = std::make_shared<Node>();\n        build(v, n->left, l, m);\n\
    \        n->right = std::make_shared<Node>();\n        build(v, n->right, m, r);\n\
    \        n->val = M::op(n->left->val, n->right->val);\n    }\n\n    node_ptr update(int\
    \ k, const T& x, const node_ptr& n, int l, int r) const {\n        if (r - l ==\
    \ 1) {\n            return std::make_shared<Node>(x, nullptr, nullptr);\n    \
    \    }\n        int m = (l + r) / 2;\n        if (k < m) {\n            node_ptr\
    \ left = update(k, x, n->left, l, m);\n            T val = M::op(left->val, n->right->val);\n\
    \            return std::make_shared<Node>(val, left, n->right);\n        } else\
    \ {\n            node_ptr right = update(k, x, n->right, m, r);\n            T\
    \ val = M::op(n->left->val, right->val);\n            return std::make_shared<Node>(val,\
    \ n->left, right);\n        }\n    }\n\n    T fold(int a, int b, const node_ptr&\
    \ n, int l, int r) const {\n        if (r <= a || b <= l) return M::id;\n    \
    \    if (a <= l && r <= b) return n->val;\n        int m = (l + r) / 2;\n    \
    \    T vl = fold(a, b, n->left, l, m);\n        T vr = fold(a, b, n->right, m,\
    \ r);\n        return M::op(vl, vr);\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Persistent Segment Tree\n */\n\
    template <typename M>\nclass PersistentSegmentTree {\n    using T = typename M::T;\n\
    \npublic:\n    PersistentSegmentTree() = default;\n    explicit PersistentSegmentTree(int\
    \ n): PersistentSegmentTree(std::vector<T>(n, M::id)) {}\n    explicit PersistentSegmentTree(const\
    \ std::vector<T>& v) : root(std::make_shared<Node>()) {\n        size = 1;\n \
    \       while (size < (int) v.size()) size <<= 1;\n        build(v, root, 0, size);\n\
    \    }\n\n    T operator[](int k) const {\n        return fold(k, k + 1);\n  \
    \  }\n\n    PersistentSegmentTree update(int k, const T& x) const {\n        return\
    \ PersistentSegmentTree(update(k, x, root, 0, size));\n    }\n\n    T fold(int\
    \ l, int r) const {\n        return fold(l, r, root, 0, size);\n    }\n\nprivate:\n\
    \    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\n    struct Node\
    \ {\n        T val;\n        node_ptr left, right;\n        Node() : val(M::id),\
    \ left(nullptr), right(nullptr) {}\n        Node(const T& val, const node_ptr&\
    \ left, const node_ptr& right) : val(val), left(left), right(right) {}\n    };\n\
    \n    const node_ptr root;\n    int size;\n\n    explicit PersistentSegmentTree(const\
    \ node_ptr& root) : root(root) {}\n\n    void build(const std::vector<T>& v, const\
    \ node_ptr& n, int l, int r) const {\n        if (r - l == 1) {\n            n->val\
    \ = l < (int) v.size() ? v[l] : M::id;\n        }\n        int m = (l + r) / 2;\n\
    \        n->left = std::make_shared<Node>();\n        build(v, n->left, l, m);\n\
    \        n->right = std::make_shared<Node>();\n        build(v, n->right, m, r);\n\
    \        n->val = M::op(n->left->val, n->right->val);\n    }\n\n    node_ptr update(int\
    \ k, const T& x, const node_ptr& n, int l, int r) const {\n        if (r - l ==\
    \ 1) {\n            return std::make_shared<Node>(x, nullptr, nullptr);\n    \
    \    }\n        int m = (l + r) / 2;\n        if (k < m) {\n            node_ptr\
    \ left = update(k, x, n->left, l, m);\n            T val = M::op(left->val, n->right->val);\n\
    \            return std::make_shared<Node>(val, left, n->right);\n        } else\
    \ {\n            node_ptr right = update(k, x, n->right, m, r);\n            T\
    \ val = M::op(n->left->val, right->val);\n            return std::make_shared<Node>(val,\
    \ n->left, right);\n        }\n    }\n\n    T fold(int a, int b, const node_ptr&\
    \ n, int l, int r) const {\n        if (r <= a || b <= l) return M::id;\n    \
    \    if (a <= l && r <= b) return n->val;\n        int m = (l + r) / 2;\n    \
    \    T vl = fold(a, b, n->left, l, m);\n        T vr = fold(a, b, n->right, m,\
    \ r);\n        return M::op(vl, vr);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree/persistent_segment_tree.cpp
  requiredBy: []
  timestamp: '2020-10-08 11:27:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/segtree/persistent_segment_tree.cpp
layout: document
redirect_from:
- /library/data-structure/segtree/persistent_segment_tree.cpp
- /library/data-structure/segtree/persistent_segment_tree.cpp.html
title: Persistent Segment Tree
---