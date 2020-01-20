#include "Logins.h"
#include <iostream>
#include <vector>
#include <fstream>

void Logins::createUser(std::fstream & loginsFile)
{
	std::string username;
	std::string password;
	loginsFile.open("Logins.txt", std::ios::out | std::ios::app);
	
	std::cout << "Please enter username: ";
	std::cin >> username;
	std::cout << std::endl;

	std::cout << "Please enter password: ";
	std::cin >> password;
	std::cout << std::endl;

	loginsFile << username << " " << password << std::endl;

	loginsFile.close();
}

int Logins::loginMenu()
{
	int choice;
	std::cout << "1) Login" << std::endl;
	std::cout << "2) Create new acc" << std::endl;
	std::cout << "3) Exit" << std::endl;
	std::cin >> choice;

	return choice;
}

bool Logins::loginScreen(std::fstream & loginsFile)
{
	//Hold usernames and passwords
	std::string Usernames[MAX];
	std::string Passwords[MAX];

	bool success;

	std::string username;
	std::string password;
	std::string foundPassword;

	std::map<std::string, std::string> users;
	//Link usernames to passwords

	for (int i = 0; i < MAX; i++)
	{
		loginsFile >> Usernames[i] >> Passwords[i];
		users.insert(std::pair<std::string, std::string>(Usernames[i], Passwords[i]));
	}

	bool userFound = false;

	do
	{
		std::cout << "Please enter username: " << std::endl;
		std::cout << "Username: " << std::endl;
		std::cin >> username;

		auto it = users.find(username);
		if (it != users.end())
		{
			//Have value of key equal to foundPassword
			foundPassword = it->second;
			userFound = true;
		}
		else
		{
			std::cout << "User not found!" << std::endl;
		}
	} while (!userFound);

	bool lginSuccess = false;

	do
	{
		int tries = 2;
		for (tries; tries >= 0; tries--)
		{
			std::cout << "Password: " << std::endl;
			std::cin >> password;
			if (foundPassword == password)
			{
				std::cout << "Welcome!\n";
				success = true; //Need?
				lginSuccess = true;
				return 0;
			}
			else if (foundPassword != password)
			{
				std::cout << tries << " tires remaining" << std::endl;
				std::cout << "Invalid Password!" << std::endl;
			}
			if (tries == 0)
			{
				exit(0);
			}
		}
	} while (!lginSuccess);
	
	loginsFile.close();
}
