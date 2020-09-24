---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"misc/timer.cpp\"\n#include <bits/stdc++.h>\n\nclass Timer\
    \ {\npublic:\n    void start() {\n        start_time = std::chrono::steady_clock::now();\n\
    \    }\n\n    long long get_time() {\n        auto cur_time = std::chrono::steady_clock::now();\n\
    \        return std::chrono::duration_cast<std::chrono::milliseconds>(cur_time\
    \ - start_time).count();\n    }\n\nprivate:\n    std::chrono::steady_clock::time_point\
    \ start_time;\n};\n"
  code: "#include <bits/stdc++.h>\n\nclass Timer {\npublic:\n    void start() {\n\
    \        start_time = std::chrono::steady_clock::now();\n    }\n\n    long long\
    \ get_time() {\n        auto cur_time = std::chrono::steady_clock::now();\n  \
    \      return std::chrono::duration_cast<std::chrono::milliseconds>(cur_time -\
    \ start_time).count();\n    }\n\nprivate:\n    std::chrono::steady_clock::time_point\
    \ start_time;\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/timer.cpp
  requiredBy: []
  timestamp: '2020-09-23 11:28:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/timer.cpp
layout: document
redirect_from:
- /library/misc/timer.cpp
- /library/misc/timer.cpp.html
title: misc/timer.cpp
---