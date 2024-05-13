#include <iostream>
#include <string>
using namespace std;

// Template class for products
template <typename T>
class Product {
public:
    Product() : name(T()), price(0), quantity(0) {}

    Product(const T& name, int price, int quantity) : name(name), price(price), quantity(quantity) {}

    T getName() const { 
    	// Write your code
		return name;
	}
    int getPrice() const { 
		// Write your code
		 return price;
	}
    int getQuantity() const { 
		// Write your code
		return quantity;    
	}

private:
	// Write your code
	// Define name, price, and quantity
    T name;
    int price;
    int quantity;
};

// Template class for shopping cart
template <typename T, int MaxProducts>
class ShoppingCart {
public:
    ShoppingCart() : total(0), productCount(0) {
    	// products array
        for (int i = 0; i < MaxProducts; ++i) {
        	// Write your code
        	 products[i] = Product<T>();
        }
    }
	
	// Calculate the total price
    void addProduct(const Product<T>& product) {
        // Write your code
        products[productCount] = product;
        total += product.getPrice() * product.getQuantity();
        productCount++;

    }
	
	// Display the cart contents
    void displayCartContents() {
    	// Write your code
    	// Make sure your output format same as OJ
    	// Ex:Product Name or Number: iPad pro 11 256GB, Price: 34900, Quantity: 2
    	cout <<"Shopping Cart Contents:" << endl;
        for (int i = 0; i < productCount; ++i) {
            cout << "Product Name or Number: " << products[i].getName() << ", Price: " << products[i].getPrice() << ", Quantity: " << products[i].getQuantity() << endl;
        }
        cout << "Total Price: " << total << endl;
    }

private:
    int total;
    Product<T> products[MaxProducts];
    int productCount;
};



// Don't modify the following main code
int main() {
    // Example usage
//    Product<string> iPad("iPad pro 11 256GB", 34900, 2);
//    Product<int> Phone(1257846, 23800, 3);
//    Product<string> Ticket("TPE -> HND", 10500, 8);
//    Product<int> Student(112511999, 123546, 1);
    Product<string> what("M3", 1314, 6);
    Product<string> M3is("You know what I am saying", 520, 3);
    Product<int> C(19890604, 1989, 64);
    Product<string> ETF("00940", 94, 5);
	Product<string> OOP("Problem Solving with C++", 1, 16);
    Product<string> OMG("Course suspension until", 240517, 1);
	Product<int> QQ(9527, 10, 4);
	Product<string> EVERYBODY("ALL PASS!!!", 77777, 8);
	
	// Shopping cart can hold up to ten products
    ShoppingCart<string, 10> cart;
//    cart.addProduct(iPad);
//    cart.addProduct(Product<string>(to_string(Phone.getName()), Phone.getPrice(), Phone.getQuantity())); // Convert Phone name to string
//    cart.addProduct(Ticket);
//    cart.addProduct(Product<string>(to_string(Student.getName()), Student.getPrice(), Student.getQuantity())); // Convert Student name to string
	cart.addProduct(what);
    cart.addProduct(M3is);
    cart.addProduct(Product<string>(to_string(C.getName()), C.getPrice(), C.getQuantity())); // Convert C name to string
    cart.addProduct(ETF);
	cart.addProduct(OOP);
    cart.addProduct(OMG);
    cart.addProduct(Product<string>(to_string(QQ.getName()), QQ.getPrice(), QQ.getQuantity())); // Convert QQ name to string
    cart.addProduct(EVERYBODY);
	cart.displayCartContents();
	
    return 0;
}

