---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/largest_rectangle.cpp
    title: Largest Rectangle
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C
  bundledCode: "#line 1 \"test/aoj/DPL_3_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C\"\
    \n\n#line 2 \"dp/largest_rectangle.cpp\"\n#include <algorithm>\n#include <stack>\n\
    #include <utility>\n#include <vector>\n\n/*\n * @brief Largest Rectangle\n */\n\
    template <typename T>\nT largest_rectangle(const std::vector<T>& h) {\n    int\
    \ n = h.size();\n    std::vector<int> left(n), right(n);\n    std::stack<std::pair<T,\
    \ int>> st;\n    st.emplace(-1, -1);\n    for (int i = 0; i < n; ++i) {\n    \
    \    while (st.top().first >= h[i]) st.pop();\n        left[i] = st.top().second\
    \ + 1;\n        st.emplace(h[i], i);\n    }\n    while (!st.empty()) st.pop();\n\
    \    st.emplace(-1, n);\n    for (int i = n - 1; i >= 0; --i) {\n        while\
    \ (st.top().first >= h[i]) st.pop();\n        right[i] = st.top().second;\n  \
    \      st.emplace(h[i], i);\n    }\n    T ret = 0;\n    for (int i = 0; i < n;\
    \ ++i) ret = std::max(ret, h[i] * (right[i] - left[i]));\n    return ret;\n}\n\
    #line 4 \"test/aoj/DPL_3_C.test.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N;\n    cin >> N;\n    vector<ll> h(N);\n    for (auto&\
    \ x : h) cin >> x;\n    cout << largest_rectangle(h) << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C\"\
    \n\n#include \"../../dp/largest_rectangle.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N;\n    cin >> N;\n    vector<ll> h(N);\n    for (auto&\
    \ x : h) cin >> x;\n    cout << largest_rectangle(h) << endl;\n}\n"
  dependsOn:
  - dp/largest_rectangle.cpp
  isVerificationFile: true
  path: test/aoj/DPL_3_C.test.cpp
  requiredBy: []
  timestamp: '2021-02-05 21:57:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_3_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_3_C.test.cpp
- /verify/test/aoj/DPL_3_C.test.cpp.html
title: test/aoj/DPL_3_C.test.cpp
---