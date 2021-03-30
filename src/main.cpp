#include <iostream>
#include <string>
#include <sstream>

struct Character
{
    int frequency; /// Number of times the character appears.
    char character; /// Actual character.
};

void print_character_information(Character c)
{
    printf("Most Frequent Character: '%c'\nFrequency of '%c': %d\n", c.character, c.character, c.frequency);
}

// O(3n)
Character max_character(std::string input)
{
    Character c;
    int ascii_chars[128];

    int max = -1;    
    char cc = ' ';

    // Init Array to 0
    for (int i = 0; i < 128; i++)
    {
        ascii_chars[i] = 0;
    }

    // Loop through string, Add to its position in ascii
    for (long long unsigned int i = 0; i < input.size(); i++)
    {
        char c = input[i];
        int pos = (int)c;
        int old_count = ascii_chars[pos];

        ascii_chars[pos] = ++old_count;
    }

    // Getting the Max
    for (int i = 0; i < 128; i++)
    {
        if (ascii_chars[i] > max && i != 32) // 32 is the ASCII label for a space.
        {
            max = ascii_chars[i];
            cc = (char)i;
        }
    }

    c.frequency = max;
    c.character = cc;

    return c;
}

void input_string()
{
    std::string line; 
    std::cout << "Please input a string: "; 
    std::getline(std::cin, line);

    Character c = max_character(line);
    print_character_information(c);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        input_string();
    }
    else
    {
        std::stringstream args;
        std::string str;

        for (int i = 1; i < argc; i++)
        {
            args << argv[i] << ' ';
        }

        str = args.str();
        std::cout << "Interpreted String: " << str << std::endl;
        Character c = max_character(str);
        print_character_information(c);
    }
}
