//////////////////////////////////////////////////////////////////
// Library Management Program                                   //
// Program: Library Management                                  //
// Candidate's Name: Jenalyn Weekes					            //
// Candidate's Number:                                          //
// School: Montserrat Community College                         //
// Class: Computer Science Unit 1					            //
// Territory: Montserrat                                 	    //
// Lecturer:  Miss Donna Ible-White                             //
//                                                              //
// Project: Internal Assessment (IA)                            //
// This program serves to manage books in a library system.     //
//////////////////////////////////////////////////////////////////


#include<stdio.h>
#include <time.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXINPUT 100


void Menu();
void BorrowBookLog();
int Display();
int numbks, cnt, counter=0;
int choice;
char password[10], username[15];
int cat;
int num, i=0;
char bk[][20]= {"Mathematics", "English", "Fiction", "Non-Fiction"};
char s[15];
FILE *fp;
FILE *ptr;
struct books //declares struct book with variables Bookname, Bookauthor,BookID, *cat and Status
{
    char Bookname[20];
    char Bookauthor[20];
    int BookID;
    char *cat;
};
struct books a;


void Password()//This function allows users to login to the library management system.
{
    struct user //creates struct 'user'
    {
        char UserNames[15];
        char Pass[10];
    };
     struct user user1={ //creates intance of struct 'user1'
            "Jane",
            "passworda"
            };
        struct user user2={
            "John",
            "passwordb"
            };
        struct user user3={
            "James",
            "passwordc"
            };

    for(cnt=1; cnt<=3; cnt++)
    {
        printf("Welcome... \n\nPlease enter your user name:"); //prompts user for user name
        scanf("%s", username); //reads username
        printf("Please enter your password:");//prompts user for password
        scanf("%s", password); //reads password


        if (strcmp(username, user1.UserNames) == 0 && strcmp(password, user1.Pass) == 0) //checks whether the username and password match that of struct user1
            cnt = 5; //cnt assigned value 5 to leave loop
        else if (strcmp(username, user2.UserNames) == 0 && strcmp(password, user2.Pass) == 0)//checks whether the username and password match that of struct user2
            cnt = 5; //cnt assigned value 5 to leave loop
        else if (strcmp(username, user3.UserNames) == 0 && strcmp(password, user3.Pass) == 0)//checks whether the username and password match that of struct user3
            cnt = 5; //cnt assigned value 5 to leave loop
        else //if password and username are not a match user is prompted to try again
            printf("\nAccess Denied.\nTry Again\n");
            system("pause");
            system("cls");

    }
    if (cnt==3){
        Quit();
    }
    else{
        Menu();
    }
    system("cls");
}


void AddBook()//This function allows user to add books to the library
{
    int c;

        printf("How many books would you like to add? ");
         while (scanf("%d", &numbks) != 1) //loops while the value entered for 'numbks' is not an integer
        {
            while (!isspace(c = getchar())); //loops while the value for c is not a blank space
            {
                system("cls");
                printf("You must enter an integer.");
                printf("\nHow many books would you like to add? ");
            }
    }
    printf("\nADDING %d BOOK(S)\n", numbks);

    do
    {
        int c;

        printf("Select a category: \n1.Mathematics \n2.English \n3.Fiction \n4.Non-Fiction \n5.Return To Main Menu"); //prompts user to choose a category
        while (scanf("%d", &cat) != 1) //loops while the value entered for 'cat' is not an integer
        {
            while (!isspace(c = getchar()));//loops while the value for c is not a blank space
        {
                system("cls");
                printf("You must enter an integer.\n");
                printf("Select a category: \n1.Mathematics \n2.English \n3.Fiction \n4.Non-Fiction \n5.Return To Main Menu");
        }
        }
        if(cat==5) //checks whether user would like to return to the menu
        {
            system("cls");
            Menu() ;
        }
        fflush(stdin);
        system("cls");

        fp=fopen("Library.bks.txt","a+"); //opens file "Library.txt" to be appended
        a.cat=bk[cat-1];

        printf("Enter the Information Below.\n");
        printf("Category: ");
        printf("%s",bk[cat-1]);


        printf("\nBook ID: ");
        while (scanf("%d", &num) != 1) //loops while the value entered for 'num' is not an integer
        {
            while (!isspace(c = getchar()));
            {
                system("cls");
                 printf("You must enter an integer.\nBook ID: ");
            }
        }
        fflush(stdin);
        a.BookID=num;;

        printf("Book Name:");
        scanf("%s", &a.Bookname);
        fflush(stdin);

        printf("Book Author:");
        scanf("%s", &a.Bookauthor);
        fflush(stdin);

        fprintf(fp, "Category:%s. Book ID:%d. Book Name:%s Book Author:%s \n", bk[cat-1], a.BookID, a.Bookname, a.Bookauthor);//adds book information to file

        fclose(fp);
        system("cls");

        printf("BOOK SUCCESSFULLY ADDED\n");
        counter++;
    }
    while(counter!=numbks);//loops through once the counter is not equal to the number of books the person wants to add
    Menu();
}

