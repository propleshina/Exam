#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>

int main() {
    const char* filename = "C:\\Users\\ogilk\\Desktop\\321_Ogilko_Ekaterina\\ConsoleApplication1\\numbers.txt";

    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Error when opening file." << std::endl;
        return 1;
    }

    std::string number;
    int maxNumber = std::numeric_limits<int>::min();

    while (inFile >> number) {
        try {
            int num = std::stoi(number);
            if (num > maxNumber) {
                maxNumber = num;
            }
        }
        catch (const std::invalid_argument&) {
            std::cerr << "Incorrect number: " << number << std::endl;
        }
    }

    inFile.close();

    std::ofstream outFile(filename, std::ios::app); 
    if (outFile.is_open()) {
        outFile << "\nMax number: " << maxNumber << std::endl;
        outFile.close();
    }
    else {
        std::cerr << "Error." << std::endl;
        return 1;
    }

    std::cout << "Max number: " << maxNumber << std::endl;

    return 0;
}
