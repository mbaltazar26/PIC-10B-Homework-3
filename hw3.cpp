//
//  hw3.cpp
//  PIC 10B HW3
//
//  Created by Michaella Baltazar on 11/3/19.
//  Copyright © 2019 Michaella Baltazar. All rights reserved.
//

#include <stdio.h>
#include "textfile.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


int main()
{
    string file1;
    string file2;
    ifstream fs1;
    ifstream fs2;
    
    //ask for file 1
    cout << "Enter the name of file 1: ";
    getline(cin, file1);
    fs1.open(file1.c_str());
    if (fs1.fail())
    {
        cout << "Error opening " << file1 << "\n";
        return 1;
    }
    
    // ask for file 2
    cout << "Enter the name of file 2: ";
    getline(cin, file2);
    fs2.open(file2.c_str());
    if (fs2.fail())
    {
        cout << "Error opening " << file2 << "\n";
        return 1;
    }
    
    // pass fs1 and fs2 as parameters to create new textfiles 
    textfile* tf1 = new textfile(fs1);
    textfile* tf2 = new textfile(fs2);
    
    // write output to properties.txt
    ofstream fs3;
    fs3.open("Properties.txt");
    
    // all about file1
    fs3 << "File Name: " << file1 << endl;
    fs3 << "Number of characters: " << tf1->getChars() << endl;
    fs3 << "Number of words: " << tf1->getWords() << endl;
    fs3 << " " << endl;
    
    // all about file2
    fs3 << "File Name: " << file2 << endl;
    fs3 << "Number of characters: " << tf2->getChars() << endl;
    fs3 << "Number of words: " << tf2->getWords() << endl;
    fs3 << " " << endl;
    
    // compare
    if (tf1->getLines() < tf2->getLines())
        fs3 << "The file named " << file1 << " has less lines than " << file2 << "." << endl;
    else if (tf2->getLines() < tf1->getLines())
        fs3 << "The file named " << file2 << " has less lines than " << file1 << "." << endl;
    else if (tf1->getLines() == tf2->getLines())
        fs3 << file1 << " and " << file2 << " have the same amount of lines." << endl;

    fs1.close();
    fs2.close();
    
    return 0;
}
