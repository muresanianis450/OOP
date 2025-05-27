# 🧠 Qt Item Filter Application

This is a Qt-based GUI application for managing and filtering categorized items. It allows users to view all items, filter them by category, or dynamically search by name or category.

---

## 📦 Features

- ✅ **Display all items** in a sorted list
- 🔍 **Live search** by name or category (partial matches)
- 📂 **Filter by category** using an input box and button
- 📋 **Preview selected item** in the category input field

---

## 🖥️ How It Works

### Main List (`listWidgetAllItems`)
- Shows all items sorted.
- Updates in real time based on input in the "Filter the initial list" field.

### Dynamic Search
- Enter a keyword in the **Filter the initial list** input.
- Matches against both **category** and **name** (case-sensitive).
- Example:
    - Typing `D` shows: `Drinks`, `Dairy`.

### Filter by Category
- Enter a category (e.g., `Dairy`) in the **Display by category** field.
- Press the **Search by category** button or hit `Enter`.
- Matching items appear in a second list below.

### Select Item
- Clicking an item from the main list shows its full string in the category field.

---

## 🧾 Item Format

```
<Category>|<Name>|<Quantity>
Drinks|Orange Juice|6
Dairy|Milk|1
Sweets|Chocolate|3
```
