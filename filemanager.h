#pragma once
#include <iostream>
#include <vector>
#include "contactmanager.h"

void saveContact(Contact con);
void deleteContact(Contact con);
std::vector<Contact> getAllContacts();