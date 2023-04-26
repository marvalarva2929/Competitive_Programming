#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <chrono>
#define nl '\n'
#define int long long
#define MAX (int)1e6
using namespace std;
int freq[MAX];

struct frequency {
    int n, f;
    frequency(int num, int freq) {
        n = num, f = freq;
    }
    friend bool operator<(const frequency & a, const frequency & b) {
        return a.f < b.f;
    }
};

void changeFreq(int i, int j, int n) {
    freq[i] += n;
    freq[j + 1] -= n;
}

auto start = chrono::high_resolution_clock::now();

int32_t main() {
    int n, a;
    cin >> n >> a;
    priority_queue<frequency> nextF;
    vector<int> nums(n + 1);
    vector<int> opt(n + 1, -1);
    vector<pair<int, int>> qs;
    for (int i = 1; i <= n; i++) 
        cin >> nums[i];
    
    sort(nums.begin(), nums.end());

    for (int i = 0; i < a; i++) {
        int x, y;
        cin >> x >> y;
        changeFreq(x, y, 1);
        qs.push_back({x, y});
    }
    int currFreq = 0;
    for (int i = 1; i <= n; i++) {
        currFreq += freq[i];
        // cout << i << ": " << currFreq << nl;
        frequency f(i, currFreq);
        nextF.push(f);
    }
    while (!nextF.empty()) {
        frequency f = nextF.top();
        nextF.pop();
        if (opt[f.n] == -1) {
            opt[f.n] = nums[nums.size() - 1];
            nums.pop_back();
        }
    }
    vector<int> psums(n + 1, 0);
    psums[0] = 0;
    for (int i = 1; i <= n; i++) {psums[i] = psums[i - 1] + opt[i];}

    int ans = 0;
    for (pair<int, int> quiery : qs) {
        ans += psums[quiery.second] - psums[quiery.first - 1];
    }

    auto end = chrono::high_resolution_clock::now();
    // cout << " took " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << "ms" << nl;
    cout << ans << nl;
    // for (int o : opt) cout << o << " " << nl;
}