void Menu()//This function directs users to a menu with options to choose from
{
        int c;

        do
        {
        printf("Library Main Menu \n");
        printf("Add New Book..........1\n");
        printf("Borrow Book...........2\n");
        printf("Display Books.........3\n");
        printf("Exit..................4\n");
        while (scanf("%d", &choice) != 1) //loops while the value entered for 'choice' is not an integer
        {
            while (!isspace(c = getchar()));//loops while the value for c is not a blank space
            {
                system("cls");
                printf("You must enter an integer.\n\n");
                printf("Library Main Menu \n");
                printf("Add Books..........1\n");
                printf("Borrow Books...........2\n");
                printf("Display Books.........3\n");
                printf("Exit..................4\n");
            }
        }

            switch(choice)
            {
                case 1://if choice is 1 takes user to AddBooks function
                {
                    system("cls");
                    AddBook();
                    break;
                }
                case 2://if choice is 2 takes user to BorrowBookLog function
                {
                    system("cls");
                    BorrowBookLog();
                    break;
                }
                case 3://if choice is 3 takes user to Display function
                {
                    system("cls");
                    Display();
                    system("pause");
                    system("cls");
                    Menu();
                    break;
                }
                case 4://if choice is 4 takes user to Quit function
                {
                    system("cls");
                    Quit();
                    break;
                }
                default://if choice is not 1,2,3 or 4 the following is carried out
                    system("cls");
                    printf("Something went wrong, please try again.\n");
            }
        }
        while(choice > 5|| choice < 1); // performs do while choice is less than or equal to 5
 }

int Quit()//This function exits the program
{
    printf("\n\n\t***********************Have a nice day!***********************\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    exit (0);
    system("cls");

}

int Display()//This function displays books in library
{

    char c = fseek(fp, 0, SEEK_SET); //assigns the variable c to the first character of the file
    char eof = fseek(fp, sizeof("library.bks.txt"), SEEK_END);
    fp = fopen("library.bks.txt","r"); //opens file "Library.txt" to be read
    if(fp == NULL) //if the file pointer is not returned, the user is informed that the file does not exist
    {
        printf("Error! File does not exist.\n");
        system("pause");
        system("cls");

    }
    else //prints contents of file
        while(1)
        {
            c = fgetc(fp);
            if(feof(fp))
            {
                return 0;
                break;
            }
            printf("%c", c);

            fflush(stdout);

        }
    fclose(fp);
    return 0;
}

void BorrowBookLog()//This function tracks books borrowed by customers
{
    int numofbks, loopcounter;
    char category[30];
    int c;
    printf("How many books would you like to borrow?");
    while (scanf("%d", &numofbks) != 1) //loops while the value entered for 'num' is not an integer
        {
            while (!isspace(c = getchar()));
            {
                system("cls");
                printf("You must enter an integer.\nHow many books would you like to borrow?\n");
            }
        }

    printf("\nBORROWING %d BOOK(S)\n", numofbks);
    for(loopcounter=0; loopcounter<numofbks; loopcounter++)
    {
        printf("Books available: \n\n");
        Display();
        int c;
        ptr=fopen("Library.borrowedbks.txt","a+"); //opens file "borrowedbks.txt" to be appended
        a.cat=bk[cat-1];

        printf("\n\nPlease enter information for the book you would like to borrow .\n");
        printf("\nCategory: ");
        scanf("%s", &category);

        printf("Book ID: ");
        while (scanf("%d", &num) != 1) //loops while the value entered for 'num' is not an integer
        {
            while (!isspace(c = getchar()));
            {
                system("cls");
                printf("You must enter an integer.\nBook ID: ");
            }
        }
        fflush(stdin);
        a.BookID=num;;

        printf("Book Name:");
        scanf("%s", &a.Bookname);
        fflush(stdin);

        printf("Book Author:");
        scanf("%s", &a.Bookauthor);
        fflush(stdin);

        //Gets the values for the  current date
        struct tm *tm;
        time_t t;
        char date[100];

        t = time(NULL);
        tm = localtime(&t);

        strftime(date, sizeof(date), "%d/%m/%Y", tm);
        printf("%s",date);

        fprintf(ptr, "Category:%s. Book ID:%d. Book Name:%s Book Author:%s Date:%s\n", category, a.BookID, a.Bookname, a.Bookauthor, date);//adds book information to file

        printf("\nBOOK SUCCESSFULLY BORROWED\n");
        fclose(ptr);

        system("pause");
        system("cls");
    }
    Menu ();
}

int main()
{
    Password();
    return 0;
}
