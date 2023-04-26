#include <iostream>
#define nl '\n'
#define MAX (int)1e4
using namespace std;
int array[MAX];

class Fenwick {
    public:
    int N;
    int *Tree;
    Fenwick(int a[], int N) {
        this->N = N;
        this->Tree = new int[(this->N) + 1];

        for (int i = 0; i <= N; i++) Tree[i] = 0;

        for (int i = 1; i <= N; i++) {
            addValue(i, a[i - 1]);}
            

    }

    void addValue(int i, int v) {
        int ix = i;
        while (ix <= N) {     
            cout << "adding value " << v << " to index " << ix << nl;
            Tree[ix] += v;
            ix += (ix&-ix);
        }
    }

    int sumTo(int i) {
        int ix = i;
        int sum = 0;
        while (ix > 0) {
            sum += Tree[ix];
            ix -= (ix&-ix);   
        }
        return sum;
    }
};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    Fenwick fenwick(array, n + 1);

    while (true) {
        int x;
        cin >> x;
        cout << "The sum of the xth prefix is " << fenwick.sumTo(x) << nl;
    }
 }