// Marc Valdez
// Machine Exercise 2 - March 23, 2023
#include <stdio.h>
float compute(int messages);

void main() {
    // Machine Exercise 2:  You’ve been hired as a programmer by SFT (Send Fail Telecoms) – a mobile telecommunications company. 
	// You are to write a program that will ask the user to input the number of text messages incurred by SFT subscriber. 
	// The text messaging charge is then computed based on the number of text messages. The charge is zero for the first 200 messages. 
	// Text messages beyond that are charged by 0.5 peso per message. The program should output the charge incurred.
    
    int messages = 0;
    printf("Please enter the number of text messages you sent: ");
    scanf("%d", &messages);
    
    printf("Your final charge is PHP %.2f", compute(messages));
}

float compute(int messages) {
    return messages < 200 ? 0 : 0.5 * (messages - 200);
}