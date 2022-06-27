#include "binSerialization.hpp"
#include <iomanip>

using namespace binSerialization;

struct UserDefinedType { //user defined type
    int idx;
    string name;
    vector<double> data;
    UserDefinedType() {}
    UserDefinedType(int a, string b, double c, double d, double e) //ctor
    {
        idx = a;
        name = b;
        data.push_back(c);
        data.push_back(d);
        data.push_back(d);
    }
    ~UserDefinedType() {}
    bool operator== (UserDefinedType& b) //overload operator '=='
    {
        if (idx != b.idx)
            return false;
        if (name != b.name)
            return false;
        if (data != b.data)
            return false;
        return true;
    }
};

void code(stringstream& s, UserDefinedType x); //serialization for user defined type
void decode(stringstream& s, UserDefinedType& x); //serialization for user defined type

//tests for all types
void bool_test();
void short_test();
void int_test();
void long_test();
void float_test();
void double_test();
void char_test();
void string_test();
void vector_test();
void map_test();
void set_test();
void list_test();
void pair_test();
void UserDefinedType_test();

int main()
{
    bool_test();
    short_test();
    int_test();
    long_test();
    float_test();
    double_test();
    char_test();
    string_test();
    vector_test();
    map_test();
    set_test();
    list_test();
    pair_test();
    UserDefinedType_test();
}

void bool_test()
{
    bool a(true);
    string file("../bin_test/bool_test.data"); //specified document address
    Serialize(a, file); //serialize bool type into the file
    bool b;
    Deserialize(b, file); //deserialize bool type from file to b
    cout << "Bool type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        cout << "Bool type serializes successfully! a: " << a << ", b: " << b << endl << endl;
    else
        cout << "Bool type serialization fails! a: " << a << ", b: " << b << endl << endl;
}

void short_test()
{
    short a(17);
    string file("../bin_test/short_test.data"); //specified document address
    Serialize(a, file); //serialize short type into the file
    short b;
    Deserialize(b, file); //deserialize short type from file to b
    cout << "Short type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        cout << "Short type serializes successfully! a: " << a << ", b: " << b << endl << endl;
    else
        cout << "Short type serialization fails! a: " << a << ", b: " << b << endl << endl;
}

void int_test()
{
    const int a(40000);
    string file("../bin_test/int_test.data"); //specified document address
    Serialize(a, file); //serialize int type into the file
    int b;
    Deserialize(b, file); //deserialize int type from file to b
    cout << "Int type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        cout << "Int type serializes successfully! a: " << a << ", b: " << b << endl << endl;
    else
        cout << "Int type serialization fails! a: " << a << ", b: " << b << endl << endl;
}

void long_test()
{
    long long a(3000000000);
    //as the size of long on the 32-bits is different from it on the 64-bits, I use long long type instead
    //although the function name is still "long_test"
    //3000000000 exceeds the maximum of int 
    string file("../bin_test/long_test.data"); //specified document address
    Serialize(a, file); //serialize long type into the file
    long long b;
    Deserialize(b, file); //deserialize long type from file to b
    cout << "Long type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        cout << "Long type serializes successfully! a: " << a << ", b: " << b << endl << endl;
    else
        cout << "Long type serialization fails! a: " << a << ", b: " << b << endl << endl;
}

void float_test()
{
    float a(1.5);
    string file("../bin_test/float_test.data"); //specified document address
    Serialize(a, file); //serialize float type into the file
    float b;
    Deserialize(b, file); //deserialize float type from file to b
    cout << "Float type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        cout << "Float type serializes successfully! a: " << a << ", b: " << b << endl << endl;
    else
        cout << "Float type serialization fails! a: " << a << ", b: " << b << endl << endl;
}

void double_test()
{
    double a(3.12345678); //exceed the precision of float
    string file("../bin_test/double_test.data"); //specified document address
    Serialize(a, file); //serialize double type into the file
    double b;
    Deserialize(b, file); //deserialize double type from file to b
    cout << "Double type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        cout << "Double type serializes successfully! a: " << setprecision(10) << a << ", b: " << setprecision(10) << b << endl << endl;
    else
        cout << "Double type serialization fails! a: " << setprecision(10) << a << ", b: " << setprecision(10) << b << endl << endl;
}

void char_test()
{
    char a('#');
    string file("../bin_test/char_test.data"); //specified document address
    Serialize(a, file); //serialize char type into the file
    char b;
    Deserialize(b, file); //deserialize char type from file to b
    cout << "Char type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        cout << "Char type serializes successfully! a: " << a << ", b: " << b << endl << endl;
    else
        cout << "Char type serialization fails! a: " << a << ", b: " << b << endl << endl;
}

void string_test()
{
    string a("Hello world");
    string file("../bin_test/string_test.data"); //specified document address
    Serialize(a, file); //serialize string type into the file
    string b;
    Deserialize(b, file); //deserialize string type from file to b
    cout << "String type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        cout << "String type serializes successfully! a: " << a << ", b: " << b << endl << endl;
    else
        cout << "String type serialization fails! a: " << a << ", b: " << b << endl << endl;
}

