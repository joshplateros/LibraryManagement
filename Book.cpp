#include <iostream>
#include "Book.h"
#include <string>
#include <sstream>
#include <vector>

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

void Book::load(std::fstream& myFile)
{
	std::string line, word;
	std::stringstream lineStream;

	while (std::getline(myFile, line))
	{
		lineStream.clear();
		lineStream.str(line);

		bookAuthor.push_back(lineStream.str());
	}
}

void Book::readOutBooks()
{
	for (int i = 0; i < bookAuthor.size(); i++)
	{
		std::cout << bookAuthor[i] << std::endl;
	}
}
