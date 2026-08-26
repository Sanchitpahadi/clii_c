#include<iostream>
#include<vector>
#include<filesystem>
#include<functional>
#include<unordered_map>

using namespace std;

using CommandArgs =vector<string>;

using CommandHandler = function<void(const CommandArgs&)>;

struct Commands
{
    string name;
    string description;
    CommandHandler handler;
};

class SANC
{
public:
    SANC();
    void run();
private:

    //filesytem 
    void commandVersion(const CommandArgs& args);
    void commandFounder(const CommandArgs& args);
    void commandPwd(const CommandArgs& args);
    void commandLs(const CommandArgs& args);
    void commandCd(const CommandArgs& args);
    void commandMkdir(const CommandArgs& args);
    void commandClear(const CommandArgs& args);
    void commandHelp(const CommandArgs& args); // show the commands 
    void commandStatus(const CommandArgs& args);
    void commandEcho(const vector<string> & args);

    //others normal
    void registerCommands(); // 
    void processCommand(const string& input);


    void registerCommands(const string& name , const string& description , CommandHandler handler);
    
    vector<string> parseCommand(const string& input); // a whole line into words and store in vecotr

    /*
    its just a good if you write variables at bottom cause class is read from the bottom by 
     compilers
    */ 
    unordered_map<string,Commands> command;
};