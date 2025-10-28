#include <iostream>
#include <iomanip>

double** create_matrix(int m, int n) {
    double** mat = new double* [m];
    for (int i = 0; i < m; ++i)
        mat[i] = new double[n];
    return mat;
}

void delete_matrix(double** mat, int m) {
    for (int i = 0; i < m; ++i)
        delete[] mat[i];
    delete[] mat;
}

void input_matrix(double** mat, int m, int n) {
    std::cout << "Unesite elemente matrice (" << m << "x" << n << "):\n";
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            std::cin >> mat[i][j];
}

void generate_matrix(double** mat, int m, int n, double a, double b) {
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            mat[i][j] = a + (b - a) * (double(rand()) / RAND_MAX);
}

void print_matrix(double** mat, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            std::cout << std::setw(10) << std::fixed << std::setprecision(4) << mat[i][j] << " ";
        std::cout << "\n";
    }
}

double** add_matrix(double** A, double** B, int m, int n) {
    double** C = create_matrix(m, n);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] + B[i][j];
    return C;
}

double** sub_matrix(double** A, double** B, int m, int n) {
    double** C = create_matrix(m, n);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = A[i][j] - B[i][j];
    return C;
}

double** mul_matrix(double** A, double** B, int m, int n, int p) {
    double** C = create_matrix(m, p);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < p; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k)
                C[i][j] += A[i][k] * B[k][j];
        }
    return C;
}

double** transpose_matrix(double** A, int m, int n) {
    double** T = create_matrix(n, m);
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            T[j][i] = A[i][j];
    return T;
}

int main() {

    int m = 2, n = 3, p = 2;

    double** A = create_matrix(m, n);
    double** B = create_matrix(n, p);

    generate_matrix(A, m, n, 1.0, 5.0);
    generate_matrix(B, n, p, 1.0, 5.0);

    std::cout << "Matrica A:\n";
    print_matrix(A, m, n);
    std::cout << "\nMatrica B:\n";
    print_matrix(B, n, p);

    double** C = mul_matrix(A, B, m, n, p);
    std::cout << "\nA * B =\n";
    print_matrix(C, m, p);

    double** T = transpose_matrix(C, m, p);
    std::cout << "\nTransponirana matrica (A*B)^T:\n";
    print_matrix(T, p, m);

    delete_matrix(A, m);
    delete_matrix(B, n);
    delete_matrix(C, m);
    delete_matrix(T, p);

    return 0;
}
