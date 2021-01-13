#include <iostream>
#include "contactmanager.h"

using namespace std;

int main()
{
    while(true)
    {
        clearConsole();
        cout << "=====================================================" << endl << "\t\tAddressbok v1.0"
        << endl << "Var god välj ett av alternativen nedan: " << endl << "1 - Lägg till en kontakt" << endl
        << "2 - Ta bort en kontakt" << endl << "3 - Visa kontakter" << endl << "4 - Sök efter kontakter" << endl << "5 - Avsluta" << endl << "=====================================================" << endl;
        char option;
        bool validInput = false;
        while(!validInput)
        {
            option = getchar();
            switch(option)
            {
                case '1':
                    initCreateContact();
                    cout << "Klicka ENTER för att återvända till start-menyn.\n";
                    getchar();
                    validInput = true;
                    break;
                case '2':
                    initRemoveContact();
                    cout << "Klicka ENTER för att återvända till start-menyn.\n";
                    getchar();
                    cin.get();
                    validInput = true;
                    break;
                case '3':
                    printAllContacts(getContactMap());
                    cout << "Klicka ENTER för att återvända till start-menyn.\n";
                    getchar();
                    cin.get();
                    validInput = true;
                    break;
                case '4':
                    initSearchContact();
                    cout << "Klicka ENTER för att återvända till start-menyn.\n";
                    getchar();
                    cin.get();
                    validInput = true;
                    break;
                case '5':
                    exit(1);
                default:
                    cout << "Ogiltigt alternativ, försök igen!" << endl;
                    break;
            }
        }
    }
}