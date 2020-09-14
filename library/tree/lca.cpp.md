---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: Lowerst Common Ancestor <small>(tree/lca.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/lca.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 23:11:46+09:00




# Lowest Common Ancestor

This struct calculates the lowest common ancestors of pairs of vertices in a tree.

## Methods

- `LCA(vector<vector<int>>& G, int root)`
    - Builds a lookup table.
    - Time complexity: $O(n\lg n)$
- `int query(int u, int v)`
    - Returns the lowest common ancestor of $u$ and $v$.
    - Time complexity: $O(\lg n)$
- `int dist(int u, int v)`
    - Calculates the distance between $u$ and $v$.
    - Time complexity: $O(\lg n)$

## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_C.test.cpp.html">test/aoj/GRL_5_C.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Lowerst Common Ancestor
 * @docs docs/tree/lca.md
 */
struct LCA {
public:
    LCA(vector<vector<int>>& G, int root) : G(G), depth(G.size()), LOG(32 - __builtin_clz(G.size())) {
        int V = G.size();
        table.assign(LOG, vector<int>(V, -1));

        dfs(root, -1, 0);

        for (int k = 0; k < LOG - 1; k++) {
            for (int v = 0; v < V; v++) {
                if (table[k][v] >= 0) {
                    table[k+1][v] = table[k][table[k][v]];
                }
            }
        }
    }

    int query(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);

        // go up to the same depth
        for (int k = 0; k < LOG; k++) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = table[k][v];
            }
        }
        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; k--) {
            if (table[k][u] != table[k][v]) {
                u = table[k][u];
                v = table[k][v];
            }
        }
        return table[0][u];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[query(u, v)];
    }

private:
    const int LOG;
    const vector<vector<int>>& G;
    vector<vector<int>> table;
    vector<int> depth;

    void dfs(int v, int p, int d) {
        table[0][v] = p;
        depth[v] = d;
        for (int c : G[v]) {
            if (c != p) dfs(c, v, d + 1);
        }
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "tree/lca.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Lowerst Common Ancestor
 * @docs docs/tree/lca.md
 */
struct LCA {
public:
    LCA(vector<vector<int>>& G, int root) : G(G), depth(G.size()), LOG(32 - __builtin_clz(G.size())) {
        int V = G.size();
        table.assign(LOG, vector<int>(V, -1));

        dfs(root, -1, 0);

        for (int k = 0; k < LOG - 1; k++) {
            for (int v = 0; v < V; v++) {
                if (table[k][v] >= 0) {
                    table[k+1][v] = table[k][table[k][v]];
                }
            }
        }
    }

    int query(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);

        // go up to the same depth
        for (int k = 0; k < LOG; k++) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = table[k][v];
            }
        }
        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; k--) {
            if (table[k][u] != table[k][v]) {
                u = table[k][u];
                v = table[k][v];
            }
        }
        return table[0][u];
    }

    int dist(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[query(u, v)];
    }

private:
    const int LOG;
    const vector<vector<int>>& G;
    vector<vector<int>> table;
    vector<int> depth;

    void dfs(int v, int p, int d) {
        table[0][v] = p;
        depth[v] = d;
        for (int c : G[v]) {
            if (c != p) dfs(c, v, d + 1);
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
