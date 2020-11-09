#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>
#include <stdlib.h>
#include <process.h>

typedef struct BankClerks //Declaring a structure called Bank Clerks
{
    char password[10], username[15];
}clerks;

typedef struct Customers //Delcaring a structure called Customers
{
    char name[50],address[50],email[20],phonenum[20];
    int accountnum;
    float balance;
}custs;

//Declaring files to be used
FILE *Balance;
FILE *BankTotal;
FILE *CustomerFile;
FILE *CustomerDatabase;

float balance,bankamount, customeramount;
char filename1[20],filename2[20],date[100];

int main()
{
    int login;
    BankClerksInfo();
    login = BankClerkLogin();
    if (login == 1)
    {
        system("pause");
        system("cls");
	    Menu();
    }
    else //If they fail to log in then the program will close
		printf("The program is now exiting as you failed to login and have run out of attempts.");
		return(0);
}

int BankClerksInfo() //This function holds all the login information for the bank clerks.
{
    //Declaration of file and variables
    FILE *BankClerksFile;
    clerks bankclerks[3];
    int count;

    //Initializes the members of the array bank clerks
    strcpy(bankclerks[0].username, "JWeekes");
    strcpy(bankclerks[0].password, "passworda");

    strcpy(bankclerks[1].username, "DQueeley");
    strcpy(bankclerks[1].password, "passwordb");

    strcpy(bankclerks[2].username, "MRoss");
    strcpy(bankclerks[2].password, "passwordc");

    //Creates the file BankClerks.txt which will be used to store bank clerks information
    BankClerksFile = fopen("BankClerks.txt", "w");

    //Checks to see if the file exists
    if (BankClerksFile != NULL)
    {
        //Writes the values of the array lecturers to the BankClerks.txt file
        for(count=0; count<3; ++count)
        {
            fprintf(BankClerksFile, "%s %s\n", bankclerks[count].username,bankclerks[count].password);
        };
    fclose(BankClerksFile);
    }
    else
        //Output this line if the BankClerks.txt file cannot be found
        printf("\nThe file BankClerks.txt cannot be found.");
        return (0);
}

int BankClerkLogin()//This function allows the bank clerks to log into the program.
{
    //Declaration of file and variables
    FILE *BankClerksFile;
    char login_name[20], login_password[20];
    int attempts,i,x,j;
    clerks bankclerks[3];


    //Displaying LOGIN with asterisks around it
    char login[20]="\tLOGIN";
    printf("\t\t");
    for(j=0;j<20;j++)
    {
        Sleep(20);
        printf("*");
    }
    printf("   \n \t \t  ");
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("%c",login[j]);
    }
    printf("\n \t \t");
    for(j=0;j<20;j++)
    {
        Sleep(20);
        printf("*");
    }

    BankClerksFile = fopen("BankClerks.txt", "r");

    //This loop runs three times as the user will have three chances to login
    for (attempts=0; attempts<3; ++attempts)
    {
        //Prompt the user to enter their login information
        printf("\nPlease enter your username and password: ");
        printf("\nUsername: ");
        gets(login_name);
        printf("Password: ");
        gets(login_password);

        //Reads the file to get the bank clerks info and compares them to the values entered.
        for(i=0; i<3; ++i)
        {
            fscanf (BankClerksFile, "%s %s\n", bankclerks[i].username, bankclerks[i].password);

            //Compares the login name and password to the lecturers info from the file
            if ((strcmp(bankclerks[i].username, login_name)== 0) && (strcmp(bankclerks[i].password, login_password)==0))
            {
                printf("You have successfully logged in, %s.\n",bankclerks[i].username);
                fclose(BankClerksFile);
                return 1;
            };
        };

    //If an incorrect login name or login password is entered this would be executed, then the user's chances will decrease
    puts("\nYou have entered an incorrect username and password combination.");

    //Checking to see if the user has used all 3 attempts and displaying attempts remaining
    if (attempts == 3)
        {
            fclose(BankClerksFile);
            return(2);
        }
    else
        x = 2-attempts;
        printf("You now have %d attempt(s) remaining.\n",x);
        system("pause");
        system("cls");
        fflush(stdin);
    };
}

