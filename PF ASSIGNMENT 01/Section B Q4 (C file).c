/* Part B - Question 4: */
#include <stdio.h>

int main()
{
    int quantity;
    double price, discountpercentage, taxpercentage;
    double subtotal, discountamount, discountedamount, taxamount, bill;

    printf("Enter quantity purchased: ");
    scanf("%d", &quantity);
    printf("Enter price per item: ");
    scanf("%lf", &price);
    printf("Enter discount percentage: ");
    scanf("%lf", &discountpercentage);
    printf("Enter tax percentage: ");
    scanf("%lf", &taxpercentage);

    if (quantity <= 0 || price <= 0 || discountpercentage < 0 ||
        discountpercentage > 100 || taxpercentage < 0)
    {
        printf("Error: Invalid input\n");
    }
    else
    {
        subtotal         = quantity * price;
        discountamount   = (subtotal * discountpercentage) / 100;
        discountedamount = subtotal - discountamount;
        taxamount        = (discountedamount * taxpercentage) / 100;
        bill             = discountedamount + taxamount;

        printf("Final payable Bill: %.2f\n", bill);
    }
    return 0;
}
