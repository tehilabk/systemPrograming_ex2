#include <stdio.h>
#include "myBank.h"

int main()
{
    char opperationCode;
    
    printf("Please choose a transaction type: \n O-Open Account \n B-Balance Inquiry \n D-Deposit \n W-Withdrawal \n C-Close Account \n I-Interest \n P-Print \n E-Exit");
    scanf(" %c", &opperationCode);
    
    switch (getchar())
    {
        case 'O':
            openAcount();
            break;
    
        case 'B':
            getBalance();
            break;
        
        case 'D':
            deposit();
            break;
        
        case 'W':
            withdrawal();
            break;
    };


}
    