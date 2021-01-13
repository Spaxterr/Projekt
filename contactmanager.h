#pragma once
#include <iostream>
#include <vector>
#include <map>

class Contact
{
    public:
        std::string name, email, address, phonenr, birthday, etc;

        std::string getAsString()
        {
            return "Name:" + name + "|Email:" + email + "|Address:" + address + "|PhoneNr:" + phonenr + "|Birthday:" + birthday + "|etc:" + etc + "|";
        }
};
Contact loadContact(std::string input);
std::map<int, Contact> getContactMap();
void clearConsole();
void initSearchContact();
void initCreateContact();
void initRemoveContact();
void printAllContacts(std::map<int, Contact> contactMap);