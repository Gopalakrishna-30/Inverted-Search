#include "inverted.h"   // Include header file which has structure definitions and function declarations

void save_database(M_node *HT[])   // Function to save database into a file
{
    char filename[30];            // Declare array to store file name entered by user

    printf("\nEnter the filename to save the database: ");   // Ask user for file name
    scanf("%s", filename);   // Read file name from user

    FILE *fptr = fopen(filename, "w");   // Open file in write mode

    if(fptr == NULL)   // Check if file is opened successfully or not
    {
        printf("ERROR: Unable to file open\n");   // Print error message
        return;                                  // Exit function if file not opened
    }

    // Traverse all hash table indexes from 0 to 26
    for(int i = 0; i < 27; i++)
    {
        if(HT[i] == NULL)   // Check if there is any data at this index
        {
            continue;   // Skip to next index if no data
        }
        M_node *temp = HT[i];   // Point temp to current index of hash table

        // Traverse through main nodes (words) at this index
        while(temp != NULL)
        {
              
                fprintf(fptr, "#%d;%s;%d",i, temp->word, temp->file_count);  
                // Write word and number of files into file

                S_node *sub_temp = temp->sub_link;   // Point to sub node (file details)

                // Traverse through all sub nodes (files)
                while(sub_temp != NULL)
                {
                    fprintf(fptr, ";%s;%d;", sub_temp->filename, sub_temp->word_count);  
                    // Write file name and how many times word appears

                    sub_temp = sub_temp->sub_link;   // Move to next sub node
                }

                fprintf(fptr, "#\n");   // Move to next line after writing one word entry

            temp = temp->main_link;   // Move to next main node (next word)
        }
    }
    fseek(fptr, 0, SEEK_END);   // Move file pointer to end of file to ensure all data is written
    long file_size = ftell(fptr);   // Get current file size after writing data
    rewind(fptr);   // Move file pointer back to beginning of file for reading

    fclose(fptr);   // Close the file after writing all data
    if(file_size > 0)   // Check if file size is greater than 0 to confirm data was written
    {
        printf("Database saved successfully to %s\n\n", filename);   // Print success message
    }
    else
    {
        printf("ERROR: Failed to save database\n\n");   // Print error message if file size is 0
    }
}