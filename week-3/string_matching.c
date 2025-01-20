#include <stdio.h>
#include <string.h>

int opcount = 0;

int isStringMatch(char *string, char *pattern)
{
    opcount++;
    if (*pattern == '\0')
    {
        return 1;
    }
    else if (*pattern == *string)
    {
        return isStringMatch((++string), (++pattern));
    }
    else
        return 0;
}

int findLengthOfString(char* string)
{
    int i = 0;
    while (string[i] != '\0')
        i++;
    return i;
}

int findStringMatch(char *string, char *pattern)
{
    int N = findLengthOfString(string);
    opcount = 0;
    for (int i = 0; i < N-1; i++)
    {
        if (isStringMatch(string + i, pattern))
        {
            // Print N and opcount for each match attempt
            printf("%d\t%d\n", N, opcount);
            return i;
        }
    }
    printf("%d\t%d\n", N, opcount);

    return -1;
}

int main()
{
    char pattern[] = "nakul";
    
    // Iterate over different string lengths (for example, up to 20)
    for (int len = 5; len <= 20; len++) 
    {
        // Create a string of length 'len' by truncating the original string
        char string[21];
        strncpy(string, "Hi my name is nakul", len);
        string[len] = '\0'; // Ensure the string is properly null-terminated
        
        // Call findStringMatch and print the results
        findStringMatch(string, pattern);
    }

    return 0;
}
