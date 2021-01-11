---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path.cpp
    title: Shortest Path Algorithms
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C
  bundledCode: "#line 1 \"test/aoj/GRL_1_C.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#line 2 \"graph/shortest_path.cpp\"\n#include <limits>\n#include <queue>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n#line 2 \"graph/edge.cpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n    int from, to;\n    T weight;\n \
    \   Edge(int to, T weight) : from(-1), to(to), weight(weight) {}\n    Edge(int\
    \ from, int to, T weight) : from(from), to(to), weight(weight) {}\n};\n#line 8\
    \ \"graph/shortest_path.cpp\"\n\n/*\n * @brief Shortest Path Algorithms\n * @docs\
    \ docs/graph/shortest_path.md\n */\n\n/*\n * Bellman-Ford Algorithm\n */\ntemplate\
    \ <typename T>\nstd::vector<T> bellman_ford(const std::vector<Edge<T>>& G, int\
    \ V, int s) {\n    constexpr T INF = std::numeric_limits<T>::max();\n    std::vector<int>\
    \ dist(V, INF);\n    dist[s] = 0;\n    for (int i = 0; i < V; ++i) {\n       \
    \ for (auto& e : G) {\n            if (dist[e.from] != INF && dist[e.to] > dist[e.from]\
    \ + e.weight) {\n                dist[e.to] = dist[e.from] + e.weight;\n     \
    \           if (i == V - 1) return std::vector<T>();\n            }\n        }\n\
    \    }\n    return dist;\n}\n\n/*\n * Floyd-Warshall Algorithm\n */\ntemplate\
    \ <typename T>\nvoid floyd_warshall(std::vector<std::vector<T>>& dist) {\n   \
    \ int V = dist.size();\n    for (int k = 0; k < V; ++k) {\n        for (int i\
    \ = 0; i < V; ++i) {\n            for (int j = 0; j < V; ++j) {\n            \
    \    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);\n           \
    \ }\n        }\n    }\n}\n\n/*\n * Dijkstra's Algorithm\n */\ntemplate <typename\
    \ T>\nstd::vector<T> dijkstra(const std::vector<std::vector<Edge<T>>>& G, int\
    \ s) {\n    std::vector<T> dist(G.size(), std::numeric_limits<T>::max());\n  \
    \  dist[s] = 0;\n    using P = std::pair<T, int>;\n    std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> pq;\n    pq.emplace(0, s);\n\n    while (!pq.empty())\
    \ {\n        T d;\n        int v;\n        std::tie(d, v) = pq.top();\n      \
    \  pq.pop();\n        if (dist[v] < d) continue;\n        for (auto& e : G[v])\
    \ {\n            if (dist[e.to] > d + e.weight) {\n                dist[e.to]\
    \ = d + e.weight;\n                pq.emplace(dist[e.to], e.to);\n           \
    \ }\n        }\n    }\n\n    return dist;\n}\n\n/*\n * Dial's Algorithm\n */\n\
    std::vector<int> dial(const std::vector<std::vector<Edge<int>>>& G, int s, int\
    \ w) {\n    std::vector<int> dist(G.size(), std::numeric_limits<int>::max());\n\
    \    dist[s] = 0;\n    std::vector<std::vector<int>> buckets(w * G.size(), std::vector<int>());\n\
    \    buckets[0].push_back(s);\n\n    for (int d = 0; d < (int) buckets.size();\
    \ ++d) {\n        while (!buckets[d].empty()) {\n            int v = buckets[d].back();\n\
    \            buckets[d].pop_back();\n            if (dist[v] < d) continue;\n\
    \            for (auto& e : G[v]) {\n                if (dist[e.to] > d + e.weight)\
    \ {\n                    dist[e.to] = d + e.weight;\n                    buckets[dist[e.to]].push_back(e.to);\n\
    \                }\n            }\n        }\n    }\n    return dist;\n}\n#line\
    \ 4 \"test/aoj/GRL_1_C.test.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n\nconst ll INF = 1e18;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int V, E;\n    cin >> V >> E;\n    vector<vector<ll>>\
    \ dist(V, vector<ll>(V, INF));\n    for (int i = 0; i < V; i++) dist[i][i] = 0;\n\
    \    for (int i = 0; i < E; i++) {\n        int s, t, d;\n        cin >> s >>\
    \ t >> d;\n        dist[s][t] = d;\n    }\n    floyd_warshall(dist);\n    for\
    \ (int i = 0; i < V; i++) {\n        if (dist[i][i] < 0) {\n            cout <<\
    \ \"NEGATIVE CYCLE\\n\";\n            return 0;\n        }\n    }\n    for (int\
    \ i = 0; i < V; i++) {\n        for (int j = 0; j < V; j++) {\n            if\
    \ (dist[i][j] < 1e10) cout << dist[i][j];\n            else cout << \"INF\";\n\
    \            if (j < V - 1) cout << \" \";\n            else cout << \"\\n\";\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C\"\
    \n\n#include \"../../graph/shortest_path.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\nusing ll = long long;\n\nconst ll INF = 1e18;\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int V, E;\n\
    \    cin >> V >> E;\n    vector<vector<ll>> dist(V, vector<ll>(V, INF));\n   \
    \ for (int i = 0; i < V; i++) dist[i][i] = 0;\n    for (int i = 0; i < E; i++)\
    \ {\n        int s, t, d;\n        cin >> s >> t >> d;\n        dist[s][t] = d;\n\
    \    }\n    floyd_warshall(dist);\n    for (int i = 0; i < V; i++) {\n       \
    \ if (dist[i][i] < 0) {\n            cout << \"NEGATIVE CYCLE\\n\";\n        \
    \    return 0;\n        }\n    }\n    for (int i = 0; i < V; i++) {\n        for\
    \ (int j = 0; j < V; j++) {\n            if (dist[i][j] < 1e10) cout << dist[i][j];\n\
    \            else cout << \"INF\";\n            if (j < V - 1) cout << \" \";\n\
    \            else cout << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - graph/shortest_path.cpp
  - graph/edge.cpp
  isVerificationFile: true
  path: test/aoj/GRL_1_C.test.cpp
  requiredBy: []
  timestamp: '2020-11-28 19:10:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_C.test.cpp
- /verify/test/aoj/GRL_1_C.test.cpp.html
title: test/aoj/GRL_1_C.test.cpp
---