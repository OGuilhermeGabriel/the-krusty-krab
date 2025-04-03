#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

//Function to clear the screen 
void clear_screen(){
	#ifdef _WIN32 
		system("cls");
	#else
		system("clear");
	#endif
}
//Drawing Mr.Krabs function
void drawMrKrabs(){
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣤⡞⣻⡄⠀⠀⣠⣼⢿⣷⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣷⣿⠏⠀⠀⢸⣿⣼⡟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡔⠛⠛⡇⠀⠀⣠⠟⠛⢻⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡏⠀⠀⠀⡿⠀⡴⠁⠀⠀⠈⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡾⠀⠀⠀⢠⡇⢰⠃⠀⠀⠀⢸⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣼⡇⠀⠀⠀⢺⢃⡟⠀⠀⠀⢀⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⡇⠀⠀⠀⣿⢸⠃⠀⠀⠀⣸⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡇⠀⡀⢠⡇⣾⠀⣀⠀⢀⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡇⣸⣿⣿⠃⡏⣼⣿⡇⣸⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⣧⢻⣿⢻⠀⡇⢻⣿⢇⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⡄⠀⢸⠀⣿⠀⠀⣸⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⠀⢸⠀⢹⠀⢀⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢤⡀⠀⠈⢧⠘⣇⣸⡄⢸⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⠿⣶⡬⣖⠉⠀⠣⠼⠢⢤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣞⠙⠛⠁⠀⠀⣰⢤⡈⠷⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠃⠈⠉⠙⠛⠋⠉⠀⠀⠀⠀⢻⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠎⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⢠⣤⣤⣄⣀⣠⡤⣄⣴⢾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡸⣷⠀⣠⠤⡀⠀⣀⣀⣤⡀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⣿⢠⡶⠶⣤⡽⠃⣨⠿⠈⣟⠦⣀⠀⠀⠀⠀⠀⠀⠀⣀⣠⠔⠋⠀⠼⠋⠀⢸⣋⣩⣽⠀⡼⠁⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⢀⣀⠀⢻⢻⡇⠀⠙⠶⡴⠃⠀⠀⢻⠔⢻⡇⠀⢀⠾⣟⠛⢛⡿⠋⠁⠀⠀⠀⢀⣀⣀⣻⣷⠃⡼⠁⠀⠀⢀⡀⠀⠀⠀\n");
    printf("⠀⣠⠴⠛⠉⣉⠿⠾⠇⠿⠓⢦⡼⠁⠀⠀⠀⠀⠀⠘⣧⠔⠁⠀⠙⠚⠁⠀⠀⠀⠀⠀⠀⠀⠈⢻⡵⠃⠐⠓⠦⣠⠞⠉⠉⠑⢆⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
}



//Order management functions 

//add_order function 
void add_order(Order **orderList, int *orderCount, char *id, Customer customer, Menu *items, int itemCount){
	*orderList = realloc(*orderList, (*orderCount + 1)* sizeof(Order));

	if(*orderList == NULL){
		printf("Memory allocation error for orders!\n");
		exit(1);
	}

	Order *newOrder = &(*orderList)[*orderCount];

	strcpy(newOrder->id, id); 
	newOrder->customer = customer; 
	newOrder->itemCount = itemCount; 
	newOrder->status = PENDING;

	newOrder->items = malloc(itemCount * sizeof(Menu));
	if(newOrder->items == NULL){
		printf("Memory allocation error for order items!\n");
	}

	for(int i=0; i<itemCount;i++){
		newOrder->items[i].name = strdup(items[i].name);
		newOrder->items[i].description = strdup(items[i].description); 
		newOrder->items[i].price = items[i].price; 
		newOrder->items[i].category = items[i].category;  
	}
	
	(*orderCount)++;
	printf("Order [%s] successfully created!\n", id);
}

//update_order_status function 
void update_order_status(Order *orderList, int orderCount, char *id, OrderStatus newStatus){
	for(int i=0; i<orderCount; i++){
		if(strcmp(orderList[i].id, id) == 0){
			orderList[i].status = newStatus; 
			printf("Order [%s] updated to STATUS: %d\n", id, newStatus);
			return;
		}
	}
	printf("Order [%s] not found!\n", id);
}

//list_orders function 
void list_orders(Order *orderList, int orderCount){
	if(orderCount == 0){
		printf("No orders registered!\n");
		return; 
	}

	const char *statusStrings[] = {"PENDING", "IN_PREPARATION", "READY", "DELIVERED"};

	printf("\n============ ORDER LIST ============\n");
	for (int i = 0; i < orderCount; i++){
		printf("\nOrder: [%s]\n", orderList[i].id);
		printf("Customer: %s\n", orderList[i].customer.name);
		printf("Status: %s\n", statusStrings[orderList[i].status]);
		printf("Ordered items:\n");
		
		float totalprice = 0.00;

		for(int j=0; j<orderList[i].itemCount;j++){
			printf(" - %s | $%.2f\n", orderList[i].items[j].name, orderList[i].items[j].price);
			totalprice += orderList[i].items[j].price;
		}
		printf("Total: $%.2f\n", totalprice);
		printf("-------------------------------------------\n");
	}
}

//Menu management functions 

//add_menu_item function
void add_menu_item(Menu **menu, int *menuSize, char *name, char *description, float price, Category category){
	*menu = realloc(*menu, (*menuSize + 1) * sizeof(Menu));

	if(*menu == NULL){
		printf("Memory allocation error for menu!\n");
		exit(1);
	}

	Menu *newItem = &(*menu)[*menuSize];

	newItem->name = strdup(name);
	newItem->description = strdup(description);
	newItem->price = price; 
	newItem->category = category; 

	(*menuSize)++;
	printf("Item added to menu successfully");
}

//delete_menu_item function 
void delete_menu_item(Menu **menu, int *menuSize, char *name){
	for(int i=0; i< *menuSize; i++){
		if(strcmp((*menu)[i].name, name) == 0){
			free((*menu)[i].name);
			free((*menu)[i].description);

			for(int j=i; j < (*menuSize)-1; j++){
				(*menu)[j] = (*menu)[j+1];
			}	

			*menu = realloc(*menu, (*menuSize-1)* sizeof(Menu));
			(*menuSize)--; 
			printf("Item removed from menu successfully!\n");
			return; 
		}
	}
	printf("Item not found in menu!\n");
}

//update_menu_item function 
void update_menu_item(Menu *menu, int menuSize, char *name, char *newDescription, float newPrice, Category newCategory){
	for(int i = 0; i < menuSize; i++){
		if(strcmp(menu[i].name, name) == 0){
			free(menu[i].description);
			menu[i].description = strdup(newDescription); 
			menu[i].price = newPrice; 
			menu[i].category = newCategory; 
			printf("Menu item updated successfully!\n");
			return; 
		}
	}
	printf("Item not found in menu!\n");
}

void list_menu(Menu *menu, int menuSize){
	if(menuSize == 0){
		printf("The menu is empty!\n");
		return; 
	}

	printf("\n============ THE KRUSTY KRAB MENU ============\n");
	for(int i=0; i < menuSize; i++){
		printf("Name: %s | Price: $%.2f | Description: %s\n", menu[i].name, menu[i].price, menu[i].description);
	}
}
