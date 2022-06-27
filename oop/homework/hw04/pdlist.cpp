#include "diary.h"
using namespace std;

vector<struct page> D;

int main(int argc, char* argv[])
{   
    Read();
    string date1("0"), date2("99999999"); //set the defaults
    if (argc == 3) //input gives the start date and the end date
    {
        date1 = argv[1]; //store the start date
        date2 = argv[2]; //store the end date
    }
    int i, size = D.size();
    bool find = false; //store whether the start date is out of range
    for (i = 0; i < size; i++)
    {
        if (D[i].date < date1) //before the start date
            continue;
        else
        {
            find = true; //the start date is in the range
            break;
        }
    }
    if (!find) //the start date is out of range 
        cout << "Not found!" << endl;
    else
    {
        for(i; i < size; i++)
        {
            if (D[i].date > date2) //find where the output ends
                break;
            cout << D[i].date << endl << D[i].content << endl;
        }
    }
    return 0;
}