#include<stdio.h>
#include<math.h>
#include<string.h>

    





void displayMenu();

int main()
{
    int choice;

    printf("====================================\n");
    printf("             CAFFTECH\n");
    printf("     SMART COFFEE BREWING ASSISTANT\n");
    printf("====================================\n");

    do
    {
        displayMenu();

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nGenerate Brewing Recipe - Coming Soon!\n");
                break;

            case 2:
                printf("\nCoffee Quantity Calculator - Coming Soon!\n");
                break;

            case 3:
                printf("\nTaste Adjustment - Coming Soon!\n");
                break;

            case 4:
                printf("\nBrewing History - Coming Soon!\n");
                break;

            case 5:
                printf("\nThank you for using CaffTech!\n");
                break;

            default:
                printf("\nInvalid choice! Please select 1 to 5.\n");
        }

    } while (choice != 5);

    return 0;
}

// Function definition
void displayMenu()
{
    printf("\n========== MAIN MENU ==========\n");
    printf("1. Generate Brewing Recipe\n");
    printf("2. Calculate Coffee Quantity\n");
    printf("3. Adjust Taste\n");
    printf("4. View Brewing History\n");
    printf("5. Exit\n");
    printf("===============================\n");
}




