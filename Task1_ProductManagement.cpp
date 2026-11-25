
#include <iostream>
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

// Insert product at the end
void insertProduct()
{
    Node* newNode = new Node;

    cout << "Enter Product ID: ";
    cin >> newNode->id;

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
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "\nProduct added successfully!\n";
}

// Display all products
void displayProducts()
{
    Node* temp = head;

    if (head == NULL)
    {
        cout << "\nProduct list is empty.\n";
    }
    else
    {
        cout << "\n= PRODUCT LIST \n";

        while (temp != NULL)
        {
            cout << "\nProduct ID: " << temp->id;
            cout << "\nProduct Name: " << temp->name;
            cout << "\nCategory: " << temp->category;
            cout << "\nPrice: " << temp->price;
            cout << "\nStock: " << temp->stock;
            

            temp = temp->next;
        }
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n ONLINE SHOPPING SYSTEM  ";
        cout << "\n1. Register Product";
        cout << "\n2. Display Products";
        cout << "\n3. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertProduct();
                break;

            case 2:
                displayProducts();
                break;

            case 3:
                cout << "\nProgram ended.";
                break;

            default:
                cout << "\nInvalid choice!";
        }

    } while (choice != 3);

    return 0;
}
