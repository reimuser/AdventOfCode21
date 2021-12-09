#include<iostream>
#include<fstream>
#include<string>
#include<array>

/**
 * @brief day 1 - part a
 * 
 * @return int 
 */
int main()
{
    std::string filename("input.txt");
    int number;

    std::ifstream input_file(filename);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file - '"
             << filename << "'" << std::endl;
        return 1;
    }

    int prevNo = 0;
    int counter = 0;
    while(input_file >> number) {
        if(prevNo < number)
        {
            std::cout << "increased" << std::endl;
            counter++;
        } 
        else if (prevNo > number) 
        {
            std::cout << "decreased" << std::endl;
        }
        prevNo = number;
    }

    std::cout << counter - 1 << std::endl;


    input_file.close();

    return 0;
}