int Menu() //This function has a list of options for the bank clerks to choose from depending on what the customer wants to do.
{
    int option;
    do
    {
        //Displaying SPCCU MENU with asterisks around it
        char d[20]="  SPCCU MENU ";
        int i=0,j;
        printf("\t\t");
        for(j=0;j<20;j++)
        {
        Sleep(50);
        printf("*");
        }
        printf("   \n \t \t  ");
        for(j=0;j<20;j++)
        {
        Sleep(50);
        printf("%c",d[j]);
        }
        printf("\n \t \t");
        for(j=0;j<20;j++)
        {
        Sleep(50);
        printf("*");
        }

        //Displays the various options and determines which one the user wants to do
        puts("\nPlease select an option from below. . .");
        puts("(1) Account Creation/Closure/Updating");
        puts("(2) Transactions");
		puts("(3) Loan Process");
        puts("(4) View Customer File");
        puts("(5) Logout");
		printf("Option: ");
        scanf("%d",&option);
        fflush(stdin); //Clears the input stream for command prompt to prevent spaces and other text to be carried on to a next function

        //Checks to ensure if the value the user entered is in the range of 1 and 5
        if (option<1 || option>5)
            {
                printf("Invalid option, your option must be either 1,2,3,4 or 5.\n");
                ClearScreenMenu();
            }
        else

        //Using switch-case function to determine what function to call based on the user's entered option
        switch(option)
        {
            case 1:
                system("cls");
                AccountManagement();
                break;
            case 2:
                system("cls");
                Transactions();
                break;
            case 3:
                system("cls");
                Loans();
                break;
            case 4:
                system("cls");
                ViewFile();
                break;
            case 5:
                system("cls");
                main();
                break;
        }scanf;
    }
    while(option<1 || option>5);//This loop will continue running until the user inputs a number in the range of 1 and 5
}

