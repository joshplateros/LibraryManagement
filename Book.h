#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iterator>

//Overloaded << constructor? Probably

class Book
{
    public:
    std::string getTitle();
    std::string getAuthor();
    void setTitle(const std::string & aTitle);
    void setAuthor(const std::string & theAuthor);
	void readOutBooks();
	bool addBook(const std::string & aTitle, const std::string & theAuthor);
	void pushOntoVector(std::stringstream & s);
	void clearVector();
	void removeSpaces(std::string & str);

	std::vector<std::string> fullBooks;
	std::vector<std::string> fullAuthors;
	std::vector<int> fullAvail;

	int getVectorSize();
    Book(){}
    Book(const std::string & aTitle, const std::string & theAuthor) : m_title(aTitle), m_author(theAuthor)
    {}
    ~Book()
    {
        m_title = " ";
        m_author = " ";
    }
    //Edit Book, can ask which part to edit, and then reassign that variable? Maybe use vectors? google map of vectors in STL on google
	int bookCounter = 0;
    private:
    std::string m_title;
    std::string m_author;
	std::vector<std::string> bookAuthor; //Delete
	//std::vector<std::string> fullBIN;
    int m_BIN;    //Similar to ASIN, implement later
	int vectorSize;

};

#include "Book.cpp"

#endif //BOOK_H
