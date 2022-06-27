#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct page
{
    string date, content;
};

void Read(void); //read from diary
void Write(void); //write into diary