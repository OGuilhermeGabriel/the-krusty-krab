#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "file_manager.h"

//*** writing and reading functions for the menu ***

int load_menu(Menu **menu, const char *filename){
	FILE *file = fopen(filename, "r");
	if(!file) return 0; 

	int capacity = 10; 
	*menu = malloc(capacity * sizeof(Menu));
	if(!*menu){
		fclose(file);
		return 0; 
	}

	int count = 0; 
	char name[100], description[200]; 
	float price; 
	int category; 

	while(fscanf(file, "%99[^,],%199[^,],%f,%d\n", name, description, &price, &category) == 4){
		if(count >= capacity){
			capacity *= 2; 
			*menu = realloc(*menu, capacity * sizeof(Menu));
		
			if(!*menu){
				fclose(file);
				return 0; 
			}
		}	
		(*menu)[count].name = strdup(name);
		(*menu)[count].description = strdup(description);
		(*menu)[count].price = price;
		(*menu)[count].category = (Category)category;
		count++;
	}

	fclose(file);
	return count; 
}

void save_menu(Menu *menu, int size, const char *filename){
	FILE *file = fopen(filename, "w");
	if (!file) return; 

	for(int i=0; i < size; i++){
		fprintf(file, "%s,%s,%.2f,%d\n",
				menu[i].name,
				menu[i].description,
				menu[i].price, 
				menu[i].category);
	}

	fclose(file); 
}


//***writing and reading functions for the orders***

int load_orders(Order **orders, const char *filename){
	FILE *file = fopen(filename, "r");
	if(!file) return 0; 

	int capacity = 10; 
	*orders = malloc(capacity * sizeof(Order));
	if(!*orders){
		fclose(file); 
		return 0; 
	}

	int count = 0; 
	char line[512];
	while(fgets(line, sizeof(line), file)){
		if(count >= capacity){
			capacity *= 2; 
			*orders = realloc(*orders, capacity * sizeof(Order));
		}

		//Creating a order register to load every order
		Order *o = &(*orders)[count];

		//Loading ID's order 
		strncpy(o->id, line, 10);
		o->id[strcspn(o->id, "\n")] = 0; 

		//Loading Customer's informations/members from the order 
		fgets(line, sizeof(line), file);
		o->customer.name = strdup(strtok(line, ","));
		o->customer.age = atoi(strtok(NULL, ","));
		o->customer.address = strdup(strtok(NULL, ","));
		o->customer.email = strdup(strtok(NULL, "\n"));
		
		//Loading item count from the order
		fgets(line, sizeof(line), file);
		o->itemCount = atoi(line); //1 item per line
		o->items = malloc(o->itemCount * sizeof(Menu));

		//Loading each Item's informations/members from the order
		for(int i = 0; i < o->itemCount; i++){
			fgets(line, sizeof(line), file);
			char *name = strtok(line, ",");
			char *desc = strtok(NULL, ",");
			float price = atof(strtok(NULL, ","));
			int cat = atoi(strtok(NULL, "\n"));

			o->items[i].name = strdup(name);
			o->items[i].description = strdup(desc);
			o->items[i].price = price;
			o->items[i].category = (Category)cat;
		}

		//Loading order's Status
		fgets(line, sizeof(line), file);
		o->status = (OrderStatus)atoi(line);

		count ++; 

	}

	fclose(file);
	return count; 
}

void save_orders (Order *orders, int count, const char *filename){
	FILE *file = fopen(filename, "w");
	if (!file) return; 

	//saving ID's and Customer's informations/members from each order
	for(int i = 0; i < count; i++){
		Order *o = &orders[i];
		fprintf(file, "%s\n", o->id);
		fprintf(file, "%s,%u,%s,%s\n",
				o->customer.name,
				o->customer.age,
				o->customer.address,
				o->customer.email);
		fprintf(file, "%d\n", o->itemCount);
	
		//saving items informations/members from each order
		for(int j = 0; j < o->itemCount; j++){
			fprintf(file, "%s,%s,%.2f,%d\n",
					o->items[j].name,
					o->items[j].description,
					o->items[j].price,
					o->items[j].category);
		}
		//saving order's status
		fprintf(file, "%d\n", o->status);
	}
	fclose(file);
}
