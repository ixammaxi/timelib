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
    // Fkt. exist_date wird aufgrufen, um zu kontrollieren, ob das �bergebene Datum zul�ssig ist.
    if (exist_date(day,month,year) == 1)
    {
        // Initialisierung der Variable numberOfDays. Hier wird sp�ter das Ergebnis gespeichert.
        int numberOfDays = 0;

        for (int i = 1; i < month, i++)
        {
            // Fkt. get_days_for_month wird aufgerufen. Hier werden f�r alle vollen Monate, die Anzahl der Tage auf numberOfDays addiert.
            numberOfDays += get_days_for_month(i, year);
        }
        // Auf numberOfDays wird der eingegebene Tag des Datums addiert
        numberOfDays += day;
        // numberOfDays wird der main zur�ckgegeben,
        return numberOfDays;
    }
}

/**
* Fkt. bestimmt, ob es sich bei der Eingabe um ein zul�ssiges Datum handelt.
*
**/
int exist_date(int day, int month, int year)
{
    // Nur zul�ssig falls ein Tag gr��er 0 bzw. kleiner gleich dem letzten Tag des Mnats,,
    // der Monat einen zul�ssigen Wert hat (hierf�r wird die Fkt. get_days_for_month aufgerufen),
    // das Jahr zwischen 1583 und 4399 liegt.
    if (day > 0 && day <= get_days_for_month(month,year) && year < 2400 && year > 1582 )
    {
        // falls erf�llt
        return 1;
    }
    else
    {
        // falls nicht erf�llt
        return 0;
    }
}
/**
* Fkt. bestimmt die Anzahl der Tage jeden Monats. Falls Monat kleiner 1 bzw. gr��er 12 wird sozusagen ein Fehler geworfen.
* Im Falle eines Schaltjahres wird der zweite Wert des Arrays von 28 auf 29 ge�ndert.
**/
int get_days_for_month(int month, int year)
{
    // Falls kein zul�ssiger Monat return -1
    if (month < 1 && month > 12)
    {
        return -1;
    }
    // Wenn Monat zul�ssig
    else
    {
        // Anlegen eines Arrays, um die Anzahl der Tage jeden Monats zu hinterlegen
        int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        // Falls Schaltjahr aendere den Wert des zweiten Eintrages auf 29. Fkt. is_leapyear wird aufgerufen, um zu pr�fen ob es sich um ein Schaltjahr handelt.
        if (is_leapyear(year) == 1)
        {
            int days[1] = {29};
        }
        // R�ckgabe der Tage des �bergebenen Monats
        return days[month-1];
    }
}

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}
