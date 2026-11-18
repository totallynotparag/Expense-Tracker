// Expense Tracker - simple console project in C++
// Features: add, view, delete, search by category, totals, category summary,
// and automatic saving/loading from "expenses.txt".

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <map>
#include <algorithm>
using namespace std;

struct Expense {
    int id;
    double amount;
    string category;
    string date;         // format: DD-MM-YYYY
    string description;
};

// ---------- Input helpers ----------

string readLine(const string& prompt) {
    string s;
    cout << prompt;
    getline(cin, s);
    // '|' is used as the file separator, so replace it
    replace(s.begin(), s.end(), '|', '-');
    return s;
}

double readPositiveDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value > 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "Invalid amount. Enter a number greater than 0.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int readInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "Invalid input. Enter a whole number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// ---------- Tracker class ----------

class ExpenseTracker {
private:
    vector<Expense> expenses;
    int nextId = 1;
    const string filename = "expenses.txt";

    void printHeader() const {
        cout << left << setw(5) << "ID"
             << setw(12) << "Date"
             << setw(15) << "Category"
             << setw(12) << "Amount"
             << "Description\n";
        cout << string(60, '-') << "\n";
    }

    void printRow(const Expense& e) const {
        cout << left << setw(5) << e.id
             << setw(12) << e.date
             << setw(15) << e.category
             << setw(12) << fixed << setprecision(2) << e.amount
             << e.description << "\n";
    }

    static string toLower(string s) {
        transform(s.begin(), s.end(), s.begin(),
                  [](unsigned char c) { return tolower(c); });
        return s;
    }

public:
    ExpenseTracker() { load(); }
    ~ExpenseTracker() { save(); }

    void addExpense() {
        Expense e;
        e.id = nextId++;
        e.amount = readPositiveDouble("Amount: ");
        e.category = readLine("Category (Food, Travel, Bills...): ");
        e.date = readLine("Date (DD-MM-YYYY): ");
        e.description = readLine("Description: ");
        expenses.push_back(e);
        cout << "Expense added successfully (ID " << e.id << ").\n";
    }

    void viewAll() const {
        if (expenses.empty()) {
            cout << "No expenses recorded yet.\n";
            return;
        }
        printHeader();
        for (const auto& e : expenses) printRow(e);
    }

    void deleteExpense() {
        if (expenses.empty()) {
            cout << "Nothing to delete.\n";
            return;
        }
        int id = readInt("Enter ID to delete: ");
        for (auto it = expenses.begin(); it != expenses.end(); ++it) {
            if (it->id == id) {
                expenses.erase(it);
                cout << "Expense deleted.\n";
                return;
            }
        }
        cout << "No expense found with ID " << id << ".\n";
    }

    void searchByCategory() const {
        string cat = toLower(readLine("Category to search: "));
        bool found = false;
        double total = 0;
        for (const auto& e : expenses) {
            if (toLower(e.category) == cat) {
                if (!found) printHeader();
                printRow(e);
                total += e.amount;
                found = true;
            }
        }
        if (found)
            cout << "Total for this category: " << fixed << setprecision(2) << total << "\n";
        else
            cout << "No expenses found in that category.\n";
    }

    void showTotal() const {
        double total = 0;
        for (const auto& e : expenses) total += e.amount;
        cout << "Total spent: " << fixed << setprecision(2) << total << "\n";
        cout << "Number of expenses: " << expenses.size() << "\n";
    }

    void categorySummary() const {
        if (expenses.empty()) {
            cout << "No expenses recorded yet.\n";
            return;
        }
        map<string, double> sums;
        for (const auto& e : expenses) sums[toLower(e.category)] += e.amount;
        cout << left << setw(20) << "Category" << "Total\n";
        cout << string(30, '-') << "\n";
        for (const auto& p : sums)
            cout << left << setw(20) << p.first
                 << fixed << setprecision(2) << p.second << "\n";
    }

    // ---------- File handling ----------

    void save() const {
        ofstream out(filename);
        if (!out) {
            cout << "Warning: could not save to " << filename << "\n";
            return;
        }
        for (const auto& e : expenses) {
            out << e.id << '|' << e.amount << '|' << e.category << '|'
                << e.date << '|' << e.description << '\n';
        }
    }

    void load() {
        ifstream in(filename);
        if (!in) return;  // first run, no file yet
        string line;
        while (getline(in, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string idStr, amtStr;
            Expense e;
            getline(ss, idStr, '|');
            getline(ss, amtStr, '|');
            getline(ss, e.category, '|');
            getline(ss, e.date, '|');
            getline(ss, e.description);
            try {
                e.id = stoi(idStr);
                e.amount = stod(amtStr);
            } catch (...) {
                continue;  // skip corrupted line
            }
            expenses.push_back(e);
            if (e.id >= nextId) nextId = e.id + 1;
        }
    }
};

// ---------- Main menu ----------

int main() {
    ExpenseTracker tracker;
    int choice;

    do {
        cout << "\n===== EXPENSE TRACKER =====\n"
             << "1. Add expense\n"
             << "2. View all expenses\n"
             << "3. Delete expense\n"
             << "4. Search by category\n"
             << "5. Show total spent\n"
             << "6. Category summary\n"
             << "0. Save and exit\n";
        choice = readInt("Choose an option: ");

        switch (choice) {
            case 1: tracker.addExpense(); break;
            case 2: tracker.viewAll(); break;
            case 3: tracker.deleteExpense(); break;
            case 4: tracker.searchByCategory(); break;
            case 5: tracker.showTotal(); break;
            case 6: tracker.categorySummary(); break;
            case 0: cout << "Data saved. Goodbye!\n"; break;
            default: cout << "Invalid option. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
