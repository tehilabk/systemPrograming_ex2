//TODO cheack if <stdio.h nedeed
//TODO define

double bank [50][2] = {0};//inner array(amount, status) => status = 1 for closed and 0 for open
int deleted [50];

char errorMessage[5][100] = {//
    "",
    "Failed to read the account number \n",
    "This account is closed \n",
    "Invalid Amount \n",
    "Failed to read the amount \n",
    "Cannot add another acount. you have reached the max amount allowed \n"
};

int accountStatus, amountStatus, deletedNum=-1, accountNum = 0, account;
double interest, amount;

/*
open a new account
*/
void openAcount(){
    printf("please enter amount for deposit:");
    scanf("%d", &amount);
    
    if(accountNum>50){
        printf(" %s \t", errorMessage[5]);
        return;
    }

    amountStatus = checkAmount(amount);
    if(amountStatus == 1){
        printf(" %s \t", errorMessage[accountStatus]);
        return;
    }
            
    if(deletedNum>-1){
        bank[deleted[deletedNum]][0]=amount;
        deletedNum--;
        deleted[deletedNum+1];
        accountNum++;
        printf ("New account number is: %d\n" , accountNum+900);
    }else{   
        bank[accountNum][0] = amount;
        accountNum++;
        printf ("New account number is: %d\n" , accountNum+900);
    }
}

/*
get balance of account
*/
void getBalance(){
    printf("Please enter account number:");
    scanf("%d", &account);
    accountStatus = checkAccount(account); 
    if(accountStatus != 0){
        printf(" %s \t", errorMessage[accountStatus]);
        return;
    }
    
    printf("The balance of account number %d is: %d\n" , account , bank[account-901][0]);
}

/*
deposit money in account
*/
void deposit(){
    printf("Please enter account number:");
    scanf("%d", &account);
    accountStatus = checkAccount(account); 
    if(accountStatus!=0){
        printf(" %s \t", errorMessage[accountStatus]);
        return;
    }

    printf("Please enter the amount to deposit:");
    scanf("%d", &amount);
    amountStatus = checkAmount(amount);
    if(amountStatus!=0){
        printf(" %s \t", errorMessage[amountStatus]);
    }

    bank[account-900][0] += amount;
    printf("The new balance is: %d\n", bank[account-900]);
}
/*
withdraw money from account
*/
void withdrawal(){
    printf("Please enter account number: ");
    scanf("%d", &account);
    int accountStatus = checkAccount(account);
    if(accountStatus!=0){
        printf(" %s \t", errorMessage[accountStatus]);
        return;
    }

    printf("Please enter the amount to withdraw");
    scanf("%d", &amount);
    
    amountStatus = checkAmount(amount);
    if(amountStatus!=0){
        printf(" %s \t", errorMessage[amountStatus]);
        return;
    }
    

    bank[account-900][0] -= amount;
    printf("The new balance is: %d \n", bank[account-900]);
}

/*
close an account
*/
void closeAccount(){
    printf("Please enter account number: ");
    scanf("%d", &account);
    int accountStatus = checkAccount(account);
    if(accountStatus != 0){
        printf(" %s \t", errorMessage[accountStatus]);
        return;
    }
    
    bank[account-900][1] = 1;
    deletedNum++;
    deleted[deletedNum] = account;
    
    printf("Closed account number %d \n", account);
}

/*
set new interest to all acounts
*/
setInterest(){

    printf("Please enter interest rate: ");
    scanf("%lf", &interest);
    if(interest<0){
        printf(" %s \t", errorMessage[5]);
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
    
    
}//amount+=(interest*amount/100)

void print(){
    if(accountNum<0){
        return;
    }
    
    int curr=0, iAccount=0;
    while(iAccount<accountNum){
        if(bank[curr][1]!=1){
            printf("The balance of account number %d is: %d\n" , iAccount+900 , bank[iAccount][0]);
            iAccount++;
        }
        curr++;
    }
}

/*
   returns  0 => legal amount
            3 => negative amount 
*/
int checkAmount(int amount){

    if(amount<0){
        return 3;
    }
    if(!isdigit(amount)){
        return 4;
    }
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

    if(bank[accountKey-900][1] == 1){
        return 2;
    }
    return 0;
}
