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
#define print(x) for (auto a : x) {cout << a << " ";} cout << nl;

int32_t main() {
    int n;
    unordered_map<int, set<char>> dice;
    cin >> n;
    string d1, d2, d3, d4;
    cin >> d1 >> d2 >> d3 >> d4;
    for (char d : d1) dice[0].insert(d);
    for (char d : d2) dice[1].insert(d);
    for (char d : d3) dice[2].insert(d);
    for (char d : d4) dice[3].insert(d);
    for (int i = 0; i < n; i++) {
        string spell;
        cin >> spell;
        vector<int> diec(4);
        iota(diec.begin(), diec.end(), 0);
        int m = spell.size();
        bool yes = false;
        while (true) {
            bool tworked = true;
            for (int i = 0; i < spell.size(); i++) {
                if (dice[diec[i]].count(spell[i]) == 0) {tworked = false; break;}
            }
            // print(diec);
            if (tworked) { yes = true; break; }
            if (!next_permutation(diec.begin(), diec.end())) break;
        }
        if (yes) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

} 
