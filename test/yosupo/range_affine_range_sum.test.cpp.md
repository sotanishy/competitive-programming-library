---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/lazy_segment_tree.cpp
    title: Segment Tree with Lazy Propagation
  - icon: ':heavy_check_mark:'
    path: math/modint.cpp
    title: math/modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/range_affine_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n#line 1 \"data-structure/lazy_segment_tree.cpp\"\
    \n#include <bits/stdc++.h>\n\n/*\n * @brief Segment Tree with Lazy Propagation\n\
    \ * @docs docs/data-structure/lazy_segment_tree.md\n */\ntemplate <typename M,\
    \ typename O, typename M::T (*act)(typename M::T, typename O::T)>\nclass LazySegmentTree\
    \ {\n    using T = typename M::T;\n    using E = typename O::T;\n\npublic:\n \
    \   LazySegmentTree() = default;\n    explicit LazySegmentTree(int n) : LazySegmentTree(std::vector<T>(n,\
    \ M::id)) {}\n    explicit LazySegmentTree(const std::vector<T>& v) {\n      \
    \  size = 1;\n        height = 0;\n        while (size < (int) v.size()) size\
    \ <<= 1, ++height;\n        node.resize(2 * size, M::id);\n        lazy.resize(2\
    \ * size, O::id);\n        std::copy(v.begin(), v.end(), node.begin() + size);\n\
    \        for (int i = size - 1; i > 0; --i) node[i] = M::op(node[2 * i], node[2\
    \ * i + 1]);\n    }\n\n    T operator[](int k) {\n        return fold(k, k + 1);\n\
    \    }\n\n    void update(int l, int r, const E& x) { update(l, r, x, 1, 0, size);\
    \ }\n\n    T fold(int l, int r) { return fold(l, r, 1, 0, size); }\n\nprivate:\n\
    \    int size, height;\n    std::vector<T> node;\n    std::vector<E> lazy;\n\n\
    \    void push(int k) {\n        if (lazy[k] == O::id) return;\n        if (k\
    \ < size) {\n            lazy[2 * k] = O::op(lazy[2 * k], lazy[k]);\n        \
    \    lazy[2 * k + 1] = O::op(lazy[2 * k + 1], lazy[k]);\n        }\n        node[k]\
    \ = act(node[k], lazy[k]);\n        lazy[k] = O::id;\n    }\n\n    void update(int\
    \ a, int b, const E& x, int k, int l, int r) {\n        push(k);\n        if (r\
    \ <= a || b <= l) return;\n        if (a <= l && r <= b) {\n            lazy[k]\
    \ = O::op(lazy[k], x);\n            push(k);\n            return;\n        }\n\
    \        int m = (l + r) / 2;\n        update(a, b, x, 2 * k, l, m);\n       \
    \ update(a, b, x, 2 * k + 1, m, r);\n        node[k] = M::op(node[2 * k], node[2\
    \ * k + 1]);\n    }\n\n    T fold(int a, int b, int k, int l, int r) {\n     \
    \   push(k);\n        if (r <= a || b <= l) return M::id;\n        if (a <= l\
    \ && r <= b) return node[k];\n        int m = (l + r) / 2;\n        return M::op(fold(a,\
    \ b, 2 * k, l, m),\n                     fold(a, b, 2 * k + 1, m, r));\n    }\n\
    };\n#line 2 \"math/modint.cpp\"\n\ntemplate <int mod>\nclass Modint {\n    static_assert(mod\
    \ > 0, \"Modulus must be positive\");\n\npublic:\n    constexpr Modint(long long\
    \ y = 0) noexcept : x(y >= 0 ? y % mod : (y % mod + mod) % mod) {}\n\n    constexpr\
    \ int value() const noexcept { return x; }\n\n    constexpr Modint& operator+=(const\
    \ Modint& p) noexcept { if ((x += p.x) >= mod) x -= mod; return *this; }\n   \
    \ constexpr Modint& operator-=(const Modint& p) noexcept { if ((x += mod - p.x)\
    \ >= mod) x -= mod; return *this; }\n    constexpr Modint& operator*=(const Modint&\
    \ p) noexcept { x = static_cast<int>(1LL * x * p.x % mod); return *this; }\n \
    \   constexpr Modint& operator/=(const Modint& p) noexcept { *this *= p.inv();\
    \ return *this; }\n\n    constexpr Modint operator-() const noexcept { return\
    \ Modint(-x); }\n\n    constexpr Modint operator+(const Modint& p) const noexcept\
    \ { return Modint(*this) += p; }\n    constexpr Modint operator-(const Modint&\
    \ p) const noexcept { return Modint(*this) -= p; }\n    constexpr Modint operator*(const\
    \ Modint& p) const noexcept { return Modint(*this) *= p; }\n    constexpr Modint\
    \ operator/(const Modint& p) const noexcept { return Modint(*this) /= p; }\n\n\
    \    constexpr bool operator==(const Modint& p) const noexcept { return x == p.x;\
    \ }\n    constexpr bool operator!=(const Modint& p) const noexcept { return x\
    \ != p.x; }\n\n    constexpr Modint inv() const noexcept {\n        int a = x,\
    \ b = mod, u = 1, v = 0;\n        while (b > 0) {\n            int t = a / b;\n\
    \            std::swap(a -= t * b, b);\n            std::swap(u -= t * v, v);\n\
    \        }\n        return Modint(u);\n    }\n\n    constexpr Modint pow(long\
    \ long n) const noexcept {\n        Modint ret(1), mul(x);\n        while (n >\
    \ 0) {\n            if (n & 1) ret *= mul;\n            mul *= mul;\n        \
    \    n >>= 1;\n        }\n        return ret;\n    }\n\n    friend std::ostream\
    \ &operator<<(std::ostream& os, const Modint& p) {\n        return os << p.x;\n\
    \    }\n\n    friend std::istream &operator>>(std::istream& is, Modint& a) {\n\
    \        long long t;\n        is >> t;\n        a = Modint<mod>(t);\n       \
    \ return is;\n    }\n\nprivate:\n    int x;\n};\n#line 5 \"test/yosupo/range_affine_range_sum.test.cpp\"\
    \n\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\nstruct M {\n  \
    \  using T = pair<mint, mint>;\n    inline static const T id = {0, 0};\n    static\
    \ T op(T a, T b) {\n        return {a.first + b.first, a.second + b.second};\n\
    \    }\n};\n\nstruct O {\n    using T = pair<mint, mint>;\n    inline static const\
    \ T id = {1, 0};\n    static T op(T a, T b) {\n        return {a.first * b.first,\
    \ a.second * b.first + b.second};\n    }\n};\n\nM::T act(M::T a, O::T b) {\n \
    \   return {a.first * b.first + a.second * b.second, a.second};\n}\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int N, Q;\n\
    \    cin >> N >> Q;\n    vector<pair<mint, mint>> a(N, {0, 1});\n    for (int\
    \ i = 0; i < N; i++) cin >> a[i].first;\n    LazySegmentTree<M, O, act> st(a);\n\
    \    for (int i = 0; i < Q; i++) {\n        int t;\n        cin >> t;\n      \
    \  if (t == 0) {\n            int l, r, b, c;\n            cin >> l >> r >> b\
    \ >> c;\n            st.update(l, r, {b, c});\n        } else {\n            int\
    \ l, r;\n            cin >> l >> r;\n            cout << st.fold(l, r).first <<\
    \ \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../../data-structure/lazy_segment_tree.cpp\"\n#include \"../../math/modint.cpp\"\
    \n\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\nstruct M {\n  \
    \  using T = pair<mint, mint>;\n    inline static const T id = {0, 0};\n    static\
    \ T op(T a, T b) {\n        return {a.first + b.first, a.second + b.second};\n\
    \    }\n};\n\nstruct O {\n    using T = pair<mint, mint>;\n    inline static const\
    \ T id = {1, 0};\n    static T op(T a, T b) {\n        return {a.first * b.first,\
    \ a.second * b.first + b.second};\n    }\n};\n\nM::T act(M::T a, O::T b) {\n \
    \   return {a.first * b.first + a.second * b.second, a.second};\n}\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int N, Q;\n\
    \    cin >> N >> Q;\n    vector<pair<mint, mint>> a(N, {0, 1});\n    for (int\
    \ i = 0; i < N; i++) cin >> a[i].first;\n    LazySegmentTree<M, O, act> st(a);\n\
    \    for (int i = 0; i < Q; i++) {\n        int t;\n        cin >> t;\n      \
    \  if (t == 0) {\n            int l, r, b, c;\n            cin >> l >> r >> b\
    \ >> c;\n            st.update(l, r, {b, c});\n        } else {\n            int\
    \ l, r;\n            cin >> l >> r;\n            cout << st.fold(l, r).first <<\
    \ \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/lazy_segment_tree.cpp
  - math/modint.cpp
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 12:29:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.test.cpp
- /verify/test/yosupo/range_affine_range_sum.test.cpp.html
title: test/yosupo/range_affine_range_sum.test.cpp
---