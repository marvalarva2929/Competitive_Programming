using namespace std;
#include <bits/stdc++.h>
#include <set>
#include <string.h>
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
#define pb push_back
#define int long long
#define nl '\n'
#define rsz resize
#define sz(x) int(x.size())
#define all(x) begin(x), end(x)
#define MAX (int)3e5

set<int> temp;
bool workOn[8][MAX];
unordered_map<int, bool> hol;
unordered_map<int, int> working;
set<int> goingToWork[8];
set<int> myProjects[MAX];
vector<queue<int>> project(MAX);
vector<int> f(MAX);
int used[MAX];
int ans[MAX];

void updProject(int v) {
    int person = project[v].front();
    myProjects[person].insert(v);
    for (int i = 1; i <= 7; i++) 
        if (workOn[i][person])
            goingToWork[i].insert(person);
}

unordered_map<string, int> di = {
    {"Monday", 1},
    {"Tuesday", 2},
    {"Wednesday", 3},
    {"Thursday", 4},
    {"Friday", 5},
    {"Saturday", 6},
    {"Sunday", 7},
};

int32_t main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        int k; cin >> k;
        while(k--) {
            string s; cin >> s;
            workOn[di[s]][i] = true;
        }
    }
    int x = m;
    while (x--) {
        int h; cin >> h;
        hol[h] = true;
    }
    int finished = k;
    int currState = 0;
    for (int i = 0; i < k; i++) {
        int t;
        cin >> t;
        while (t--) {
            int l;
            cin >> l;
            project[i].push(l); 
        }
    }    
    int today = 1;   
    for (int i = 0; i < k; i++) 
        updProject(i);

    while (currState != finished) {
        if (!hol[today]) {
            set<int> returningNextWeek;
            set<int> updatedProjects;
            for (int person : goingToWork[((today - 1) % 7) + 1]) {
                if (used[person] == today) continue;
                used[person] = today;
                if (myProjects[person].empty()) continue;
                returningNextWeek.insert(person);
                int finishedToday = *myProjects[person].begin();
                myProjects[person].erase(myProjects[person].begin());
                // cout << "On day " << today << ", person " << person << " completed a part of project " << finishedToday << ", has " << myProjects[person].size() << " left" << nl;
                project[finishedToday].pop();
                if (project[finishedToday].empty()) {
                    currState++;
                    ans[finishedToday] = today;
                    continue;
                }
                updatedProjects.insert(finishedToday);
            }
            goingToWork[((today - 1) % 7) + 1] = returningNextWeek;
            for (int project : updatedProjects) {
                updProject(project);
            }
            // for (int i = 0; i < prj.size(); i++) {
            //     if (!prj[i].empty() && working[prj[i].front()] != today && emp[((today - 1) % 7) + 1].count(prj[i].front()) > 0) {
            //         // cout << i << ": " << prj[i].front() << ": " << today % 7<< nl;    
            //         working[prj[i].front()] = today;
            //         prj[i].pop();
            //         if (prj[i].empty()) {
            //             currState++;
            //             // cout << i <<" finished on " << today << nl;
            //             f[i] = today;
            //         }
            //     } 
            //     // cout << "e of " << prj[i].front() << ": " << emp[today % 7].count(prj[i].front()) << nl;
            // }
        } 
        today++;
    }
    for (int i = 0; i < k; i++) cout << ans[i] << " ";
    cout << nl;
} 
