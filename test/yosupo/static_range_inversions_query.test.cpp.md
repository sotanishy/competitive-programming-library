---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick_tree.cpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: misc/compress.cpp
    title: Coordinate Compression
  - icon: ':heavy_check_mark:'
    path: misc/mo.cpp
    title: Mo's Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/yosupo/static_range_inversions_query.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\n\n\
    #line 2 \"data-structure/fenwick_tree.cpp\"\n#include <algorithm>\n#include <functional>\n\
    #include <vector>\n\n/*\n * @brief Fenwick Tree\n * @docs docs/data-structure/fenwick_tree.md\n\
    \ */\ntemplate <typename M>\nclass FenwickTree {\n    using T = typename M::T;\n\
    \npublic:\n    FenwickTree() = default;\n    explicit FenwickTree(int n) : n(n),\
    \ data(n + 1, M::id) {}\n\n    T prefix_fold(int i) const {\n        T ret = M::id;\n\
    \        for (; i > 0; i -= i & -i) ret = M::op(ret, data[i]);\n        return\
    \ ret;\n    }\n\n    void update(int i, const T& x) {\n        for (++i; i <=\
    \ n; i += i & -i) data[i] = M::op(data[i], x);\n    }\n\n    int lower_bound(const\
    \ T& x) const {\n        return lower_bound(x, std::less<>());\n    }\n\n    template\
    \ <typename Compare>\n    int lower_bound(const T& x, Compare cmp) const {\n \
    \       int k = 1;\n        while (k * 2 <= n) k <<= 1;\n        int i = 0;\n\
    \        T v = M::id;\n        for (; k > 0; k >>= 1) {\n            if (i + k\
    \ <= n) continue;\n            T nv = M::op(v, data[i + k]);\n            if (cmp(nv,\
    \ x)) {\n                std::swap(v, nv);\n                i += k;\n        \
    \    }\n        }\n        return i + 1;\n    }\n\nprivate:\n    int n;\n    std::vector<T>\
    \ data;\n};\n#line 4 \"misc/compress.cpp\"\n\n/*\n * @brief Coordinate Compression\n\
    \ */\ntemplate <typename T>\nclass Compress {\npublic:\n    Compress() = default;\n\
    \    explicit Compress(const std::vector<T>& vs) : xs(vs) {\n        std::sort(xs.begin(),\
    \ xs.end());\n        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n\
    \    }\n\n    int compress(const T& x) const {\n        return std::lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n    }\n\n    std::vector<int> compress(const std::vector<T>&\
    \ vs) const {\n        std::vector<int> ret;\n        std::transform(vs.begin(),\
    \ vs.end(), std::back_inserter(ret), [&](const T& x) {\n            return compress(x);\n\
    \        });\n        return ret;\n    }\n\n    T decompress(int i) const {\n\
    \        return xs[i];\n    }\n\nprivate:\n    std::vector<T> xs;\n};\n#line 3\
    \ \"misc/mo.cpp\"\n#include <cmath>\n#line 5 \"misc/mo.cpp\"\n\n/*\n * @brief\
    \ Mo's Algorithm\n */\nclass Mo {\npublic:\n    Mo() = default;\n    explicit\
    \ Mo(int n) : n(n), cnt(0) {}\n\n    void query(int l, int r) {\n        queries.emplace_back(cnt++,\
    \ l, r);\n    }\n\n    template <typename T, typename ExL, typename ShL, typename\
    \ ExR, typename ShR>\n    std::vector<T> run(T init, ExL exl, ShL shl, ExR exr,\
    \ ShR shr) {\n        int s = sqrt(n);\n        std::sort(queries.begin(), queries.end(),\
    \ [&](const auto& a, const auto& b) {\n            if (a.l / s != b.l / s) return\
    \ a.l < b.l;\n            return a.r < b.r;\n        });\n\n        std::vector<T>\
    \ ret(cnt);\n        int curL = 0, curR = 0;\n        T res = init;\n        for\
    \ (auto [id, l, r] : queries) {\n            while (curL > l) res = exl(res, --curL);\n\
    \            while (curL < l) res = shl(res, curL++);\n            while (curR\
    \ < r) res = exr(res, curR++);\n            while (curR > r) res = shr(res, --curR);\n\
    \            ret[id] = res;\n        }\n        return ret;\n    }\n\nprivate:\n\
    \    struct Query {\n        int id, l, r;\n        Query(int id, int l, int r)\
    \ : id(id), l(l), r(r) {}\n    };\n\n    int n, cnt;\n    std::vector<Query> queries;\n\
    };\n#line 6 \"test/yosupo/static_range_inversions_query.test.cpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\nstruct AddMonoid\
    \ {\n    using T = int;\n    static constexpr T id = 0;\n    static T op(T a,\
    \ T b) { return a + b; }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> A(N);\n\
    \    for (int i = 0; i < N; ++i) cin >> A[i];\n    A = Compress<int>(A).compress(A);\n\
    \    Mo mo(N);\n    for (int i = 0; i < Q; ++i) {\n        int l, r;\n       \
    \ cin >> l >> r;\n        mo.query(l, r);\n    }\n\n    FenwickTree<AddMonoid>\
    \ fw(N);\n    auto exl = [&](ll res, int i) {\n        res += fw.prefix_fold(A[i]);\n\
    \        fw.update(A[i], 1);\n        return res;\n    };\n    auto shl = [&](ll\
    \ res, int i) {\n        res -= fw.prefix_fold(A[i]);\n        fw.update(A[i],\
    \ -1);\n        return res;\n    };\n    auto exr = [&](ll res, int i) {\n   \
    \     res += fw.prefix_fold(N) - fw.prefix_fold(A[i] + 1);\n        fw.update(A[i],\
    \ 1);\n        return res;\n    };\n    auto shr = [&](ll res, int i) {\n    \
    \    res -= fw.prefix_fold(N) - fw.prefix_fold(A[i] + 1);\n        fw.update(A[i],\
    \ -1);\n        return res;\n    };\n    auto ans = mo.run(0LL, exl, shl, exr,\
    \ shr);\n    for (auto& x : ans) cout << x << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include \"../../data-structure/fenwick_tree.cpp\"\n#include \"../../misc/compress.cpp\"\
    \n#include \"../../misc/mo.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n\nstruct AddMonoid {\n    using T = int;\n    static\
    \ constexpr T id = 0;\n    static T op(T a, T b) { return a + b; }\n};\n\nint\
    \ main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int N, Q;\n    cin >> N >> Q;\n    vector<int> A(N);\n    for (int i = 0;\
    \ i < N; ++i) cin >> A[i];\n    A = Compress<int>(A).compress(A);\n    Mo mo(N);\n\
    \    for (int i = 0; i < Q; ++i) {\n        int l, r;\n        cin >> l >> r;\n\
    \        mo.query(l, r);\n    }\n\n    FenwickTree<AddMonoid> fw(N);\n    auto\
    \ exl = [&](ll res, int i) {\n        res += fw.prefix_fold(A[i]);\n        fw.update(A[i],\
    \ 1);\n        return res;\n    };\n    auto shl = [&](ll res, int i) {\n    \
    \    res -= fw.prefix_fold(A[i]);\n        fw.update(A[i], -1);\n        return\
    \ res;\n    };\n    auto exr = [&](ll res, int i) {\n        res += fw.prefix_fold(N)\
    \ - fw.prefix_fold(A[i] + 1);\n        fw.update(A[i], 1);\n        return res;\n\
    \    };\n    auto shr = [&](ll res, int i) {\n        res -= fw.prefix_fold(N)\
    \ - fw.prefix_fold(A[i] + 1);\n        fw.update(A[i], -1);\n        return res;\n\
    \    };\n    auto ans = mo.run(0LL, exl, shl, exr, shr);\n    for (auto& x : ans)\
    \ cout << x << \"\\n\";\n}"
  dependsOn:
  - data-structure/fenwick_tree.cpp
  - misc/compress.cpp
  - misc/mo.cpp
  isVerificationFile: true
  path: test/yosupo/static_range_inversions_query.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 14:13:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_range_inversions_query.test.cpp
- /verify/test/yosupo/static_range_inversions_query.test.cpp.html
title: test/yosupo/static_range_inversions_query.test.cpp
---