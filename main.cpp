#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <string>
#include <vector>

#include <time.h>   // for calculating and formating to week number
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>
using namespace std;

// home-made libraries
#include "server.h"
#include "linkedlist.h"
#include "hashTable.h"
#include "code_functions.h"

// CString sDir = COleDateTime::GetCurrentTime().Format( "\\%Y\\%W" );


// argc == argument count. Count is set automatically.
// argv == argument vector(string of characters). literally arr of string, which can be indexed.
int main(int argc, char* argv[]){

    if(argc <= 1) exit(0);
    if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0){help();exit(0);}

    LinkedList<char*> commands = LinkedList<char*>();      // queue creation
    string route="abc";int number_breached_directions = 5; // variables to store input
    LinkedList<Server>  auxiliar_ll;
    int auxiliar_ll_size;
    for(int i = 1; i < argc; i++){
        commands.queue(argv[i]);
        if(strcmp(argv[i], "-f") == 0 || strcmp(argv[i], "--file") == 0){route = argv[i+1];i++;}
        if(strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--directions") == 0){number_breached_directions = atoi(argv[i+1]);i++;}
    }
    string command = commands.dequeue();
    read_file(route, auxiliar_ll);
    auxiliar_ll_size = auxiliar_ll.length();
    Hashtable<string, int> attacked_ports(pow(auxiliar_ll_size,2.3));
    Hashtable<string, int> directions(pow(auxiliar_ll_size,2.3));
    Hashtable<string, int> sms_frequency(pow(auxiliar_ll_size,2.3));
    Hashtable<int, int> weeks(pow(auxiliar_ll_size,2.3));


    while(!commands.is_empty()){
        command = commands.dequeue();
        if(command == "-a" || command == "--attacked"){
            cout << "========= BREACHED PORTS ==========" << endl;
            count_briched_ports(auxiliar_ll, attacked_ports, auxiliar_ll_size);
        }
        if(command == "-d" ||command == "--directions"){
            cout << "========= MOST BREACHED IPs =========" << endl;
            most_breached_ips(auxiliar_ll, directions, auxiliar_ll_size, 5);
        }
        if(command == "--frequency"){
            cout << "========= FREQUENCY OF EACH MESSAGE =======" << endl;
            message_frequency(auxiliar_ll, sms_frequency, auxiliar_ll_size);
        }
        if(command == "--dates"){
            cout << "======== MOST VULNERABLE WEEK OF THE YEAR =====" << endl;
            most_vulnerable_week(auxiliar_ll, weeks, auxiliar_ll_size);
        }

    }
    
    return 0;
};