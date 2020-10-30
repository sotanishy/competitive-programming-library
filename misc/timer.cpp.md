---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/timer.cpp\"\n#include <chrono>\n\nclass Timer {\npublic:\n\
    \    void start() {\n        start_time = std::chrono::steady_clock::now();\n\
    \    }\n\n    long long get_time() const {\n        auto cur_time = std::chrono::steady_clock::now();\n\
    \        return std::chrono::duration_cast<std::chrono::milliseconds>(cur_time\
    \ - start_time).count();\n    }\n\nprivate:\n    std::chrono::steady_clock::time_point\
    \ start_time;\n};\n"
  code: "#pragma once\n#include <chrono>\n\nclass Timer {\npublic:\n    void start()\
    \ {\n        start_time = std::chrono::steady_clock::now();\n    }\n\n    long\
    \ long get_time() const {\n        auto cur_time = std::chrono::steady_clock::now();\n\
    \        return std::chrono::duration_cast<std::chrono::milliseconds>(cur_time\
    \ - start_time).count();\n    }\n\nprivate:\n    std::chrono::steady_clock::time_point\
    \ start_time;\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/timer.cpp
  requiredBy: []
  timestamp: '2020-10-24 00:03:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/timer.cpp
layout: document
redirect_from:
- /library/misc/timer.cpp
- /library/misc/timer.cpp.html
title: misc/timer.cpp
---