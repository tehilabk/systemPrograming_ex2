#include <stdio.h>
#include <stdbool.h>
#include "myBank.h"
#include "myBank.c"


int main()
{
    bool stop = false;
    char opperationCode;
    
    while(!stop){
        
        printf("Please choose a transaction type: \n O-Open Account \n B-Balance Inquiry \n D-Deposit \n W-Withdrawal \n C-Close Account \n I-Interest \n P-Print \n E-Exit \n");
        
        
        opperationCode = getchar();
        
        if(opperationCode== '\n'){
            opperationCode = getchar();
        }
        switch (opperationCode)
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
                
            case 'C':
                closeAccount();
                break;
                
            case 'I':
                setInterest();
                break;
            
            case 'P':
                print();
                break;
                
            case 'E':
                stop = true;
                break;
            
            default:    
                printf(" Invalid transaction type \n\n");
        }
    }
        
}
