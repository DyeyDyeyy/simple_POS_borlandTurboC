#include <stdio.h>
#include <conio.h>
#include <string.h>

#define USERNAME "cashier"
#define PASSWORD "password"

struct Item {
    char name[50];
    float price;
};

void login();
void showMenu();
float calculateTotal(struct Item items[], int quantities[], int count);
void printReceipt(struct Item items[], int quantities[], int count, float total, float customerMoney);

int main() {
    login();
    getch();
    return 0;
}

void login() {
    char username[20];
    char password[20];

    printf("=== Welcome To My POS ===\n");
    printf("=== Cashier Login ===\n");
    printf("Username: ");
    scanf("%s", username);
    printf("Password: ");
    scanf("%s", password);

    if (strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0) {
        printf("Login successful!\n");
        showMenu();
    } else {
        printf("Invalid username or password. Please try again.\n");
        login();
    }
}

void showMenu() {
    struct Item items[3] = {{"T-shirt", 10.0}, {"Pants", 20.0}, {"Hoodie Jacket", 30.0}};
    int quantities[3] = {0};
    int choice;
    float total = 0;
    float customerMoney;

    do {
        printf("\n=== Menu ===\n");
        printf("1. %s - P %.2f\n", items[0].name, items[0].price);
        printf("2. %s - P %.2f\n", items[1].name, items[1].price);
        printf("3. %s - P %.2f\n", items[2].name, items[2].price);
        printf("4. Calculate total\n");
        printf("5. Print receipt and exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
            case 2:
            case 3:
                printf("Enter quantity for %s: ", items[choice - 1].name);
                scanf("%d", &quantities[choice - 1]);
                break;
            case 4:
                total = calculateTotal(items, quantities, 3);
                printf("Total: P %.2f\n", total);
                break;
            case 5:
                printf("Enter customer money amount: P ");
                scanf("%f", &customerMoney);
                printReceipt(items, quantities, 3, total, customerMoney);
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(1);
}

float calculateTotal(struct Item items[], int quantities[], int count) {
    float total = 0;
    for (int i = 0; i < count; ++i) {
        total += items[i].price * quantities[i];
    }
    return total;
}

void printReceipt(struct Item items[], int quantities[], int count, float total, float customerMoney) {
    printf("\n=== Receipt ===\n");
    for (int i = 0; i < count; ++i) {
        if (quantities[i] > 0) {
            printf("%s x%d - P %.2f\n", items[i].name, quantities[i], items[i].price * quantities[i]);
        }
    }
    printf("Total: P %.2f\n", total);
    printf("Customer money: P %.2f\n", customerMoney);
    printf("Change: P %.2f\n", customerMoney - total);
    printf("Thank you for shopping!\n");
}
