/* Question 5: */
#include <stdio.h>
#include <ctype.h>

#define CAP_A 20      /* Zone A - Faculty  */
#define CAP_B 40      /* Zone B - Students */
#define CAP_C 15      /* Zone C - Visitors */

int main()
{
    int occA, occB, occC;                    /* current occupied spaces        */
    char vType, category, permit, emergency;
    char zone = 'N';                         /* 'A', 'B', 'C' or 'N' (none)    */
    const char *reason = "";
    int processed = 0, accepted = 0, rejected = 0;
    int cars = 0, bikes = 0, vans = 0;
    char highest;

    printf("===== SMART CAMPUS PARKING SYSTEM =====\n");
    printf("Current occupancy of Zone A (0-20): ");
    scanf("%d", &occA);
    printf("Current occupancy of Zone B (0-40): ");
    scanf("%d", &occB);
    printf("Current occupancy of Zone C (0-15): ");
    scanf("%d", &occC);
    printf("Vehicle type (C = Car, B = Bike, V = Van): ");
    scanf(" %c", &vType);
    printf("User category (F = Faculty, S = Student, G = Guest): ");
    scanf(" %c", &category);
    printf("Valid parking permit (Y/N): ");
    scanf(" %c", &permit);
    printf("Emergency vehicle (Y/N): ");
    scanf(" %c", &emergency);

    vType = toupper(vType);  category = toupper(category);
    permit = toupper(permit); emergency = toupper(emergency);

    /* ---------- validation ---------- */
    if (occA < 0 || occA > CAP_A || occB < 0 || occB > CAP_B || occC < 0 || occC > CAP_C)
    {
        printf("Error: invalid zone occupancy entered. Vehicle not processed.\n");
    }
    else if (vType != 'C' && vType != 'B' && vType != 'V')
    {
        printf("Error: invalid vehicle type. Vehicle not processed.\n");
    }
    else if (category != 'F' && category != 'S' && category != 'G')
    {
        printf("Error: invalid user category. Vehicle not processed.\n");
    }
    else if (permit != 'Y' && permit != 'N')
    {
        printf("Error: invalid permit value. Vehicle not processed.\n");
    }
    else if (emergency != 'Y' && emergency != 'N')
    {
        printf("Error: invalid emergency value. Vehicle not processed.\n");
    }
    else
    {
        processed = 1;

        /* ---------- eligibility and zone assignment ---------- */
        if (permit == 'N' && emergency == 'N')
        {
            reason = "Invalid permit (no permit and not an emergency vehicle)";
        }
        else if (category == 'F')                        /* Faculty -> Zone A */
        {
            if (occA < CAP_A)                            /* car, bike, van: 1 space */
            {
                zone = 'A';
                occA = occA + 1;
            }
            else
                reason = "No available space in Zone A";
        }
        else if (category == 'S')                        /* Student */
        {
            if (vType == 'V')                            /* van redirected to Zone C */
            {
                if (CAP_C - occC >= 2)
                {
                    zone = 'C';
                    occC = occC + 2;
                }
                else
                    reason = "No suitable zone (Zone C cannot hold a van)";
            }
            else                                         /* car or bike -> Zone B */
            {
                if (occB < CAP_B)
                {
                    zone = 'B';
                    occB = occB + 1;
                }
                else
                    reason = "No available space in Zone B";
            }
        }
        else                                             /* Guest -> Zone C */
        {
            if (vType == 'V')                            /* van needs 2 spaces */
            {
                if (CAP_C - occC >= 2)
                {
                    zone = 'C';
                    occC = occC + 2;
                }
                else
                    reason = "No available space in Zone C (van needs 2 spaces)";
            }
            else                                         /* car or bike: 1 space */
            {
                if (occC < CAP_C)
                {
                    zone = 'C';
                    occC = occC + 1;
                }
                else
                    reason = "No available space in Zone C";
            }
        }

        /* ---------- result of this vehicle ---------- */
        if (zone != 'N')
        {
            accepted = 1;
            if (vType == 'C')      cars = 1;
            else if (vType == 'B') bikes = 1;
            else                   vans = 1;

            printf("\nVehicle ACCEPTED - assigned to Zone %c.\n", zone);
            if (zone == 'A')
                printf("Remaining capacity of Zone A: %d\n", CAP_A - occA);
            else if (zone == 'B')
                printf("Remaining capacity of Zone B: %d\n", CAP_B - occB);
            else
                printf("Remaining capacity of Zone C: %d\n", CAP_C - occC);
        }
        else
        {
            rejected = 1;
            printf("\nVehicle REJECTED - reason: %s\n", reason);
        }

        /* ---------- highest occupancy zone (ties favour A, then B) ---------- */
        if (occA >= occB && occA >= occC)
            highest = 'A';
        else if (occB >= occC)
            highest = 'B';
        else
            highest = 'C';

        /* ---------- parking summary ---------- */
        printf("\n========== PARKING SUMMARY ==========\n");
        printf("Total vehicles processed : %d\n", processed);
        printf("Total accepted           : %d\n", accepted);
        printf("Total rejected           : %d\n", rejected);
        printf("Cars parked              : %d\n", cars);
        printf("Bikes parked             : %d\n", bikes);
        printf("Vans parked              : %d\n", vans);
        printf("Zone A: occupied %d / %d, remaining %d\n", occA, CAP_A, CAP_A - occA);
        printf("Zone B: occupied %d / %d, remaining %d\n", occB, CAP_B, CAP_B - occB);
        printf("Zone C: occupied %d / %d, remaining %d\n", occC, CAP_C, CAP_C - occC);
        printf("Zone with highest occupancy: Zone %c\n", highest);

        if (occA == CAP_A && occB == CAP_B && occC == CAP_C)
            printf("Campus parking facility is FULL.\n");
        else
            printf("Campus parking facility is NOT full.\n");
    }
    return 0;
}
