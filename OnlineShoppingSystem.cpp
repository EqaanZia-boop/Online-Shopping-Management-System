
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;


struct Product
{
    int id;
    string name;
    string category;
    float price;
    int stock;
};


struct Node
{
    Product data;
    Node* next;
};


struct CartItem
{
    Product product;
    int quantity;
};


struct Order
{
    int orderID;
    string customerName;
    int productID;
    string productName;
    int quantity;
    float total;
};


Node* head = NULL;

CartItem cart[100];
int top = -1;

Order orders[100];
int front = -1;
int rear = -1;

int nextOrderID = 1001;

Node* findProduct(int id)
{
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data.id == id)
        {
            return temp;
        }

        temp = temp->next;
    }

    return NULL;
}


void registerProduct()
{
    Product p;

    cout << "Enter Product ID: ";
    cin >> p.id;

    if (findProduct(p.id) != NULL)
    {
        cout << "Duplicate Product ID!" << endl;
        return;
    }

    cout << "Enter Product Name: ";
    cin >> p.name;

    cout << "Enter Category: ";
    cin >> p.category;

    cout << "Enter Price: ";
    cin >> p.price;

    cout << "Enter Stock: ";
    cin >> p.stock;

    if (p.price <= 0 || p.stock < 0)
    {
        cout << "Invalid Price or Stock!" << endl;
        return;
    }

    Node* newNode = new Node;

    newNode->data = p;
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

    cout << "Product Registered Successfully!" << endl;
}


void displayProducts()
{
    if (head == NULL)
    {
        cout << "No Products Available!" << endl;
        return;
    }

    Node* temp = head;

    cout << endl << "===== PRODUCT RECORDS =====" << endl;

    while (temp != NULL)
    {
        cout << endl;
        cout << "Product ID: " << temp->data.id << endl;
        cout << "Product Name: " << temp->data.name << endl;
        cout << "Category: " << temp->data.category << endl;
        cout << "Price: " << temp->data.price << endl;
        cout << "Stock: " << temp->data.stock << endl;

        temp = temp->next;
    }
}


void searchProduct()
{
    int choice;

    cout << "1. Search by ID" << endl;
    cout << "2. Search by Name" << endl;
    cout << "3. Search by Category" << endl;
    cout << "4. Search by Price" << endl;
    cout << "Enter choice: ";
    cin >> choice;

    Node* temp = head;
    bool found = false;

    int id;
    string name, category;
    float price;

    if (choice == 1)
    {
        cout << "Enter Product ID: ";
        cin >> id;
    }
    else if (choice == 2)
    {
        cout << "Enter Product Name: ";
        cin >> name;
    }
    else if (choice == 3)
    {
        cout << "Enter Category: ";
        cin >> category;
    }
    else if (choice == 4)
    {
        cout << "Enter Price: ";
        cin >> price;
    }
    else
    {
        cout << "Invalid Choice!" << endl;
        return;
    }

    while (temp != NULL)
    {
        if ((choice == 1 && temp->data.id == id) ||
            (choice == 2 && temp->data.name == name) ||
            (choice == 3 && temp->data.category == category) ||
            (choice == 4 && temp->data.price == price))
        {
            cout << endl << "Product Found!" << endl;
            cout << "Product ID: " << temp->data.id << endl;
            cout << "Product Name: " << temp->data.name << endl;
            cout << "Category: " << temp->data.category << endl;
            cout << "Price: " << temp->data.price << endl;
            cout << "Stock: " << temp->data.stock << endl;

            found = true;
        }

        temp = temp->next;
    }

    if (!found)
    {
        cout << "Product Not Found!" << endl;
    }
}

void sortProducts()
{
    if (head == NULL)
    {
        cout << "No Products Available!" << endl;
        return;
    }

    Node* current;
    Node* index;

    Product temp;

    for (current = head; current->next != NULL;
         current = current->next)
    {
        for (index = current->next; index != NULL;
             index = index->next)
        {
            if (current->data.id > index->data.id)
            {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }

    cout << "Products Sorted by ID Successfully!" << endl;
    displayProducts();
}


void binarySearch()
{
    sortProducts();

    int count = 0;
    Node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (count == 0)
    {
        return;
    }

    Product arr[100];

    temp = head;

    for (int i = 0; i < count; i++)
    {
        arr[i] = temp->data;
        temp = temp->next;
    }

    int id;

    cout << "Enter Product ID to Search: ";
    cin >> id;

    int low = 0;
    int high = count - 1;
    bool found = false;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid].id == id)
        {
            cout << "Product Found!" << endl;
            cout << "Product Name: " << arr[mid].name << endl;
            cout << "Price: " << arr[mid].price << endl;
            cout << "Stock: " << arr[mid].stock << endl;

            found = true;
            break;
        }
        else if (arr[mid].id < id)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (!found)
    {
        cout << "Product Not Found!" << endl;
    }
}

