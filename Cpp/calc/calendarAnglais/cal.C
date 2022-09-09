/* *******************************
Cal.c version 1.0 by D. Martel
January 16, 2002

All algorithms for date calculation taken from:
Duffet-Smith, Peter
PRACTICAL ASTRONOMY WITH YOUR CALCULATOR
Cambridge University Press
Second Edition, 1981
ISBN 0 521 28411 2

*  *******************************
*/
#define DEBUG_CODE 0   /* 1 == debug code active */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#include "cal.h"   /* Date manipulation structures header */

/* st_cal is used to store info on calendars to print */
struct st_cal {
  unsigned int m;            /* year */
  unsigned int y;            /* month */
  unsigned int day;          /* day */
  unsigned int wd;           /* week day from 0 to 6 (sun to sat) */
  unsigned int ndays;        /* number of days in month */
  unsigned int finished;     /* flag indicates this month finished printing */
};


/***************************************************************
************** FUNCTION PROTOTYPES *****************************
****************************************************************/
void printCal(struct st_cal c[], int index);
unsigned int isnumeral(char *s);

/****************************************************************
***************       MAIN          *****************************
*****************************************************************/

int main(int argc, char *argv[])
 {
 int i, k;
 unsigned int y, m1, m2 = 0;
 struct st_cal cal[12];

 /* Setup for command line parameter input
    argv[n]= language year month1 month2 (interval)
         n = 1        2    3      4
 */

  if (argc > 0)    /**** verify each argument to be a numeral */
     for (i=1; i < argc; i++)
      if ( !isnumeral(argv[i]) ) {
        printf("\n%s: Invalid value in date: usage is: year [month1 [month2]]\n", argv[0]);
        return 1;
      }


  switch ( argc  ) {
    case 1 :  /* no argument error */
      printf("\n%s: usage is: year [month [month2]]\n", argv[0]);
      return 1;

    case 2 :  /* year only: setup for interval 1 to 12 */
      sscanf(argv[1], "%i", &y);
      m1 = 1;
      m2 = 12;
      k = 12;    /* k is the interval */
      break;

    case 3 :  /* year and one month only */
      sscanf(argv[1], "%i", &y);
      sscanf(argv[2], "%i", &m1);
      if ( (m1 < 1) || (m1 > 12) ) {
        printf("\n%s: Invalid value for month.\n", argv[0]);
        return 1;
      }
      k = 1;
      break;

    case 4 :  /* we've got a year and two months to form an interval */
      sscanf(argv[1], "%i", &y);
      sscanf(argv[2], "%i", &m1);
      sscanf(argv[3], "%i", &m2);

      /* check if interval is acceptable */
      if ( (m1 < 1) || (m1 > 12) || (m2 < 1) || (m2 > 12) || (m1 == m2) ) {
        printf("\n%s: Invalid values for months.\n", argv[0]);
        return 1;
      }

      /**** compute interval k */
      if (m1 < m2) /* stay in same year */
        k = m2-m1+1;

      else { /**** step up to next year, like 11 1 means Nov to Jan  */
        k = m2+12-m1+1;
        if (y+1 > MAXYEAR) {
          printf("%s: ", "Year will become invalid in chosen interval.\n", argv[0]);
          return 1;
        }
      }
   } /* end switch */



 /* Validate the year */
    if ( y < MINYEAR || y > MAXYEAR) {
      printf("\n%s: Year is not valid! (Should be : 0 < year <= 9999)\n", argv[0]);
      return 1;
    }

/* fills cal with zeros and then proper data
   only put zeros in m position
*/
  for (i=0; i < 12; i++) (cal[i]).m = 0;

  for (i=0; i < k; i++) {
    if (m1 > 12) {
      ++y;
      m1 = 1;
    }
    (cal[i]).m = m1;
    (cal[i]).y = y;
    ++m1;
  }

  /* now print calendars */
  for (i=0; i < k; i+=3) printCal( cal, i );

  return 0;
} /* end main */

/**************************************************************\
 ************************* FUNCTIONS **************************
 **************************************************************/

