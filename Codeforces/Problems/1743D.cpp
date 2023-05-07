using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

const int mxn = (int)1e6 + 10;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

string withoutLead(string a) {
    int pos = a.find_first_not_of('0');
    if (pos == string::npos)
        return "0";
    else return a.substr(pos);

}

string shift(string x, int s, int t) {
    string ret = x;
    int n = x.size();
    ret = ret.substr(s, n - t);
    return ret;
}

string operator |(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string c;
    if (a.size() < b.size())
        swap(a, b);
    c = a;

    for (int i = 0; i < b.size(); i++)
        if (b[i] & 1)
            c[i] = '1';

    reverse(c.begin(), c.end());

    return withoutLead(c);
}



bool better(string & a, string & b) {
    a = withoutLead(a);
    b = withoutLead(b);
    if (a.size() != b.size()) return a.size() > b.size();
    else return a > b;
}

string b;
string a;

void solve() {
    int n; cin >> n;
    cin >> a;   
    a = withoutLead(a);
    string ans = a;
    int s = a.find('1');
    n = a.size();
    // while (true) {
    //     string a, b; cin >> a >> b;
    //     cout << (a | b) << nl;
    // }

    if (s != string::npos) {
        int t = a.find('0', s);
        if (t != string::npos) {
            // cout << s << " " << t << nl;
            int cur = s;
            int cut = 0;
            while (true) {
                if (cur == n || (a[cur] == '1' && cur > t)) break;
                string check = (a | (a.substr(s, n - s - cut)));
                // cout << cut << " " << a.substr(s, n - s - cut - 1) << nl;
                if (better(check, ans))
                    ans = check;
                cur++;
                cut++;
            }        
        }
    }

    cout << withoutLead(ans) << nl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t = 1;
    while (t--)
        solve();
}