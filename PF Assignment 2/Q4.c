#include <stdio.h>
#include <stdlib.h>

int getValidDays(){
    int days;
    printf("Enter number of festival days 1 to 7:\n");
    scanf("%d",&days);
    if(days < 1 || days > 7){
        printf("\nInvalid input\n");
        return getValidDays();
    }
    return days;
}

float calculateDailySales(int dayNumber){
    int number_of_orders,sum=0,max=0,amount;
    float avg = 0.00;
    printf("\nEnter the number of orders for day:\n");
    scanf("%d",&number_of_orders);
    for(int i=0; i<number_of_orders;i++){
        printf("Enter amount of order %d: \n",i+1);
        scanf("%d",&amount);
        if(amount<=0){
            printf("\nInvalid input\n");
            i--;
        }
        else{
            if(amount > max) max = amount;
            sum = sum + amount;
        }
    }
    printf("Day %d total sale = %d\n",dayNumber,sum);
    avg = (float)sum/number_of_orders;
    printf("Average order amount = %.2f\n",avg);
    printf("Highest order amount = %d\n",max);
    return (float)sum;
}

int findHighestSalesDay(float dailySales[], int numberOfDays){
    int max=0,max_index;
    for(int i=0; i<numberOfDays; i++){
        if(dailySales[i] > max){
            max=dailySales[i];
            max_index = i;
        }
    }
    return max_index+1;
}


void displayBarChart(float dailySales[], int numberOfDays){
    int asterik = 0;
    for(int i=0; i<numberOfDays;i++){
        asterik = dailySales[i]/100;
        printf("Day %d: ",i+1);
        for(int j = 0 ; j < asterik;j++){
            printf("*");
        }
        printf(" (Rs. %.2f)\n",dailySales[i]);
    }
}



int main(){
    int days = getValidDays();
    float *sales = calloc(days, sizeof(float));

    float festival_total = 0;
    for(int i = 0; i < days; i++){
        sales[i] = calculateDailySales(i + 1);   // store each day's total
        festival_total = festival_total + sales[i];
    }

    int best_day = findHighestSalesDay(sales, days);
    printf("==== FESTIVAL SUMMARY ====");
    printf("\nTotal festival sales = %.2f\n", festival_total);
    printf("Day with highest sales = %d\n", best_day);

    printf("\n==== DAILY SALES BAR CHART ====\n");
    displayBarChart(sales, days);

    free(sales);
    return 0;
}