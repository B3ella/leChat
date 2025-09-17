#include <iostream>
#include <fstream>

#include <stdio.h>
#include <string>

#include <unistd.h>

using namespace std;

string get_name(string log_line){
    int start = log_line.find("|")+1;
    int end = log_line.find("|", start);
    int size = end - start;
    return log_line.substr(start, size);
}
string get_date(string log_line){
    int end = log_line.find("|");
    return log_line.substr(0, end);
}
string get_msg(string log_line){
    int start = log_line.find('"')+1;
    int end = log_line.find('"', start);
    int size = end - start;
    return log_line.substr(start, size);
}

int print_line(string log_line){
    string user = get_name(log_line);
    cout << user;
    cout << "\n";

    string msg = get_msg(log_line);
    cout << msg;
    cout << "\n";
    cout << "\n";
    return 0;
}

string stringfy(int value, int size){
  string str = to_string(value);
  if (str.length() >= size) {
    return str;
  }
  int pad_size = size - str.length();
  string pad = string(pad_size, '0');
  return pad + str;
}

string getdate(){
  time_t timestamp = time(&timestamp);
  struct tm today = *localtime(&timestamp);

  string year = to_string(1900 + today.tm_year);
  string month = stringfy(today.tm_mon + 1, 2);
  string day = stringfy(today.tm_mday, 2);
  string date = year + "-" + month + "-" + day;

  string hour = stringfy(today.tm_hour, 2);
  string minute = stringfy(today.tm_min, 2);
  string second = stringfy(today.tm_sec, 2);
  string time = hour + ":" + minute + ":" + second;

  string result = date + "(" + time + ")";
  return result;
}

int add_msg(string msg){
    string user = getlogin();
    string date = getdate();
    string line = date + "|" + user + "|" + "\"" + msg + "\"\n";

    string log_path = "./chat.log";


    ofstream outfile;
    ofstream log(log_path, ios_base::app);
    log << line;
    log.close();
    
    return 0;
}

int main() {
    string log_path = "./chat.log";

    add_msg("mensagemm");

    ifstream log(log_path);
    string line;
    while (getline(log, line)){
        print_line(line);
    }
    log.close();
    return 0;
};
