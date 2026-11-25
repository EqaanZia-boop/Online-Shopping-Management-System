
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Product
{
    int id;
    string name;
    string category;
    float price;
    int stock;
};

struct Order
{
    int orderID;
    string customerName;
    int productID;
    int quantity;
    float total;
};

Product products[100];
Order orders[100];

int productCount = 0;
int orderCount = 0;

// Save Products in File
void saveProducts()
{
    ofstream file("products.txt");

    for (int i = 0; i < productCount; i++)
    {
        file << products[i].id << " "
             << products[i].name << " "
             << products[i].category << " "
             << products[i].price << " "
             << products[i].stock << endl;
    }

    file.close();
}

// Save Orders in File
void saveOrders()
{
    ofstream file("orders.txt");

    for (int i = 0; i < orderCount; i++)
    {
        file << orders[i].orderID << " "
             << orders[i].customerName << " "
             << orders[i].productID << " "
             << orders[i].quantity << " "
             << orders[i].total << endl;
    }

    file.close();
}

// Load Products from File
void loadProducts()
{
    ifstream file("products.txt");

    productCount = 0;

    while (file >> products[productCount].id
                >> products[productCount].name
                >> products[productCount].category
                >> products[productCount].price
                >> products[productCount].stock)
    {
        productCount++;

        if (productCount == 100)
        {
            break;
        }
    }

    file.close();
}

// Load Orders from File
void loadOrders()
{
    ifstream file("orders.txt");

    orderCount = 0;

    while (file >> orders[orderCount].orderID
                >> orders[orderCount].customerName
                >> orders[orderCount].productID
                >> orders[orderCount].quantity
                >> orders[orderCount].total)
    {
        orderCount++;

        if (orderCount == 100)
        {
            break;
        }
    }

    file.close();
}

// Register Product
void addProduct()
{
    if (productCount == 100)
    {
        cout << "Product List is Full!" << endl;
        return;
    }

    Product p;

    cout << "Enter Product ID: ";
    cin >> p.id;

    for (int i = 0; i < productCount; i++)
    {
        if (products[i].id == p.id)
        {
            cout << "Product ID already exists!" << endl;
            return;
        }
    }

    cout << "Enter Product Name: ";
    cin >> p.name;

    cout << "Enter Category: ";
    cin >> p.category;

    cout << "Enter Price: ";
    cin >> p.price;

    cout << "Enter Stock: ";
    cin >> p.stock;

    products[productCount] = p;
    productCount++;

    saveProducts();

    cout << "Product Saved Successfully!" << endl;
}

// Display Products
void displayProducts()
{
    if (productCount == 0)
    {
        cout << "No Products Available!" << endl;
        return;
    }

    cout << endl << "===== PRODUCT RECORDS =====" << endl;

    for (int i = 0; i < productCount; i++)
    {
        cout << endl << "Product ID: " << products[i].id << endl;
        cout << "Product Name: " << products[i].name << endl;
        cout << "Category: " << products[i].category << endl;
        cout << "Price: " << products[i].price << endl;
        cout << "Stock: " << products[i].stock << endl;
    }
}

// Place Customer Order
void placeOrder()
{
    if (orderCount == 100)
    {
        cout << "Order List is Full!" << endl;
        return;
    }

    int id;
    int quantity;
    int index = -1;
    string customerName;

    cout << "Enter Customer Name: ";
    cin >> customerName;

    cout << "Enter Product ID: ";
    cin >> id;

    for (int i = 0; i < productCount; i++)
    {
        if (products[i].id == id)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Product Not Available!" << endl;
        return;
    }

    cout << "Enter Quantity: ";
    cin >> quantity;

    if (quantity <= 0)
    {
        cout << "Invalid Quantity!" << endl;
        return;
    }

    if (quantity > products[index].stock)
    {
        cout << "Insufficient Stock!" << endl;
        return;
    }

    orders[orderCount].orderID = 1001 + orderCount;
    orders[orderCount].customerName = customerName;
    orders[orderCount].productID = id;
    orders[orderCount].quantity = quantity;

    orders[orderCount].total =
        products[index].price * quantity;

    cout << endl << "Order Placed Successfully!" << endl;
    cout << "Order ID: " << orders[orderCount].orderID << endl;
    cout << "Total Amount: " << orders[orderCount].total << endl;

    orderCount++;

    // Update Inventory
    products[index].stock =
        products[index].stock - quantity;

    saveProducts();
    saveOrders();

    cout << "Inventory Updated Successfully!" << endl;
}

// Display Orders
void displayOrders()
{
    if (orderCount == 0)
    {
        cout << "No Orders Available!" << endl;
        return;
    }

    cout << endl << "===== CUSTOMER ORDERS =====" << endl;

    for (int i = 0; i < orderCount; i++)
    {
        cout << endl << "Order ID: " << orders[i].orderID << endl;
        cout << "Customer Name: " << orders[i].customerName << endl;
        cout << "Product ID: " << orders[i].productID << endl;
        cout << "Quantity: " << orders[i].quantity << endl;
        cout << "Total Amount: " << orders[i].total << endl;
    }
}

int main()
{
    int choice;

    // Load saved data when program starts
    loadProducts();
    loadOrders();

    cout << "Saved Data Loaded Successfully!" << endl;

    do
    {
        cout << endl << "===== ONLINE SHOPPING SYSTEM =====" << endl;
        cout << "1. Register Product" << endl;
        cout << "2. Display Products" << endl;
        cout << "3. Place Customer Order" << endl;
        cout << "4. Display Orders" << endl;
        cout << "5. Save and Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addProduct();
                break;

            case 2:
                displayProducts();
                break;

            case 3:
                placeOrder();
                break;

            case 4:
                displayOrders();
                break;

            case 5:
                saveProducts();
                saveOrders();
                cout << "All Data Saved Successfully!" << endl;
                cout << "Program Ended!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
