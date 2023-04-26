using namespace std;
#include <bits/stdc++.h>
#define nl '\n'
// #define int long long

void solve() {
    int n, m; cin >> n >> m;
    int in[m][n] = {};
    int out[m] = {};
     
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            in[i][j] = c&1;
        }
        cin >> out[i];
    }

    int finished[m] = {};

    for (int i = 0; i < 2 * n; i++) {
        for (int bit = 0; bit < n; bit++) {

            for (int output = 0; output < 2; output++) {
                bool outputs[2] = {};

                for (int l = 0; l < m; l++) 
                    if (!finished[l]) 
                        if (in[l][bit] == output)
                            outputs[out[l]] = true;
                
                // cout << bit << " " << outputs[0] << " " << outputs[1] << nl;

                if (outputs[0] != outputs[1]) {
                    for (int l = 0; l < m; l++)
                        if (in[l][bit] == output)   
                            finished[l] = true;
                }

            }
        }
    }

    cout << (count(finished, finished + m, true) == m ? "OK" : "LIE") << nl;

    return;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while (t--)
        solve();
}