# Minimum Cost Flow

フローネットワークの最小費用流を求める．

## Template parameters

- `Cap`
    - 容量の型
- `Cost`
    - コストの型

## Construcor

- `MinCostFlow(int V)`
    - グラフを $V$ 頂点で初期化する
    - 時間計算量: $O(V)$

## Member functions

- `void add_edge(int u, int v, Cap cap, Cost cost)`
    - 容量 $cap$，コスト $cost$ の辺 $(u, v)$ を追加する
    - 時間計算量: $O(1)$
- `Cost min_cost_flow(int s, int t, Cap f)`
    - 始点 $s$ から終点 $t$ への流量 $f$ の最小費用流を求める
    - 時間計算量: $O(fE\lg V)$