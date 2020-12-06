#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <typename T>
void fzt(std::vector<T>& a, bool subset) {
    int k = 31 - __builtin_clz(a.size());
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < (1 << k); ++j) {
            if ((j >> i & 1) == subset) a[j] += a[j ^ (1 << i)];
        }
    }
}

template <typename T>
void fmt(std::vector<T>& a, bool subset) {
    int k = 31 - __builtin_clz(a.size());
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < (1 << k); ++j) {
            if ((j >> i & 1) == subset) a[j] -= a[j ^ (1 << i)]
        }
    }
}

template <typename T>
void divisor_fzt(std::vector<T>& a, bool subset) {
    int n = a.size();
    std::vector<bool> sieve(n, true);
    for (int p = 2; p < n; ++p) {
        if (!sieve[p]) continue;
        if (subset) {
            for (int k = 1; k * p < n; ++k) {
                sieve[k * p] = false;
                a[k * p] += a[k];
            }
        } else {
            for (int k = (n - 1) / p; k > 0; --k) {
                sieve[k * p] = false;
                a[k] += a[k * p];
            }
        }
    }
}

template <typename T>
void divisor_fmt(std::vector<T>& a, bool subset) {
    int n = a.size();
    std::vector<bool> sieve(n, true);
    for (int p = 2; p < n; ++p) {
        if (!sieve[p]) continue;
        if (subset) {
            for (int k = (n - 1) / p; k > 0; --k) {
                sieve[k * p] = false;
                a[k * p] -= a[k];
            }
        } else {
            for (int k = 1; k * p < n; ++k) {
                sieve[k * p] = false;
                a[k] -= a[k * p];
            }
        }
    }
}

template <typename T>
void fht(std::vector<T>& a) {
    int n = a.size();
    for (int h = 1; h < n; h <<= 1) {
        for (int i = 0; i < n; i += h << 1) {
            for (int j = i; j < i + h; ++j) {
                int x = a[j];
                int y = a[j | h];
                a[j] = x + y;
                a[j | h] = x - y;
            }
        }
    }
}

template <typename T>
void ifht(std::vector<T>& a) {
    int n = a.size();
    for (int h = 1; h < n; h <<= 1) {
        for (int i = 0; i < n; i += h << 1) {
            for (int j = i; j < i + h; ++j) {
                int x = a[j];
                int y = a[j | h];
                a[j] = (x + y) / 2;
                a[j | h] = (x - y) / 2;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


}