//esta é a função principal 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h" 

int main (){
	Order *orderList = NULL; 
	int orderCount = 0, menuSize = 0, option; 
	Menu *menu = NULL; 

    do {
        printf("\n===== MENU =====\n");
        printf("1. Add menu item\n");
        printf("2. Remove menu item\n");
        printf("3. Update menu item\n");
        printf("4. List menu\n");
        printf("5. Add order\n");
        printf("6. Update order status\n");
        printf("7. List orders\n");
        printf("0. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        getchar(); // Clear buffer

        switch (option) {
            case 1: { // Add menu itemi
		clear_screen();
                char name[50], description[100];
                float price;
                int category;

                printf("Enter item name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline

                printf("Enter item description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0;

                printf("Enter price: ");
                scanf("%f", &price);
                getchar();

                printf("Enter category (0=Appetizer, 1=Main Course, 2=Dessert, 3=Beverage): ");
                scanf("%d", &category);
                getchar();

                add_menu_item(&menu, &menuSize, name, description, price, (Category)category);
                break;
            }

            case 2: { // Remove menu item
		clear_screen();
                char name[50];
                printf("Enter the name of the item to remove: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;
                delete_menu_item(&menu, &menuSize, name);
                break;
            }

            case 3: { // Update menu item
		clear_screen();
                char name[50], newDescription[100];
                float newPrice;
                int newCategory;

                printf("Enter item name to update: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = 0;

                printf("Enter new description: ");
                fgets(newDescription, sizeof(newDescription), stdin);
                newDescription[strcspn(newDescription, "\n")] = 0;

                printf("Enter new price: ");
                scanf("%f", &newPrice);
                getchar();

                printf("Enter new category (0=Appetizer, 1=Main Course, 2=Dessert, 3=Beverage): ");
                scanf("%d", &newCategory);
                getchar();

                update_menu_item(menu, menuSize, name, newDescription, newPrice, (Category)newCategory);
                break;
            }

            case 4: // List menu
		clear_screen();
                list_menu(menu, menuSize);
                break;

            case 5: { // Add order
		clear_screen();
                char id[10];
                char customerName[50], address[100], email[50];
                int itemCount;

                printf("Enter order ID: ");
                fgets(id, sizeof(id), stdin);
                id[strcspn(id, "\n")] = 0;

                printf("Enter customer name: ");
                fgets(customerName, sizeof(customerName), stdin);
                customerName[strcspn(customerName, "\n")] = 0;

                printf("Enter customer address: ");
                fgets(address, sizeof(address), stdin);
                address[strcspn(address, "\n")] = 0;

                printf("Enter customer email: ");
                fgets(email, sizeof(email), stdin);
                email[strcspn(email, "\n")] = 0;

                printf("How many items in the order? ");
                scanf("%d", &itemCount);
                getchar();

                if (itemCount > menuSize || itemCount <= 0) {
                    printf("Invalid number of items!\n");
                    break;
                }

                Menu *orderItems = malloc(itemCount * sizeof(Menu));
                if (orderItems == NULL) {
                    printf("Memory allocation error!\n");
                    break;
                }

                for (int i = 0; i < itemCount; i++) {
                    printf("Enter item name for item %d: ", i + 1);
                    char itemName[50];
                    fgets(itemName, sizeof(itemName), stdin);
                    itemName[strcspn(itemName, "\n")] = 0;

                    int found = 0;
                    for (int j = 0; j < menuSize; j++) {
                        if (strcmp(menu[j].name, itemName) == 0) {
                            orderItems[i] = menu[j];
                            found = 1;
                            break;
                        }
                    }

                    if (!found) {
                        printf("Item not found in menu!\n");
                        free(orderItems);
                        break;
                    }
                }

                Customer customer = {strdup(customerName), 0, strdup(address), strdup(email)};
                add_order(&orderList, &orderCount, id, customer, orderItems, itemCount);

                free(orderItems);
                break;
            }

            case 6: { // Update order status
		clear_screen();
                char id[10];
                int status;

                printf("Enter order ID to update: ");
                fgets(id, sizeof(id), stdin);
                id[strcspn(id, "\n")] = 0;

                printf("Enter new status (0=Pending, 1=In Preparation, 2=Ready, 3=Delivered): ");
                scanf("%d", &status);
                getchar();

                update_order_status(orderList, orderCount, id, (OrderStatus)status);
                break;
            }

            case 7: // List orders
		clear_screen();
                list_orders(orderList, orderCount);
                break;

            case 0:
		clear_screen();
                printf("Exiting...\n");
                break;

            default:
		clear_screen();
                printf("Invalid option! Try again.\n");
        }

    } while (option != 0);
    
    // Free allocated memory
    for (int i = 0; i < menuSize; i++) {
        free(menu[i].name);
        free(menu[i].description);
    }
    free(menu);

    for (int i = 0; i < orderCount; i++) {
        free(orderList[i].customer.name);
        free(orderList[i].customer.address);
        free(orderList[i].customer.email);
        for (int j = 0; j < orderList[i].itemCount; j++) {
            free(orderList[i].items[j].name);
            free(orderList[i].items[j].description);
        }
        free(orderList[i].items);
    }
    free(orderList);

    return 0;
}
