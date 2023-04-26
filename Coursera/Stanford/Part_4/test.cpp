#include <bits/stdc++.h>
#define nl '\n'
using namespace std;

int main() {
    int n;
    cin >> n;
    auto start = chrono::high_resolution_clock::now();
    vector<set<int>> pS(n + 1);
    pS[1].insert(1);
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int a : pS[i - 1]) {
                int add = a ^ (int)pow(2, j - 1);
                // cout << i << ": " << add << nl;
                if (add > a) pS[i].insert(add);
            }
        }
    }

    for (int i = 0; i < pS.size(); i++) {
        set<int> currs = pS[i];
        for (int a : currs) {
            int j = 13;
            cout << a << nl;
            cout <<" the components in set " << i << " are {";
            int iter = 0;
            while (a > 0) {
                iter++;
                if (a % 2 == 1) cout << iter << ", ";
                a = a >> 1;
            }
            cout << "} " << nl;
        }
    }
    auto end = chrono::high_resolution_clock::now();

    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << nl;
}