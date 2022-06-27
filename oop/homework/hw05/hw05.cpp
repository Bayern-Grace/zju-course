#include <iostream>
#include <cstring>
#include <string>
#include <math.h>

using namespace std;

class fraction
{
public:
    int numerator, denominator;
    fraction() : numerator(0), denominator(1) {} // default ctor, the default numerator is 0, default denominator is 1
    fraction(int k, int j)                       // ctor takes two integers as parameters
    {
        int flag = 1, common = divide(abs(k), abs(j)); //find the greatest common divisor
        if (j == 0) //denominator = 0, restore to default values
        {
            k = 0;
            j = 1;
        }
        if (k * j < 0)
            flag = -1;
        numerator = abs(k) * flag / common;
        denominator = abs(j) / common; //guarantee denominator is positive, only numerator has sign
    }
    fraction(const fraction &f) //copy ctor
    {
        numerator = f.numerator;
        denominator = f.denominator;
    }
    fraction(const string &s) // conversion from a finite decimal string
    {
        int i, l = s.length(), new_numerator, new_denominator;
        for (i = l - 1; i >= 0; i--)
            if (s[i] == '.') //find the location of '.'
                break;
        string a;
        a = s.substr(0, i) + s.substr(i + 1, l - i); //delete '.'
        new_numerator = stoi(a); //calculate the numerator before the divisor
        new_denominator = pow(10, l - i - 1);
        int common = divide(abs(new_numerator), abs(new_denominator)); //find the greatest common divisor
        numerator = new_numerator / common; //calculate the real numerator
        denominator = new_denominator / common;
    }
    fraction operator+(const fraction &f)
    {
        fraction newf;
        int new_numerator, new_denominator, common;
        new_numerator = numerator * f.denominator + f.numerator * denominator; //calculate the numerator before the divisor
        new_denominator = denominator * f.denominator;
        common = divide(new_numerator, new_denominator);//find the greatest common divisor
        newf.numerator = new_numerator / common;//calculate the real numerator
        newf.denominator = new_denominator / common;
        return newf;
    }
    fraction operator-(const fraction &f)
    {
        int new_denominator, common, new_numerator;
        fraction newf;
        new_denominator = denominator * f.denominator;
        new_numerator = numerator * f.denominator - f.numerator * denominator;//calculate the numerator before the divisor
        common = divide(new_numerator, new_denominator);//find the greatest common divisor
        newf.numerator = new_numerator / common;//calculate the real numerator
        newf.denominator = new_denominator / common;
        return newf;
    }
    fraction operator*(const fraction &f)
    {
        fraction newf;
        int new_numerator, new_denominator, common;
        new_numerator = numerator * f.numerator;//calculate the numerator before the divisor
        new_denominator = denominator * f.denominator;
        common = divide(new_numerator, new_denominator);//find the greatest common divisor
        newf.numerator = new_numerator / common;//calculate the real numerator
        newf.denominator = new_denominator / common;
        return newf;
    }
    fraction operator/(const fraction &f)
    {
        int new_numerator, new_denominator, common;
        fraction newf;
        new_numerator = numerator * f.denominator;//calculate the numerator before the divisor
        new_denominator = denominator * f.numerator;
        common = divide(new_numerator, new_denominator);//find the greatest common divisor
        newf.numerator = new_numerator / common;//calculate the real numerator
        newf.denominator = new_denominator / common;
        return newf;
    }
    bool operator==(const fraction &f) const
    {
        if (numerator == f.numerator && denominator == f.denominator) //all fractions are reduced to their simplest form
            return true;                                              //so we can only compare their numerators and denominators
        return false;
    }
    bool operator!=(const fraction &f) const
    {
        return !(*this == f); //use '==' to judge unequal
    }
    bool operator<(const fraction &f) const
    {
        int a_numerator, b_numerator;
        a_numerator = numerator * f.denominator; 
        b_numerator = denominator * f.numerator;
        if (a_numerator < b_numerator) //the numerator of a is smaller than the numerator of b after making their denominator same
            return true;
        return false;
    }
    bool operator<=(const fraction &b) const
    {
        if (*this < b || *this == b) //use '<' and '==' to judge whether a less than or equal to b
            return true;
        return false;
    }
    bool operator>(const fraction &b) const
    {
        return !(*this <= b); //use '<=' to judge whether a is larger than b
    }
    bool operator>=(const fraction &b) const
    {
        return !(*this < b); //use '<' and to judge whether a larger than or equal to b
    }
    operator double() const
    {
        return numerator / (double)denominator; //type conversion to double
    }
    operator string() const
    {
        string a, b, c;
        a = to_string(numerator); //converse numerator to string
        b = to_string(denominator); //converse denominator to string
        c = a + string{'/'} + b; //add '/' between numerator and denominator
        return c;
    }
    int divide(int a, int b) //use toss and turn division to find the greatest common divisor
    {
        if (a == 0 || b == 0)
            return 1;
        if (a < b) //guarantee a is larger than or equal to b
        {
            int temp;
            temp = a;
            a = b;
            b = temp;
        }
        int r = a % b;
        while (r) //use toss and turn division
        {
            a = b;
            b = r;
            r = a % b;
        }
        return b;
    }
    ~fraction() {}
};

