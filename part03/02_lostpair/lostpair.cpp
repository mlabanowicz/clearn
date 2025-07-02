#include <iostream>
#include <unordered_map>

int main()
{
    std::unordered_map<std::string, short> word_ctr;

    std::string word;

    while (getline(std::cin, word))
    {
        word_ctr[word]++;
    }

    for (const auto& pair : word_ctr)
    {
        if (pair.second == 1)
        {
            std::cout << pair.first << std::endl;
            break;
        }
    }
}