#include <iostream>
#include <string>

class Product {
protected:
    int prod_id;
    std::string prod_name;
    int stock;
    double gst;
    double discount;
    double product_price;

public:
    
    Product(int id, const std::string& name, int stock, double gst, double discount, double price)
        : prod_id(id), prod_name(name), stock(stock), gst(gst), discount(discount), product_price(price) {}


    void setProdId(int id) { prod_id = id; }
    void setProdName(const std::string& name) { prod_name = name; }
    void setStock(int stock) { this->stock = stock; }
    void setGst(double gst) { this->gst = gst; }
    void setDiscount(double discount) { this->discount = discount; }
    void setProductPrice(double price) { product_price = price; }

    
    int getProdId() const { return prod_id; }
    std::string getProdName() const { return prod_name; }
    int getStock() const { return stock; }
    double getGst() const { return gst; }
    double getDiscount() const { return discount; }
    double getProductPrice() const { return product_price; }


    void viewProduct() const {
        std::cout << "Product ID: " << prod_id << std::endl;
        std::cout << "Product Name: " << prod_name << std::endl;
        std::cout << "Stock: " << stock << std::endl;
        std::cout << "GST: " << gst << std::endl;
        std::cout << "Discount: " << discount << std::endl;
        std::cout << "Price: " << product_price << std::endl;
    }

    
    bool checkStock() const {
        return stock > 0;
    }
};

class Purchased_Product : public Product {
private:
    int quantity;

public:
    
    Purchased_Product(int id, const std::string& name, int stock, double gst, double discount, double price, int qty)
        : Product(id, name, stock, gst, discount, price), quantity(qty) {}

    
    void setQuantity(int qty) { quantity = qty; }

    
    int getQuantity() const { return quantity; }

    
    double calculateGst() const {
        return (product_price * gst / 100) * quantity;
    }

    
    double calculateDiscount() const {
        return (product_price * discount / 100) * quantity;
    }

    // Calculate total price for purchased product
    double calculatePrice() const {
        return (product_price + calculateGst() - calculateDiscount()) * quantity;
    }
};

class Node {
public:
    Purchased_Product *purchased_product;
    Node *next;

    // Constructor
    Node(Purchased_Product *p_product) : purchased_product(p_product), next(nullptr) {}
};

class LinkedList {
private:
    Node *head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor
    ~LinkedList() {
        Node *current = head;
        while (current != nullptr) {
            Node *next = current->next;
            delete current->purchased_product;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // Add a product to the linked list
    void addProduct(Purchased_Product *product) {
        Node *newNode = new Node(product);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Remove a product from the linked list
    void removeProduct(int prod_id) {
        if (head == nullptr) {
            std::cout << "Cart is empty!" << std::endl;
            return;
        }
        if (head->purchased_product->getProdId() == prod_id) {
            Node *temp = head;
            head = head->next;
            delete temp->purchased_product;
            delete temp;
            return;
        }
        Node *prev = head;
        Node *current = head->next;
        while (current != nullptr && current->purchased_product->getProdId() != prod_id) {
            prev = current;
            current = current->next;
        }
        if (current == nullptr) {
            std::cout << "Product not found in the cart!" << std::endl;
            return;
        }
        prev->next = current->next;
        delete current->purchased_product;
        delete current;
    }


    void viewCart() const {
        if (head == nullptr) {
            std::cout << "Cart is empty!" << std::endl;
            return;
        }
        Node *temp = head;
        std::cout << "Cart Contents:" << std::endl;
        while (temp != nullptr) {
            std::cout << "Product ID: " << temp->purchased_product->getProdId() << ", Quantity: " << temp->purchased_product->getQuantity() << std::endl;
            temp = temp->next;
        }
    }

    
    double generateBill() const {
        double totalBill = 0.0;
        Node *temp = head;
        while (temp != nullptr) {
            totalBill += temp->purchased_product->calculatePrice();
            temp = temp->next;
        }
        return totalBill;
    }
};

int main() {
    
    LinkedList cart;

    
    Purchased_Product product1(1, "Laptop", 10, 18.0, 5.0, 500.0, 2);
    Purchased_Product product2(2, "Mobile", 5, 12.0, 3.0, 300.0, 1);
    cart.addProduct(&product1);
    cart.addProduct(&product2);


    cart.viewCart();

    
    std::cout << "Total Bill: $" << cart.generateBill() << std::endl;

    return 0;
}
