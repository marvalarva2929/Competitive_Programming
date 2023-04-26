#include <iostream>
#include <vector>
#define nl "\n"
#define vector2d vector<vector<int>>
using namespace std;

vector2d sum(vector2d p, vector2d q, int size) {
    vector<int> temp(size, 0);
    vector2d out(size, temp);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            out[i][j] = p[i][j] + q[i][j];
        }
    } 
    return out;
}

vector2d sub(vector2d p, vector2d q, int size) {
    vector<int> temp(size, 0);
    vector2d out(size, temp);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            out[i][j] = p[i][j] - q[i][j];
        }
    } 
    return out;
}

void strassen(vector2d matrix1, vector2d matrix2, vector2d &ret, int n, string s) {
    int new_size = n/2;
    vector<int> temp(new_size, 0);
    if (n == 1) {
        ret[0][0] = matrix1[0][0] * matrix2[0][0];
    } else {

        vector2d a(new_size, temp), b(new_size, temp), c(new_size, temp), d(new_size, temp), e(new_size, temp), f(new_size, temp), g(new_size, temp), h(new_size, temp);
        for (int i = 0; i < new_size; i++) {
            for (int j = 0; j < new_size; j++) {
                a[i][j] = matrix1[i][j];
                b[i][j] = matrix1[i][j + new_size];
                c[i][j] = matrix1[i + new_size][j];
                d[i][j] = matrix1[i + new_size][j + new_size];
                e[i][j] = matrix2[i][j];
                f[i][j] = matrix2[i][j + new_size];
                g[i][j] = matrix2[i + new_size][j];
                h[i][j] = matrix2[i + new_size][j + new_size];
            }   
        }

        // cout << s << nl;
        // for (int i = 0; i < new_size; i++) {
        //     for (int j = 0; j < new_size; j++) {
        //         cout << a[i][j] << " ";
        //     }
        //     cout << nl;
        // }
        vector2d p1(new_size, temp), p2(new_size, temp), p3(new_size, temp), p4(new_size, temp), p5(new_size, temp), p6(new_size, temp), p7(new_size, temp);
        strassen(a, sub(f, h, new_size), p1, new_size, "p1");
        strassen(sum(a, b, new_size), h, p2, new_size, "p2");
        strassen(sum(c, d, new_size), e, p3, new_size, "p3");
        strassen(d, sub(g, e, new_size), p4, new_size, "p4");
        strassen(sum(a, d, new_size), sum(e, h, new_size), p5, new_size, "p5");
        strassen(sub(b, d, new_size), sum(g, h, new_size), p6, new_size, "p6");
        strassen(sub(a, c, new_size), sum(e, f, new_size), p7, new_size, "p7");
        vector2d A, B, C, D;
        A = sub(sum(p4, sum(p5, p6, new_size), new_size), p2, new_size);
        B = sum(p1, p2, new_size);
        C = sum(p3, p4, new_size);
        D = sub(sum(p1, p5, new_size), sum(p3, p7, new_size), new_size);
        for (int i = 0; i < new_size; i++) {
            for (int j = 0; j < new_size; j++) {
                ret[i][j] = A[i][j];
                ret[i][j + new_size] = B[i][j];
                ret[i + new_size][j] = C[i][j];
                ret[i + new_size][j + new_size] = D[i][j];
            }
        }
    }
}

int main() {
    int n, new_size;
    cin >> n;
    new_size = n/2;
    vector<int> temp(n, 0);
    vector2d matrix1(n, temp), matrix2(n, temp);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix1[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix2[i][j];
        }
    }
    vector2d product(n, temp);
    cout << "|";
    strassen(matrix1, matrix2, product, n, "first");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << product[i][j] << "| ";
        }
        cout << nl << "|";
    }
}
