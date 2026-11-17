#include<stdio.h>
#include<math.h>
#include<string.h>

    


int main()
{
    int cups;
    float price = 80.0;
    float total;

    printf("================================\n");
    printf("       CAFFTECH COFFEE SHOP\n");
    printf("================================\n");

    printf("\nPrice per cup: Rs. %.2f\n", price);

    printf("How many cups of coffee do you want? ");
    scanf("%d", &cups);

    total = cups * price;

    printf("\n---------- YOUR BILL ----------\n");
    printf("Number of cups : %d\n", cups);
    printf("Price per cup  : Rs. %.2f\n", price);
    printf("Total amount   : Rs. %.2f\n", total);

    printf("\nThank you for visiting CaffTech!\n");

    return 0;
}



