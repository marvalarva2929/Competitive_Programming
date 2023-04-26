#include <iostream>
#include <vector>
#include <climits>
#define nl "\n"
using namespace std;

class MaxPQ {
    public:

    vector<int> storage;
    int N;

    MaxPQ() {
        N = 0;
        storage.push_back(INT_MAX);
    }

    void print() {
        for (int i = 1; i < storage.size(); i++) cout << nl << "-----" << i << ": " << storage[i] << nl;
        cout << nl;
    }

    int getMax() {
        return storage[1];
    }

    int delMax() {
        int ret = storage[1];
        exch(1, N);
        storage[N] = NULL;
        sink(1);
        return ret;
    }

    void insert(int k) {
        storage.push_back(k);
        N++;
        swim(N);
    }

    void sink(int k) {
        while(k*2 <= N) {
            int j = k*2;
            if(j < N) if (less(j, j + 1)) j++;
            if (less(j, k)) break;
            exch(k, j);
            k = j;
        }
    }

    void swim(int k) {
        while (k > 1) {
            if (less(k/2, k)) {
                exch(k/2, k);
                k /= 2;
            }
            else break;
        }
    }

    void exch(int p, int q) { swap(storage[p], storage[q]); }

    bool less(int p, int q) {
        return storage[p] < storage[q];
    }
};

class MinPQ {
    public:

    vector<int> storage;
    int N;

    MinPQ() {
        N = 0;
        storage.push_back(INT_MIN);
    }

    void print() {
        for (int i = 1; i < storage.size(); i++) cout << nl << "-----" << i << ": " << storage[i] << nl;
        cout << nl;
    }

    int getMin() {
        return storage[1];
    }

    int delMin() {
        int ret = storage[1];
        exch(1, N);
        storage.pop_back();
        N--;
        sink(1);
        return ret;
    }

    void insert(int k) {
        storage.push_back(k);
        N++;
        swim(N);
    }

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
        return storage[p] < storage[q];
    }
};

int main() {
    MinPQ pq;
    while (true) {
        int a; cin >> a;
        switch(a) {
            case 69:
                pq.print();
                break;
            case 420: 
                cout << pq.getMin();
                break;
            case 421:
                cout << pq.delMin();
                break;
            default:
                pq.insert(a);
                break;
        }
    }
}