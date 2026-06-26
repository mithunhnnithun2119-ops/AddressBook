#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
//#include "populate.h"
void listContacts(AddressBook *addressBook)
{
    for (int i = 0; i < addressBook->contactCount; i++) // Loop run all saved contacts
    {
        printf("\nContact %d\n", i + 1);// Display contact number
        printf("Name  : %s\n", addressBook->contacts[i].name);// Display contact name
        printf("Phone : %s\n", addressBook->contacts[i].phone);// Display contact phone
        printf("Email : %s\n", addressBook->contacts[i].email);// Display contact email
    }
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;// Initialize contact count to zero

 loadContactsFromFile(addressBook);// Load contacts from file into address book
}

void saveAndExit(AddressBook *addressBook) {
   saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}


// (function(01)) -> function defination its finding the correct name based on conditions................
int namecheck(char name[])
{
    int letters = 0;

    // check first character must be alphabet
    if (!((name[0] >= 'a' && name[0] <= 'z') ||
          (name[0] >= 'A' && name[0] <= 'Z')))
    {
        return 0;
    }
for (int i = 0; name[i] != '\0'; i++) // run the loop
    {
        if ((name[i] >= 'a' && name[i] <= 'z') ||
            (name[i] >= 'A' && name[i] <= 'Z'))// allow only alphabets and space
        {
            letters++; // count only letters
        }
        else if (name[i] == ' ')
        {
            continue;  // space allowed
        }
        else
        {
            return 0;  // invalid character
        }
    }
    if (letters < 3)// name must have at least 3 letters
    {
        return 0;
    }

    return 1; // valid name
}

// phone number check...................................................
int phone(char number[])
{
    if (number[0] < '6' || number[0] > '9')// first number allowed only 6 to 9 
        return 0;

    for (int i = 0; i < 10; i++)// 
    {
        if (number[i] < '0' || number[i] > '9')//remaing  numeber allowed 0 t0 10
            return 0;
    }

    if (number[10] != '\0')// check the phone number its only 10 
        return 0;

    return 1;
}
// duplicate phone number find............................
int duplicate_phone(char number[], AddressBook *addressBook)
{
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].phone, number) == 0)//check the duplicate phone number using the strcmp function
        {
            return 0;//Return 0 to indicate duplication
        }
    }
    return 1;//Return 1 to indicate the phone number is unique
}
// create emailId function defination
int mail_g(char gemail[])
{
    int i = 0;
 if (gemail[0] < 'a' || gemail[0] > 'z')// First character must be lowercase letter
        return 0;
while (gemail[i] != '@')// 2. Check username part (before @)
    {
       
        if (gemail[i] == '\0') // @ must exist
            return 0;
        if (!((gemail[i] >= 'a' && gemail[i] <= 'z') ||
              (gemail[i] >= '0' && gemail[i] <= '9')))// Only lowercase letters and numbers allowed
            return 0;

        i++;
    }
// Check exact "@gmail.com"
    if (gemail[i]     == '@' &&
        gemail[i + 1] == 'g' &&
        gemail[i + 2] == 'm' &&
        gemail[i + 3] == 'a' &&
        gemail[i + 4] == 'i' &&
        gemail[i + 5] == 'l' &&
        gemail[i + 6] == '.' &&
        gemail[i + 7] == 'c' &&
        gemail[i + 8] == 'o' &&
        gemail[i + 9] == 'm' &&
        gemail[i + 10] == '\0')
    {
        return 1; // VALID
    }

    return 0;// INVALID
}

