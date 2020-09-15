#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Disjoint Sparse Table
 * @docs docs/data-structure/disjoint_sparse_table.md
 */
template <typename S>
struct DisjointSparseTable {
    using T = typename S::T;

    vector<vector<T>> lookup;

    DisjointSparseTable(const vector<T>& v) {
        int n = v.size(), b = 0;
        while ((1 << b) < n) b++;
        lookup.resize(b + 1, vector<T>(n));
        copy(v.begin(), v.end(), lookup[0].begin());
        for (int i = 1; i <= b; i++) {
            int len = 1 << i;
            for (int l = 0; l + len / 2 < n; l += len) {
                int m = l + len / 2;
                lookup[i][m - 1] = v[m - 1];
                for (int j = 1; j < len / 2; j++) {
                    lookup[i][m - 1 - j] = S::op(v[m - 1 - j], lookup[i][m - j]);
                }
                lookup[i][m] = v[m];
                for (int j = 1; m + j < min(l + len, n); j++) {
                    lookup[i][m + j] = S::op(lookup[i][m + j - 1], v[m + j]);
                }
            }
        }
    }

    T fold(int l, int r) {
        if (r - l == 1) return lookup[0][l];
        int i = 32 - __builtin_clz(l ^ (r - 1));
        return S::op(lookup[i][l], lookup[i][r - 1]);
    }
};