/* *******************************
calf.h version 1.0 by D. Martel
Juin 2018
Header file for calf.c
*  *******************************
*/

#define MINYEAR 1 /* min year value */
#define MAXYEAR 9999 /* max year value */
#define TRUE 1
#define FALSE 0

/* number of day in each month */
const unsigned int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

char message[80];  /* Holds messages for user  */

struct st_DATEJD {
   unsigned int year;
   unsigned int month;
   unsigned int day;
   unsigned int weekDay;
   double julianDay;

   unsigned int valid; /* == 1 if validated */
 };

//const char *shortDayNames[7] = { "Di", "Lu", "Ma", "Me", "Je", "Ve", "Sa" };
//const char *longDayNames[7] = { "Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi" };

/*
const char *shortMonthNames[12] = {  "Jan",
                          "Fév",
                          "Mar",
                          "Avr",
                          "Mai",
                          "Jun",
                          "Jul",
                          "Aou",
                          "Sep",
                          "Oct",
                          "Nov",
                          "Déc"
                       };
*/
const char *longMonthsNames[12] = {  "Janvier",
                          "Février",
                          "Mars",
                          "Avril",
                          "Mai",
                          "Juin",
                          "Juillet",
                          "Août",
                          "Septembre",
                          "Octobre",
                          "Novembre",
                          "Décembre"
};

/***************************************************************
*************** FUNCTION PROTOTYPES ****************************
****************************************************************/

void dayOFweek(struct st_DATEJD *dateg);
void gregorTOjulian(struct st_DATEJD *dateg);
unsigned int isleap(double);
unsigned int valideDate(struct st_DATEJD *dateg, char *message);

/**************
 this function computes the day of the week */

void dayOFweek(struct st_DATEJD *dateg) {

  double a, fa, jj;
  jj = dateg->julianDay;

  if (jj >= 0 ) {          /*  Validation ok pour jj */
     a = (jj + 1.5) / 7;
     fa = modf(a, &jj);
     a= fa * 7L;

     if ( modf(a, &jj) > 0.5 ) dateg->weekDay = (unsigned int)jj+1;
        else dateg->weekDay = (unsigned int)jj;
   } /*  Fin de validation ok */

  return;
  }

/*************
 This fuction computes the julian day number from a Gregorian date */

void gregorTOjulian(struct st_DATEJD *dateg) {
  double a, b, c, d, m, yy;

   m = (double)(dateg->month);
  yy = (double)(dateg->year);

  if ( (m  == 1) || (m == 2) ) {
     --yy;
     m += 12;
  }
  /* check if date later than 15 October 1582 */
  if ( (((yy * 100) + m) * 100 + dateg->day) > 15821015 ) {
    modf( (yy/100), &a);   /* integer part of yy/100 into a */
    modf( (a/4), &c);       /* integer part of a/4 into c */
    b= 2 - a + c;
  }
  else b = 0;

  modf( (365.25 * yy), &c);
  modf( (30.6001 * (m + 1)), &d);
  dateg->julianDay = b + c + d + (double)(dateg->day) + 1720994.5;
  return;

}

/*************
 This fuction validate the date */

unsigned int valideDate( struct st_DATEJD *dateg, char *message) {

 unsigned int y, m, d;

 y = dateg->year;
 m = dateg->month;
 d = dateg->day;
 dateg->valid = FALSE;

 if ( y < MINYEAR || y > MAXYEAR ) {
    strcpy(message, "Year is outside range!");
    return 1;
 }

 /* validation du mois */

 if ( m < 1 || m > 12 ) {
    strcpy(message, "Month is outside range!");
    return 1;
 }

 /* verification du jour */

 if ( d < 1 ) {
    strcpy(message, "Day is to small!");
    return FALSE;
 }

 if ( m != 2 ) {
   if ( d > daysInMonth[m-1] ) {
    strcpy(message, "Day is outside range!");
    return FALSE;
   }
 }
 else
   if ( d > 28 + isleap((double)y) ) {
     strcpy(message, "Day is outside range!");
     return FALSE;
   }

 strcpy(message, "Date is OK!");
 dateg->valid = TRUE;
 return TRUE;

}


/*************
 This fuction return 1 if year is leap, 0 if not */

unsigned int isleap(double year) {
  double millesime, century, g;
  unsigned int leap = 0;

  millesime = modf( (year/100), &century);
  modf(millesime * 100 + 0.5, &g);
  millesime = g;

  if ( millesime == 0 ) {
    if ( (modf( (century / 4 ), &g) ) == 0 )
      leap = 1;
   }

  else
    if ( modf((millesime / 4 ), &g) == 0 ) leap = 1;

  return(leap);
}
