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
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;


int32_t main() {
    int n, ans = 0;
    cin >> n;
    vector<int> flowers(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> flowers[i];
    
    vector<int> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; i++) 
        pref[i] += pref[i - 1] + flowers[i];

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) {
            int length = abs(i - j) + 1;
            int petals = (i >= j) ? (pref[i] - pref[j - 1]) : (pref[j] - pref[i - 1]);
            double average = (double)petals/(double)length;
            // cout << i << ": " << j << " : " << average << nl;
            for (int k = i; k <= j; k++)
                if (flowers[k] == average) {
                    ans++;
                    // cout << i << " : " << j << nl;
                    break;
                } 
        }

    cout << ans << nl;
} 