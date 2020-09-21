#include <bits/stdc++.h>
using namespace std;

// monoids

struct AddMonoid {
    using T = int;
    inline static const T id = 0;
    static T op(T a, T b) {
        return a + b;
    }
};

struct MinMonoid {
    using T = int;
    inline static const T id = (1u << 31) - 1;
    static T op(T a, T b) {
        return min(a, b);
    }
};

struct AddRangeMonoid {
    using T = pair<int, int>;
    inline static const T id = {0, 0};
    static T op(T a, T b) {
        return {a.first + b.first, a.second + b.second};
    }
};

struct UpdateMonoid {
    using T = int;
    inline static const T id = -1;
    static T op(T a, T b) {
        return b;
    }
};

struct AffineMonoid {
    using T = pair<int, int>;
    inline static const T id = {1, 0};
    static T op(T a, T b) {
        return {a.first * b.first, a.second * b.first + b.second};
    }
};

// actions

AddRangeMonoid::T act(AddRangeMonoid::T a, AffineMonoid::T b) {
    return {a.first * b.first + a.second * b.second, a.second};
}