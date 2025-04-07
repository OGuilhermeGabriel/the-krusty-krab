#ifndef TYPES_H
#define TYPES_H

typedef enum Category{
	APPETIZER, 
	MAIN_COURSE, 
	DESSERT, 
	BEVERAGE
} Category;

typedef enum OrderStatus{
	PENDING, 
	IN_PREPARATION,
	READY, 
	DELIVERED
} OrderStatus;

typedef struct Customer {
	char *name;
	unsigned age; 
	char *address; 
	char *email; 
} Customer;

typedef struct Menu{
	char *name; 
	char *description; 
	float price; 
	Category category; 
} Menu;

typedef struct Order{
	char id[10];
	struct Customer customer;
	struct Menu *items; //items from menu  
	int itemCount; 
	OrderStatus status; 
} Order; 

#endif 
