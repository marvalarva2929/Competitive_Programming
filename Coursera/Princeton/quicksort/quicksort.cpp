#include <iostream>
#include <vector>
#include <fstream>
#define nl "\n"
using namespace std;
vector <int> a;
long long nums = 0;

void sort(int lo, int hi) {
    if (hi <= lo) return;
    nums += hi - lo - 1;
    int mid = (hi + lo) /2;
    int v = a[lo];
    int lt = lo, gt = hi, i = lo;
    while (i <= gt) {
        if (a[i] < v)
        { 
            swap(a[i], a[lt]);
            i++;
            lt++;
        } 
        else if (a[i] > v)
        {
            swap(a[i], a[gt]);
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

int main() {
    ifstream fin("quick.txt");
    int n = 10000;
    a.resize(n);
    for (int i = 0; i < n; i++) fin >> a[i];
    sort(0, n - 1);
    for (int n : a) cout << n << " ";
    cout << nl << nums;
}