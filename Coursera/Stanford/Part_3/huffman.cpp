#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
#define nl '\n'
using namespace std;

ifstream fin("huffman.in");
ofstream fout("huffman.out");

struct Letter { 
    int letter, weight;
    Letter* left;
    Letter* right;

    friend bool operator< (const Letter & a, const Letter & b) {
        return a.weight > b.weight; 
    }
};

void explore(Letter* start, int iter) {
    if(start->left->weight != -1) {
        explore(start->left, iter++);
        fout << iter << start->left->letter << nl;
    }
    if(start->right->weight != -1) {
        explore(start->right, iter++);
        fout << iter << start->right->letter << nl;
    }   
}

int main() {

    int n;
    fin >> n;
    priority_queue<Letter> nextLetter;
    for (int i = 0; i < n; i++) {
        int weight; 
        fin >> weight;
        Letter newLetter;
        newLetter = new Letter;
        newLetter->left = NULL;
        newLetter->right = NULL;
        newLetter->weight = weight;
        nextLetter.push(newLetter);
    }
    while (nextLetter.size() > 1) {
        Letter connectOne = nextLetter.top();
        nextLetter.pop();
        Letter connectTwo = nextLetter.top();
        nextLetter.pop();
        Letter* ancestor = new Letter;
        ancestor->left = connectOne;
        ancestor->right = connectTwo;   
        ancestor->weight = connectOne->weight + connectTwo->weight;
        nextLetter.push(ancestor);
    }
    Letter* top = nextLetter.top();
    explore(top, 1);
}