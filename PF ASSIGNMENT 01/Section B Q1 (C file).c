/* Part B - Question 1: */
#include <stdio.h>
#include <string.h>

int main()
{
    int nights;
    char season[20], roomtype[20];
    int discount;                      /* 1 = True, 0 = False */
    int Standard, Deluxe, Suite;
    double Total, Revenue = 0;

    printf("Enter season (Peak / OffPeak): ");
    scanf("%s", season);
    printf("Enter room type (Standard / Deluxe / Suite): ");
    scanf("%s", roomtype);
    printf("Enter stay (nights): ");
    scanf("%d", &nights);

    if (nights > 7)
        discount = 1;
    else
        discount = 0;

    if (strcmp(season, "Peak") == 0)
    {
        Standard = 5000;
        Deluxe   = 8000;
        Suite    = 12000;
    }
    else
    {
        Standard = 3000;
        Deluxe   = 5000;
        Suite    = 8000;
    }

    if (strcmp(roomtype, "Standard") == 0)
        Total = nights * Standard;
    else if (strcmp(roomtype, "Deluxe") == 0)
        Total = nights * Deluxe;
    else
        Total = nights * Suite;

    if (discount == 1)
        Total = 0.85 * Total;          /* flat 15% long-stay discount */

    Revenue = Revenue + Total;

    printf("Your total price is: %.2f\n", Total);
    printf("Total revenue is: %.2f\n", Revenue);
    return 0;
}
