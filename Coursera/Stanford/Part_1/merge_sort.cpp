#include <iostream>
#include <vector>
#define nl "\n"
using namespace std;
vector <int> a;

vector<int> merge(int low, int high, int n, int iter) {
    if (high - low == 1) return {a[low]};

    vector<int> a1 = merge(low, (high+low)/2, n/2, iter+1);
    vector<int> a2 = merge((high+low)/2, high, n - n/2, iter+1);

    vector<int> c(n, 0);
    int i = 0, j = 0, k = 0;
    for (int q = 0; q < n; q++) {
      if ((a1[i] < a2[j] || j >= a2.size()) && i < a1.size()) {
        c[k] = a1[i];
        k++;
        i++;
      } else if ((a2[j] <= a1[i] || i >= a1.size()) && j < a2.size()) {
        c[k] = a2[j];
        k++;
        j++;
      }
    }
    return c;
}

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> c = merge(0, n, n, 0);
    for (int a : c) cout << a << " ";
}