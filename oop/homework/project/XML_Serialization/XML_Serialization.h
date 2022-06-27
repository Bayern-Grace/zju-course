#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <fstream>
using namespace tinyxml2;

namespace XML_Serialization
{
inline void code(bool x, std::string name, XMLElement* roof, XMLDocument& doc)
{
    XMLElement* type;
    if (name != "") //judge whether type is given or not
        type = doc.NewElement(name.c_str());
    else //if not, we need to set the type according to x's type
        type = doc.NewElement("bool");
    type -> SetAttribute("val", std::to_string(x).c_str()); //store the value under the type
    roof -> InsertEndChild(type);
}
inline void decode(bool& x, XMLNode* root)
{
    std::string value = root -> ToElement() ->  Attribute("val"); //read the value
    x = stoi(value, 0, 10); //transform the value to the required type
}
inline std::string judge(bool x, std::string name)
{
    //judge whether it is the correct type name
    if (name != "bool")
    {
        std::cout << "Warning: requested type is not matched with object type!" << std::endl;
        return "";
    }
    return name; //return the correct type name
}
inline void code(short x, std::string name, XMLElement* roof, XMLDocument& doc)
{
    XMLElement* type;
    if (name != "") //judge whether type is given or not
        type = doc.NewElement(name.c_str());
    else //if not, we need to set the type according to x's type
        type = doc.NewElement("code");
    type -> SetAttribute("val", std::to_string(x).c_str()); //store the value under the type
    roof -> InsertEndChild(type);
}
inline void decode(short& x, XMLNode* root)
{
    std::string value = root -> ToElement() ->  Attribute("val"); //read the value
    x = stoi(value, 0, 10); //transform the value to the required type
}
inline std::string judge(short x, std::string name)
{
    //judge whether it is the correct type name
    if (name != "short")
    {
        std::cout << "Warning: requested type is not matched with object type!" << std::endl;
        return "";
    }
    return name; //return the correct type name
}
inline void code(int x, std::string name, XMLElement* roof, XMLDocument& doc)
{
    XMLElement* type;
    if (name != "") //judge whether type is given or not
        type = doc.NewElement(name.c_str());
    else //if not, we need to set the type according to x's type
        type = doc.NewElement("int");
    type -> SetAttribute("val", std::to_string(x).c_str()); //store the value under the type
    roof -> InsertEndChild(type);
}
inline void decode(int& x, XMLNode* root)
{
    std::string value = root -> ToElement() -> Attribute("val"); //read the value
    x = stoi(value, 0, 10); //transform the value to the required type
}
inline std::string judge(int x, std::string name)
{
    //judge whether it is the correct type name
    if (name != "int")
    {
        std::cout << "Warning: requested type is not matched with object type!" << std::endl;
        return "";
    }
    return name; //return the correct type name
}
inline void code(long long x, std::string name, XMLElement* roof, XMLDocument& doc)
{
    XMLElement* type;
    if (name != "") //judge whether type is given or not
        type = doc.NewElement(name.c_str());
    else //if not, we need to set the type according to x's type
        type = doc.NewElement("long");
    type -> SetAttribute("val", std::to_string(x).c_str()); //store the value under the type
    roof -> InsertEndChild(type);
}
inline void decode(long long& x, XMLNode* root)
{
    std::string value = root -> ToElement() ->  Attribute("val"); //read the value
    x = stoll(value, 0, 10); //transform the value to the required type
}
inline std::string judge(long long x, std::string name)
{
    //judge whether it is the correct type name
    if (name != "long")
    {
        std::cout << "Warning: requested type is not matched with object type!" << std::endl;
        return "";
    }
    return name; //return the correct type name
}
inline void code(float x, std::string name, XMLElement* roof, XMLDocument& doc)
{
    XMLElement* type;
    if (name != "") //judge whether type is given or not
        type = doc.NewElement(name.c_str());
    else //if not, we need to set the type according to x's type
        type = doc.NewElement("float");
    std::stringstream s;
    s << std::setprecision(3) << x;
    type -> SetAttribute("val", s.str().c_str()); //store the value under the type
    roof -> InsertEndChild(type);
}
inline void decode(float& x, XMLNode* root)
{
    std::string value = root -> ToElement() ->  Attribute("val"); //read the value
    x = std::stof(value); //transform the value to the required type
}
inline std::string judge(float x, std::string name)
{
    //judge whether it is the correct type name
    if (name != "float")
    {
        std::cout << "Warning: requested type is not matched with object type!" << std::endl;
        return ""; //return the correct type name
    }
    return name;
}
inline void code(double x, std::string name, XMLElement* roof, XMLDocument& doc)
{
    XMLElement* type;
    if (name != "") //judge whether type is given or not
        type = doc.NewElement(name.c_str());
    else //if not, we need to set the type according to x's type
        type = doc.NewElement("double");
    std::stringstream s;
    s << std::setprecision(10) << x; //set precision, as double exceeds the default precision
    type -> SetAttribute("val", s.str().c_str()); //store the value under the type
    roof -> InsertEndChild(type);
}
inline void decode(double& x, XMLNode* root)
{
    std::string value = root -> ToElement() ->  Attribute("val"); //read the value
    x = std::stod(value); //transform the value to the required type
}
inline std::string judge(double x, std::string name)
{
    //judge whether it is the correct type name
    if (name != "double")
    {
        std::cout << "Warning: requested type is not matched with object type!" << std::endl;
        return "";
    }
    return name; //return the correct type name
}
inline void code(char x, std::string name, XMLElement* roof, XMLDocument& doc)
{
    XMLElement* type;
    if (name != "") //judge whether type is given or not
        type = doc.NewElement(name.c_str());
    else //if not, we need to set the type according to x's type
        type = doc.NewElement("char");
    std::stringstream s;
    s << std::setprecision(10) << x;
    type -> SetAttribute("val", s.str().c_str()); //store the value under the type
    roof -> InsertEndChild(type);
}
inline void decode(char& x, XMLNode* root)
{
    std::string value = root -> ToElement() ->  Attribute("val"); //read the value
    x = value[0]; //transform the value to the required type
}
inline std::string judge(char x, std::string name)
{
    //judge whether it is the correct type name
    if (name != "char")
    {
        std::cout << "Warning: requested type is not matched with object type!" << std::endl;
        return "";
    }
    return name; //return the correct type name
}
inline void code(std::string x, std::string name, XMLElement* roof, XMLDocument& doc)
{
    XMLElement* type;
    if (name != "") //judge whether type is given or not
        type = doc.NewElement(name.c_str());
    else //if not, we need to set the type according to x's type
        type = doc.NewElement("std_string");
    std::stringstream s;
    s << std::setprecision(10) << x; //set precision, as string exceeds the default precision
    type -> SetAttribute("val", s.str().c_str()); //store the value under the type
    roof -> InsertEndChild(type);
}
inline void decode(std::string& x, XMLNode* root)
{
    x = root -> ToElement() ->  Attribute("val"); //read the value
}
inline std::string judge(std::string x, std::string name)
{
    //judge whether it is the correct type name
    if (name != "std_string")
    {
        std::cout << "Warning: requested type is not matched with object type!" << std::endl;
        return "";
    }
    return name; //return the correct type name
}
template<typename T>
inline std::string judge(std::vector<T> x, std::string name)
{
    //judge whether it is the correct type name
    if (name != "std_vector")
    {
        std::cout << "Warning: requested type is not matched with object type!" << std::endl;
        return "";
    }
    return "std_vector"; //return the correct type name
}
template <typename T>
inline void code(std::vector<T> x, std::string name, XMLElement* roof, XMLDocument& doc)
{
    XMLElement* type;
    if (name != "") //judge whether type is given or not
        type = doc.NewElement(name.c_str());
    else //if not, we need to set the type according to x's type
        type = doc.NewElement("std_vector");
    type -> SetAttribute("size", x.size()); //store the value under the type
    roof -> InsertEndChild(type);
    for (auto i = x.begin(); i != x.end(); i++)
        code(*i, "", type, doc); //for each item, call their own serialization function
}
template<typename T>
inline void decode(std::vector<T>& x, XMLNode* root)
{
    XMLNode* child = root -> FirstChild();
    for (int i = 0; i < atoi(root -> ToElement() -> Attribute("size")); i++)
    {
        T a;
        decode(a, child); //for each item, call their own serialization function
        x.push_back(a);
        if (child -> NextSibling()) //seak for its siblings
            child = child -> NextSibling();
    }
}
template<typename T>
inline std::string judge(std::set<T> x, std::string name)
{
    //judge whether it is the correct type name
    if (name != "std_set")
    {
        std::cout << "Warning: requested type is not matched with object type!" << std::endl;
        return "";
    }
    return "std_set"; //return the correct type name
}
template <typename T>
inline void code(std::set<T> x, std::string name, XMLElement* roof, XMLDocument& doc)
{
    XMLElement* type;
    if (name != "") //judge whether type is given or not
        type = doc.NewElement(name.c_str());
    else //if not, we need to set the type according to x's type
        type = doc.NewElement("std_set");
    type -> SetAttribute("size", x.size()); //store the value under the type
    roof -> InsertEndChild(type);
    for (auto i = x.begin(); i != x.end(); i++)
        code(*i, "", type, doc); //for each item, call their own serialization function
}
template<typename T>
inline void decode(std::set<T>& x, XMLNode* root)
{
    XMLNode* child = root -> FirstChild();
    for (int i = 0; i < atoi(root -> ToElement() -> Attribute("size")); i++)
    {
        T a;
        decode(a, child); //for each item, call their own serialization function
        x.insert(a);
        if (child -> NextSibling()) //seak for its siblings
            child = child -> NextSibling();
    }
}
template<typename T>
inline std::string judge(std::list<T> x, std::string name)
{
    //judge whether it is the correct type name
    if (name != "std_list")
    {
        std::cout << "Warning: requested type is not matched with object type!" << std::endl;
        return "";
    }
    return "std_list"; //return the correct type name
}
template <typename T>
inline void code(std::list<T> x, std::string name, XMLElement* roof, XMLDocument& doc)
{
    XMLElement* type;
    if (name != "") //judge whether type is given or not
        type = doc.NewElement(name.c_str());
    else //if not, we need to set the type according to x's type
        type = doc.NewElement("std_list");
    type -> SetAttribute("size", x.size()); //store the value under the type
    roof -> InsertEndChild(type);
    for (auto i = x.begin(); i != x.end(); i++)
        code(*i, "", type, doc); //for each item, call their own serialization function
}
template<typename T>
inline void decode(std::list<T>& x, XMLNode* root)
{
    XMLNode* child = root -> FirstChild();
    for (int i = 0; i < atoi(root -> ToElement() -> Attribute("size")); i++)
    {
        T a;
        decode(a, child); //for each item, call their own serialization function
        x.push_back(a);
        if (child -> NextSibling()) //seak for its siblings
            child = child -> NextSibling();
    }
}
template<typename T, typename S>
inline std::string judge(std::pair<T, S> x, std::string name)
{
    //judge whether it is the correct type name
    if (name != "std_pair")
    {
        std::cout << "Warning: requested type is not matched with object type!" << std::endl;
        return "";
    }
    return "std_pair"; //return the correct type name
}
template<typename T, typename S>
inline void code(std::pair<T, S> x, std::string name, XMLElement* roof, XMLDocument& doc)
{
    XMLElement* type;
    if (name != "") //judge whether type is given or not
        type = doc.NewElement(name.c_str());
    else //if not, we need to set the type according to x's type
        type = doc.NewElement("std_pair");
    roof -> InsertEndChild(type);
    //for each item, call their own serialization function
    code(x.first, "first", type, doc);
    code(x.second, "second", type, doc);
}
template <typename T, typename S>
inline void decode(std::pair<T, S>& x, XMLNode* root)
{
    XMLNode* child = root -> FirstChild();
    T a;
    decode(a, child); //for each item, call their own serialization function
    S b;
    child = child -> NextSibling(); //seak for its siblings
    decode(b, child); //for each item, call their own serialization function
    x = std::make_pair(a, b);
}
template<typename T, typename S>
inline std::string judge(std::map<T, S> x, std::string name)
{
    //judge whether it is the correct type name
    if (name != "std_map")
    {
        std::cout << "Warning: requested type is not matched with object type!" << std::endl;
        return "";
    }
    return "std_map"; //return the correct type name
}
template <typename T, typename S>
inline void code(std::map<T, S> x, std::string name, XMLElement* roof, XMLDocument& doc)
{
    XMLElement* type;
    if (name != "") //judge whether type is given or not
        type = doc.NewElement(name.c_str());
    else //if not, we need to set the type according to x's type
        type = doc.NewElement("std_map");
    type -> SetAttribute("size", x.size()); //store the value under the type
    roof -> InsertEndChild(type);
    for (auto i : x)
    {
        T a = i.first;
        S b = i.second;
        XMLElement* child = doc.NewElement("std_pair");
        type->InsertEndChild(child);
        //for each item, call their own serialization function
        code(a, "key", child, doc);
        code(b, "value", child, doc);
    }
}
template<typename T, typename S>
inline void decode(std::map<T, S>& x, XMLNode* root)
{
    XMLNode* child = root -> FirstChild();
    for (int i = 0; i < atoi(root -> ToElement() -> Attribute("size")); i++)
    {
        std::pair<T, S> new_elem;
        decode(new_elem, child); //for each item, call their own serialization function
        x.insert(new_elem); 
        if (child -> NextSibling()) //seak for its siblings
            child = child -> NextSibling();
    }
}
template <typename T>
void XML_Serialize(T x, std::string name, std::string f)
{
    XMLDocument doc;
    XMLDeclaration* dec = doc.NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\"");
    //write the declaration
    doc.InsertFirstChild(dec);
    auto roof = doc.NewElement("Serialization");
    doc.InsertEndChild(roof);
    judge(x, name); //judge whether it is the correct type
    code(x, name, roof, doc); //call the corresponding serialization function
    doc.SaveFile(f.c_str());
}
template <typename T>
void XML_Deserialize(T& x, std::string name, std::string f)
{
    XMLDocument doc;
    XMLError ret = doc.LoadFile(f.c_str());
    if (ret)
    {
        std::cout << "Cannot open XML file" << std::endl;
        return ;
    }
    auto root = doc.FirstChildElement("Serialization");
    judge(x, name); //judge whether it is the correct type
    if (!root)
        return ;
    decode(x, root -> FirstChild()); //call the corresponding serialization function
}
}