int Transactions() //This functions allows the user to process withdraws and deposits.
{
    custs customer;
    float deposit, withdraw;
    int choice, choice2, accountnum[1000], i=0, count=0;

    //Getting the values for the  current date
    struct tm *tm;
    time_t v;
    v = time(NULL);
    tm = localtime(&v);
    strftime(date, sizeof(date), "%d/%m/%Y", tm);

    char t[20]=" TRANSACTIONS ";
    int j;
    printf("\t\t");
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }
    printf("   \n \t \t  ");
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("%c",t[j]);
    }
    printf("\n \t \t");
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }


    printf("\nPlease enter your bank account number: ");
    scanf("%d",&customer.accountnum);
    CustomerDatabase = fopen("BankCustomers.txt","r");

    //Reads the customer account numbers from the file into an array accountnum
    while(!feof(CustomerDatabase))
    {
        fscanf(CustomerDatabase,"%d\n",&accountnum[i]);
        count++;
        i++;
    }


    //Searches through the array to find entered account number
    for(i=0;i<count;i++)
    {
        if(customer.accountnum == accountnum[i])
        {
            printf("Account number is found in database\n");
            break;
        }
        else
        {
            if(i==(count-1))
            {
                printf("Account number not found in database. . .");
                ClearScreenMenu();
            }
        }
    }

    //Checking to see whether the file exists
    sprintf(filename1,"%d.txt",customer.accountnum);
    sprintf(filename2,"%d Balance.txt",customer.accountnum);

    if ((CustomerFile = fopen(filename1,"r")) && (Balance = fopen(filename2,"r")) == NULL)
    {
        printf("Account file cannot be found or the account is closed. . .");
        ClearScreenMenu();
    }
    else
    {
        puts("Please select an option from below: ");
        puts("(1) Deposit");
        puts("(2) Withdraw");
        printf("Option: ");
        scanf("%d",&choice);
        fflush(stdin);

        if (choice<1 || choice>2)//condition ensuring choice input is valid
        {
            printf("Invalid option, your option must be either 1 or 2.\n");
            ClearScreenMenu();
        }
        else

        //Using switch function to determine what action to do based on what the user entered
        switch(choice)
        {
            case 1:
                printf("Enter amount to deposited: ");//not done
                scanf("%f",&deposit);

                Balance = fopen(filename2,"r");//opens file
                BankTotal = fopen("BankTotal.txt","r");//opens file
                CustomerFile = fopen(filename1,"a");//opens file

                fscanf(Balance,"%f",&customer.balance);//scans file
                fscanf(BankTotal,"%f",&bankamount);//scans file

                fprintf(CustomerFile,"\n\n****Customer Transactions****\n%s Balance is: $%.2f \n",date,customer.balance);

                customer.balance = customer.balance + deposit;
                bankamount = bankamount + deposit;

                Balance = fopen(filename2,"w");
                BankTotal = fopen("BankTotal.txt","w");


                //Updating the customers balance and the bank total
                fprintf(CustomerFile,"%s Deposited: $%.2f \n",date,deposit);
                fprintf(CustomerFile,"%s New Balance is: $%.2f \n",date,customer.balance);
                fprintf(Balance,"%.2f",customer.balance);
                fprintf(BankTotal,"%.2f",bankamount);

                fclose(CustomerFile);
                fclose(Balance);
                fclose(BankTotal);

                printf("New Balance is: $%.2f", customer.balance);
                ClearScreenMenu();

           case 2:
                printf("Enter amount to be withdrawn: ");
                scanf("%f",&withdraw);

                Balance = fopen(filename2,"r");
                BankTotal = fopen("BankTotal.txt","r");
                CustomerFile = fopen(filename1,"a");

                fscanf(Balance,"%f",&customer.balance);
                fscanf(BankTotal,"%f",&bankamount);

                fprintf(CustomerFile,"\n\n****Customer Transactions****\n%s Balance is: $%.2f \n",date,customer.balance);

                customer.balance = customer.balance - withdraw;
                bankamount = bankamount - withdraw;

                printf("Amount Withdrawn: %.2f \nNew Balance is: %.2f\n\n", withdraw, customer.balance);

                system("pause");

                Balance = fopen(filename2,"w");
                BankTotal = fopen("BankTotal.txt","w");

                //Updating the customers balance and the bank total
                fprintf(CustomerFile,"%s Withdrawn: $%.2f \n",date,withdraw);
                fprintf(CustomerFile,"%s New Balance is: $%.2f \n",date,customer.balance);

                fprintf(Balance,"%.2f",customer.balance);
                fprintf(BankTotal,"%.2f",bankamount);

                fclose(CustomerFile);
                fclose(Balance);
                fclose(BankTotal);
                ClearScreenMenu();
        }
            while(choice<1 || choice>2);
    }
    return 0;
}

