---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/lazy_segment_tree.cpp
    title: Segment Tree with Lazy Propagation
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "#line 1 \"test/aoj/DSL_2_G.lazy_segment_tree.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\n\n#line\
    \ 1 \"data-structure/lazy_segment_tree.cpp\"\n#include <bits/stdc++.h>\n\n/*\n\
    \ * @brief Segment Tree with Lazy Propagation\n * @docs docs/data-structure/lazy_segment_tree.md\n\
    \ */\ntemplate <typename M, typename O, typename M::T (*act)(typename M::T, typename\
    \ O::T)>\nclass LazySegmentTree {\n    using T = typename M::T;\n    using E =\
    \ typename O::T;\n\npublic:\n    LazySegmentTree() = default;\n    explicit LazySegmentTree(int\
    \ n) : LazySegmentTree(std::vector<T>(n, M::id)) {}\n    explicit LazySegmentTree(const\
    \ std::vector<T>& v) {\n        size = 1;\n        height = 0;\n        while\
    \ (size < (int) v.size()) size <<= 1, ++height;\n        node.resize(2 * size,\
    \ M::id);\n        lazy.resize(2 * size, O::id);\n        std::copy(v.begin(),\
    \ v.end(), node.begin() + size);\n        for (int i = size - 1; i > 0; --i) node[i]\
    \ = M::op(node[2 * i], node[2 * i + 1]);\n    }\n\n    T operator[](int k) {\n\
    \        return fold(k, k + 1);\n    }\n\n    void update(int l, int r, const\
    \ E& x) { update(l, r, x, 1, 0, size); }\n\n    T fold(int l, int r) { return\
    \ fold(l, r, 1, 0, size); }\n\nprivate:\n    int size, height;\n    std::vector<T>\
    \ node;\n    std::vector<E> lazy;\n\n    void push(int k) {\n        if (lazy[k]\
    \ == O::id) return;\n        if (k < size) {\n            lazy[2 * k] = O::op(lazy[2\
    \ * k], lazy[k]);\n            lazy[2 * k + 1] = O::op(lazy[2 * k + 1], lazy[k]);\n\
    \        }\n        node[k] = act(node[k], lazy[k]);\n        lazy[k] = O::id;\n\
    \    }\n\n    void update(int a, int b, const E& x, int k, int l, int r) {\n \
    \       push(k);\n        if (r <= a || b <= l) return;\n        if (a <= l &&\
    \ r <= b) {\n            lazy[k] = O::op(lazy[k], x);\n            push(k);\n\
    \            return;\n        }\n        int m = (l + r) / 2;\n        update(a,\
    \ b, x, 2 * k, l, m);\n        update(a, b, x, 2 * k + 1, m, r);\n        node[k]\
    \ = M::op(node[2 * k], node[2 * k + 1]);\n    }\n\n    T fold(int a, int b, int\
    \ k, int l, int r) {\n        push(k);\n        if (r <= a || b <= l) return M::id;\n\
    \        if (a <= l && r <= b) return node[k];\n        int m = (l + r) / 2;\n\
    \        return M::op(fold(a, b, 2 * k, l, m),\n                     fold(a, b,\
    \ 2 * k + 1, m, r));\n    }\n};\n#line 4 \"test/aoj/DSL_2_G.lazy_segment_tree.test.cpp\"\
    \n\nusing namespace std;\n\nusing ll = long long;\n\nstruct M {\n    using T =\
    \ pair<ll, int>;\n    inline static const T id = {0, 1};\n    static T op(T a,\
    \ T b) {\n        return {a.first + b.first, a.second + b.second};\n    }\n};\n\
    \nstruct O {\n    using T = ll;\n    inline static const T id = 0;\n    static\
    \ T op(T a, T b) {\n        return a + b;\n    }\n};\n\nM::T act(M::T a, O::T\
    \ b) {\n    return {a.first + a.second * b, a.second};\n}\n\nint main() {\n  \
    \  ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int n, q;\n    cin\
    \ >> n >> q;\n    LazySegmentTree<M, O, act> st(n);\n    for (int i = 0; i < q;\
    \ i++) {\n        int type, s, t;\n        cin >> type >> s >> t;\n        if\
    \ (type == 0) {\n            int x;\n            cin >> x;\n            st.update(s\
    \ - 1, t, x);\n        } else {\n            cout << st.fold(s - 1, t).first <<\
    \ \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\n#include \"../../data-structure/lazy_segment_tree.cpp\"\n\nusing namespace\
    \ std;\n\nusing ll = long long;\n\nstruct M {\n    using T = pair<ll, int>;\n\
    \    inline static const T id = {0, 1};\n    static T op(T a, T b) {\n       \
    \ return {a.first + b.first, a.second + b.second};\n    }\n};\n\nstruct O {\n\
    \    using T = ll;\n    inline static const T id = 0;\n    static T op(T a, T\
    \ b) {\n        return a + b;\n    }\n};\n\nM::T act(M::T a, O::T b) {\n    return\
    \ {a.first + a.second * b, a.second};\n}\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n, q;\n    cin >> n >> q;\n    LazySegmentTree<M,\
    \ O, act> st(n);\n    for (int i = 0; i < q; i++) {\n        int type, s, t;\n\
    \        cin >> type >> s >> t;\n        if (type == 0) {\n            int x;\n\
    \            cin >> x;\n            st.update(s - 1, t, x);\n        } else {\n\
    \            cout << st.fold(s - 1, t).first << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/lazy_segment_tree.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_G.lazy_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2020-09-22 15:17:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_G.lazy_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_G.lazy_segment_tree.test.cpp
- /verify/test/aoj/DSL_2_G.lazy_segment_tree.test.cpp.html
title: test/aoj/DSL_2_G.lazy_segment_tree.test.cpp
---