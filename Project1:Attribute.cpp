#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>
#include <string>

int main ()
{
    std:srand(std::time(0));

    int n;
    
    std::cout << "Enter Number Of Attributes:";
    std::cin >> n;

    std::vector<int> attributes;

    for (int i = 1; i <= n; i++)
    {
        attributes.push_back(i);
    }

    std::vector<std::set<int>> users;

    while (users.size() < 10)
    {
        std::set<int> temp;

        int num = 2 + std:: rand() % (n -1);
        while (temp.size() < num)
        {
            int r = attributes[std::rand() % n];
            temp.insert(r);
        }
        bool duplicate = false;

        for (int i = 0; i < users.size(); i++)
        {
            if (users[i] == temp)
            {
                duplicate = true;
            }
        }
        if (!duplicate)
        {
            users.push_back(temp);
        }
    }
    std::cout << "Generated Users:\n";

    for (int i = 0; i < users.size(); i++)
    {
        std::cout << "User" << i + 1 << ": ";

        for (int attr : users[i])
        {
            std:: cout << attr << " ";
        }
        std::cout << "\n";
    }
    while (true)
    {
        int user;

        std::cout << "Enter User Number (1-10) or 0 to quit\n";
        std::cin >> user;

        if (user == 0)
        {
            break;
        }
        if (user < 1 || user > 10)
        { std::cout << "Invalid user.\n";
        continue;
    }
    std::cout << "User Attributes: ";

    for ( int attr : users[user - 1])
    {
        std::cout << attr << "  " ;
    }
    int a1, a2;
    std::string ope;
     std::cout << "Enter First Attribute: ";
     std::cin >> a1;

     std::cout << "Enter Operator (AND or OR): ";
     std::cin >> ope;

     std::cout << "Enter Second Attribute: ";
     std::cin >> a2;

     bool has1 = users[user -1].count(a1);
     bool has2 = users[user -1].count(a2);

     bool result = false;

     if (ope == "AND")
     {
        result = has1 && has2;
     }
     else if ( ope == "OR")
     {
        result = has1 || has2;
     }
     if (result)
     {
        std::cout << "TRUE (Access Granted)\n";
     }
     else
     {
        std::cout << "FALSE (Access Denided)\n";
     }
    }
    return 0;
}
