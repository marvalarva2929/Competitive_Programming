#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
#include <climits>
#define nl "\n"
#define ll long long
using namespace std;

struct Point {
    int a;
    int b;
    ll sum = pow(a, 3) + pow(b, 3);
    string toString() {
        stringstream ss;
        ss << "( " << a << ", " << b << ", " << pow(a, 3) + pow(b, 3) << " )";
        return ss.str();
    }
};

struct Taxicab {
    Point a;
    Point b;
    string toString() { 
        stringstream ss;
        ss << a.sum << " -- ( " << a.a << ", " << a.b << " )" << " = " <<  "( " << b.a <<  ", " <<  b.b << " ) ";
        return ss.str();
    }
};

class MinPQ {
    public:

    vector<Point> storage;
    int N;

    MinPQ() {
        N = 0;
        storage.push_back({});
    }

    void print() {
        cout << "----------" << nl;
        for (int i = 1; i < storage.size(); i++) cout << i << ": " << storage[i].toString() << nl;
        cout << nl;
    }

    Point getMin() {
        return storage[1];
    }



    Point delMin() {
        Point ret = storage[1];
        exch(1, N); 
        storage.pop_back();
        N--;
        sink(1);
        return ret;
    }

    void insert(Point k) {
        storage.push_back(k);
        N++;
        swim(N);
    }

    bool isEmpty() { return N == 0; }

    int size() { return N; }

    void sink(int k) {
        while(k*2 <= N) {
            int j = k*2;
            if(j < N) if (less(j + 1, j)) j++;
            if (less(k, j)) break;
            exch(k, j);
            k = j;
        }
    }

    void swim(int k) {
        while (k > 1) {
            if (less(k, k/2)) {
                exch(k/2, k);
                k /= 2;
            }
            else break;
        }
    }

    void exch(int p, int q) { swap(storage[p], storage[q]); }

    bool less(int p, int q) {
        return storage[p].sum < storage[q].sum;
    }
};

int main() {
    MinPQ pq;
    vector<Taxicab> taxicabs;
    cout << "Enter the maximum number: ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        pq.insert({i, i});
    }

    Point prev;
    while(!pq.isEmpty()) {
        Point curr = pq.delMin();
        if (curr.sum == prev.sum) {taxicabs.push_back({curr, prev});}
        if(curr.b < n) {
            Point toAdd = {curr.a, curr.b + 1};
            pq.insert(toAdd);
        }
        prev = curr;
    }

    for (Taxicab t : taxicabs) cout << t.toString() << nl;
}
