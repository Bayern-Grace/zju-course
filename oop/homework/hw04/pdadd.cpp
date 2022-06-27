#include "diary.h"
using namespace std;

vector<struct page> D;

int main(int argc, char* argv[])
{
    Read();
    string dat, con(""), str("");
    dat = argv[1]; //store date
    while (getline(cin, str)) //judge whether read EOF
    {
        if (str == ".") //judge whether read '.'
            break;
        con += str + "\n"; //add the 'enter' character
    }
    con += "."; //add '.' to the end, as the diary requires each page is ended with a line with a single '.'
    struct page p;
    p.date = dat;
    p.content = con;
    int i, size = D.size();
    for (i = 0; i < size; i++) //seak the correct positon, as the diary is in time order
        if (D[i].date >= p.date) //find the correct position
            break;
    if (D[i].date == p.date)
        D[i].content = p.content;
    else
        D.insert(D.begin() + i, p); //insert into vector D
    Write();
    return 0;
}