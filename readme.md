# The Krusty Krab Menu and Order Management System (On progress)

![the_krusty_krab](/assets/The_Krusty_Krab.png)

For a few weeks now, Mr. Krabs has seen a good opportunity to make more money with his business delivering snacks. He even hired Mrs. Puff to deliver the orders using her car.

![mr_krabs_money](/assets/mr_krabs_money.jpg)

However, Squidward recently resigned from The Krusty Krab and SpongeBob alone will not be enough to manage the restaurant's orders and menu.

![squidwards_out](/assets/without_squid.png)

With this in mind, Mr. Krabs has hired a programmer to deliver an menu and order management system to fill in for Squidward.

## Summary

- [Overview](###Overview)
- [Features](###Features)


### Overview

This project was made based on some concepts learned in the C language: pointers, memory allocation and reallocation, structs, enumerations and search and sorting algorithms.

### Features 

- Register a menu

Containing all the Krusty Krab snacks and drinks to order for delivery.

- Order management

Mr. Krabs wants to have control over the flow of orders to make it easier for his Sponge Bob chef to order.

- Control the status of each order

Mr. Krabs also wants to be aware at all times whether Mrs. Puff has already delivered the orders or not.

(more features coming soon...)

### Methodology

Here I will talk a little more about how I designed the algorithm for the restaurant's order and menu management system.

#### Pointers

They will be used for various aspects of the code: from dynamic memory allocation to accessing certain data from main memory.

#### Memory allocation and reallocation

The use of memory allocation will be necessary to be able to handle possible large quantities of orders and additions to the restaurant's menu, avoiding memory leak and overflow problems.

#### File access, headers

They will be necessary to be able to organize the code in the best possible way, instead of leaving everything together and polluted in the same main.c file

#### Functions

Each operation performed by the system is directly related to a function. It is a good approach to manipulate the code since I can "attack" a problem about the operation of adding a new order in isolation, dealing only with its respective function.
