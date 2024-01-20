#include <iostream>
#include <vector>
#include "ppl.h" 

class BookstoreInterface
{
private:
    StoreManager storeManager;
    Cashier cashier;
    vector<Customer *> customers;

public:
    void displayMenu()
    {
        cout << "Welcome to the Bookstore Management System\n";
        cout << "Are you a:\n";
        cout << "1. Store Manager\n";
        cout << "2. Cashier\n";
        cout << "3. Customer\n";
        cout << "Enter your choice: ";
        int userChoice;
        cin >> userChoice;

        switch (userChoice)
        {
        case 1:
            storeManagerMenu();
            break;
        case 2:
            cashierMenu();
            break;
        case 3:
            customerMenu();
            break;
        default:
            cout << "Invalid choice. Exiting...\n";
        }
    }

private:
    void storeManagerMenu()
    {
        int choice;
        do
        {
            cout << "\nStore Manager Menu:\n";
            cout << "1. Add Book\n";
            cout << "2. Add Magazine\n";
            cout << "3. Update Book Cost\n";
            cout << "4. Update Book Price\n";
            cout << "5. Update Magazine Cost\n";
            cout << "6. Update Magazine Price\n";
            cout << "7. Restock Book\n";
            cout << "8. Restock Magazine\n";
            cout << "9. View Inventory\n";
            cout << "10. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            string title;
            double nc;
            int qty;
            switch (choice)
            {

            case 1:
                storeManager.add_book();
                break;
            case 2:
                storeManager.add_mag();
                break;
            case 3:
                cout << "Enter title : ";
                cin >> title;
                cout << endl
                     << "Enter new cost : ";
                cin >> nc;
                cout << endl;
                storeManager.update_cost_bk(title, nc);
                break;
            case 4:
                cout << "Enter title : ";
                cin >> title;
                cout << endl
                     << "Enter new price : ";
                cin >> nc;
                cout << endl;
                storeManager.update_price_bk(title, nc);
                break;
            case 5:
                cout << "Enter title : ";
                cin >> title;
                cout << endl
                     << "Enter new cost : ";
                cin >> nc;
                cout << endl;
                storeManager.update_cost_mg(title, nc);
                break;
            case 6:
                cout << "Enter title : ";
                cin >> title;
                cout << endl
                     << "Enter new price : ";
                cin >> nc;
                cout << endl;
                storeManager.update_price_mg(title, nc);
                break;
            case 7:
                cout << "Enter title : ";
                cin >> title;
                cout << endl
                     << "Enter qty : ";
                cin >> qty;
                cout << endl;
                storeManager.restock_bk(title, nc);
                break;
            case 8:
                cout << "Enter title : ";
                cin >> title;
                cout << endl
                     << "Enter qty : ";
                cin >> qty;
                cout << endl;
                storeManager.restock_mg(title, qty);
                break;
            case 9:
                storeManager.displaybk();
                cout << endl;
                storeManager.displaymag();
                break;
            case 10:
                cout << "Exiting Store Manager Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 10);
    }

    void cashierMenu()
    {
        int choice;
        do
        {
            string c;
            cout << "Enter name of customer for transaction: ";
            cin >> c;
            cout << endl;
            Customer *cust = nullptr;
            for (auto i : customers)
            {
                if (i->name == c)
                {
                    cust = i;
                    break;
                }
            }
            if (cust == nullptr)
            {
                cust = new Customer(c);
                cout << "New customer added!" << endl;
            }
            cout << "\nCashier Menu:\n";
            cout << "1. Sell Book\n";
            cout << "2. Sell Magazine\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cashier.addBook(cust);
                break;
            case 2:
                cashier.addMag(cust);
                break;
            case 3:
                cout << "Exiting Cashier Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 3);
    }

    void customerMenu()
    {
        int choice;
        do
        {

            string c;
            cout << "Enter name: ";
            cin >> c;
            cout << endl;
            Customer *cust = nullptr;
            for (auto i : customers)
            {
                if (i->name == c)
                {
                    cust = i;
                    break;
                }
            }
            if (cust == nullptr)
            {
                cust = new Customer(c);
            }
            cout << "\nCustomer Menu:\n";
            cout << "1. Start New Purchase\n";
            cout << "2. View Past Bills\n";
            cout << "3. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cust->newpurchase();
                break;
            case 2:
                cust->view_pastbills();
                break;
            case 3:
                cout << "Exiting Customer Menu.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 3);
    }
};

int main()
{
    BookstoreInterface bookstore;
    bookstore.displayMenu();

    return 0;
}
