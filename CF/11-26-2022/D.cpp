#include <iostream>
#define nl '\n'
#define MAX (int)1e6
#include <vector>
#define int long long
using namespace std;
int factorial[MAX];
int iFact[MAX];
int bad[MAX];
int m;

int inv(int A, int M);
int gcdExtended(int a, int b, int* x, int* y);

int choose(int n, int k) {
    // cout << factorial[572] << " " << n << ": " << k << nl;
    // cout << factorial[n] << ": " << factorial[n - k] << ' ' << factorial[k]<< nl;
    // return (factorial[n] * iFact[k] * iFact[n - k]);
    int ans = (factorial[n] * iFact[k] * iFact[n - k]); 
    // while (ans < 0) ans += m;
    return (ans % m);
}

int inv(int A, int M)
{
    int x, y;
    int g = gcdExtended(A, M, &x, &y);
    if (g != 1)
        cout << "Inverse doesn't exist";
    else {
 
        // m is added to handle negative x
        int res = (x % M + M) % M;
        // return x;
        return res;
    }
}

 
// Function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int* x, int* y)
{
 
    // Base Case
    if (a == 0) {
        *x = 0, *y = 1;
        return b;
    }
 
    // To store results of recursive call
    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;
 
    return gcd;
}

int32_t main() {
    int n, m;
    cin>>n>>m;
    vector<int> fac(n+1),ifac(n+1);
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=(fac[i-1]*i) % m;
    
    ifac[n]= inv(fac[n], m);
    for(int i=n;i>0;i--)
        ifac[i-1]=ifac[i]*i;
    auto binom=[&](int x,int y){
        return fac[x]*ifac[y]*ifac[x-y];
    };  
    vector<int> forbid(n);
    for(int i=n/2;i<n-1;i++)
        forbid[i]=binom(n-n/2-1,n-i-1)*fac[i]*n;
    forbid[n-1]=fac[n];
    int ans=0;
    for(int i=n/2;i<n;i++)
        ans+=forbid[i]-forbid[i-1]*(n-i+1);
    cout<<ans % m<<'\n';
}