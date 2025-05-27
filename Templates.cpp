#include <iostream>
#include <string>
#include <array>
#include <typeinfo>

// 1. Class Template Package<T>
template<typename T>
class Package {
private:
    T item;
public:
    Package(T i) : item(i) {}
    void label() {
        std::cout << "Generic package containing: " << typeid(T).name() << std::endl;
    }
};

// 2. Full Specialization for std::string
template<>
class Package<std::string> {
private:
    std::string item;
public:
    Package(std::string i) : item(i) {}
    void label() {
        std::cout << "Book package: \"" << item << "\"" << std::endl;
    }
};

// 3. Partial Specialization for Pointer Types
template<typename T>
class Package<T*> {
private:
    T* item;
public:
    Package(T* i) : item(i) {}
    void label() {
        std::cout << "Fragile package for pointer to type: " << typeid(T).name() << std::endl;
    }
};

// 4. Class Template Box<T, int Size>
template<typename T, int Size>
class Box {
private:
    std::array<T, Size> items;
    int count;
public:
    Box() : count(0) {}

    bool addItem(const T& item) {
        if (count < Size) {
            items[count] = item;
            ++count;
            std::cout << "Added item to box: \"" << item << "\"" << std::endl;
            return true;
        }
        else {
            std::cout << "Box is full. Cannot add more items." << std::endl;
            return false;
        }
    }

    void printItems() const {
        std::cout << "Box contents:\n";
        for (int i = 0; i < count; ++i) {
            std::cout << " - " << items[i] << std::endl;
        }
    }
};

// 5. Function Template shipItem<T>
template<typename T>
void shipItem(const T& item) {
    std::cout << "Shipping item of type: " << typeid(T).name() << std::endl;
}

// 6. Specialization for double
template<>
void shipItem<double>(const double& item) {
    std::cout << "Shipping temperature-controlled item: " << item << "C" << std::endl;
}

// Main Function to demonstrate features
int main() {
    // Create packages of different types
    Package<int> p1(42);
    p1.label();

    Package<std::string> p2("C++ Primer");
    p2.label();

    double temp = 98.6;
    Package<double*> p3(&temp);
    p3.label();

    // Box for books
    Box<std::string, 3> bookBox;
    bookBox.addItem("The Pragmatic Programmer");
    bookBox.addItem("Clean Code");
    bookBox.printItems();

    // Ship different item types
    int part = 123;
    std::string title = "Algorithms";
    double temperature = 22.5;

    shipItem(part);
    shipItem(title);
    shipItem(temperature);

    // Continue choice to allow for verification of output results
    char choice;
    std::cout << "Continue? (y/n)";
    std::cin >> choice;
    while (choice == 'Y' || choice == 'y') {
        std::cout << "type n for exit";
        std::cin >> choice;
    }

    return 0;
}
