#ifndef BOOK_H
#define BOOK_H
#include <string>

//Overloaded << constructor? Probably

class Book
{
    public:
    std::string getTitle() const;
    std::string getAuthor() const;
    void setTitle(const std::string & aTitle);
    void setAuthor(const std::string & theAuthor);
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
    int m_BIN;    

};

#include "Book.cpp"

#endif //BOOK_H
