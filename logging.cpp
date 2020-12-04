#include <iostream>

using namespace std;

static class Logger
{
public:
	static void info(const string& message)
	{
		cout << "[info] " << message << endl;
	}
	static void error(const string& message)
	{
		cout << "[error] " << message << endl; 
	}
};