/* This function prints 1 to 3 calendars from consecutive months.
   INPUT : struct st_cal cal :: m = month, y = year
           cal.m is 0 if entry in not used
   Other contents of struct st)cal cal used to control execution.
*/
void printCal(struct st_cal cal[], int index) {
  int i, j, mX;              /* mX = index of calendar being processed */
  int NBRfinished = 0;   /* indicate number of calendar finished */
  struct st_DATEJD dateg;
  char buff1[31]; /* padding spaces */
  char buff2[31];
  memset(buff1, '\0', 31);
  memset(buff2, '\0', 31);

 mX = index;
 while ( (mX < index+3) && ((cal[mX]).m != 0) ) {
    (cal[mX]).ndays = daysInMonth[(cal[mX]).m-1];
    if ( (cal[mX]).m == 2 )
      (cal[mX]).ndays = daysInMonth[(cal[mX]).m-1] + isleap( (double)((cal[mX]).y) );


    /* print year and month centered on 20 spaces */
    j = strlen(longMonthsNames[(cal[mX]).m-1]) + 5;
    i = (20-j)/2;

    memset(buff1, '\0', i+1);       /* left padding */
    memset(buff1,  ' ', i);
    memset(buff2, '\0', 20-j-i+1);  /* right padding */
    memset(buff2,  ' ', 20-i-j);


    printf("%s%s %4d%s  ", buff1, longMonthsNames[(cal[mX].m)-1], (cal[mX]).y, buff2);
    ++mX;
  } /* end of printing headers */
  printf(NEWLINE);

  mX = index; /* reset to first month in interval */

  /* print day headers */
  while ( (mX < index+3) && ((cal[mX]).m != 0) ) { /* at least the 1st one is not zero */
    printf("Su Mo Tu We Th Fr Sa  ");
    mX++;
  }
  printf(NEWLINE);

  mX = index; /* reset month index */
  dateg.day   = 1;
  while ( (mX < index+3) && ((cal[mX]).m != 0) ) { /* at least the 1st one is not zero */
    /* Compute the day of the week of 1st of the month */
    dateg.month = (cal[mX]).m;
    dateg.year  = (cal[mX]).y;

    gregorTOjulian(&dateg);  /* compute julian day number */
    dayOFweek(&dateg);       /* and then day of the week */

    (cal[mX]).wd = dateg.weekDay;   /* set the day of the 1st of the month */
    (cal[mX]).day = 1;
    (cal[mX]).finished = FALSE;
    ++mX;
  }

  /* print the 1st lines of max 3 calendars */
  mX = index; /* reset month index */
  while ( (mX < index+3) && ((cal[mX]).m != 0) ) {
    /* print first of month at proper place */
    memset(buff1, '\0', 3*((cal[mX]).wd)+1);
    memset(buff1, ' ' , 3*((cal[mX]).wd));
    printf(buff1);

    while ( (cal[mX]).wd < 7 ) {
      printf("%2d ", (cal[mX]).day);
      ((cal[mX]).wd)++;
      ((cal[mX]).day)++;
    }
    printf(" ");
    (cal[mX]).wd = 0;
    ++mX;
  }
  printf(NEWLINE);

  mX = index;   /* reset month index*/

  /* print the rest of calendars */
   while ( NBRfinished < index+3 ) {
    while ( mX < index+3 && ((cal[mX]).m != 0) ) {
        while ( (cal[mX]).wd < 7 ) {
          if ( (cal[mX]).finished || ((cal[mX]).day > (cal[mX]).ndays) ) printf("   ");
          else printf("%2d ", (cal[mX]).day);

          ++((cal[mX]).wd);
          ++((cal[mX]).day);
        }
        printf(" ");                /* spaces for next calendar */

        /* finish the last line of this calendar if necessary */
        if ((cal[mX]).day > (cal[mX]).ndays) {
      	  (cal[mX]).finished = TRUE;
      	  ++NBRfinished;
          /* print required spaces on last line of calendar */
          memset(buff1, '\0', 3*(6-(cal[mX]).wd+1)+1);
          memset(buff1, ' ' , 3*(6-(cal[mX]).wd+1));
          printf(buff1);
        }
        (cal[mX]).wd = 0;
        ++mX;
    }
    mX = index;
    printf(NEWLINE);
  }
printf(NEWLINE);
return;
}


/*************
 Checks if string s is numeral */

unsigned int isnumeral(char *s) {
  unsigned int i;
  for (i=0; i < strlen(s); i++)
   if (!isdigit(s[i])) return FALSE;

  return TRUE;
}
