#include <bits/stdc++.h>
#define int long long
#define pi pair<int, int>
#define ff first
#define ss second
#define nl " \n"

using namespace std;
const int mxn = 350;
int a[mxn];
ifstream fin, fin2;
string suff;

void solve() {
    int n, k; fin >> n >> k;
    for (int i = 0; i < n; i++) {
        char c; fin >> c;
        a[i] = (c == 'C');
    }
    
    int l = 0, r = n - 1;
    int o = 0, t = 0;
    int i = 1;
    
    string ans;
    while (l <= r) {
        if (!a[l]) { l++; i^= 1; continue; }
        if (!a[r]) { r--; i^= 1; continue; }
        else {
            o += i, t += !i;

            if (o >= k) { ans = "NE"; break; }
            else if (t >= k) { ans = "DA"; break; }
            r--;
            i ^= 1;
        }
    }

    string aans; fin2 >> aans;
    cout << suff << " " << ans << " : " << aans << nl;
}

signed main() {
    
    for (int i = 1; i <= 3; i++) 
        for (char j = 'a'; j <= 'f'; j++) {
            suff = to_string(i) + j;
            fin = ifstream("contest1_testdata/kamencici/kamencici.in." + suff);
            fin2 = ifstream("contest1_testdata/kamencici/kamencici.out." + suff);
            solve();
        }
}
