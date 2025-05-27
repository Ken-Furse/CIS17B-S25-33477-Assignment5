# CIS17B-S25-33477-Assignment5
The Congo Smart Packaging System is a flexible, template-based C++ application designed to help you manage and ship various types of items in a smart warehouse.
To use it, you can create a Package<T> for any item type—like int, std::string, or even pointers—to simulate general, book-specific, or fragile packaging, respectively.
For grouping multiple items, the Box<T, Size> class lets you store up to a fixed number of items and print their contents. 
To simulate shipping, the shipItem() function outputs a message based on the item type, with a specialized version for temperature-sensitive double values.
With template specialization and partial specialization built in, the system automatically adjusts its behavior based on item type, making it reusable, type-safe, and easy to extend for different packaging needs.
I included a quick continue option at the end of the code, to verify results.
