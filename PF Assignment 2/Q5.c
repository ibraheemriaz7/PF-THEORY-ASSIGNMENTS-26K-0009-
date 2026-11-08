#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayMenu(){
    int choice;
    printf("\n====UNIVERSITY LIBRARY MENU====\n");
    printf("1. MEMBER REGISTRATION\n2. DISPLAY AVAILABLE BOOKS\n3. BORROW A BOOK\n4. RETURN A BOOK\n5. DISPLAY MEMBER RECORD\n6. EXIT\n");
    printf("Enter choice: ");
}

void registerMember(char name[], int *studentID, int *memberType){
    printf("Enter name: ");
    scanf(" %49[^\n]", name);

    printf("Enter student ID: ");
    scanf("%d", studentID);

    do {
        printf("Enter membership type (1 = Student, 2 = Faculty): ");
        scanf("%d", memberType);
        if(*memberType != 1 && *memberType != 2){
            printf("Invalid type.\n");
        }
    } while(*memberType != 1 && *memberType != 2);
}

void displayBooks(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks){
    printf("\n%-8s %-30s %-10s\n", "Book ID", "Title", "Available");
    printf("-------------------------------------------------\n");
    for(int i = 0; i < totalBooks; i++){
        printf("%-8d %-30s %-10d\n", bookIDs[i], bookTitles[i], availableCopies[i]);
    }
    printf("-------------------------------------------------\n");
}

void borrowBook(int bookIDs[], char bookTitles[][50], int availableCopies[], int totalBooks, int borrowedBookIDs[], int *borrowedCount, int memberType){
    int bookID, days, index = -1;

    printf("Enter book ID: ");
    scanf("%d", &bookID);
    printf("Enter number of days you want to keep the book: ");
    scanf("%d", &days);

    if(days <= 0){
        printf("Number of days must be positive.\n");
        return;
    }

    for(int i = 0; i < totalBooks; i++){
        if(bookIDs[i] == bookID){
            index = i;
        }
    }

    if(index == -1){
        printf("Invalid book ID.\n");
        return;
    }

    if(availableCopies[index] == 0){
        printf("Sorry, no copies of this book are available.\n");
        return;
    }

    if(*borrowedCount >= 3){
        printf("You cannot borrow more than 3 books at a time.\n");
        return;
    }

    borrowedBookIDs[*borrowedCount] = bookID;
    (*borrowedCount)++;
    availableCopies[index]--;

    printf("You have borrowed \"%s\".\n", bookTitles[index]);
    if(memberType == 1 && days > 14){
        printf("Note: students can keep books for 14 days, fine applies after that.\n");
    }
    else if(memberType == 2 && days > 30){
        printf("Note: faculty can keep books for 30 days, fine applies after that.\n");
    }
}

float returnBook(int bookIDs[], int availableCopies[], int totalBooks, int borrowedBookIDs[], int *borrowedCount, int memberType, float *totalFine){
    int bookID, days, pos = -1, index = -1, allowed, extra;
    float fine = 0, payable = 0;
    char code[20];

    printf("Enter book ID: ");
    scanf("%d", &bookID);
    printf("Enter actual number of days the book was kept: ");
    scanf("%d", &days);

    if(days <= 0){
        printf("Number of days must be positive.\n");
        return 0;
    }

    for(int i = 0; i < *borrowedCount; i++){
        if(borrowedBookIDs[i] == bookID){
            pos = i;
        }
    }

    if(pos == -1){
        printf("You have not borrowed this book.\n");
        return 0;
    }

    for(int i = 0; i < totalBooks; i++){
        if(bookIDs[i] == bookID){
            index = i;
        }
    }

    availableCopies[index]++;

    for(int i = pos; i < *borrowedCount - 1; i++){
        borrowedBookIDs[i] = borrowedBookIDs[i + 1];
    }
    (*borrowedCount)--;

    if(memberType == 1){
        allowed = 14;
    }
    else{
        allowed = 30;
    }

    if(days > allowed){
        extra = days - allowed;
        if(memberType == 1){
            fine = extra * 20;
        }
        else{
            fine = extra * 10;
        }

        printf("Book returned %d days late. Fine: Rs. %.2f\n", extra, fine);
        *totalFine = *totalFine + fine;

        printf("Enter membership code: ");
        scanf("%19s", code);

        if(strcmp(code, "LIB2026") == 0){
            payable = fine * 0.5;
            printf("Correct code, 50%% waiver applied.\n");
        }
        else{
            payable = fine;
            printf("Wrong code, no waiver applied.\n");
        }
        printf("Fine payable for this return: Rs. %.2f\n", payable);
    }
    else{
        printf("Book returned on time. No fine.\n");
    }

    return payable;
}

void displayMemberRecord(char name[], int studentID, int memberType, int borrowedBookIDs[], int borrowedCount, float totalFine, float fineAfterWaiver){
    printf("\n====MEMBER RECORD====\n");
    printf("Name: %s\n", name);
    printf("Student ID: %d\n", studentID);
    if(memberType == 1){
        printf("Membership type: Student\n");
    }
    else{
        printf("Membership type: Faculty\n");
    }

    printf("Currently borrowed books: ");
    if(borrowedCount == 0){
        printf("None");
    }
    for(int i = 0; i < borrowedCount; i++){
        printf("%d ", borrowedBookIDs[i]);
    }
    printf("\n");

    printf("Total fine before waiver: Rs. %.2f\n", totalFine);
    printf("Final fine payable after waiver: Rs. %.2f\n", fineAfterWaiver);
}

int main(){
    int bookIDs[5] = {101, 102, 103, 104, 105};
    char bookTitles[5][50] = {"C Programming", "Data Structures", "Calculus", "Discrete Mathematics", "Digital Logic Design"};
    int availableCopies[5] = {3, 2, 1, 4, 2};
    int totalBooks = 5;

    char name[50];
    int studentID = 0, memberType = 0;
    int borrowedBookIDs[3];
    int borrowedCount = 0;
    float totalFine = 0, fineAfterWaiver = 0;
    int registered = 0;
    int choice;

    do{
        displayMenu();
        scanf("%d", &choice);

        switch(choice){
            case 1:
                if(registered == 1){
                    printf("Member is already registered.\n");
                }
                else{
                    registerMember(name, &studentID, &memberType);
                    registered = 1;
                    printf("Registration successful.\n");
                }
                break;
            case 2:
                displayBooks(bookIDs, bookTitles, availableCopies, totalBooks);
                break;
            case 3:
                if(registered == 0){
                    printf("Please register first.\n");
                }
                else{
                    borrowBook(bookIDs, bookTitles, availableCopies, totalBooks, borrowedBookIDs, &borrowedCount, memberType);
                }
                break;
            case 4:
                if(registered == 0){
                    printf("Please register first.\n");
                }
                else{
                    fineAfterWaiver = fineAfterWaiver + returnBook(bookIDs, availableCopies, totalBooks, borrowedBookIDs, &borrowedCount, memberType, &totalFine);
                }
                break;
            case 5:
                if(registered == 0){
                    printf("Please register first.\n");
                }
                else{
                    displayMemberRecord(name, studentID, memberType, borrowedBookIDs, borrowedCount, totalFine, fineAfterWaiver);
                }
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while(choice != 6);

    return 0;
}
