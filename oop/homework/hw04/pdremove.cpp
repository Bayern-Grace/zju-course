#include "diary.h"
using namespace std;

vector<struct page> D;

int main(int argc, char* argv[])
{
    Read();
    string str;
    str = argv[1]; //store the date
    int i, size = D.size();
    for (i = 0; i < size; i++) //seak the corresponding date
    {
        if (D[i].date == str) //have found the coresponding date
        {
            D.erase(D.begin() + i, D.begin() + i + 1); //remove from diary
            Write();
            return 0;
        }
    }
    return -1;
}