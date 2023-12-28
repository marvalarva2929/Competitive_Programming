#include <bits/stdc++.h>
#define int long long
#define nl " \n"
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;
const int mxn = 3e5;
int a[mxn + 1], b[mxn + 1], into[mxn + 1], mx[mxn + 1];
bool active[mxn];
vector<int> events[mxn];

class cmp {
    public:
        bool operator()(int a, int b) {
            return into[a] < into[b];
        }
};

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int n; cin >> n;
    priority_queue<int, vector<int>, cmp> pq;
    fill(into, into + n + 1, -1);

    for (int i = 1; i <= n; i++)
        cin >> a[i], events[i - a[i]].push_back(i);
    for (int i = 1; i <= n; i++) 
        cin >> b[i], into[i + b[i]] = max(into[i + b[i]], i);

    for (int i = n; i >= 0; i--) {
        active[i] = 1;
        pq.push(i);
        while (pq.size() && !active[pq.top()]) pq.pop();
        if (pq.size()) mx[i] = into[pq.top()];
        for (int x : events[i])
            active[x] = 0;
    }

    vector<int> ans;
    ans.push_back(0);
    while (mx[ans.back()] != n && ans.back() != -1) ans.push_back(mx[ans.back()]);
    
    if (ans.back() == -1) cout << -1 << nl;
    else {
        cout << ans.size() << nl;
        reverse(ans.begin(), ans.end());
        for (int x : ans)
            cout << x << " ";
        cout << nl;
    }
}
