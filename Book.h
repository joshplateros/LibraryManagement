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
	bool setBook(const std::string & aTitle, const std::string & theAuthor);
	void addBook(std::map<std::string, std::string> & m1, std::fstream & myFile);
	void loadBooks(std::fstream & booksFile);
	void pushOntoVector(std::stringstream & s);

	std::string getGenre(int type); //Type is Fiction or Nonfiction
	int displayFictionGenres();
	int displayNFictionGenres();

	//Helper
	std::string addSpaces(std::string & str);
	void removeSpaces(std::string & str);
	std::string toString(int x);

	std::vector<std::string> fullBooks;
	std::vector<std::string> fullAuthors;
	std::vector<char> fullType;
	std::vector<std::string> fullGenre;
	std::vector<int> fullBIN;
	std::vector<int> fullAvail;

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
	int vectorSize;
	size_t MAX = 100;

};

#include "Book.cpp"

#endif //BOOK_H
