/* Part B - Question 3:*/
#include <stdio.h>

int main()
{
    int m1, m2, m3, m4, m5;
    int Total;
    int Fail;                          /* 1 = True, 0 = False */

    printf("Enter subject 1 marks: ");
    scanf("%d", &m1);
    printf("Enter subject 2 marks: ");
    scanf("%d", &m2);
    printf("Enter subject 3 marks: ");
    scanf("%d", &m3);
    printf("Enter subject 4 marks: ");
    scanf("%d", &m4);
    printf("Enter subject 5 marks: ");
    scanf("%d", &m5);

    Total = m1 + m2 + m3 + m4 + m5;

    if (m1 < 33 || m2 < 33 || m3 < 33 || m4 < 33 || m5 < 33)
        Fail = 1;
    else
        Fail = 0;

    if (Fail == 1)
        printf("Fail - Subject Deficiency\n");
    else if (Total / 5.0 >= 80)
        printf("Distinction\n");
    else if (Total / 5.0 >= 60)
        printf("Pass\n");
    else
        printf("Fail\n");
    return 0;
}
