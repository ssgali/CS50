#include<stdio.h>
#include<cs50.h>
//#include<string.h>
int main(void)
{
    long int a, m, z, q, final, val, min, digit, r, t, p, f, product, y, td, z2, final2, v, sum, d, ans, d2, am, vm, q2, g;
    //Prompt for user input of  Credit card number using do while loop
    do
    {
        a = get_long("Enter the Credit Card Number : ");
    }       // for VISA
    while ((4e+12 > a && 4e+15 < a) || (51e+14 > a && 55e+14 < a) || (34e+13 > a && 35e+13 < a) || (37e+13 > a && 38e+13 < a));
    //Variables Initialization!
    z = 10;
    q = 1;
    final = 0;
    t = 0;
    g = 0;
    v = 0;
    z2 = 1;
    d2 = 1;
    final2 = 0;
    for (r = 0; r < 16; r++)          //Checksum loop of credit card
    {
        min = a % z;
        v = a % z2;
        z = 10 * z;
        q = 10 * q;
        z2 = z2 * 100;
        val = a % z;
        m = val - min;
        d = min - v;
        q2 = d / d2;
        d2 = 100 * d2;
        final2 = final2 + q2;
        digit = m / q;
        // Multiply each of the underlined digits by 2
        product = digit * 2;
        // add those products’ digits together
        if (product > 9 && product < 99)
        {
            y = product;
            t = product % 10;
            f = y - t;
            p = f / 10;
            td = p + t;
            final = final + td;
        }
        else
        {
            final = final + product;
        }

        q = 10 * q;
        z = 10 * z;
    }
    // add that sum to the sum of the digits that weren’t multiplied by 2
    sum = final + final2;
    // Using mod of sum to check the last digit in that sum is a 0 for credit card number validations
    ans = (int)(sum % 10);
    // Checking the card type if credit card number is valid
    if (ans == 0)
    {
        am = a / 1000000000000;
        vm = a / 1000000000000000;
        if (am == 4 || vm == 4)
        {
            printf("VISA\n");
            return 0;
        }
        am = a / 100000000000000;
        if (am == 51 || am == 52 || am == 53 || am == 54 || am == 55)
        {
            printf("MASTERCARD\n");
            return 0;
        }
        am = a / 10000000000000;
        if (am == 34 || am == 37)
        {
            printf("AMEX\n");
            return 0;
        }
    }
    printf("INVALID\n");
}