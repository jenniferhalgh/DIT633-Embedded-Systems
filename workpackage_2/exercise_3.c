#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// -----typedefs ------- //

// structure type PERSON
typedef struct
{
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

// fp is a pointer of FILE
FILE *fp;

// Function declaration (to be extend)
PERSON input_record(void) // Reads a person’s record.
{
    PERSON input; // an instance of PERSON
    printf("\n Enter the first name:");
    scanf("%s", input.firstname);
    printf("\n Enter the last name:");
    scanf("%s", input.famname);
    printf("\n Enter the personnel number in format 'yyyymmddnnnc':");
    scanf("%s", input.pers_number);

    return input; // returning instance of PERSON
};

void write_new_file(PERSON *inrecord) // Creates a file and writes the first record
{

    if (access("persons.bin", F_OK) == 0) // if the file exists
    {
        if (remove("persons.bin") == 0) // if the file has been deleted
        {
            printf("\nThe old file has been deleted successfully.");
            strcpy(inrecord[0].firstname, "Sadhana");        // add first name in index 0
            strcpy(inrecord[0].famname, "Anandan");          // add last name in index 0
            strcpy(inrecord[0].pers_number, "20020606xxxx"); // add personnel number in index 0

            fp = fopen("persons.bin", "wb"); // Open the file in binary writing mode
            if (fp == NULL)                  // if the file was not opened
            {
                printf("\nError: file out.bin cannot be opened\n");
                exit(1); // The program exited with errors.
            }

            // Writes the record to the binary file
            fwrite(inrecord, sizeof(PERSON), 1, fp);
            printf("\nThe new file has been created successfully.");
            fclose(fp); // Close the file
        }
        else // if the file is not deleted
        {
            printf("\nThe file is not deleted.");
            printf("Try again");
        }
    }
    else // if the file does not exist
    {
        fp = fopen("persons.bin", "wb"); // Open the file in binary writing mode
            printf("Error: file out.bin cannot be opened\n");
            printf("Try again");
            exit(1); // The program exited with errors.
        
    }
};

void printfile(void) // Prints out all persons in the file
{
    PERSON record;
    fp = fopen("persons.bin", "rb"); // Open the file in binary writing mode
    if (fp == NULL)                  // if the file was not opened
    {
        printf("Error: file out.bin cannot be opened\n");
        exit(1); // The program exited with errors.
    }

    // while reading the file
    while (fread(&record, sizeof(PERSON), 1, fp))
    {
        // print every record's firstname, famname and persnumber in the file
        printf("%s %s %s\n", record.firstname, record.famname, record.pers_number);
    }
    fclose(fp); // close the file
    printf("\nAll the records have been printed.");
};

void search_by_firstname(char *name) // Prints out the person if in list
{
    int personFound = 0;
    PERSON person;

    fp = fopen("persons.bin", "rb"); // Open the file in binary writing mode
    if (fp == NULL)                  // if the file was not opened
    {
        printf("File could not open");
        exit(1); // The program exited with errors.
    }

    printf("\n Enter the name:");
    scanf("%s", name);

    // read the file
    while ((fread(&person, sizeof(PERSON), 1, fp)))
    {

        if (strcasecmp(person.firstname, name) == 0) // if the name entered is the same as the first name of a record
        {
            printf("\n%s %s %s", person.firstname, person.famname, person.pers_number); // print the attributes of the record
            personFound = 1;                                                            // variable personFound becomes 1
        }
    }
    if (personFound == 0) // if personFound is still 0
        printf("\n Person not found in this file!\n");
    fclose(fp); // close the file
}

void append_file(PERSON *inrecord) // appends a new person to the file
{
    char moreRecords;
    fp = fopen("persons.bin", "ab"); // Open the file in binary appending mode
    if (fp == NULL)                  // if the file was not opened
    {
        printf("File could not open");
        exit(1); // The program exited with errors.
    }

    fwrite(inrecord, sizeof(PERSON), 1, fp); // Writes the record to the binary file
    printf("\nPerson has been added to the database\n");
    fclose(fp); // close the file
};

int main(void)
{
    PERSON ppost;
    int num;
    char ans;
    char fname;

    printf("\nWelcome to the database of persons!\n");
    printf("1. Create a new and delete the old file.\n");
    printf("2. Add a new person to the file.\n");
    printf("3. Search for a person in the file.\n");
    printf("4. Print out all in the file.\n");
    printf("5. Exit the program.\n");
    scanf("%d", &num);

    switch (num) // based on the value of num, one of the following cases will take place
    {
    case 1:
        write_new_file(&ppost); // giving the address of ppost in the method
        printf("\nDo you want to go back to the main menu?\nY/N?");
        scanf("%s", &ans);
        if (strcasecmp(&ans, "Y") == 0) // if ans is Y or y
        {
            main(); // call the main function
        }
        else if (strcasecmp(&ans, "N") == 0) // if ans is N or n
        {
            break;
        }
        else
        {
            do // repeat until it satisfies the while condition
            {
                printf("Not a valid answer, either give a Y / y or N / n\n");
                scanf("%s", &ans);
                if (strcasecmp(&ans, "Y") == 0) // if ans is Y or y
                {
                    main();
                }
                else if (strcasecmp(&ans, "N") == 0) // if ans is N or n
                {
                    printf("Program exited");
                    exit(0); // The program exited without any errors.
                }
                // The while condition states that the value of ans must not be Y/y or N/n
            } while (strcasecmp(&ans, "Y") != 0 || strcasecmp(&ans, "N") != 0);
        }
        break;
    case 2:
        ppost = input_record();
        append_file(&ppost);
        printf("\nDo you want to go back to the main menu?\nY/N?");
        scanf("%s", &ans);
        if (strcasecmp(&ans, "Y") == 0)
        {
            main();
        }
        else if (strcasecmp(&ans, "N") == 0)
        {
            break;
        }
        else
        {
            do
            {
                printf("Not a valid answer, either give a Y / y or N / n\n");
                scanf("%s", &ans);
                if (strcasecmp(&ans, "Y") == 0)
                {
                    main();
                }
                else if (strcasecmp(&ans, "N") == 0)
                {
                    printf("Program exited");
                    exit(0); // The program exited without any errors.
                }
            } while (strcasecmp(&ans, "Y") != 0 || strcasecmp(&ans, "N") != 0);
        }
        break;
    case 3:
        search_by_firstname(&fname);
        printf("\nDo you want to go back to the main menu?\nY/N?");
        scanf("%s", &ans);
        if (strcasecmp(&ans, "Y") == 0)
        {
            main();
        }
        else if (strcasecmp(&ans, "N") == 0)
        {
            break;
        }
        else
        {
            do
            {
                printf("Not a valid answer, either give a Y / y or N / n\n");
                scanf("%s", &ans);
                if (strcasecmp(&ans, "Y") == 0)
                {
                    main();
                }
                else if (strcasecmp(&ans, "N") == 0)
                {
                    printf("Program exited");
                    exit(0); // The program exited without any errors.
                }
            } while (strcasecmp(&ans, "Y") != 0 || strcasecmp(&ans, "N") != 0);
        }
        break;
    case 4:
        printfile();
        printf("\nDo you want to go back to the main menu?\nY/N?");
        scanf("%s", &ans);
        if (strcasecmp(&ans, "Y") == 0)
        {
            main();
        }
        else if (strcasecmp(&ans, "N") == 0)
        {
            break;
        }
        else
        {
            do
            {
                printf("Not a valid answer, either give a Y / y or N / n\n");
                scanf("%s", &ans);
                if (strcasecmp(&ans, "Y") == 0)
                {
                    main();
                }
                else if (strcasecmp(&ans, "N") == 0)
                {
                    printf("Program exited");
                    exit(0); // The program exited without any errors.
                }
            } while (strcasecmp(&ans, "Y") != 0 || strcasecmp(&ans, "N") != 0);
        }
        break;
    case 5:
        printf("Program exited"); // maybe ask for "are you sure"
        break;

    default:
        break;
    }

    return (0);
}