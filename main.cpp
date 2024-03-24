#include "Item.h"
int main()
{
  // Add some items
  Item::addItem();
  Item::addItem();

  // Print all items
  Item::printItems();

  // Export items to a file
  Item::exportToFile("items.txt");

  // Print the total cost
  std::cout << "Total Cost: " << Item::getTotalCost() << std::endl;

  // Print the value result for each item
  Item::printValueResult();

  return 0;
}
