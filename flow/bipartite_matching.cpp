#pragma once
#include <algorithm>
#include <vector>

class BipartiteMatching {
public:
    BipartiteMatching() = default;
    explicit BipartiteMatching(int n) : G(n), used(n), match(n) {}

    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    int bipartite_matching() {
        int res = 0;
        std::fill(match.begin(), match.end(), -1);
        for (int v = 0; v < (int) G.size(); ++v) {
            if (match[v] == -1) {
                std::fill(used.begin(), used.end(), false);
                if (dfs(v)) ++res;
            }
        }
        return res;
    }

    std::vector<std::pair<int, int>> get_edges() {
        std::vector<std::pair<int, int>> ret;
        for (int i = 0; i < (int) G.size(); ++i) {
            if (i < match[i]) ret.emplace_back(i, match[i]);
        }
        return ret;
    }

private:
    std::vector<std::vector<int>> G;
    std::vector<bool> used;
    std::vector<int> match;

    bool dfs(int u) {
        used[u] = true;
        for (int v : G[u]) {
            int w = match[v];
            if (w == -1 || (!used[w] && dfs(w))) {
                match[u] = v;
                match[v] = u;
                return true;
            }
        }
        return false;
    }
};