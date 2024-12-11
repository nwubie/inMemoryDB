#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class InMemoryDB {
private:
    unordered_map<string, int> mainDB;
    unordered_map<string, int> transactionDB;
    bool isTransaction;

public:
    // Constructor
    InMemoryDB() {
        isTransaction = false;
    }

    // Gets key value from the transaction or main DB
    int get(const string &key) {
        // If value exists in trasaction DB
        if (transactionDB.find(key) != transactionDB.end()) {
            return transactionDB[key];
        }
        // If value exists in main DB
        if (mainDB.find(key) != mainDB.end()) {
            return mainDB[key];
        }
        cout << "ERROR: Key does not exist" << endl;
        return -1;
    }

    // Updates key-value pair in transaction DB
    void put(const string &key, int value) {
        if (!isTransaction) {
            cout << "ERROR: Transaction not in progress" << endl;
            return;
        }
        transactionDB[key] = value; // Insert or update the key-value pair
        cout << "Key: " << key << " Value: " << value << endl;
    }

    // Starts a new transaction
    void begin_transaction() {
        if (isTransaction) {
            cout << "ERROR: Transaction in progress" << endl;
            return;
        }
        isTransaction = true;
        transactionDB.clear();
        cout << "Transaction started" << endl;
    }

    // Commits current transaction and updates main DB with transaction DB changes
    void commit() {
        if (!isTransaction) {
            cout << "ERROR: Transaction not in progress" << endl;
            return;
        }

        for (auto it = transactionDB.begin(); it != transactionDB.end(); ++it) {
            mainDB[it->first] = it->second;
        }

        isTransaction = false;
        transactionDB.clear();
        cout << "Transaction committed" << endl;
    }

    // Aborts all changes made in the current transaction
    void rollback() {
        if (!isTransaction) {
            cout << "ERROR: Transaction not in progress" << endl;
            return;
        }

        isTransaction = false;
        transactionDB.clear();
        cout << "Transaction rolled back" << endl;
    }
};

int main() {
    InMemoryDB db;

    /* FIG 2: EXAMPLE CASES */

    // Test case 1
    cout << "Trying to get 'A' from DB (doesn't exist):" << endl;
    int value = db.get("A");

    // Test case 2
    cout << "Trying to put 'A' with value 5 (transaction not in progress):" << endl;
    db.put("A", 5);

    // Test case 3
    cout << "Starting a new transaction:" << endl;
    db.begin_transaction();
    cout << "Trying to put 'A' with value 5" << endl;
    db.put("A", 5);
    cout << "Getting value of 'A' (should be 5):" << endl;
    value = db.get("A");
    if (value != -1) cout << "Value of A: " << value << endl;

    // Test case 4
    cout << "Updating 'A' to 6 within the transaction:" << endl;
    db.put("A", 6);

    // Test case 5
    cout << "Committing the transaction:" << endl;
    db.commit();

    // Test case 6
    cout << "Getting value of 'A' after commit (should be 6):" << endl;
    value = db.get("A");
    if (value != -1) cout << "Value of A after commit: " << value << endl;

    // Test case 7
    cout << "Starting a transaction:" << endl;
    db.begin_transaction();
    cout << "Setting B's value to 10:" << endl;
    db.put("B", 10);
    cout << "Rollback the transaction:" << endl;
    db.rollback();

    // Test case 8
    cout << "Getting value of 'B' after rollback (should not exist):" << endl;
    value = db.get("B");
    if (value != -1) cout << "Value of B after rollback: " << value << endl;

    return 0;
}
