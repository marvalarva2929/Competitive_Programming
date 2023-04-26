using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
int ans[8];
vector<pi> constraints;

bool satisfied() {

    // for (int i : ans)
    //     cout << i << " ";
    // cout << nl;

    for (auto constraint : constraints) {
        bool worked = 0;
        for (int i = 1; i < 8; i++)
            worked |= ((ans[i - 1] == constraint.first && ans[i] == constraint.second) || (ans[i - 1] == constraint.second && ans[i] == constraint.first));
        // cout << constraint.first << " " << constraint.second << " " << worked << nl;
        if (!worked) return false;
    }
    return true;
}

unordered_map<string, int> tag = {
    {"Beatrice", 1},   
    {"Belinda", 2},
    {"Bella", 3},
    {"Bessie", 4},
    {"Betsy", 5},
    {"Blue", 6},
    {"Buttercup", 7},
    {"Sue", 8}
};

unordered_map<int, string> names = {
    {1, "Beatrice"},   
    {2, "Belinda"},
    {3, "Bella"},
    {4, "Bessie"},
    {5, "Betsy"},
    {6, "Blue"},
    {7, "Buttercup"},
    {8, "Sue"}
};


signed main() {
    ifstream cin("lineup.in");
    ofstream cout("lineup.out");

    iota(ans, ans + 8, 1);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string name1, must, be, milked, beside, name2;
        cin >> name1 >> must >> be >> milked >> beside >> name2;
        constraints.push_back({tag[name1], tag[name2]});
        // cout << tag[name1] << " " << tag[name2] << nl;
    }

    while (!satisfied()) {
        next_permutation(ans, ans + 8);
    }


    for (int i : ans)
        cout << names[i] << nl;
}