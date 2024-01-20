#include <bits/stdc++.h>
using namespace std;
#include "management.h"

class StoreManager
{
protected:
    Inventory inventory;

public:
    void add_book()
    {
        string title, author;
        int copies;
        double price, cost;
        cout << "Enter book title: ";
        cin >> title;

        Book *check = inventory.get_bkptr(title);
        if (check != nullptr)
        {
            cout << endl
                 << "Book already present in inventory!" << endl;
            return;
        }

        cout << endl
             << "Enter author: ";
        cin >> author;

        cout << endl
             << "Enter number of copies: ";
        cin >> copies;

        cout << endl
             << "Enter price: ";
        cin >> price;

        cout << endl
             << "Enter cost: ";
        cin >> cost;
        cout << endl;

        Book *newbook = new Book(title, author, copies, price, cost);
        inventory.add_book(newbook);
    }
    void add_mag()
    {
        string title, publisher;
        int copies;
        double price, cost;
        cout << "Enter book title: ";
        cin >> title;
        Magazine *check = inventory.get_mgptr(title);
        if (check != nullptr)
        {
            cout << endl
                 << "Magazine already present in inventory!" << endl;
            return;
        }
        cout << endl
             << "Enter publisher: ";
        cin >> publisher;

        cout << endl
             << "Enter number of copies: ";
        cin >> copies;

        cout << endl
             << "Enter price: ";
        cin >> price;

        cout << endl
             << "Enter cost: ";
        cin >> cost;
        cout << endl;
        Magazine *newmag = new Magazine(title, publisher, copies, price, cost);
        inventory.add_mag(newmag);
    }

    void update_cost_bk(string name, double newcost)
    {
        Book *bk = inventory.get_bkptr(name);
        if (bk == nullptr)
        {
            cout << "Book not found!" << endl;
        }
        else
        {
            bk->update_cost(newcost);
        }
    }
    void update_price_bk(string name, double newprice)
    {
        Book *bk = inventory.get_bkptr(name);
        if (bk == nullptr)
        {
            cout << "Book not found!" << endl;
        }
        else
        {
            bk->update_price(newprice);
        }
    }
    void update_cost_mg(string name, double newcost)
    {
        Magazine *mg = inventory.get_mgptr(name);
        if (mg == nullptr)
        {
            cout << "Magazine not found!" << endl;
        }
        else
        {
            mg->update_cost(newcost);
        }
    }
    void update_price_mg(string name, double newprice)
    {
        Magazine *mg = inventory.get_mgptr(name);
        if (mg == nullptr)
        {
            cout << "Magazine not found!" << endl;
        }
        else
        {
            mg->update_price(newprice);
        }
    }

    void restock_bk(string name, int newquant)
    {
        Book *bk = inventory.get_bkptr(name);
        if (bk != nullptr)
        {
            bk->restock(newquant);
        }
        else
        {
            cout << "Book data not available! Add book first." << endl;
        }
    }
    void restock_mg(string name, int newquant)
    {
        Magazine *mg = inventory.get_mgptr(name);
        if (mg != nullptr)
        {
            mg->restock(newquant);
        }
        else
        {
            cout << "Magazine data not available! Add book first." << endl;
        }
    }

    void del_book()
    {
        string title;
        cout << "Enter book title: ";
        cin >> title;
        cout << endl;
        Book *bk = inventory.get_bkptr(title);
        if (bk == nullptr)
        {
            cout << "Book already not present in inventory!" << endl;
        }
        else
        {
            inventory.del_book(bk);
        }
    }
    void del_mag()
    {
        string title;
        cout << "Enter book title: ";
        cin >> title;
        cout << endl;
        Magazine *mg = inventory.get_mgptr(title);
        if (mg == nullptr)
        {
            cout << "Magazine already not present in inventory!" << endl;
        }
        else
        {
            inventory.del_mag(mg);
        }
    }

    void displaymag()
    {
        inventory.display_mag();
    }
    void displaybk()
    {
        inventory.display_books();
    }
};

class Customer
{
public:
    string name;
    vector<Bill *> bills;

    Customer(string nm)
    {
        name = nm;
    }
    void view_pastbills()
    {
        for (auto i : bills)
        {
            cout << i->date << endl;
            for (auto j : i->bks)
            {
                cout << j.first->get_title() << j.second << endl;
            }
            for (auto k : i->mgs)
            {
                cout << k.first->get_title() << k.second << endl;
            }
            cout << "Total was : " << i->total << endl;
        }
    }

    void newpurchase()
    {
        Bill *newbill = new Bill();
        newbill->total = 0;
        bills.push_back(newbill);
    }
};

class Cashier : StoreManager
{
public:
    void addBook(Customer *cust)
    {
        Bill *bill = cust->bills.back();
        string title;
        cin >> title;
        cout << endl;
        Book *bk = inventory.get_bkptr(title);
        if (bk == nullptr)
        {
            cout << "Book does not exist in inventory!" << endl;
            return;
        }
        else
        {
            int qty;
            cin >> qty;
            bk->sell(qty);
            bill->total += qty * bk->get_price();
            bill->bks.insert({bk, qty});
        }
    }

    void addMag(Customer *cust)
    {
        Bill *bill = cust->bills.back();
        string title;
        cin >> title;
        cout << endl;
        Magazine *mg = inventory.get_mgptr(title);
        if (mg == nullptr)
        {
            cout << "Magazine does not exist in inventory!" << endl;
            return;
        }
        else
        {
            int qty;
            cin >> qty;
            mg->sell(qty);
            bill->total += qty * mg->get_price();
            bill->mgs.insert({mg, qty});
        }
    }

    void delBook(Customer *cust)
    {
        Bill *bill = cust->bills.back();
        string title;
        cin >> title;
        cout << endl;
        Book *bk = nullptr;
        for (auto i : bill->bks)
        {
            if (i.first->get_title() == title)
            {
                bk = i.first;
                break;
            }
        }
        if (bk == nullptr)
        {
            cout << "Book does not exist in bill!" << endl;
            return;
        }
        else
        {
            bill->total -= bill->bks[bk] * bk->get_price();
            bill->bks.erase(bk);
            cout << "Book deleted from bill" << endl;
        }
    }

    void delMag(Customer *cust)
    {
        Bill *bill = cust->bills.back();
        string title;
        cin >> title;
        cout << endl;
        Magazine *mg = nullptr;
        for (auto i : bill->mgs)
        {
            if (i.first->get_title() == title)
            {
                mg = i.first;
                break;
            }
        }
        if (mg == nullptr)
        {
            cout << "Magazine does not exist in bill!" << endl;
            return;
        }
        else
        {
            bill->total -= bill->mgs[mg] * mg->get_price();
            bill->mgs.erase(mg);
            cout << "Magazine deleted from bill" << endl;
        }
    }
};
