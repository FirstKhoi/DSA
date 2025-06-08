#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Account {
private:
    int accountNumber;
    char name[50];
    float balance;
    char accountType;

public:
    Account() {
        accountNumber = 0;
        strcpy(name, "");
        balance = 0.0;
        accountType = ' ';
    }

    void createAccount() {
        cout << "Enter account number: ";
        cin >> accountNumber;
        cout << "Enter account holder name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter account type (C/S): ";
        cin >> accountType;
        cout << "Enter initial deposit amount: ";
        cin >> balance;
        cout << "Account created successfully!\n";
    }

    void showAccount() const {
        cout << "Account number: " << accountNumber << "\n";
        cout << "Account holder name: " << name << "\n";
        cout << "Account type: " << accountType << "\n";
        cout << "Balance: " << balance << "\n";
    }

    void deposit(float amount) {
        balance += amount;
        cout << "Amount deposited successfully!\n";
    }

    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn successfully!\n";
        } else {
            cout << "Insufficient balance!\n";
        }
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    void modifyAccount() {
        cout << "Enter new account holder name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter new account type (C/S): ";
        cin >> accountType;
        cout << "Enter new balance: ";
        cin >> balance;
        cout << "Account modified successfully!\n";
    }

    float getBalance() const {
        return balance;
    }

    void setBalance(float newBalance) {
        balance = newBalance;
    }
};

void writeAccount();
void displayAccount(int);
void modifyAccount(int);
void deleteAccount(int);
void displayAllAccounts();
void depositAmount(int);
void withdrawAmount(int);

int main() {
    int choice, accNo;
    do {
        cout << "\n\nBank Management System\n";
        cout << "1. Create new account\n";
        cout << "2. Deposit amount\n";
        cout << "3. Withdraw amount\n";
        cout << "4. Display account details\n";
        cout << "5. Modify account\n";
        cout << "6. Delete account\n";
        cout << "7. Display all accounts\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: writeAccount(); break;
            case 2: 
                cout << "Enter account number: ";
                cin >> accNo;
                depositAmount(accNo); break;
            case 3: 
                cout << "Enter account number: ";
                cin >> accNo;
                withdrawAmount(accNo); break;
            case 4: 
                cout << "Enter account number: ";
                cin >> accNo;
                displayAccount(accNo);
                break;
            case 5: 
                cout << "Enter account number: ";
                cin >> accNo;
                modifyAccount(accNo);
                break;
            case 6: 
                cout << "Enter account number: ";
                cin >> accNo;
                deleteAccount(accNo);
                break;
            case 7: displayAllAccounts(); break;
            case 8: cout << "Exiting the system...\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 8);
    return 0;
}

void writeAccount() {
    Account account;
    account.createAccount();
    ofstream outFile("accounts.dat", ios::binary | ios::app);
    outFile.write(reinterpret_cast<const char*>(&account), sizeof(Account));
    outFile.close();
    cout << "Account record saved!\n";
}

void displayAccount(int accNo) {
    Account account;
    ifstream inFile("accounts.dat", ios::binary);
    if (inFile) {
        bool found = false;
        while (inFile.read(reinterpret_cast<char*>(&account), sizeof(Account))) {
            if (account.getAccountNumber() == accNo) {
                account.showAccount();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Account not found!\n";
        }
        inFile.close();
    } else {
        cout << "File could not be opened!\n";
    }
}

void modifyAccount(int accNo) {
    Account account;
    fstream file("accounts.dat", ios::binary | ios::in | ios::out);
    if (file) {
        bool found = false;
        while (file.read(reinterpret_cast<char*>(&account), sizeof(Account)) && !found) {
            if (account.getAccountNumber() == accNo) {
                account.showAccount();
                cout << "Enter new account details:\n";
                account.modifyAccount();
                int pos = -1 * static_cast<int>(sizeof(account));
                file.seekp(pos, ios::cur);
                file.write(reinterpret_cast<const char*>(&account), sizeof(Account));
                cout << "Account record updated!\n";
                found = true;
            }
        }
        if (!found) {
            cout << "Account not found!\n";
        }
        file.close();
    } else {
        cout << "File could not be opened!\n";
    }
}

void deleteAccount(int accNo) {
    Account account;
    ifstream inFile("accounts.dat", ios::binary);
    ofstream outFile("temp.dat", ios::binary | ios::out);
    if (inFile && outFile) {
        bool found = false;
        while (inFile.read(reinterpret_cast<char*>(&account), sizeof(Account))) {
            if (account.getAccountNumber() != accNo) {
                outFile.write(reinterpret_cast<const char*>(&account), sizeof(Account));
            } else {
                found = true;
            }
        }
        inFile.close();
        outFile.close();
        remove("accounts.dat");
        rename("temp.dat", "accounts.dat");
        if (found) {
            cout << "Account deleted!\n";
        } else {
            cout << "Account not found!\n";
        }
    } else {
        cout << "File could not be opened!\n";
    }
}

void displayAllAccounts() {
    Account account;
    ifstream inFile("accounts.dat", ios::binary);
    if (inFile) {
        cout << "\n\nAccount List:\n";
        while (inFile.read(reinterpret_cast<char*>(&account), sizeof(Account))) {
            account.showAccount();
            cout << "----------------------\n";
        }
        inFile.close();
    } else {
        cout << "File could not be opened!\n";
    }
}

void depositAmount(int accNo) {
    Account account;
    fstream file("accounts.dat", ios::binary | ios::in | ios::out);
    if (file) {
        bool found = false;
        while (file.read(reinterpret_cast<char*>(&account), sizeof(Account)) && !found) {
            if (account.getAccountNumber() == accNo) {
                account.showAccount();
                float depositAmount;
                cout << "Enter amount to deposit: ";
                cin >> depositAmount;
                account.deposit(depositAmount);
                int pos = -1 * static_cast<int>(sizeof(account));
                file.seekp(pos, ios::cur);
                file.write(reinterpret_cast<const char*>(&account), sizeof(Account));
                found = true;
                cout << "Deposit successful.\n";
            }
        }
        if (!found) {
            cout << "Account not found!\n";
        }
        file.close();
    } else {
        cout << "File could not be opened!\n";
    }
}

void withdrawAmount(int accNo) {
    Account account;
    fstream file("accounts.dat", ios::binary | ios::in | ios::out);
    if (file) {
        bool found = false;
        while (file.read(reinterpret_cast<char*>(&account), sizeof(Account)) && !found) {
            if (account.getAccountNumber() == accNo) {
                account.showAccount();
                float withdrawAmount;
                cout << "Enter amount to withdraw: ";
                cin >> withdrawAmount;
                account.withdraw(withdrawAmount);
                int pos = -1 * static_cast<int>(sizeof(account));
                file.seekp(pos, ios::cur);
                file.write(reinterpret_cast<const char*>(&account), sizeof(Account));
                found = true;
                cout << "Withdrawal successful.\n";
            }
        }
        if (!found) {
            cout << "Account not found!\n";
        }
        file.close();
    } else {
        cout << "File could not be opened!\n";
    }
}
