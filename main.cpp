#include <iostream>
#include <fstream>
#include <random>

double average_sym (std::ifstream& inputfile)
{
    double result;
    bool flag = false;
    char ch;
    int countofnum = 0, countofsym = 0;
    while (inputfile >> ch)
    {
        if (ch <= '9' && ch >= '0')
        {
            flag = true;
            countofsym++;
        }
        else if (flag)
        {
            flag = false;
            countofnum++;
        }
    }
    if (countofnum == 0)
    {
        return 0;
    }
    result = countofsym / (1. * countofnum);
    return result;
}

int main()
{
    char ch;
    std::string inname, outname;
    std::cout << "Enter input file name (\"test.txt\" for test program)" << std::endl;
    std::cin >> inname;
    std::cout << "Enter output file name" << std::endl;
    std::cin >> outname;

    std::ifstream inputfile (inname);
    std::ofstream outputfile;
    outputfile.open(outname, std::ofstream::app);
    if(!inputfile)
    {
        std::cout << "The File wasn`t opened" << std::endl;
    }
    outputfile << std::endl << "Result = " << average_sym(inputfile);
    inputfile.close();
    outputfile.close();
    return 0;
}