int AccountManagement()//This function creates,closes and update customer files.
{
    custs customer;
    char amount[100000];
    int option, enter = 0, i;

    char d[30]="ACCOUNT MANAGEMENT";
    int j;
    printf("\t\t");
    for(j=0;j<22;j++)
    {
        Sleep(50);
        printf("*");
    }
    printf("   \n \t \t  ");
    for(j=0;j<22;j++)
    {
        Sleep(50);
        printf("%c",d[j]);
    }
    printf("\n \t \t");
    for(j=0;j<22;j++)
    {
        Sleep(50);
        printf("*");
    }

    //Getting the values for the current date
    struct tm *tm;
    time_t v;
    v = time(NULL);
    tm = localtime(&v);
    strftime(date, sizeof(date), "%d/%m/%Y", tm);


    //Prompting the user for their option
    puts("\nPlease select an option from below. . .");
    puts("(1) Account Creation");
    puts("(2) Account Closure");
    puts("(3) Account Updating");
    printf("Option: ");
    scanf("%d",&option);
    fflush(stdin); //Clears the input stream for CMD

    //Checks to ensure if the value the user entered is in the range of 1 and 3
    if (option<1 || option>3)
        {
            puts("Invalid option, your option must be either 1,2 or 3. . .");
            ClearScreenMenu();
        }

    switch(option)
    {
        case 1:

            //Getting information about the customer so that an account can be created for them
            system("cls");
            puts("ACCOUNT CREATION");
            puts("Please enter the following information. . .");
            printf("Full Name: ");
            gets(customer.name);
            printf("Address: ");
            gets(customer.address);
            printf("Email Address: ");
            gets(customer.email);
            fflush(stdin);
            printf("Telephone Number: ");
            gets(customer.phonenum);
            printf("Starting Amount: ");
            gets(amount);

            //Checking to see if the starting amount only contains numbers and that it is in the range of 50 and 1,000,000
            for(i=0;i<strlen(amount);i++)
            {
                if(isdigit(amount[i]) == 0)
                {
                    puts("A customer's starting amount must be between 50 and 1,000,000");
                    ClearScreenMenu();
                }
            };

            customer.balance = atof(amount);
            if (customer.balance>1000000 || customer.balance<50)
            {
                puts("A customer's starting amount must be between 50 and 1,000,000.");
                ClearScreenMenu();
            };

            //Generating a random number for the Customer's bank account number
            srand(time(NULL));
            customer.accountnum = rand();

            //Storing text in a variable to open them as a file
            sprintf(filename1,"%d.txt",customer.accountnum);
            sprintf(filename2,"%d Balance.txt",customer.accountnum);

            //Creating files needed to be used for an account creation
            BankTotal = fopen("BankTotal.txt","r");
            CustomerFile = fopen(filename1,"w");
            Balance = fopen(filename2,"w");

            fscanf(BankTotal,"%f",&bankamount);
            BankTotal = fopen("BankTotal.txt","w");
            bankamount = bankamount + customer.balance;

            CustomerDatabase = fopen("BankCustomers.txt","a");
            fprintf(CustomerDatabase,"%d\n",customer.accountnum);

            fprintf(BankTotal,"%.2f",bankamount);
            fprintf(CustomerFile,"Name: %s\nAccount Number: %d\nAddress: %s\nEmail Address: %s\nTelephone Number: %s",customer.name, customer.accountnum, customer.address, customer.email, customer.phonenum);
            fprintf(Balance,"%.2f",customer.balance);

            fclose(CustomerDatabase);
            fclose(BankTotal);
            fclose(CustomerFile);
            fclose(Balance);

            printf("%s's account number is: %d",customer.name,customer.accountnum);
            printf("\n%s account has been successfully created with starting amount %.2f" ,customer.name, customer.balance);
            ClearScreenMenu();
            break;

        case 2:

            system("cls");
            puts("ACCOUNT CLOSURE");

            printf("Please enter the bank account number to be closed: ");
            scanf("%d",&customer.accountnum);

            sprintf(filename1,"%d.txt",customer.accountnum);
            sprintf(filename2,"%d Balance.txt",customer.accountnum);

            //Checking to see if the account exists
            if ((CustomerFile = fopen(filename1,"r")) && (Balance = fopen (filename2,"r")) == NULL)
            {
                printf("\nThe bank account number you entered cannot be found. . .");
                ClearScreenMenu();
            }
            else
            {
                do
                {
                    //Verifying that the person wants to close the account
                    fflush(stdin);
                    system("cls");
                    printf("Are you sure you want to close this account? \nEnter 1 for Yes and 2 for No.");
                    printf("\nOption: ");
                    scanf("%d", &option);
                }
                while(option < 1 || option >2);
                if(option == 1)
                    {
                        //Subtracting the person's balance from the total bank file and updating it
                        BankTotal = fopen("BankTotal.txt","r");
                        fscanf(Balance,"%f",&customer.balance);
                        fscanf(BankTotal,"%f",&bankamount);
                        bankamount = bankamount - customer.balance;
                        BankTotal = fopen("BankTotal.txt","w");
                        fprintf(BankTotal,"%.2f",bankamount);
                        fprintf(CustomerFile,"\n\n****ACCOUNT CLOSED ON: %s****",date);

                        fclose(CustomerFile);
                        fclose(Balance);
                        fclose(BankTotal);

                        //Deleting the files associated with the entered bank account number
                        unlink(filename1);
                        unlink(filename2);

                        printf("Account number %d has been successfully closed. Balance before closure %.2f. . .",customer.accountnum, customer.balance);
                        ClearScreenMenu();

                    }
                }
                ClearScreenMenu();
            case 3:

                system("cls");
                puts("ACCOUNT UPDATING");

                printf("Please enter bank account number to be updated: ");
                scanf("%d",&customer.accountnum);

                sprintf(filename1,"%d.txt",customer.accountnum);

                //Checking to see if the account exists
                if ((CustomerFile = fopen(filename1,"r")) == NULL)
                {
                    printf("The account number you entered cannot be found or the account does not exist. . .");
                    ClearScreenMenu();
                }
                else

                    fflush(stdin);
                    CustomerFile = fopen(filename1,"a");

                    //Getting the updated information about the customer
                    puts("Please fill the updated versions of the following fields. . .");
                    printf("Name: ");
                    gets(customer.name);
                    printf("Address: ");
                    gets(customer.address);
                    printf("Email address: ");
                    gets(customer.email);
                    printf("Telephone number: ");
                    gets(customer.phonenum);

                    //Updating the file
                    fprintf(CustomerFile,"\n\n****Updated Customer Information****\nDate Updated: %s \nName: %s\nAddress: %s\nEmail Address: %s\nTelephone Number: %s", date ,customer.name, customer.address, customer.email, customer.phonenum);
                    fclose(CustomerFile);

                    puts("Account has been successfully updated");
                    ClearScreenMenu();
    }
}

