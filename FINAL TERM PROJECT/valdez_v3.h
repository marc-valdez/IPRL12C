#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include <ctype.h>

#define MAX 100

/*
 This header file utilizes ANSI escape codes to color the output.
 The custom cprintf function takes an INPUT in the form of a TextColor enum.
 It then takes a string buffer and a variadic argument list. (e.g., %d, %f, %s)
 It colors the string according to the enum INPUT, then prints it.
 Lastly, it reverts to the default output color after printing.
*/
#define COLOR "\x1B"
typedef enum TextColor {
    BLACK = 30,
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    BLUE = 34,
    MAGENTA = 35,
    CYAN = 36,
    WHITE = 37,
    DEFAULT = 0
} TextColor;
void cprintf(const TextColor INPUT, const char *buffer, ...)
{
    va_list args;
    va_start(args, buffer);

    printf("%s[%dm", COLOR, INPUT);
    vprintf(buffer, args);
    printf("%s[%dm", COLOR, DEFAULT);

    va_end(args);
}

/*
 The following functions are used to validate user input.
 The most common checks are:
 1. If the input is empty;
 2. If the input contains any whitespace;
 3. If the input starts or ends with a period/dot (.)
*/
int is_empty(const char *buffer)
{
    if(buffer[0] == '\0')
    {
        cprintf(RED, "  ! Input cannot be empty. Please enter a value.\n");
        return 1;
    }
    return 0;
}

int has_whitespace(const char *buffer)
{
    if(strchr(buffer, ' ') != NULL)
    {
        cprintf(RED, "  ! Invalid input. Please try again without using whitespace characters.\n");
        return 1;
    }
    return 0;
}

int starts_or_ends_with_dot(const char *buffer)
{
    if(buffer[0] == '.' || buffer[strlen(buffer) - 1] == '.')
    {
        cprintf(RED, "  ! Invalid input. Please enter a value that does not start or end with a period (.) character.\n");
        return 1;
    }
    return 0;
}

/*
 The following functions are used to take user input.
 Each function takes an address to an integer, float, double, or string to modify.
 For the numeric functions, a min and max value need to be specified.
 For the string function, a character limit needs to be specified.
 All functions require a string literal for the message prompt.
 It also accepts variadic arguments for the prompt (e.g., %d, %f, %s).
 There is a preprocessor defined constant called MAX to specify the maximum character length of all inputs.
*/
void get_int(int *user_input, const int min, const int max, const char *va_prompt, ...)
{
    char prompt[MAX];

    va_list args;
    va_start(args, va_prompt);
    vsprintf_s(prompt, strlen(va_prompt) + 1, va_prompt, args);
    va_end(args);

    char buffer[MAX];
    while(true)
    {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if(is_empty(buffer))
            continue;
        if(has_whitespace(buffer))
            continue;
        if(starts_or_ends_with_dot(buffer))
            continue;

        if(sscanf_s(buffer, "%d", user_input) != 1)
        {
            cprintf(RED, "  ! Invalid input. Please enter a numeric value.\n");
            continue;
        }

        char remaining[MAX];
        if(sscanf_s(buffer, "%f%s", (float *)user_input, remaining) != 1)
        {
            cprintf(RED, "  ! Invalid input. Please refrain from using non-numeric characters.\n");
            continue;
        }

        if(sscanf_s(buffer, "%d%[.]%s", user_input, remaining, remaining) != 1)
        {
            cprintf(YELLOW, "  ! Invalid input. Please enter a whole number.\n");
            continue;
        }

        if(*user_input < (int)min || *user_input >(int)max)
        {
            cprintf(YELLOW, "  ! Input out of range. Please enter a number between %d and %d (inclusive).\n", (int)min, (int)max);
            continue;
        }

        return;
    }
}

void get_float(float *user_input, const float min, const float max, const char *va_prompt, ...)
{
    char prompt[MAX];

    va_list args;
    va_start(args, va_prompt);
    vsprintf_s(prompt, strlen(va_prompt) + 1, va_prompt, args);
    va_end(args);

    char buffer[MAX];
    while(true)
    {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if(is_empty(buffer))
            continue;
        if(has_whitespace(buffer))
            continue;
        if(starts_or_ends_with_dot(buffer))
            continue;

        if(sscanf_s(buffer, "%f", user_input) != 1)
        {
            cprintf(RED, "  ! Invalid input. Please enter a numeric value.\n");
            continue;
        }

        char remaining[MAX];
        if(sscanf_s(buffer, "%f%s", user_input, remaining) != 1)
        {
            cprintf(YELLOW, "  ! Invalid input. Please enter a whole number.\n");
            continue;
        }

        if(*user_input < (float)min || *user_input >(float)max)
        {
            cprintf(YELLOW, "  ! Input out of range. Please enter a number between %.2f and %.2f (inclusive).\n", (float)min, (float)max);
            continue;
        }

        return;
    }
}

