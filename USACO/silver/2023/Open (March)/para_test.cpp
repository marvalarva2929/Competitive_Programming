using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)

const int mxn = 3e5;
vector<pi> segments;

char order[6] = {'b', 'e', 's', 's', 'i', 'e'};

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    string s; cin >> s;
    int n = s.size();
    int cur = 0;
    int last = 0;
    int ans = 0;

    for (int i = 1; i <= s.size(); i++) {
        if (cur == 0)
            last = i;
        if (s[i - 1] == order[cur]) 
            cur++;
        if (cur == 6)
            segments.push_back(mp(last, i)),
            cur = 0;
    }

    for (int i = 0; i < segments.size(); i++) {
        int left, right;
        if (i == 0) 
            left = 
        for (int j = i + 1; j < segments.size(); j++) {

        }
    }
}