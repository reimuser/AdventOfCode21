#include<iostream>
#include<fstream>
#include<string>
#include<array>
#include<vector>
#include<sstream>

struct COMMANDS {   // Declare PERSON struct type
    std::string direction;
    int unit;
} command;


COMMANDS splitString(std::string line)
{
    struct COMMANDS command;
    std::string delimiter = " ";
    std::vector<std::string> strings;
    std::istringstream lineStream(line);
    std::string str;

    while (getline(lineStream, str, ' ')) 
    {
        strings.push_back(str);
    }

    command.direction =  strings.at(0);
    command.unit = std::stoi(strings.at(1));

    return command;
}

/**
 * @brief 
 * 
 * @return int 
 */
int main ()
{
    int depth = 0, horizon = 0;
    std::ifstream input;
    std::vector<COMMANDS> values;

    input.open("input.txt");
    std::string line;

    if(input.is_open()) 
    {
        while(input)
        {
            std::getline(input, line);
            values.push_back(splitString(line));
        }
        values.pop_back();

        for(auto& command : values)
        {
            if(command.direction == "forward")
            {
                horizon += command.unit;
            }
            else if(command.direction == "down")
            {
                depth += command.unit;
            }
            else if(command.direction == "up")
            {
                depth -= command.unit;
            }
        }

        std::cout << "depth: " << depth << " horizon: "<< horizon << " mult: " << depth * horizon << std::endl;
    }
    else
    {
        std::cout << "Couldn't open file\n";
    }
    
    return 0;
}
