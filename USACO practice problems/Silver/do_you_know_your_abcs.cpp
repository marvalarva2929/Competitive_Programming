#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 8;
int a[mxn];
int n;

void solve() {
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    n++;
    sort(a, a + n);

    set<pair<int, pi>> ans;    

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = 0; k < n; k++)
                for (int l = k + 1; l < n; l++)
                    for (int m = 0; m < n; m++)
                        for (int o = m + 1; o < n ; o++) {
                            int A = a[j] - a[i],
                                B = a[l] - a[k],
                                C = a[o] - a[m];
                            
                            if (A <= B && B <= C); 
                            else continue;

                            set<int> t = {A, B, C, A + B, A + C, B + C, A + B + C};
                            bool ret = 1;
                            for (int b = 1; b < n; b++)
                                ret &= t.count(a[b]);

                            if (ret) ans.insert({A, {B, C}}); 
                        }
    
    cout << ans.size() << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
