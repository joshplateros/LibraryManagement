#include <iostream>
#include "Book.h"
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>

bool Book::setBook(const std::string & aTitle, const std::string & theAuthor)
{
    setTitle(aTitle);
    setAuthor(theAuthor);

    return true;
}

void Book::setTitle(const std::string & aTitle)
{
    m_title = aTitle;
}
void Book::setAuthor(const std::string & theAuthor)
{
    m_author = theAuthor;
} 
std::string Book::getTitle()
{
    return m_title;
}

std::string Book::getAuthor()
{
    return m_author;
}

void Book::readOutBooks()
{
	//std::cout << "Book Counter is " << bookCounter << std::endl;
	for (int i = 0; i < fullBooks.size() - 1;i++)
	{
		std::cout << fullBooks[i] << " by " << fullAuthors[i] << " - " << toString(fullAvail[i]) << std::endl << std::endl;
	}
			//resize vector in addBook?
}

void Book::removeSpaces(std::string & str)
{
	std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
	str.erase(end_pos, str.end());
}

void Book::loadBooks(std::fstream & booksFile)
{
	std::string Book[MAX];
	std::string Authors[MAX];
	int Avail[MAX];

	int size = 0;

	int i = 0;

	fullBooks.clear();
	fullAuthors.clear();
	fullAvail.clear();

	while (!booksFile.eof())
	{
		booksFile >> Book[i] >> Authors[i] >> Avail[i];
		i++;
		size++;
		bookCounter++; //Might not use
	}

	booksFile.clear();
	booksFile.seekg(0, std::ios::beg);

	for (int i = 0; i < size; ++i)
	{
		fullBooks.push_back(addSpaces(Book[i]));
		fullAuthors.push_back(addSpaces(Authors[i]));
		fullAvail.push_back(Avail[i]);
	}
}

void Book::addBook(std::map<std::string, std::string> & m1, std::fstream & myFile)
{
	std::string title;
	std::string author;

	myFile.open("BooksInventory.csv", std::ios::out | std::ios::app);

	fullBooks.clear();
	fullAuthors.clear();
	fullAvail.clear();

	std::cout << "Please enter title" << std::endl;
	std::cin.ignore();
	std::getline(std::cin, title);

	std::cout << "Please enter author" << std::endl;
	std::getline(std::cin, author);

	removeSpaces(title);
	removeSpaces(author);

	setBook(title, author);

	std::cout << "Please select type" << std::endl;
	std::cout << "1) Fiction " << std::endl;
	std::cout << "2) Non-fiction " << std::endl;
	
	int type;

	std::cin >> type;

	std::cout << "Please select genre" <<< std::endl;

	getGenre(type); //Select genre based on type, if Other ask for user input

	myFile << getTitle() << " " << getAuthor() << " " << 1 << std::endl;

	myFile.close();

}

std::string Book::addSpaces(std::string & str)
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

std::string Book::toString(int x)
{
	if (x == 1)
	{
		return "Available";
	}
	else
	{
		return "Not Available";
	}
}

std::string Book::getGenre(int type)
{
	if (type == 1) // Fiction (not real)
	{
		int choice = displayFictionGenres();
		switch(choice)
		{
			case 1:
			{
				return "genre 1";
			}
		}
	}
	else if (type == 2) // Non-Fiction
	{
		int choice = displayNFictionGenres();
		switch(choice)
		{
			case 1:
			{
				return "genre 1";
			}
		}
	}
}

int displayFictionGenres()
{
	int genreSelection;

	std::cout << "1) Action & Adventure" << std::endl;
	std::cout << "2) Alternate History" << std::endl;
	std::cout << "3) Anthology" << std::endl;
	std::cout << "4) Chick Lit" << std::endl;
	std::cout << "5) Children's" << std::endl;
	std::cout << "6) Comic Book" << std::endl;
	std::cout << "7) Coming-of-age" << std::endl;
	std::cout << "8) Crime" << std::endl;
	std::cout << "9) Drama" << std::endl;
	std::cout << "10) Fairytale" << std::endl;
	//Next page insert? with CLS and back page
	std::cout << "11) Fantasy" << std::endl;
	std::cout << "12) Graphic Novel" << std::endl;
	std::cout << "13) Historical Fiction" << std::endl;
	std::cout << "14) Horror" << std::endl;
	std::cout << "15) Mystery" << std::endl;
	std::cout << "16) Paranormal Romance" << std::endl;
	std::cout << "17) Picture Book" << std::endl;
	std::cout << "18) Poetry" << std::endl;
	std::cout << "19) Satire" << std::endl;
	std::cout << "20) Science Fiction" << std::endl;
	//Next page
	std::cout << "21) Short Story" << std::endl;
	std::cout << "22) Suspense" << std::endl;
	std::cout << "23) Thriller" << std::endl;
	std::cout << "24) Young Adult" << std::endl;
	std::cout << "25) Other" << std::endl; //Have user input other genre
	
	std::cin >> genreSelection;

	return genreSelection;
}

