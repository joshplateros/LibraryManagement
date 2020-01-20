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
		std::cout << fullBooks[i] << " by " << fullAuthors[i] << std::endl;
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
