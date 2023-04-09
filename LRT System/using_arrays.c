#include <stdio.h>
#include <string.h>
#include "valdez.h"

#define INITIAL_BEEP_CARD_BALANCE 70.0
#define MIN_RELOAD 13.0
#define MAX_RELOAD 10000.0
#define STATION_COUNT 20

void beep_check(float *beep_card_balance, int *beep_card_status);
void get_stations(int *origin, int *destination);
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

// This is a 3d Lookup Array that contains all the fare data for each station pairing.
// The first dimension corresponds to the beep card, 0 if the user doesn't have it, 1 if they do.
// The second and third dimensions are the actual fare data.
static int fare_matrix[2][20][20] = {
	{
		// Single Journey Fares
		{0, 15, 15, 15, 15, 15, 20, 20, 20, 20, 20, 20, 30, 30, 30, 30, 30, 30, 30, 30}, // Baclaran
		{15, 0, 15, 15, 15, 15, 15, 20, 20, 20, 20, 20, 20, 30, 30, 30, 30, 30, 30, 30}, // EDSA
		{15, 15, 0, 15, 15, 15, 15, 15, 20, 20, 20, 20, 20, 20, 30, 30, 30, 30, 30, 30}, // Libertad
		{15, 15, 15, 0, 15, 15, 15, 15, 20, 20, 20, 20, 20, 20, 20, 30, 30, 30, 30, 30}, // Gil Puyat
		{15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 20, 20, 20, 20, 20, 20, 30, 30, 30, 30}, // Vito Cruz
		{15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 20, 20, 20, 20, 20, 20, 30, 30, 30}, // Quirino
		{20, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 20, 20, 20, 20, 20, 20, 30, 30}, // Pedro Gil
		{20, 20, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 20, 20, 20, 20, 20, 30, 30}, // UN Ave
		{20, 20, 20, 20, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 20, 20, 20, 20, 30}, // Central
		{20, 20, 20, 20, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 20, 20, 20, 30}, // Carriedo
		{20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 15, 20, 20, 30}, // Doroteo Jose
		{20, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 20, 20, 20}, // Bambang
		{30, 20, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 15, 20, 20}, // Tayuman
		{30, 30, 20, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 0, 15, 15, 15, 15, 20, 20}, // Blumentritt
		{30, 30, 30, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 20, 20}, // Abad Santos
		{30, 30, 30, 30, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 15, 0, 15, 15, 15, 20}, // R. Papa
		{30, 30, 30, 30, 30, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 15, 0, 15, 15, 20}, // 5th Avenue
		{30, 30, 30, 30, 30, 30, 20, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 0, 15, 15}, // Monumento
		{30, 30, 30, 30, 30, 30, 30, 30, 20, 20, 20, 20, 20, 20, 20, 15, 15, 15, 0, 15}, // Balintawak
		{30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 20, 20, 20, 20, 20, 20, 15, 15, 0}  // Roosevelt
	},
	{
		// Stored Value Fares
		{0, 12, 13, 13, 14, 15, 16, 17, 18, 19, 19, 20, 21, 21, 22, 23, 24, 25, 27, 29}, // Baclaran
		{12, 0, 12, 13, 14, 15, 15, 16, 17, 18, 19, 19, 20, 21, 22, 22, 23, 24, 27, 29}, // EDSA 
		{13, 12, 0, 12, 13, 14, 14, 15, 16, 17, 18, 18, 19, 20, 21, 21, 22, 23, 26, 28}, // Libertad 
		{13, 13, 12, 0, 12, 13, 14, 14, 16, 16, 17, 18, 18, 19, 20, 21, 22, 23, 25, 27}, // Gil Puyat
		{14, 14, 13, 12, 0, 12, 13, 13, 15, 15, 16, 17, 17, 18, 19, 20, 21, 22, 24, 26}, // Vito Cruz
		{15, 15, 14, 13, 12, 0, 12, 13, 14, 14, 15, 16, 16, 17, 18, 19, 20, 21, 23, 25}, // Quirino
		{16, 15, 14, 14, 13, 12, 0, 12, 13, 14, 14, 15, 16, 16, 17, 18, 19, 20, 22, 24}, // Pedro Gil
		{17, 16, 15, 14, 13, 13, 12, 0, 12, 13, 14, 14, 15, 16, 17, 17, 18, 19, 22, 23}, // UN Ave 
		{18, 17, 16, 16, 15, 14, 13, 12, 0, 12, 12, 13, 14, 14, 15, 16, 17, 18, 20, 22}, // Central
		{19, 18, 17, 16, 15, 14, 14, 13, 12, 0, 12, 12, 13, 14, 15, 15, 16, 17, 20, 22}, // Carriedo
		{19, 19, 18, 17, 16, 15, 14, 14, 12, 12, 0, 12, 12, 13, 14, 15, 15, 17, 19, 21}, // Doroteo Jose 
		{20, 19, 18, 18, 17, 16, 15, 14, 13, 12, 12, 0, 12, 12, 13, 14, 15, 16, 18, 20}, // Bambang 
		{21, 20, 19, 18, 17, 16, 16, 15, 14, 13, 12, 12, 0, 12, 13, 13, 14, 15, 18, 20}, // Tayuman
		{21, 21, 20, 19, 18, 17, 16, 16, 14, 14, 13, 12, 12, 0, 12, 13, 14, 15, 17, 19}, // Blumentritt
		{22, 22, 21, 20, 19, 18, 17, 17, 15, 15, 14, 13, 13, 12, 0, 12, 13, 14, 16, 18}, // Abad Santos
		{23, 22, 21, 21, 20, 19, 18, 17, 16, 15, 15, 14, 13, 13, 12, 0, 12, 13, 15, 17}, // R. Papa
		{24, 23, 22, 22, 21, 20, 19, 18, 17, 16, 15, 15, 14, 14, 13, 12, 0, 12, 15, 16}, // 5th Avenue
		{25, 24, 23, 23, 22, 21, 20, 19, 18, 17, 17, 16, 15, 15, 14, 13, 12, 0, 13, 15}, // Monumento
		{27, 27, 26, 25, 24, 23, 22, 22, 20, 20, 19, 18, 18, 17, 16, 15, 15, 13, 0, 13}, // Balintawak
		{29, 29, 28, 27, 26, 25, 24, 23, 22, 22, 21, 20, 20, 19, 18, 17, 16, 15, 13, 0}  // Roosevelt
	}
};

