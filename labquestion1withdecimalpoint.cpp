#include <iostream>
#include <string>

bool isNumeric(const std::string& input) {
 bool hasDecimalPoint = false;

for (char c : input)
{
 if (c == '.')
{
 if (hasDecimalPoint)
{
    return false;
}
  hasDecimalPoint = true;
} else if (c < '0' || c > '9')
{
  return false;
}
}
return true;
}

int main()
{
 std::string userInput;
 std::cout << "Enter a value: ";
 std::cin >> userInput;
  if (isNumeric(userInput))
    {
    std::cout << "The given input is numeric." << std::endl;
    } else
    {
      std::cout << "The given input is not numeric." << std::endl;
    }
      return 0;
}
