#ifndef LOGINS_H
#define LOGINS_H
#include <string>
#include <fstream>
#include <vector>

class Logins
{
	public:
		void createUser(std::fstream & loginsFile);
		int loginMenu();
		bool loginScreen(std::fstream & loginsFile);



	private:

		size_t MAX = 100;

};

#include "Logins.cpp"

#endif
