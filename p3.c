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
    int n;
    double a[31];
    scanf("%d", &n);
    for (int i = 0; i <= n; ++i)
        scanf("%lf", &a[i]);
    int number;
    scanf("%d", &number);
    double resultarray[10001];
    for (int j = 0; j < number; ++j)
    {
        double x;
        scanf("%lf", &x);
        double result = a[0];
        double variable = 1.0;
        for (int i = 1; i <= n; ++i)
        {
            variable *= x;
            result += a[i] * variable;
        }
        resultarray[j] = result;
    }
    for (int m = 0; m < number; ++m)
    {
        printf("%.3f\n", resultarray[m]);
    }
    return 0;
}
