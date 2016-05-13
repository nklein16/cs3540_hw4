#include "bank_account.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define ACCT_LENGTH 13

int balance;

int is_all_digits(char* b)
{
   int result = 0;
   if(b != NULL)
   {
      int i = 0;
      while(i < strlen(b) && isdigit(b[i]))
         i++;
      result = i == strlen(b);
   }
   return result;
}

char* create_copy(char* b)
{
   char* cpy = NULL;
   if(b != NULL)
   {
      cpy = malloc((strlen(b) + 1) * sizeof(char));
      strcpy(cpy, b);
      cpy[strlen(b)] = 0;
   }
   return cpy;
}

bank_account* create_account(char* acct_owner, double init_balance, char* acct_num)
{
   bank_account* b = NULL;
   
   if(acct_owner != NULL && strlen(acct_owner) > 0)
   {
      if(acct_num != NULL && is_all_digits(acct_num))
      {
         if(strlen(acct_num) == ACCT_LENGTH)
         {
            if(init_balance >= 0)
            {
               b =  malloc(sizeof(bank_account));
               b -> owner = create_copy(acct_owner);
               b -> balance = init_balance;
               b -> num = create_copy(acct_num);
            }
            else
            {
               printf("The account balance is less than 0.  Please try again with a balance of zero or greater.\n");
               exit(0);
            }
         }
         else 
         {
             printf("Please be sure the account number is 13 digits in length and try again.\n");
             exit(0);
         }
      }
      else 
      {
         printf("Please be sure your account is valid and that the account number contains only digits and try again.\n");
         exit(0);
      }
   }
   else
   {
      printf("Please be sure the account is valid and that there is an owner's name associated with it and try again.\n");
      exit(0);
   }
   return b;
}

int deposit(bank_account* b, double amount)
{
   if(b != NULL)
   {
      if(amount >= 0)
      {
         balance += amount;
         return balance;
      }
      else return 0;
   }
   else return 0;
}

int withdraw(bank_account* b, double amount)
{
   if(b != NULL)
   {
      if(amount >= 0 && amount <= balance)
      {
         balance -= amount;
         return balance;
      }
      else return 0;
   }
   else return 0;
}

void display_account(bank_account* b)
{
   if(b != NULL)
   {
      printf("The account owner: %s\n", b->owner);
      printf("The account balance: %.2f\n", b->balance);
      printf("The account number:%s\n", b->num);
   }
}

void delete_account(bank_account* b)
{
   if(b != NULL)
   {
      free (b -> owner);
      free (b -> num);
      free (b);
   }
} 
