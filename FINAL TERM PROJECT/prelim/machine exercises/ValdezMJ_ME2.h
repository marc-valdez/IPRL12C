// Marc Valdez
// Machine Exercise 2 - March 23, 2023
#include <stdio.h>
float compute(int messages);

void prelim_ME2() {
    // Machine Exercise 2:  You’ve been hired as a programmer by SFT (Send Fail Telecoms) – a mobile telecommunications company. 
    // You are to write a program that will ask the user to input the number of text messages incurred by SFT subscriber. 
    // The text messaging charge is then computed based on the number of text messages. The charge is zero for the first 200 messages. 
    // Text messages beyond that are charged by 0.5 peso per message. The program should output the charge incurred.
    printf("=====================================================================\n");
    printf("Machine Exercise 2 - March 23, 2023\n\n");

    int messages, min = 0, max = 2000;
    get_int(&messages, min, max, "Please enter the number of text messages you sent: ");

    printf("Your final charge is PHP %.2f\n", compute(messages));
}

float compute(int messages) {
    return messages < 200 ? 0 : 0.5 * (messages - 200);
}