#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = (1 << 19), MOD = 998244353;
int fact[mxn + 1];
int n;

int power(int a, int b) {
    int ans = 1;
    a %= MOD;

    while (b) {
        if (b & 1) ans = ans * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }
    
    return ans % MOD;
}

int rec(int k, vector<int> sg) {
    int b = 0, c = 0;
    if (sg.size() == 1) return 1;
        
    vector<int> nsg;

    for (int i = 0; i < sg.size(); i += 2) {
        int f = sg[i], s = sg[i + 1];         
        bool iff = f <= (sg.size() >> 1), 
             iss = s <= (sg.size() >> 1); 
        
        if (f == -1 && s == -1) b++, c++, nsg.push_back(-1);
        else if (f == -1) {
            if (iss) nsg.push_back(s), c++;
            else nsg.push_back(-1); 
        } else if (s == -1) {
            if (iff) nsg.push_back(f), c++;
            else nsg.push_back(-1);
        } else if (iff && !iss) nsg.push_back(f);
        else if (iss && !iff) nsg.push_back(s);
        else return 0;
    }
    
    return (power(2, b) * fact[c] % MOD) * rec(k + 1, nsg) % MOD;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;

    fact[0] = 1;
    for (int i = 1; i <= (1 << n); i++)
        fact[i] = fact[i - 1] * i % MOD;

    vector<int> a(1 << n);
    for (int i = 0; i < (1 << n); i++)
        cin >> a[i]; 
   
    cout << rec(0, a) % MOD << nl;
} 
