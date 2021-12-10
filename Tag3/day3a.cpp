#include<iostream>
#include<fstream>
#include<string>
#include<array>
#include<vector>
#include<sstream>

struct COMMANDS {
    std::string direction;
    int unit;
} command;

/**
 * @brief 
 * 
 * @return int 
 */
int main ()
{
    int depth = 0, horizon = 0;
    std::ifstream input;
    std::vector<std::string> values;
    std::string gamma;
    std::string epsilon;

    input.open("input.txt");
    std::string line;

    if(input.is_open()) 
    {
        while(input)
        {
            std::getline(input, line);
            values.push_back(line);
        }
        values.pop_back();


        int oneCount = 0, zeroCount = 0;
        for(int i = 0; i < values.front().length(); i++)
        {
            for(auto& binary : values)
            {
                if(binary.at(i) == '0')
                {
                    zeroCount++;
                }
                else
                {
                    oneCount++;
                }
            }
            if(zeroCount > oneCount)
            {
                gamma.append("0");
                epsilon.append("1");
            }
            else
            {
                gamma.append("1");
                epsilon.append("0");
            }
        }

        int gam = std::stoi(gamma, nullptr, 2);
        int eps = std::stoi(epsilon, nullptr, 2);

        std::cout << gam << " " << eps << " " << gam * eps << std::endl;
    }
    else
    {
        std::cout << "Couldn't open file\n";
    }
    
    return 0;
}
