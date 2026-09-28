#include <stdio.h>

int main()
{
    char vehicleType, membership, disabled, station;
    int battery, requiredBattery;
    int parkingHours, currentTime;
    
    float chargingRequired = 0;
    float chargingCost = 0;
    float parkingCost = 0;
    float chargingDiscount = 0;
    float parkingDiscount = 0;
    float finalBill = 0;

    printf("Enter vehicle type (E for EV, H for Hybrid): ");
    scanf(" %c", &vehicleType);

    printf("Enter current battery percentage: ");
    scanf("%d", &battery);

    printf("Enter required charging percentage: ");
    scanf("%d", &requiredBattery);

    printf("Enter parking duration in hours: ");
    scanf("%d", &parkingHours);

    printf("Enter current time (24-hour format): ");
    scanf("%d", &currentTime);

    printf("Are you a member? (Y/N): ");
    scanf(" %c", &membership);

    printf("Disabled-person priority? (Y/N): ");
    scanf(" %c", &disabled);

    printf("Is charging station available? (Y/N): ");
    scanf(" %c", &station);


    /* Charging availability */
    if (station == 'N' || station == 'n')
    {
        if (vehicleType == 'H' || vehicleType == 'h')
        {
            printf("\nCharging unavailable - Parking only.\n");
        }
        else
        {
            printf("\nNo charging slot available.\n");
        }
    }
    else
    {
        /* Check whether vehicle qualifies for charging */
        if (vehicleType == 'E' || vehicleType == 'e')
        {
            printf("\nEV qualifies for charging.\n");
        }
        else if ((vehicleType == 'H' || vehicleType == 'h') && battery < 40)
        {
            printf("\nHybrid qualifies for charging.\n");
        }
        else
        {
            printf("\nVehicle does not qualify for EV charging.\n");
        }

        /* Calculate charging required */
        if (requiredBattery <= battery)
        {
            chargingRequired = 0;
            printf("No charging required.\n");
        }
        else
        {
            chargingRequired = requiredBattery - battery;

            /* Charging priority */
            if (battery <= 15 && requiredBattery >= 80)
            {
                printf("Charging Priority: Emergency\n");
            }
            else if (disabled == 'Y' || disabled == 'y' ||
                     (membership == 'Y' || membership == 'y') && battery <= 30)
            {
                printf("Charging Priority: Priority Customer\n");
            }
            else
            {
                printf("Charging Priority: Normal\n");
            }

            /* Peak or Off-Peak */
            if (currentTime >= 17 && currentTime <= 22)
            {
                printf("Time: Peak\n");
                chargingCost = chargingRequired * 50;

                /* Emergency does not get membership discount */
                if (battery <= 15 && requiredBattery >= 80)
                {
                    chargingDiscount = 0;
                }
                else if (membership == 'Y' || membership == 'y')
                {
                    chargingDiscount = chargingCost * 0.10;
                }
            }
            else
            {
                printf("Time: Off-Peak\n");
                chargingCost = chargingRequired * 35;

                if (battery <= 15 && requiredBattery >= 80)
                {
                    chargingDiscount = 0;
                }
                else if (membership == 'Y' || membership == 'y')
                {
                    chargingDiscount = chargingCost * 0.20;
                }
            }

            chargingCost = chargingCost - chargingDiscount;
        }
    }


    /* Parking cost */
    if (disabled == 'Y' || disabled == 'y')
    {
        parkingCost = 0;
        printf("Parking is free for disabled-person priority.\n");
    }
    else if (parkingHours <= 2)
    {
        parkingCost = 200;
    }
    else if (parkingHours <= 5)
    {
        parkingCost = 400;
    }
    else
    {
        parkingCost = 700;
    }

    /* Membership parking discount */
    if (disabled == 'N' || disabled == 'n')
    {
        if (membership == 'Y' || membership == 'y')
        {
            parkingDiscount = parkingCost * 0.20;
            parkingCost = parkingCost - parkingDiscount;
        }
    }

    /* Warning for long parking */
    if (parkingHours > 8)
    {
        printf("Warning: Parking duration exceeds 8 hours.\n");
    }

    finalBill = chargingCost + parkingCost;


    /* Final output */
    printf("\n----- FINAL DETAILS -----\n");
    printf("Vehicle Type: %c\n", vehicleType);
    printf("Battery Level: %d%%\n", battery);
    printf("Required Charging: %d%%\n", requiredBattery);
    printf("Charging Cost: Rs. %.2f\n", chargingCost);
    printf("Parking Cost: Rs. %.2f\n", parkingCost);
    printf("Charging Discount: Rs. %.2f\n", chargingDiscount);
    printf("Parking Discount: Rs. %.2f\n", parkingDiscount);
    printf("Final Payable Amount: Rs. %.2f\n", finalBill);

    return 0;
}
```
