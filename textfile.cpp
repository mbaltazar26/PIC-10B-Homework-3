//
//  textfile.cpp
//  PIC 10B HW3
//
//  Created by Michaella Baltazar on 11/3/19.
//  Copyright © 2019 Michaella Baltazar. All rights reserved.
//

#include "textfile.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

textfile::textfile()
{
    return;
}

textfile::textfile(istream &n)
{
    currentFile = &n;
}

long textfile::getChars()
{
    currentFile->seekg(0, ios::end);
    characters = currentFile->tellg();
    currentFile->clear();
    currentFile->seekg(0, ios::beg);
    return characters;
}

int textfile::getWords()
{
    string s;
    while (*currentFile >> s)
    {
        words++;
    }
    currentFile->clear();
    currentFile->seekg(0, ios::beg);
    return words;
}

int textfile::getLines()
{
    string s;
    *currentFile >> s;
    while (std::getline(*currentFile, s))
    {
        lines++;
    }
    currentFile->clear();
    currentFile->seekg(0, ios::beg);
    return lines;
}

