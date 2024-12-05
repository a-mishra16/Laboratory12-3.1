/*
* Program: Laboratory12-3.1.cpp
* Author: Aanika Mishra
* Date 12-5-2024
* Description: This program will read in text files and display the word count and character count
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void pressEnterToContinue();
bool readFromFile(string filename);


int main()
{
    string datafile;
    cout << "Enter filename: ";
    getline(cin, datafile);
    readFromFile(datafile);
    pressEnterToContinue();
}

//Keeps Terminal Open
void pressEnterToContinue()
{
    cout << "\nPress enter to continue... \n";
    cin.clear();
    while (cin.get() != '\n') continue;
}

//Reads in the text
bool readFromFile(string filename)
{
    ifstream inFile;        //Input filestream to read in data
    string words;
    int wordCount = 0;
    int characters = 0;
    inFile.open(filename); //Attempts to open specified file

    if (inFile.fail()) //In case a problem occurs
    {
        cout << "Read error - sorry\n";
        return false;
    }

    //Here it reads data until done
    while (true)
    {
        inFile >> words;
        if (inFile.fail())
        {
            break; //No more data to read
        }

        wordCount++;
        characters += words.length();
    }

    //Close file and return
    inFile.close();
    cout << "Words: " << wordCount << endl;
    cout << "Characters: " << characters << endl;
    return true;
}

