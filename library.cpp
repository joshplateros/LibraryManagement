#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include "Book.h"
#include <fstream>
#include <sstream>
#include <vector>

/* TODO: Read in book file to accept. <-- Look at create users, most likely use CSV.

   Password Restritions (Spaces)
*/

size_t CAPACITY = 100;

//Login functions
void createUser(std::fstream & myFile);
int loginMenu();
bool loginScreen(std::fstream & myFile);

//Menu function
int menu();

//Book functions
bool addBook(Book & acc, std::map<std::string, std::string> & m1, std::fstream & myFile);
void displayBooks(Book & acc, std::map<std::string, std::string> & m1, std::fstream & myFile);
void readInBooks(std::fstream & myFile, std::map<std::string, std::string> & m1);
//bool addStudent(Student & acc);

int main()
{
    std::fstream myFile;    
	std::fstream testFile("BooksInventory.csv");

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
                bool entry = loginScreen(myFile);
                //If login was success, break out of loop
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
                std::cout << "Displaying books..." << std::endl;
    //            displayBooks(acc, m1, myFile);
				acc.load(testFile);
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
    std::cout << "2) Display Books" << std::endl;
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

    //Optimize later?
    std::cout << "Please enter title" << std::endl;
    std::cin.ignore();
    std::getline(std::cin,title);

    std::cout << "Please enter author" << std::endl;
    std::getline(std::cin,author);

    acc.addBook(title, author);

    m1.insert(std::pair<std::string, std::string>(acc.getTitle(), acc.getAuthor()));
   
  	//Write book information to file

	myFile.open("BooksInventory.csv", std::ios::out | std::ios::app);

	myFile << acc.getTitle() << "," << acc.getAuthor() << std::endl;

	myFile.close();

}
void displayBooks(Book & acc, std::map<std::string, std::string> & m1, std::fstream & myFile)
{
	//Use readInBooks first to populate map
    std::cout << "Display Book Function" << std::endl;
    std::map<std::string, std::string>::iterator itr;

    //if (m1.empty())
    //{
    //    std::cout << "Empty!" << std::endl;
    //}
    //else
    //{
    //    for (itr = m1.begin(); itr != m1.end(); ++itr)
    //    {
    //        std::cout << itr->first << " - ";
    //        std::cout << itr->second << std::endl;
    //    }
   // }

	std::vector<std::string> bookAuthor;
	std::string line, word;
	std::stringstream lineStream;

	int row = 0;

	myFile.open("BooksInventory.csv");

	while (std::getline(myFile, line))
	{
		lineStream.clear();
		lineStream.str(line);

		bookAuthor.push_back(lineStream.str());

		//Implement later to have books in one vector and author in another

		//while (std::getline(lineStream, word, ',' ))
		//{
		//	book.push_back(word);
		//}
		std::cout << "Test 1: " << bookAuthor[0] << std::endl;
	}


	myFile.close();
}

//Use this when existing user is logging in
//Read in file "Logins.txt"
bool loginScreen(std::fstream &myFile)
{
    //Arrays to hold usernames and password.
    std::string Usernames[CAPACITY];
    std::string Passwords[CAPACITY];

    bool success;
    myFile.open("Logins.txt");
    std::string username;
    std::string password;
    std::string foundPassword;
    //Map to hold users and password
    std::map<std::string, std::string> users;

    //Put text file into usernames and passwords
    //Insert in users map
    for(int i = 0; i < CAPACITY; i++)
    {
        myFile >> Usernames[i] >> Passwords[i];
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

    myFile.close();
}

//Allows User to create new User
//Create bounds for user and pass?
//Send user and password to logins.txt
void createUser(std::fstream & myFile)
{
    std::string username;
    std::string password;
    myFile.open("Logins.txt", std::ios::out | std::ios::app);
    std::cout << "Please enter username : ";
    std::cin >> username;
    std::cout << std::endl;

    std::cout << "Please enter password : ";
    std::cin >> password;
    std::cout << std::endl;
    
    myFile << username << " " << password << std::endl;

    myFile.close(); 

}
void readInBooks(std::fstream & myFile, std::map<std::string, std::string> & m1)
{
	//Read in CSV file, store into m1 (map)
	myFile.open("BooksInventory.csv", std::ios::out | std::ios::app); //ios::app is append to file


	myFile.close();

}
