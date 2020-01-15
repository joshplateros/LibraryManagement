#include <iostream>
#include <vector>

int menuChoice();

class theVector
{
	public: 
		void addToVector()
		{
			int userInput;

			std::cout << "Enter number to add: ";
			std::cin >> userInput;

			theVector.push_back(userInput);

		}

		void displayVector()
		{
			for (int i = 0; i < theVector.size(); i++)
			{
				std::cout << theVector[i] << " ";
			}
			std::cout << std::endl;
		}
	private: 
		std::vector<int> theVector;


};
int main()
{
	theVector access;

	bool flag = false;

	do
	{	
	int userChoice = menuChoice();
		switch(userChoice)
		{
			case 1:
			{
				access.addToVector();
				break;
			}
			case 2:
			{
				access.displayVector();
				break;
			}
			case 3:
			{
				exit(1);
			}

		}
	} while(!flag);
}

int menuChoice()
{
	
	int userChoice = 0;

	std::cout << "1) Add number" << std::endl;
	std::cout << "2) Displayer numbers" << std::endl;
	std::cout << "3) Exit " << std::endl;

	std::cin >> userChoice;

	return userChoice;

}
