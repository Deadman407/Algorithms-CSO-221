#include <bits/stdc++.h>
using namespace std;

int next_power_of_2(int k){
    return pow(2, int(ceil(log2(k))));
}

void print_matrix(vector< vector<int>> &matrix, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (j != 0){
                cout << "\t";
            }
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

void add(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size){
    int i, j;

    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size){
    int i, j;

    for (i = 0; i < size; i++){
        for (j = 0; j < size; j++){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassen_algorithm(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size){
    if(size == 1){
        C[0][0] = A[0][0] * B[0][0];
        return;
    }else{
        int new_size = size / 2;
        vector<int> v(new_size);
        vector<vector<int>>
            a11(new_size, v), a12(new_size, v), a21(new_size, v), a22(new_size, v),
            b11(new_size, v), b12(new_size, v), b21(new_size, v), b22(new_size, v),
            c11(new_size, v), c12(new_size, v), c21(new_size, v), c22(new_size, v),
            p1(new_size, v), p2(new_size, v), p3(new_size, v), p4(new_size, v),
            p5(new_size, v), p6(new_size, v), p7(new_size, v),
            a_result(new_size, v), b_result(new_size, v);

int i, j;

for (i = 0; i < new_size; i++){
            for (j = 0; j < new_size; j++){
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + new_size];
                a21[i][j] = A[i + new_size][j];
                a22[i][j] = A[i + new_size][j + new_size];

                b11[i][j] = B[i][j];
                b12[i][j] = B[i][j + new_size];
                b21[i][j] = B[i + new_size][j];
                b22[i][j] = B[i + new_size][j + new_size];
            }
}

        add(a11, a22, a_result, new_size);
        add(b11, b22, b_result, new_size);
        strassen_algorithm(a_result, b_result, p1, new_size);

        add(a21, a22, a_result, new_size);
        strassen_algorithm(a_result, b11, p2, new_size);

        subtract(b12, b22, b_result, new_size);
        strassen_algorithm(a11, b_result, p3, new_size);

        subtract(b21, b11, b_result, new_size);
        strassen_algorithm(a22, b_result, p4, new_size);

        add(a11, a12, a_result, new_size);
        strassen_algorithm(a_result, b22, p5, new_size);

        subtract(a21, a11, a_result, new_size);
        add(b11, b12, b_result, new_size);

        strassen_algorithm(a_result, b_result, p6, new_size);

        subtract(a12, a22, a_result, new_size);
        add(b21, b22, b_result, new_size);

        strassen_algorithm(a_result, b_result, p7, new_size);


        add(p3, p5, c12, new_size);
        add(p2, p4, c21, new_size);

        add(p1, p4, a_result, new_size);
        add(a_result, p7, b_result, new_size);
        subtract(b_result, p5, c11, new_size);

        add(p1, p3, a_result, new_size);
        add(a_result, p6, b_result, new_size);
        subtract(b_result, p2, c22, new_size);

        for (i = 0; i < new_size; i++){
            for (j = 0; j < new_size; j++){
                C[i][j] = c11[i][j];
                C[i][j + new_size] = c12[i][j];
                C[i + new_size][j] = c21[i][j];
                C[i + new_size][j + new_size] = c22[i][j];
            }
        }
    }
}
void strassen_matrix_multiplication(vector<vector<int>> &A, vector<vector<int>> &B, int m, int n, int a, int b){
    int k = max({m, n, a, b});

    int s = next_power_of_2(k);

    vector<int> v(s);
    vector<vector<int>> Aa(s, v), Bb(s, v), Cc(s, v);

    for (unsigned int i = 0; i < m; i++){
        for (unsigned int j = 0; j < n; j++){
            Aa[i][j] = A[i][j];
        }
    }
    for (unsigned int i = 0; i < a; i++){
        for (unsigned int j = 0; j < b; j++){
            Bb[i][j] = B[i][j];
        }
    }
    strassen_algorithm(Aa, Bb, Cc, s);
    vector<int> temp1(b);
    vector<vector<int>> C(m, temp1);
    for (unsigned int i = 0; i < m; i++){
        for (unsigned int j = 0; j < b; j++){
            C[i][j] = Cc[i][j];
        }
    }
    print_matrix(C, m, b);
}

bool check(int n, int a){
    if (n == a)
        return true;
    else
        return false;
}

int main(){
    int m, n, a, b;
    cout << "Enter the rows and columns of first matrix : ";
    cin >> m >> n;
    cout << "Enter values into the first matrix : " << endl;
    vector<vector<int>> A;

    for (int i = 0; i < m; i++){
        vector<int> temp;
        for (int j = 0; j < n; j++){
            int i;
            cin >> i;
            temp.push_back(i);
        }
        A.push_back(temp);
    }
    cout << "Enter the rows and columns of second matrix : ";
    cin >> a >> b;
    cout << "Enter values into the second matrix : " << endl;
    vector<vector<int>> B;

    for (int i = 0; i < a; i++){
        vector<int> temp;
        for (int j = 0; j < b; j++){
            int i;
            cin >> i;
            temp.push_back(i);
        }
        B.push_back(temp);
    }

    bool k = check(n, a);
    if(k){
        cout << "Matrix multiplication of given matrices : " << endl;
        strassen_matrix_multiplication(A, B, m, n, a, b);
    }else{
        cout << "Matrix multiplication not possible!";
    }
    return 0;
}
