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

int query(int u, int v) {
    cout << "? " << u << " " << v << nl;
    int x; cin >> x;
    cout.flush();
    return x;
}

signed main() {
    int inc = 2;
    unordered_map<int, int> length;
    while (true) {
        int resp = query(1, inc);
        if (resp == 0)
            return 0;
        else if (resp == -1) {
            cout << "! " << inc - 1 << nl;
            cout.flush();
            return 0;
        } else {
            int opp = query(inc, 1);
            if (opp != 0) {
                if (opp != resp) {
                    cout << "! " << opp + resp << nl;
                    cout.flush();
                    return 0;
                } 
            } else if (opp == 0) return 0;
        }
        inc++;
    }
}