#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;

int sum13(int x) {
    int s = 0;
    while (x) s += x % 10, x /= 10;

    return s % 13;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end(), [](const int & a, const int & b) -> bool {
                if (sum13(a) == sum13(b)) return a > b;
                else return sum13(a) > sum13(b);
            });
    
    for (int i = 0; i < m; i++)
        cout << a[i] << nl;

}
