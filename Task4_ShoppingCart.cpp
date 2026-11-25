
#include <iostream>
#include <string>
using namespace std;

struct Product
{
    int id;
    string name;
    float price;
    int quantity;
};

Product cart[100];
int top = -1;


void addProduct()
{
    if (top == 99)
    {
        cout << "Shopping Cart is Full!" << endl;
        return;
    }

    Product p;

    cout << "Enter Product ID: ";
    cin >> p.id;

    cout << "Enter Product Name: ";
    cin >> p.name;

    cout << "Enter Product Price: ";
    cin >> p.price;

    cout << "Enter Quantity: ";
    cin >> p.quantity;

    if (p.price <= 0 || p.quantity <= 0)
    {
        cout << "Invalid Price or Quantity" << endl;
        return;
    }

    top++;

    cart[top] = p;

    cout << "Product Added to Shopping Cart" << endl;
}


void removeProduct()
{
    if (top == -1)
    {
        cout << "Shopping Cart is Empty!" << endl;
        return;
    }

    cout << "Removed Product: " << cart[top].name << endl;

    top--;

    cout << "Product Removed Successfully!" << endl;
}


void displayCart()
{
    if (top == -1)
    {
        cout << "Shopping Cart is Empty!" << endl;
        return;
    }

    cout << endl << "===== SHOPPING CART =====" << endl;

    for (int i = top; i >= 0; i--)
    {
        cout << endl << "Product ID: " << cart[i].id << endl;
        cout << "Product Name: " << cart[i].name << endl;
        cout << "Price: " << cart[i].price << endl;
        cout << "Quantity: " << cart[i].quantity << endl;
        cout << "Subtotal: " << cart[i].price * cart[i].quantity << endl;

        cout << endl;
    }
}

void peekProduct()
{
    if (top == -1)
    {
        cout << "Shopping Cart is Empty!" << endl;
        return;
    }

    cout << endl << "Last Added Product:" << endl;
    cout << "Product ID: " << cart[top].id << endl;
    cout << "Product Name: " << cart[top].name << endl;
    cout << "Price: " << cart[top].price << endl;
    cout << "Quantity: " << cart[top].quantity << endl;
}

int main()
{
    int choice;

    do
    {
        cout << endl << " SHOPPING CART MENU " << endl;
        cout << "1. Add Product to Cart" << endl;
        cout << "2. Remove Product from Cart" << endl;
        cout << "3. Display Shopping Cart" << endl;
        cout << "4. View Last Added Product" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addProduct();
                break;

            case 2:
                removeProduct();
                break;

            case 3:
                displayCart();
                break;

            case 4:
                peekProduct();
                break;

            case 5:
                cout << "Shopping Cart Program Ended!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
