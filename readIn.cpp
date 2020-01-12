#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <string>

class CSV
{
	public:
		void load(std::fstream& myFile)
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
		void readOutBooks()
		{
			for (int i = 0; i < bookAuthor.size(); i++)
			{
				std::cout << bookAuthor[i] << std::endl;
			}
		}


	private:
			std::vector<std::string> bookAuthor;
};

int main()
{
	std::fstream myFile("BooksInventory.csv");
	CSV file;

	file.load(myFile);

	file.readOutBooks();

}

