#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Minimum Cost Flow
 * @docs docs/flow/min_cost_flow.md
 */
template <typename Cap, typename Cost>
struct MinCostFlow {
public:
    MinCostFlow(int V) : V(V), G(V) {}

    void add_edge(int u, int v, Cap cap, Cost cost) {
        G[u].emplace_back(v, cap, cost, G[v].size());
        G[v].emplace_back(u, 0, -cost, G[u].size() - 1);
    }

    Cost min_cost_flow(int s, int t, Cap f) {
        int ret = 0;
        vector<Cost> dist(V), h(V);
        vector<int> prevv(V), preve(V);
        using P = pair<Cost, int>;
        priority_queue<P, vector<P>, greater<P>> pq;

        while (f > 0) {
            // update h using dijkstra
            fill(dist.begin(), dist.end(), INF);
            dist[s] = 0;
            pq.emplace(0, s);
            while (!pq.empty()) {
                Cost d;
                int v;
                tie(d, v) = pq.top();
                pq.pop();
                if (dist[v] < d) continue;
                for (int i = 0; i < G[v].size(); i++) {
                    Edge& e = G[v][i];
                    Cost ndist = dist[v] + e.cost + h[v] - h[e.to];
                    if (e.cap > 0 && dist[e.to] > ndist) {
                        dist[e.to] = ndist;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        pq.emplace(dist[e.to], e.to);
                    }
                }
            }

            if (dist[t] == INF) return -1;
            for (int v = 0; v < V; v++) h[v] += dist[v];

            Cap m = f;
            int v = t;
            for (int v = t; v != s; v = prevv[v]) {
                m = min(m, G[prevv[v]][preve[v]].cap);
            }
            f -= m;
            ret += m * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                Edge& e = G[prevv[v]][preve[v]];
                e.cap -= m;
                G[v][e.rev].cap += m;
            }
        }
        return ret;
    }

private:
    struct Edge {
        int to;
        Cap cap;
        Cost cost;
        int rev;
        Edge(int to, Cap cap, Cost cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) {}
    };

    const Cost INF = numeric_limits<Cost>::max() / 2;

    int V;
    vector<vector<Edge>> G;
};