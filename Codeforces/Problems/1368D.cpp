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
#define MAX (int)2e5 + 10
int a[MAX];
set<int, greater<int>> withBit[21];

void printbin(int x, int maxl) {
    for (int i = maxl; i >= 0; i--)
        if ((x >> i)&1)
            cout << '1';
        else 
            cout << '0';
    cout << " : " << fixed << pow(x, 2) << nl;
}

int32_t main() {
    int n; cin >> n;
    int maxl = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxl = max((int)log2(a[i]), maxl);
    }

    sort(a, a + n);
    for (int i = 0; i <= maxl; i++) {
        vector<int> withBitI;
        for (int j = 0; j < n; j++) 
            if ((a[j] >> i)&1) {
                withBitI.push_back(j);
                a[j] -= pow(2, i);
            }
        int count = 0;
        for (int j = n - 1; j >= 0 && count < withBitI.size(); j--) 
            if (!((a[j] >> i)&1)) {
                a[j] += pow(2, i);
                count++;
            }
    }


    int ans = 0;
    for (int i = 0; i < n; i++) 
        ans += a[i] * a[i];
    
    cout << ans << nl;
} 