#include <sstream>
#include<string>
#include"cli.h"

    CLI::CLI()
    {
        registerCommands();
    }
    void CLI::run()
    {
        string input;
        cout << "************Devloper Mode**************" << endl;
        while(true)
        {
            cout << "dev > ";
            if(!getline(cin,input))
            {
                break;
            }

            if(input.empty())
            {
                continue;
            }

            if(input == "exit")
            {
                cout << "THanks for using my program \n";
                break;
            }
            processCommand(input);
        }
    }

    void CLI::registerCommands()
    {
        commands.push_back({"help", "show available command"});
        commands.push_back({"status", "show CLI status"});
        commands.push_back({"echo", "print the text"});
        commands.push_back({"clear", "clear the screen"});
        commands.push_back({"exit", "exit the program"});
        commands.push_back({"ls", "list the directory inthe sys"});
        commands.push_back({"mkdir", "makes the directory inside the file"});
        commands.push_back({"pwd", "show the current directory"});

    }

    void CLI::processCommand(const string& input)
    {
        vector<string> args = parseCommand(input);

        if(args.empty())
        {}
        string command = args[0];

        if(command == "help")
        {
            commandHelp();
        }
        else if(command == "status")
        {
           commandStatus();
        }
       else if(command == "clear")
        {
           commandClear();
        }
        else if(command == "echo")
        {
            commandEcho(args);
        }
        else if(command == "pwd")
        {
            commandPwd();
        }
        else if(command == "ls")
        {
            commandLs();
        }
        else if(command == "mkdir")
        {
            commandMkdir(args);
        }
        else
        {
            cout << "check for help \n";
        }
    }
   
    void CLI::commandPwd()
    {
        cout << filesystem::current_path() << '\n';
    }

    void CLI::commandLs()
    {
        for(const auto& entry : filesystem::directory_iterator(filesystem::current_path()))
        {
            cout << entry.path().filename().string() << ' ';
        }
        cout << '\n';
    } 

     void CLI::commandMkdir(const vector<std::string>& args)
    {
        if(args.size() < 2)
        {
            cout << "Usage:  mkdir <directory> \n";

            return;
        }
        try
        {
            if(filesystem::create_directory(args[1]))
            {
                cout <<"Directory created. \n";
            }
            else
            {
                cout <<"Directory already exist . \n";

            }
        }
        catch(const filesystem::filesystem_error& error)
        {
            cout << error.what() << '\n';
        }
    } 
    void CLI::commandClear()
    {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    void CLI::commandHelp()
    {
        cout << "Available Command \n";
        for(const Command & command :commands)
        {
            cout << " " << command.name << "---" << command.description << "\n";
        }

        cout << "\n";
    }

    void CLI::commandStatus()
    {
        cout << " its running man \n";
        cout << "Everything going good \n";
    }

    vector<string> CLI::parseCommand(const string& input)
    {
        vector<string> args;

        stringstream stream(input);

        string word;

        while (stream >> word)
        {
            args.push_back(word);
        }

        return args;
    }

    void CLI::commandEcho(const vector<string> & args)
    {   
        for(size_t i = 1; i <args.size(); ++i)
        {
            cout << args[i];
            
            if(i +1 < args.size())
            {
                cout << " ";
            }
        }

        cout << "\n";

    }