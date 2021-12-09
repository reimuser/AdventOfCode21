#include<iostream>
#include<fstream>
#include<string>
#include<array>

/**
 * @brief day 1 - part b
 * 
 * @return int 
 */
int main()
{
    std::string filename("input.txt");
    
    int array[2000] = {0};
    int prevNo = 0, number = 0;
    int counter = 0;
    
    int a = 0, b = 0, c = 0;
    int d = 0, e = 0, f = 0;

    std::ifstream input_file(filename);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file - '"
             << filename << "'" << std::endl;
        return 1;
    }

    while(input_file >> number) {
        array[counter] = number;
        counter++;
    }
    counter = 0;



    for(int i = 0; i < 2000 - 3; i++)
    {
        a = array[i];
        b = array[i+1];
        c = array[i+2];

        d = array[i+1];
        e = array[i+2];
        f = array[i+3];

        if(a+b+c < d+e+f)
        {
            std::cout << "increased" << std::endl;
            counter++;
        } 
        else if (a+b+c > d+e+f) 
        {
            std::cout << "decreased" << std::endl;
        }
    }

    std::cout << counter << std::endl;


    input_file.close();

    return 0;
}