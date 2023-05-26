#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

const int mxn = 5e5;
int a[mxn];
bool seen[26];
vector<int> occ[26];
pair<pi, pi> border[mxn];
vector<int> order;

bool check(string a, string b, char t) {
    int i = 0, j = 0;
    while (j < b.size()) {
        if (i == a.size()) return false;
        int l2 = b[j];
       
        while (i < a.size() && a[i] == t) i++;

        if (i == a.size() || l2 != a[i]) return false;
        
        i++; 
        j++;
       
        while (i < a.size() && a[i] == t) i++;
    }
    if (i != a.size()) return false;

    return true;
}

void solve() {
    string s; cin >> s;
    int n = s.size();
    fill(border, border + n, make_pair(make_pair(INT_MIN, INT_MAX), make_pair(INT_MIN, INT_MAX)));
    fill(occ, occ + 26, vector<int>());
    fill(seen, seen + 26, 0);
    order.clear();

    for (int i = 0; i < n; i++)
        a[i] = s[i] - 'a',
        occ[a[i]].push_back(i);

    for (int i = n - 1; i >= 0; i--)
        if (!seen[a[i]])
            order.push_back(a[i]),
            seen[a[i]] = true;

    reverse(order.begin(), order.end());
    
    for (int i = 0; i < order.size(); i++) {
        int let = order[i]; 
        if (occ[let].size() % (i + 1)) {
            cout << -1 << nl;
            return;
        } else { 
            int add = occ[let].size() / (i + 1);
            for (int j = 0; j < occ[let].size(); j += add) {
                pi f = {(j ? occ[let][j - 1] + 1 : 0), occ[let][j]}; 
                pi s = {occ[let][j + add - 1], (j + add < occ[let].size()) ? occ[let][j + add] - 1 : n - 1};
                border[j/add].ff.ff = max(border[j/add].ff.ff, f.ff);
                border[j/add].ff.ss = min(border[j/add].ff.ss, f.ss);
                border[j/add].ss.ff = max(border[j/add].ss.ff, s.ff);
                border[j/add].ss.ss = min(border[j/add].ss.ss, s.ss);
            }
        }
    } 
    
    for (int i = 0; i < order.size() - 1; i++) {
        int ll = border[i].ss.ff;
        int lg = border[i].ss.ss;
        int gl = border[i + 1].ff.ff;
        int gg = border[i + 1].ff.ss;
            
        if (lg + 1 >= gl && lg + 1 <= gg)
            border[i + 1].ff.ss = lg + 1;
        else {
            cout << -1 << nl;
            return;
        }
    }
    
    for (int i = 0; i < order.size() - 1; i++) { 
        string s1 = s.substr(border[i].ff.ss, (border[i].ss.ss - border[i].ff.ss + 1));
        string s2 = s.substr(border[i + 1].ff.ss, (border[i + 1].ss.ss - border[i + 1].ff.ss + 1));
        if (!check(s1, s2, (char)(order[i] + 'a'))) {
            cout << -1 << nl;
            return;
        }
    }

    cout << s.substr(0, border[0].ss.ss + 1) << " ";
    for (int i = 0; i < order.size(); i++)
        cout << (char)('a' + order[i]);

    cout << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        solve();
}
