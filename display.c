#include "inverted.h"   // Include header file for structures and functions

void display_database(M_node *HT[])   // Function to display the entire database
{
    printf("\n============ Inverted Index Database ===========\n");  
    // Print heading for output

    for(int i = 0 ; i < 27; i++)   // Loop through all hash table indexes (0 to 26)
    {
        if(HT[i] != NULL)   // Check if any data exists at this index
        {
            printf("Index [%d]:\n", i);   // Print index number
            M_node *temp = HT[i];   // Point to first main node at this index
            while(temp != NULL)   // Traverse main nodes (words)
            {
                if(temp->file_count > 0)   // Check if word exists in files
                {
                    // Print word and number of files it appears in
                    printf("Word  : %-20s | File Count: %d\n", temp->word, temp->file_count);  
                    S_node *sub_temp = temp->sub_link;  // Point to sub nodes (file details)
                    while(sub_temp != NULL)   // Traverse sub nodes
                    {
                        // Print file name and how many times word appears
                        printf("File  : %-20s | Word Count: %d\n",sub_temp->filename,sub_temp->word_count);  
                        sub_temp = sub_temp->sub_link;   // Move to next sub node
                    }
                    printf("\n");   // Print empty line for better readability
                }
                temp = temp->main_link;   // Move to next main node (next word)
            }
        }
    }
}