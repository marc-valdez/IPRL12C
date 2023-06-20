#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

#define MAX 256
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

void cprintf(const TextColor INPUT, const char *buffer, ...);

int is_empty(const char *buffer);
int has_whitespace(const char *buffer);
int starts_or_ends_with_dot(const char *buffer);

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
            cprintf(RED, "\n! Invalid input. Please enter a numeric value.\n");
            continue;
        }

        char remaining[MAX];
        if(sscanf_s(buffer, "%f%s", (float *)user_input, remaining) != 1)
        {
            cprintf(RED, "\n! Invalid input. Please refrain from using non-numeric characters.\n");
            continue;
        }

        if(sscanf_s(buffer, "%d%[.]%s", user_input, remaining, remaining) != 1)
        {
            cprintf(YELLOW, "\n! Invalid input. Please enter a whole number.\n");
            continue;
        }

        if(*user_input < (int)min || *user_input >(int)max)
        {
            cprintf(YELLOW, "\n! Input out of range. Please enter a number between %d and %d (inclusive).\n", (int)min, (int)max);
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
            cprintf(RED, "\n! Invalid input. Please enter a numeric value.\n");
            continue;
        }

        char remaining[MAX];
        if(sscanf_s(buffer, "%f%s", user_input, remaining) != 1)
        {
            cprintf(YELLOW, "\n! Invalid input. Please enter a whole number.\n");
            continue;
        }

        if(*user_input < (float)min || *user_input >(float)max)
        {
            cprintf(YELLOW, "\n! Input out of range. Please enter a number between %.2f and %.2f (inclusive).\n", (float)min, (float)max);
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
            cprintf(RED, "\n! Invalid input. Please enter a numeric value.\n");
            continue;
        }

        char remaining[MAX];
        if(sscanf_s(buffer, "%lf%s", user_input, remaining) != 1)
        {
            cprintf(YELLOW, "\n! Invalid input. Please enter a whole number.\n");
            continue;
        }

        if(*(double *)user_input < (double)min || *(double *)user_input >(double)max)
        {
            cprintf(YELLOW, "\n! Input out of range. Please enter a number between %.2lf and %.2lf (inclusive).\n", (double)min, (double)max);
            continue;
        }

        return;
    }
}

char get_char(const char *va_prompt, ...)
{
    char prompt[MAX];

    va_list args;
    va_start(args, va_prompt);
    vsprintf_s(prompt, strlen(va_prompt) + 1, va_prompt, args);
    va_end(args);

    char buffer[MAX], user_input[MAX];
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
            cprintf(YELLOW, "\n! Invalid input. Please enter a single character.\n");
            continue;
        }

        if(strlen(user_input) != 1)
        {
            cprintf(YELLOW, "\n! Invalid input. Please enter a single character.\n");
            continue;
        }

        return user_input[0];
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
            cprintf(YELLOW, "\n! Invalid input. Please enter a string of characters.\n");
            continue;
        }

        if((int)strlen(user_input) > limit)
        {
            cprintf(YELLOW, "\n! Invalid input. Character limit is %d characters.\n", limit);
            continue;
        }

        return;
    }
}

int is_empty(const char *buffer)
{
    if(buffer[0] == '\0')
    {
        cprintf(RED, "\n! Input cannot be empty. Please enter a value.\n");
        return 1;
    }
    return 0;
}

int has_whitespace(const char *buffer)
{
    if(strchr(buffer, ' ') != NULL)
    {
        cprintf(RED, "\n! Invalid input. Please try again without using whitespace characters.\n");
        return 1;
    }
    return 0;
}

int starts_or_ends_with_dot(const char *buffer)
{
    if(buffer[0] == '.' || buffer[strlen(buffer) - 1] == '.')
    {
        cprintf(RED, "\n! Invalid input. Please enter a value that does not start or end with a period (.) character.\n");
        return 1;
    }
    return 0;
}

void cprintf(const TextColor INPUT, const char *buffer, ...)
{
    va_list args;
    va_start(args, buffer);

    printf("%s[%dm", COLOR, INPUT);
    vprintf(buffer, args);
    printf("%s[%dm", COLOR, DEFAULT);

    va_end(args);
}

void exit_prompt(const char *prompt)
{
    system("cls");
    printf(prompt);
    system("pause");
    exit(0);
}

char yes_or_no(const char *prompt)
{
    while(true)
    {
        char buffer[MAX];
        get_string(buffer, 1, prompt);

        if(strspn(buffer, "YyNn") != strlen(buffer))
        {
            cprintf(YELLOW, "\n! Invalid input. Please enter Y or N to continue.\n");
            continue;
        }

        return buffer[0];
    }
}