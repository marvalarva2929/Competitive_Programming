using namespace std;
#include <bits/stdc++.h>
#define int long long
#define nl '\n'
#define MAX (int)1e3


signed main() {

    auto start = chrono::high_resolution_clock::now();
    cin.tie(0)->sync_with_stdio(false);
    bool isComp[MAX] = {};
    vector<int> primes;

    for (int i = 2; i < MAX; i++)
        if (!isComp[i]) {
            primes.push_back(i);
            for (int j = i + i; j < MAX; j += i)
                isComp[j] = true;
        }

    // cout << isComp[2] << " " << isComp[3] << " " << isComp[5] << nl;
    
    for (int prime : primes)
        for (int prime2 : primes)
            if (prime + prime2 < MAX && !isComp[prime + prime2])
                cout << prime << " " << prime2 << " "<< prime + prime2 << nl;

}