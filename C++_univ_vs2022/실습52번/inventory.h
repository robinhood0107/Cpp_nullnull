#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <vector>

struct Item {
    int id;              // identifier
    std::string name;
    double price;
    int qty;
};

using inventory = std::vector<Item>;

void create_item(const std::string& name, double price, int qty);
const inventory get_inventory();
bool find_item(int id, Item& found_item);
bool update_item(int id, double new_price, int new_qty);
bool delete_item(int id);

int generate_next_id();
double calculate_total_value();

#endif // INVENTORY_H