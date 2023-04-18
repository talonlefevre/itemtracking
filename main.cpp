#include <iostream>
#include <fstream>
#include <map>
#include <string>

class Inventory {
public:
    // Constructor
    Inventory(const std::string& input_file, const std::string& output_file);

    // Public methods
    void readInputFile();
    int getItemFrequency(const std::string& item);
    void printFrequencyList();
    void printHistogram();
    void writeToOutputFile();

private:
    // Private member variables
    std::string input_file;
    std::string output_file;
    std::map<std::string, int> items_frequency;
};

// Constructor implementation
Inventory::Inventory(const std::string& input_file, const std::string& output_file)
    : input_file(input_file), output_file(output_file) {
    readInputFile();
    writeToOutputFile();
}

// Read input file and populate items_frequency map
void Inventory::readInputFile() {
    std::ifstream file(input_file);
    std::string item;

    // Read items from the input file and increment their frequencies in the map
    while (file >> item) {
        items_frequency[item]++;
    }

    file.close();
}

// Get the frequency of a specific item
int Inventory::getItemFrequency(const std::string& item) {
    return items_frequency[item];
}

// Print the frequency list
void Inventory::printFrequencyList() {
    // Iterate through the map and print the item and its frequency
    for (const auto& entry : items_frequency) {
        std::cout << entry.first << " " << entry.second << std::endl;
    }
}

// Print the histogram
void Inventory::printHistogram() {
    // Iterate through the map and print the item followed by asterisks representing its frequency
    for (const auto& entry : items_frequency) {
        std::cout << entry.first << " ";
        for (int i = 0; i < entry.second; i++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

// Write the frequency list to an output file
void Inventory::writeToOutputFile() {
    std::ofstream file(output_file);

    // Iterate through the map and write the item and its frequency to the output file
    for (const auto& entry : items_frequency) {
        file << entry.first << " " << entry.second << std::endl;
    }

    file.close();
}

int main() {
    // Create an instance of the Inventory class with the input and output file names
    Inventory inventory("input.txt", "frequency.dat");
    int choice;

    // Display a menu for the user to interact with the Inventory object
    do {
        std::cout << "1. Search item frequency\n"
                  << "2. Print frequency list\n"
                  << "3. Print histogram\n"
                  << "4. Exit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        // Perform the chosen action based on the user's input
        switch (choice) {
            case 1: {
                std::string item;
                std::cout << "Enter the item name: ";
                std::cin >> item;
                std::cout << "Frequency: " << inventory.getItemFrequency(item) << std::endl;
                break;
            }
            case 2:
                inventory.printFrequencyList();
                break;
            case 3:
                inventory.printHistogram();
                break;
            case 4:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
