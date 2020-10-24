# Minimum Spanning Tree Algorithms

最小全域木を求めるアルゴリズム詰め合わせ

## Kruskal's Algorithm

Kruskal のアルゴリズムは，無向重み付きグラフの最小全域木を求めるアルゴリズムである．

- `pair<T, vector<Edge<T>>> kruskal(vector<Edge<T>> G, int V)`
    - 頂点数 $V$ のグラフ $G$ の辺のリストが与えられたとき，最小全域木とその重みを求める
    - 時間計算量: $O(E\lg V)$

## Prim's Algorithm

Prim のアルゴリズムは，無向重み付きグラフの最小全域木を求めるアルゴリズムである．

- `pair<T, vector<Edge<T>>> prim(vector<vector<Edge<T>>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，最小全域木とその重みを求める
    - 時間計算量: $O(E\lg V)$

## Boruvka's Algorithm

Boruvka のアルゴリズムは，無向重み付きグラフの最小全域木を求めるアルゴリズムである．

- `pair<T, vector<Edge<T>>> kruskal(vector<Edge<T>> G, int V)`
    - 頂点数 $V$ のグラフ $G$ の辺のリストが与えられたとき，最小全域木とその重みを求める
    - 時間計算量: $O(E\lg V)$