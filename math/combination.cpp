#include <bits/stdc++.h>
using namespace std;

struct Combination {
    long long mod;
    vector<long long> fact, fact_inv;

private:
    static long long mod_pow(long long n, long long p, long long mod) {
        long long ret = 1;
        while (p > 0) {
            if (p & 1) ret = ret * n % mod;
            n = n * n % mod;
            p >>= 1;
        }
        return ret;
    }

public:
    static long long C(int n, int r, long long mod) {
        long long num = 1, den = 1;
        for (int i = 1; i <= r; i++) {
            num = num * (n - i + 1) % mod;
            den = den * i % mod;
        }
        return num * mod_pow(den, mod - 2, mod) % mod;
    }

    Combination(int n, long long mod) : mod(mod), fact(n+1), fact_inv(n+1) {
        fact[0] = fact_inv[0] = 1;
        for (int i = 1; i <= n; i++) fact[i] = fact[i-1] * i % mod;
        fact_inv[n] = mod_pow(n, mod - 2, mod);
        for (int i = n; i > 0; i--) fact_inv[i-1] = fact_inv[i] * i % mod;
    }

    long long P(int n, int r) const {
        if (r < 0 || n < r) return 0;
        return fact[n] * fact_inv[n - r] % mod;
    }

    long long C(int n, int r) const {
        if (r < 0 || n < r) return 0;
        return fact[n] * fact_inv[r] % mod * fact_inv[n - r] % mod;
    }
}