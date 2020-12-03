#include <stdio.h>
//TODO define
//TODO .2 to all printf
int i;
double bank [50][2] = {0};//inner array(amount, status) => status = 1 for closed and 0 for open

char errorMessage[11][100] = {//errors array
    "",
    "Failed to read the account number\n",             //1
    "This account is closed\n",                        //2
    "Invalid Amount\n",                                //3
    "Invalid account number\n",                        //4
    "Invalid interest rate\n",                         //5
    "Faild. you have reached the max amount allowed\n",//6
    "Failed to read the interest rate\n",              //7
    "Failed to read the amount\n",                     //8
    "Cannot deposit a negative amount\n",              //9
    "This account is already closed\n"                 //10
}; 

int accountStatus, amountStatus, interestStatus, accountNum = 0, account;
double interest, amount;

void initializeArray(){
    while(i<50){
        bank[i][1]=1;
        i++;
    }
}

int checkInterest(double interest){

    if(interest<0){
        return 5;
    }
    if(interest == 0){
        return 7;
    }
    return 0;
}

/*
   returns  0 => legal amount
            3 => negative amount 
*/
int checkAmount(double amount){

    if(amount<0){
        return 3;
    }
    if(amount == 0){
        return 8;
    }
    return 0;
}

/*
   returns  0 => legal account number
            1 => account number is out of bound 
            2 => account closed
            4 => negative account number
*/
int checkAccount(int account){
    
    if(account<0){
        return 4;
    } else if (account<901 || account>950){
        return 1;
    }

    if(bank[account-901][1] == 1){
        return 2;
    }
    return 0;
}


/*
open a new account
*/
void openAcount(){
    printf("Please enter amount for deposit: ");
    amount=0;
    scanf("%lf", &amount);
    fflush(stdin);
    
    amountStatus = checkAmount(amount);
    if(amountStatus != 0){
        printf("%s \n", errorMessage[amountStatus]);
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
                printf("%s \n", errorMessage[7]);
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
    bank[accountNum][1]= 0;
    printf ("New account number is: %d \n\n" , accountNum+901);
    accountNum++;
        
}


/*
get balance of account
*/
void getBalance(){
    printf("Please enter account number:");
    account=0;
    scanf("%d", &account);
    accountStatus = checkAccount(account); 
    if(accountStatus != 0){
        printf("%s \n", errorMessage[accountStatus]);
        return;
    }
    
    printf(" The balance of account number %d is: %.2lf\n\n" , account , bank[account-901][0]);
}

/*
deposit money in account
*/
void deposit(){
    printf("Please enter account number:");
    account=0;
    scanf("%d", &account);
    accountStatus = checkAccount(account);

    if(accountStatus == 1){accountStatus = 4;}//fix error message to this spesific method
    if(accountStatus!=0){
        printf("%s \n", errorMessage[accountStatus]);
        return;
    }

    printf(" Please enter the amount to deposit:");
    amount = 0;
    scanf("%lf", &amount);
    amountStatus = checkAmount(amount);
    if(amountStatus == 3){amountStatus=9;}//fix error message to this spesific method 

    if(amountStatus!=0){
        printf("%s \n", errorMessage[amountStatus]);
        return;
    }

    bank[account-901][0] += amount;
    printf(" The new balance is: %.2lf\n", bank[account-901][0]);
}
/*
withdraw money from account
*/
void withdrawal(){
    printf("Please enter account number: ");
    account = 0;
    scanf("%d", &account);
    int accountStatus = checkAccount(account);
    if(accountStatus!=0){
        printf("%s \n", errorMessage[accountStatus]);
        return;
    }

    printf("Please enter the amount to withdraw:");
    amount=0;
    scanf("%lf", &amount);
    
    amountStatus = checkAmount(amount);
    if(amountStatus!=0 && amountStatus!=3){
        printf("%s \n", errorMessage[amountStatus]);
        return;
    }

    bank[account-901][0] -= amount;
    printf("The new balance is: %.2lf\n", bank[account-901][0]);
}

/*
close an account
*/
void closeAccount(){
    printf("Please enter account number: ");
    account=0;
    scanf("%d", &account);
    int accountStatus = checkAccount(account);
    if(accountStatus == 2){ //fix error message to this spesific method
        accountStatus = 10;
    }
    if(accountStatus != 0){
        printf("%s \n", errorMessage[accountStatus]);
        return;
    }
    
    bank[account-901][1] = 1;     
    printf("Closed account number %d\n", account);
}

/*
set new interest to all acounts
*/
void setInterest(){

    printf("Please enter interest rate: ");
    interest=0;
    scanf("%lf", &interest);
    
    interestStatus = checkInterest(interest);
    if(interestStatus!=0){
        printf("%s \n", errorMessage[interestStatus]);
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