// finding the duplicate of the emailID
int duplicate_email(char email_g[], AddressBook *addressBook)
{
    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (strcmp(addressBook->contacts[i].email, email_g) == 0)//check the duplicate mail using the str cmp function
        {
            return 0;//indicate duplication number
    }
}
    return 1;//Return 1 to indicate the email is unique
}
//--------------------------------------------------------------------------------------------------------------------------
void createContact(AddressBook *addressBook)
{
    char name[30];
    char phone_number[11];
    char email_id[30];
    int attempts = 0;


    while (attempts < 3)
    {
        // Ask user to enter name
        printf("Enter the name: ");
        scanf(" %[^\n]", name);

        if (!namecheck(name))// check the name validation
        {
            attempts++;// increment the attemps when enter the wrong input
            printf("INVALID NAME. ATTEMPTS LEFT %d\n", 3 - attempts);
            continue;// retry input enter
        }

        strcpy(addressBook->contacts[addressBook->contactCount].name, name);// store the valid into address book
        break;
    }

    if (attempts == 3)// you reach maximum attemts
    {
        printf("MAXIMUM ATTEMPTS REACHED. CONTACT NOT SAVED\n");
        return;//Exit function without saving contact
    }
// phone number validation

    attempts = 0;// attempts start with 0
    while (attempts < 3)
    {
        //Ask user to enter phone number
        printf("Enter the phone number: ");
        scanf(" %10s", phone_number);

        if (!phone(phone_number))// check the phone number validation
        {
            attempts++;//increment the attemps when enter the wrong input
            printf("INVALID PHONE NUMBER PLASE ENTER THE CORRECT PHONE NUMBER WITH 10 DIGITS. ATTEMPTS LEFT %d\n", 3 - attempts);
            continue;// give the another the chance enter the valid phone numbere
        }
// check for duplicate phone number
        if (!duplicate_phone(phone_number, addressBook))
        {
            attempts++;// increment attempts find duplicate
            printf("ALREADY NUMBER FOUND PLASE ENTER THE DIFFRENT PHONE NUMBER. ATTEMPTS LEFT %d\n", 3 - attempts);
            continue;//retry input enter once
        }

        strcpy(addressBook->contacts[addressBook->contactCount].phone, phone_number);// store the valid phone number
        break ;
    

    }
    if(attempts==3)// reach maximum attempts
    {

    printf("MAXIMUM ATTEMPTS REACHED. CONTACT NOT SAVED\n");
    return;// exit function
}
// email input and validation of the mail
 attempts = 0;// attempts start with 0
    while (attempts < 3)
    {
        // ask the user enter
        printf("Enter the email ID: ");
        scanf(" %[^\n]", email_id);

        if (!mail_g(email_id))//check the validate email
        {
            attempts++;//increment the attemps when enter the wrong input
            printf("INVALID EMAIL FORMAT PLASE ENTER VALIED EMAIL. ATTEMPTS LEFT %d\n", 3 - attempts);
            continue;//retry input enter once
        }

        if (!duplicate_email(email_id, addressBook))//finding the duplicate email
        {
            attempts++;// icrement the attempts if duplicate find
            printf("EMAIL ALREADY EXISTS. ATTEMPTS LEFT %d\n", 3 - attempts);
            continue;//retry input enter once
        }

        strcpy(addressBook->contacts[addressBook->contactCount].email, email_id);// save the valid email
        addressBook->contactCount++;// Increment total contact count after successful save
        printf("CONTACT SAVED SUCCESSFULLY\n");
        return;// Exit function after succesful save
    }

    printf("MAXIMUM ATTEMPTS REACHED. CONTACT NOT SAVED\n");
}

