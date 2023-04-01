#include <stdio.h>
#include <string.h>
#define MAX 100

int beep_check();
void print_stations(char *station_names[], int size);
int get_station(char *);

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

    // This function simply prints the station_names array by iterating through it linearly.
	print_stations(station_names, sizeof(station_names)/sizeof(station_names[0]));

    // This function will output an integer that corresponds to the index number of the chosen station.
	int origin = get_station("Current");
    int destination = get_station("Destination");
	
	// If the user input the same station twice, the program will end.
	if(origin == destination)
        printf("\nOrigin and Destination cannot be the same.\n\n");
    else
        printf("\nGoing from %s to %s will cost you %d pesos.\n\n", station_names[origin], station_names[destination], fare_matrix[beep][origin][destination]);
	
	return 0;
}

// This function will ask the user if they have a beep card.
int beep_check()
{
    char buffer[MAX];
	// while(1) is usually not a good idea, but one can use break; 
		// or in the case of functions, use return; to end the loop.
    while(1)
    {
        printf("Do you have a beep card? (Y/N): ");
        fgets(buffer, sizeof(buffer), stdin);
		
		// The strlen is used to check if the input exceeds one character.
		// It is set to != 2 because the newline character is factored in the calculation.
		// So if a user were to input "Y", the fgets actually reads "Y\n"
		// If a user were to input "Yy" for example, fgets will read "Yy\n" which is 3 characters, 
			// therefore it will not pass the if statement.
		// If a user were to just press enter, fgets will read "\n" which amounts to only 1 character,
			// but the strlen requires 2, so it also won't pass.
		// The rest of the if statement is there to limit the user to input only these characters: "Y y N n"
        if(strlen(buffer) != 2 || (buffer[0] != 'Y' && buffer[0] != 'y' && buffer[0] != 'N' && buffer[0] != 'n'))
		{
        	// The strcpy resets the value of the buffer for the next loop.
			strcpy(buffer, "");
        	printf("\n\t* Invalid input. Please enter Y or N.\n\n");
		}
        else
        {
            // If the user input passes the error checking, this next if will return a 1 if the user inputted either 'Y' or 'y'
            	// otherwise, it will return 0.
			if(buffer[0] == 'Y' || buffer[0] == 'y')
                return 1;
            else
                return 0;
        }
    }
}

// This function just prints the station_names array for the user.
void print_stations(char *station_names[], int size)
{
    printf("\n");
    // For the sake of space constraints, a second integer j is initialized to start at the halfway point of the array index,
    	// printing the stations side by side, effectively creating two columns.
	for(int i = 0, j = size/2; i < size/2; i++, j++)
		printf("[%d] %s\t\t[%d] %s\n", i, station_names[i], j, station_names[j]);
	printf("\nRefer to the list above.\n");
}
// This function will only let the user input a number from 0 to 19.
int get_station(char *station)
{
    char buffer[MAX];
    int user_input;

    while (1) {
		// Instead of using another if else, this function utilizes a string input to determine what to print in front of the Station number.
    		// So if the function was called with the string "Origin", then the %s will be replaced with the word "Origin".
        printf("Please enter your %s Station number [0-19]: ", station);
        fgets(buffer, sizeof(buffer), stdin);
		
		// The strspn function checks if the buffer contains the characters "0123456789\n".
			// It includes the \n character because of fgets.
			// This function will count the number of characters found till it sees an invalid character.
			// For example, if we have a buffer input of "g12a3a\n", it will return 2 because a is not inside "0123456789\n".
		// It then checks against the length of the buffer.
			// If they're not equal, that means that the buffer contains characters that doesn't belong inside "0123456789\n".
        if(strspn(buffer, "0123456789\n") != strlen(buffer))
        {
            // The strcpy resets the value of the buffer for the next loop.
			strcpy(buffer, "");
            printf("\n\t* Invalid input. Please enter a number between 0 and 19.\n\n");
            continue;
        }
        
        // The sscanf is a function that reads a formatted input from a string.
			// In this case, it was called with a %d, meaning the sscanf will look for an integer inside the buffer string.
			// It will then assign this value inside the address of the declared integer called user_input.
		// The if statement here simply asks if the sscanf has successfully read one and only one integer from the buffer string.
        if(sscanf(buffer, "%d", &user_input) != 1)
        {
			strcpy(buffer, "");
            printf("\n\t* Invalid input. Please enter a number between 0 and 19.\n\n");
            continue;
        }
        
		// When both error checks have passed, this last one will finally check if the user input is within the array index range of 0 to 19.
		if(user_input < 0 || user_input > 19) 
        {
            strcpy(buffer, "");
			printf("\n\t* Invalid input. Please enter a number between 0 and 19.\n\n");
            continue;
        }
        return user_input;
    }
}

