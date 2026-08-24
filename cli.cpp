#include<string>
#include"cli.h"


void CLI::run()
{
    string command;
    cout << "Suprising Git Hub By pushing/start CLI in 1 AM" << endl;
    cout << "************Devloper Mode**************" << endl;
    while(true)
    {
        cout << "dev > ";
        getline(cin,command);

        if(command == "exit")
        {
            cout << "THanks for using my program \n";
            break;
        }
        processCommand(command);
    }
}

void CLI::processCommand(const string& command)
{
        if(command == "help")
        {
            cout << "Available Command \n";
            cout << " help \n";
            cout << " status \n";
            cout << " exit \n";
        }
        else if(command == "status")
        {
            cout << " its running man \n";
        }

        else
        {
            cout << "check for help \n";
        }
}