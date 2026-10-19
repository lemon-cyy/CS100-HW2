/* CS100 Fall 2026 - HW2 Problem 3: Polynomial evaluation
 *
 * Evaluate P(x) at m given points; print each value rounded to 3 decimals.
 * An array is enough for the coefficients; do not use heap memory and do
 * not use <math.h> (your program is not linked against the math library).
 * Do not rename this file.
 */
#include <stdio.h>

int main(void)
{    
    int n,m;
    double a[35];

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i <= n; i++) {
        scanf("%lf", &a[i]);
    }
    if (scanf("%d", &m) != 1) return 0;

    for (int i = 0; i < m; i++) {
        double x;
        scanf("%lf", &x);
        double ans = 0.0;
        for (int j = n; j >= 0; j--) ans = ans * x + a[j];
        if (ans > -0.0005 && ans < 0.0005) ans = 0.0; 
        printf("%.3f\n", ans);
    }

    return 0;
}
