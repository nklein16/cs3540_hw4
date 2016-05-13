#include "bank_account.h"
#include <stdlib.h>
#include <stdio.h>

int main ()
{
   
   // testing for all possible good and bad data

   // testing with good data 
   bank_account* b = create_account("Ploni Amoni", 250000, "0123456789876");

/* ALL OF THESE WITH BAD DATA "WORK" BY DISPLAYING GUIDING MESSAGES TO THE USER WITHOUT BOMBING OUT THE SYSTEM */
      
   // testing with incorrect account name
   // Running caused Segmentation fault (core dumped)
   // bank_account* b = create_account("", 150000, "0123456789876");

   // testing with incorrect amount
   // error: causes a Segmentation fault (core dumped)
   // bank_account* b = create_account("Bais Hillel", -100, "0123456789876");

   // testing with incorrect account_num length
   // bank_account* b = create_account("Bais Hillel", 150000, "0123456789");
   
   // testing with incorrect account_num chars instead of ints
   //bank_account* b = create_account("Bais Hillel", 250000, "01A3B5C7D9E7F");


/* MUST HANDLE EACH OF THESE CASES THAT BOMBED OUT!!! */

   // testing with incorrect number of parameters
   // bank_account* b = create_account("Bais Hillel", 0123456789876);
   
   // error:  with "badamount": incompatible type for argument 2 of âcreate_accountâ
   // bank_account.h:20: note: expected âdoubleâ but argument is of type âchar *â

   // bank_account* b = create_account("Bais Hillel", "badamount", "0123456789876");

   // error with badamount:  âbadamountâ undeclared (first use in this function)

   //bank_account* b = create_account("Bais Hillel", badamount, "0123456789876");


   if(b == NULL)
   {
      printf("Invalid account");   
   }
   
   if(b->balance < 0)            
   {
      printf("Invalid account");
   }
     
   else
   {
      display_account(b);
      delete_account(b);
   }
   
   return 0;
}
