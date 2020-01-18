#include <iostream>
#include <fstream>
#include <vector>
#include <locale>

void removeSpaces(std::string & str);
std::string addSpaces(std::string & str);

int main()
{
	std::fstream file("testFile.csv");

	std::string Books[5];
	std::string Authors[100];
	std::string Avail[100];

	int size = 0;

	std::vector<std::string> fullBooks;
	std::vector<std::string> fullAuthors;
	std::vector<std::string> fullAvail;

	int i = 0;
	while (!file.eof())
	{
		file >> Books[i] >> Authors[i] >> Avail[i];
		i++;
		size++;
	}

	for(int i = 0; i < size - 1; ++i)
	{
		fullBooks.push_back(addSpaces(Books[i]));
		fullAuthors.push_back(addSpaces(Authors[i]));
	}

	for (int i = 0; i < size - 1; ++i)
	{
//		fullAuthors.push_back(addSpaces(Authors[i]));
	}
	for (int i = 0; i < fullBooks.size(); ++i)
	{
		std::cout << fullBooks[i] << std::endl;
		std::cout << fullAuthors[i] << std::endl;
	//	std::cout << fullAvail[i] << std::endl;
	}

	//Make function to read in author and avail.

	file.close();



}

void removeSpaces(std::string & str)
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

std::string addSpaces(std::string & str)
{

	int size = str.size();

	int j = 0; //For each word

	for (int i = 1; i < 10; i++)
	{
		if (isupper(str[i]))
		{
			str.insert(i++, " ");
		}
		
		if(isdigit(str[i]))
		{
			str.insert(i++, " ");
		}
	}

	//Send array of strings, add spaces to all strings, then push those strings to vector then 
	//return
	return str;
}
