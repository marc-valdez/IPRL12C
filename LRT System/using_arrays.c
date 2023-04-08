#include <stdio.h>
#include <string.h>
#include "valdez.h"

int beep_check();

void balance_check(float *beep_balance, int fare);
void beep_avail(float *beep_balance, int *beep);

void get_stations(char *station_names[], int station_count, int *origin, int *destination);

void update_balance(float *beep_balance, int fare);
void calculate_change(int fare);

int main()
{ 
	// This is a string array of all the Station names in LRT Line 1.
    char *station_names[] = {
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
    
	// This is to initialize the size of the array above for easier function passing.
	int station_count = sizeof(station_names)/sizeof(station_names[0]);

    // This is a 3d Lookup Array that contains all the fare data for each station pairing.
    	// The first dimension corresponds to the beep card, 0 if the user doesn't have it, 1 if they do.
    	// The second and third dimensions are the actual fare data.
	int fare_matrix[2][20][20] = {
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
	
	// Some greetings.
	printf("Welcome to LRT Line 1!\n\n");

	// Initialize beep card balance.
	float beep_balance = 0.0;

    // If the user has a beep card, then beep should be equal to 1, otherwise 0.
	int beep_state = beep_check();

	if(beep_state == 1)
	{
		beep_balance = get_float("\nPlease enter your beep card balance [13-10000] >> ", "0123456789.\n", 0.0, 10000.0);
		balance_check(&beep_balance, 13);
	}
	else
		beep_avail(&beep_balance, &beep_state);

	// This function modifies the values inside origin and destination, based on user input.
	int origin, destination;
	get_stations(station_names, station_count, &origin, &destination);
	
	// Because index zero.
	--origin;
	--destination;

	// The fare is then looked up using the 3D array.
	int fare = fare_matrix[beep_state][origin][destination];

	// The respective fare price is then printed, along with the station names that the user has inputted.
    if(beep_state == 1)
	{
		printf("\nThe stored value fare from %s to %s is %d PHP.\n", station_names[origin], station_names[destination], fare);
		update_balance(&beep_balance, fare);
	}
	else
	{
		printf("\nThe single journey fare from %s to %s is %d PHP.\n", station_names[origin], station_names[destination], fare);
		calculate_change(fare);
	}
   	
    // Some closing greetings.
    printf("\nThank you for riding LRT-1!\n\n");	

	return 0;
}

// This function either outputs a 1 or a 0 depending on user input.
int beep_check()
{	
    char buffer = get_char("Do you have a beep card? [Y/N] >> ", "YyNn\n");
    
    // If the user input passes the error checking, this next if will return a 1 if the user inputted either 'Y' or 'y' otherwise, it will return 0.
	if(buffer == 'Y' || buffer == 'y')
        return 1;
    else
		return 0;
}

// The minimum reload amount of a beep card is 13 pesos.
void beep_reload(float *beep_balance)
{
	float reload_amount = 0.0;
	reload_amount = get_int("\nPlease enter your reload amount. [13-10000] >> ", "0123456789.\n", 13.0, 10000.0);
	*beep_balance += reload_amount;

	printf("\nYour beep card balance has been reloaded to %.2f PHP.\n", *beep_balance);
}

// This function simply checks if the user has suffienct beep card funds.
void balance_check(float *beep_balance, int fare)
{
	while(1)
	{
		if(*beep_balance >= fare)
			break;
		printf("\n\t* Insufficient balance of %.2f PHP. Please reload.\n", *beep_balance);
		beep_reload(beep_balance);
	}
}

// This function sells the user a new beep card.
void beep_avail(float *beep_balance, int *beep_state)
{
	printf("\nA new beep card costs 100 PHP, 30 for the card, 70 for the initial load.");

	char buffer = get_char("\nWould you like to avail a beep card? [Y/N] >> ", "YyNn\n");

	float beep_price = 0.0;
	if(buffer == 'Y' || buffer == 'y')
	{
		*beep_state = 1;

		beep_price = get_float("\nPlease enter your payment amount. [100-1000] >> ", "0123456789.\n", 100.0, 1000.0);
		
		printf("\nYour change is %.2f\n", beep_price - 100);

		printf("\nYour new beep card has a balance of 70 PHP.\n");

		*beep_balance = 70.0;

		char buffer = get_char("Would you like to immediately reload your new beep card? [Y/N] >> ", "YyNn\n");
		if(buffer == 'Y' || buffer == 'y')
			beep_reload(beep_balance);
	}
}

// This function prints the selection menu for the user.
void print_menu(char *station_names[], int size)
{
    printf("\n");
    // For the sake of space constraints, a second integer j is initialized to start at the halfway point of the array index, 
    // printing the stations side by side, effectively creating two columns.
	for(int i = 0, j = size/2; i < size/2; i++, j++)
		printf("[%d] %s\t\t[%d] %s\n", i+1, station_names[i], j+1, station_names[j]);
	printf("\nPlease refer to the list above.\n");
}

// This function will loop if the user were to input the same origin and destination.
void get_stations(char *station_names[], int station_count, int *origin, int *destination)
{
	while(1)
	{
		// This function simply prints the station_names array by iterating through it linearly.
	    print_menu(station_names, station_count);
		
		*origin = get_int("\nPlease enter your Current Station number [1-20] >> ", "0123456789\n", 1, 20);
		*destination = get_int("\nPlease enter your Destination Station number [1-20] >> ", "0123456789\n", 1, 20);
		
		// This checks if the user inputted the same station twice.
		if(*origin != *destination)
			break;
		printf("\n\t* Invalid input. Origin and Destination cannot be the same.\n");
	}
}

// This function calculates the updated balance from a stored value fare.
void update_balance(float *beep_balance, int fare)
{	
	balance_check(beep_balance, fare);

	// Update and print the balance.
    *beep_balance -= fare;

    printf("\nSubtracting %.2f PHP from the fare, your beep card balance is now %.2f PHP.\n", (float) fare, *beep_balance);
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