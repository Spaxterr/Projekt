#include <iostream>
#include "contactmanager.h"

using namespace std;

int main()
{
    while(true)
    {
        clearConsole(); // Rensa konsolen
        cout << "=====================================================" << endl << "\t\tAddressbok v1.0"    // Skriv ut menyn
        << endl << "Var god välj ett av alternativen nedan: " << endl << "1 - Lägg till en kontakt" << endl
        << "2 - Ta bort en kontakt" << endl << "3 - Visa kontakter" << endl << "4 - Sök efter kontakter" << endl << "5 - Avsluta" << endl << "=====================================================" << endl;
        char option;
        bool validInput = false;
        while(!validInput)  // Starta en loop som kör så länge användaren anger ett giltigt val
        {
            option = getchar(); // Läs valet användaren ger
            switch(option)  // Switch-sats för valet
            {
                case '1':   // Skapa kontakt
                    initCreateContact();
                    cout << "Klicka ENTER för att återvända till start-menyn.\n";
                    getchar();
                    validInput = true;
                    break;
                case '2':   // Ta bort kontakt
                    initRemoveContact();
                    cout << "Klicka ENTER för att återvända till start-menyn.\n";
                    getchar();
                    validInput = true;
                    break;
                case '3':   // Skriv ut alla kontakter
                    printAllContacts(getContactMap());
                    cout << "Klicka ENTER för att återvända till start-menyn.\n";
                    getchar();
                    validInput = true;
                    break;
                case '4':   // Sök efter kontakter
                    initSearchContact();
                    cout << "Klicka ENTER för att återvända till start-menyn.\n";
                    getchar();
                    validInput = true;
                    break;
                case '5':   // Avsluta kontakten
                    exit(1);
                default:
                    cout << "Ogiltigt alternativ, försök igen!" << endl;
                    break;
            }
        }
    }
}