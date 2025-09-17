#include <iostream>
#include <fstream>

#include <stdio.h>
#include <string>

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

int add_msg(string msg){
    
    return 0
}

int main() {
    string log_path = "./chat.log";

    ifstream log(log_path);
    string line;
    while (getline(log, line)){
        print_line(line);
    }
    log.close();
    return 0;
};
