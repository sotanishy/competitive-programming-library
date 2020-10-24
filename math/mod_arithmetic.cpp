#pragma once
#include <cmath>
#include <numeric>
#include <unordered_map>

/*
 * @brief Modular Arithmetic
 * @docs docs/math/mod_arithmetic.md
 */

/*
 * Modular Exponentiation
 */
long long mod_pow(long long a, long long p, long long mod) {
    long long ret = 1;
    while (p > 0) {
        if (p & 1) ret = ret * a % mod;
        a = a * a % mod;
        p >>= 1;
    }
    return ret;
}

long long mod_inv(long long a, long long mod) {
    return mod_pow(a, mod - 2, mod);
}

/*
 * Discrete Logarithm
 */
int mod_log(long long a, long long b, int p) {
    a %= p;
    b %= p;
    long long k = 1, add = 0, g;
    while ((g = std::gcd(a, p)) > 1) {
        if (b == k) return add;
        if (b % g) return -1;
        b /= g;
        p /= g;
        ++add;
        k = k * a / g % p;
    }

    const int m = sqrt(p) + 1;
    std::unordered_map<long long, int> baby_index;
    long long baby = b;
    for (int i = 0; i <= m; ++i) {
        baby_index[baby] = i;
        baby = baby * a % p;
    }
    long long am = 1;
    for (int i = 0; i < m; ++i) am = am * a % p;
    long long giant = k;
    for (int i = 1; i <= m; ++i) {
        giant = giant * am % p;
        if (baby_index.count(giant)) {
            return i * m - baby_index[giant] + add;
        }
    }
    return -1;
}

/*
 * Quadratic Residue
 */
long long mod_sqrt(long long n, long long p) {
    if (n == 0) return 0;
    if (p == 2) return 1;
    if (std::gcd(n, p) != 1) return -1;
    if (mod_pow(n, (p - 1) / 2, p) == p - 1) return -1;
    int Q = p - 1, S = 0;
    while (!(Q & 1)) Q >>= 1, ++S;
    long long z = 2;
    while (true) {
        if (mod_pow(z, (p - 1) / 2, p) == p - 1) break;
        ++z;
    }
    int M = S;
    long long c = mod_pow(z, Q, p);
    long long t = mod_pow(n, Q, p);
    long long R = mod_pow(n, (Q + 1) / 2, p);
    while (t != 1) {
        int i = 0;
        long long s = t;
        while (s != 1) {
            s = s * s % p;
            ++i;
        }
        long long b = mod_pow(c, 1 << (M - i - 1), p);
        M = i;
        c = b * b % p;
        t = t * c % p;
        R = R * b % p;
    }
    return R;
}