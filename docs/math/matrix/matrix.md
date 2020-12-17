## Description

行列を表す．

## Operations

- `Matrix(int m, int n)`
    - $m \times n$ 零行列を構築する
    - 時間計算量: $O(mn)$
- `Matrix(initializer_list<initializer_list<T>> list)`
    - `list` の要素で行列を構築する
    - 時間計算量: $O(mn)$
- `static Matrix concatenate(const Matrix& A, const Matrix& B)`
    - $A$ と $B$ を結合した行列を返す
    - 時間計算量: $O(m(n_A + n_B))$
- `Matrix transpose()`
    - 転置行列を返す
    - 時間計算量: $O(mn)$
- `Matrix matmul(const Matrix& B)`
    - 行列積 $AB$ を返す
    - 時間計算量: $O(m_A n_A n_B)$
- `Matrix rref()`
    - $A$ に対して掃き出し法を行った結果を返す
    - 時間計算量: $O(mn^2)$
- `int rank()`
    - $A$ の階数を返す
    - 時間計算量: $O(mn^2)$
- `vector<vector<T>> solve_system(vector<T> b)`
    - $Ax = b$ の解を返す．返り値を `sol` としたとき，`sol[0]` は解の1つ，`sol[1:]` は解空間の基底である．解がないときは空リストを返す．
    - 時間計算量: $O(mn^2)$