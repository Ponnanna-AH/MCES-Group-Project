/*The C code using reg51.h controls door lock, automate it using a passcode, 4 digit long. 
    * It would ask for your choice 'E' or 'R' fot entry or reset option.
    * If the choice seems "E", impling you can access the door lock to unlock it with the predefined passcode.
    * Otherwise the option "R", you would be ask to reset the password  
 */

#include <reg51.h>

#define PASSCODE_LENGTH 4

// Function to initialize the UART communication
void initUART() {
  TMOD = 0x20;        // Set Timer 1 in mode 2 (8-bit auto-reload)
  TH1 = 0xFD;         // Set baud rate to 9600
  SCON = 0x50;        // Set serial mode 1, enable receiver
  TR1 = 1;            // Start Timer 1
}

// Function to receive a single character from UART
char receiveChar() {
  while (RI == 0);     // Wait until reception is complete
  RI = 0;             // Reset reception flag
  return SBUF;        // Return received character
}

// Function to transmit a single character through UART
void transmitChar(char c) {
  SBUF = c;           // Load character to be transmitted
  while (TI == 0);     // Wait until transmission is complete
  TI = 0;             // Reset transmission flag
}

// Function to compare the entered passcode with the authorized passcode
int comparePasscode(char* enteredPasscode, char* authorizedPasscode) {
  for (int i = 0; i < PASSCODE_LENGTH; i++) {
    if (enteredPasscode[i] != authorizedPasscode[i]) {
      return 0;  // Return 0 if any digit does not match
    }
  }
  return 1;  // Return 1 if all digits match
}

// Function to reset the passcode
void resetPasscode(char* authorizedPasscode) {
  transmitChar('R');  // Prompt the user to reset the passcode

  for (int i = 0; i < PASSCODE_LENGTH; i++) {
    authorizedPasscode[i] = receiveChar();  // Receive each digit of the new passcode
    transmitChar('*');                      // Display '*' for each entered digit
  }

  transmitChar('O');  // Passcode reset successful
}

void main() {
  char authorizedPasscode[PASSCODE_LENGTH] = {'1', '2', '3', '4'};
  char enteredPasscode[PASSCODE_LENGTH];

  initUART();

  transmitChar('M');  // Prompt the user to choose between entering or resetting the passcode

  char choice = receiveChar();

  if (choice == 'E' || choice == 'e') {  // Enter passcode
    transmitChar('E');  // Prompt the user to enter the passcode

    for (int i = 0; i < PASSCODE_LENGTH; i++) {
      enteredPasscode[i] = receiveChar();  // Receive each digit of the passcode
      transmitChar('*');                   // Display '*' for each entered digit
    }

    if (comparePasscode(enteredPasscode, authorizedPasscode)) {
      transmitChar('A');  // Authorization successful
    } else {
      transmitChar('D');  // Authorization failed
    }
  } else if (choice == 'R' || choice == 'r') {  // Reset passcode
    resetPasscode(authorizedPasscode);
  }

  while (1);  // Infinite loop to prevent the program from exiting
}