istream &operator>>(istream &in, fraction &f)
{
    in >> f.numerator >> f.denominator;
    if (f.denominator == 0)
    {
        cout << "Error!" << endl; //output Error
        f.numerator = 0; //restore default values
        f.denominator = 1;
        return in;
    }
    int flag = 1, common = f.divide(abs(f.numerator), abs(f.denominator));//find the greatest common divisor
    if (f.numerator * f.denominator < 0) //judge whether it is positive or negative
        flag = -1;
    f.numerator = abs(f.numerator) * flag / common;
    f.denominator = abs(f.denominator) / common;//guarantee denominator is positive, only numerator has sign
    return in;
}
ostream &operator<<(ostream &out, fraction &f)
{
    if (f.numerator % f.denominator == 0) //f is actually an integer
        out << f.numerator / f.denominator;
    else if (f.numerator * f.denominator > 0) //numerator and denominator have the same sign
        out << abs(f.numerator) << "/" << abs(f.denominator);
    else //numerator and denominator have different signs
        out << "-" << abs(f.numerator) << "/" << abs(f.denominator); 
    return out;
}

// Now I will show you some typical usages

int main()
{
    fraction a, b(2, 4); //default ctor and ctor with two parameters
    cout << "fraction a, b(2, 4)" << endl << "b: " << b << endl << "Please input fraction a: "; //output fraction
    cin >> a; //input fraction
    cout << "a: " << a << endl; //output fraction
    string s("1.414");
    fraction c = s, w("1.414"); //converse string to fraction
    cout << "string s(\"1.414\")" << endl << "conversion from string to fraction(c = s, fraction w(\"1.414\")): c = " << c << ", w = " << w << endl;
    s = (string)a; //converse string to fraction
    cout << "type cast to string(s = (string)a): s = " << s << endl;
    double y(2.5), z;
    z = y * a; //conversion from double to fraction
    cout << "type cast to double(double y(2.5), z = y * a): z = " << z << endl;
    cout << "Now we show the arithmetic operations of the fraction: a = " << a << ", b = " << b << endl;
    //show the arithmetic operations of the fraction
    c = a - b;
    cout << "c = a - b = " << c << endl;
    c = a + b;
    cout << "c = a + b = " << c << endl;
    c = a * b;
    cout << "c = a * b = " << c << endl;
    c = a / b;
    cout << "c = a / b = " << c << endl;
    cout << "Now we show the copy constructor: c = a, fraction d(a)" << endl;
    c = a;
    fraction d(a);
    //show the copy constructor 
    cout << "c: " << c << endl;
    cout << "d: " << d << endl;
    cout << "Now we show the comparison operators of the fraction: a = " << a << ", b = " << b << endl;
    //show the comparison operators of the fraction
    cout << "a < b: "; 
    if (a < b)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    cout << "a <= b: ";
    if (a <= b)
        cout << "True" << endl; 
    else
        cout << "False" << endl;
    cout << "a == b: ";
    if (a == b)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    cout << "a > b: ";
    if (a > b)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    cout << "a >= b: ";
    if (a >= b)
        cout << "True" << endl;
    else
        cout << "False" << endl;
    cout << "a != b: ";
    if (a != b)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}