# Data Processing and Storage Assignment

## **Description**
This is an **in-memory key-value database** with basic **transaction support**. You can add, update, and get key-value pairs. Transactions ensure "all-or-nothing updates", so changes are only saved when committed and discarded when rolled back.

### **Key Functions**
- **`begin_transaction()`**: Starts a new transaction.
- **`put(key, value)`**: Sets or updates the value for a key during an active transaction
- **`get(key)`**: Retrieves the value for a key from the main database or transaction database
- **`commit()`**: Finalizes changes from the transaction into the main database
- **`rollback()`**: Discards all changes made during the current transaction

---

## **How to Run**

### **Requirements**
- **C++ Compiler**: Ensure a C++ compiler (like **g++**) is installed.
- **Command Line**: Run commands in a terminal, shell, or command prompt.

### **Steps**
1. **Download the file** `InMemoryDB.cpp`.
2. **Open a terminal** in the same directory as the file.
3. **Compile the program**:
g++ -o InMemoryDB InMemoryDB.cpp
4. **Run the program**:
./InMemoryDB

---

## **Test Cases**

The test cases from Figure 2 of the assignment PDF have already been implemented in the `main()` function.

If you want to run additional test cases, you can modify the `main()` function in **InMemoryDB.cpp**.
