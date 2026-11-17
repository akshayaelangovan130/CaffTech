#include<stdio.h>
#include<math.h>
#include<string.h>

    
struct BrewingMethod
{
    char name[30];
    float ratio;
    int temperature;
    int brewingTime;
};




void displayMenu();
void displayMethods(struct BrewingMethod methods[], int size);
void generateRecipe(struct BrewingMethod methods[], int size);
void coffeeCalculator();

int main()
{
    int choice;

    printf("====================================\n");
    printf("             CAFFTECH\n");
    printf("     SMART COFFEE BREWING ASSISTANT\n");
    printf("====================================\n");

    struct BrewingMethod methods[3] =
{
    {"Pour-over", 15, 93, 180},
    {"French Press", 15, 94, 240},
    {"AeroPress", 12, 90, 120}
};
    do
    {
        displayMenu();

        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1)
            {
                printf("\nInvalid input! Please enter a number.\n");
                break;
            }

        switch (choice)
        {
            case 1:
                displayMethods(methods, 3);
                break;

            case 2:
                generateRecipe(methods, 3);
                break;

            case 3:
                coffeeCalculator();
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
void displayMethods(struct BrewingMethod methods[], int size)
{
    int i;

    printf("\n======= AVAILABLE BREWING METHODS =======\n");

    for (i = 0; i < size; i++)
    {
        printf("\n%d. %s", i + 1, methods[i].name);
        printf("\n   Ratio       : 1:%.0f", methods[i].ratio);
        printf("\n   Temperature : %d C", methods[i].temperature);
        printf("\n   Brewing Time: %d seconds\n", methods[i].brewingTime);
    }

    printf("\n=========================================\n");
}

void generateRecipe(struct BrewingMethod methods[], int size)
{
    int methodChoice;
    int servings;
    int strengthChoice;

    float water;
    float coffee;
    float ratio;

    printf("\n======= GENERATE BREWING RECIPE =======\n");

    // Display available methods
    displayMethods(methods, size);

    printf("\nSelect brewing method (1-%d): ", size);
    if (scanf("%d", &methodChoice) != 1)
    {
        printf("Invalid input!\n");
        return;
    }

    if (methodChoice < 1 || methodChoice > size)
    {
        printf("Invalid brewing method!\n");
        return;
    }

    printf("\nEnter number of servings: ");
    if (scanf("%d", &servings) != 1 || servings <= 0)
    {
        printf("Invalid number of servings!\n");
        return;
    }

    printf("\nSelect coffee strength:\n");
    printf("1. Mild\n");
    printf("2. Medium\n");
    printf("3. Strong\n");

    printf("Enter your choice: ");
    if (scanf("%d", &strengthChoice) != 1)
    {
        printf("Invalid input!\n");
        return;
    }

    switch (strengthChoice)
    {
        case 1:
            ratio = 17;
            break;

        case 2:
            ratio = 15;
            break;

        case 3:
            ratio = 13;
            break;

        default:
            printf("Invalid strength choice!\n");
            return;
    }

    // Calculate water and coffee
    water = servings * 225;
    coffee = water / ratio;

    // Display recipe
    printf("\n========== YOUR COFFEE RECIPE ==========\n");

    printf("Brewing Method : %s\n", methods[methodChoice - 1].name);
    printf("Servings       : %d\n", servings);

    if (strengthChoice == 1)
        printf("Strength       : Mild\n");
    else if (strengthChoice == 2)
        printf("Strength       : Medium\n");
    else
        printf("Strength       : Strong\n");

    printf("Coffee         : %.2f grams\n", coffee);
    printf("Water          : %.2f ml\n", water);

    printf("Temperature    : %d C\n",
           methods[methodChoice - 1].temperature);

    printf("Brewing Time   : %d seconds\n",
           methods[methodChoice - 1].brewingTime);

    printf("Coffee Ratio   : 1:%.0f\n", ratio);

    printf("========================================\n");
}

void coffeeCalculator()
{
    int choice;
    float coffee, water, ratio;

    do
    {
        printf("\n======= COFFEE QUANTITY CALCULATOR =======\n");
        printf("1. Calculate Coffee from Water\n");
        printf("2. Calculate Water from Coffee\n");
        printf("3. Return to Main Menu\n");
        printf("==========================================\n");

        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input!\n");
            return;
        }

        switch (choice)
        {
            case 1:

                printf("\nEnter water quantity (ml): ");
                if (scanf("%f", &water) != 1 || water <= 0)
                {
                    printf("Invalid water quantity!\n");
                    return;
                }

                printf("Enter coffee-to-water ratio (e.g. 15 for 1:15): ");
                if (scanf("%f", &ratio) != 1 || ratio <= 0)
                {
                    printf("Invalid ratio!\n");
                    return;
                }

                coffee = water / ratio;

                printf("\nRequired coffee: %.2f grams\n", coffee);
                break;

            case 2:

                printf("\nEnter coffee quantity (grams): ");
                if (scanf("%f", &coffee) != 1 || coffee <= 0)
                {
                    printf("Invalid coffee quantity!\n");
                    return;
                }

                printf("Enter coffee-to-water ratio (e.g. 15 for 1:15): ");
                if (scanf("%f", &ratio) != 1 || ratio <= 0)
                {
                    printf("Invalid ratio!\n");
                    return;
                }

                water = coffee * ratio;

                printf("\nRequired water: %.2f ml\n", water);
                break;

            case 3:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice! Select 1, 2 or 3.\n");
        }

    } while (choice != 3);
}






