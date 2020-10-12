---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/bit_vector.cpp
    title: Bit Vector
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_kth_smallest.test.cpp
    title: test/yosupo/range_kth_smallest.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-strucutre/wavelet_matrix.md
    document_title: Wavelet Matrix
    links: []
  bundledCode: "#line 1 \"data-structure/wavelet_matrix.cpp\"\n#include <bits/stdc++.h>\n\
    #line 2 \"data-structure/bit_vector.cpp\"\n\n/*\n * @brief Bit Vector\n */\nclass\
    \ BitVector {\n    using u32 = uint32_t;\n\npublic:\n    BitVector() = default;\n\
    \    explicit BitVector(const std::vector<bool>& v) {\n        int n = (v.size()\
    \ + sz - 1) / sz;\n        data.resize(n);\n        sum.resize(n + 1);\n     \
    \   for (int i = 0; i < (int) v.size(); ++i) data[i / sz] |= v[i] << (i % sz);\n\
    \        for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + __builtin_popcount(data[i]);\n\
    \    }\n\n    int access(int k) const {\n        return data[k / sz] >> (k % sz)\
    \ & 1;\n    }\n\n    int rank(int k, bool b) const {\n        int mask = (1 <<\
    \ (k % sz)) - 1;\n        int r = sum[k / sz] + __builtin_popcount(data[k / sz]\
    \ & mask);\n        return b ? r : k - r;\n    }\n\n    int select(int k, bool\
    \ b) const {\n        int lb = 0, ub = data.size();\n        while (ub - lb >\
    \ 1) {\n            int m = (lb + ub) / 2;\n            if (rank(m, b) <= k) lb\
    \ = m;\n            else ub = m;\n        }\n        return lb;\n    }\n\nprivate:\n\
    \    static constexpr int sz = 32;\n\n    std::vector<u32> data;\n    std::vector<int>\
    \ sum;\n};\n#line 3 \"data-structure/wavelet_matrix.cpp\"\n\n/*\n * @brief Wavelet\
    \ Matrix\n * @docs docs/data-strucutre/wavelet_matrix.md\n */\nclass WaveletMatrix\
    \ {\npublic:\n    WaveletMatrix() = default;\n    explicit WaveletMatrix(std::vector<int>\
    \ v) {\n        int n = v.size() ;\n        int m = *max_element(v.begin(), v.end());\n\
    \        int d = 32 - __builtin_clz(m);\n        mat.resize(d);\n        cnt0.resize(d);\n\
    \        for (d -= 1; d >= 0; --d) {\n            std::vector<bool> bit(n);\n\
    \            for (int i = 0; i < n; ++i) bit[i] = v[i] >> d & 1;\n           \
    \ mat[d] = BitVector(bit);\n            std::vector<int> cnt(2);\n           \
    \ for (int i = 0; i < n; ++i) if (!bit[i]) cnt[0]++;\n            cnt0[d] = cnt[0];\n\
    \            cnt[1] = n;\n            std::vector<int> nv(n);\n            for\
    \ (int i = n - 1; i >= 0; --i) nv[--cnt[bit[i]]] = v[i];\n            v.swap(nv);\n\
    \        }\n        for (int i = 0; i < n; ++i) if (!start.count(v[i])) start[v[i]]\
    \ = i;\n    }\n\n    int access(int k) const {\n        int ret = 0;\n       \
    \ for (int d = mat.size() - 1; d >= 0; --d) {\n            int b = mat[d].access(k);\n\
    \            ret |= b << d;\n            k = cnt0[d] * b + mat[d].rank(k, b);\n\
    \        }\n        return ret;\n    }\n\n    int rank(int k, int x) const {\n\
    \        for (int d = mat.size() - 1; d >= 0; --d) {\n            int b = x >>\
    \ d & 1;\n            k = cnt0[d] * b + mat[d].rank(k, b);\n        }\n      \
    \  return k - start.at(x);\n    }\n\n    int rank_less(int k, int x) const {\n\
    \        int ret = 0;\n        int l = 0;\n        for (int d = mat.size() - 1;\
    \ d >= 0; --d) {\n            int b = x >> d & 1;\n            if (b) ret += mat[d].rank(k,\
    \ 0) - mat[d].rank(l, 0);\n            l = cnt0[d] * b + mat[d].rank(l, b);\n\
    \            k = cnt0[d] * b + mat[d].rank(k, b);\n        }\n        return ret;\n\
    \    }\n\n    int select(int k, int x) const {\n        k += start.at(x);\n  \
    \      for (int d = 0; d < (int) mat.size(); ++d) {\n            int b = x >>\
    \ d & 1;\n            k = mat[d].select(k - cnt0[d] * b, b);\n        }\n    \
    \    return k;\n    }\n\n    int quantile(int l, int r, int k) const {\n     \
    \   int ret = 0;\n        for (int d = (int) mat.size() - 1; d >= 0; --d) {\n\
    \            int cnt = mat[d].rank(r, 0) - mat[d].rank(l, 0);\n            int\
    \ b = k < cnt ? 0 : 1;\n            l = cnt0[d] * b + mat[d].rank(l, b);\n   \
    \         r = cnt0[d] * b + mat[d].rank(r, b);\n            if (b) {\n       \
    \         ret |= 1 << d;\n                k -= cnt;\n            }\n        }\n\
    \        return ret;\n    }\n\nprivate:\n    std::vector<BitVector> mat;\n   \
    \ std::vector<int> cnt0;\n    std::unordered_map<int, int> start;\n};\n"
  code: "#include <bits/stdc++.h>\n#include \"bit_vector.cpp\"\n\n/*\n * @brief Wavelet\
    \ Matrix\n * @docs docs/data-strucutre/wavelet_matrix.md\n */\nclass WaveletMatrix\
    \ {\npublic:\n    WaveletMatrix() = default;\n    explicit WaveletMatrix(std::vector<int>\
    \ v) {\n        int n = v.size() ;\n        int m = *max_element(v.begin(), v.end());\n\
    \        int d = 32 - __builtin_clz(m);\n        mat.resize(d);\n        cnt0.resize(d);\n\
    \        for (d -= 1; d >= 0; --d) {\n            std::vector<bool> bit(n);\n\
    \            for (int i = 0; i < n; ++i) bit[i] = v[i] >> d & 1;\n           \
    \ mat[d] = BitVector(bit);\n            std::vector<int> cnt(2);\n           \
    \ for (int i = 0; i < n; ++i) if (!bit[i]) cnt[0]++;\n            cnt0[d] = cnt[0];\n\
    \            cnt[1] = n;\n            std::vector<int> nv(n);\n            for\
    \ (int i = n - 1; i >= 0; --i) nv[--cnt[bit[i]]] = v[i];\n            v.swap(nv);\n\
    \        }\n        for (int i = 0; i < n; ++i) if (!start.count(v[i])) start[v[i]]\
    \ = i;\n    }\n\n    int access(int k) const {\n        int ret = 0;\n       \
    \ for (int d = mat.size() - 1; d >= 0; --d) {\n            int b = mat[d].access(k);\n\
    \            ret |= b << d;\n            k = cnt0[d] * b + mat[d].rank(k, b);\n\
    \        }\n        return ret;\n    }\n\n    int rank(int k, int x) const {\n\
    \        for (int d = mat.size() - 1; d >= 0; --d) {\n            int b = x >>\
    \ d & 1;\n            k = cnt0[d] * b + mat[d].rank(k, b);\n        }\n      \
    \  return k - start.at(x);\n    }\n\n    int rank_less(int k, int x) const {\n\
    \        int ret = 0;\n        int l = 0;\n        for (int d = mat.size() - 1;\
    \ d >= 0; --d) {\n            int b = x >> d & 1;\n            if (b) ret += mat[d].rank(k,\
    \ 0) - mat[d].rank(l, 0);\n            l = cnt0[d] * b + mat[d].rank(l, b);\n\
    \            k = cnt0[d] * b + mat[d].rank(k, b);\n        }\n        return ret;\n\
    \    }\n\n    int select(int k, int x) const {\n        k += start.at(x);\n  \
    \      for (int d = 0; d < (int) mat.size(); ++d) {\n            int b = x >>\
    \ d & 1;\n            k = mat[d].select(k - cnt0[d] * b, b);\n        }\n    \
    \    return k;\n    }\n\n    int quantile(int l, int r, int k) const {\n     \
    \   int ret = 0;\n        for (int d = (int) mat.size() - 1; d >= 0; --d) {\n\
    \            int cnt = mat[d].rank(r, 0) - mat[d].rank(l, 0);\n            int\
    \ b = k < cnt ? 0 : 1;\n            l = cnt0[d] * b + mat[d].rank(l, b);\n   \
    \         r = cnt0[d] * b + mat[d].rank(r, b);\n            if (b) {\n       \
    \         ret |= 1 << d;\n                k -= cnt;\n            }\n        }\n\
    \        return ret;\n    }\n\nprivate:\n    std::vector<BitVector> mat;\n   \
    \ std::vector<int> cnt0;\n    std::unordered_map<int, int> start;\n};"
  dependsOn:
  - data-structure/bit_vector.cpp
  isVerificationFile: false
  path: data-structure/wavelet_matrix.cpp
  requiredBy: []
  timestamp: '2020-10-12 03:03:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/range_kth_smallest.test.cpp
documentation_of: data-structure/wavelet_matrix.cpp
layout: document
redirect_from:
- /library/data-structure/wavelet_matrix.cpp
- /library/data-structure/wavelet_matrix.cpp.html
title: Wavelet Matrix
---