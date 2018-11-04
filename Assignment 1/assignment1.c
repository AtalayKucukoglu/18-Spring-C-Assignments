/*

Date: 15.03.2018
Author: Atalay Küçükkoğlu

This program asks user to enter a date and calculates
corresponding weekday of given date. Then, asks user for
an end year and calculates how many times month-day falls
on the same weekday starting from the next year to the
end year.


*/

#include <stdio.h>  // printf, scanf
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

int main()
{
  // year, month and day variables are initialized.

  int year = 0;
  int month = 0;
  int day = 0;

  printf("Enter date [year month day]: \n");
  scanf("%d%d%d", &year, &month, &day); //Reads year, month and day from the user.

  /*  
  Determines whether user entered a valid date.
  If invalid date is entered, program prints 
  an error message and returns with EXIT_FAILURE.
  */
  if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
  {
    printf("Invalid date.\n");
    return EXIT_FAILURE;
  }
  else
  {

    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      if (day > 31)
      {
        printf("Invalid date\n");
        return EXIT_FAILURE;
      }
      break;
    case 2:
      if (day > 28)
      {
        printf("Invalid date.\n");
        return EXIT_FAILURE;
      }
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      if (day > 30)
      {
        printf("Invalid date.\n");
        return EXIT_FAILURE;
      }
    }
  }

  // If entered date is valid, asks for the
  // end year and reads it.

  int end_year = 0;

  printf("Enter end year: \n");
  scanf("%d", &end_year);

  if (end_year < year)
  {
    printf("Invalid end year.\n");
    return EXIT_FAILURE;
  }

  if (month == 1 || month == 2) // If month is January or February,
  {                             // adds 12 to month and -1 to year
    month += 12;                // due to the Zeller's congruence.
    year--;
  }
  
  // Initializes the variables that will be
  // used in Zeller's congruence.

  int q = day;   
  int m = month; 
  int j = year / 100;
  int k = year % 100;

  int zeller_day = (q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

  // prints the correspnding weekday (0 for Saturday and 6 for Friday).

  switch (zeller_day)
  {
  case 0:
    printf("It\'s a Saturday.\n");
    break;
  case 1:
    printf("It\'s a Sunday.\n");
    break;
  case 2:
    printf("It\'s a Monday.\n");
    break;
  case 3:
    printf("It\'s a Tuesday.\n");
    break;
  case 4:
    printf("It\'s a Wednesday.\n");
    break;
  case 5:
    printf("It\'s a Thursday.\n");
    break;
  case 6:
    printf("It\'s a Friday.\n");
  }

  // Initializes the variables to calculate the
  // other years' zeller days.

  int i = 0;
  int new_zeller_day = 0;
  int count = 0;

  for (i = year + 1; i <= end_year; i++)
  {
    j = i / 100;
    k = i % 100;

    new_zeller_day = (q + 13 * (m + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;

    if (zeller_day == new_zeller_day)
      count++;
  }

  	if (month == 13 || month == 14)
		  year++;
	

  // Prints the number of same days.

  printf("Same day-and-month on same weekday between %d and %d: %d\n", year + 1, end_year, count);

  return EXIT_SUCCESS; // Terminates the program succesfully.
}
