# Expense-Tracker (C++)
A console-based Expense Tracker in C++ that lets you add, view, search, and delete expenses, with category-wise totals and automatic file saving.

## Features

- Add expenses with amount, category, date, and description
- View all expenses in a formatted table
- Delete an expense by ID
- Search expenses by category
- View total amount spent
- Category-wise spending summary
- Automatic saving and loading of data from `expenses.txt`
- Input validation to prevent invalid entries

## Concepts Used

- Structures and classes (OOP)
- Vectors (STL)
- File handling (`ifstream`, `ofstream`)
- String manipulation
- Menu-driven program design
- Input validation

## How to Run

1. Clone the repository:
   ```
   git clone https://github.com/totallynotparag/expense-tracker.git
   cd expense-tracker
   ```
2. Compile:
   ```
   g++ expense_tracker.cpp -o expense_tracker
   ```
3. Run:
   ```
   ./expense_tracker
   ```
   (On Windows: `expense_tracker.exe`)

## Sample Menu

```
===== EXPENSE TRACKER =====
1. Add expense
2. View all expenses
3. Delete expense
4. Search by category
5. Show total spent
6. Category summary
0. Save and exit
```

## Future Improvements

- Edit existing expenses
- Filter by month or date range
- Sort by amount or date
- Export to CSV
- Budget limits and alerts
## Author

totallynotparag
