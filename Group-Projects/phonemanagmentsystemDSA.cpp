
#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Contact
{
    string Name;
    string Phone;
    string Email;
    Contact *prev;
    Contact *next;
};

struct PhoneBook
{
    Contact *head;
    Contact *tail;
};

PhoneBook createPhoneBook()
{
    PhoneBook phoneBook;
    phoneBook.head = NULL;
    phoneBook.tail = NULL;
    return phoneBook;
}

void addContact(PhoneBook &phoneBook, string Name, string Phone, string Email)
{
    Contact *New_Contact = new Contact;
    New_Contact->Name = Name;
    New_Contact->Phone = Phone;
    New_Contact->Email = Email;
    New_Contact->prev = NULL;
    New_Contact->next = NULL;

    if (phoneBook.head == NULL)
    {
        phoneBook.head = New_Contact;
        phoneBook.tail = New_Contact;
    }
    else
    {
        phoneBook.tail->next = New_Contact;
        New_Contact->prev = phoneBook.tail;
        phoneBook.tail = New_Contact;
    }
}

void displayContacts(const PhoneBook &phoneBook)
{
    if (phoneBook.head == NULL)
    {
        cout << "Phone book is empty." << endl;
    }
    else
    {
        Contact *current = phoneBook.head;
        while (current != NULL)
        {
            cout << "Name: " << current->Name << endl;
            cout << "Phone Number: " << current->Phone << endl;
            cout << "Email: " << current->Email << endl;
            cout << "--------------------------" << endl;
            current = current->next;
        }
    }
}

void updateContact(PhoneBook &phoneBook, string Name)
{
    Contact *current = phoneBook.head;
    bool found = false;
    while (current != NULL)
    {
        if (current->Name == Name)
        {
            found = true;
            break;
        }
        current = current->next;
    }

    if (found)
    {
        string Phone, Email, name;
        int choice;
        do
        {
            system("cls");
            cout << "Press the perdefined keys to perform required operations " << endl;
            cout << "1. Name" << endl;
            cout << "2. Phone Number " << endl;
            cout << "3. Email" << endl;
            cout << "4. To terminate " << endl;
            cout << "What do you want to update " << endl;
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << " Enter new name: ";
                cin >> name;
                current->Name = name;
                break;
            case 2:
                cout << "Enter new phone number: ";
                cin >> Phone;
                current->Phone = Phone;
                break;
            case 3:
                cout << "Enter new Email: ";
                cin >> Email;
                current->Email = Email;
                break;
            case 4:
                break;
            default:
                cout << "Inappropriate key was pressed ";
                break;
            }
        } while (choice != 4);
        cout << "Contact updated successfully." << endl;
    }
    else
    {
        cout << "Contact not found." << endl;
    }
}

