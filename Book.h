#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

//Overloaded << constructor? Probably

class Book
{
    public:
    std::string getTitle() const;
    std::string getAuthor() const;
    void setTitle(const std::string & aTitle);
    void setAuthor(const std::string & theAuthor);
	void readOutBooks();
	void load(std::fstream & myFile);
    bool addBook(const std::string & aTitle, const std::string & theAuthor);
    Book(){}
    Book(const std::string & aTitle, const std::string & theAuthor) : m_title(aTitle), m_author(theAuthor)
    {}
    ~Book()
    {
        m_title = " ";
        m_author = " ";
    }
    //Edit Book, can ask which part to edit, and then reassign that variable? Maybe use vectors? google map of vectors in STL on google

    private:
    std::string m_title;
    std::string m_author;
	std::vector<std::string> bookAuthor;
    int m_BIN;    

};

#include "Book.cpp"

#endif //BOOK_H
