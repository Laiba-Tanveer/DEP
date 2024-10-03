#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Contact {
private:
    string name;
    string phoneNumber;
public:
    Contact(string name, string phoneNumber) {
        this->name = name;
        this->phoneNumber = phoneNumber;
    }
    void displayContact() const {
        cout << "Name: " << name << ", Phone Number: " << phoneNumber << endl;
    }
    string getName() const {
        return name;
    }
};
class ContactManager {
private:
    vector<Contact> contacts;
public:
    void addContact(const string& name, const string& phoneNumber) {
        Contact newContact(name, phoneNumber);
        contacts.push_back(newContact);
        cout << "Contact added successfully!\n";
    }
    void viewContacts() const {
        if (contacts.empty()) {
            cout << "No contacts to display.\n";
        } else {
            cout << "Contact List:\n";
            for (const auto& contact : contacts) {
                contact.displayContact();
            }
        }
    }
    void deleteContact(const string& name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->getName() == name) {
                contacts.erase(it);
                cout << "Contact deleted successfully!\n";
                return;
            }
        }
        cout << "Contact not found.\n";
    }
};
void displayMenu() {
    cout << "\n--- Contact Management System ---\n";
    cout << "1. Add Contact\n";
    cout << "2. View Contacts\n";
    cout << "3. Delete Contact\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}
int main() {
    ContactManager manager;
    int choice;
    string name, phoneNumber;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter phone number: ";
                getline(cin, phoneNumber);
                manager.addContact(name, phoneNumber);
                break;
            case 2:
                manager.viewContacts();
                break;
            case 3:
                cout << "Enter the name of the contact to delete: ";
                cin.ignore();
                getline(cin, name);
                manager.deleteContact(name);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 4);
    return 0;
}