void searchContact(AddressBook *addressBook)
{
    int choice;
    char search_key[50];
    int found = 0;// to check at least one contact is found

    printf("Search Contact By:\n");// asking user enter the choice (name , phone number, email)
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("PLASE ENTER THE YOUR CHOICE: ");// asking user enter the choice (name , phone number, email)
    scanf("%d", &choice);
    getchar();   // clear newline

    printf("PLASE ENTER WHAT YOU SELECTE THE CHOICE: ");// asking user enter search value
    scanf("%[^\n]", search_key);

    for (int i = 0; i < addressBook->contactCount; i++)
    {
        if (
            (choice == 1 && strcmp(addressBook->contacts[i].name, search_key) == 0) ||
            (choice == 2 && strcmp(addressBook->contacts[i].phone, search_key) == 0) ||
            (choice == 3 && strcmp(addressBook->contacts[i].email, search_key) == 0)
           )
        {
            printf("\nContact Found (%d)\n", i + 1);// what you enter it is true print the all contact
            printf("Name  : %s\n", addressBook->contacts[i].name);
            printf("Phone : %s\n", addressBook->contacts[i].phone);
            printf("Email : %s\n", addressBook->contacts[i].email);

            found = 1;// duplicate contacts also printed
        }
    }

    if (!found)
    {
        printf("\nContact Not Found\n");// if no matching contact is available
    }
}
void editContact(AddressBook *addressBook)
{
    char name[50];          // store name entered by user
    char new_value[50];     // store new value (name / phone / email)
    int choice;             // store user choice
    int select;             // store which duplicate contact to edit
    int count = 0;          // count how many duplicate names found
    
    printf("Enter name to edit:\n");// ask user to enter name to edit
    scanf(" %[^\n]", name);

    for (int i = 0; i < addressBook->contactCount; i++)// display all contacts having same name
    {
        if (strcmp(addressBook->contacts[i].name, name) == 0)// compare entered name with stored contact name
        {
            count++;   // increment duplicate count
            printf("%d. Name: %s  Phone: %s  Email: %s\n",
                   count,
                   addressBook->contacts[i].name,
                   addressBook->contacts[i].phone,
                   addressBook->contacts[i].email);// show duplicate contact details
        }
    }
 if (count == 0) // if no contact found with entered name
    {
        printf("Contact not found\n");
        return;   // exit function
    }
// ask user to select which contact to edit
    printf("Plase Select contact:\n");
    scanf("%d", &select);
    printf("1. Name\n");
    printf("2. Phone\n");
    printf("3. Email\n");
    printf("Enter your choice what you edit(1.Name, 2.Phone, 3.Email):\n");
    scanf("%d", &choice);
    printf("Enter new value what you select the choice :\n");// ask user to enter new value
    scanf(" %[^\n]", new_value);
    count = 0;// reset count to find selected contact

    for (int i = 0; i < addressBook->contactCount; i++)// loop again to edit selected contact only
    {
         if (strcmp(addressBook->contacts[i].name, name) == 0)// check same name again
        {
            count++;   // count duplicates again
            if (count == select)// if this is the selected contact
            {
                // edit name
                if (choice == 1)
                {
                    strcpy(addressBook->contacts[i].name, new_value);
                }
                // edit phone
                else if (choice == 2)
                {
                    strcpy(addressBook->contacts[i].phone, new_value);
                }
                // edit email
                else if (choice == 3)
                {
                    strcpy(addressBook->contacts[i].email, new_value);
                }
               else
                {
                    printf("Invalid choice\n"); // wrong choice entered
                    return;
                }
                printf("Contact updated successfully\n");
                return;   // exit after editing one contact
            }
        }
    }
}

void deleteContact(AddressBook *addressBook)// this function use delete particlular conatcts
{
    // Ask user to enter the name of the contact to delete
    char name[50];
    int found = 0;
    int serial;
    printf("Enter the name to delete: ");
    scanf(" %[^\n]", name);
    for (int i = 0; i < addressBook->contactCount; i++)//Loop through all contacts to find matching names
    {
        if (strcmp(addressBook->contacts[i].name, name) == 0)// Compare entered name with stored contact name
        {
             // Display matching contact details with index number
            printf("%d. %s  %s  %s\n",
                   i,
                   addressBook->contacts[i].name,
                   addressBook->contacts[i].phone,
                   addressBook->contacts[i].email);
            found = 1;//// Mark that at least one contact is found
        }
    }

    if (!found) // If no matching contact found, exit the function
    {
        printf("Contact not found\n");
        return;
    }
    printf("Plase enter the choice to delete: \n");// Ask user to enter the serial number of the contact to delete
    scanf("%d", &serial);

    if (serial < 0 || serial >= addressBook->contactCount)  // Check whether entered serial number is valid
    {
        printf("Invalid choice Plase enter valied1\n");
        return;
    }
    // Shift contacts to the left to remove the selected contact
    for (int j = serial; j < addressBook->contactCount - 1; j++)
    {
        addressBook->contacts[j] = addressBook->contacts[j + 1];
    }

    addressBook->contactCount--;// Reduce contact count after deletion
    printf("Contact deleted successfully\n");
}
