#include "inverted.h"   // Include header file

/* Function definitions */
void validate_files(char *argv[], F_node **head)
{
    for(int i = 1; argv[i] != NULL; i++)   // Loop through command line arguments
    {
        char *ext = strstr(argv[i], ".txt");   // Check for ".txt" extension

        if(ext == NULL || strcmp(ext, ".txt") != 0)   // Validate file format
        {
            printf("Invalid file format for file: %s. Only .txt files are allowed.\n", argv[i]);
            continue;   // Skip invalid file
        }
        FILE *fptr = fopen(argv[i], "r");   // Open file in read mode
        if(fptr == NULL)   // Check if file exists
        {
            printf("File not found: %s. Please check the file path and try again.\n", argv[i]);
            continue;   // Skip if file not found
        }

        fseek(fptr, 0, SEEK_END);   // Move file pointer to end
        if(ftell(fptr) == 0)   // Check if file is empty
        {
            printf("File is empty: %s. Please provide a non-empty file.\n", argv[i]);
            fclose(fptr);   // Close file
            continue;       // Skip empty file
        }
        fclose(fptr);   // Close file after validation
        if(check_duplicates(*head, argv[i]) == SUCCESS)   // Check duplicate file
        {
            printf("Duplicate file: %s. This file has already been added to the database.\n", argv[i]);
            continue;   // Skip duplicate file
        }
        insert_last(head, argv[i]);   // Insert file into linked list
        printf("File added successfully: %s\n", argv[i]);   // Success message
        if(*head == NULL)   // Check if no valid files
        {
            printf("No valid files to process. Please add valid files to the database first.\n");
            print_filenames(*head);   // Print file list
            return;   // Exit function
        }
    }
}
int insert_last(F_node **head, char *f_name)
{
    F_node *new_node = (F_node *)malloc(sizeof(F_node));   // Allocate memory for new node
    if(new_node == NULL)   // Check memory allocation
    {
        printf("Memory allocation failed for file: %s\n", f_name);
        return FAILURE;
    }
    strcpy(new_node->f_name, f_name);   // Copy file name
    new_node->link = NULL;              // Set next pointer as NULL
    if(*head == NULL)   // If list is empty
    {
        *head = new_node;   // Make new node as head
        return SUCCESS;
    }
    F_node *temp = *head;   // Start from head
    while(temp->link != NULL)   // Traverse till last node
    {
        temp = temp->link;
    }
    temp->link = new_node;   // Attach new node at end
    return SUCCESS;
}
int check_duplicates(F_node *head, char *f_name)
{
    F_node *temp = head;   // Start from head

    while(temp != NULL)   // Traverse list
    {
        if(strcmp(temp->f_name, f_name) == 0)   // Compare file names
        {
            return SUCCESS;   // Duplicate found
        }
        temp = temp->link;   // Move to next node
    }

    return FAILURE;   // No duplicate found
}
int print_filenames(F_node *head)
{
    F_node *temp = head;   // Start from head

    if(temp == NULL)   // Check if list is empty
    {
        printf("No valid files to display. \n");
        return FAILURE;
    }
    else
    {
        while(temp != NULL)   // Traverse list
        {
            printf("%s\n", temp->f_name);   // Print file name
            temp = temp->link;              // Move to next node
        }
        return SUCCESS;
    }
}
int get_index(char *word)
{
    char ch = word[0];   // Take first character of word

    if(ch >= 'a' && ch <= 'z')   // If lowercase letter
    {
        return ch - 'a';   // Map to index 0–25
    }
    else if(ch >= 'A' && ch <= 'Z')   // If uppercase letter
    {
        return ch - 'A';   // Map to index 0–25
    }
    else
    {
        return 26;   // For special characters (last index)
    }
}
