#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include <vector>
#include <chrono>
#define nl '\n'
using namespace std;
auto start = chrono::high_resolution_clock::now();
struct Job {
    int w, l; 
    double score;
    Job(int wi, int le) {
        w = wi, l = le;
        //  score = (double) w/l;
        score = w - l; // unoptimal
    }
    friend bool operator< (const Job & a, const Job & b) {
        return (a.score == b.score ? a.w > b.w : a.score > b.score);
    }
    void print() {
        cout << "This job has a score of: " << score << " and a weight of " << w << " and a length of " << l << nl;
    }
};

int main() {
    ifstream fin("jobs.txt");
    ofstream fout("jobsUO.txt");
    vector<Job> jobs; // jobs.first = job weight, job.second = job length, job.third = job score
    int n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        int w, l;
        fin >> w >> l;
        Job newJob(w, l);
        jobs.push_back(newJob);
    }
    sort(jobs.begin(), jobs.end());
    long long currentTime = 0, runningTotal = 0;
    for (int i = 0 ; i < jobs.size(); i++) {
        Job currentJob = jobs[i];
        // currentJob.print();
        currentTime += currentJob.l;
        runningTotal += currentJob.w * currentTime;
    }
    fout << currentTime << nl;
    fout << runningTotal << nl;
    auto end = chrono::high_resolution_clock::now();
    cout << chrono::duration_cast<chrono::milliseconds>(end - start).count() << nl;
 }