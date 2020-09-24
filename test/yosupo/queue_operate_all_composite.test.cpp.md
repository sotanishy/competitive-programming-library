---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sliding_window_aggregation.cpp
    title: Sliding Window Aggregation
  - icon: ':heavy_check_mark:'
    path: math/modint.cpp
    title: math/modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/yosupo/queue_operate_all_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\n\n\
    #line 1 \"data-structure/sliding_window_aggregation.cpp\"\n#include <bits/stdc++.h>\n\
    \n/*\n * @brief Sliding Window Aggregation\n * @docs docs/data-structure/sliding_window_aggregation.md\n\
    \ */\ntemplate <typename M>\nclass SlidingWindowAggregation {\n    using T = typename\
    \ M::T;\n\npublic:\n    void push(T x) {\n        if (back.empty()) back.emplace(x,\
    \ x);\n        else back.emplace(x, M::op(back.top().second, x));\n    }\n\n \
    \   void pop() {\n        if (front.empty()) {\n            if (back.empty())\
    \ return;\n            T x = back.top().first;\n            back.pop();\n    \
    \        front.emplace(x, x);\n            while (!back.empty()) {\n         \
    \       x = back.top().first;\n                back.pop();\n                front.emplace(x,\
    \ M::op(x, front.top().second));\n            }\n        }\n        front.pop();\n\
    \    }\n\n    T fold() const {\n        T ret = M::id;\n        if (!front.empty())\
    \ ret = M::op(ret, front.top().second);\n        if (!back.empty()) ret = M::op(ret,\
    \ back.top().second);\n        return ret;\n    }\n\nprivate:\n    std::stack<std::pair<T,\
    \ T>> front, back;\n};\n#line 2 \"math/modint.cpp\"\n\ntemplate <int mod>\nclass\
    \ Modint {\n    static_assert(mod > 0, \"Modulus must be positive\");\n\npublic:\n\
    \    constexpr Modint(long long y = 0) noexcept : x(y >= 0 ? y % mod : (y % mod\
    \ + mod) % mod) {}\n\n    constexpr int value() const noexcept { return x; }\n\
    \n    constexpr Modint& operator+=(const Modint& p) noexcept { if ((x += p.x)\
    \ >= mod) x -= mod; return *this; }\n    constexpr Modint& operator-=(const Modint&\
    \ p) noexcept { if ((x += mod - p.x) >= mod) x -= mod; return *this; }\n    constexpr\
    \ Modint& operator*=(const Modint& p) noexcept { x = static_cast<int>(1LL * x\
    \ * p.x % mod); return *this; }\n    constexpr Modint& operator/=(const Modint&\
    \ p) noexcept { *this *= p.inv(); return *this; }\n\n    constexpr Modint operator-()\
    \ const noexcept { return Modint(-x); }\n\n    constexpr Modint operator+(const\
    \ Modint& p) const noexcept { return Modint(*this) += p; }\n    constexpr Modint\
    \ operator-(const Modint& p) const noexcept { return Modint(*this) -= p; }\n \
    \   constexpr Modint operator*(const Modint& p) const noexcept { return Modint(*this)\
    \ *= p; }\n    constexpr Modint operator/(const Modint& p) const noexcept { return\
    \ Modint(*this) /= p; }\n\n    constexpr bool operator==(const Modint& p) const\
    \ noexcept { return x == p.x; }\n    constexpr bool operator!=(const Modint& p)\
    \ const noexcept { return x != p.x; }\n\n    constexpr Modint inv() const noexcept\
    \ {\n        int a = x, b = mod, u = 1, v = 0;\n        while (b > 0) {\n    \
    \        int t = a / b;\n            std::swap(a -= t * b, b);\n            std::swap(u\
    \ -= t * v, v);\n        }\n        return Modint(u);\n    }\n\n    constexpr\
    \ Modint pow(long long n) const noexcept {\n        Modint ret(1), mul(x);\n \
    \       while (n > 0) {\n            if (n & 1) ret *= mul;\n            mul *=\
    \ mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\n    friend\
    \ std::ostream &operator<<(std::ostream& os, const Modint& p) {\n        return\
    \ os << p.x;\n    }\n\n    friend std::istream &operator>>(std::istream& is, Modint&\
    \ a) {\n        long long t;\n        is >> t;\n        a = Modint<mod>(t);\n\
    \        return is;\n    }\n\nprivate:\n    int x;\n};\n#line 5 \"test/yosupo/queue_operate_all_composite.test.cpp\"\
    \n\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\nstruct M {\n  \
    \  using T = pair<mint, mint>;\n    inline static const T id = {1, 0};\n    static\
    \ T op(T a, T b) {\n        return {a.first * b.first, a.second * b.first + b.second};\n\
    \    }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int Q;\n    cin >> Q;\n    SlidingWindowAggregation<M> que;\n    for (int\
    \ i = 0; i < Q; i++) {\n        int t;\n        cin >> t;\n        if (t == 0)\
    \ {\n            int a, b;\n            cin >> a >> b;\n            que.push({a,\
    \ b});\n        } else if (t == 1) {\n            que.pop();\n        } else {\n\
    \            int x;\n            cin >> x;\n            auto p = que.fold();\n\
    \            cout << p.first * x + p.second << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include \"../../data-structure/sliding_window_aggregation.cpp\"\n#include\
    \ \"../../math/modint.cpp\"\n\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\
    \nstruct M {\n    using T = pair<mint, mint>;\n    inline static const T id =\
    \ {1, 0};\n    static T op(T a, T b) {\n        return {a.first * b.first, a.second\
    \ * b.first + b.second};\n    }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int Q;\n    cin >> Q;\n    SlidingWindowAggregation<M>\
    \ que;\n    for (int i = 0; i < Q; i++) {\n        int t;\n        cin >> t;\n\
    \        if (t == 0) {\n            int a, b;\n            cin >> a >> b;\n  \
    \          que.push({a, b});\n        } else if (t == 1) {\n            que.pop();\n\
    \        } else {\n            int x;\n            cin >> x;\n            auto\
    \ p = que.fold();\n            cout << p.first * x + p.second << \"\\n\";\n  \
    \      }\n    }\n}"
  dependsOn:
  - data-structure/sliding_window_aggregation.cpp
  - math/modint.cpp
  isVerificationFile: true
  path: test/yosupo/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 11:43:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/queue_operate_all_composite.test.cpp
- /verify/test/yosupo/queue_operate_all_composite.test.cpp.html
title: test/yosupo/queue_operate_all_composite.test.cpp
---