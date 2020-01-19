#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include "Book.h"
#include <fstream>
#include <vector>
#include <algorithm> //Remove spaces

/* TODO: Read in book file to accept. <-- Look at create users, most likely use CSV.

   Password Restritions (Spaces)
*/

size_t CAPACITY = 100;

//Login functions
void createUser(std::fstream & loginsFile);
int loginMenu();
bool loginScreen(std::fstream & loginsFile);

//Menu function
int menu();

//Book functions
bool addBook(Book & acc, std::map<std::string, std::string> & m1, std::fstream & myFile);
void loadBooks(Book & acc, std::fstream & booksFile);

//Helper functions
std::string addSpaces(std::string & str);
void removeSpaces(std::string & str);

int main()
{
    std::fstream myFile;    
	std::fstream loginsFile("Logins.txt");
	std::fstream booksFile("BooksInventory.csv");

	bool loadBooksFlag = true;
    bool activeMenuFlag = false;
    bool loginMenuFlag = false;    
    std::map<std::string,std::string> m1;
    Book acc;
   
   // Logging in	
    do
    {
    int loginChoice = loginMenu();
        switch(loginChoice)
        {
            case 1:
            {
                bool entry = loginScreen(loginsFile); //If login was success, break out of loop
                if (entry = true)
                {
                loginMenuFlag = true; //Continue to main screen
                }
                break;
            }
            case 2:
            {
                createUser(myFile);
                break;
            }
            case 3:
            {
				std::cout << "Now exiting.." << std::endl;
                exit(1);
            }
            default:
            {
                std::cout << "Incorrect choice!" << std::endl;
                break;
            }
        }
    }while(!loginMenuFlag);

	//After logging in
        do
        {
        int menuOption = menu();
        switch(menuOption)
        {
            case 1: 
            {
                std::cout << "Adding book..." << std::endl;
                addBook(acc, m1, myFile);
                break;
            }
            case 2:
            {
				std::cout << "Displaying Books..." << std::endl;
				loadBooks(acc, booksFile);
				acc.readOutBooks();	

				break;
			}
            case 5:
            {
                activeMenuFlag = true;
                break;
            }
            default:
            {
                std::cout << "Invalid Input" << std::endl;
                break;
            }
        }
    } while (!activeMenuFlag);
    return 0;
    //Should we use vectors?
    //std::cout << acc.getTitle();

}

int menu()
{
    int choice;
    std::cout << "1) Add book" << std::endl;
    std::cout << "2) Display books" << std::endl;
    std::cout << "5) Quit" << std::endl;

    std::cin >> choice;

    return choice;
}

int loginMenu()
{
    int choice;
    std::cout << "1) Login" << std::endl;
    std::cout << "2) Create new acc" << std::endl;
    std::cout << "3) Exit" << std::endl;
    std::cin >> choice;
    
    return choice;
}

bool addBook(Book & acc,std::map<std::string, std::string> & m1, std::fstream & myFile)
{
    std::string title;
    std::string author;


	myFile.open("BooksInventory.csv", std::ios::out | std::ios::app);


	acc.fullBooks.clear();
	acc.fullAuthors.clear();
	acc.fullAvail.clear();

    std::cout << "Please enter title" << std::endl;
    std::cin.ignore();
    std::getline(std::cin,title);

    std::cout << "Please enter author" << std::endl;
    std::getline(std::cin,author);

	removeSpaces(title);
	removeSpaces(author);

    acc.addBook(title, author);



//	std::cout << "Inserting... " << acc.getTitle() << " by " << acc.getAuthor() << std::endl;

//    m1.insert(std::pair<std::string, std::string>(acc.getTitle(), acc.getAuthor())); //Not need?
   
  	//Write book information to file

    myFile << acc.getTitle() << " " << acc.getAuthor() << " " << 1 << std::endl;



	myFile.close();

}

