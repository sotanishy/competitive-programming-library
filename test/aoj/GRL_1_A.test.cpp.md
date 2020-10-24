---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.cpp
    title: Dijkstra's Algorithm
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A
  bundledCode: "#line 1 \"test/aoj/GRL_1_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#line 1 \"graph/dijkstra.cpp\"\n#include <bits/stdc++.h>\n#line 3 \"graph/edge.cpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n    int from, to;\n    T weight;\n \
    \   Edge(int to, T weight) : from(-1), to(to), weight(weight) {}\n    Edge(int\
    \ from, int to, T weight) : from(from), to(to), weight(weight) {}\n};\n#line 3\
    \ \"graph/dijkstra.cpp\"\n\n/*\n * @brief Dijkstra's Algorithm\n * @docs docs/graph/dijkstra.md\n\
    \ */\ntemplate <typename T>\nstd::vector<T> dijkstra(const std::vector<std::vector<Edge<T>>>&\
    \ G, int s) {\n    std::vector<T> dist(G.size(), std::numeric_limits<T>::max());\n\
    \    dist[s] = 0;\n    using P = std::pair<T, int>;\n    std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> pq;\n    pq.emplace(0, s);\n\n    while (!pq.empty())\
    \ {\n        T weight;\n        int v;\n        std::tie(weight, v) = pq.top();\n\
    \        pq.pop();\n        if (dist[v] < weight) continue;\n        for (auto&\
    \ e : G[v]) {\n            if (dist[e.to] > dist[v] + e.weight) {\n          \
    \      dist[e.to] = dist[v] + e.weight;\n                pq.emplace(dist[e.to],\
    \ e.to);\n            }\n        }\n    }\n\n    return dist;\n}\n#line 4 \"test/aoj/GRL_1_A.test.cpp\"\
    \n\nusing namespace std;\n\nconst int INF = 1e9;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int V, E, r;\n    cin >> V >> E >> r;\n    vector<vector<Edge<int>>>\
    \ G(V);\n    for (int i = 0; i < E; i++) {\n        int s, t, d;\n        cin\
    \ >> s >> t >> d;\n        G[s].push_back({t, d});\n    }\n    auto dist = dijkstra(G,\
    \ r);\n    for (int i = 0; i < V; i++) {\n        if (dist[i] < INF) cout << dist[i]\
    \ << \"\\n\";\n        else cout << \"INF\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A\"\
    \n\n#include \"../../graph/dijkstra.cpp\"\n\nusing namespace std;\n\nconst int\
    \ INF = 1e9;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int V, E, r;\n    cin >> V >> E >> r;\n    vector<vector<Edge<int>>> G(V);\n\
    \    for (int i = 0; i < E; i++) {\n        int s, t, d;\n        cin >> s >>\
    \ t >> d;\n        G[s].push_back({t, d});\n    }\n    auto dist = dijkstra(G,\
    \ r);\n    for (int i = 0; i < V; i++) {\n        if (dist[i] < INF) cout << dist[i]\
    \ << \"\\n\";\n        else cout << \"INF\\n\";\n    }\n}"
  dependsOn:
  - graph/dijkstra.cpp
  - graph/edge.cpp
  isVerificationFile: true
  path: test/aoj/GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2020-10-06 11:51:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_A.test.cpp
- /verify/test/aoj/GRL_1_A.test.cpp.html
title: test/aoj/GRL_1_A.test.cpp
---