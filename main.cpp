#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string>
#include <vector>

#include <time.h>   // for calculating and formating to week number

#include <stdio.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

// home-made libraries
#include "server.h"
#include "linkedlist.h"
#include "bst.h"
#include "hashTable.h"
#include "code_functions.h"

// CString sDir = COleDateTime::GetCurrentTime().Format( "\\%Y\\%W" );


// argc == argument count. Count is set automatically.
// argv == argument vector(string of characters). literally arr of string, which can be indexed.
int main(int argc, char* argv[]){

    LinkedList<Server>  auxiliar_ll;
    read_file("bitacora1.txt", auxiliar_ll);
    int auxiliar_ll_size = auxiliar_ll.length();
    most_breached_ips(auxiliar_ll, auxiliar_ll_size);

    





















//   time_t rawtime;
//   struct tm * timeinfo;
//   char buffer [80];

//   time (&rawtime);
//   timeinfo = localtime (&rawtime);

//   strftime(buffer,80,"week %U.",timeinfo);
//   puts(buffer);

    // In case the size of the argv or just main.exe on argv, then run help for giving
    // run instructions or examples to user and then exit
    if(argc <= 1) exit(0);
    if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0){help();exit(0);}

    // create a queue for reciving the commands and apply them in FIFO order
    // FIFO == First in First out
    LinkedList<char*> commands = LinkedList<char*>();      // queue creation
    string route="abc";int number_breached_directions = 0; // variables to store input
    for(int i = 1; i < argc; i++){
        commands.queue(argv[i]);
        if(strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--file") == 0){route = argv[i+1];i++;}
        if(strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--directions") == 0){number_breached_directions = atoi(argv[i+1]);i++;}
    }
    char * command;
    while(!commands.is_empty()){
        command = commands.dequeue();
        // here corresponding methods will me runned
        cout << command << endl;
    }
    
    return 0;
};