/* Part B - Question 2: */
#include <stdio.h>

int main()
{
    int floor;
    int currentfloor = 0;              /* elevator starts at Floor 0 */

    printf("Enter requested floor: ");
    scanf("%d", &floor);

    if (floor == currentfloor)
        printf("DOORS OPENING\n");
    else if (floor > currentfloor)
        printf("Moving up\n");
    else
        printf("Moving down\n");

    currentfloor = floor;              /* update current floor after the stop */
    printf("Elevator is now at floor %d\n", currentfloor);
    return 0;
}