//Use this when existing user is logging in
//Read in file "Logins.txt"
bool loginScreen(std::fstream & loginsFile)
{
    //Arrays to hold usernames and password.
    std::string Usernames[CAPACITY];
    std::string Passwords[CAPACITY];

    bool success;
//    myFile.open("Logins.txt");
    std::string username;
    std::string password;
    std::string foundPassword;
    //Map to hold users and password
    std::map<std::string, std::string> users;

    //Put text file into usernames and passwords
    //Insert in users map
    for(int i = 0; i < CAPACITY; i++)
    {
        loginsFile >> Usernames[i] >> Passwords[i];
        users.insert(std::pair<std::string, std::string>(Usernames[i], Passwords[i]));
    }

    bool userFound = false;
    do
    {
        std::cout << "Hello, please enter username: " << std::endl;
        std::cout << "Username: " << std::endl;
        std::cin >> username;
         
        //Find username
        auto it = users.find(username);
        if(it != users.end())
        {   
            //Have value of key equal to foundPassword
            foundPassword = it->second;
            userFound = true;
        }
        else
        {
            std::cout << "User not found!" << std::endl;
        }
    }while(!userFound);
    bool lginSuccess = false;

    do
    { 
        int tries = 2;
        for(tries; tries >= 0; tries--)
        {
            std::cout << "Password: " << std::endl;
            std::cin >> password;
            if (foundPassword == password)
            {
                std::cout << "Welcome!\n";
                success = true;
                lginSuccess = true;
                return 0;
            }
            else if (foundPassword != password)
            {
            std::cout << tries << " tries remaining" << std::endl;
            std::cout << "Invalid Password!" << std::endl;
            }
            if(tries == 0)
            {
                exit(0);
            }
        }
    }while(!lginSuccess);

    loginsFile.close();
}

//Allows User to create new User
//Create bounds for user and pass?
//Send user and password to logins.txt
void createUser(std::fstream & loginsFile)
{
    std::string username;
    std::string password;
    loginsFile.open("Logins.txt", std::ios::out | std::ios::app);
    std::cout << "Please enter username : ";
    std::cin >> username;
    std::cout << std::endl;

    std::cout << "Please enter password : ";
    std::cin >> password;
    std::cout << std::endl;
    
    loginsFile << username << " " << password << std::endl;

    loginsFile.close(); 

}

void loadBooksv2(Book & acc, std::fstream & booksFile)
{
	booksFile.open("BooksInventory.csv");
	std::string line, word;
	std::stringstream lineStream;

	while (std::getline(booksFile, line))
	{
		lineStream.clear();
		lineStream.str(line);

		std::cout << "Pushing" << std::endl;
	//	acc.pushOntoVector(lineStream);
	}
	std::cout << "Vector size is " << acc.getVectorSize();

	booksFile.close();
}

void loadBooks(Book & acc, std::fstream & booksFile)
{
	
	std::string Book[CAPACITY];
	std::string Authors[CAPACITY];
	int Avail[CAPACITY];

	int size = 0;

	int i = 0;

	while(!booksFile.eof())
	{
		booksFile >> Book[i] >> Authors[i] >> Avail[i];
		i++;
		size++;
		acc.bookCounter++;
	}
	
	std::cout << "Stage 2" << std::endl;
	for (int i = 0; i < size; ++i)
	{
		acc.fullBooks.push_back(addSpaces(Book[i]));
		acc.fullAuthors.push_back(addSpaces(Authors[i]));
		acc.fullAvail.push_back(Avail[i]);
	}

}

std::string addSpaces(std::string & str)
{
	int size = str.size();

	int j = 0;

	for (int i = 1; i < str.size(); i++)
	{
		if (isupper(str[i]))
		{
			str.insert(i++, " ");
		}

		if (isdigit(str[i]))
		{
			str.insert(i++, " ");
		}
	}

	return str;
}

void removeSpaces(std::string & str)
{
	std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
	str.erase(end_pos, str.end());
}
