#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <map>
#define MAX (int)626
#define nl '\n'
using namespace std;
map<string, set<int>> population;
set<string> traits;

bool crossing(int a, int b) {

}

int main() {
    ofstream fout("evolution.out");
    ifstream fin("evolution.in");
    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        int k; fin >> k;
        for (int j = 0; j < k; j++) {
            string s;
            fin >> s;
            traits.insert(s);
            population[s].insert(i);
        }
    }
    for (string trait : traits) {
        for (string trait2 : traits) {
            int one = 0, two = 0, both = 0;
            if (trait != trait2) {
                for (int p : population[trait]) {
                    if (population[trait2].count(p) > 0) both++;
                    else one++;
                }
                for (int p : population[trait2]) {
                    if (population[trait].count(p) == 0) two++;
                }
            }
            if (one > 0 && two > 0 && both > 0) {
                fout << "no" << nl;
                return 0;
            }
        }
    }

    fout << "yes" << nl;
    return 0;
}