#include <stdio.h>
#include <string.h>
#include "valdez.h"

#define BEEP_CARD_PRICE 30.0
#define INITIAL_BEEP_CARD_BALANCE 70.0
#define MIN_RELOAD 13.0
#define MAX_RELOAD 10000.0

void check_beep_card(float *beep_card_balance, int *beep_card_status);
void get_stations(int *origin, int *destination);
int calculate_fare(char *in1, char *in2, int beep_card_status);
void print_fare(float *beep_card_balance, int *beep_card_status, char *origin_station, char *destination_station, int fare);

// This is a string array of all the Station names in LRT Line 1.
static char *station_names[] = {
	"Baclaran", 
	"EDSA", 
	"Libertad", 
	"Gil Puyat", 
	"Vito Cruz", 
	"Quirino", 
	"Pedro Gil", 
	"UN Ave", 
	"Central", 
	"Carriedo", 
	"Doroteo Jose", 
	"Bambang", 
	"Tayuman", 
	"Blumentritt", 
	"Abad Santos", 
	"R. Papa", 
	"5th Ave", 
	"Monumento", 
	"Balintawak", 
	"Roosevelt"
};

// Initialize station count.
static const int station_count = sizeof(station_names)/sizeof(station_names[0]);

// This declares a structure called Station that has 4 properties: an origin, a destination, and the two fares.
struct Station {
    char *station1;
    char *station2;
    int sj_fare; // Single Journey
    int sv_fare; // Stored Value
};

// This declares a new data type called LRT_Line1 that takes the form of a struct Station.
typedef struct Station LRT_Line1;

