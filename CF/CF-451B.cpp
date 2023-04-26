#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define nl "\n"
int main() {
  int n, L = -1, R = -1;
  cin >> n;
  int a[n];
  int b[n];
  bool ok = true;
  map<int,int> num;
  for (int i = 0; i < n; i++) {
    cin >> a[i]; 
    b[i] = a[i];
  }
  sort(b, b+n);

  for (int i = 0; i < n; i++) {
    num[b[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    a[i] = num[a[i]];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] != i) {
      L = i;
      break;
    }
  }
  for (int i = n-1; i >= 0; i--) {
    if(a[i] != i) {
      R = i;
      break;
    }
  }
  
  if ((R == -1 || L == -1)) {
      cout << "yes" << nl << 1 << " " << 1 << nl;
  } else { 
      reverse(a + L, a + R + 1);
    for (int i = 0; i < n; i++) {
      if (a[i] != i) {
        ok = false;
        break;  
        }
    }
    ok ? cout << "yes" << nl <<  L+1 << " " << R+1 << nl : cout << "no" << nl;
  }
}