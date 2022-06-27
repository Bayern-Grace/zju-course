#include "XML_Serialization.h"
#include <iomanip>
using namespace XML_Serialization;

struct UserDefinedType { //user defined type
    int idx;
    std::string name;
    std::vector<double> data;
    UserDefinedType() {}
    UserDefinedType(int a, std::string b, double c, double d, double e) //ctor
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

void code(UserDefinedType x, std::string name, XMLElement* roof, XMLDocument& doc); //serialization for user defined type
void decode(UserDefinedType& x, XMLNode* root); //serialization for user defined type
inline std::string judge(UserDefinedType x, std::string name); //judge whether it is the correct type
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
    std::string file("../XML_test/bool_test.xml"); //specified document address
    XML_Serialize(a, "bool", file); //serialize bool type into the file
    bool b;
    XML_Deserialize(b, "bool", file); //deserialize bool type from file to b
    std::cout << "Bool type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        std::cout << "Bool type serializes successfully! a: " << a << ", b: " << b << std::endl << std::endl;
    else
        std::cout << "Bool type serialization fails! a: " << a << ", b: " << b << std::endl << std::endl;
}

void short_test()
{
    short a(17);
    std::string file("../XML_test/short_test.xml");
    XML_Serialize(a, "short", file);
    short b;
    XML_Deserialize(b, "short", file);
    std::cout << "Short type test: ";
    if (a == b)
        std::cout << "Short type serializes successfully! a: " << a << ", b: " << b << std::endl << std::endl;
    else
        std::cout << "Short type serialization fails! a: " << a << ", b: " << b << std::endl << std::endl;
}

void int_test()
{
    int a(40000);
    std::string file("../XML_test/int_test.xml"); //specified document address
    XML_Serialize(a, "int", file); //serialize short type into the file
    int b;
    XML_Deserialize(b, "int", file); //deserialize short type from file to b
    std::cout << "Int type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        std::cout << "Int type serializes successfully! a: " << a << ", b: " << b << std::endl << std::endl;
    else
        std::cout << "Int type serialization fails! a: " << a << ", b: " << b << std::endl << std::endl;
}

void long_test()
{
    long long a(3000000000);
    //as the size of long on the 32-bits is different from it on the 64-bits, I use long long type instead
    //although the function name is still "long_test"
    //3000000000 exceeds the maximum of int 
    std::string file("../XML_test/long_test.xml"); //specified document address
    XML_Serialize(a, "long", file); //serialize int type into the file
    long long b;
    XML_Deserialize(b, "long", file); //deserialize int type from file to b
    std::cout << "Long type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        std::cout << "Long type serializes successfully! a: " << a << ", b: " << b << std::endl << std::endl;
    else
        std::cout << "Long type serialization fails! a: " << a << ", b: " << b << std::endl << std::endl;
}

void float_test()
{
    float a(1.5);
    std::string file("../XML_test/float_test.xml"); //specified document address
    XML_Serialize(a, "float", file); //serialize float type into the file
    float b;
    XML_Deserialize(b, "float", file); //deserialize float type from file to b
    std::cout << "Float type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        std::cout << "Float type serializes successfully! a: " << a << ", b: " << b << std::endl << std::endl;
    else
        std::cout << "Float type serialization fails! a: " << a << ", b: " << b << std::endl << std::endl;
}

void double_test()
{
    double a(3.12345678); //exceed the precision of float
    std::string file("../XML_test/double_test.xml"); //specified document address 
    XML_Serialize(a, "double", file); //serialize double type into the file
    double b;
    XML_Deserialize(b, "double", file); //deserialize double type from file to b
    std::cout << "Double type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        std::cout << "Double type serializes successfully! a: " << std::setprecision(10) << a << ", b: " << std::setprecision(10) << b << std::endl << std::endl;
    else
        std::cout << "Double type serialization fails! a: " << std::setprecision(10) << a << ", b: " << std::setprecision(10) << b << std::endl << std::endl;
}

void char_test()
{
    char a('#');
    std::string file("../XML_test/char_test.xml"); //specified document address
    XML_Serialize(a, "char", file); //serialize char type into the file
    char b;
    XML_Deserialize(b, "char", file); //deserialize char type from file to b
    std::cout << "Char type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        std::cout << "Char type serializes successfully! a: " << a << ", b: " << b << std::endl << std::endl;
    else
        std::cout << "Char type serialization fails! a: " << a << ", b: " << b << std::endl << std::endl;
}

void string_test()
{
    std::string a("Hello world");
    std::string file("../XML_test/string_test.xml"); //specified document address
    XML_Serialize(a, "std_string", file); //serialize string type into the file
    std::string b;
    XML_Deserialize(b, "std_string", file); //deserialize string type from file to b
    std::cout << "String type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        std::cout << "String type serializes successfully! a: " << a << ", b: " << b << std::endl << std::endl;
    else
        std::cout << "String type serialization fails! a: " << a << ", b: " << b << std::endl << std::endl;
}

void vector_test()
{
    std::vector<std::vector<int>> a{{1,2,3}, {4,5,6}, {7,8,9}};
    std::string file("../XML_test/vector_test.xml"); //specified document address
    XML_Serialize(a, "std_vector", file); //serialize vector type into the file
    std::vector<std::vector<int>> b;
    XML_Deserialize(b, "std_vector", file); //deserialize vector type from file to b
    std::cout << "Vector type test: ";
    if (a == b) //judge whether serialization and deserialization are correct, and print both of them
        std::cout << "Vector type serializes successfully! a:";
    else
        std::cout << "Vector type serialization fails! a:";
    //print both a and b
    for (auto i = a.begin(); i != a.end(); i++)
        for (auto k = i->begin(); k != i->end(); k++)
            std::cout << " " << *k;
    std::cout << ", b:";
    for (auto i = b.begin(); i != b.end(); i++)
        for (auto k = i->begin(); k != i->end(); k++)
            std::cout << " " << *k;
    std::cout << std::endl << std::endl;
}

