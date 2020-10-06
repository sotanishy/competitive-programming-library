# Li Chao Tree

Li Chao tree は，直線及び線分の集合をセグメント木で管理し，与えられた $x$ 座標での最小値を取得するデータ構造である．

## Template parameter

- `T`
    - 値の型

## Constructor

- `LiChaoTree(vector<T> vs)`
    - クエリに用いる $x$ 座標を受け取り，Li Chao tree を構築する
    - 時間計算量: $O(n)$

## Member functions

- `void add_line(T a, T b)`
    - 直線 $y = ax + b$ を追加する
    - 時間計算量: $O(\lg n)$
- `void add_segment(T a, T b, int l, int r)`
    - 線分 $y = ax + b \quad (x \in [vs_l, vs_r))$ を追加する
    - 時間計算量: $O(\lg^2 n)$
- `T get_min(int k)`
    - $x = vs_k$ での最小値を取得する
    - 時間計算量: $O(\lg n)$

## Reference

- [Li Chao Treeのメモ](https://smijake3.hatenablog.com/entry/2018/06/16/144548)