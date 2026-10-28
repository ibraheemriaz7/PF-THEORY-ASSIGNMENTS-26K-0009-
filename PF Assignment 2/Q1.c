// 26k - 0009 
// Ibraheem Riaz
// Pf lab assigment 2
// Q1 cinema seat management

#include <stdio.h>
#include <stdlib.h>
int main(){
    int rows,seats_per_row,status,sum = 0;
    printf("Enter number of rows:\n");
    scanf("%d",&rows);
    printf("Enter number of seats per row:\n");
    scanf("%d",&seats_per_row);
    if (rows <= 0 || seats_per_row <= 0) {
        printf("Rows and seats per row must be greater than zero.\n");
        return 1;
    }
    char (*seats_array)[seats_per_row] = malloc(rows * sizeof(char[seats_per_row]));
    if (seats_array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    printf("Enter '0' if seat is availabe and '1' if booked:\n");
    for(int r=0; r<rows; r++){
        for(int c=0; c<seats_per_row; c++){
            do {
                printf("Seat %d of row %d ?\n",c,r);
                scanf("%d",&status);
                if (status != 0 && status != 1) printf("Invalid input, enter 0 or 1.\n");
            } while (status != 0 && status != 1);
            seats_array[r][c] = (status == 0) ? '_' : 'X';
        }
    }
    printf("Complete Seating plan:\n");
    printf("   ");
    for (int p=0;p<seats_per_row;p++){
        printf("%4d ",p);
    }
    printf("\n");
    for (int i = 0; i < rows; i++) {
        printf("R%-2d",i);
        for (int j = 0; j < seats_per_row; j++) {
            printf("%4c ", seats_array[i][j]);
        }
        printf("\n");
    }
    int availabe_seats_array[rows];
    for (int i = 0; i < rows; i++) availabe_seats_array[i] = 0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<seats_per_row;j++){
            if(seats_array[i][j] == '_'){
                availabe_seats_array[i] = availabe_seats_array[i] + 1;
            }
        }
    }
    printf("Free seats per row: ");
    for(int i = 0;i<rows;i++){
        sum = sum + availabe_seats_array[i];
        printf("%d, ",availabe_seats_array[i]);
    }
    printf("\nTotal available seats: %d\n",sum);

    int k;
    do {
        printf("Enter number of customers for booking: \n");
        scanf("%d",&k);
        if (k <= 0 || k > seats_per_row)
            printf("Invalid group size. Enter 1 to %d.\n", seats_per_row);
    } while (k <= 0 || k > seats_per_row);

    int mid = rows/2;
    int found_row = -1, found_start = -1;

    // d = distance from the middle row
    for (int d = 0; d < rows && found_row == -1; d++) {
        int candidates[2] = { mid - d, mid + d };
        int count = (d == 0) ? 1 : 2;

        for (int t = 0; t < count && found_row == -1; t++) {
            int r = candidates[t];
            if (r < 0 || r >= rows) continue;

            int run = 0;
            for (int c = 0; c < seats_per_row; c++) {
                if (seats_array[r][c] == '_') {
                    run++;
                    if (run == k) {
                        found_row = r;
                        found_start = c - k + 1;
                        break;
                    }
                } else {
                    run = 0;
                }
            }
        }
    }

    if (found_row != -1) {
        printf("Seats allocated in row %d, seats %d to %d\n",
               found_row, found_start, found_start + k - 1);

        // confirm booking
        for (int c = found_start; c < found_start + k; c++) {
            seats_array[found_row][c] = 'X';
        }

        // display updated seating arrangement
        printf("Updated seating plan:\n");
        printf("   ");
        for (int p = 0; p < seats_per_row; p++){
            printf("%4d ", p);
        }
        printf("\n");
        for (int i = 0; i < rows; i++) {
            printf("R%-2d", i);
            for (int j = 0; j < seats_per_row; j++) {
                printf("%4c ", seats_array[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("No %d consecutive seats available. Seating plan unchanged.\n", k);
    }

    free(seats_array);
    return 0;
}
