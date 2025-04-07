#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "types.h"

int load_menu(Menu **menu, const char *filename);
void save_menu(Menu *menu, int size, const char *filename);

int load_orders(Order **orders, const char *filename);
void save_orders(Order *orders, int size, const char *filename);

#endif
