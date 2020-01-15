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

int Book::getVectorSize()
{
	return bookAuthor.size();
}

void Book::clearVector()
{
	bookAuthor.clear();
}

void Book::pushOntoVector(std::stringstream & s)
{
	bookAuthor.push_back(s.str());
}
