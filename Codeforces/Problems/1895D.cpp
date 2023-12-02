#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 2e5, mxb = 20;
int a[mxn], cnt[mxb];
bitset<mxn> b[mxb];

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++)
        cin >> a[i];
    
    for (int i = 0; i < n; i++) {
        int x = i;
        int ct = 0;
        while (x) 
            cnt[ct++] += (x & 1), x >>= 1;
    }

    for (int j = 0; j < mxb; j++)
        for (int i = 1; i < n; i++) {
            b[j][i] = b[j][i - 1];
            int ata = (a[i - 1] >> j) & 1; 
            if (ata) b[j][i].flip();
        }
    
    for (int j = 0; j < mxb; j++)
        if (b[j].count() != cnt[j]) 
            b[j].flip();
    
    for (int i = 0; i < n; i++) {
        int bi = 0;
        for (int j = 0; j < mxb; j++)
            if (b[j][i]) bi += (1 << j);
        cout << bi << " ";
    }
    cout << nl;
}
