#include <bits/stdc++.h>
#define int long long
#define nl '\n'

using namespace std;

int power(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1)
            ans *= a;
        a *= a;
        b >>= 1;
    }

    return ans;
}

bool matches(string s, string t) {
    char X = '#'; 
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '_') continue;
        if (s[i] == 'X' && X != '#' && t[i] != X) return false;
        else if (s[i] == 'X') X = t[i];
        else if (s[i] != t[i]) return false;
    }
    return true;
}

signed main() {

    string s; cin >> s;
    int n = s.size();

    int lo = power(10, n - 1);
    int hi = power(10, n) - 1;

    if (lo == 1) lo--;
    while (lo % 25) lo++;
    int ans = 0;
    
    for (; lo <= hi; lo += 25) 
        ans += matches(s, to_string(lo)); 

    cout << ans << nl;
}
