#include <iostream>
#include "Book.h"
#include <string>

bool Book::addBook(const std::string & aTitle, const std::string & theAuthor)
{
   // Book *newPtr = new Book;
   // std::cout << "Book added!" << " - " << aTitle << " by " << theAuthor;
    setTitle(aTitle);
    setAuthor(theAuthor);
   // newPtr->m_title = "Test";
   // newPtr->setAuthor(theAuthor);

   // std::cout << "Added - " << getTitle() << " by " << getAuthor() << std::endl;

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
