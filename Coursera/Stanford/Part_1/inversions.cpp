#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <algorithm>
#define nl "\n"
#define ll long long
using namespace std;
vector<int> enter;

pair<vector<int>, ll> inversions(int low, int high, int n, int iter) {
    if (n == 1) {
//      cout << enter[low] << nl;
      return {{enter[low]}, 0};
    }
    vector<int> out(n, 0);
    int mid = (low+high)/2;

    auto l = inversions(low, mid, n/2, iter+1);
    vector<int> a1 = l.first;
    ll linv = l.second;
    auto r = inversions(mid, high, n - n/2, iter+1);
    vector<int> a2 = r.first;
    ll rinv = r.second;
//    cout << iter << "from " << low << " to " << high << nl;
//for (int i = 0; i < (int) a2.size(); i++) cout << iter << "-- " << a1[i] << ": " << a2[i] << nl;
    ll split = 0;
    int i = 0, j = 0, k = 0;
for (int q = 0; q < n; q++) {
  if ((a1[i] < a2[j] || j >= a2.size()) && i < a1.size()) {
    out[k] = a1[i];
    k++;
    i++;
  } else if ((a2[j] <= a1[i] || i >= a1.size()) && j < a2.size()) {
    out[k] = a2[j];
    split += max(0, (int) a1.size() - i);
    k++;
    j++;
  }
}
    return {out, split + linv + rinv};
}


int main() {
    ifstream fin("inv.txt");
  int n;
  cin >> n;
    enter.resize(n);
    for (int i = 0; i < n; i++) cin >> enter[i];

    auto ans = inversions(0, n, n, 1);
//    for (int inv : ans.first) cout << inv << " ";
//      cout << nl;
    cout << ans.second;
}