int ClearScreenMenu()//This function pauses the screen,clears it then returns to the menu.
{
    fflush(stdin);
    puts("\nNow returning to the menu . . .");
    system("pause");
    system("cls");
    Menu();
};

int ViewFile() //This function opens the file of a Customer.
{
    //Declaration of file and variables
    char ans;
    int c;
    custs customer;

    //Displaying CUSTOMER FILE with asterisks around it
    char t[40]=" CUSTOMER FILE ";
    int j;
    printf("\t\t");
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }
    printf("   \n \t \t  ");
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("%c",t[j]);
    }
    printf("\n \t \t");
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }


    //Entering the customers account number
    printf("\nPlease enter the customer's bank account number: ");
    scanf("%d",&customer.accountnum);

    sprintf(filename1,"%d.txt",customer.accountnum); //Assigns the entered customer account number and the .txt file extension into the variable filename

    //Checks to see if the file was successfully opened. If it was not successful then it returns to the menu
    if((CustomerFile = fopen(filename1 , "r")) == NULL)
    {
        printf("Account number cannot be found.");
        ClearScreenMenu();
    };

    //Reads the entire file and outputs it on the screen
    printf("\n");
    while(1)
    {
        c = fgetc(CustomerFile);
        if(feof(CustomerFile))
        {
            break;
        }
        printf("%c",c);
    };
    fclose(CustomerFile);

    //Determines what the user wants to do next
    printf("\n\nPress ENTER if you want to continue viewing customer files\nOr ANY OTHER KEY to return to the menu . . .\n\n\n");
    ans = getch();
    if (ans != 13) //Checks the user's option and determines whether to call the function again or return to the menu
    {
        ClearScreenMenu();
    }
    else
        ViewFile();
}

