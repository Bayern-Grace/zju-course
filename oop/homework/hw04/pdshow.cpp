#include "diary.h"
using namespace std;

vector<struct page> D;

int main(int argc, char* argv[])
{   
    Read();
    string str;
    str = argv[1]; //store the given date
    vector<struct page>::iterator it;
    for (it = D.begin(); it != D.end(); it++)
    {
        if (it -> date == str) //find the given date
        {
            cout << it -> content << endl; //output its content
            return 0;
        }
    }
    cout << "Not found!" << endl; //cannot find the given date
    return 0;
}