void help(){
    cout << endl;
    cout << "-h or --help       :   to acces ussage parameters or comments." << endl;
    cout << "-f or --file       :   for setting the route and name of the file." << endl;
    cout << "                       example:    main.exe -f route/documentName.txt" << endl;
    cout << "-d or --directions :   command to get the most breached directions. Input number of directions to be retrieved." << endl;
    cout << "                       example:    main.exe -f [...] -d 5   (returns five directions)." << endl;
    cout << "--frequency        :   returns the frequency of each message." << endl;
    cout << "                       example:    main.exe -f [...] --frequency" << endl;
    cout << "-a or --attacked   :   returns number of attacked ports." << endl;
    cout << "                       example:    main.exe -f [...] -a" << endl;
    cout << "-d or --dates      :   returns days wiht more breaches per week." << endl;
    cout << "                       example:    main.exe -f [...] -d" << endl;
    cout << "\nYou can actually set various commands at the same run, for example:" << endl;
    cout << "main.exe -f route/fileName.txt -d 5 --frequency -a -d" << endl;
}

