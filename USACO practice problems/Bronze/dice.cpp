using namespace std;
#include <bits/stdc++.h>
#include <string.h>
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
#define pb push_back
#define int long long
#define nl '\n'
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define f first
#define s second
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

bool beats(vector<int> a, vector<int> b) {
    int abb = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            if (a[i] > b[j]) abb++;
            else if (a[i] < b[j]) abb--;
        }

    return (abb > 0);
}

void solve() {
    vector<int> a(4);
    vector<int> b(4);
    for (int i = 0; i < 4; i++)
        cin >> a[i];
    for (int i = 0; i < 4; i++)
        cin >> b[i];

    for (int i = 1; i <= 10; i++) 
        for (int j = 1; j <= 10; j++)
            for (int k = 1; k <= 10; k++)
                for (int l = 1; l <= 10; l++) {
                    vector<int> c = {i, j, k, l};
                    if ((beats(a, b) && beats(b, c) && beats(c, a)) || (beats(a, c) && beats(b, a) && beats(c, b))) {
                        cout << "yes" << nl;
                        return;
                    }
                }
    
    cout << "no" << nl;
    return;
                    
    
}


int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
} 