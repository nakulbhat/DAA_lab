#include <stdio.h>

int min(int a, int b) {
    return a <= b ? a : b;
}

int isGCD(int a, int b, int r) {
    return a % r == 0 && b % r == 0;
}

void checkGCD(int a, int b) {
    int opcount = 0;
    for (int r = min(a, b); r > 0; --r) {
        opcount++;
        if (isGCD(a, b, r)) {
            break;
        }
    }
    printf("%d\t%d\n", a + b, opcount);
}

int main() {
    int n = 20;
    int a[20], b[20];

    // Generate arrays programmatically
    for (int i = 0; i < n; ++i) {
        a[i] = 1000 + (i * i * 3);  // Example formula for array 'a'
        b[i] = 200 + (i * 165);     // Example formula for array 'b'
    }

    // Perform GCD check for each pair
    for (int i = 0; i < n; ++i) {
        checkGCD(a[i], b[i]);
    }

    return 0;
}
