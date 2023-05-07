#include <iostream>
#include <deque>
#define nl '\n'
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    deque<long long> d;
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        d.push_back(w);
    }
    int a = 0, b = 0, moves = 0, alice = 0, bob = 0;
    while (d.size() > 0) {
        moves++;
        a = 0;
        while (a <= b) {
            a += d.front();
            alice += d.front();
            d.pop_front();
            if (d.size() == 0) {
                cout << moves << " " << alice << " " << bob << nl;
                return;
            }
        }
        b = 0;
        moves++;
        while (b <= a) {
            b += d.back();
            bob += d.back();
            d.pop_back();
            if (d.size() == 0) {
                cout << moves << " " << alice << " " << bob << nl;
                return;
            }
        }
    }
    cout << moves << " " << alice << " " << bob << nl;
}
int32_t main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}