#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 1e5, mxa = 5e6;
int a[mxn];
vector<int> pr;
bool isc[mxa +1];
int mvs[mxa + 1];
int lrg[4];

void solve() {
    int n; cin >> n;
    int mn = INT_MAX;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (mvs[a[i]]/2 < mn/2) mn = mvs[a[i]];     
    }

    cout << (mn % 2 ? "Farmer John" : "Farmer Nhoj") << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    isc[1] = 0;
    mvs[0] = 0;
    mvs[1] = 1;
    mvs[2] = 1;
    mvs[3] = 1;
    
    lrg[1] = 1;
    lrg[0] = 0;

    pr.push_back(1);
    for (int i = 2; i <= mxa; i++) {
        if (!isc[i]) {
            pr.push_back(i);
            lrg[i % 4] = i; 
            for (int j = i + i; j <= mxa; j += i)
                isc[j] = 1;
        }
        
        if (i % 2) mvs[i] = (i - lrg[i % 4])/2 + 1;
        else mvs[i] = i/2; 
    }
    
    int t; cin >> t;
    while (t--)
        solve();
}

