#include<iostream>
#include<vector>
#include<filesystem>

using namespace std;

struct Command
{
    string name;
    string description;
};
class CLI
{
public:
    CLI();
    void run();
private:

    //filesytem 
    void commandVersion();
    void commandFounder();
    void commandPwd();
    void commandLs();
    void commandCd(const vector<string>& args);
    void commandMkdir(const vector<std::string>& args);

    //others normal
    void registerCommands(); // 
    void processCommand(const string& input);
    void commandClear();
    void commandHelp(); // show the commands 
    void commandStatus();
    void commandEcho(const vector<string> & args);

    vector<string> parseCommand(const string& input); // a whole line into words and store in vecotr

    /*
    its just a good if you write variables at bottom cause class is read from the bottom by 
     compilers
    */ 
    vector<Command> commands; // eg. help status echo exit;
};