#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct student
{
    int id, num; // num represents the number of courses
    string name;
    vector<string> course;
    vector<int> grade;
};
vector<struct student> stu;
vector<string> maincourse; // collection of all the course names

int Readfile(void);      // read file
void Printgrade(void);   // print lines of grades
void Printmax(void);     // print the line of max grades
void Printmin(void);     // print the line of min grades
void Printaverage(void); // print the line of average grades
double Average(int n);   // calculate the average grade
int Min(string str);     // seak for the min grade
int Max(string str);     // seak for the max grade

int main()
{
    if (Readfile()) //if it fails to open the file, it will return 0 and the program will end.
    {
        Printgrade();
        Printaverage();
        Printmin();
        Printmax();
    }
    return 0;
}

int Readfile(void)
{
    int i;
    string str;
    ifstream file("sample1.txt"); // read file
    if (!file.is_open())
    {
        cout << "Cannot open the file!" << endl; // fail to open the file
        return 0;
    }
    while (file >> i) // if file isn't over, program will get into the loop
    {
        struct student temp;
        temp.id = i;       // store id
        file >> temp.name; // store name
        file >> temp.num;  // store the number of courses
        for (int k = 0; k < temp.num; k++)
        {
            file >> str >> i;
            temp.course.push_back(str); // store the ith course name
            temp.grade.push_back(i);    // store the ith grade
            vector<string>::iterator it;
            int flag = 1;                                              // flag == 1 represents that the course name has appeared
            for (it = maincourse.begin(); it < maincourse.end(); it++) // traverse the vector to judge whether course name has appeared
            {
                if ((*it) == str) // course name has appeared
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                maincourse.push_back(str); // add the course name
        }
        stu.push_back(temp); // add the record
    }
    return 1;
}

void Printgrade(void)
{
    cout << "no    name    "; // print the title
    vector<string>::iterator t;
    for (t = maincourse.begin(); t < maincourse.end(); t++)
        cout << (*t) << "  "; // print the course name in turn
    cout << "average" << endl;
    int i, k;
    for (i = 0; i < stu.size(); i++)
    {
        cout << setiosflags(ios::left) << setw(6) << stu[i].id << setw(8) << stu[i].name;
        // print student's id and name
        for (t = maincourse.begin(); t < maincourse.end(); t++)
        {
            int flag = 0;
            for (k = 0; k < stu[i].num; k++)
            {
                if (stu[i].course[k] == (*t)) // traverse to judge whether the student has this course
                {
                    flag = 1; // flag == 1 represents that the student has this course
                    break;
                }
            }
            if (flag)
                cout << setiosflags(ios::left) << setw((*t).length() + 2) << stu[i].grade[k];
            // if student has this course, print the grade
            else
                cout << setiosflags(ios::left) << setw((*t).length() + 2) << "-";
            // if student doesn't have this course, print -
        }
        cout << Average(i) << endl;
        // print the average grade
    }
}

void Printaverage(void)
{
    int size = maincourse.size(); // store the number of all the course
    cout << "      average ";     // print title
    for (int i = 0; i < size; i++)
        cout << setiosflags(ios::left) << setw(maincourse[i].length() + 2) << Average(-i - 1);
    // traverse to print each course's average grade
    cout << endl;
}

void Printmax(void)
{
    vector<string>::iterator it;
    cout << "      max     "; // print title
    for (it = maincourse.begin(); it < maincourse.end(); it++)
        cout << setiosflags(ios::left) << setw((*it).length() + 2) << Max((*it));
    // traverse to print each course's max grade
    cout << endl;
}

void Printmin(void)
{
    vector<string>::iterator it;
    cout << "      min     "; // print title
    for (it = maincourse.begin(); it < maincourse.end(); it++)
        cout << setiosflags(ios::left) << setw((*it).length() + 2) << Min((*it));
    // traverse to print each course's min grade
    cout << endl;
}

double Average(int n)
{
    double s = 0;
    if (n >= 0) // n > 0 represents that it calculates the average grade of a student
    {
        for (int i = 0; i < stu[n].num; i++)
            s += stu[n].grade[i]; // traverse to add grades
        s = s * 1.0 / stu[n].num; // calculate the average grade
    }
    else // n <= 0 represents that it calculates the average grade of a course
    {
        int number = 0, flag, i; // number stores the number of students who have this course
        vector<struct student>::iterator it;
        for (it = stu.begin(); it < stu.end(); it++)
        {
            flag = 0;
            for (i = 0; i < (*it).num; i++)
            {
                if ((*it).course[i] == maincourse[-n - 1])
                {
                    flag = 1; // flag == 1 represents that the student has this course
                    break;
                }
            }
            if (flag)
            {
                number++; // add the number of students who have this course
                s += (*it).grade[i];
            }
        }
        s = s * 1.0 / number; // calculate the average grade
    }
    return s;
}

int Max(string str)
{
    int max = 0, i, flag;
    vector<struct student>::iterator it;
    for (it = stu.begin(); it < stu.end(); it++) // traverse all the students
    {
        flag = 0;
        for (i = 0; i < (*it).num; i++)
        {
            if ((*it).course[i] == str)
            {
                flag = 1; // flag == 1 represents that the student has this course
                break;
            }
        }
        if (flag)
            if (max < (*it).grade[i])
                max = (*it).grade[i]; // store the max grade
    }
    return max;
}

int Min(string str)
{
    int min = 100, i, flag;
    vector<struct student>::iterator it;
    for (it = stu.begin(); it < stu.end(); it++) // traverse all the students
    {
        flag = 0;
        for (i = 0; i < (*it).num; i++)
        {
            if ((*it).course[i] == str) // flag == 1 represents that the student has this course
            {
                flag = 1;
                break;
            }
        }
        if (flag)
            if (min > (*it).grade[i])
                min = (*it).grade[i]; // store the min grade
    }
    return min;
}