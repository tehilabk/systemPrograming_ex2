//TODO cheack if <stdio.h nedeed
//TODO define

int bank [50][2];//inner array(amount, status)
int deleted [50];

char errorMessage[4][40] = {
    "Failed to read the account number",
    "This account is closed",
    "Cannot deposit a negative amount",
    "Cannot add another acount. you have reached the max amount allowed"
};

int accountStatus;
int amountStatus;
int deletedNum=-1;
static int accountNum = 0;
int amount;
int account;


void openAcount(){
    printf("please enter amount for deposit:");
    scanf("%d", amount);
    
    if(accountNum>50){
        printf(" %s \t", errorMessage[4]);
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


void getBalance(){
    printf("Please enter account number:");
    scanf("%d", account);
    accountStatus = checkAccount(account); 
    if(accountStatus!=0){
        printf(" %s \t", errorMessage[accountStatus]);
        return;
    }
    
    printf("The balance of account number %d is: %d\n" , account , bank[account-900]);
}

void deposit(){
    printf("Please enter account number:");
    scanf("%d", account);
    accountStatus = checkAccount(account); 
    if(accountStatus!=0){
        printf(" %s \t", errorMessage[accountStatus]);
        return;
    }

    printf("Please enter the amount to deposit:");
    scanf("%d", amount);
    amountStatus = checkAmount(amount);
    if(amountStatus!=0){
        printf(" %s \t", errorMessage[amountStatus]);
    }

    bank[account-900][0] += amount;
    printf("The new balance is: %d\n", bank[account-900]);
}

void withdrawal(){
    printf("Please enter account number:");
    scanf("%d", account);
    int accountStatus = checkAccount(account);
    if(accountStatus!=0){
        printf(" %s \t", errorMessage[accountStatus]);
        return;
    }

    printf("Please enter the amount to withdraw");
    scanf("%d", amount);
    
    amountStatus = checkAmount(amount);
    if(amountStatus!=0){
        printf(" %s \t", errorMessage[amountStatus]);
    }
    

    bank[account-900][0] -= amount;
    printf("The new balance is: %d\n", bank[account-900]);
}

void closeAccount(int account){
    int accountStatus = checkAccount(account); 
    if(accountStatus == 2){
        printf("this accpunt is already closed");
    }

    if(accountStatus==1){
        printf(" %s \t", errorMessage[accountStatus]);
        return;
    }
    
    bank[account-900]== -1;
    prinf("closed account number %d\n", account);
}

/*
   returns  0 => legal amount
            3 => negative amount 
*/
int checkAmount(int amount){
    if(amount<0){
        return 3;
    }
    return 0;
}

/*
   returns  0 => legal key
            1 => accountKey is out of bound 
            2 => account closed
*/
int checkAccount(int accountKey){
    if (accountKey<901 || accountKey>950 || accountKey >= accountNum){
        return 1;
    }

    if(bank[accountKey-900] == -1){
        return 2;
    }
    
    return 0;
}