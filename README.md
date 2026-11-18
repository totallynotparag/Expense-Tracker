# Expense-Tracker (C++)
A console-based Expense Tracker in C++ that lets you add, view, search, and delete expenses, with category-wise totals and automatic file saving.

# Expense Tracker

A simple expense tracker built in two ways: a **C++ console application** and a **responsive web app** (HTML, CSS, JavaScript). Both let you record daily expenses, organise them by category, and see where your money goes.

**Live demo:** https://totallynotparag.github.io/Expense-Tracker/

---

## Versions

| Version | File | Built with | Data storage |
|---------|------|------------|--------------|
| Console app | `expense_tracker.cpp` | C++ | `expenses.txt` file |
| Web app (Spendly) | `index.html` | HTML, CSS, JavaScript | Browser localStorage |

---

## Console App (C++)

A menu-driven program that runs in the terminal and saves your data automatically.

### Features

- Add expenses with amount, category, date, and description
- View all expenses in a formatted table
- Delete an expense by ID
- Search expenses by category
- View the total amount spent
- Category-wise spending summary
- Automatic saving and loading from `expenses.txt`
- Input validation to prevent invalid entries

### Concepts Used

- Structures and classes (OOP)
- Vectors (STL) and maps
- File handling (`ifstream`, `ofstream`)
- String manipulation
- Menu-driven program design

### How to Run

```
g++ expense_tracker.cpp -o expense_tracker
./expense_tracker
```

On Windows, run `expense_tracker.exe` instead.

### Sample Menu

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

---

## Web App (Spendly)

A clean, responsive website for tracking expenses in the browser. No installation, no backend, and no sign-up needed.

### Features

- Add, edit, and delete expenses
- Seven categories: Food, Travel, Bills, Shopping, Health, Fun, and Other
- Monthly total and all-time total
- Colour-coded spending breakdown by category
- Search by description and filter by category
- Light and dark themes (follows your system setting, with a manual toggle)
- Works on both mobile and desktop
- Amounts formatted in Indian rupees
- Data saved in your browser, so it stays after a refresh
- One-click sample data to try the app quickly

### Concepts Used

- Semantic HTML and responsive layout with CSS Grid and Flexbox
- CSS variables for theming
- JavaScript DOM manipulation and event handling
- `localStorage` for saving data
- Input validation and safe rendering of user text

### How to Run

**Option 1: Open it online.** Visit the live demo link at the top of this page.

**Option 2: Run it locally.**

1. Clone the repository:
   ```
   git clone https://github.com/totallynotparag/Expense-Tracker.git
   cd Expense-Tracker
   ```
2. Open `index.html` in any modern browser (Chrome, Edge, Firefox, or Safari).

---

## Project Structure

```
Expense-Tracker/
├── expense_tracker.cpp   # C++ console version
├── index.html            # Web version (HTML, CSS, JS in one file)
├── .gitignore
└── README.md
```

---

## Notes

- The web app stores data only in your own browser. Clearing your browser data will remove your expenses.
- The console app creates `expenses.txt` in the folder where you run it.

## Future Improvements

- Edit existing expenses in the console version
- Filter by month or date range
- Sort by amount or date
- Export data to CSV
- Monthly budget limits and alerts
- A C++ backend for the web app

## Author

Your Name

GitHub: [@totallynotparag](https://github.com/totallynotparag)