void sortByPrice()
{
    if (head == NULL)
    {
        cout << "No Products Available!" << endl;
        return;
    }

    Node* current;
    Node* index;
    Product temp;

    for (current = head; current->next != NULL;
         current = current->next)
    {
        for (index = current->next; index != NULL;
             index = index->next)
        {
            if (current->data.price > index->data.price)
            {
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
        }
    }

    cout << "Products Sorted by Price Successfully!" << endl;
    displayProducts();
}


void updateProduct()
{
    int id;

    cout << "Enter Product ID: ";
    cin >> id;

    Node* temp = findProduct(id);

    if (temp == NULL)
    {
        cout << "Product Not Found!" << endl;
        return;
    }

    cout << "Enter New Name: ";
    cin >> temp->data.name;

    cout << "Enter New Category: ";
    cin >> temp->data.category;

    cout << "Enter New Price: ";
    cin >> temp->data.price;

    cout << "Enter New Stock: ";
    cin >> temp->data.stock;

    if (temp->data.price <= 0 || temp->data.stock < 0)
    {
        cout << "Invalid Price or Stock! Update the record again." << endl;
        return;
    }

    cout << "Product Updated Successfully!" << endl;
}


void deleteProduct()
{
    int id;

    cout << "Enter Product ID: ";
    cin >> id;

    Node* temp = head;
    Node* previous = NULL;

    while (temp != NULL && temp->data.id != id)
    {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Product Not Found!" << endl;
        return;
    }

    if (previous == NULL)
    {
        head = temp->next;
    }
    else
    {
        previous->next = temp->next;
    }

    delete temp;

    cout << "Product Deleted Successfully!" << endl;
}


void addToCart()
{
    if (top == 99)
    {
        cout << "Shopping Cart is Full!" << endl;
        return;
    }

    int id, quantity;

    cout << "Enter Product ID: ";
    cin >> id;

    Node* temp = findProduct(id);

    if (temp == NULL)
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

    if (quantity > temp->data.stock)
    {
        cout << "Insufficient Stock!" << endl;
        return;
    }

    cart[top + 1].product = temp->data;
    cart[top + 1].quantity = quantity;

    top++;

    cout << "Product Added to Cart Successfully!" << endl;
}


void removeFromCart()
{
    if (top == -1)
    {
        cout << "Shopping Cart is Empty!" << endl;
        return;
    }

    cout << "Removed Product: "
         << cart[top].product.name << endl;

    top--;

    cout << "Product Removed from Cart!" << endl;
}


void displayCart()
{
    if (top == -1)
    {
        cout << "Shopping Cart is Empty!" << endl;
        return;
    }

    float total = 0;

    cout << endl << "===== SHOPPING CART =====" << endl;

    for (int i = top; i >= 0; i--)
    {
        float amount =
            cart[i].product.price * cart[i].quantity;

        cout << "Product: " << cart[i].product.name << endl;
        cout << "Quantity: " << cart[i].quantity << endl;
        cout << "Amount: " << amount << endl;

        total = total + amount;
    }

    cout << "Cart Total: " << total << endl;
}

bool enqueue(Order o)
{
    if (front != -1 && (rear + 1) % 100 == front)
    {
        return false;
    }

    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = (rear + 1) % 100;
    }

    orders[rear] = o;

    return true;
}


void placeOrder()
{
    if (top == -1)
    {
        cout << "Shopping Cart is Empty!" << endl;
        return;
    }

    string customerName;

    cout << "Enter Customer Name: ";
    cin >> customerName;

    int required = top + 1;
    int freeSlots;

    if (front == -1)
    {
        freeSlots = 100;
    }
    else if (rear >= front)
    {
        freeSlots = 100 - (rear - front + 1);
    }
    else
    {
        freeSlots = front - rear - 1;
    }

    if (required > freeSlots)
    {
        cout << "Order Queue is Full!" << endl;
        return;
    }

    for (int i = 0; i <= top; i++)
    {
        Node* p = findProduct(cart[i].product.id);

        if (p == NULL || cart[i].quantity > p->data.stock)
        {
            cout << "Product Unavailable or Insufficient Stock!" << endl;
            return;
        }
    }

    float grandTotal = 0;

    for (int i = top; i >= 0; i--)
    {
        Node* p = findProduct(cart[i].product.id);

        Order o;

        o.orderID = nextOrderID++;
        o.customerName = customerName;
        o.productID = p->data.id;
        o.productName = p->data.name;
        o.quantity = cart[i].quantity;
        o.total = p->data.price * cart[i].quantity;

        enqueue(o);

        p->data.stock = p->data.stock - cart[i].quantity;

        grandTotal = grandTotal + o.total;
    }

    top = -1;

    cout << "Order Placed Successfully!" << endl;
    cout << "Total Amount: " << fixed << setprecision(0)
         << grandTotal << endl;
    cout << "Inventory Updated Successfully!" << endl;
}


