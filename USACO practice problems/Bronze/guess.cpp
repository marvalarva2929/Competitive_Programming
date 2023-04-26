using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
set<int> traitsOf[100];

int set_union_size(set<int> a, set<int> b) {
    int ret = 0;
    for (int i : a)
        if (b.find(i) != b.end())
            ret++;
    return ret; 
}

signed main() {
    ifstream cin("guess.in");
    ofstream cout("guess.out");

    int traitcount = 1;
    unordered_map<string, int> tn;

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string _; cin >> _;
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            string trait; cin >> trait;
            if (!tn[trait]) tn[trait] = traitcount++;
            traitsOf[i].insert(tn[trait]);
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j)
                ans = max(ans, set_union_size(traitsOf[i], traitsOf[j]));
        }
    }

    cout << ++ans << nl;
}