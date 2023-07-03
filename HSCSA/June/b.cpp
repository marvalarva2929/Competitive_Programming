#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

const int mxn = 1e5;
vector<int> a[mxn];

signed main() {
    int n; cin >> n;
       
    for (int i = 0; i < n; i++) {
        a[i].resize(3); 
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
        sort(a[i].begin(), a[i].end());
    }
    sort(a, a + n);
    
    for (int j = 0; j < 3; j++) {
        for (int i = 1; i < n; i++)
            if (a[i][j] <= a[i - 1][j]) {
                cout << "NO" << nl;
                return 0;
            }
    }
    
    cout << "YES" << nl;
}