// Using the defined struct above called Station, a dictionary called fare_matrix is created.
static LRT_Line1 fare_matrix[190] = {
    {"Baclaran", "EDSA", 15, 12},
    {"Baclaran", "Libertad", 15, 13},
    {"Baclaran", "Gil Puyat", 15, 13},
    {"Baclaran", "Vito Cruz", 15, 14},
    {"Baclaran", "Quirino", 15, 15},
    {"Baclaran", "Pedro Gil", 20, 16},
    {"Baclaran", "UN Ave", 20, 17},
    {"Baclaran", "Central", 20, 18},
    {"Baclaran", "Carriedo", 20, 19},
    {"Baclaran", "Doroteo Jose", 20, 19},
    {"Baclaran", "Bambang", 20, 20},
    {"Baclaran", "Tayuman", 30, 21},
    {"Baclaran", "Blumentritt", 30, 21},
    {"Baclaran", "Abad Santos", 30, 22},
    {"Baclaran", "R. Papa", 30, 23},
    {"Baclaran", "5th Ave", 30, 24},
    {"Baclaran", "Monumento", 30, 25},
    {"Baclaran", "Balintawak", 30, 27},
    {"Baclaran", "Roosevelt", 30, 29},

    {"EDSA", "Libertad", 15, 12},
    {"EDSA", "Gil Puyat", 15, 13},
    {"EDSA", "Vito Cruz", 15, 14},
    {"EDSA", "Quirino", 15, 15},
    {"EDSA", "Pedro Gil", 15, 15},
    {"EDSA", "UN Ave", 20, 16},
    {"EDSA", "Central", 20, 17},
    {"EDSA", "Carriedo", 20, 18},
    {"EDSA", "Doroteo Jose", 20, 19},
    {"EDSA", "Bambang", 20, 19},
    {"EDSA", "Tayuman", 20, 21},
    {"EDSA", "Blumentritt", 30, 21},
    {"EDSA", "Abad Santos", 30, 22},
    {"EDSA", "R. Papa", 30, 22},
    {"EDSA", "5th Ave", 30, 23},
    {"EDSA", "Monumento", 30, 24},
    {"EDSA", "Balintawak", 30, 27},
    {"EDSA", "Roosevelt", 30, 29},

    {"Libertad", "Gil Puyat", 15, 12},
    {"Libertad", "Vito Cruz", 15, 13},
    {"Libertad", "Quirino", 15, 14},
    {"Libertad", "Pedro Gil", 15, 14},
    {"Libertad", "UN Ave", 15, 15},
    {"Libertad", "Central", 20, 16},
    {"Libertad", "Carriedo", 20, 17},
    {"Libertad", "Doroteo Jose", 20, 18},
    {"Libertad", "Bambang", 20, 18},
    {"Libertad", "Tayuman", 20, 19},
    {"Libertad", "Blumentritt", 20, 20},
    {"Libertad", "Abad Santos", 30, 21},
    {"Libertad", "R. Papa", 30, 21},
    {"Libertad", "5th Ave", 30, 22},
    {"Libertad", "Monumento", 30, 23},
    {"Libertad", "Balintawak", 30, 26},
    {"Libertad", "Roosevelt", 30, 28},

    {"Gil Puyat", "Vito Cruz", 15, 12},
    {"Gil Puyat", "Quirino", 15, 13},
    {"Gil Puyat", "Pedro Gil", 15, 14},
    {"Gil Puyat", "UN Ave", 15, 14},
    {"Gil Puyat", "Central", 20, 16},
    {"Gil Puyat", "Carriedo", 20, 16},
    {"Gil Puyat", "Doroteo Jose", 20, 17},
    {"Gil Puyat", "Bambang", 20, 18},
    {"Gil Puyat", "Tayuman", 20, 18},
    {"Gil Puyat", "Blumentritt", 20, 19},
    {"Gil Puyat", "Abad Santos", 20, 20},
    {"Gil Puyat", "R. Papa", 30, 21},
    {"Gil Puyat", "5th Ave", 30, 22},
    {"Gil Puyat", "Monumento", 30, 23},
    {"Gil Puyat", "Balintawak", 30, 25},
    {"Gil Puyat", "Roosevelt", 30, 27},

    {"Vito Cruz", "Quirino", 15, 12},
    {"Vito Cruz", "Pedro Gil", 15, 13},
    {"Vito Cruz", "UN Ave", 15, 13},
    {"Vito Cruz", "Central", 15, 15},
    {"Vito Cruz", "Carriedo", 15, 15},
    {"Vito Cruz", "Doroteo Jose", 20, 16},
    {"Vito Cruz", "Bambang", 20, 17},
    {"Vito Cruz", "Tayuman", 20, 17},
    {"Vito Cruz", "Blumentritt", 20, 18},
    {"Vito Cruz", "Abad Santos", 20, 19},
    {"Vito Cruz", "R. Papa", 20, 20},
    {"Vito Cruz", "5th Ave", 30, 21},
    {"Vito Cruz", "Monumento", 30, 22},
    {"Vito Cruz", "Balintawak", 30, 24},
    {"Vito Cruz", "Roosevelt", 30, 26},

    {"Quirino", "Pedro Gil", 15, 12},
    {"Quirino", "UN Ave", 15, 13},
    {"Quirino", "Central", 15, 14},
    {"Quirino", "Carriedo", 15, 14},
    {"Quirino", "Doroteo Jose", 15, 15},
    {"Quirino", "Bambang", 20, 16},
    {"Quirino", "Tayuman", 20, 16},
    {"Quirino", "Blumentritt", 20, 17},
    {"Quirino", "Abad Santos", 20, 18},
    {"Quirino", "R. Papa", 20, 19},
    {"Quirino", "5th Ave", 20, 20},
    {"Quirino", "Monumento", 30, 21},
    {"Quirino", "Balintawak", 30, 23},
    {"Quirino", "Roosevelt", 30, 25},

    {"Pedro Gil", "UN Ave", 15, 12},
    {"Pedro Gil", "Central", 15, 13},
    {"Pedro Gil", "Carriedo", 15, 14},
    {"Pedro Gil", "Doroteo Jose", 15, 14},
    {"Pedro Gil", "Bambang", 15, 15},
    {"Pedro Gil", "Tayuman", 20, 16},
    {"Pedro Gil", "Blumentritt", 20, 16},
    {"Pedro Gil", "Abad Santos", 20, 17},
    {"Pedro Gil", "R. Papa", 20, 18},
    {"Pedro Gil", "5th Ave", 20, 19},
    {"Pedro Gil", "Monumento", 20, 20},
    {"Pedro Gil", "Balintawak", 30, 22},
    {"Pedro Gil", "Roosevelt", 30, 24},

    {"UN Ave", "Central", 15, 12},
    {"UN Ave", "Carriedo", 15, 13},
    {"UN Ave", "Doroteo Jose", 15, 14},
    {"UN Ave", "Bambang", 15, 14},
    {"UN Ave", "Tayuman", 15, 15},
    {"UN Ave", "Blumentritt", 20, 16},
    {"UN Ave", "Abad Santos", 20, 17},
    {"UN Ave", "R. Papa", 20, 17},
    {"UN Ave", "5th Ave", 20, 18},
    {"UN Ave", "Monumento", 20, 19},
    {"UN Ave", "Balintawak", 30, 22},
    {"UN Ave", "Roosevelt", 30, 23},

    {"Central", "Carriedo", 15, 12},
    {"Central", "Doroteo Jose", 15, 12},
    {"Central", "Bambang", 15, 13},
    {"Central", "Tayuman", 15, 14},
    {"Central", "Blumentritt", 15, 14},
    {"Central", "Abad Santos", 15, 15},
    {"Central", "R. Papa", 20, 16},
    {"Central", "5th Ave", 20, 17},
    {"Central", "Monumento", 20, 18},
    {"Central", "Balintawak", 20, 20},
    {"Central", "Roosevelt", 30, 22},

    {"Carriedo", "Doroteo Jose", 15, 12},
    {"Carriedo", "Bambang", 15, 12},
    {"Carriedo", "Tayuman", 15, 13},
    {"Carriedo", "Blumentritt", 15, 14},
    {"Carriedo", "Abad Santos", 15, 15},
    {"Carriedo", "R. Papa", 15, 15},
    {"Carriedo", "5th Ave", 20, 16},
    {"Carriedo", "Monumento", 20, 17},
    {"Carriedo", "Balintawak", 20, 20},
    {"Carriedo", "Roosevelt", 30, 22},

    {"Doroteo Jose", "Bambang", 15, 12},
    {"Doroteo Jose", "Tayuman", 15, 12},
    {"Doroteo Jose", "Blumentritt", 15, 13},
    {"Doroteo Jose", "Abad Santos", 15, 14},
    {"Doroteo Jose", "R. Papa", 15, 15},
    {"Doroteo Jose", "5th Ave", 15, 15},
    {"Doroteo Jose", "Monumento", 20, 17},
    {"Doroteo Jose", "Balintawak", 20, 19},
    {"Doroteo Jose", "Roosevelt", 30, 21},

    {"Bambang", "Tayuman", 15, 12},
    {"Bambang", "Blumentritt", 15, 12},
    {"Bambang", "Abad Santos", 15, 13},
    {"Bambang", "R. Papa", 15, 14},
    {"Bambang", "5th Ave", 15, 15},
    {"Bambang", "Monumento", 20, 16},
    {"Bambang", "Balintawak", 20, 18},
    {"Bambang", "Roosevelt", 20, 20},

    {"Tayuman", "Blumentritt", 15, 12},
    {"Tayuman", "Abad Santos", 15, 13},
    {"Tayuman", "R. Papa", 15, 13},
    {"Tayuman", "5th Ave", 15, 14},
    {"Tayuman", "Monumento", 15, 15},
    {"Tayuman", "Balintawak", 20, 18},
    {"Tayuman", "Roosevelt", 20, 20},

    {"Blumentritt", "Abad Santos", 15, 12},
    {"Blumentritt", "R. Papa", 15, 13},
    {"Blumentritt", "5th Ave", 15, 14},
    {"Blumentritt", "Monumento", 15, 15},
    {"Blumentritt", "Balintawak", 20, 17},
    {"Blumentritt", "Roosevelt", 20, 19},

    {"Abad Santos", "R. Papa", 15, 12},
    {"Abad Santos", "5th Ave", 15, 13},
    {"Abad Santos", "Monumento", 15, 14},
    {"Abad Santos", "Balintawak", 20, 16},
    {"Abad Santos", "Roosevelt", 20, 18},

    {"R. Papa", "5th Ave", 15, 12},
    {"R. Papa", "Monumento", 15, 13},
    {"R. Papa", "Balintawak", 15, 15},
    {"R. Papa", "Roosevelt", 20, 17},

    {"5th Ave", "Monumento", 15, 12},
    {"5th Ave", "Balintawak", 15, 15},
    {"5th Ave", "Roosevelt", 20, 16},

    {"Monumento", "Balintawak", 15, 13},
    {"Monumento", "Roosevelt", 15, 15},

    {"Balintawak", "Roosevelt", 15, 13},
};

