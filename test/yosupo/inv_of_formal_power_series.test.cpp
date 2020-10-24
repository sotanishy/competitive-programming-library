#define PROBLEM "https://judge.yosupo.jp/problem/inv_of_formal_power_series"

#include "../../math/modint.cpp"
#include "../../math/formal_power_series.cpp"

#include <bits/stdc++.h>
using namespace std;

using mint = Modint<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    FormalPowerSeries<mint> f(N);
    for (int i = 0; i < N; ++i) cin >> f[i];
    auto g = f.inv();
    for (int i = 0; i < N; ++i) cout << g[i] << (i < N - 1 ? " " : "\n");
}
