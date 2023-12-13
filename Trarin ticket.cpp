#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
    struct Product* next;
};

struct Product* head = NULL;  // Head of the linked list

void insertProduct(int id, char Name[], float price, int quantity) {
    struct Product* newProduct = (struct Product*)malloc(sizeof(struct Product));
    newProduct->id = id;
    strcpy(newProduct->name, Name);
    newProduct->price = price;
    newProduct->quantity = quantity;
    newProduct->next = NULL;

    if (head == NULL) {
        head = newProduct;
    } else {
        struct Product* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newProduct;
    }
}

void freeProducts() {
    struct Product* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void displayProducts() {
    struct Product* current = head;

    printf("\n           ,,,,,,,,,,,,,,,,,,,,,,,,,,        \n");
    printf("           | Welcome to vending app |    \n");
    printf("           ``````````````````````````        \n");
    printf("................................................\n");
    printf("| %-6s %-15s %-12s %-2s |\n", "ID", "Name", "Price", "Quantity");

    printf("|``````````````````````````````````````````````|\n");

    while (current != NULL) {
        printf("|  %-5d %-15s %-12.2f %-2d       |\n", current->id, current->name, current->price, current->quantity);
        current = current->next;
    }

    printf("|,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,|\n");
    printf("\n");
}

void select(int productID, int quantity, float* balance, float* totalCost) {
    struct Product* current = head;

    while (current != NULL && current->id != productID) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Invalid selection. Please enter a valid product ID.\n");
        return;
    }

    if (quantity > current->quantity) {
        printf("Sorry, we don't have enough quantity of %s. Please choose a smaller quantity.\n", current->name);
        return;
    }

    float cost = current->price * quantity;
    if (cost > *balance) {
        printf("Insufficient balance. Please insert more money.\n");
        return;
    }

    if (current->quantity > 0) {
        printf("Enjoy your %d %s!\n", quantity, current->name);
        current->quantity -= quantity;
        *balance -= cost;
        *totalCost += cost;
    } else {
        printf("Sorry, %s is out of stock. Please choose another product.\n", current->name);
    }
}

int main() {
    float balance = 10000.0, totalCost = 0;
    int productCount = 0;
    int Quantity[6];

    // Insert products into the linked list
    insertProduct(1, "Chips", 15, 30);
    insertProduct(2, "Chocolate", 100, 20);
    insertProduct(3, "Soda", 35, 16);
    insertProduct(4, "Cake", 40, 15);
    insertProduct(5, "Biscuit", 20, 30);
    insertProduct(6, "Ice Cream", 50, 15);

    // Initialize Quantity array
    struct Product* current = head;
    for (int i = 0; i < 6; i++) {
        Quantity[i] = current->quantity;
        current = current->next;
    }

    while (1) {
        displayProducts();
        printf("Current Balance: $%.2f\n", balance);
        int productID, quantity;

        printf("Enter the product ID or 0 to exit: ");
        scanf("%d", &productID);

        if (productID == 0) break;

        printf("Enter the quantity you want to purchase: ");
        scanf("%d", &quantity);

        select(productID, quantity, &balance, &totalCost);

        current = head;
        while (current != NULL && current->id != productID) {
            current = current->next;
        }

        if (current != NULL) {
            int purchasedQuantity = Quantity[current->id - 1] - current->quantity;
            float productTotalCost = purchasedQuantity * current->price;
            printf("Added to Shopping Cart: %-2d %s for $%.2f\n", purchasedQuantity, current->name, productTotalCost);
            productCount++;
        }
    }

    printf("\n\n\n\n        ............ Shopping Cart ............\n\n");

    if (productCount > 0) {
        printf(",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,\n");
        printf("| %-5s %-20s %-12s %-12s |\n", "Qty", "Product", "Price(Tk.)", "Total");
        printf("|``````````````````````````````````````````````````````|\n");

        current = head;
        for (int i = 0; i < 6; i++) {
            int quantity = Quantity[i] - current->quantity;
            float productTotalCost = quantity * current->price;
            if(quantity > 0)
            printf("|  %-4d %-20s %-12.2f %-12.2f |\n", quantity, current->name, current->price, productTotalCost);
            current = current->next;
        }

        printf("|,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,|\n");
        printf("                            Total cost: $%.2f\n", totalCost);
    } else {
        printf("Your cart is empty.\n\n");
    }

    // Free the allocated memory for the linked list
    freeProducts();

    printf("\nThank you for using the Vending Machine! Your remaining balance is: $%.2f\n\n\n", balance);

    return 0;
       _GLIBCXX_HAVE_HYPOTgt
    nhyyhn
}