int main()
{ 
	// Some greetings.
	printf("Welcome to LRT Line 1!\n\n");

	
	// Initialize beep card balance as well as the initial beep status.
	float beep_card_balance = 0.0;
	int beep_card_status = 0;

	// If the user has a beep card, then beep_card_status should be equal to 1, otherwise 0.
	check_beep_card(&beep_card_balance, &beep_card_status);


	// Declare origin and destination for indexing in the fare_matrix later.
	int origin, destination;
	
	// This function modifies the values inside origin and destination, based on user input.
	get_stations(&origin, &destination);
	
	// Because index zero.
	--origin;
	--destination;

	// Store the station names to pass later.
	char *origin_station = *(station_names + origin);
	char *destination_station = *(station_names + destination);

    // The fare is then looked up using the dictionary.
    int fare = calculate_fare(origin_station, destination_station, beep_card_status);

	// The respective fare price is then printed, along with the station names that the user has inputted.
    print_fare(&beep_card_balance, &beep_card_status, origin_station, destination_station, fare);


    // Some closing greetings.
    printf("\nThank you for riding LRT-1!\n\n");	

	return 0;
}

// The minimum reload amount of a beep card is 13 pesos.
void beep_reload(float *beep_card_balance)
{
	float reload_amount = 0.0;
	
	// sprintf is similar to printf wherein it can read format specifiers but it instead outputs to a string/character array.
	char prompt[100];
	sprintf(prompt, "\nPlease enter your reload amount. [%.0f-%.0f] >> ", MIN_RELOAD, MAX_RELOAD - *beep_card_balance);

	// Get the reload amount from the user then add it to the beep balance.
	reload_amount = get_float(prompt, "0123456789.\n", MIN_RELOAD, MAX_RELOAD - *beep_card_balance);
	*beep_card_balance += reload_amount;

	// Update the user on what happened.
	printf("\nAdding %.2f PHP, your beep card balance has been reloaded to %.2f PHP.\n", reload_amount, *beep_card_balance);
}

