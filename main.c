/*
Name : T.Gopalakrishna
Date : 25/03/2023

Project Title : Inverted Search Engine.

Project Description:
			The Inverted Search Engine is a data structure–based project developed in C that efficiently indexes and retrieves words from multiple text files.
			It uses an inverted index technique, where each word is mapped to the list of files in which it appears, along with the frequency of occurrence.
			The system processes multiple input files, extracts words, and stores them in a hash table for fast access. 
			Each word is stored as a main node, and its corresponding file details are maintained in sub-nodes, including file names and word counts.

			This project also supports advanced operations such as searching for words, displaying the database, saving the index to a backup file, 
			and rebuilding the database from the saved file, ensuring persistence and efficiency.*/


#include "inverted.h"   // Include header file with structures and functions

int db_created = 0;    // Flag to check whether database is already created

int main(int argc, char *argv[])
{
    F_node *head = NULL;     // Head pointer for file linked list
    M_node *HT[27];          // Hash table with 27 indexes (a-z + special)

    for(int i = 0; i < 27; i++)
    {
        HT[i] = NULL;        // Initialize all hash table entries to NULL
    }

    if(argc < 2)
    {
        printf("\n=================================================\n");
        printf("============INVERTED SEARCH ENGINE===============\n");
        printf("=================================================\n");
        printf("Usage:\n");
        printf(" %s <file1> <file2> ...\n\n", argv[0]);   // Show how to run program
        printf("Description:\n");
        printf(" %s sample1.txt sample2.txt ...\n", argv[0]); // Example input
        printf("=================================================\n");
        printf("Invalid\n");   // Error message
        return FAILURE;        // Exit if no files are given
    }

    validate_files(argv, &head);   // Validate input files and create file list

    int option;   // Variable to store user choice

    do
    {
        printf("Select your choice among following operations:\n");
        printf("1. Create Database\n2. Display Database\n3. Save Database\n");
        printf("4. Search\n5. Update Database\n6. Exit\n\n");

        printf("Enter your choice : ");
        scanf("%d", &option);   // Read user input

        switch (option)
        {
            case 1:
                create_database(HT, head);   // Create database from files
                break;

            case 2:
                display_database(HT);        // Display database contents
                break;

            case 3:
                save_database(HT);           // Save database into file
                break;

            case 4:
                search_database(HT);         // Search a word in database
                break;

            case 5:
                update_database(HT, &head);  // Update database from backup file
                break;

            case 6:
                printf("Exiting the program. Goodbye!\n"); // Exit message
                break;

            default:
                printf("INFO : Please enter the valid option\n"); // Invalid choice
        }

    } while(option != 6);   // Repeat until user chooses exit

    return 0;   // End of program
}