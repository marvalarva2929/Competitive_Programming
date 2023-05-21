#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define pi pair<int, int>
#define ff first
#define ss second

using namespace std;

const int MOD = 1e9 + 7;
const int mxn = 2e5;

int paths = 0;
int lengths = 0;

vector<int> adj[mxn];
int len[mxn];
int num[mxn];

pi dfs(int cur, int par) {
		pi ans = {0, 0}; // number of paths, length of all paths
		for (int nex : adj[cur]) {
				if (nex != par) {
						pi next = dfs(nex, cur);
						ans.ff += next.ff + 1;
						ans.ss += next.ff + 2 + next.ss;
                }
		}
        
        int s = 0, t = 0;
        for (int nex : adj[cur]) {
            if (nex != par) {
                s += num[nex] + 1;
                t += num[nex];
            }
        }

        int toAddPaths = 0;
        int toAddLengths = 0;

        for (int nex : adj[cur])
            if (nex != par)
                toAddPaths += (num[nex] + 1) * (ans.ff - (num[nex] + 1)),
                toAddLengths += (len[nex] + 1) * (ans.ff - (num[nex] + 1));
        
        toAddPaths /= 2;

        paths += toAddPaths;
        lengths += toAddLengths + toAddPaths;

		len[cur] = ans.ss;
		num[cur] = ans.ff;
		return ans;
}

int power(int a, int b) {
		int ans = 1;
		while (b > 0) {
				if (b & 1)
						ans = ((ans % MOD) * a) % MOD;
				b /= 2;
				a = ((a % MOD) * (a % MOD)) % MOD;
		}
		return ans % MOD;
}

int inv(int a) {
		return power(a, MOD - 2);
}

signed main() {
		cin.tie(0)->sync_with_stdio(false);

		int n, k; cin >> n >> k;

		for (int i = 1; i < n; i++) {
				int u, v; cin >> u >> v;
				--u, --v;
				adj[v].push_back(u);
				adj[u].push_back(v);
		}
		
		if (k == 1 || k == 3) {
				cout << 1 << nl;
				return 0;
		}

		dfs(0, -1);

		for (int i = 0; i < n; i++)
				lengths += len[i],
				paths += num[i];

		if (k == 2) {
				cout << ((lengths % MOD) * (inv(paths) % MOD) % MOD) % MOD << nl;
				return 0;
		}

}
