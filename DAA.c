#include <stdio.h>
#include <math.h>

// funtion is only allowed when n has limited input and no polynomialgreater then n power 1

// Function to calculate the asymptotic behavior using Master Theorem
void masterTheorem(int a, int b, int n, int (*f)(int)) {            // pointer for more flexibility (can change function dynamicly (calling fun 2 times for different function))
    double logResult = log(a) / log(b);
    int fn = f(n);

    if (fn == pow(n, logResult)) {
        printf("lets try case 1 \n");
        printf("T(n) = Theta(n^%.2f log n)\n", logResult);  // %.2f print with pricision of 2 digits (0.00)
    } else if (fn < pow(n, logResult)) {
        printf("lets try case 1 \n");
        printf("Case 1 falied!, because T(n) != Theta(n^%.2f log n)\n", logResult );
        printf("lets try case 2 \n");
        printf("T(n) = Theta(n^%.2f)\n", logResult);
    } else {
        printf("lets try case 1 \n");
        printf("Case 1 falied!, because T(n) != Theta(n^%.2f log n)\n", logResult);
        printf("lets try case 2 \n");
        printf("Case 2 falied!, because T(n) != Theta(n^%.2f)\n", logResult);
        printf("lets try case 3 \n");
        printf("T(n) = Theta(f(n))\n");
    }
}

// Example :-
int f(int n) {
    return n; // Example: f(n) = n
}

int main() {
    int a = 2; // Example: T(n) = 2T(n/2) + n
    int b = 2;
    int n = 16; // Example input size
    // int n = n; // Example input size
    // int n = pow(n,4); // Example input size

    masterTheorem(a, b, n, f);

    return 0;
}
