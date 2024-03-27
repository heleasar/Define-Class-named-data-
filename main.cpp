#include <iostream>
#include <vector>
#include <algorithm>

class Data {
private:
    std::vector<int> numbers;

public:
    void Display_Menu() {
        int choice;
        do {
            std::cout << "Menu:\n";
            std::cout << "0. Quit\n";
            std::cout << "1. Input Numbers\n";
            std::cout << "2. Display Numbers\n";
            std::cout << "3. Search Numbers\n";
            std::cout << "4. Delete Numbers\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 0:
                    std::cout << "Goodbye!\n";
                    break;
                case 1:
                    Input_Numbers();
                    break;
                case 2:
                    Display_Numbers();
                    break;
                case 3:
                    Search_Numbers();
                    break;
                case 4:
                    Delete_Numbers();
                    break;
                default:
                    std::cout << "Invalid choice. Try again.\n";
                    break;
            }
        } while (choice != 0);
    }

    void Input_Numbers() {
        int num;
        std::cout << "Enter numbers (0 to stop): ";
        while (true) {
            std::cin >> num;
            if (num == 0)
                break;
            numbers.push_back(num);
        }
    }

    void Display_Numbers() {
        std::cout << "Numbers: ";
        for (const int& num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    void Search_Numbers() {
        int target;
        std::cout << "Enter the number to search for: ";
        std::cin >> target;

        auto it = std::find(numbers.begin(), numbers.end(), target);
        if (it != numbers.end()) {
            int index = std::distance(numbers.begin(), it);
            std::cout << "Number found at index: " << index << std::endl;
        } else {
            std::cout << "Number not found." << std::endl;
        }
    }

    void Delete_Numbers() {
        numbers.clear();
        std::cout << "All numbers deleted." << std::endl;
    }
};

int main() {
    Data data;
    data.Display_Menu();
    return 0;
}
