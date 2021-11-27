

class Server{
  private:
    string  month;      // three letter format : sep
    int     day;        // dd format
    string  hour;       // "hh:mm:ss" format
    string  ip;         // "###.###.###.###:#####" format
    string reason;      // failing reason
  public:
    Server(string month="jan", int day=1, string hour="00:00:00", string ip="192.169.1.1", string reason="save"){
      this->month   = month;      //O(1)
      this->day     = day;        //O(1)
      this->hour    = hour;       //O(1)
      this->ip      = ip;         //O(1)
      this->reason  = reason;    //O(1)
    }

    // GETTERS
    string getMonth(){
      return month;   //O(1)
    }
    int getDay(){
      return day;     //O(1)
    }
    string getHour(){
      return hour;    //O(1)
    }
    string getIp(){
      return ip;      //O(1)
    }
    string getReason(){
      return reason;  //O(1)
    }

    // SETTERS
    void setMonth(string month){
      this->month   = month;    //O(1)
    }
    void setDay(int day){
      this->day     = day;      //O(1)
    }
    void setHour(string hour){
      this->hour    = hour;     //O(1)
    }
    void setIp(string ip){
      this->ip      = ip;       //O(1)
    }
    void setReason(string reason){
      this->reason = reason;    //O(1)
    }
};