---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/matrix/matrix.cpp
    title: Matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/system_of_linear_equations.test.cpp
    title: test/yosupo/system_of_linear_equations.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/system_of_linear_equations.cpp\"\n#include <cassert>\n\
    #include <vector>\n#line 2 \"math/matrix/matrix.cpp\"\n#include <algorithm>\n\
    #line 4 \"math/matrix/matrix.cpp\"\n#include <cmath>\n#include <initializer_list>\n\
    #include <type_traits>\n#line 8 \"math/matrix/matrix.cpp\"\n\ntemplate <typename\
    \ T>\nclass Matrix {\npublic:\n    static Matrix concat(const Matrix& A, const\
    \ Matrix& B) {\n        assert(A.m == B.m);\n        Matrix C(A.m, A.n + B.n);\n\
    \        for (int i = 0; i < A.m; ++i) {\n            std::copy(A[i].begin(),\
    \ A[i].end(), C[i].begin());\n            std::copy(B[i].begin(), B[i].end(),\
    \ C[i].begin() + A.n);\n        }\n        return C;\n    }\n\n    Matrix() =\
    \ default;\n    Matrix(int m, int n) : mat(m, std::vector<T>(n)), m(m), n(n) {}\n\
    \    Matrix(std::initializer_list<std::initializer_list<T>> list) {\n        for\
    \ (auto& l : list) mat.emplace_back(l);\n        m = mat.size();\n        n =\
    \ mat[0].size();\n    }\n\n    int row() const { return m; }\n    int col() const\
    \ { return n; }\n\n    const std::vector<T>& operator[](int i) const { return\
    \ mat[i]; }\n    std::vector<T>& operator[](int i) { return mat[i]; }\n\n    Matrix&\
    \ operator+=(const Matrix& rhs) {\n        assert(m == rhs.m && n == rhs.n);\n\
    \        for (int i = 0; i < m; ++i) {\n            for (int j = 0; j < n; ++j)\
    \ {\n                mat[i][j] += rhs[i][j];\n            }\n        }\n     \
    \   return *this;\n    }\n\n    Matrix& operator-=(const Matrix& rhs) {\n    \
    \    assert(m == rhs.m && n == rhs.n);\n        for (int i = 0; i < m; ++i) {\n\
    \            for (int j = 0; j < n; ++j) {\n                mat[i][j] -= rhs[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n\n    Matrix operator+(const\
    \ Matrix& rhs) const { return Matrix(*this) += rhs; }\n    Matrix operator-(const\
    \ Matrix& rhs) const { return Matrix(*this) -= rhs; }\n\n    Matrix transpose()\
    \ const {\n        Matrix ret(n, m);\n        for (int i = 0; i < n; ++i) {\n\
    \            for (int j = 0; j < m; ++j) {\n                ret[i][j] = mat[j][i];\n\
    \            }\n        }\n        return ret;\n    }\n\n    Matrix matmul(const\
    \ Matrix& B) const {\n        assert(n == B.m);\n        Matrix ret(m, B.n);\n\
    \        for (int i = 0; i < m; ++i) {\n            for (int j = 0; j < B.n; ++j)\
    \ {\n                for (int k = 0; k < n; ++k) {\n                    ret[i][j]\
    \ += mat[i][k] * B[k][j];\n                }\n            }\n        }\n     \
    \   return ret;\n    }\n\n    Matrix rref() const {\n        Matrix A(*this);\n\
    \        int pivot = 0;\n        for (int j = 0; j < n; ++j) {\n            int\
    \ i = pivot;\n            while (i < m && eq(A[i][j], T(0))) ++i;\n          \
    \  if (i == m) continue;\n\n            if (i != pivot) A[i].swap(A[pivot]);\n\
    \n            T p = A[pivot][j];\n            for (int l = j; l < n; ++l) A[pivot][l]\
    \ /= p;\n\n            for (int k = 0; k < m; ++k) {\n                if (k ==\
    \ pivot) continue;\n                T v = A[k][j];\n                for (int l\
    \ = j; l < n; ++l) {\n                    A[k][l] -= A[pivot][l] * v;\n      \
    \          }\n            }\n\n            ++pivot;\n        }\n        return\
    \ A;\n    }\n\n    int rank() const {\n        auto A = rref();\n        for (int\
    \ i = 0; i < m; ++i) {\n            bool nonzero = false;\n            for (int\
    \ j = 0; j < n; ++j) {\n                if (!eq(A[i][j], T(0))) {\n          \
    \          nonzero = true;\n                    break;\n                }\n  \
    \          }\n            if (!nonzero) return i;\n        }\n        return m;\n\
    \    }\n\n    template <typename U, typename std::enable_if<std::is_floating_point<U>::value>::type*\
    \ = nullptr>\n    static constexpr bool eq(U a, U b) { return std::abs(a - b)\
    \ < 1e-8; }\n\n    template <typename U, typename std::enable_if<!std::is_floating_point<U>::value>::type*\
    \ = nullptr>\n    static constexpr bool eq(U a, U b) { return a == b; }\n\nprotected:\n\
    \    std::vector<std::vector<T>> mat;\n    int m, n;\n};\n#line 5 \"math/system_of_linear_equations.cpp\"\
    \n\ntemplate <typename T>\nstd::vector<std::vector<T>> solve_system(const Matrix<T>\
    \ A, const std::vector<T>& b) {\n    int m = A.row(), n = A.col();\n    assert(m\
    \ == (int) b.size());\n    Matrix<T> bb(m, 1);\n    for (int i = 0; i < m; ++i)\
    \ bb[i][0] = b[i];\n    auto sol = Matrix<T>::concat(A, bb).rref();\n\n    std::vector<bool>\
    \ independent(n);\n    std::vector<std::vector<T>> ret(1, std::vector<T>(n));\n\
    \    std::vector<std::vector<T>> bases(n, std::vector<T>(n));\n    for (int j\
    \ = 0; j < n; ++j) bases[j][j] = 1;\n    int j = 0;\n    for (int i = 0; i < m;\
    \ ++i) {\n        for (; j < n; ++j) {\n            if (Matrix<T>::eq(sol[i][j],\
    \ T(1))) {\n                independent[j] = true;\n                for (int k\
    \ = j + 1; k < n; ++k) {\n                    bases[k][j] = -sol[i][k];\n    \
    \            }\n                ret[0][j] = sol[i][n];\n                break;\n\
    \            }\n        }\n        if (j == n && !Matrix<T>::eq(sol[i][n], T(0)))\
    \ return {};\n    }\n    for (int j = 0; j < n; ++j) {\n        if (!independent[j])\
    \ ret.push_back(bases[j]);\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"matrix/matrix.cpp\"\
    \n\ntemplate <typename T>\nstd::vector<std::vector<T>> solve_system(const Matrix<T>\
    \ A, const std::vector<T>& b) {\n    int m = A.row(), n = A.col();\n    assert(m\
    \ == (int) b.size());\n    Matrix<T> bb(m, 1);\n    for (int i = 0; i < m; ++i)\
    \ bb[i][0] = b[i];\n    auto sol = Matrix<T>::concat(A, bb).rref();\n\n    std::vector<bool>\
    \ independent(n);\n    std::vector<std::vector<T>> ret(1, std::vector<T>(n));\n\
    \    std::vector<std::vector<T>> bases(n, std::vector<T>(n));\n    for (int j\
    \ = 0; j < n; ++j) bases[j][j] = 1;\n    int j = 0;\n    for (int i = 0; i < m;\
    \ ++i) {\n        for (; j < n; ++j) {\n            if (Matrix<T>::eq(sol[i][j],\
    \ T(1))) {\n                independent[j] = true;\n                for (int k\
    \ = j + 1; k < n; ++k) {\n                    bases[k][j] = -sol[i][k];\n    \
    \            }\n                ret[0][j] = sol[i][n];\n                break;\n\
    \            }\n        }\n        if (j == n && !Matrix<T>::eq(sol[i][n], T(0)))\
    \ return {};\n    }\n    for (int j = 0; j < n; ++j) {\n        if (!independent[j])\
    \ ret.push_back(bases[j]);\n    }\n    return ret;\n}"
  dependsOn:
  - math/matrix/matrix.cpp
  isVerificationFile: false
  path: math/system_of_linear_equations.cpp
  requiredBy: []
  timestamp: '2021-03-30 13:20:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/system_of_linear_equations.test.cpp
documentation_of: math/system_of_linear_equations.cpp
layout: document
redirect_from:
- /library/math/system_of_linear_equations.cpp
- /library/math/system_of_linear_equations.cpp.html
title: math/system_of_linear_equations.cpp
---