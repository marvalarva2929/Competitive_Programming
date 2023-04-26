using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'

const int mxn = (int)3e5 + 10;

int a[mxn];
int ld[mxn];
set<int> edges[mxn];
int dist[mxn];
int path[mxn];
int ind[mxn];
int vv[mxn];
bool used[mxn];

signed main() {
    cin.tie(0)->sync_with_stdio(false);
    
    fill(ld, ld + mxn, mxn);
    fill(dist, dist + mxn, mxn);
    fill(path, path + mxn, -1);

    ld[1] = 1;

    for (int i = 2; i < mxn; i++) {
        if (ld[i] == mxn) {
            ld[i] = i;
            for (int j = i * i; j < mxn; j += i)
                ld[j] = min(ld[j], i);
        }
    }


    int n; 
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i],
        ind[a[i]] = i;

    int s, t; cin >> s >> t; s--, t--;

    if (a[s] == a[t]) {
        if (s == t) {
            cout << 1 << nl << s + 1 << nl;
            return 0;
        }
        if (a[s] == 1) {
            cout << -1 << nl;
            return 0;
        }
        cout << 2 << nl << s + 1 << nl << t + 1 << nl;
        return 0;
    }

    queue<int> pc;

    for (int i = 0; i < n; i++) {
        int val = a[i];
        while (val > 1) {
            edges[a[i]].insert(ld[val]);
            if (i == s)
                pc.push(ld[val]),
                dist[ld[val]] = 0;
            val /= ld[val];
        }
    }

    while (pc.size()) {
        int curr = pc.front();
        pc.pop();
        for (int i = curr * 2; i < mxn; i += curr) {
            if (!used[i]) {
                used[i] = true;
                for (int value : edges[i]) {
                    if (dist[value] == mxn) {
                        dist[value] = dist[curr] + 1;
                        path[value] = curr;
                        vv[value] = ind[i];
                        pc.push(value);
                    }
                }
            }
        }
    }

    pair<int, int> opt = {mxn, 0};
    for (int edge : edges[a[t]])
        opt = min(opt, {dist[edge], edge});

    if (opt.first == mxn) {
        cout << -1 << nl;
        return 0;
    }

    vector<int> ans;

    ans.push_back(t);
    int x = opt.second; 
    while (path[x] != -1) {
        ans.push_back(vv[x]);
        x = path[x];
    }

    ans.push_back(s);
    reverse(ans.begin(), ans.end());

    cout << ans.size() << nl;
    for (int i : ans)
        cout << i + 1 << " ";
    cout << nl;
}