void get_double(double *user_input, const double min, const double max, const char *va_prompt, ...)
{
    char prompt[MAX];

    va_list args;
    va_start(args, va_prompt);
    vsprintf_s(prompt, strlen(va_prompt) + 1, va_prompt, args);
    va_end(args);

    char buffer[MAX];
    while(true)
    {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if(is_empty(buffer))
            continue;
        if(has_whitespace(buffer))
            continue;
        if(starts_or_ends_with_dot(buffer))
            continue;

        if(sscanf_s(buffer, "%lf", user_input) != 1)
        {
            cprintf(RED, "  ! Invalid input. Please enter a numeric value.\n");
            continue;
        }

        char remaining[MAX];
        if(sscanf_s(buffer, "%lf%s", user_input, remaining) != 1)
        {
            cprintf(YELLOW, "  ! Invalid input. Please enter a whole number.\n");
            continue;
        }

        if(*(double *)user_input < (double)min || *(double *)user_input >(double)max)
        {
            cprintf(YELLOW, "  ! Input out of range. Please enter a number between %.2lf and %.2lf (inclusive).\n", (double)min, (double)max);
            continue;
        }

        return;
    }
}

void get_string(char *user_input, const int limit, const char *va_prompt, ...)
{
    char prompt[MAX];

    va_list args;
    va_start(args, va_prompt);
    vsprintf_s(prompt, strlen(va_prompt) + 1, va_prompt, args);
    va_end(args);

    char buffer[MAX];
    while(true)
    {
        printf("%s", prompt);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        if(is_empty(buffer))
            continue;
        if(has_whitespace(buffer))
            continue;
        if(starts_or_ends_with_dot(buffer))
            continue;

        if(sscanf_s(buffer, "%s", user_input) != 1)
        {
            cprintf(YELLOW, "  ! Invalid input. Please enter a string of characters.\n");
            continue;
        }

        if((int)strlen(user_input) > limit)
        {
            cprintf(YELLOW, "  ! Invalid input. Character limit is %d characters.\n", limit);
            continue;
        }

        return;
    }
}

/*
 The following function is a simple yes or no question prompt.
 The user input is not case sensitive.
 It is up to the programmer to determine what to do next after this function returns either a Yes or No.
*/
char yes_or_no(const char *prompt)
{
    while(true)
    {
        char buffer[MAX];
        get_string(buffer, 1, prompt);

        if(strspn(buffer, "YyNn") != strlen(buffer))
        {
            cprintf(YELLOW, "  ! Invalid input. Please enter Y or N to continue.\n");
            continue;
        }

        return buffer[0];
    }
}

/*
 The following function is a simple exit prompt.
 Instead of exiting abruply, it prints a programmer defined exit message and waits for the user to press any key before exiting.
*/
void exit_prompt(const char *prompt)
{
    system("cls");
    printf(prompt);
    system("pause");
    exit(0);
}

/*
 The following function is a not so simple file open prompt.
 The simple act of concatenating two strings becomes extremely complicated once buffer overflow is considered.
 The user input is case sensitive.
*/
FILE *open_file(const char *prompt, const char *extension)
{
    char filename[MAX];
    get_string(filename, MAX, prompt);

    // Concatenate filename and extension using strncat_s
    size_t filename_length = strlen(filename);
    size_t extension_length = strlen(extension);
    size_t remaining_space = sizeof(filename) - filename_length - 1;
    size_t copy_length = remaining_space > extension_length ? extension_length : remaining_space;
    if(strncat_s(filename, sizeof(filename), extension, copy_length) != 0) {
        // Handle buffer overflow or truncation error
        printf("Error: Filename buffer overflow or truncation occurred.\n");
        return NULL;
    }

    // Open the file
    FILE *fp;
    errno_t err = fopen_s(&fp, filename, "r");
    if(err != 0) {
        // Handle file opening error
        printf("Error opening file: %s\n", filename);
        return NULL;
    }
    return fp;
}