// This function simply checks if the user has sufficient beep card funds, loops otherwise.
void balance_check(float *beep_card_balance, int fare)
{
	while(1)
	{
		if(*beep_card_balance >= fare)
			break;
		printf("\n\t* Insufficient balance of %.2f PHP. Please reload.\n", *beep_card_balance);
		beep_reload(beep_card_balance);
	}
}

// This function sells the user a new beep card.
void beep_avail(float *beep_card_balance, int *beep_card_status)
{
	float new_card_total = BEEP_CARD_PRICE + INITIAL_BEEP_CARD_BALANCE;
	printf("\nA new beep card costs %.2f PHP, %.2f for the card, %.2f for the initial load.", new_card_total, BEEP_CARD_PRICE, INITIAL_BEEP_CARD_BALANCE);
	char buffer = get_char("\nWould you like to avail a beep card? [Y/N] >> ", "YyNn\n");

	float payment = 0.0;
	if(buffer == 'Y' || buffer == 'y') 
	{
		// Update the beep status to 1 since the user said yes in availing a new card.
		*beep_card_status = 1;

		// Ask user for the payment, the minimum price of a beep card today is 100 pesos.
		char prompt[100];
		sprintf(prompt, "\nPlease enter your payment amount. [%.0f-1000] >> ", new_card_total);
		payment = get_float(prompt, "0123456789.\n", new_card_total, 1000.0);
		
		// Print the user's change and update them on their new beep card balance.
		printf("\nYour change is %.2f PHP.\n", payment - new_card_total);
		
		// Set the beep balance to the value of INITIAL_BEEP_CARD_BALANCE
		printf("\nYour new beep card has a balance of %.0f PHP.\n", *beep_card_balance = INITIAL_BEEP_CARD_BALANCE);

		// Ask the user if they want to reload immediately.
		char buffer = get_char("Would you like to immediately reload your new beep card? [Y/N] >> ", "YyNn\n");
		if(buffer == 'Y' || buffer == 'y')
			beep_reload(beep_card_balance);
	}
}

