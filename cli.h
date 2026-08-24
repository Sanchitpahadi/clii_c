#include<iostream>

using namespace std;

class CLI
{
public:
    void run();
private:
    void processCommand(const string& command);
};