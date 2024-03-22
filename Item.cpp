#include "Item.h"
#include <fstream>
#include <iomanip>
#include <iostream>

std::vector<Item> Item::items;

Item::Item(): recipient("Unknown"), value(0), date(0), costToShip(0)
{
}

Item::Item(const std::string& recipient, int value, int date, int costToShip):
    recipient(recipient), value(value), date(date), costToShip(costToShip)
{
}

void Item::addItem()
{
  std::string recipient;
  int value, date, costToShip;
  std::cout << "Enter recipient, value, date (mmddyy), and cost to ship: ";
  std::cin >> recipient >> value >> date >> costToShip;
  items.emplace_back(recipient, value, date, costToShip);
}

void Item::printItems()
{
  for (const auto& item : items) {
    std::cout << "Recipient: " << item.recipient << ", Value: " << item.value
              << ", Date: " << item.date
              << ", Cost to Ship: " << item.costToShip << std::endl;
  }
}

void Item::exportToFile(const std::string& filename)
{
  std::ofstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Failed to open file: " << filename << std::endl;
    return;
  }
  for (const auto& item : items) {
    file << item.recipient << " " << item.value << " " << item.date << " "
         << item.costToShip << std::endl;
  }
  file.close();
}

int Item::getTotalCost()
{
  int total = 0;
  for (const auto& item : items) {
    total += item.costToShip;
  }
  return total;
}

void Item::printValueResult()
{
  for (const auto& item : items) {
    std::cout << "Recipient: " << item.recipient << ", Value: " << item.value;
    if (item.value >= 10000 && item.value <= 50000) {
      std::cout << ", Result: 1.75%";
    } else if (item.value < 10000) {
      std::cout << ", Result: 2%";
    } else {
      std::cout << ", Result: 1.5%";
    }
    std::cout << std::endl;
  }
}
