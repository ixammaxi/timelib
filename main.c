/**
 *
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 * Fkt. berechnet fuer ein gegebenes Datum (gregorianischer Kalender) bestehend aus Tag, Monat und Jahr die Nummer des Tages.
 * Gezaehlt wird ausgehend vom Jahresbeginn (1.Januar). Schaltjahre werden berueckschtigt.
 *
 **/
int day_of_the_year(int day, int month, int year)
{
    if (exist_date(day,month,year) == 1)
    {
        int numberOfDays = 0;

        for (int i = 1; i < month, i++)
        {
            numberOfDays += get_days_for_month(i, year);
        }
        numberOfDays += day;
        return numberOfDays;
    }
}

/**
* Fkt. bestimmt, ob es sich bei der Eingabe um ein zulŠssiges Datum handelt.
*
**/
int exist_date(int day, int month, int year)
{
    // Nur zulŠssig falls ein Tag grš§er 0 bzw. kleiner gleich dem letzten Tag des Mnats,,
    // der Monat einen zulŠssigen Wert hat (hierfŸr wird die Fkt. get_days_for_month aufgerufen),
    // das Jahr zwischen 1583 und 4399 liegt.
    if (day > 0 && day <= get_days_for_month(month,year) && year < 2400 && year > 1582 )
    {
        // falls erfŸllt
        return 1;
    }
    else
    {
        // falls nicht erfŸllt
        return 0;
    }
}

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}
