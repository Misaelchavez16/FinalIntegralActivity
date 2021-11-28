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
    cout << "--dates            :   returns days wiht more breaches per week." << endl;
    cout << "                       example:    main.exe -f [...] --dates" << endl;
    cout << "\nYou can actually set various commands at the same run, for example:" << endl;
    cout << "main.exe -f route/fileName.txt -d 5 --frequency -a -d" << endl;
};



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

};


void most_breached_ips( LinkedList<Server> s, Hashtable<string, int> & directions,const int & size_ll, int num_directions = 5){
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
        cout << auxiliar_interator_string << " : " << auxiliar_interator_int << endl;
        the_ips.erase(the_ips.begin() + auxiliar_index);
        the_stack.queue(auxiliar_interator_string);
    }

};


void message_frequency(LinkedList<Server> s, Hashtable<string,int> & sms_frequency,const int size_ll){
  while(!s.is_empty()){
    string sms = s.pop().reason;
        if(!sms_frequency.contains_key(sms)) {
            sms_frequency.put(sms, 1);
        }
        else sms_frequency.add_value(sms, 1);
  }
  cout << sms_frequency << endl;
};


string splitter(string to_split,char delimeter){
  string to_return;
  bool option = false;
  for(int i = 0; i < to_split.length(); i++){
    if(to_split[i] == ':') {option = true;continue;}
    if(option == true) to_return += to_split[i];
  }
  return to_return;
}

void count_briched_ports(LinkedList<Server> s, Hashtable<string, int> & attacked_ports,const int size_ll){
  string the_port;
  string ip_and_port;
  while(!s.is_empty()){
    ip_and_port = s.pop().ip;
    the_port = splitter(ip_and_port, ':');
    if(!attacked_ports.contains_key(the_port)) attacked_ports.put(the_port, 1);
  }
  cout << "attacket ports: " << attacked_ports.the_size() << "/" << size_ll << endl;
}


void most_vulnerable_week(LinkedList<Server> s, Hashtable<int, int> & weeks,const int size_ll){
  vector <string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
  LinkedList<string> the_months = LinkedList<string>();
  for(int i = 0; i < months.size(); i++){
    the_months.addLast(months[i]);
  }
  

  tm date = {};
  date.tm_year = 2020-1900;
  Server auxiliar_server;
  while(!s.is_empty()){
    auxiliar_server = s.pop();
    date.tm_mon = the_months.indexOf(auxiliar_server.month)-0;
    // cout << "month>>" << date.tm_mon<< endl;
    date.tm_mday = auxiliar_server.day-0;
    mktime(&date); 
    if(!weeks.contains_key(((date.tm_yday-date.tm_wday+7)/7)+1))weeks.put(((date.tm_yday-date.tm_wday+7)/7)+1, 1);
    else weeks.add_value(((date.tm_yday-date.tm_wday+7)/7)+1, 1);
  }
  // cout << weeks << endl;
  cout << "weeks of the year with more attacks: " ;weeks.print_highest();cout <<endl; 

  
};
