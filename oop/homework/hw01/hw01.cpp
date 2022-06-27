#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double average(int arr[][3], int n); //计算平均分
int max(int arr[][3], int n); //寻找最高分
int min(int arr[][3], int n); //寻找最低分

int main()
{
    string name[10]; //存储学生姓名
    int score[10][3]; //存储学生三门成绩
    cout << "Please enter 10 records of students:" << endl;
    for (int i = 0; i < 10; i++)
        cin >> name[i] >> score[i][0] >> score[i][1] >> score[i][2];
    cout << "no    name    score1 score2 score3 average" << endl; //输出表头
    for (int i = 0; i < 10; i++)
    {
        cout << setiosflags(ios:: left) << setw(6) << i + 1 << setw(8) << name[i]; //输出编号和姓名
        cout << setiosflags(ios:: left) << setw(7) << score[i][0] << setw(7) << score[i][1] << setw(7) << score[i][2] << average(score, i) << endl;
        //用左对齐和固定位宽格式化输出学生成绩和均分
    }
    cout << "      average " << setiosflags(ios:: left) << setw(7) << average(score, -1) << setw(7) << average(score, -2) << average(score, -3) << endl;
    cout << "      min     " << setiosflags(ios:: left) << setw(7) << min(score, 0) << setw(7) << min(score, 1) << min(score, 2) << endl; 
    cout << "      max     " << setiosflags(ios:: left) << setw(7) << max(score, 0) << setw(7) << max(score, 1) << max(score, 2) << endl;
    //用左对齐格式化输出每门课的均分，最低分和最高分
    return 0;
}

double average(int arr[][3], int n)
{
    double s = 0;
    if (n >= 0) // n >= 0表示计算某个学生三门课的均分
    {
        for (int i = 0; i < 3; i++)
            s += arr[n][i];
        s = s / 3.0;
    }
    else // n < 0表示计算某一门课的总均分
    {
        for (int i = 0; i < 10; i++)
            s += arr[i][-n - 1];
        s = s / 10.0;
    }
    return s;
}

int max(int arr[][3], int n) //n指定某一门课
{
    int max = 0;
    for (int i = 1; i < 10; i++)
    {
        if (arr[max][n] < arr[i][n])
            max = i; //记录最高分的下标
    }
    return arr[max][n];
}

int min(int arr[][3], int n) //n指定某一门课
{
    int min = 0;
    for (int i = 1; i < 10; i++)
    {
        if (arr[min][n] > arr[i][n])
            min = i; //记录最低分的下标
    }
    return arr[min][n];
}