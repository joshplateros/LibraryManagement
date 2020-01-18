#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

int menuChoice();

int main()
{
	std::fstream file("testFile.csv");

	std::vector<std::string> authors;
	std::vector<std::string> books;
	std::vector<std::string> avail;

	std::string line, word;
	std::getline(file,line);

	std::stringstream lineStream(line);
		while (std::getline(lineStream, word, '|'))
		{
			books.push_back(word);
			std::stringstream elementStream(word);
			std::string element;
			lineStream.clear();
			while (std::getline(lineStream, element, ';'))
			{
				authors.push_back(element);
				std::string number;
				lineStream.clear();
				std::stringstream numberStream(element);
				while (std::getline(lineStream, number))
				{
					avail.push_back(number);
					lineStream.clear();
				}
			}
		}

	for (int i = 0; i < books.size(); i++)
	{
//		std::cout << books[i] << std::endl;
	}

	std::cout << books[0] << std::endl;
	std::cout << authors[0] << std::endl;
	std::cout << avail[0] << std::endl;

	file.close();
}


