//
//  textfile.hpp
//  PIC 10B HW3
//
//  Created by Michaella Baltazar on 11/3/19.
//  Copyright © 2019 Michaella Baltazar. All rights reserved.
//

#ifndef textfile_h
#define textfile_h
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>

using namespace std;

class textfile
{
public:
    textfile();
    textfile(istream &n);
    long getChars();
    int getWords();
    int getLines();
private:
    long characters = 0;
    int words = 0;
    int lines = 0;
    istream* currentFile = nullptr;
};

#endif /* textfile_hpp */
