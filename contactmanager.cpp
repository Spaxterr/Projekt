#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "filemanager.h"

void clearConsole()
{
    std::cout << std::string(100, '\n');
}


void initCreateContact()    // Metod för att påbörja skapelesen av en kontakt
{
    clearConsole();
    std::cout << "----------- [Lägg till en kontakt] -----------\n";
    Contact con;
    std::cout << "Ange namn: ";
    getchar();
    getline(std::cin, con.name);
    std::cout << "\nAnge address: ";
    getline(std::cin, con.address);
    std::cout << "\nAnge telefonnummer: ";
    getline(std::cin, con.phonenr);
    std::cout << "\nAnge födelsedatum: ";
    getline(std::cin, con.birthday);
    std::cout << "\nAnge övrig information: ";
    getline(std::cin, con.etc);

    saveContact(con);
    std::cout << "Kontakt sparad!\n";
}

void initSearchContact()    // Metod för att påbörja sökning av en kontakt
{
    clearConsole();
    std::map<int, Contact> contactMap = getContactMap();
    std::string searchTerm;
    std::cout << "Var vänlig ange en sök-term: ";
    getchar();
    std::getline(std::cin, searchTerm);
    for(size_t i = 0; i < contactMap.size(); i++)
    {
        std::string contact = contactMap[i].getAsString();
        if(contact.find(searchTerm) != std::string::npos)
        {
            Contact currContact = contactMap[i];
            std::cout << "--------------[" << (i+1) << "]--------------\n";
            std::cout << "Namn: " << currContact.name << "\nAddress: " << currContact.address << "\nTelefon Nr: " << currContact.phonenr << "\nFödelsedatum: " << currContact.birthday << "\nÖvrigt: " << currContact.etc << "\n";
            std::cout << "-------------------------------\n";
        }
    }
}

void initRemoveContact()    // Metod för att påbörja borttagelse av en kontakt
{
    std::map<int, Contact> contactMap = getContactMap();
    printAllContacts(contactMap);
    std::cout << "Var vänlig ange siffran på den kontakten du vill ta bort eller skriv 0 för att avbryta: ";
    getchar();
    std::string num;
    getline(std::cin, num);
    int newNum = std::stoi(num);
    if (newNum == 0)
        return;
    while(newNum > contactMap.size())
    {
        std::cout << "Ingen kontakt med siffra " << num << " hittades! Försök igen: ";
        std::cin >> num;
    }
    deleteContact(contactMap[newNum-1]);
    std::cout << "Kontakt " << contactMap[newNum - 1].name << " raderad!\n";
}


Contact loadContact(std::string input)  //Metod för att ladda en kontakt från contacts.txt
{
    Contact con;
    short n = 0;
    std::string key, value;
    for (size_t i = 0; i < input.length(); i++)
    {
        char curChar = input[i];
        if (curChar == ':')
        {
            n = 1;
            i++;
        }
        
        else if (curChar == '|')
        {
            n = 2;
        }

        if (n == 0)
            key += input[i];

        if (n == 1)
            value += input[i];

        if (n == 2)
        {
            if (key == "Name")
                con.name = value;
            else if (key == "Address")
                con.address = value;
            else if (key == "PhoneNr")
                con.phonenr = value;
            else if (key == "Birthday")
                con.birthday = value;
            else if (key == "etc")
                con.etc = value;
            key = "";
            value = "";
            n = 0;
        }
    }
    return con;
}

void printAllContacts(std::map<int, Contact> contactMap)    // Metod för att skriva ut alla kontakter
{
    clearConsole();
    for(size_t i = 0; i < contactMap.size(); i++)
    {
        Contact currContact = contactMap[i];
        std::cout << "--------------[" << (i+1) << "]--------------\n";
        std::cout << "Namn: " << currContact.name << "\nAddress: " << currContact.address << "\nTelefon Nr: " << currContact.phonenr << "\nFödelsedatum: " << currContact.birthday << "\nÖvrigt: " << currContact.etc << "\n";
        std::cout << "-------------------------------\n";
    }
}


std::map<int, Contact> getContactMap()  //Metod för att hämta alla kontakter till en map
{
    std::map<int, Contact> contactMap;
    std::vector<Contact> contacts = getAllContacts();
    for (size_t i = 0; i < contacts.size(); i++)
    {
        contactMap[i] = contacts.at(i);
    }
    return contactMap;
}