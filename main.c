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
void adjustTaste();
void viewHistory();

void saveHistory(char method[], int servings, char strength[],float coffee, float water, int temperature,int brewingTime, char feedback[]);
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
        generateRecipe(methods, 3);
        break;

    case 2:
        coffeeCalculator();
        break;

    case 3:
        adjustTaste();
        break;

    case 4:
        viewHistory();
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
    int feedbackChoice;


    float water;
    float coffee;
    float ratio;

    char strength[20];
    char feedback[50];

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
        strcpy(strength, "Mild");
        break;

    case 2:
        ratio = 15;
        strcpy(strength, "Medium");
        break;

    case 3:
        ratio = 13;
        strcpy(strength, "Strong");
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
printf("\n========== TASTE FEEDBACK ==========\n");
printf("1. Bitter\n");
printf("2. Sour\n");
printf("3. Weak\n");
printf("4. Strong\n");
printf("5. Balanced\n");
printf("6. Not tried yet\n");

printf("\nEnter your feedback: ");

if (scanf("%d", &feedbackChoice) != 1)
{
    printf("Invalid input!\n");
    strcpy(feedback, "Not recorded");
}
else
{
    switch (feedbackChoice)
    {
        case 1:
            strcpy(feedback, "Bitter");
            break;

        case 2:
            strcpy(feedback, "Sour");
            break;

        case 3:
            strcpy(feedback, "Weak");
            break;

        case 4:
            strcpy(feedback, "Strong");
            break;

        case 5:
            strcpy(feedback, "Balanced");
            break;

        case 6:
            strcpy(feedback, "Not tried");
            break;

        default:
            strcpy(feedback, "Not recorded");
            break;
    }
}

saveHistory(methods[methodChoice - 1].name,
             servings,
             strength,
             coffee,
             water,
             methods[methodChoice - 1].temperature,
             methods[methodChoice - 1].brewingTime,
             feedback);

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

void adjustTaste()
{
    int choice;

    do
    {
        printf("\n========== TASTE ADJUSTMENT ==========\n");

        printf("1. Too Bitter\n");
        printf("2. Too Sour\n");
        printf("3. Too Weak\n");
        printf("4. Too Strong\n");
        printf("5. Balanced\n");
        printf("6. Return to Main Menu\n");

        printf("======================================\n");

        printf("\nHow did your coffee taste? ");
        
        if (scanf("%d", &choice) != 1)
        {
            printf("\nInvalid input! Please enter a number.\n");
            return;
        }

        switch (choice)
        {
            case 1:
                printf("\nRecommendation:\n");
                printf("Try a coarser grind or slightly lower the brewing temperature.\n");
                break;

            case 2:
                printf("\nRecommendation:\n");
                printf("Try a finer grind or slightly increase the brewing temperature.\n");
                break;

            case 3:
                printf("\nRecommendation:\n");
                printf("Increase the coffee quantity or reduce the water quantity.\n");
                break;

            case 4:
                printf("\nRecommendation:\n");
                printf("Increase the water quantity or reduce the coffee quantity.\n");
                break;

            case 5:
                printf("\nGreat! Your coffee is balanced.\n");
                printf("Keep using your current brewing recipe!\n");
                break;

            case 6:
                printf("\nReturning to Main Menu...\n");
                break;

            default:
                printf("\nInvalid choice! Please select 1 to 6.\n");
        }

    } while (choice != 6);
}

void saveHistory(char method[], int servings, char strength[],float coffee, float water, int temperature,int brewingTime, char feedback[])
{
    FILE *file;

    file = fopen("data/brewing_history.csv", "a");

    if (file == NULL)
    {
        printf("\nError opening brewing history file!\n");
        return;
    }

    fprintf(file, "%s,%d,%s,%.2f,%.2f,%d,%d,%s\n",
            method, servings, strength, coffee, water,
            temperature, brewingTime, feedback);

    fclose(file);

    printf("\nBrewing record saved successfully!\n");
}
void viewHistory()
{
    FILE *file;
    char line[200];

    char method[30];
    char strength[20];
    char feedback[50];

    int servings;
    int temperature;
    int brewingTime;

    float coffee;
    float water;

    file = fopen("data/brewing_history.csv", "r");

    if (file == NULL)
    {
        printf("\nNo brewing history found!\n");
        return;
    }

    // Skip the CSV header
    fgets(line, sizeof(line), file);

    printf("\n========== BREWING HISTORY ==========\n");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (sscanf(line, "%29[^,],%d,%19[^,],%f,%f,%d,%d,%49[^\n]",
                   method, &servings, strength,
                   &coffee, &water, &temperature,
                   &brewingTime, feedback) == 8)
        {
            printf("\n------------------------------------\n");

            printf("Method       : %s\n", method);
            printf("Servings     : %d\n", servings);
            printf("Strength     : %s\n", strength);
            printf("Coffee       : %.2f grams\n", coffee);
            printf("Water        : %.2f ml\n", water);
            printf("Temperature  : %d C\n", temperature);
            printf("Brewing Time : %d seconds\n", brewingTime);
            printf("Feedback     : %s\n", feedback);
        }
    }

    printf("\n====================================\n");

    fclose(file);
}





