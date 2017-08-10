// =======================================
// = CS136, S14: Assignment 6, Problem 1 =
// = =================================== =
// = Author: The Manufacturer            =
// =======================================

// C program to checkin travelers travelling with AirX on the flight.

#include <stdio.h>

#include "reservation.h"

int main(void) {
  // Stores the flight information.
  struct manifest flight_man = M(5, 10);

  // Begin checkin.
  char class = -1;
  char response = '\0';
  int seat = -1;

  // Iterates while the response to resetting the flight's manifest is 'R'.
  while (response != 'X') {
    // Iterates while there are seats available on the flight.
    while ((get_available_seats_fc(&flight_man) > 0) || 
           (get_available_seats_ec(&flight_man) > 0)) {
      printf("Welcome, Traveller!\n");
      printf("Enter 'F' to book a First Class seat or 'E' to book an Economic Class seat: ");

      class = getchar();
      getchar(); // eats the newline.

      // Iterates while the traveller does not have a seat or until he/she decides 
      // to exit.
      while (seat == -1) {
        seat = (class == 'F') ? book_seat_fc(&flight_man) : book_seat_ec(&flight_man);

        if (seat > -1) {
          printf("Success! You have been booked in %s on the flight!\n\n", (class == 'F') ? "First Class" : "Economic Class");
          printf("----- BOARDING PASS -----\n");
          printf("AirX Flight 1234\n");
          printf("%s\n", (class == 'F') ? "First Class" : "Economic Class");
          printf("Seat: %d\n", seat + 1);
          printf("-------------------------\n\n");
        } else {
          printf("%s is full, do you want a seat in %s (y/n)? ", (class == 'F') ? "First Class" : "Economic Class", 
                                                                 (class == 'F') ? "Economic Class" : "First Class");

          response = getchar();
          getchar(); // eats the newline.

          if (response == 'y') {
            class = (class == 'F') ? 'E' : 'F';
          } else {
            break;
          }
        }
      }

      // Resets the seat.
      seat = -1;
    }

    printf("The flight is entirely booked! Enter 'R' to reset the flight's manifest or 'X' to exit: ");

    response = getchar();
    getchar(); // eats the newline.

    if (response == 'R') {
      printf("\n");
      
      reset_manifest(&flight_man);
    }
  }

  return 0;
}
