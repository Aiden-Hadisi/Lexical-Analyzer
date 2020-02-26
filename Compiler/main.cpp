#include<iostream>
#include <fstream>
#include "lexical-tests.h"
using namespace std;
/**
Lexical analyzer by Aiden Hadisi
Main File.
The lexical_tests.h includes the function declarations
lexer.cpp contains function definitions
**/
int main()
{

    ifstream infile;
    string fileName = "";
    string expression = "";
    vector<Token> tokens;

    // Ask user to enter a file name containing the code
    cout<<"Please enter the name of the file: ";
    getline(cin, fileName);

    infile.open(fileName.c_str());

    if(infile.fail())
    {
        cout<<"ERROR: COULD NOT FIND THAT FILE!";
        exit(1);
    }

    // read file line by line
    while(getline(infile, expression))
    {

        //Call the lexer that will return a list of tokens
        tokens = lexer(expression);

        // show the tokens
        for(unsigned x = 0; x < tokens.size(); ++x)
        {
            cout<<tokens[x].lexemeName<<":   "
                <<tokens[x].tokenName<<endl;
        }
    }

    infile.close();

    return 0;
}
