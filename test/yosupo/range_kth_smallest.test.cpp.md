---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/bit_vector.cpp
    title: Rank/Select Dictionary
  - icon: ':heavy_check_mark:'
    path: data-structure/wavelet_matrix.cpp
    title: Wavelet Matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"test/yosupo/range_kth_smallest.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#line 2 \"data-structure/wavelet_matrix.cpp\"\
    \n#include <algorithm>\n#include <unordered_map>\n#include <vector>\n#line 2 \"\
    data-structure/bit_vector.cpp\"\n#include <cstdint>\n#line 4 \"data-structure/bit_vector.cpp\"\
    \n\n/*\n * @brief Rank/Select Dictionary\n * @docs docs/data-structure/bit_vector.md\n\
    \ */\nclass BitVector {\npublic:\n    BitVector() = default;\n    explicit BitVector(const\
    \ std::vector<bool>& v) {\n        int n = (v.size() + sz - 1) / sz;\n       \
    \ data.resize(n);\n        sum.resize(n + 1);\n        for (int i = 0; i < (int)\
    \ v.size(); ++i) data[i / sz] |= v[i] << (i % sz);\n        for (int i = 0; i\
    \ < n; ++i) sum[i + 1] = sum[i] + __builtin_popcount(data[i]);\n    }\n\n    bool\
    \ access(int k) const {\n        return data[k / sz] >> (k % sz) & 1;\n    }\n\
    \n    int rank(int k, bool b) const {\n        int mask = (1 << (k % sz)) - 1;\n\
    \        int r = sum[k / sz] + __builtin_popcount(data[k / sz] & mask);\n    \
    \    return b ? r : k - r;\n    }\n\n    int select(int k, bool b) const {\n \
    \       int lb = 0, ub = data.size();\n        while (ub - lb > 1) {\n       \
    \     int m = (lb + ub) / 2;\n            if (rank(m, b) <= k) lb = m;\n     \
    \       else ub = m;\n        }\n        return lb;\n    }\n\nprivate:\n    static\
    \ constexpr int sz = 32;\n\n    std::vector<uint32_t> data;\n    std::vector<int>\
    \ sum;\n};\n#line 6 \"data-structure/wavelet_matrix.cpp\"\n\n/*\n * @brief Wavelet\
    \ Matrix\n * @docs docs/data-structure/wavelet_matrix.md\n */\ntemplate <typename\
    \ T>\nclass WaveletMatrix {\npublic:\n    WaveletMatrix() = default;\n    explicit\
    \ WaveletMatrix(std::vector<T> v) {\n        int n = v.size() ;\n        T m =\
    \ *std::max_element(v.begin(), v.end());\n        int d = 0;\n        while ((1\
    \ << d) <= m) ++d;\n        mat.resize(d);\n        cnt0.resize(d);\n        for\
    \ (d -= 1; d >= 0; --d) {\n            std::vector<bool> bit(n);\n           \
    \ for (int i = 0; i < n; ++i) bit[i] = v[i] >> d & 1;\n            mat[d] = BitVector(bit);\n\
    \            std::vector<int> cnt(2);\n            for (int i = 0; i < n; ++i)\
    \ if (!bit[i]) cnt[0]++;\n            cnt0[d] = cnt[0];\n            cnt[1] =\
    \ n;\n            std::vector<T> nv(n);\n            for (int i = n - 1; i >=\
    \ 0; --i) nv[--cnt[bit[i]]] = v[i];\n            v.swap(nv);\n        }\n    \
    \    for (int i = 0; i < n; ++i) if (!start.count(v[i])) start[v[i]] = i;\n  \
    \  }\n\n    T access(int k) const {\n        T ret = 0;\n        for (int d =\
    \ mat.size() - 1; d >= 0; --d) {\n            bool b = mat[d].access(k);\n   \
    \         ret |= T(b) << d;\n            k = cnt0[d] * b + mat[d].rank(k, b);\n\
    \        }\n        return ret;\n    }\n\n    int rank(int k, T x) const {\n \
    \       for (int d = mat.size() - 1; d >= 0; --d) {\n            bool b = x >>\
    \ d & 1;\n            k = cnt0[d] * b + mat[d].rank(k, b);\n        }\n      \
    \  return k - start.at(x);\n    }\n\n    int rank_less(int k, T x) const {\n \
    \       int ret = 0;\n        int l = 0;\n        for (int d = mat.size() - 1;\
    \ d >= 0; --d) {\n            bool b = x >> d & 1;\n            if (b) ret +=\
    \ mat[d].rank(k, 0) - mat[d].rank(l, 0);\n            l = cnt0[d] * b + mat[d].rank(l,\
    \ b);\n            k = cnt0[d] * b + mat[d].rank(k, b);\n        }\n        return\
    \ ret;\n    }\n\n    int select(int k, T x) const {\n        k += start.at(x);\n\
    \        for (int d = 0; d < (int) mat.size(); ++d) {\n            bool b = x\
    \ >> d & 1;\n            k = mat[d].select(k - cnt0[d] * b, b);\n        }\n \
    \       return k;\n    }\n\n    T quantile(int l, int r, int k) const {\n    \
    \    T ret = 0;\n        for (int d = (int) mat.size() - 1; d >= 0; --d) {\n \
    \           int cnt = mat[d].rank(r, 0) - mat[d].rank(l, 0);\n            bool\
    \ b = k < cnt ? 0 : 1;\n            l = cnt0[d] * b + mat[d].rank(l, b);\n   \
    \         r = cnt0[d] * b + mat[d].rank(r, b);\n            if (b) {\n       \
    \         ret |= T(1) << d;\n                k -= cnt;\n            }\n      \
    \  }\n        return ret;\n    }\n\nprivate:\n    std::vector<BitVector> mat;\n\
    \    std::vector<int> cnt0;\n    std::unordered_map<T, int> start;\n};\n#line\
    \ 4 \"test/yosupo/range_kth_smallest.test.cpp\"\n\n#include <bits/stdc++.h>\n\n\
    using namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> a(N);\n\
    \    for (int i = 0; i < N; ++i) cin >> a[i];\n    WaveletMatrix<int> wm(a);\n\
    \    for (int i = 0; i < Q; ++i) {\n        int l, r, k;\n        cin >> l >>\
    \ r >> k;\n        cout << wm.quantile(l, r, k) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../../data-structure/wavelet_matrix.cpp\"\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> a(N);\n\
    \    for (int i = 0; i < N; ++i) cin >> a[i];\n    WaveletMatrix<int> wm(a);\n\
    \    for (int i = 0; i < Q; ++i) {\n        int l, r, k;\n        cin >> l >>\
    \ r >> k;\n        cout << wm.quantile(l, r, k) << \"\\n\";\n    }\n}"
  dependsOn:
  - data-structure/wavelet_matrix.cpp
  - data-structure/bit_vector.cpp
  isVerificationFile: true
  path: test/yosupo/range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2020-11-03 02:25:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_kth_smallest.test.cpp
- /verify/test/yosupo/range_kth_smallest.test.cpp.html
title: test/yosupo/range_kth_smallest.test.cpp
---