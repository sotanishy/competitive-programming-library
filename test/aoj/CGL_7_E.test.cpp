#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E"
#define ERROR 0.00000001

#include "../../math/geometry.cpp"

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(10);

    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    Vec p1 = {x1, y1}, p2 = {x2, y2};
    auto ans = intersection_circles(p1, r1, p2, r2);
    if (ans.size() == 1) {
        cout << ans[0].real() << " " << ans[0].imag() << " ";
        cout << ans[0].real() << " " << ans[0].imag() << endl;
    } else {
        if (make_pair(ans[0].real(), ans[0].imag()) > make_pair(ans[1].real(), ans[1].real())) swap(ans[0], ans[1]);
        cout << ans[0].real() << " " << ans[0].imag() << " ";
        cout << ans[1].real() << " " << ans[1].imag() << endl;
    }
}