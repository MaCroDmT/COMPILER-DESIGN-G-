#include <iostream>
#include <string>
#include <vector>

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
int main() {
std::string expression;
std::cout << "Enter an arithmetic expression: ";
std::cin >> expression;
std::vector<char> operatorsWithinBrackets;
bool withinBrackets=false;

for (char c : expression)
{
   if (c == '(')
{
withinBrackets=true;
}
  else if (c == ')')
{
withinBrackets=false;
}
  else if(withinBrackets && isOperator(c))
{
operatorsWithinBrackets.push_back(c);
}
}
if (!operatorsWithinBrackets.empty())
{
std::cout << "Operators within brackets: ";
for (char op : operatorsWithinBrackets)
{
std::cout <<op<< " ";
}
std::cout <<std::endl;
} else
    {
    std::cout << "No operators within brackets found." << std::endl;
    }
    return 0;
}
