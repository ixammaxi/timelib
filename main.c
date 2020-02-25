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
    return 0;
}

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}