void deleteContact(PhoneBook &phoneBook, string Name)
{
    Contact *current = phoneBook.head;
    bool found = false;

    while (current != NULL)
    {
        if (current->Name == Name)
        {
            found = true;
            break;
        }
        current = current->next;
    }

    if (found)
    {
        if (current == phoneBook.head && current == phoneBook.tail)
        {
            phoneBook.head = NULL;
            phoneBook.tail = NULL;
        }
        else if (current == phoneBook.head)
        {
            phoneBook.head = current->next;
            phoneBook.head->prev = NULL;
        }
        else if (current == phoneBook.tail)
        {
            phoneBook.tail = current->prev;
            phoneBook.tail->next = NULL;
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }

        delete current;

        cout << "Contact deleted successfully." << endl;
    }
    else
    {
        cout << "Contact not found." << endl;
    }
}
void deleteSameName(PhoneBook &phoneBook)
{
    Contact *curren1 = phoneBook.head;
    Contact *ptr2;
    Contact *Duplicate;
    while (curren1 != NULL && curren1->next != NULL)
    {
        ptr2 = curren1;
        while (ptr2->next != NULL)
        {
            if (curren1->Name == ptr2->next->Name)
            {
                cout << "Contacts with the same name: " << curren1->Name << endl;
                cout << "--------------------------" << endl;
                Contact *current = phoneBook.head;
                while (current != NULL)
                {
                    if (current->Name == curren1->Name)
                    {
                        cout << "Name: " << current->Name << endl;
                        cout << "Phone Number: " << current->Phone << endl;
                        cout << "Email: " << current->Email << endl;
                        cout << "--------------------------" << endl;
                    }
                    current = current->next;
                }
                string phoneToDelete;
                cout << "Enter the phone number of the contact you want to delete: ";
                cin >> phoneToDelete;

                current = phoneBook.head;
                while (current != NULL)
                {
                    if (current->Name == curren1->Name && current->Phone == phoneToDelete)
                    {
                        if (current == phoneBook.head && current == phoneBook.tail)
                        {
                            phoneBook.head = NULL;
                            phoneBook.tail = NULL;
                        }
                        else if (current == phoneBook.head)
                        {
                            phoneBook.head = current->next;
                            phoneBook.head->prev = NULL;
                        }
                        else if (current == phoneBook.tail)
                        {
                            phoneBook.tail = current->prev;
                            phoneBook.tail->next = NULL;
                        }
                        else
                        {
                            current->prev->next = current->next;
                            current->next->prev = current->prev;
                        }

                        delete current;

                        cout << "Contact deleted successfully." << endl;

                        break;
                    }
                    current = current->next;
                }

                break;
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        curren1 = curren1->next;
    }
}



void deleteSameNumber(PhoneBook &phoneBook)
{
    Contact *curren1 = phoneBook.head;
    Contact *ptr2;
    Contact *Duplicate;
    while (curren1 != NULL && curren1->next != NULL)
    {
        ptr2 = curren1;
        while (ptr2->next != NULL)
        {
            if (curren1->Phone == ptr2->next->Phone)
            {
                cout << "Contacts with the same phone number: " << curren1->Phone << endl;
                cout << "--------------------------" << endl;
                Contact *current = phoneBook.head;
                while (current != NULL)
                {
                    if (current->Phone == curren1->Phone)
                    {
                        cout << "Name: " << current->Name << endl;
                        cout << "Phone Number: " << current->Phone << endl;
                        cout << "Email: " << current->Email << endl;
                        cout << "--------------------------" << endl;
                    }
                    current = current->next;
                }
                string nameToDelete;
                cout << "Enter the name of the contact you want to delete: ";
                cin.ignore();
                getline(cin, nameToDelete);

                current = phoneBook.head;
                while (current != NULL)
                {
                    if (current->Phone == curren1->Phone && current->Name == nameToDelete)
                    {
                        if (current == phoneBook.head && current == phoneBook.tail)
                        {
                            phoneBook.head = NULL;
                            phoneBook.tail = NULL;
                        }
                        else if (current == phoneBook.head)
                        {
                            phoneBook.head = current->next;
                            phoneBook.head->prev = NULL;
                        }
                        else if (current == phoneBook.tail)
                        {
                            phoneBook.tail = current->prev;
                            phoneBook.tail->next = NULL;
                        }
                        else
                        {
                            current->prev->next = current->next;
                            current->next->prev = current->prev;
                        }

                        delete current;

                        cout << "Contact deleted successfully." << endl;

                        break;
                    }
                    current = current->next;
                }

                break;
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
        curren1 = curren1->next;
    }
}



void searchContacts(const PhoneBook &phoneBook, string Search_term)
{
    cout << "Search Results:" << endl;

    Contact *current = phoneBook.head;
    bool found = false;

    while (current != NULL)
    {
        if (current->Name.find(Search_term) == 0)
        {
            cout << "Name: " << current->Name << endl;
            cout << "Phone Number: " << current->Phone << endl;
            cout << "Email: " << current->Email << endl;
            cout << "--------------------------" << endl;
            found = true;
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No contacts found with the given Search_term." << endl;
    }
}

int main()
{
    PhoneBook phoneBook = createPhoneBook();

    int choice;
    char choice1;
    string Name, Phone, Email, Search_term;
    char name[50];
    cout << ".................                                PHONE BOOK                    .................";
    cout << endl
         << "WHAT IS YOUR NAME?" << endl;
    cin.getline(name, 40);
    system("cls");
    cout << endl
         << "############## WELCOME  " << name<<"  ###############"<<endl;
    cout << endl
         << "LET'S CREATE OUR PHONEBOOK " << name << endl;

    do
    {
        cout << "Phone Management System" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Display Contacts" << endl;
        cout << "3. Update Contact" << endl;
        cout << "4. Delete Contact" << endl;
        cout << "5. Delete Contacts with Same Name" << endl;
        cout << "6. Delete Contacts with Same Number" << endl;
        cout << "7. Search Contacts" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        try
        {
            cin >> choice;
            if (cin.fail())
            {
                throw runtime_error("Invalid input");
            }
        }
        catch (const runtime_error &e)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << e.what() << ". Please try again." << endl;
            continue;
        }
        system("cls");
        switch (choice)
        {
        case 1:
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, Name);
            do
            {
                cout << "Enter phone number: ";
                cin >> Phone;

                bool valid = true;
                for (char c : Phone)
                {
                    if (!isdigit(c))
                    {
                        cerr << "Error: Phone number must consist only of digits." << endl;
                        valid = false;
                        break;
                    }
                }
                if (valid)
                    break;
            } while (true);
            do
            {
                cout << "Enter Email: ";
                cin >> Email;

                size_t at_pos = Email.find('@');
                size_t dot_pos = Email.rfind('.');
                if (at_pos == string::npos || dot_pos == string::npos || at_pos > dot_pos)
                {
                    cerr << "Error: Invalid email address. It should at least contain '@' or '.'" << endl;
                }
                else
                {
                    break;
                }
            } while (true);

            addContact(phoneBook, Name, Phone, Email);
            cout << "Contact added successfully." << endl;
            break;

        case 2:
            displayContacts(phoneBook);
            break;

        case 3:
            cout << "Enter Name of the contact to update: ";

            cin.ignore();
            getline(cin, Name);
            updateContact(phoneBook, Name);
            break;

        case 4:
            cout << "Enter Name of the contact to delete: ";
            cin.ignore();
            getline(cin, Name);
            deleteContact(phoneBook, Name);
            break;

        case 5:
            deleteSameName(phoneBook);
            break;

        case 6:
            deleteSameNumber(phoneBook);
            break;

        case 7:
            cout << "Enter search Search_term: ";
            cin.ignore();
            getline(cin, Search_term);
            searchContacts(phoneBook, Search_term);
            break;

        case 8:
            cout << "Exiting Phone Management System." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
        cout << endl;
    } while (choice != 8);


    return 0;
}
