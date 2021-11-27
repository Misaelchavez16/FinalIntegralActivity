#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

// home-made libraries
#include "server.h"
#include "linkedlist.h"
#include "bst.h"

#include "code_functions.h"


// argc == argument count. Count is set automatically.
// argv == argument vector(string of characters). literally arr of string, which can be indexed.
int main(int argc, char* argv[]){
    for(int i = 0; i < argc; i++){
        cout << argv[i] << endl;
        if(strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) help();
    }
    
    return 0;
};