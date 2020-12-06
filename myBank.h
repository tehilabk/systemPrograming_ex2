#ifndef MYBANK_H
#define MYBANK_H

void openAcount();
void getBalance();
void deposit();
void withdrawal();
void closeAccount();
void setInterest();
void print();

void initializeArray();
int checkAmount(double amount);
int checkAccount(int account);
int checkInterest(double interest);

#endif //MYBANK_H
