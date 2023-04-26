#include <iostream>
#include <vector>
#include <fstream>
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
        if (N == 0) return 0;
        return storage[1];
    }

    int delMax() {
        if (N == 0) return 0;
        int ret = storage[1];
        exch(1, N);
        storage[N] = NULL;
        sink(1);
        N--;
        return ret;
    }

    int size() { return N; }

    void insert(int k) {
        storage.push_back(k);
        N++;
        swim(N);
    }

    void sink(int k) {
        while(k*2 <= N) {
            int j = k*2;
            if(j < N) if (greater(j, j + 1)) j++;
            if (greater(j, k)) break;
            exch(k, j);
            k = j;
        }
    }

    void swim(int k) {
        while (k > 1) {
            if (greater(k/2, k)) {
                exch(k/2, k);
                k /= 2;
            }
            else break;
        }
    }

    void exch(int p, int q) { swap(storage[p], storage[q]); }

    bool greater(int p, int q) {
        return storage[p] > storage[q];
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
        if (N == 0) return 0;
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

    int size() { return N; }

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

class Median_Maintanance {

    private:

    MinPQ upperHalf;
    MinPQ lowerHalf;
    int curr_median = -1;

    void calculateMediam() {
        if ((upperHalf.size() + lowerHalf.size()) % 2 != 0) {
            curr_median = upperHalf.size() > lowerHalf.size() ? upperHalf.getMin() : -lowerHalf.getMin();
        } else {
            // cout << upperHalf.getMin() << ": " << lowerHalf.getMax() << nl;
            // lowerHalf.print();
            curr_median = -lowerHalf.getMin();
        }
        // cout << upperHalf.size() << ": " << lowerHalf.size() << nl;
    }

    public: 

    void insert(int to_insert) {
        if (curr_median != -1) {
            if (to_insert <= curr_median) lowerHalf.insert(-to_insert);
            else upperHalf.insert(to_insert);
            if (upperHalf.size() >= lowerHalf.size() + 2) {
                int to_move = upperHalf.delMin();
                // cout << "moving " << to_move << nl;
                lowerHalf.insert(-to_move);
            } else if (lowerHalf.size() >= upperHalf.size() + 2) {
                int to_move = lowerHalf.delMin();
                upperHalf.insert(-to_move);
            }
        } else {
            lowerHalf.insert(-to_insert);
        }
        calculateMediam();
    }

    int get_median() {
        return curr_median;
    }
};

// int main() {
//     ifstream fin("medians.txt");
//     ofstream fout("medians.out");
//     Median_Maintanance maintain;
//     long long running_total = 0;
//     for (int i = 0; i < 10000; i++) {
//         int n, median;
//         fin >> n;
//         maintain.insert(n);
//         median = maintain.get_median();
//         running_total += median;
//         cout << median << nl;
//     }
//     fout << running_total % 10000;
// }

int main() {
    ifstream fin("medians.txt");
    ofstream fout("medians.out");
    Median_Maintanance m;
    long long running_total = 0;
    while (!fin.eof()) {
        int n, median;
        fin >> n;
        m.insert(n);
        median = m.get_median();
        running_total += median;
        // cout << median << nl;
        // fout << "The current median is " << m.get_median() << nl;
    }
    fout << running_total % 10000;
}