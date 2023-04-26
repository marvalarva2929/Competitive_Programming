#include <iostream>
#include <queue>
#include <fstream>
#include <deque>
#include <vector>
#include <algorithm>
#define nl '\n'
#define MAX (int)5e4 + 10
using namespace std;

ifstream fin("meetings.in");
ofstream fout("meetings.out");

vector<pair<int, pair<int, int>>> cows; // .first = loc, .second.first = w, .second.second = vel
int start = 0;
int total = 0;
int meetings = 0;
int n;
int stop = 0;
int w[MAX];
int v[MAX];
int x[MAX];

int crash(int i) { // -1 if i is moving left, 1 if i is moving right

    int v = cows[i].second.second;
    int w = cows[i].second.first;
    if (v == -1 && i == start) {
        // cout << "Node " << i << " reached the front with a val of " << w << nl;
        total += w;
        start++;
        if (!(total < stop/2)) {
            return 0;
        }
        return -1;
    } else if (v == 1 && i == cows.size() - 1) {
        // cout << "Node " << i << " reached the end with a val of " << w << nl;
        total += w;
        cows.pop_back();
        if (!(total < stop/2)) {
            return 0;
        }
        return 1;
    } else if (v == 1) {
        int stat = crash(i + 1);
        if (stat == 1) {
            cows.pop_back();
            total += w;
            if (!(total < stop/2)) {
                return 0;
            }
            return 1;
        } else if (stat == -1) {
            meetings++;
            cows[i + 1] = {cows[i + 1].first, {cows[i + 1].second.first, 1}};
            stat = crash(i + 1);
            cows[i] = {cows[i].first, {cows[i].second.first, -1}};
            return -1;
        }
        return 0;
    } else if (v == -1) {
        return -1;
    }
}

int main() {
    int l;
    fin >> n >> l;
    for (int i = 0; i < n; i++) {
        int x, w, v;
        fin >> w >> x >> v;
        cows.push_back({x, {w, v}});
        stop += w;
    }
    sort(cows.begin(), cows.end());

    while (start < cows.size() && (total < stop/2)) {
        if (crash(start) == 0) {
            fout << meetings << nl;
            return 0;
        };
    }
    // for (int i = start; i < cows.size(); i++) {
    //     cout << i << ": " << cows[i].second.first << ": " << cows[i].second.second << nl;
    // }
    fout << meetings << nl;
}