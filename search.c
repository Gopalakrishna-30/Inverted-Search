#include "inverted.h"   // Include header file for structures and functions

void search_database(M_node *HT[])   // Function to search a word in database
{
    char word[25];   // Array to store the word entered by user
    printf("Enter the word to search: ");   // Ask user to enter word
    scanf("%s", word);   // Read word from user
    int index = get_index(word);   // Get index using hash function
    M_node *temp = HT[index];   // Point to corresponding index in hash table
    // Traverse main nodes (words) at that index
    while(temp != NULL)
    {
        if(strcmp(temp->word, word) == 0)   // Check if word matches
        {
            printf("\nword found: %s\n", temp->word);   // Print found word
            printf("Total files containing the word: %d\n", temp->file_count); // Print number of files containing that word
            S_node *sub_temp = temp->sub_link;   // Point to sub nodes (file details)
            // Traverse sub nodes to show file info
            while(sub_temp != NULL)
            {
                // Print file name and word count
                printf("File: %s, Count: %d\n\n",sub_temp->filename,sub_temp->word_count);  
                sub_temp = sub_temp->sub_link;   // Move to next sub node
            }
            return;   // Exit function after finding word
        }
        temp = temp->main_link;   // Move to next main node
    }
    printf("\nWord not found in database.\n");   // Print if word not found
}