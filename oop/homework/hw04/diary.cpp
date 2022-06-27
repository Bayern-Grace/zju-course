#include "diary.h"
using namespace std;

extern vector<struct page> D; //vector<struct page> D is defined in implementation cpp files

void Read(void)
{
    ifstream f("diary.txt"); //read diary
    if (!f.is_open()) //fail to read diary
    {
        cout << "Cannot open the file!" << endl;
        return ;
    }
    string con(""), str(""); //str is the each line of input, con consists of str
    struct page p;
    while (!f.eof())
    {
        con = "";
        f >> p.date; //read date
        getline(f, str); //read the left blank of the date line
        getline(f, str); //read the first line of content
        while (str != ".") //all content of each diary is ended with a line with a single '.'
        {
            con += str; //join the newly read content to the read content
            con += "\n"; //add the 'enter' character
            getline(f, str); //read next line
        }
        con += str; //add the '.'
        p.content = con;
        D.push_back(p); //push the page into diary
    }
    f.close(); //close the file
}

void Write(void)
{
    ofstream f("diary.txt"); //open file
    if (!f.is_open()) //fail to open
    {
        cout << "Cannot open the file!" << endl;
        return ;
    }
    vector<struct page>::iterator it;
    int i, size = D.size(); //calculate the number of pages in the diary
    for(i = 0; i < size - 1; i++)
        f << D[i].date << endl << D[i].content << endl; //write each page into the file
    f << D[i].date << endl << D[i].content; //the last page do not need a 'enter' charater
    f.close(); //close tht file
}