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
bool readFromCSVFile(string filename);


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

bool readFromCSVFile(string filename)
{
    ifstream inFile;
    istringstream thisLine;
    string movieInfo;
    string movieTitle;
    string year;
    string director;

    inFile.open(filename);
    if (inFile.fail())
    {
        cout << "Read error - sorry!\n";
        return false;
    }

    while (true)
    {
        getline(inFile, movieInfo);
        if (inFile.fail())
        {
            break;
        }
        thisLine.clear();
        thisLine.str(movieInfo);
        getline(thisLine, movieTitle, ',');
        getline(thisLine, year, ',');

        vector <string> directorList;
        string dir;
        while (getline(thisLine, dir, ','))
        {
            directorList.push_back(dir);
        }
        director = directorList[0];
        for (int i = 1; i < directorList.size(); i++)
        {
            director = director + " and " + directorList[i];
        }

        cout << movieTitle << " is a " << year << " film directed by " << director << endl;
    }

    //Close the file and return
    inFile.close();
    return true;
}