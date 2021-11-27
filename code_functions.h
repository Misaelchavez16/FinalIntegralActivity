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



// split function
void split(string line, string & month, string & day, string & hour, string & ip, string & reason){
  stringstream ss(line);// object to stream the variable
  string word;          // variable to store each word in large string

  string reason_str;    // string to concatenate reason

  int counter = 1;      // to check position of word
  while(ss>>word){
    
    switch(counter){
      case 1:
        month = word;   // modify month variable
        break;
      case 2:
        day = word;     // modify day variable
        break;
      case 3:
        hour = word;    // modify hour variable
        break;
      case 4:
        ip = word;      // modify ip variable
        break;
    }
    if(counter >= 5) reason_str += " " + word; // concatenating reason
    counter ++;
  }
  reason = reason_str;
}
// function to read each line of txt
void read_file(string fileName, LinkedList<Server> & auxiliar_ll){
  fstream txt_file;                                // creating an SStream object
  txt_file.open(fileName, ios::in);          // opening bitacora file in input mode


  // server atributes definition
  string month, day, hour, ip, reason;

  if(txt_file.is_open()){                          // checking wether the file is open or not
    string line;                                   // variable to store the line
    while(getline(txt_file, line)){
      split(line, month, day, hour, ip, reason);  // splitting each line of txt and adding to
                                                  // corresponding variable.
      auxiliar_ll.addLast(Server(month, stoi(day), hour, ip, reason));
    }
    txt_file.close();                             // closing connection to bitacora file
  }

}


void most_breached_ips(LinkedList<Server> s, int & size_ll, int num_directions = 5){
    Hashtable<string, int> directions(size_ll/2);
    vector<string> the_ips;
    while(!s.is_empty()){
        string direction_ip = s.pop().ip;
        string delimiter = ":";
        direction_ip = direction_ip.substr(0, direction_ip.find(delimiter));
        if(!directions.contains_key(direction_ip)) {
            directions.put(direction_ip, 1);
            the_ips.push_back(direction_ip);
        }
        else directions.add_value(direction_ip, 1);
    } 

    LinkedList<string> the_stack = LinkedList<string>();
    string auxiliar_interator_string = the_ips[0];
    int auxiliar_interator_int = 0, auxiliar_index;
    while(the_stack.length() != num_directions){
        auxiliar_interator_string = the_ips[0];
        auxiliar_interator_int = 0;
        for(int i = 0; i < the_ips.size(); i++){
            if(directions.get(the_ips[i]) > auxiliar_interator_int){
                auxiliar_interator_int = directions.get(the_ips[i]);
                auxiliar_interator_string = the_ips[i];
                auxiliar_index = i;
            }
        }
        // cout << "===================="<<auxiliar_interator_string << "," <<the_ips.size()<< endl;
        // for(int j = 0; j < the_ips.size(); j++){
        //     cout << the_ips[j] << endl;
        // }
        cout << auxiliar_interator_string << " : " << auxiliar_interator_int << endl;
        the_ips.erase(the_ips.begin() + auxiliar_index);
        the_stack.queue(auxiliar_interator_string);
    }

}




// template<typename T>
// class Container{
//     private:
//     protected:
//     public:
//         string ip;
//         int occurrence;

//         friend ostream& operator <<(ostream & salida, const Container<T>&contenedor){
//             salida << contenedor.ip << "->" << contenedor.occurrence << endl;
//             return salida;
//         }
//         int operator + (const Container<T>& c){
//           return c.occurrence + occurrence;  
//         }
//         int operator - (const Container<T>&c){
//             return c.occurrence - occurrence;
//         }
//         void operator += (const Container<T>&c){
//             occurrence += c.occurrence;
//         }
//         void operator ++(){
//             occurrence += 1;
//         }
//         bool operator == (const Container<T>&c){
//             return occurrence == occurrence
//         }

// };