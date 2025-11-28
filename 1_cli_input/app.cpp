#include <iostream>
#include <string>
#include <limits>

int main() {
    std::cout << "--------------------  Initialized  --------------------" << std::endl;

    std::string description;
    double amount = 0.0;

    std::cout << ">> enter a description: ";

    // Use std::getline to read the entire line, including spaces
    std::getline(std::cin, description);

    std::cout << ">> enter an amount (e.g., 45.99): $";
    
    while (!(std::cin >> amount)) {
        std::cout << "\n[Error] Invalid input. Please enter a numerical amount: $";
        // clear error flags on cin
        std::cin.clear();
        // discard invalid input up to the next line
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "\n--- Item Logged ---\n";
    std::cout << "Description: " << description << "\n";
    std::cout << "Amount: " << amount << "\n\n\n";

    std:: cout << "--------------------  Terminated   --------------------" << std::endl;
    return 0;
}