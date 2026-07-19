clear#include "inverted.h"   // Include header file for structures and functions

void create_database(M_node *HT[], F_node *head)   // Function to create database from files
{
    // Check if database is already created
    if(db_created == 1)
    {
        printf("Database already created. Cannot create again!\n\n");  // Show message
        return;   // Exit function
    }
    F_node *temp = head;   // Start from first file in file list
    while(temp != NULL)   // Traverse all files
    {
        FILE *fptr = fopen(temp->f_name, "r");   // Open file in read mode

        if(fptr == NULL)   // Check if file opened successfully
        {
            printf("Error opening file: %s\n", temp->f_name);  // Print error
            temp = temp->link;   // Move to next file
            continue;   // Skip current file
        }
        char word[25];   // Array to store each word from file
        while(fscanf(fptr, "%s", word) != EOF)   // Read words until end of file
        {
            int index = get_index(word);   // Get hash index using first character
            M_node *main_temp = HT[index];   // Point to main node at that index
            // Search word in main node list
            while(main_temp != NULL)
            {
                if(strcmp(main_temp->word, word) == 0)   // Check if word matches
                {
                    S_node *sub_temp = main_temp->sub_link;   // Point to sub nodes
                    // Check if file already exists in sub list
                    while(sub_temp != NULL)
                    {
                        if(strcmp(sub_temp->filename, temp->f_name) == 0)
                        {
                            sub_temp->word_count++;   // Increase word count
                            break;
                        }
                        sub_temp = sub_temp->sub_link;   // Move to next sub node
                    }
                    // If file not found in sub list
                    if(sub_temp == NULL)
                    {
                        S_node *new_sub = malloc(sizeof(S_node));   // Create new sub node
                        strcpy(new_sub->filename, temp->f_name);   // Copy file name
                        new_sub->word_count = 1;   // Initialize count
                        new_sub->sub_link = main_temp->sub_link;   // Link to existing list
                        main_temp->sub_link = new_sub;   // Insert at beginning
                        main_temp->file_count++;   // Increase file count
                    }
                    break;   // Exit main node search
                }
                main_temp = main_temp->main_link;   // Move to next main node
            }
            // If word not found in main list
            if(main_temp == NULL)
            {
                M_node *new_main = malloc(sizeof(M_node));   // Create new main node
                strcpy(new_main->word, word);   // Copy word
                new_main->file_count = 1;       // Initialize file count
                S_node *new_sub = malloc(sizeof(S_node));   // Create sub node
                strcpy(new_sub->filename, temp->f_name);   // Copy file name
                new_sub->word_count = 1;   // Initialize word count
                new_sub->sub_link = NULL;  // No next node

                new_main->sub_link = new_sub;   // Link sub node
                new_main->main_link = HT[index];   // Insert into hash table
                HT[index] = new_main;   // Update hash table
            }
        }
        fclose(fptr);   // Close file after reading
        temp = temp->link;   // Move to next file
    }
    db_created = 1;   // Mark database as created
    printf("Database created successfully\n\n");   // Success message
}