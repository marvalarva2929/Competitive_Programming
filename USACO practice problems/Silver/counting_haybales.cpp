#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define nl "\n"
using namespace std;

// int search(int lo, int hi, int s) {
//     int mid;
//     while(!(hi <= lo)) {
//         mid = lo + ((hi - lo)/2);
//         if (bales[mid] > s) hi = mid;
//         else if (bales[mid] < s) lo = mid + 1;
//         else return mid;
//     }
//     return 0;
// }

int main() {
    ifstream fin("haybales.in");
    ofstream fout("haybales.out");

    int n, q;
    fin >> n >> q;
    vector<int> bales(n);
    for (int i = 0; i < n; i++) fin >> bales[i];
    sort(bales.begin(), bales.end());
    for (int i = 0; i < q; i++) {
        int x1, x2;
        fin >> x1 >> x2;
        int left = lower_bound(bales.begin(), bales.end(), x1) - bales.begin();
        int right = upper_bound(bales.begin(), bales.end(), x2) - bales.begin();
        fout << right - left << nl;
    }
}