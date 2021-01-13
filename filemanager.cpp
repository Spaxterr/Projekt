#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "contactmanager.h"

using namespace std;

void saveContact(Contact contact)
{
    ofstream myFile;
    myFile.open("contacts.txt", ofstream::out | ofstream::app);
    myFile << "Name:" << contact.name << "|Address:" << contact.address << "|PhoneNr:" << contact.phonenr << "|Birthday:" << contact.birthday << "|etc:" << contact.etc << "|" << endl;
    myFile.close();
}

void deleteContact(Contact contact)
{
    string fileStr;
    string strToIgnore = contact.getAsString();
    ifstream myInFile("contacts.txt");
    string line;
    while(getline(myInFile, line))
    {
        if (line != strToIgnore)
        {
            fileStr += line + "\n";
        }
    }
    myInFile.close();
    ofstream myOutFile("contacts.txt");
    myOutFile << fileStr;
    myOutFile.close();
}

vector<Contact> getAllContacts()
{
    vector<Contact> contacts;
    ifstream myFile("contacts.txt");
    string line;
    while (getline(myFile, line))
    {
        contacts.push_back(loadContact(line));
    }
    return contacts;
}