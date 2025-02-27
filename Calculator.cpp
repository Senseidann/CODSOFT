#include <iostream>
#include <iomanip>

int main() {
    double num1, num2;
    char operation;

    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    std::cout << "Enter an operator (+, -, *, /): ";
    std::cin >> operation;

    double result;

    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
                return; // Exit without an error code
            }
        default:
            std::cout << "Error: Invalid operator." << std::endl;
            return; // Exit without error code
    }

    std::cout << std::fixed << std::setprecision(3); // fmt output to 3 decimal places vc
    std::cout << "Result: " << result <<std::endl;

    return 0;
}