// This function checks the existence of a beep card and sells the user a new one if they don't already have it.
void check_beep_card(float *beep_card_balance, int *beep_card_status)
{	
    char buffer = get_char("Do you have a beep card? [Y/N] >> ", "YyNn\n");
    
	if(buffer == 'Y' || buffer == 'y')
    {
		// Update the beep status to 1 since the user already has a beep card.
		*beep_card_status = 1;
		*beep_card_balance = get_float("\nPlease enter your beep card balance [0-10000] >> ", "0123456789.\n", 0.0, MAX_RELOAD);
		
		// Check if the user has the minimum required balance of 13 pesos inside their beep card.
		balance_check(beep_card_balance, MIN_RELOAD);
	}
    else
		beep_avail(beep_card_balance, beep_card_status);
}

// This function prints the selection menu for the user.
void print_menu()
{
    printf("\n");
    /*	For the sake of space constraints, a second integer j is initialized to start at the halfway point of the array index, 
		printing the stations side by side, effectively creating two columns. */
	for(int i = 0, j = station_count/2; i < station_count/2; i++, j++)
		printf("[%d] %s\t\t[%d] %s\n", i+1, station_names[i], j+1, station_names[j]);
	printf("\nPlease refer to the list above.\n");
}

// This function will loop if the user were to input the same origin and destination.
void get_stations(int *origin, int *destination)
{
	while(1)
	{
		// This function simply prints the station_names array by iterating through it linearly.
	    print_menu();
		
		*origin = get_int("\nPlease enter your Current Station number [1-20] >> ", "0123456789\n", 1, 20);
		*destination = get_int("\nPlease enter your Destination Station number [1-20] >> ", "0123456789\n", 1, 20);
		
		// This checks if the user inputted the same station twice.
		if(*origin != *destination)
			break;
		printf("\n\t* Invalid input. Origin and Destination cannot be the same.\n");
	}
}

// This will simply return the fare value dependent on the station pair and if the user has a beep card or not.
int calculate_fare(char *in1, char *in2, int beep_card_status)
{
	// This for loop simply iterates through the dictionary.
    for(int i = 0; i < sizeof(fare_matrix)/sizeof(fare_matrix[0]); i++)
    {   
        // The first part of the if statement simply compares the first input to the first station in the dictionary, 
        // as well as the second input to the second station in the dictionary.
        // The second part of the if statement simply reverses the order in which the station names are checked.
        // So if the user were to input "Roosevelt" and "Baclaran," the if statement will also check for "Baclaran" and "Roosevelt" as well.
		if((strcmp(in1, fare_matrix[i].station1) == 0 && strcmp(in2, fare_matrix[i].station2) == 0) 
        || (strcmp(in2, fare_matrix[i].station1) == 0 && strcmp(in1, fare_matrix[i].station2) == 0))
        {
            // If the user has a beep card, the stored value fare will be returned.
			if (beep_card_status == 1)
                return fare_matrix[i].sv_fare;
            // Otherwise, the single journey fare will be returned.
            return fare_matrix[i].sj_fare;    
        }
    }
}

// This function calculates the updated balance from a stored value fare.
void update_balance(float *beep_card_balance, int fare)
{	
	balance_check(beep_card_balance, fare);

	// Update and print the balance.
    *beep_card_balance -= fare;

    printf("\nSubtracting %.2f PHP from the fare, your beep card balance is now %.2f PHP.\n", (float) fare, *beep_card_balance);
}

// This function calculates the change from a single journey fare.
void calculate_change(int fare)
{
    float change;
    while(1)
    {
        change = get_float("\nPlease enter your payment amount. [0-1000] >> ", "0123456789.\n", 0.0, 1000.0);

		if(change >= fare)
			break;
        printf("\n\t* Insufficient balance. Please try again.\n\n");
    }

    // Update and print the change.
	change -= fare;

    printf("\nYour change is %.2f PHP.\n", change);
}

// This function prints the corresponding fare price and subsequently calculates the beep balance / change for the user.
void print_fare(float *beep_card_balance, int *beep_card_status, char *origin_station, char *destination_station, int fare)
{
	if(*beep_card_status == 1)
	{
		printf("\nThe stored value fare from %s to %s is %d.00 PHP.\n", origin_station, destination_station, fare);
		update_balance(beep_card_balance, fare);
	}
	else
	{
		printf("\nThe single journey fare from %s to %s is %d.00 PHP.\n", origin_station, destination_station, fare);
		calculate_change(fare);
	}
}