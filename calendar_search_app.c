#include <stdio.h>
#include <stdlib.h>
#define monthCount 12

int checkLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

void processCalendar() {
    int year;
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November",
        "December"
    };  // name of every months
    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30
    };  // by defalut February is 28, but for leap-year it is 29

    system("cls");
    printf("\n===============================================\n");
    printf("\t<=== Calendar Search App ===>\n");
    printf("===============================================\n");

    printf("\tEnter the year: ");
    scanf("%d", &year);
    // check leap year
    int isLeapYear; 
    isLeapYear = checkLeapYear(year); // 1 or 0

    if (isLeapYear == 1)
        daysInMonth[1] = 29;    // leap-year=FEB=29 days

    printf("\n%d year is LY: %d\n", year, isLeapYear);
    printf("===============================================\n");

    printf("Menu: ==================>");
    printf("\nA. Search Again\n");
    printf("\nB. Back to Main Menu\n");
    
    while (1) {
        char ch;
        scanf("%c", &ch);
        if (ch == 'A') {
            processCalendar();  // recursioning
            break;
        }
        else if (ch == 'B') {
            appMenu();  // back to main-menu
            break;
        }
        else {
            printf("\nError: Invalid input");
            system("cls");
            processCalendar(); // recursioning
            break;
        }
    }
}


void appMenu() {
    char userInput;

    printf("\n===============================================\n");
    printf("\t<=== Calendar Search App ===>\n");
    printf("===============================================\n");
    printf("\tEnter an option given below: \n");
    printf("\tA. Search a calendar\n");
    printf("\tQ. Quit / Exit\n");
    printf("\t=============================================\n");
    
    while (1) {
        printf("\tEnter your option: ");
        scanf("%c", &userInput);    // user-input as char only
        
        if (userInput == 'A') {
            // calendar menu works
            processCalendar();
            break;
        }
        else if (userInput == 'Q') {
            // quit this app
            // system("cls");
            exit(0);
            break;
        }
        else if (userInput != 'A' || userInput != 'Q') {
            // clear screen
            //appMenu();  // recursion used here
            system("cls");
            printf("Error: Invaild menu option passed\n");
            continue;
        }
    }

}

void main() {
    /**
     * @Info: PROJECT: Calendar Search Application in C
     * @Author: Md Mahabub Alam
     * @Contact: +8801629235256 | ID: 212002072
     *  Dept. of CSE, Green University of Bangladesh
     */

    /// App process starts here
    appMenu();  // taking user-input through the main_menu


}