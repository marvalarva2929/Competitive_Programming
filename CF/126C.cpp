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
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;


class KMP_Prefix {
    private:

    int ctoi(char a) { return (int)a - 97; } 
    string s;

    public:

    KMP_Prefix(string in) {
        s = in;
    }

    vector<int> prefixFunction() {
        int n = s.size();
        string pattern = s;
        vector<int> p(s.size());
        vector<int> temp(26, 0);
        vector<vector<int>> dfa(pattern.size(), temp); 
        int x = 0;
        dfa[0][ctoi(pattern[0])] = 1;
        for (int i = 1; i < pattern.size(); i++) {
            dfa[i] = dfa[x];
            dfa[i][ctoi(pattern[i])] = i + 1;
            // cout << x << nl;
            x = dfa[x][ctoi(pattern[i])];
            // cout << i << ": " << ctoi(pattern[i]) << ": " << x << nl;
        }
        int j = 0;
        for (int i = 1; i < s.size(); i++) {
            j = dfa[j][ctoi(s[i])];
            p[i] = j;
        }
        return p;               
    }
};

int32_t main() {
    string s;
    cin >> s;
    int n = s.size();
    KMP_Prefix kp(s);
    vector<int> p = kp.prefixFunction();

    if (p[n - 1] == 0) {
        cout << "Just a legend" << nl;
        return 0;
    }

    // print(p, 0, na - 1);

    int check = p[n - 1];
    // cout << check << nl;
    for (int i = 0; i < p.size() - 1; i++)
        if (p[i] == check) {
            // cout << i << ": " << p[i] << nl;
            cout << s.substr(0, p[i]) << nl;
            return 0;
        }
    
    int check2 = p[p[n - 1] - 1];
    // cout << check2 << nl;
    if (check2 == 0) {
        cout << "Just a legend" << nl;
        return 0;
    } else cout << s.substr(0, check2) << nl;
} 