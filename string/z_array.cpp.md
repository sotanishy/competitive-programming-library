---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/zalgorithm.test.cpp
    title: test/yosupo/zalgorithm.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/z_array.md
    document_title: Z Array
    links: []
  bundledCode: "#line 2 \"string/z_array.cpp\"\n#include <bits/stdc++.h>\n\n/*\n *\
    \ @brief Z Array\n * @docs docs/string/z_array.md\n */\nstd::vector<int> z_array(const\
    \ std::string& s) {\n    int n = s.size();\n    std::vector<int> z(n);\n    z[0]\
    \ = n;\n    int l = 0, r = 0;\n    for (int i = 1; i < n; ++i) {\n        int\
    \ k = i - l;\n        if (i <= r && z[k] < r - i + 1) {\n            z[i] = z[k];\n\
    \        } else {\n            l = i;\n            if (i > r) r = i;\n       \
    \     while (r < n && s[r - l] == s[r]) ++r;\n            --r;\n            z[i]\
    \ = r - l + 1;\n        }\n    }\n    return z;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n\n/*\n * @brief Z Array\n * @docs\
    \ docs/string/z_array.md\n */\nstd::vector<int> z_array(const std::string& s)\
    \ {\n    int n = s.size();\n    std::vector<int> z(n);\n    z[0] = n;\n    int\
    \ l = 0, r = 0;\n    for (int i = 1; i < n; ++i) {\n        int k = i - l;\n \
    \       if (i <= r && z[k] < r - i + 1) {\n            z[i] = z[k];\n        }\
    \ else {\n            l = i;\n            if (i > r) r = i;\n            while\
    \ (r < n && s[r - l] == s[r]) ++r;\n            --r;\n            z[i] = r - l\
    \ + 1;\n        }\n    }\n    return z;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/z_array.cpp
  requiredBy: []
  timestamp: '2020-10-01 22:40:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/zalgorithm.test.cpp
documentation_of: string/z_array.cpp
layout: document
redirect_from:
- /library/string/z_array.cpp
- /library/string/z_array.cpp.html
title: Z Array
---
# Z Array

Z 配列は，文字列 `S` と `S[i:]` の最長共通接頭辞の長さを表す配列である．Z 配列を求めるアルゴリズムは Z algorithm と呼ばれる．

Z 配列を用いると文字列中のパターンをすべて検索することができる．文字列を `S`，パターンを `P` とし，`"P$S"` (`$` は `S` にも `P` にも含まれない文字) の Z 配列を構築すると，値が `P` の長さと一致するところで `P` が現れる．

- `vector<int> z_array(string s)`
    - Z 配列を構築する．
    - 時間計算量: $O(n)$

## Reference

- [Z algorithm (Linear time pattern searching Algorithm)](https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/)