
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int id;
    string name;
    string category;
    float price;
    int stock;

    Node* next;
};

Node* head = NULL;

// Register Product
void insertProduct()
{
    Node* newNode = new Node;

    cout << "Enter Product ID: ";
    cin >> newNode->id;

    // Check duplicate ID
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->id == newNode->id)
        {
            cout << "Product ID already exists!" << endl;
            delete newNode;
            return;
        }

        temp = temp->next;
    }

    cout << "Enter Product Name: ";
    cin >> newNode->name;

    cout << "Enter Category: ";
    cin >> newNode->category;

    cout << "Enter Price: ";
    cin >> newNode->price;

    cout << "Enter Stock: ";
    cin >> newNode->stock;

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Product registered successfully!" << endl;
}

// Update Product
void updateProduct()
{
    int id;
    Node* temp = head;

    cout << "Enter Product ID to Update: ";
    cin >> id;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "Enter New Product Name: ";
            cin >> temp->name;

            cout << "Enter New Category: ";
            cin >> temp->category;

            cout << "Enter New Price: ";
            cin >> temp->price;

            cout << "Enter New Stock: ";
            cin >> temp->stock;

            cout << "Product updated successfully!" << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Product not found!" << endl;
}

// Delete Product
void deleteProduct()
{
    int id;

    cout << "Enter Product ID to Delete: ";
    cin >> id;

    Node* temp = head;
    Node* previous = NULL;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (previous == NULL)
            {
                head = temp->next;
            }
            else
            {
                previous->next = temp->next;
            }

            delete temp;

            cout << "Product deleted successfully!" << endl;
            return;
        }

        previous = temp;
        temp = temp->next;
    }

    cout << "Product not found!" << endl;
}

// Search Product
void searchProduct()
{
    int id;
    Node* temp = head;

    cout << "Enter Product ID to Search: ";
    cin >> id;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << endl << "Product Found!" << endl;
            cout << "Product ID: " << temp->id << endl;
            cout << "Product Name: " << temp->name << endl;
            cout << "Category: " << temp->category << endl;
            cout << "Price: " << temp->price << endl;
            cout << "Stock: " << temp->stock << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "Product not found" << endl;
}

// Display All Products
void displayProducts()
{
    Node* temp = head;

    if (head == NULL)
    {
        cout << "Product list is empty" << endl;
        return;
    }

    cout << endl << " PRODUCT LIST " << endl;

    while (temp != NULL)
    {
        cout << endl << "Product ID: " << temp->id << endl;
        cout << "Product Name: " << temp->name << endl;
        cout << "Category: " << temp->category << endl;
        cout << "Price: " << temp->price << endl;
        cout << "Stock: " << temp->stock << endl;

        cout<< endl;

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << endl << " ONLINE SHOPPING SYSTEM " << endl;
        cout << "1. Register Product" << endl;
        cout << "2. Update Product" << endl;
        cout << "3. Delete Product" << endl;
        cout << "4. Search Product" << endl;
        cout << "5. Display All Products" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertProduct();
                break;

            case 2:
                updateProduct();
                break;

            case 3:
                deleteProduct();
                break;

            case 4:
                searchProduct();
                break;

            case 5:
                displayProducts();
                break;

            case 6:
                cout << "Program Ended!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 6);

    return 0;
}
