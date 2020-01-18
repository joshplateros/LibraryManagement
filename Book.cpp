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
std::string Book::getTitle()
{
	removeSpaces(m_title);
    return m_title;
}

std::string Book::getAuthor()
{
	removeSpaces(m_author);
    return m_author;
}

void Book::readOutBooks()
{
	//std::cout << "Book Counter is " << bookCounter << std::endl;
	for (int i = 0; i < fullBooks.size();i++)
	{
		std::cout << fullBooks[i] << " by " << fullAuthors[i] << std::endl;
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

void Book::removeSpaces(std::string & str)
{
	int count = 0;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			str[count++] = str[i];
		}
	}

	str[count] = '\0';
}
