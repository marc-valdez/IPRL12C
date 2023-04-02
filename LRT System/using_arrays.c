#include <stdio.h>
#include <string.h>
#include "valdez.h"

int beep_check();
void get_stations(char *station_names[], int station_count, int *origin, int *destination);
void print_stations(char *station_names[], int size);
void calculate_change(int beep, int fare);

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

    // If the user has a beep card, then beep should be equal to 1, otherwise 0.
	int beep = beep_check();

	// This function modifies the values inside origin and destination, based on user input.
	int origin, destination;
	get_stations(station_names, station_count, &origin, &destination);
	
	// Because index zero.
	--origin;
	--destination;

	// The fare is then looked up using the 3D array.
	int fare = fare_matrix[beep][origin][destination];

	// The fare price is then printed, along with the station names that the user has inputted.
    printf("\nThe fare from %s to %s is %d pesos.\n\n", station_names[origin], station_names[destination], fare);
    
    // Lastly, a simple banking system that outputs the updated balance or change.
    calculate_change(beep, fare);

    // Some closing greetings.
    printf("\nThank you for riding LRT-1!\n\n");	

	return 0;
}

// This function either outputs a 1 or a 0 depending on user input.
int beep_check()
{	
    char buffer = get_char("Do you have a beep card? (Y/N) >> ", "YyNn\n");
    
    // If the user input passes the error checking, this next if will return a 1 if the user inputted either 'Y' or 'y' otherwise, it will return 0.
	if(buffer == 'Y' || buffer == 'y')
        return 1;
    else
        return 0;
}

// This function will loop if the user were to input the same origin and destination.
void get_stations(char *station_names[], int station_count, int *origin, int *destination)
{
	while(1)
	{
		// This function simply prints the station_names array by iterating through it linearly.
	    print_stations(station_names, station_count);
		
		*origin = get_int("Please enter your Current Station number [1-20] >> ", "0123456789\n", 1, 20);
		*destination = get_int("Please enter your Destination Station number [1-20] >> ", "0123456789\n", 1, 20);
		
		// This checks if the user inputted the same station twice.
		if(*origin != *destination)
			break;
		printf("\n\t* Invalid input. Origin and Destination cannot be the same.\n");
	}
}

// This function just prints the station_names array for the user.
void print_stations(char *station_names[], int size)
{
    printf("\n");
    // For the sake of space constraints, a second integer j is initialized to start at the halfway point of the array index, 
    // printing the stations side by side, effectively creating two columns.
	for(int i = 0, j = size/2; i < size/2; i++, j++)
		printf("[%d] %s\t\t[%d] %s\n", i+1, station_names[i], j+1, station_names[j]);
	printf("\nPlease refer to the list above.\n");
}

// This function will simply act as a basic banking system.
void calculate_change(int beep, int fare)
{
    float balance;

    // This will loop until the user inputs a sufficient amount of money.
    while(1)
    {
        if(beep == 1)
            balance = get_float("Please enter your beep card balance >> ", "0123456789.\n", 0.0, 10000.0);
        else
            balance = get_float("Please enter your payment amount >> ", "0123456789.\n", 0.0, 10000.0);

        if(balance >= fare)
            break;
        printf("\n\t* Insufficient balance. Please try again.\n\n");
    }

    // Update and print the balance/change.
    balance -= fare;
    if(beep == 1)
        printf("\nYour beep card balance has been updated to %.2f pesos.\n", balance);
    else
        printf("\nYour change is %.2f pesos.\n", balance);
}