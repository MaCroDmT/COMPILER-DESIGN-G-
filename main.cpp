#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <unordered_set>

bool isOperator(const std::string &word) {
    static const std::unordered_set<std::string> operators =
    {
        "+", "-", "*", "/", "=", "<", ">", "<=", ">=", "==", "!="
    };
    return operators.find(word) != operators.end();
}

int main()
{
    std::unordered_set<std::string> keywords = {
        "auto", "break", "case", "char", "class", "const", "continue", "default", "do", "double", "else", "enum",
        "extern", "float", "for", "goto", "if", "int", "long", "namespace", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "template", "this", "typedef", "union", "unsigned", "void", "volatile", "while"
    };

    std::ifstream file("source.txt");
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    std::regex wordRegex(R"([a-zA-Z_]\w*|[+\-*/=<>]+|\d+\.\d+|\d+)");
    std::sregex_iterator regexIterator(content.begin(), content.end(), wordRegex);
    std::sregex_iterator regexEnd;
    std::vector<std::string> identifiers;
    std::vector<std::string> constants;
    std::vector<std::string> operators;
    std::vector<std::string> foundKeywords;

    while (regexIterator != regexEnd)
        {
        std::smatch match = *regexIterator;
        std::string word = match.str();

        if (keywords.find(word) != keywords.end())
            {

            foundKeywords.push_back(word);
        } else if (isOperator(word))
         {

            operators.push_back(word);
        } else if (std::isdigit(word[0]))
         {

            constants.push_back(word);
        } else
        {
            identifiers.push_back(word);
        }
        ++regexIterator;
    }
    std::cout << "Identifiers found in the source file:" << std::endl;
    for (const auto &identifier : identifiers) {
        std::cout << identifier << std::endl;
    }
    std::cout << "Constants found in the source file:" << std::endl;
    for (const auto &constant : constants) {
        std::cout << constant << std::endl;
    }
    std::cout << "Operators found in the source file:" << std::endl;
    for (const auto &op : operators) {
        std::cout << op << std::endl;
    }
    std::cout << "Keywords found in the source file:" << std::endl;
    for (const auto &keyword : foundKeywords) {
        std::cout << keyword << std::endl;
    }

    return 0;
}
