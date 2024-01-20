#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    Item(const string &title, int copies, double price, double cost)
        : title(title), copies(copies), price(price), cost(cost) {}

    void update_cost(double newcost)
    {
        cost = newcost;
    }
    void update_price(double newprice)
    {
        price = newprice;
    }

    virtual void displayDetails() const = 0;
    void sell(int quantity)
    {
        if (quantity <= copies)
        {
            copies -= quantity;
            cout << quantity << " copies of \"" << title << "\" sold. Thank you!\n";
        }
        else
        {
            cout << "Not enough copies available for sale.\n";
        }
    };
    void restock(int quantity)
    {
        copies += quantity;
        cout << quantity << " copies of \"" << title << "\" added to the inventory.\n";
    };
    virtual string getType() const = 0;
    string get_title()
    {
        return title;
    }

    double get_price() { return price; }

    virtual ~Item() {}

protected:
    string title;
    int copies;
    double price;
    double cost;
};

class Book : public Item
{
private:
    string author;

public:
    Book(const string title, const string author, int copies, double price, double cost)
        : Item(title, copies, price, cost), author(author) {}

    void displayDetails() const override
    {
        cout << "Title: " << title << "\nAuthor: " << author
             << "\nCopies available: " << copies << "\nPrice: $" << price
             << "\nCost: $" << cost << endl;
    }

    string getType() const override
    {
        return "Book";
    }
};

class Magazine : public Item
{
private:
    string publisher;

public:
    Magazine(const string &title, const string &publisher, int copies, double price, double cost)
        : Item(title, copies, price, cost), publisher(publisher) {}

    void displayDetails() const override
    {
        cout << "Title: " << title << "\nPublisher: " << publisher
             << "\nCopies available: " << copies << "\nPrice: $" << price << "\nCost: $" << cost << endl;
    }

    string getType() const override
    {
        return "Magazine";
    }
};