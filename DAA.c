#include <stdio.h>
#include <math.h>

// Function to calculate the asymptotic behavior using Master Theorem
void masterTheorem(int a, int b, int n, int (*f)(int)) {
    double logResult = log(a) / log(b);
    int fn = f(n);

    if (fn == pow(n, logResult)) {
        printf("T(n) = Theta(n^%.2f log n)\n", logResult);
    } else if (fn < pow(n, logResult)) {
        printf("T(n) = Theta(n^%.2f)\n", logResult);
    } else {
        printf("T(n) = Theta(f(n))\n");
    }
}

// Example function f(n)
int f(int n) {
    return n; // Example: f(n) = n
}

int main() {
    int a = 2; // Example: T(n) = 2T(n/2) + n
    int b = 2;
    int n = 16; // Example input size

    masterTheorem(a, b, n, f);

    return 0;
}
