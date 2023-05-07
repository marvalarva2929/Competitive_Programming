using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define no "no"
#define yes "yes"
#define print(x, y, z) for (int i = y; i <= z; i++) {cout << x[i] << " ";} cout << nl;

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

const int mxn = (1 << 17) + 10;

int query(int x, int y) {
    cout << "? " << x << " " << y << nl;
    cout.flush();
    int ans; cin >> ans;
    return ans;
}

int getwinner(int i, int j, int k, int l) {
	int res = query(i, k);
	int res2 = 0;
	switch (res) {
		case 0:  // both are equal, neither are winnners
			res2 = query(j, l);
			return (res2 == 1 ? j : l);
			break;
			
		case 1:  // i has more wins, k and j cannot be winners
			res2 = query(i, l);
			return (res2 == 1 ? i : l);
			break;
		case 2:  // k has more wins, l and and i cannot be winners
			res2 = query(j, k);
			return (res2 == 1 ? j : k);
			break;
	}		
}

void answer(int ans) {
    cout << "! " << ans << nl;
    cout.flush();
}

bool solve() {
    	int cur = 1;
    	int n; cin >> n;
    	n = (1 << n);
	vector<int> a(n);
	iota(a.begin(), a.end(), 1);
	vector<int> b;
	while (a.size() > 2) {
		for (int i = 0; i + 3 < a.size(); i += 4)
			b.push_back(getwinner(a[i], a[i + 1], a[i + 2], a[i + 3]));
		a = b;
		b.clear();
	}
	if (a.size() == 2) {
		answer((query(a[0], a[1]) == 1 ? a[0] : a[1]));
	} else answer(a[0]);
	return true;
}

signed main() {
    cin.tie(0)->sync_with_stdio(false);

    int t; cin >> t;
    while (t--)
        if (!solve()) {
            return 0;
        }
    return 0;
}
