// Bank Account Makefile.c

// makes the bank_account.o file
bank_account.o: bank_account.c bank_account.h
   gcc -g -c bank_account.c
   
// makes the test_back_account.o file
test_bank_account.o: test_bank_account.c bank_account.h
   gcc -g -c test_bank_account.c

// makes the bank_account.exe file using the two .0 files we just made
test_bank_account.exe: bank_account.o test_bank_account.o
   gcc -o test_bank_account.exe bank_account.o test_bank_account.o
   