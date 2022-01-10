#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define monthsCount 12

/// using struct for event info
struct eventInfo {
    //int id;
    char eventTitle[20];
    char eventLocation[20];
    char eventDate[11]; // ex. "01-02-2022" :: string[11]
};

// struct getDateInfo {
//     int day;
//     int month;
//     int year;
// };

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
    // int hasEvent = 0;
    // FILE *dataFile;
    // dataFile = fopen("data.txt", "r");
    // if (dataFile != NULL)
    //     hasEvent = 1;
    

    // if (hasEvent) {
    //     struct getDateInfo parsedDate;
    //     char tmp[100];
    //     tmp = 
    // }



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


void addEvent() {
    FILE *dataFile;
    dataFile = fopen("data.txt", "a");  // with file append-mode

    struct eventInfo newEvent;

    printf("\n=============================================\n");
    printf("\t<========== Add An Event =========>\n");
    printf("===============================================\n");
    printf("\tEnter event-title: ");
    fflush(stdin);
    gets(newEvent.eventTitle);
    // scanf ("%[^\n]%*c", &newEvent.eventTitle);
    printf("\n\tEnter event-location: ");
    fflush(stdin);
    gets(newEvent.eventLocation);
    // scanf ("%[^\n]%*c", &newEvent.eventLocation);
    printf("\n\tEnter event-date: ");
    fflush(stdin);
    gets(newEvent.eventDate);
    // scanf ("%[^\n]%*c", &newEvent.eventDate);

    // write this record
    // fwrite(&newEvent, sizeof(struct eventInfo), 1, dataFile); // not worked
    fprintf(dataFile, "%s\t%s\t%s\n", newEvent.eventTitle, newEvent.eventLocation, newEvent.eventDate);

    if (fprintf != 0) {
        // successfully written the data as record
        printf("\n\t..........Event added successfully!");
        getch();
    }
    else {
        printf("\n\tError: record couldn't be added.");
        getch();
    }

    fclose(dataFile);   // closing file end of this process
}


void appMenu() {

    char userInput;

    
    
    while (1) {
        system("cls");
        printf("\n===============================================\n");
        printf("\t<=== Calendar Search App ===>\n");
        printf("===============================================\n");
        printf("\tEnter an option given below: \n");
        printf("\tA. Search a calendar\n");
        printf("\tB. Add an event\n");
        printf("\tQ. Quit / Exit\n");
        printf("\t=============================================\n");
        printf("\tEnter your option: ");
        scanf("%c", &userInput);    // user-input as char only
        
        if (userInput == 'A') {
            // calendar menu works
            system("cls");
            processCalendar();
            getch();
            //break;
        }
        else if (userInput == 'B') {
            // quit this app
            system("cls");
            addEvent(); // add event
            // getch();
        }
        else if (userInput == 'Q') {
            // quit this app
            //system("cls");
            exit(0);
            //break;
            getch();
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

    /// opening file for data stores @Events
    FILE *dataFile;
    dataFile = fopen("data.txt", "w+");  // with file write-mode
    if (dataFile == NULL) {
        fprintf(stderr, "\nError: File couldn't be opened");
        exit(1);    // exit status 1: True
    }

    /// App process starts here
    appMenu();  // taking user-input through the main_menu


}