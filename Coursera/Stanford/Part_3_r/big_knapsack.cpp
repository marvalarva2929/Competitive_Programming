#include <iostream>
#include <fstream>
#include <chrono>
#include <unordered_map>
#include <vector>
#include <climits>
#define nl '\n'
using namespace std;
int dp[101][10001];
vector<int> w(2001);
vector<int> v(2001);

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
 
        if (hash1 != hash2) {
            return (hash1 * hash2) % 10618452;             
        }
         
          return hash1;
    }
};

unordered_map<pair<int, int>, int, hash_pair> cache;

void sort(int lo, int hi) {
    if (hi <= lo) return;
    int p = w[lo];
    int lt = lo, gt = hi, i = lo;
    while (i <= gt) {
        if (w[i] < p)
        { 
            swap(w[i], w[lt]);
            swap(v[i], v[lt]);
            i++;
            lt++;
        } 
        else if (w[i] > p)
        {
            swap(w[i], w[gt]);
            swap(v[i], v[gt]);
            gt--;
        }
        else 
        {
            i++;
        }
    }
    sort(lo, lt - 1);
    sort(gt + 1, hi);
}

int capacity(int i, int j) {
    if (i == 0) return 0;
    if (cache.find({i, j}) != cache.end()) {
        return cache.at({i, j});
    } else {
        int one = capacity(i - 1, j), two = 0;
        if (j >= w[i]) two = capacity(i - 1, j - w[i]) + v[i];
        int ans = max(one, two);
        cache[{i, j}] = ans;
        return ans;
    }
}

auto start = chrono::high_resolution_clock::now();
int32_t main() {
    ifstream fin("big_knap.txt");
    ofstream fout("knap.out");
    int W;
    fin >> W;
    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> v[i] >> w[i];
    }
    sort(0, n);
    // cout << "sorted" << nl;
    long long val = capacity(n, W);
    auto end = chrono::high_resolution_clock::now();
    cout << "took " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << nl;
    fout << "Cached " << cache.size() << " items" << nl;
    fout << "with a size of: " <<  val << nl;
}