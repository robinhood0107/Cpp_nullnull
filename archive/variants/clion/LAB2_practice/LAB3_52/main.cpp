#include "inventory.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <limits>

void print_inventory(const inventory& items) {
    if (items.empty()) {
        std::cout << "Inventory is empty." << std::endl;
        return;
    }
    std::cout << "\nInventory (sorted by price):\n";
    std::cout << std::left 
              << std::setw(5) << "ID" 
              << std::setw(25) << "Name" 
              << std::setw(10) << "Price" 
              << std::setw(10) << "Quantity" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    
    for (const auto& [id, name, price, qty] : items) {
        std::cout << std::left 
                  << std::setw(5) << id
                  << std::setw(25) << name
                  << std::setw(10) << price
                  << std::setw(10) << qty << std::endl;
    }
}

void print_item(const Item& item) {
    std::cout << "Found: [ID: " << item.id << "] " << item.name 
              << " $" << item.price << " Qty: " << item.qty << std::endl;
}

bool parse_create_command(const std::string& input, std::string& name, double& price, int& qty) {
    size_t first_quote = input.find('"');
    if (first_quote == std::string::npos) return false;
    
    size_t second_quote = input.find('"', first_quote + 1);
    if (second_quote == std::string::npos) return false;
    name = input.substr(first_quote + 1, second_quote - first_quote - 1);

    std::istringstream remaining(input.substr(second_quote + 1));
    remaining >> price >> qty;
    
    return !remaining.fail() && remaining.eof();
}


int main() {
    std::string command;
    double price;
    int qty, id, threshold;
    std::string name, line;
    
    while (true) {
        //std::cout << "\nEnter command (create/find/update/delete/total/print/exit): ";
        std::getline(std::cin, line);
        std::istringstream iss(line);
        iss >> command;
        
        if (command.empty()) continue;
        
        if (command == "exit") {
            std::cout << "Bye!\n";
            break;
        }
        
        if (command == "create") {
            std::string item_name;
            double item_price;
            int item_qty;
            
            if (parse_create_command(line, item_name, item_price, item_qty)) {
                create_item(item_name, item_price, item_qty);
                std::cout << "Added: \"" << item_name << "\" $" << item_price << " Qty: " << item_qty << std::endl;
            } else {
                std::cout << "Error: Invalid format.\n";
            }
        }
        else if (command == "print") {
            print_inventory(get_inventory());
        }
        else if (command == "find") {
            std::cout << "Enter item ID: ";
            if (!(iss >> id)) {
                std::cin >> id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            
            Item found_item;
            if (find_item(id, found_item)) {
                print_item(found_item);
            } else {
                std::cout << "Item not found with ID: " << id << std::endl;
            }
        }
        else if (command == "update") {
            std::cout << "Enter item ID, new price, new quantity: ";
            if (!(iss >> id >> price >> qty)) {
                std::cin >> id >> price >> qty;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            
            if (update_item(id, price, qty)) {
                std::cout << "Updated item with ID: " << id << std::endl;
            } else {
                std::cout << "Item not found with ID: " << id << std::endl;
            }
        }
        else if (command == "delete") {
            std::cout << "Enter item ID: ";
            if (!(iss >> id)) {
                std::cin >> id;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            
            if (delete_item(id)) {
                std::cout << "Deleted item with ID: " << id << std::endl;
            } else {
                std::cout << "Item not found with ID: " << id << std::endl;
            }
        }
        else if (command == "total") {
            double total_value = calculate_total_value();
            std::cout << "Total inventory value: $" << std::fixed << std::setprecision(2) << total_value << std::endl;
        }
        else {
            std::cout << "Invalid command. Try again.\n";
        }
        
        // 버퍼 비우기
        if (std::cin.peek() == '\n') {
            std::cin.ignore();
        }
    }
    return 0;
}