#include <stdio.h>
#include <string.h>
struct date {
    int day;
    int month;
    int year;
};
typedef struct
{
    char name[100];
    char discription[255];
    char priority[20];
    struct date deadline;
} taches;

taches P[100];
int run = 0;

void add() {
    printf("Enter the task name: ");
    scanf(" %[^\n]", P[run].name);
    printf("Enter the day: ");
    scanf("%d", &P[run].deadline.day);
    printf("enter month: ");
    scanf("%d", &P[run].deadline.month);
    printf("enter year: ");
    scanf("%d", &P[run].deadline.year);
    printf("Enter the description: ");
    scanf(" %[^\n]", P[run].discription);
    printf("Enter priority (high or low): ");
    scanf("%s", P[run].priority);
    run++;
}

void display() {
    int i;
    for (i = 0; i < run; i++) {
        printf("\n-----------------------\n");
        printf("Name       : %s\n", P[i].name);
        printf("Description: %s\n", P[i].discription);
        printf("Priority   : %s\n", P[i].priority);
        printf("date       : %d/%d/%d", P[i].deadline.day, P[i].deadline.month, P[i].deadline.year);
        printf("\n-----------------------\n");

    }
}

void modify() {
    int mo;
    printf("Enter the task number to modify (1-%d): ", run);
    scanf("%d", &mo);
    // Convert to 0-based index
    if (mo < 1 || mo > run) {
        printf("Invalid task number.\n");
        return;
    }
    mo--;  // Adjust for 0-based index

    printf("Enter the new name: ");
    scanf(" %[^\n]", P[mo].name);
    printf("Enter new deadline: ");
    scanf("%d", &P[mo].deadline);
    printf("Enter the new description: ");
    scanf(" %[^\n12]", P[mo].discription);
    printf("Enter the new priority: ");
    scanf("%s", P[mo].priority);
}

void delete() {
    int mo, i;
    printf("Enter the task number to delete (1-%d): ", run);
    scanf("%d", &mo);
    // Convert to 0-based index
    if (mo < 1 || mo > run) {
        printf("Invalid task number.\n");
        return;
    }
    mo--;  // Adjust for 0-based index

    for (i = mo; i < run - 1; i++) {
        P[i] = P[i + 1];
    }
    run--;  // Reduce the count of tasks
}

void filter() {
    int i;
    char filter[20];

    // Ask user for priority filter
    printf("Enter priority to filter (high or low): ");
    scanf("%s", filter);

    printf("\nTasks with priority '%s':\n", filter);
    for (i = 0; i < run; i++) {
        if (strcmp(P[i].priority, filter) == 0) {  // Only print tasks with matching priority
            printf("Name: %s\n", P[i].name);
            printf("Deadline: %d\n", P[i].deadline);
            printf("Description: %s\n", P[i].discription);
            printf("Priority: %s\n\n", P[i].priority);
        }
    }
}

int main() {
    int chois;
    do {
        printf("\n1. Add task\n");
        printf("2. Display tasks\n");
        printf("3. Modify task\n");
        printf("4. Delete task\n");
        printf("5. Filter tasks\n");  // New option
        printf("0. Exit\n");  // Option to exit the program
        printf("Select your choice: ");
        scanf("%d", &chois);
        switch (chois) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: modify(); break;
            case 4: delete(); break;
            case 5: filter(); break;  // Filter by priority functionality
            case 0: printf("End of the program\n"); break;  // Exit when 0 is chosen
            default: printf("Invalid choice\n"); break;
        }
    } while (chois != 0);  // Loop ends when the user chooses 0

    return 0;
}
