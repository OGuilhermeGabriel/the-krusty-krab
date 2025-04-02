#ifndef FUNCTIONS_H 
#define FUNCTIONS_H

#include "types.h" //importing structs and enumerations 

//function to clear the screen 
void clear_screen();

// Order management functions
void add_order(Order **orderList, int *orderCount, char *id, Customer customer, Menu *items, int itemCount);
void update_order_status(Order *orderList, int orderCount, char *id, OrderStatus newStatus);
void list_orders(Order *orderList, int orderCount);

// Menu management functions
void add_menu_item(Menu **menu, int *menuSize, char *name, char *description, float price, Category category);
void delete_menu_item(Menu **menu, int *menuSize, char *name);
void update_menu_item(Menu *menu, int menuSize, char *name, char *newDescription, float newPrice, Category newCategory);
void list_menu(Menu *menu, int menuSize);

#endif
