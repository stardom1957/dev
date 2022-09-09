/* *******************************
p.c version 0.1 by D. Martel
December 15, 2001
Header file for p.c
*  *******************************
*/

#define MINYEAR 1582 /* min year value */
#define MAXYEAR 9999 /* max year value */
#define TRUE 1
#define FALSE 0

/* number of day in each month */
const short int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

char message[80];  /* Holds messages for user  */

struct st_DATEJD {
   unsigned int year;
   unsigned int month;
   unsigned int day;
   unsigned int weekDay;
   double julianDay;

   unsigned int valid; /* == 1 if validated */
 };

const char *NEWLINE = "\n";
const char *shortDayNames[7] = { "Su", "Mo", "Tu", "We", "Th", "Fr", "Sa" };
const char *longDayNames[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thurday", "Friday", "Saturday" };

const char *shortMonthNames[12] = {  "Jan",
                          "Feb",
                          "Mar",
                          "Apr",
                          "May",
                          "Jun",
                          "Jul",
                          "Aug",
                          "Sep",
                          "Oct",
                          "Nov",
                          "Dec"
                       };

const char *longMonthsNames[12] = {  "January",
                          "February",
                          "March",
                          "April",
                          "May",
                          "June",
                          "July",
                          "August",
                          "September",
                          "October",
                          "November",
                          "December"
};
