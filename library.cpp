#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include "Book.h"
#include "Logins.h"
#include <fstream>
#include <vector>
#include <algorithm> //Remove spaces

/* TODO: Read in book file to accept. <-- Look at create users, most likely use CSV.

   Password Restritions (Spaces)
*/

size_t CAPACITY = 100;

//Menu function
int menu();

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
	Logins lgAcc;
   
   // Logging in	
    do
    {
    int loginChoice = lgAcc.loginMenu();
        switch(loginChoice)
        {
            case 1:
            {
                //bool entry = loginScreen(loginsFile); //If login was success, break out of loop
				bool entry = lgAcc.loginScreen(loginsFile);
                if (entry = true)
                {
                loginMenuFlag = true; //Continue to main screen
                }
                break;
            }
            case 2:
            {
                lgAcc.createUser(myFile);
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
                acc.addBook(m1, myFile);
                break;
            }
            case 2:
            {
				std::cout << "Displaying Books..." << std::endl;
				acc.loadBooks(booksFile);
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

	booksFile.close();
}

