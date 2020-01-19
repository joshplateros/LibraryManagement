#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

void removeSpaces(std::string & str);

int main()
{
	std::string send = "Taco Bell";

	removeSpaces(send);

	std::cout << send << std::endl;



}


void removeSpaces(std::string & str)
{
	std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
	str.erase(end_pos, str.end());
}
