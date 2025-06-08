#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Contact {
    string name;
    string phone;
    string email;
};


void showMenu() {
    cout << "\nContact Book - Contact Management\n";
    cout << "1. Add contact\n";
    cout << "2. Display all contacts\n";
    cout << "3. Edit contact\n";
    cout << "4. Delete contact\n";
    cout << "5. Find contact\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}


void addContact(vector<Contact>& contacts) {
    Contact newContact;
    cout << "Enter name: ";
    cin.ignore();  
    getline(cin, newContact.name);
    cout << "Enter phone number: ";
    getline(cin, newContact.phone);
    cout << "Enter email: ";
    getline(cin, newContact.email);
    
    contacts.push_back(newContact); 
    cout << "Contact added successfully!\n";
}


void showContacts(const vector<Contact>& contacts) {
    if (contacts.empty()) {
        cout << "Contact book is empty!\n";
        return;
    }
    
    cout << "\nContact List:\n";
    for (const auto& contact : contacts) {
        cout << "Name: " << contact.name << ", Phone: " << contact.phone << ", Email: " << contact.email << endl;
    }
}


void editContact(vector<Contact>& contacts) {
    string name;
    cout << "Enter the name of the contact to edit: ";
    cin.ignore();  // To ignore any leftover newline character in the buffer
    getline(cin, name);
    
    for (auto& contact : contacts) {
        if (contact.name == name) {
            cout << "Edit phone number (current: " << contact.phone << "): ";
            getline(cin, contact.phone);
            cout << "Edit email (current: " << contact.email << "): ";
            getline(cin, contact.email);
            cout << "Contact updated!\n";
            return;
        } 
    }
    
    cout << "No contact found with the name " << name << "!\n";
}


void deleteContact(vector<Contact>& contacts) {
    string name;
    cout << "Enter the name of the contact to delete: ";
    cin.ignore();  
    getline(cin, name);
    
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->name == name) {
            contacts.erase(it);
            cout << "Contact deleted!\n";
            return;
        }
    }
    
    cout << "No contact found with the name " << name << "!\n";
}


void findContact(const vector<Contact>& contacts) {
    string name;
    cout << "Enter the name of the contact to find: ";
    cin.ignore(); 
    getline(cin, name);
    
    for (const auto& contact : contacts) {
        if (contact.name == name) {
            cout << "Contact found:\n";
            cout << "Name: " << contact.name << ", Phone: " << contact.phone << ", Email: " << contact.email << endl;
            return;
        }
    }
    
    cout << "No contact found with the name " << name << "!\n";
}

int main() {
    vector<Contact> contacts;  
    int choice;
    
    do {
        showMenu(); 
        cin >> choice;
        
        switch (choice) {
            case 1:
                addContact(contacts);
                break;
            case 2:
                showContacts(contacts);
                break;
            case 3:
                editContact(contacts);
                break;
            case 4:
                deleteContact(contacts);
                break;
            case 5:
                findContact(contacts);
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please choose again.\n";
        }
    } while (choice != 6);
    
    return 0;
}