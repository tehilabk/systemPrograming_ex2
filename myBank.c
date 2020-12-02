#include <stdio.h>
//TODO define
//TODO .2 to all printf

double bank [50][2] = {0};//inner array(amount, status) => status = 1 for closed and 0 for open


char errorMessage[6][100] = {//errors array
    "",
    "Failed to read the account number \n",             //1
    "This account is closed \n",                        //2
    "Invalid Amount \n",                                //3
    "Failed to read the amount \n",                     //4
    "Faild. you have reached the max amount allowed \n" //5
}; 

int accountStatus, amountStatus, accountNum = 0, account;
double interest, amount;


/*
   returns  0 => legal amount
            3 => negative amount 
*/
int checkAmount(double amount){

    if(amount<0){
        return 3;
    }
    // if(!isdigit(amount)){
    //     return 4;
    // }
    return 0;
}

/*
   returns  0 => legal key
            1 => accountKey is out of bound 
            2 => account closed
*/
int checkAccount(int accountKey){
    if (accountKey<901 || accountKey>950 || accountKey > accountNum+900){
        return 1;
    }

    if(bank[accountKey-901][1] == 1){
        return 2;
    }
    return 0;
}


/*
open a new account
*/
void openAcount(){
    printf("please enter amount for deposit:");
    scanf("%lf", &amount);


    amountStatus = checkAmount(amount);
    if(amountStatus != 0){
        printf(" %s \n", errorMessage[amountStatus]);
        return;
    }
    int i;
    if(accountNum>49){
        for (i=0; i<50; i++){
            if (bank [i][1] == 1 ){ 
                bank [i][0]= amount;    
                bank [i][1]=0;
                printf ("New account number is: %d \n\n" , i+901);
                return;
            }
        }
                printf(" %s \n", errorMessage[5]);
                return;  
        
    }

    for (i=0; i<accountNum; i++){
        if (bank [i][1] == 1 ){
            bank [i][0]= amount;
            bank [i][1]=0;
            printf ("New account number is: %d \n\n" , i+901);
            return;
        }
    }
    
    bank[accountNum][0]= amount;
    printf ("New account number is: %d \n\n" , accountNum+901);
    accountNum++;
        
}


/*
get balance of account
*/
void getBalance(){
    printf("Please enter account number:");
    scanf("%d", &account);
    accountStatus = checkAccount(account); 
    if(accountStatus != 0){
        printf(" %s \n", errorMessage[accountStatus]);
        return;
    }
    
    printf("The balance of account number %d is: %.2lf \n\n" , account , bank[account-901][0]);
}

/*
deposit money in account
*/
void deposit(){
    printf("Please enter account number:");
    scanf("%d", &account);
    accountStatus = checkAccount(account); 
    if(accountStatus!=0){
        printf(" %s \n", errorMessage[accountStatus]);
        return;
    }

    printf("Please enter the amount to deposit:");
    scanf("%lf", &amount);
    amountStatus = checkAmount(amount);
    if(amountStatus!=0){
        printf(" %s \n", errorMessage[amountStatus]);
    }

    bank[account-901][0] += amount;
    printf("The new balance is: %.2lf \n", bank[account-901][0]);
}
/*
withdraw money from account
*/
void withdrawal(){
    printf("Please enter account number: ");
    scanf("%d", &account);
    int accountStatus = checkAccount(account);
    if(accountStatus!=0){
        printf(" %s \n", errorMessage[accountStatus]);
        return;
    }

    printf("Please enter the amount to withdraw");
    scanf("%lf", &amount);
    
    amountStatus = checkAmount(amount);
    if(amountStatus!=0){
        printf(" %s \n", errorMessage[amountStatus]);
        return;
    }
    

    bank[account-901][0] -= amount;
    printf("The new balance is: %.2lf \n", bank[account-901][0]);
}

/*
close an account
*/
void closeAccount(){
    printf("Please enter account number: ");
    scanf("%d", &account);
    int accountStatus = checkAccount(account);
    if(accountStatus != 0){
        printf(" %s \n", errorMessage[accountStatus]);
        return;
    }
    
    bank[account-901][1] = 1;     
    printf("Closed account number %d \n", account);
}

/*
set new interest to all acounts
*/
void setInterest(){

    printf("Please enter interest rate: ");
    scanf("%lf", &interest);
    if(interest<0){
        printf(" %s \n", errorMessage[5]);
        return;    
    }
    
    int curr=0, iAccount=0;
    interest = (interest/100) + 1;
    
    while(iAccount<accountNum){
        if(bank[curr][1]!=1){
            bank[curr][0]*= interest;
            iAccount++;
        }
        curr++;
    }
    
           
}//amount+=(interest*amount/100 )  

void print(){
    if(accountNum<0){
        return;
    }
    
    int iAccount=0;
    while(iAccount<accountNum){
        if(bank[iAccount][1]!=1){
            printf("The balance of account number %d is: %.2lf \n\n" , iAccount+901 , bank[iAccount][0]);
        }
        iAccount++;
    }
}