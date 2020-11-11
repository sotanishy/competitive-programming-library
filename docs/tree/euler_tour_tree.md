## Description

Euler tour 木は，森を管理するデータ構造である．以下の機能を提供する:
- 辺の追加
- 辺の削除
- 頂点の値の更新
- 部分木の頂点の値 (可換モノイド) の総和

オイラーツアーを平衡二分探索木で管理することでこれらの操作を実現する．

空間計算量: $O(n)$

## Operations

- `EulerTourTree(int n)`
    - 頂点数 $n$ の森を構築する
    - 時間計算量: $O(n)$
- `void link(int u, int v)`
    - 辺 $uv$ を追加する
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `void cut(int u, int v)`
    - 辺 $uv$
    - 木 $v$ を親から切る
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `void get(int v)`
    - $v$ の値を取得する
    - 時間計算量: $O(1)$
- `void update(int v, T x)`
    - 頂点 $v$ の値を $x$ に変更する
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `T fold(int v, int p)`
    - $p$ を親として，$v$ を根とする部分木上の頂点の値を fold する
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$

## Reference

- [プログラミングコンテストでのデータ構造 2　～動的木編～](https://www.slideshare.net/iwiwi/2-12188845)
- [Euler Tour Tree](https://kopricky.github.io/code/DataStructure_OnGraph/euler_tour_tree.html)
- [Euler Tour Trees](https://web.stanford.edu/class/archive/cs/cs166/cs166.1146/lectures/04/Small04.pdf)
- [【競技プログラミング】online dynamic connectivity(削除可能union-find)の作り方を詳しく解説！！！](https://qiita.com/hotman78/items/78cd3aa50b05a57738d4)

## TODO

- 遅延伝搬
- online dynamic connectivity