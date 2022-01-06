#include <stdio.h>
#include <stdlib.h>
#define monthsCount 12

int checkLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        return 1;
    else
        return 0;
}

int getYearFirstDay(int year) {
    int day;
    // a formula for getting the starting day of year
    // according to this serial: Sunday => 0, Monday => 1 ...
    day = (year*365 + ((year-1)/4) - ((year-1)/100) + ((year-1)/400)) % 7;
    return day;
}

void processCalendar() {
    int year, isLeapYear, i, monthDays, j, weekDays=0, spaceCount=0;
    char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November",
        "December"
    };  // name of every months
    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30
    };  // by defalut February is 28, but for leap-year it is 29

    // check leap year
    isLeapYear = checkLeapYear(year); // 1 or 0
    if (isLeapYear == 1)
        daysInMonth[1] = 29;    // leap-year=FEB=29 days

    //system("cls");
    printf("\n===============================================\n");
    printf("\t<=== Calendar Search App ===>\n");
    
    printf("\tEnter the year: ");
    scanf("%d", &year);
    printf("\n<================ Welcome to %d ================>\n", year);
    
    weekDays = getYearFirstDay(year);
    for (i=0; i<monthsCount; i++) {
        printf("\n===================== %s =====================\n", *(months+i));
        printf("\n   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n");
        monthDays = *(daysInMonth+i);

        for (spaceCount = 1; spaceCount <= weekDays; spaceCount++) {
            printf("      "); //6 space
        }
        for (j=1; j<monthDays; j++) {
            printf("%6d", j);
            weekDays++;
            if (weekDays > 6) {
                weekDays = 0;   // reset
                printf("\n");   // new line
            }
        }
    }
    

    //printf("\n%d year is LY: %d\n", year, isLeapYear);


    printf("\n===============================================\n");
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
            system("cls");
            processCalendar();
            break;
        }
        else if (userInput == 'Q') {
            // quit this app
            //system("cls");
            exit(0);
            break;
        }
        else if (userInput != 'A' || userInput != 'Q') {
            // clear screen
            //appMenu();  // recursion used here
            system("cls");
            printf("Error: Invaild menu option passed\n");
            printf("\t=============================================\n");
            printf("\tEnter an option given below: \n");
            printf("\tA. Search a calendar\n");
            printf("\tQ. Quit / Exit\n");
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