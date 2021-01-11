---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/euler_totient.cpp
    title: Euler's Totient Function
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
  bundledCode: "#line 1 \"test/aoj/NTL_1_D.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\
    \n\n#line 2 \"math/euler_totient.cpp\"\n\n/*\n * @brief Euler's Totient Function\n\
    \ * @docs docs/math/euler_totient.md\n */\nlong long euler_totient(long long n)\
    \ {\n    long long ret = n;\n    if (n % 2 == 0) {\n        ret -= ret / 2;\n\
    \        while (n % 2 == 0) n /= 2;\n    }\n    for (long long i = 3; i * i <=\
    \ n; i += 2) {\n        if (n % i == 0) {\n            ret -= ret / i;\n     \
    \       while (n % i == 0) n /= i;\n        }\n    }\n    if (n != 1) ret -= ret\
    \ / n;\n    return ret;\n}\n#line 4 \"test/aoj/NTL_1_D.test.cpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n;\n    cin >> n;\n    cout << euler_totient(n) <<\
    \ endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\
    \n\n#include \"../../math/euler_totient.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int n;\n    cin >> n;\n    cout << euler_totient(n) << endl;\n}"
  dependsOn:
  - math/euler_totient.cpp
  isVerificationFile: true
  path: test/aoj/NTL_1_D.test.cpp
  requiredBy: []
  timestamp: '2020-10-26 00:14:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_D.test.cpp
- /verify/test/aoj/NTL_1_D.test.cpp.html
title: test/aoj/NTL_1_D.test.cpp
---