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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/aoj/DSL_2_F.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_F.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-14 16:31:52+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data-structure/lazy_segment_tree.cpp.html">Segment Tree with Lazy Propagation <small>(data-structure/lazy_segment_tree.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include "../../data-structure/lazy_segment_tree.cpp"

struct M {
    using T = int;
    inline static const T id = (1u << 31) - 1;
    static T op(T a, T b) {
        return min(a, b);
    }
};

struct O {
    using T = int;
    inline static const T id = (1u << 31) - 1;
    static T op(T a, T b) {
        return b;
    }
};

M::T act(M::T a, O::T b) {
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    LazySegmentTree<M, O, act> st(n);
    for (int i = 0; i < q; i++) {
        int type, s, t;
        cin >> type >> s >> t;
        if (type == 0) {
            int x;
            cin >> x;
            st.update(s, t + 1, x);
        } else {
            cout << st.fold(s, t + 1) << "\n";
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_F.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#line 1 "data-structure/lazy_segment_tree.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Segment Tree with Lazy Propagation
 * @docs docs/data-structure/lazy_segment_tree.md
 */
template <typename M, typename O, typename M::T (*act)(typename M::T, typename O::T)>
struct LazySegmentTree {
    using T = typename M::T;
    using E = typename O::T;

    LazySegmentTree(int n) : LazySegmentTree(vector<T>(n, M::id)) {}
    LazySegmentTree(const vector<T>& v) {
        size = 1;
        height = 0;
        while (size < v.size()) size <<= 1, height++;
        node.resize(2 * size, M::id);
        lazy.resize(2 * size, O::id);
        copy(v.begin(), v.end(), node.begin() + size);
        for (int i = size - 1; i > 0; i--) node[i] = M::op(node[2 * i], node[2 * i + 1]);
    }

    T operator[](int k) {
        return fold(k, k + 1);
    }

    void update(int l, int r, const E& x) { update(l, r, x, 1, 0, size); }

    T fold(int l, int r) { return fold(l, r, 1, 0, size); }

private:
    int size, height;
    vector<T> node;
    vector<E> lazy;

    void push(int k) {
        if (lazy[k] == O::id) return;
        if (k < size) {
            lazy[2 * k] = O::op(lazy[2 * k], lazy[k]);
            lazy[2 * k + 1] = O::op(lazy[2 * k + 1], lazy[k]);
        }
        node[k] = act(node[k], lazy[k]);
        lazy[k] = O::id;
    }

    void update(int a, int b, const E& x, int k, int l, int r) {
        push(k);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] = O::op(lazy[k], x);
            push(k);
            return;
        }
        int m = (l + r) / 2;
        update(a, b, x, 2 * k, l, m);
        update(a, b, x, 2 * k + 1, m, r);
        node[k] = M::op(node[2 * k], node[2 * k + 1]);
    }

    T fold(int a, int b, int k, int l, int r) {
        push(k);
        if (r <= a || b <= l) return M::id;
        if (a <= l && r <= b) return node[k];
        int m = (l + r) / 2;
        return M::op(fold(a, b, 2 * k, l, m),
                     fold(a, b, 2 * k + 1, m, r));
    }
};
#line 4 "test/aoj/DSL_2_F.test.cpp"

struct M {
    using T = int;
    inline static const T id = (1u << 31) - 1;
    static T op(T a, T b) {
        return min(a, b);
    }
};

struct O {
    using T = int;
    inline static const T id = (1u << 31) - 1;
    static T op(T a, T b) {
        return b;
    }
};

M::T act(M::T a, O::T b) {
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    LazySegmentTree<M, O, act> st(n);
    for (int i = 0; i < q; i++) {
        int type, s, t;
        cin >> type >> s >> t;
        if (type == 0) {
            int x;
            cin >> x;
            st.update(s, t + 1, x);
        } else {
            cout << st.fold(s, t + 1) << "\n";
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