int Loans()//This function allows customer to take out a loan from the bank.
{
    custs customer;
    int option, accountnum, paymentperiod;
    float salary, loanamount, paymentrate, bankmaximum=21000;
    char date[20];

    system("cls");

    char d[20]="  LOANS PROCESS ";
    int i=0,j;
    printf("\t\t");
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }

    printf("   \n \t \t  ");
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("%c",d[j]);
    }

    printf("\n \t \t");
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }


    printf("\nPlease enter your bank account number\n");
    scanf("%d",&customer.accountnum);
    sprintf(filename1,"%d.txt",customer.accountnum);
    if ((CustomerFile = fopen(filename1,"r")) == NULL)
        {
            printf("Account does not exist\n\n");
            ClearScreenMenu();
        }
    else
    {
        printf("Account exists\n");
        Sleep(2*1000);
        system("cls");
    }

        puts("Enter your monthly salary: $");
        scanf("%f", &salary);
        printf("Please select a loan amount: ");
        printf("\n(1)$5,000 \n(2)$10,000 \n(3)15,000 \n(4)20,000 \n");
        printf("Option: ");
        scanf("%d", &option);
        if (option<1 || option>4)//This check if the users input is erroneous
            {
                system("cls");
                printf("Invalid option, your option must be either 1, 2, 3 or 4.\n"); //Output displayed if input is erroneous

            }
        else

        switch(option)
        {
            case 1://if option is 1
                loanamount= 5000;
                //reads customer name
                if(loanamount>bankmaximum)
                {
                   printf("Loan cannot be given at this time \n");
                   ClearScreenMenu();
                }
                else
                {
                    printf("Enter payment period in months: ");
                    scanf("%d", &paymentperiod);
                    system("cls");

                    paymentrate=(loanamount/paymentperiod);
                    if(paymentrate>(0.4*salary)) //ensures payment rate can be satisfied within payment period selected
                    {
                        printf("You are not eligible to receive a loan...");
                        ClearScreenMenu();
                    }
                    else
                    {
                        printf("\nYou are eligible to receive a loan.");
                        sprintf(filename2,"%d Balance.txt",customer.accountnum);

                        Balance = fopen(filename2,"r");
                        BankTotal = fopen("BankTotal.txt","r");

                        fscanf(Balance,"%f",&customer.balance);
                        fscanf(BankTotal,"%f",&bankamount);

                        customer.balance = customer.balance + loanamount;//adds loan amount to the customer's bank account
                        bankamount = bankamount - loanamount;//subtracts loan amount from the total amount in the bank

                        printf("\nA loan of %.2f was entered into your account. \nYour account balance is now %.2f\n\n", loanamount, customer.balance);

                        Balance = fopen(filename2,"w");
                        BankTotal = fopen("BankTotal.txt","w");

                        fprintf(Balance,"%.2f",customer.balance);
                        fprintf(BankTotal,"%.2f",bankamount);

                        fclose(Balance);
                        fclose(BankTotal);

                    }
                }
                ClearScreenMenu();
                break;
            case 2:
                 loanamount= 10000;
                    //reads customer name
                    if(loanamount>bankmaximum)
                    {
                       printf("Loan cannot be given at this time \n");
                       ClearScreenMenu();
                    }
                    else
                    {
                        printf("Enter payment period in months: ");
                        scanf("%d", &paymentperiod);
                        system("cls");

                        paymentrate=(loanamount/paymentperiod);
                        if(paymentrate>(0.4*salary)) //ensures payment rate an be satisfied within payment period selected
                        {
                            printf("You are not eligible to receive a loan...\n Returning to Menu...");
                            system("pause");
                            Menu();
                        }
                        else
                        {
                            printf("You are eligible to receive a loan.");
                            sprintf(filename2,"%d Balance.txt",customer.accountnum);

                            Balance = fopen(filename2,"r");
                            BankTotal = fopen("BankTotal.txt","r");

                            fscanf(Balance,"%f",&customer.balance);
                            fscanf(BankTotal,"%f",&bankamount);

                            customer.balance = customer.balance + loanamount;//adds loan amount to the customer's bank account
                            bankamount = bankamount - loanamount;//subtracts loan amount from the total amount in the bank

                            printf("\nA loan of %.2f was entered into your account. \nYour account balance is now %.2f\n\n", loanamount, customer.balance);

                            Balance = fopen(filename2,"w");
                            BankTotal = fopen("BankTotal.txt","w");

                            fprintf(Balance,"%.2f",customer.balance);
                            fprintf(BankTotal,"%.2f",bankamount);

                            fclose(Balance);
                            fclose(BankTotal);

                        }
                    }
                    ClearScreenMenu();
                break;
            case 3:
                 loanamount= 15000;
                    //reads customer name
                    if(loanamount>bankmaximum)
                    {
                       printf("Loan cannot be given at this time \n");
                       ClearScreenMenu();
                    }
                    else
                    {
                        printf("Enter payment period in months: ");
                        scanf("%d", &paymentperiod);
                        system("cls");

                        paymentrate=(loanamount/paymentperiod);
                        if(paymentrate>(0.4*salary)) //ensures payment rate an be satisfied within payment period selected
                        {
                            printf("You are not eligible to receive a loan...\n Returning to Menu...");
                            system("pause");
                            Menu();
                        }
                        else
                        {
                            printf("You are eligible to receive a loan.");
                            sprintf(filename2,"%d Balance.txt",customer.accountnum);

                            Balance = fopen(filename2,"r");
                            BankTotal = fopen("BankTotal.txt","r");

                            fscanf(Balance,"%f",&customer.balance);
                            fscanf(BankTotal,"%f",&bankamount);

                            customer.balance = customer.balance + loanamount;//adds loan amount to the customer's bank account
                            bankamount = bankamount - loanamount;//subtracts loan amount from the total amount in the bank

                            printf("\nA loan of %.2f was entered into your account. \nYour account balance is now %.2f\n\n", loanamount, customer.balance);

                            Balance = fopen(filename2,"w");
                            BankTotal = fopen("BankTotal.txt","w");

                            fprintf(Balance,"%.2f",customer.balance);
                            fprintf(BankTotal,"%.2f",bankamount);

                            fclose(Balance);
                            fclose(BankTotal);

                        }
                    }
                    ClearScreenMenu();
                break;
            case 4:
                 loanamount= 20000;
                    //reads customer name
                    if(loanamount>bankmaximum)
                    {
                       printf("Loan cannot be given at this time \n");
                       ClearScreenMenu();
                    }
                    else
                    {
                        printf("Enter payment period in months: ");
                        scanf("%d", &paymentperiod);
                        system("cls");

                        paymentrate=(loanamount/paymentperiod);
                        if(paymentrate>(0.4*salary)) //ensures payment rate an be satisfied within payment period selected
                        {
                            printf("You are not eligible to receive a loan...\n Returning to Menu...");
                            system("pause");
                            Menu();
                        }
                        else
                        {
                            printf("You are eligible to receive a loan.");
                            sprintf(filename2,"%d Balance.txt",customer.accountnum);

                            Balance = fopen(filename2,"r");
                            BankTotal = fopen("BankTotal.txt","r");

                            fscanf(Balance,"%f",&customer.balance);
                            fscanf(BankTotal,"%f",&bankamount);

                            customer.balance = customer.balance + loanamount;//adds loan amount to the customer's bank account
                            bankamount = bankamount - loanamount;//subtracts loan amount from the total amount in the bank

                            printf("\nA loan of %.2f was entered into your account. \nYour account balance is now %.2f\n\n", loanamount, customer.balance);

                            Balance = fopen(filename2,"w");
                            BankTotal = fopen("BankTotal.txt","w");

                            fprintf(Balance,"%.2f",customer.balance);
                            fprintf(BankTotal,"%.2f",bankamount);

                            fclose(Balance);
                            fclose(BankTotal);

                        }
                    }
                    ClearScreenMenu();
                break;
        }
}
