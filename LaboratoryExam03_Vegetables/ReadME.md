# 🥦 Vegetable Families Application

This is a Qt-based C++ GUI application that helps users explore vegetables categorized by their botanical families. The application loads data from a text file, displays vegetable families, allows users to view all vegetables in a family, and provides a search function to find a specific vegetable and show its consumable parts.

---

## 🧾 Problem Statement

You are required to build a desktop application that:

- Displays a list of vegetable families.
- Shows all vegetables that belong to a selected family.
- Allows the user to search for a vegetable by name.
- Displays the consumable parts of the searched vegetable.
- Highlights the family to which the searched vegetable belongs.

---

## ✅ Application Requirements

1. **Load Data from File**
    - On startup, the application reads data from a text file named `vegetables.txt`.
    - Each line in the file contains one vegetable with its family, name, and consumable parts.

2. **Display Families**
    - The application displays all unique vegetable families found in the file.

3. **List Vegetables by Family**
    - When a user selects a family, all vegetables from that family are shown in a list.
    - Each entry shows both the name of the vegetable and its consumable parts.

4. **Search for Vegetable**
    - The user can type a vegetable’s name and press Enter or click a button to search.
    - If the vegetable exists, its consumable parts are shown.
    - The family of the vegetable is highlighted in red in the list of families.

---

## 📄 Input File Format (`vegetables.txt`)

The input file should be named `vegetables.txt` and placed in the working directory. Each line has the following format:

```
Potato family|Potato|fruit
Potato family|Tomato|fruit
Beetroot family|Spinach|leaves
Marrow family|Melon|fruit
Onion family|Onion|stem, root
```
