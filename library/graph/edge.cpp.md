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


# :heavy_check_mark: graph/edge.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/edge.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 15:01:14+09:00




## Required by

* :heavy_check_mark: <a href="bellman_ford.cpp.html">Bellman-Ford Algorithm <small>(graph/bellman_ford.cpp)</small></a>
* :heavy_check_mark: <a href="dijkstra.cpp.html">Dijkstra's Algorithm <small>(graph/dijkstra.cpp)</small></a>
* :heavy_check_mark: <a href="kruskal.cpp.html">Kruskal's Algorithm <small>(graph/kruskal.cpp)</small></a>
* :heavy_check_mark: <a href="prim.cpp.html">Prim's Algorithm <small>(graph/prim.cpp)</small></a>
* :heavy_check_mark: <a href="../tree/tree_diameter.cpp.html">tree/tree_diameter.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_1_A.test.cpp.html">test/aoj/GRL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_1_B.test.cpp.html">test/aoj/GRL_1_B.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_2_A.kruskal.test.cpp.html">test/aoj/GRL_2_A.kruskal.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_2_A.prim.test.cpp.html">test/aoj/GRL_2_A.prim.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_A.test.cpp.html">test/aoj/GRL_5_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Edge {
    int from, to;
    T cost;
    Edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/edge.cpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Edge {
    int from, to;
    T cost;
    Edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

