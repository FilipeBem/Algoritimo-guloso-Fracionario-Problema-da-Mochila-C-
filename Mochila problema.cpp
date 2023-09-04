#include <stdio.h>
#include <stdlib.h>
// Define the data structure for an item.
struct Item {
    char name[20];
    int weight;
    int profit;
};
// Define the function to sort the items in decreasing order of their profit-to-weight ratio.
void sortItems(struct Item *items, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].profit / items[i].weight < items[j].profit / items[j].weight) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}
// Define the function to add an item to the knapsack.
void addItem(struct Item *items, int n, int capacity, int *totalProfit) {
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            *totalProfit += items[i].profit;
        }
    }
}
// Define the function to remove an item from the knapsack.
void removeItem(struct Item *items, int n, int capacity, int *totalProfit) {
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= capacity) {
            capacity += items[i].weight;
            *totalProfit -= items[i].profit;
        }
    }
}
// Define the main function.
int main() {
    // Define the number of items.
    int n = 5;
    // Define the items.
    struct Item items[] = {
        {"Item 1", 10, 100},/*Peso, Beneficio*/
        {"Item 2", 20, 200},
        {"Item 3", 30, 300},
        {"Item 4", 40, 400},
        {"Item 5", 50, 500},
    };
    // Sort the items in decreasing order of their profit-to-weight ratio.
    sortItems(items, n);
    // Initialize the capacity of the knapsack.
    int capacity = 100;
    // Initialize the total profit.
    int totalProfit = 0;
    // Add the items to the knapsack until the capacity is reached.
    addItem(items, n, capacity, &totalProfit);
    // Print the total profit.
    printf("O total profit is %d.\n", totalProfit);
    return 0;
}