void processOrder()
{
    if (front == -1)
    {
        cout << "Order Queue is Empty!" << endl;
        return;
    }

    Order o = orders[front];

    cout << endl << "===== PROCESSING ORDER =====" << endl;
    cout << "Order ID: " << o.orderID << endl;
    cout << "Customer Name: " << o.customerName << endl;
    cout << "Product ID: " << o.productID << endl;
    cout << "Product Name: " << o.productName << endl;
    cout << "Quantity: " << o.quantity << endl;
    cout << "Total Amount: " << o.total << endl;

    cout << "Order Processed Successfully!" << endl;

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % 100;
    }
}


void displayOrders()
{
    if (front == -1)
    {
        cout << "No Pending Orders!" << endl;
        return;
    }

    cout << endl << "===== PENDING ORDERS =====" << endl;

    int i = front;

    while (true)
    {
        cout << endl;
        cout << "Order ID: " << orders[i].orderID << endl;
        cout << "Customer Name: " << orders[i].customerName << endl;
        cout << "Product ID: " << orders[i].productID << endl;
        cout << "Product Name: " << orders[i].productName << endl;
        cout << "Quantity: " << orders[i].quantity << endl;
        cout << "Total Amount: " << orders[i].total << endl;

        if (i == rear)
        {
            break;
        }

        i = (i + 1) % 100;
    }
}


void saveData()
{
    ofstream productFile("products.txt");

    Node* temp = head;

    while (temp != NULL)
    {
        productFile << temp->data.id << " "
                    << temp->data.name << " "
                    << temp->data.category << " "
                    << temp->data.price << " "
                    << temp->data.stock << endl;

        temp = temp->next;
    }

    productFile.close();

    ofstream orderFile("orders.txt");

    if (front != -1)
    {
        int i = front;

        while (true)
        {
            orderFile << orders[i].orderID << " "
                      << orders[i].customerName << " "
                      << orders[i].productID << " "
                      << orders[i].productName << " "
                      << orders[i].quantity << " "
                      << orders[i].total << endl;

            if (i == rear)
            {
                break;
            }

            i = (i + 1) % 100;
        }
    }

    orderFile.close();

    cout << "All Data Saved Successfully!" << endl;
}


void loadData()
{
    ifstream productFile("products.txt");

    Product p;

    while (productFile >> p.id >> p.name >> p.category
                       >> p.price >> p.stock)
    {
        Node* newNode = new Node;

        newNode->data = p;
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
    }

    productFile.close();

    ifstream orderFile("orders.txt");

    Order o;

    while (orderFile >> o.orderID >> o.customerName
                     >> o.productID >> o.productName
                     >> o.quantity >> o.total)
    {
        if (enqueue(o))
        {
            if (o.orderID >= nextOrderID)
            {
                nextOrderID = o.orderID + 1;
            }
        }
    }

    orderFile.close();

    cout << "Saved Data Loaded Successfully!" << endl;
}

int main()
{
    int choice;

    loadData();

    do
    {
        cout << endl;
        cout << "===== ONLINE SHOPPING SYSTEM =====" << endl;
        cout << "1. Register Product" << endl;
        cout << "2. Display Products" << endl;
        cout << "3. Search Product" << endl;
        cout << "4. Sort Products by ID" << endl;
        cout << "5. Binary Search by ID" << endl;
        cout << "6. Sort Products by Price" << endl;
        cout << "7. Update Product" << endl;
        cout << "8. Delete Product" << endl;
        cout << "9. Add Product to Cart" << endl;
        cout << "10. Remove Product from Cart" << endl;
        cout << "11. Display Shopping Cart" << endl;
        cout << "12. Place Customer Order" << endl;
        cout << "13. Process Order" << endl;
        cout << "14. Display Orders" << endl;
        cout << "15. Save and Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registerProduct();
                break;

            case 2:
                displayProducts();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                sortProducts();
                break;

            case 5:
                binarySearch();
                break;

            case 6:
                sortByPrice();
                break;

            case 7:
                updateProduct();
                break;

            case 8:
                deleteProduct();
                break;

            case 9:
                addToCart();
                break;

            case 10:
                removeFromCart();
                break;

            case 11:
                displayCart();
                break;

            case 12:
                placeOrder();
                break;

            case 13:
                processOrder();
                break;

            case 14:
                displayOrders();
                break;

            case 15:
                saveData();
                cout << "Program Ended!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 15);

    return 0;
}
