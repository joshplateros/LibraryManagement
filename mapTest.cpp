#include<iostream>
#include<map>
#include<fstream>
#include<iterator>

using namespace std;

int main()
{
    string Usernames[100];
    string Passwords[100];
    fstream myFile;
    myFile.open("Logins.txt");
    map<string,string> m1;
    map<string,string>::iterator itr;
    for(int i = 0; i < 100; i++)
    {
        myFile >> Usernames[i] >> Passwords[i];
    }
    for(int i = 0; i < 100; i++)
    {
        m1.insert(pair<string,string>(Usernames[i],Passwords[i]));
    }
   // for(itr = m1.begin(); itr != m1.end(); itr++)
   // {
   //     cout << itr-> first << " " << itr->second << endl; 
   // }
    string user;
    string password; 
    cout << "Enter username" << endl;
    cin >> user;
    cout << "Enter password" << endl;
    cin >> password;
    auto it = m1.find(user);
    if(it != m1.end())
    {
        string foundPassword = it->second;
        if(foundPassword == password)
        {
            cout << "mmm" << endl;
        }
    }

//    for(itr = m1.begin(); itr != m1.end(); itr++)


}
