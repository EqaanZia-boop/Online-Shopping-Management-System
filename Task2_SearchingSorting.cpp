
#include <iostream>
#include <string>
using namespace std;

struct Product
{
    int id;
    string name;
    string category;
    float price;
};

Product products[100];

// Display all products
void displayProducts(int n)
{
    cout << endl << " PRODUCT RECORDS " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << endl << "Product ID: " << products[i].id << endl;
        cout << "Product Name: " << products[i].name << endl;
        cout << "Category: " << products[i].category << endl;
        cout << "Price: " << products[i].price << endl;
    }
}

// Linear Search by Product ID
void linearSearchByID(int n)
{
    int id;
    bool found = false;

    cout << "Enter Product ID: ";
    cin >> id;

    for (int i = 0; i < n; i++)
    {
        if (products[i].id == id)
        {
            cout << "Product Found!" << endl;
            cout << "Name: " << products[i].name << endl;
            cout << "Category: " << products[i].category << endl;
            cout << "Price: " << products[i].price << endl;

            found = true;
            break;
        }
    }

    if (found == false)
    {
        cout << "Product not found!" << endl;
    }
}

// Linear Search by Product Name
void linearSearchByName(int n)
{
    string name;
    bool found = false;

    cout << "Enter Product Name: ";
    cin >> name;

    for (int i = 0; i < n; i++)
    {
        if (products[i].name == name)
        {
            cout << "Product Found!" << endl;
            cout << "Product ID: " << products[i].id << endl;
            cout << "Category: " << products[i].category << endl;
            cout << "Price: " << products[i].price << endl;

            found = true;
            break;
        }
    }

    if (found == false)
    {
        cout << "Product not found!" << endl;
    }
}

// Linear Search by Category
void linearSearchByCategory(int n)
{
    string category;
    bool found = false;

    cout << "Enter Category: ";
    cin >> category;

    for (int i = 0; i < n; i++)
    {
        if (products[i].category == category)
        {
            cout << "Product Found!" << endl;
            cout << "Product ID: " << products[i].id << endl;
            cout << "Name: " << products[i].name << endl;
            cout << "Price: " << products[i].price << endl;

            found = true;
        }
    }

    if (found == false)
    {
        cout << "Product not found!" << endl;
    }
}

// Linear Search by Price
void linearSearchByPrice(int n)
{
    float price;
    bool found = false;

    cout << "Enter Product Price: ";
    cin >> price;

    for (int i = 0; i < n; i++)
    {
        if (products[i].price == price)
        {
            cout << "Product Found!" << endl;
            cout << "Product ID: " << products[i].id << endl;
            cout << "Name: " << products[i].name << endl;
            cout << "Category: " << products[i].category << endl;

            found = true;
        }
    }

    if (found == false)
    {
        cout << "Product not found!" << endl;
    }
}

// Bubble Sort by Product ID
void bubbleSortByID(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (products[j].id > products[j + 1].id)
            {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }

    cout << "Products sorted by Product ID!" << endl;
}

// Binary Search by Product ID
void binarySearchByID(int n)
{
    int id;

    // Binary search requires sorted records
    bubbleSortByID(n);

    cout << "Enter Product ID: ";
    cin >> id;

    int low = 0;
    int high = n - 1;
    int mid;
    bool found = false;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (products[mid].id == id)
        {
            cout << "Product Found!" << endl;
            cout << "Product Name: " << products[mid].name << endl;
            cout << "Category: " << products[mid].category << endl;
            cout << "Price: " << products[mid].price << endl;

            found = true;
            break;
        }
        else if (id < products[mid].id)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (found == false)
    {
        cout << "Product not found!" << endl;
    }
}

// Bubble Sort by Product Price
void bubbleSortByPrice(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (products[j].price > products[j + 1].price)
            {
                Product temp = products[j];
                products[j] = products[j + 1];
                products[j + 1] = temp;
            }
        }
    }

    cout << "Products sorted by Price in Ascending Order " << endl;

    displayProducts(n);
}

int main()
{
    int n;
    int choice;

    cout << "Enter Number of Products: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << endl << "Enter Details of Product " << i + 1 << endl;

        cout << "Enter Product ID: ";
        cin >> products[i].id;

        cout << "Enter Product Name: ";
        cin >> products[i].name;

        cout << "Enter Category: ";
        cin >> products[i].category;

        cout << "Enter Price: ";
        cin >> products[i].price;
    }

    do
    {
        cout << endl << " SEARCHING AND SORTING MENU" << endl;
        cout << "1. Display Products" << endl;
        cout << "2. Linear Search by ID" << endl;
        cout << "3. Linear Search by Name" << endl;
        cout << "4. Linear Search by Category" << endl;
        cout << "5. Linear Search by Price" << endl;
        cout << "6. Binary Search by ID" << endl;
        cout << "7. Bubble Sort by Product ID" << endl;
        cout << "8. Bubble Sort by Product Price" << endl;
        cout << "9. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                displayProducts(n);
                break;

            case 2:
                linearSearchByID(n);
                break;

            case 3:
                linearSearchByName(n);
                break;

            case 4:
                linearSearchByCategory(n);
                break;

            case 5:
                linearSearchByPrice(n);
                break;

            case 6:
                binarySearchByID(n);
                break;

            case 7:
                bubbleSortByID(n);
                displayProducts(n);
                break;

            case 8:
                bubbleSortByPrice(n);
                break;

            case 9:
                cout << "Program Ended!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 9);

    return 0;
}
