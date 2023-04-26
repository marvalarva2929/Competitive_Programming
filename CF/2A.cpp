#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <queue>
#include <climits>
#define nl '\n'
using namespace std;

vector<pair<string, int>> log;
unordered_map<string, int> scores;
unordered_map<string, int> secondPass;

int main() {
    int n, winScore = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int m;
        cin >> m;
        log.push_back({s, m});
    }

    for (pair<string, int> round : log) {
        string name = round.first;
        int score = round.second;
        scores[name] += score;
    }
    for (pair<string, int> finalscore : scores) {
        winScore = max(finalscore.second, winScore);
    }

    for (pair<string, int> round : log) {
        string name = round.first;
        int score = round.second;
        secondPass[name] += score;
        if (secondPass[name] >= winScore && scores[name] >= winScore) {
            cout << name << nl;
            return 0;
        }
    }
}