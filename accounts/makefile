#makefiles

all: accounts

accounts: account.o transaction.o main.o

# deps compile to make .o objects
		# if any of deps changed
account.o: Account.cpp Account.h Transaction.h
		# re-compile this source
	clang++ -std=c++14 Account.cpp

transaction.o: Transaction.cpp Transaction.h
	clang++ -std=c++14 Transaction.cpp

main.o: main.cpp Account.h
	clang++ -std=c++14 main.cpp