int main()
{ 
	// Some greetings.
	printf("Welcome to LRT Line 1!\n\n");

	
	// Initialize beep card balance as well as the initial beep status.
	float beep_card_balance = 0.0;
	int beep_card_status = 0;

	// If the user has a beep card, then beep_card_status should be equal to 1, otherwise 0.
	beep_check(&beep_card_balance, &beep_card_status);


	// Declare origin and destination for indexing in the fare_matrix later.
	int origin, destination;
	
	// This function modifies the values inside origin and destination, based on user input.
	get_stations(&origin, &destination);
	
	// Because index zero.
	--origin;
	--destination;


	// The fare is then looked up using the 3D array.
	int fare = fare_matrix[beep_card_status][origin][destination];

	// Store the station names to pass later.
	char *origin_station = *(station_names + origin);
	char *destination_station = *(station_names + destination);

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
	reload_amount = get_int(prompt, "0123456789.\n", MIN_RELOAD, MAX_RELOAD - *beep_card_balance);
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
	printf("\nA new beep card costs 100.00 PHP, 30.00 for the card, 70.00 for the initial load.");
	char buffer = get_char("\nWould you like to avail a beep card? [Y/N] >> ", "YyNn\n");

	float beep_price = 0.0;
	if(buffer == 'Y' || buffer == 'y') 
	{
		// Update the beep status to 1 since the user said yes in availing a new card.
		*beep_card_status = 1;

		// Ask for the payment, the minimum price of a beep card today is 100 pesos.
		beep_price = get_float("\nPlease enter your payment amount. [100-1000] >> ", "0123456789.\n", 100.0, 1000.0);
		
		// Print the user's change and update them on their new beep card balance.
		printf("\nYour change is %.2f\n", beep_price - 100);
		printf("\nYour new beep card has a balance of 70 PHP.\n");

		// Set the beep balance to 70 pesos
		*beep_card_balance = INITIAL_BEEP_CARD_BALANCE;

		// Ask the user if they want to reload immediately.
		char buffer = get_char("Would you like to immediately reload your new beep card? [Y/N] >> ", "YyNn\n");
		if(buffer == 'Y' || buffer == 'y')
			beep_reload(beep_card_balance);
	}
}

// This function checks the existence of a beep card and sells the user a new one if they don't already have it.
void beep_check(float *beep_card_balance, int *beep_card_status)
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
	for(int i = 0, j = STATION_COUNT/2; i < STATION_COUNT/2; i++, j++)
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