void map_test()
{
    std::map<std::string, int> a;
    a.insert(std::make_pair("wa", 1));
    a.insert(std::make_pair("wawa", 2));
    a.insert(std::make_pair("wawawa", 3));
    std::string file("../XML_test/map_test.xml"); //specified document address
    XML_Serialize(a, "std_map", file); //serialize map type into the file
    std::map<std::string, int> b;
    XML_Deserialize(b, "std_map", file); //deserialize map type from file to b
    std::cout << "Map type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        std::cout << "Map type serializes successfully! a:";
    else
        std::cout << "Map type serialization fails! a:";
    //print both a and b
    for (auto i = a.begin(); i != a.end(); i++)
        std::cout << " <" << i -> first << ", " << i -> second << ">";
    std::cout << ", b:";
    for (auto i = b.begin(); i != b.end(); i++)
        std::cout << " <" << i -> first << ", " << i -> second << ">";
    std::cout << std::endl << std::endl;
}

void set_test()
{
    std::set<double> a{1.23, 2.34, -5.67, 3.14};
    std::string file("../XML_test/set_test.xml"); //specified document address
    XML_Serialize(a, "std_set", file); //serialize set type into the file
    std::set<double> b;
    XML_Deserialize(b, "std_set", file); //deserialize set type from file to b
    std::cout << "Set type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        std::cout << "Map type serializes successfully! a:";
    else
        std::cout << "Map type serialization fails! a:";
    //print both a and b
    for (auto i = a.begin(); i != a.end(); i++)
        std::cout << *i << " ";
    std::cout << ", b:";
    for (auto i = b.begin(); i != b.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl << std::endl;
}

void list_test()
{
    std::list<std::string> a{"abc", "def", "ghijk"};
    std::string file("../XML_test/list_test.xml"); //specified document address
    XML_Serialize(a, "std_list", file); //serialize list type into the file
    std::list<std::string> b;
    XML_Deserialize(b, "std_list", file); //deserialize list type from file to b
    std::cout << "List type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        std::cout << "List type serializes successfully! a:";
    else
        std::cout << "List type serialization fails! a:";
    //print both a and b
    for (auto i = a.begin(); i != a.end(); i++)
        std::cout << *i << " ";
    std::cout << ", b:";
    for (auto i = b.begin(); i != b.end(); i++)
        std::cout << *i << " ";
    std::cout << std::endl << std::endl;
}

void pair_test()
{
    std::pair<std::string, int> a;
    a = std::make_pair("wawawa", 3); 
    std::string file("../XML_test/pair_test.xml"); //specified document address
    XML_Serialize(a, "std_pair", file); //serialize pair type into the file
    std::pair<std::string, int> b;
    XML_Deserialize(b, "std_pair", file); //deserialize pair type from file to b
    std::cout << "Pair type test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        std::cout << "Pair type serializes successfully! a: <" << a.first << ", " << a.second << ">, b: <" << b.first << ", " << b.second << ">\n\n";
    else
        std::cout << "Pair type serialization fails! a: <" << a.first << ", " << a.second << ">, b: <" << b.first << ", " << b.second << ">\n\n";
}

void UserDefinedType_test()
{
    struct UserDefinedType a(9, "tzh", 3.14, 4.5, -1.2);
    std::string file("../XML_test/UserDefinedType_test.xml"); //specified document address
    XML_Serialize(a, "UserDefinedType", file); //serialize user defined type into the file
    struct UserDefinedType b;
    XML_Deserialize(b,"UserDefinedType", file); //deserialize user defined type from file to b
    std::cout << "UserDefinedType test: ";
    if (a == b) //judge whether serialization and deserialization are correct
        std::cout << "UserDefinedType type serializes successfully! a{ ";
    else
        std::cout << "UserDefinedType serialization fails! a{ ";
    //print both a and b
    std::cout << "idx: " << a.idx << ", name: " << a.name << ", data: ";
    for (auto i = a.data.begin(); i != a.data.end(); i++)
        std::cout << *i << " ";
    std::cout << "}, b{ ";
    std::cout << "idx: " << b.idx << ", name: " << b.name << ", data: ";
    for (auto i = b.data.begin(); i != b.data.end(); i++)
        std::cout << *i << " ";
    std::cout << "}";
}

inline std::string judge(UserDefinedType x, std::string name)
{
    if (name != "UserDefinedType") //check its type
    {
        std::cout << "Warning: requested type is not matched with object type!" << std::endl;
        return "";
    }
    return "UserDefinedType"; //return the correct type
}

void code(UserDefinedType x, std::string name, XMLElement* roof, XMLDocument& doc)
{
    //for each member, call their own serialization function
    code(x.data, "", roof, doc);
    code(x.idx, "", roof, doc);
    code(x.name, "", roof, doc);
}
void decode(UserDefinedType& x, XMLNode* root)
{
    //for each member, call their own deserialization function
    XMLNode* child = root;
    decode(x.data, child);
    child = child -> NextSibling();
    decode(x.idx, child);
    child = child -> NextSibling();
    decode(x.name, child);
}