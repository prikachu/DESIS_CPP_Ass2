#include <bits/stdc++.h>
using namespace std;
#include "bookmag.h"

class Inventory
{
private:
    unordered_set<Book *> all_books;
    unordered_set<Magazine *> all_mag;

public:
    void display_books()
    {
        cout << "No of different books in inventory: " << all_books.size() << endl;
        for (auto i : all_books)
        {
            i->displayDetails();
            cout << endl;
        }
    }

    void display_mag()
    {
        cout << "No of different magazines in inventory: " << all_books.size() << endl;
        for (auto i : all_mag)
        {
            i->displayDetails();
            cout << endl;
        }
    }

    void add_book(Book *newbook)
    {
        all_books.insert(newbook);
        cout << "Book added in inventory!" << endl;
    }
    void add_mag(Magazine *newmag)
    {
        all_mag.insert(newmag);
        cout << "Magazine added in inventory!" << endl;
    }

    void del_book(Book *book)
    {
        all_books.erase(book);
        cout << "Book removed from inventory!" << endl;
    }

    void del_mag(Magazine *mag)
    {

        all_mag.erase(mag);
        cout << "Magazine removed from inventory!" << endl;
    }

    Book *get_bkptr(string name)
    {
        for (auto i : all_books)
        {
            if (i->get_title() == name)
            {
                return i;
            }
        }
        return nullptr;
    }
    Magazine *get_mgptr(string name)
    {
        for (auto i : all_mag)
        {
            if (i->get_title() == name)
            {
                return i;
            }
        }
        return nullptr;
    }
};

class Bill
{
public:
    string date;
    unordered_map<Book *, int> bks;
    unordered_map<Magazine *, int> mgs;
    double total;

    Bill()
    {
        total = 0;
    }
};