void vector_test()
{
    std::vector<std::vector<int>> a{{1,2,3}, {4,5,6}, {7,8,9}};
    string file("../bin_test/vector_test.data"); //specified document address
    Serialize(a, file); //serialize vector type into the file
    std::vector<std::vector<int>> b;
    Deserialize(b, file); //deserialize vector type from file to b
    cout << "Vector type test: ";
    if (a == b) //judge whether serialization and deserialization are correct, and print both of them
        cout << "Vector type serializes successfully! a:";
    else
        cout << "Vector type serialization fails! a:";
    //print both a and b
    for (auto i = a.begin(); i != a.end(); i++)
        for (auto k = i->begin(); k != i->end(); k++)
        cout << " " << *k;
    cout << ", b:";
    for (auto i = b.begin(); i != b.end(); i++)
        for (auto k = i->begin(); k != i->end(); k++)
        cout << " " << *k;
    cout << endl << endl;
}

void map_test()
{
    map<string, int> a;
    a.insert(std::make_pair("wa", 1));
    a.insert(std::make_pair("wawa", 2));
    a.insert(std::make_pair("wawawa", 3));
    string file("../bin_test/map_test.data"); //specified document address
    Serialize(a, file); //serialize map type into the file
    map<string, int> b;
    Deserialize(b, file); //deserialize map type from file to b
    cout << "Map type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        cout << "Map type serializes successfully! a:";
    else
        cout << "Map type serialization fails! a:";
    //print both a and b
    for (auto i = a.begin(); i != a.end(); i++)
        cout << " <" << i -> first << ", " << i -> second << ">";
    cout << ", b:";
    for (auto i = b.begin(); i != b.end(); i++)
        cout << " <" << i -> first << ", " << i -> second << ">";
    cout << endl << endl;
}

void set_test()
{
    set<double> a{1.23, 2.34, -5.67, 3.14};
    string file("../bin_test/set_test.data"); //specified document address
    Serialize(a, file); //serialize set type into the file
    set<double> b;
    Deserialize(b, file); //deserialize set type from file to b
    cout << "Set type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        cout << "Map type serializes successfully! a:";
    else
        cout << "Map type serialization fails! a:";
    //print both a and b
    for (auto i = a.begin(); i != a.end(); i++)
        cout << *i << " ";
    cout << ", b:";
    for (auto i = b.begin(); i != b.end(); i++)
        cout << *i << " ";
    cout << endl << endl;
}

void list_test()
{
    std::list<string> a{"abc", "def", "ghijk"};
    string file("../bin_test/list_test.data"); //specified document address
    Serialize(a, file); //serialize list type into the file
    std::list<string> b;
    Deserialize(b, file); //deserialize list type from file to b
    cout << "List type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        cout << "List type serializes successfully! a:";
    else
        cout << "List type serialization fails! a:";
    //print both a and b
    for (auto i = a.begin(); i != a.end(); i++)
        cout << *i << " ";
    cout << ", b:";
    for (auto i = b.begin(); i != b.end(); i++)
        cout << *i << " ";
    cout << endl << endl;
}

void pair_test()
{
    pair<string, int> a;
    a = make_pair("wawawa", 3); 
    string file("../bin_test/pair_test.data"); //specified document address
    Serialize(a, file); //serialize pair type into the file
    pair<string, int> b;
    Deserialize(b, file); //deserialize pair type from file to b
    cout << "Pair type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        cout << "Pair type serializes successfully! a: <" << a.first << ", " << a.second << ">, b: <" << b.first << ", " << b.second << ">\n\n";
    else
        cout << "Pair type serialization fails! a: <" << a.first << ", " << a.second << ">, b: <" << b.first << ", " << b.second << ">\n\n";
}

void UserDefinedType_test()
{
    struct UserDefinedType a(9, "tzh", 3.14, 4.5, -1.2);
    string file("../bin_test/UserDefinedType_test.data"); //specified document address
    Serialize(a, file); //serialize user defined type into the file
    struct UserDefinedType b;
    Deserialize(b, file); //deserialize user defined type from file to b
    cout << "UserDefinedType test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        cout << "UserDefinedType type serializes successfully! a{ ";
    else
        cout << "UserDefinedType serialization fails! a{ ";
    //print both a and b
    cout << "idx: " << a.idx << ", name: " << a.name << ", data: ";
    for (auto i = a.data.begin(); i != a.data.end(); i++)
        cout << *i << " ";
    cout << "}, b{ ";
    cout << "idx: " << b.idx << ", name: " << b.name << ", data: ";
    for (auto i = b.data.begin(); i != b.data.end(); i++)
        cout << *i << " ";
    cout << "}";
}

void code(stringstream& s, UserDefinedType x)
{
    //for each member, call their own serialization function
    code(s, x.data);
    code(s, x.idx);
    code(s, x.name);
}
void decode(stringstream& s, UserDefinedType& x)
{
    //for each member, call their own deserialization function
    decode(s, x.data);
    decode(s, x.idx);
    decode(s, x.name);
}