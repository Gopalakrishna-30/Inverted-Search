#include "inverted.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int update_database(M_node *HT[], F_node **head)
{
    // Prevent duplicate update
    if(db_created == 1) // Check if database is already created
    {
        printf("Database already created. Cannot update again!\n");// Show message
        return FAILURE;// Exit function
    }
    char filename[50]; // Buffer to store backup file name
    printf("Enter backup file name: "); // Prompt user for backup file name
    scanf("%s", filename);   // Read backup file name from user

    FILE *fptr = fopen(filename, "r"); // Open backup file in read mode
    if(fptr == NULL) // Check if file opened successfully
    {
        printf("ERROR: Unable to open file\n"); // Print error message
        return FAILURE; // Exit function
    }
    char line[200]; // Buffer to store each line read from backup file
    while(fgets(line, sizeof(line), fptr)) // Read each line from backup file
    {
        line[strcspn(line, "\n")] = '\0'; // Remove newline character from end of line

        char *token = strtok(line, "#;"); // Tokenize line using '#' and ';' as delimiters
        if(token == NULL) // Check if token is valid
            continue; // Skip invalid lines

        token = strtok(NULL, "#;"); // Get the word (first token is index, second token is word)
        if(token == NULL)  // Check if word token is valid
            continue;      // Skip if word token is missing

        M_node *new_main = malloc(sizeof(M_node)); //   Allocate memory for new main node
        if(!new_main) // Check if memory allocation was successful
        {
            printf("Memory allocation failed\n"); // Print error message
            continue; // Skip if memory allocation failed
        }
        strcpy(new_main->word, token); // Copy word into main node
        token = strtok(NULL, "#;"); // Get file count (third token)
        if(token == NULL) // Check if file count token is valid
        {
            free(new_main); // Free allocated main node if file count is missing
            continue;// Skip if file count token is missing
        }
        new_main->file_count = atoi(token);  // convert file count from string to integer
        new_main->sub_link = NULL;           // initialize sub node link to NULL
        new_main->main_link = NULL;          // initialize main node link to NULL

        if(new_main->file_count <= 0)        // check if file count is invalid
        {
            free(new_main);                  // free allocated memory for main node
            continue;                        // skip this entry and move to next line
        }
        S_node *last = NULL;   // Pointer to keep track of the last sub node for linking
        for(int i = 0; i < new_main->file_count; i++) // Loop through the number of files for the word
        {
            char *fname = strtok(NULL, "#;");   // Get file name (next token after file count)
            char *count = strtok(NULL, "#;");   // Get word count in the file (next token after file name)
            if(fname == NULL || count == NULL)  // Check if file name and word count tokens are valid
            {
                printf("Invalid file format\n"); // Print error message for invalid format
                break;    // exit
            }
            S_node *new_sub = malloc(sizeof(S_node)); // Allocate memory for new sub node
            if(!new_sub)                              // Check if memory allocation was successful
            {
                printf("Memory allocation failed\n");  // Print error message
                break; // Skip if memory allocation failed
            }
            strcpy(new_sub->filename, fname);  // Copy file name into sub node
            new_sub->word_count = atoi(count); // Convert word count to integer and store in sub node
            new_sub->sub_link = NULL;          // Initialize sub link to NULL

            if(new_main->sub_link == NULL)    // If this is the first sub node, link it directly to the main node
                new_main->sub_link = new_sub; // Link first sub node to main node
            else                              // If this is not the first sub node, link it to the last sub node
                last->sub_link = new_sub;    // Link new sub node to the last sub node

            last = new_sub;          // Update last pointer to the new sub node
        }
        int index = get_index(new_main->word); // Get hash index for the word
        new_main->main_link = HT[index];// Insert new main node at the beginning of the list at the hash index
        HT[index] = new_main; // Update hash table to point to new main node
    }
    fclose(fptr); // Close backup file after reading
    db_created = 1; // Mark database as created
    printf("Database updated successfully from backup file\n"); // Success message
    return SUCCESS; // Return success status
}