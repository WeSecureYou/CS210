#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string> // Include this header for stoi
#include <sstream> // For stringstream (alternative to stoi)

using namespace std;

// Custom GCD function using Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Structure to represent a fraction
struct Fraction {
    int numerator;
    int denominator;

    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        simplify();
    }

    // Simplify the fraction
    void simplify() {
        int commonDivisor = gcd(abs(numerator), abs(denominator));
        numerator /= commonDivisor;
        denominator /= commonDivisor;
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
    }

    // Overload operators for fraction operations
    Fraction operator+(const Fraction& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator*(const Fraction& other) const {
        int num = numerator * other.numerator;
        int denom = denominator * other.denominator;
        return Fraction(num, denom);
    }

    Fraction operator/(const Fraction& other) const {
        int num = numerator * other.denominator;
        int denom = denominator * other.numerator;
        return Fraction(num, denom);
    }

    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    // Print the fraction
    void print() const {
        if (denominator == 1) {
            cout << numerator;
        }
        else {
            cout << numerator << "/" << denominator;
        }
    }
};

// Function to print a matrix of fractions
void printMatrix(const vector<vector<Fraction>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& val : row) {
            val.print();
            cout << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to convert a matrix to RREF
void rref(vector<vector<Fraction>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int lead = 0; // Lead variable (pivot column)

    for (int r = 0; r < rows; r++) {
        if (lead >= cols) break;

        // Find the row with the largest element in the current column
        int i = r;
        for (int k = r; k < rows; k++) {
            if (abs(matrix[k][lead].numerator) > abs(matrix[i][lead].numerator)) {
                i = k;
            }
        }

        // If the pivot element is zero, move to the next column
        if (matrix[i][lead] == Fraction(0)) {
            lead++;
            r--;
            continue;
        }

        // Swap the current row with the row containing the largest element
        swap(matrix[i], matrix[r]);

        // Normalize the pivot row by dividing by the pivot element
        Fraction pivot = matrix[r][lead];
        for (int j = 0; j < cols; j++) {
            matrix[r][j] = matrix[r][j] / pivot;
        }

        // Eliminate all other rows
        for (int k = 0; k < rows; k++) {
            if (k != r) {
                Fraction factor = matrix[k][lead];
                for (int j = 0; j < cols; j++) {
                    matrix[k][j] = matrix[k][j] - factor * matrix[r][j];
                }
            }
        }

        lead++;
    }
}

// Helper function to convert string to integer (alternative to stoi)
int stringToInt(const string& s) {
    stringstream ss(s);
    int result;
    ss >> result;
    return result;
}

int main() {
    int rows, cols;

    // Input matrix dimensions
    cout << "Enter the number of rows: ";
    cin >> rows;
    cout << "Enter the number of columns: ";
    cin >> cols;

    // Input matrix elements as fractions
    vector<vector<Fraction>> matrix(rows, vector<Fraction>(cols));
    cout << "Enter the matrix elements row by row (as fractions, e.g., 1/2 for 0.5):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            string frac;
            cin >> frac;
            size_t slash = frac.find('/');
            if (slash != string::npos) {
                int num = stringToInt(frac.substr(0, slash));
                int denom = stringToInt(frac.substr(slash + 1));
                matrix[i][j] = Fraction(num, denom);
            }
            else {
                matrix[i][j] = Fraction(stringToInt(frac), 1);
            }
        }
    }

    // Print the original matrix
    cout << "\nOriginal Matrix:" << endl;
    printMatrix(matrix);

    // Convert to RREF
    rref(matrix);

    // Print the RREF matrix
    cout << "Reduced Row Echelon Form (RREF):" << endl;
    printMatrix(matrix);

    return 0;
}
