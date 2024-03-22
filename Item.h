#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>

class Item {
public:
  std::string recipient;
  int value;
  int date; // Format: mmddyy
  int costToShip;

  Item();
  Item(const std::string& recipient, int value, int date, int costToShip);

  static void addItem();
  static void printItems();
  static void exportToFile(const std::string& filename);
  static int getTotalCost();
  static void printValueResult();

private:
  static std::vector<Item> items;
};

#endif // ITEM_H
