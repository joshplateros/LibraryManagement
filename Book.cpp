#include <iostream>
#include "Book.h"
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

bool Book::addBook(const std::string & aTitle, const std::string & theAuthor)
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
std::string Book::getTitle() const
{
    return m_title;
}

std::string Book::getAuthor() const
{
    return m_author;
}

void Book::loadInitial(std::fstream& booksFile)
{
	booksFile.open("BooksInventory.csv");
	std::cout << "Opening file.." << std::endl;
	std::string line, word;
	std::stringstream lineStream;

	while (std::getline(booksFile, line))
	{
		lineStream.clear();
		lineStream.str(line);

		std::cout << "Pushing" << std::endl;
		bookAuthor.push_back(lineStream.str());

	}

	//bookCounter = bookAuthor.size();
}

void Book::loadNext(std::fstream & booksFile)
{
	std::string line, word;
	std::stringstream lineStream;
	while (std::getline(booksFile, line))
	{
		lineStream.clear();
		lineStream.str(line);

		bookAuthor.push_back(lineStream.str());
	}
}

void Book::readOutBooks()
{
	//std::cout << "Book Counter is " << bookCounter << std::endl;
	for (int i = 0; i < bookAuthor.size();i++)
	{
		std::cout << "I is : " << i << " ";
		std::cout << bookAuthor[i] << std::endl;
	}
			//resize vector in addBook?
}

void Book::updateVectorSize()
{
	bookAuthor.resize(bookAuthor.size() + 1);
}

int Book::getVectorSize()
{
	return bookAuthor.size();
}

//Might not need
void Book::setVectorSize()
{
	vectorSize = bookAuthor.size();
}

void Book::clearVector()
{
	bookAuthor.clear();
}

void Book::sayLastBook()
{
	std::cout << bookAuthor[getVectorSize()];
	std::cout << std::endl;
}

void Book::updateBookCounter()
{
	bookCounter++;
}

void Book::pushOntoVector(std::stringstream & s)
{
	bookAuthor.push_back(s.str());
}
