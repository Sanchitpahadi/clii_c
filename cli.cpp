#include <sstream>
#include<string>
#include"cli.h"

    CLI::CLI()
    {
        registerCommands();
    }
    void CLI::registerCommands(const string& name , const string& description ,CommandHandler handler)
    {
        command[name] = Commands
        {
            name,
            description,
            handler
        };
    }

    void CLI::run()
    {
        string input;
        cout << "************Devloper Mode**************" << endl;
        while(true)
        {
            cout << "sanc"<< "<" << filesystem::current_path().string()<< "> -";
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
        
        registerCommands("help",
             "show available command", 
             [this](const auto& args)
            {
                commandHelp(args);
            }
            );
        
        registerCommands("status",
             "show CLI status",
                         [this](const auto& args)
            {
                commandStatus(args);
            }
        );
        
        registerCommands("echo",
             "print the text",
            [this](const auto& args)
            {
                commandEcho(args);
            }
            );
        
        registerCommands("clear",
             "clear the screen",
            [this](const auto& args)
            {
                commandClear(args);
            }
        );
       /*
            registerCommands("exit",
             "exit the program",
            [this](const auto& args)
            {
                commandExit(args);
            }
        );
       */ 

        
        registerCommands("ls",
             "list the directory inthe sys",
            [this](const auto& args)
            {
                commandLs(args);
            }
        );
    
        
        registerCommands("mkdir", 
            "makes the directory inside the file",
            [this](const auto& args)
            {
                commandMkdir(args);
            }
        );
        
        registerCommands("pwd",
             "show the current directory",
            [this](const auto& args)
            {
                commandPwd(args);
            }
            );
        
        registerCommands("cd",
            "change directory",
            [this](const auto& args)
            {
                commandCd(args);
            }
        );
        
        registerCommands("version",
            "which version You are in",
            [this](const auto& args)
            {
                commandVersion(args);
            }
        );
        
        registerCommands("founder", 
            "who created the great thing",
           [this](const auto& args)
            {
                commandFounder(args);
            }
        );


    }

    void CLI::processCommand(const string& input)
    {
        CommandArgs args = parseCommand(input);

        if(args.empty())
        {}
        string command = args[0];

        if(command == "help")
        {
            commandHelp(args);
        }
        else if(command == "status")
        {
           commandStatus(args);
        }
       else if(command == "clear")
        {
           commandClear(args);
        }
        else if(command == "echo")
        {
            commandEcho(args);
        }
        else if(command == "pwd")
        {
            commandPwd(args);
        }
        else if(command == "ls")
        {
            commandLs(args);
        }
        else if(command == "mkdir")
        {
            commandMkdir(args);
        }
        else if(command == "cd")
        {
            commandCd(args);
        }  
        else if(command == "version")
        {
            commandVersion(args);
        }
        else if(command == "founder")
        {
            commandFounder(args);
        }         
        else
        {
            cout << "check for help \n";
        }
    }
    
    void CLI::commandCd(const CommandArgs& args)
    {
        if(args.size() < 2)
        {
            cout << "Usage: cd <directory> \n";

            return;
        }
        try
        {
            filesystem::current_path(args[1]);
        }
        catch(const filesystem::filesystem_error& error)
        {
            cout << error.what() << '\n';
        }

    }
    void CLI::commandFounder(const CommandArgs& args)
    {
       cout <<
        R"(
           |\__/,|   (`\
          _.|o o  |_   ) )
        -(((---(((--------
               / \_/ \
              /        \
             /   sanc! \
            (___)   (___)
        )" << endl;
        cout<< "\n \n \n ";
        cout << "*-------------------------------*\n";
        cout << "| Never stopping until, stoped!!|\n";
        cout << "|               sanc            |\n";
        cout << "*-------------------------------*\n";
    }
    void CLI::commandVersion(const CommandArgs& args)
    {
    cout<<
       R"(            zzz
                     z
                   z
                  /\_/\
                 ( -.- )
                  )   (
                 (  Z  )
                  `---'
        )"
     <<endl;
        cout<< "\n";
       cout << "*--------------------------------------------------*\n";
       cout << "|  sanc just as baby phase - version - 0.1         |\n";
       cout << "*--------------------------------------------------*\n";
    }
    void CLI::commandPwd(const CommandArgs& args)
    {
        cout << filesystem::current_path() << '\n';
    }

    void CLI::commandLs(const CommandArgs& args)
    {
        for(const auto& entry : filesystem::directory_iterator(filesystem::current_path()))
        {
            cout << entry.path().filename().string() << ' ';
        }
        cout << '\n';
    } 

     void CLI::commandMkdir(const CommandArgs& args)
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
    void CLI::commandClear(const CommandArgs& args)
    {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }


    void CLI::commandHelp(const CommandArgs& args)
    {
        for(const auto& [name, cmd] : command)
        {
            cout << "  "
                 << name
                 << " --- "
                 << cmd.description
                 << '\n';
        }
    }
  

    void CLI::commandStatus(const CommandArgs& args)
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

    void CLI::commandEcho(const CommandArgs& args)
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