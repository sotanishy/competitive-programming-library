#include <bits/stdc++.h>
#include "mod_pow.cpp"
using namespace std;

// returns x such that a^x = b (mod p)
int mod_log(long long a, long long b, long long p) {
    int m = sqrt(p) + 1;
    vector<long long> baby(m);
    unordered_map<long long, int> baby_index;
    long long x = 1;
    for (int i = 0; i < m; i++) {
        baby[i] = x;
        baby_index[x] = i;
        x = x * a % p;
    }

    vector<long long> giant(m);
    long long c = mod_inv(mod_pow(a, m, p), p);
    x = 1;
    for (int i = 0; i < m; i++) {
        giant[i] = x;
        x = x * c % p;
    }

    for (int i = 0; i < m; i++) {
        long long y = b * giant[i] % p;
        if (baby_index.count(y) > 0) {
            return i * m + baby_index[y];
        }
    }
    return -1;
}