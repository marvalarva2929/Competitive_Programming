#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i = 0, j = 0;
        vector<pair<int, int>> a;
        vector<vector<int>> ans;
        for (auto interval : intervals) {
            a.emplace_back(interval[0], interval[1]);
        }
        sort(a.begin(), a.end());
        int n = a.size();
        int l = 0, r = 1;

        while (l < n) {
            int mx = a[l].second;
            while (r < n && a[r].first <= mx) mx = max(mx, a[r++].second);
            ans.push_back({a[l].first, mx});
            l = r++;
        }
        return ans;
    }
};
