#include <iostream>
#define nl "\n"
typedef long long ll;
typedef long int li;
using namespace std;

ll friends(ll i) {
  return ((i*(i-1))/2);
}

int main() {
  int n, m;
  ll amn = 0, amx = 0;
  cin >> n >> m;
  int nu = n;
  
  int even = n / m;
  int left = n % m;

  amn = left * friends(even + 1) + (m - left) * friends(even);
  amx = friends(n - (m - 1));

  cout << amn << " " << amx << nl;
}