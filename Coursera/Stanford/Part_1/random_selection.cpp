#include <iostream>
#include <vector>
#include <cmath>
#define nl "\n"
using namespace std;

int selection(vector<int> &a, int lo, int hi, int p) {
    int n = a.size();
    int v = a[rand() % n];
    int lt = 0, gt = n, i = 0;
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
    if (lt == p) return a[lt];
    else if (lt > p) return selection(a, 0, lt, p);
    else if (lt < p) return selection(a, lt, n, p  - lt);
}

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    cout << "The " << m << "th element in the array is: " << selection(a, 0, n, m) << nl; 
}