#include <iostream>
#include <string.h>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <sstream>
#include <fstream>

using namespace std;

namespace binSerialization{ 
inline void code(stringstream& f, bool data)
{
    f.write((char*)&data, 1); //write bool type into the stringstream
}

inline void decode(stringstream& f, bool& data)
{
    f.read((char*)&data, 1); //read value into bool type
}

inline void code(stringstream& f, short data)
{
    f.write((char*)&data, 2); //write short type into the stringstream
}

inline void decode(stringstream& f, short& data)
{
    f.read((char*)&data, 2); //read value into short type
}

inline void code(stringstream& f, int data)
{
    f.write((char*)&data, 4); //write int type into the stringstream
}

inline void decode(stringstream& f, int& data)
{
    f.read((char*)&data, 4); //read value into short type
}

inline void code(stringstream& f, long long data)
{
    f.write((char*)&data, 8); //write long type into the stringstream
}

inline void decode(stringstream& f, long long& data)
{
    f.read((char*)&data, 8); //read value into long type
}

inline void code(stringstream& f, unsigned short data)
{
    f.write((char*)&data, 2); //write unsigned short type into the stringstream
}

inline void decode(stringstream& f, unsigned short& data)
{
    f.read((char*)&data, 2); //read value into unsigned short type
}

inline void code(stringstream& f, unsigned data)
{
    f.write((char*)&data, 4); //write unsigned int type into the stringstream
}

inline void decode(stringstream& f, unsigned& data)
{
    f.read((char*)&data, 4); //read value into unsigned int type
}

inline void code(stringstream& f, unsigned long long data)
{
    f.write((char*)&data, 8); //write unsigned long type into the stringstream
}

inline void decode(stringstream& f, unsigned long long& data)
{
    f.read((char*)&data, 8); //read value into unsigned long type
}

inline void code(stringstream& f, double data)
{
    f.write((char*)&data, 8); //write double type into the stringstream
}

inline void decode(stringstream& f, double& data)
{
    f.read((char*)&data, 8); //read value into double type
}

inline void code(stringstream& f, float data)
{
    f.write((char*)&data, 4); //write float type into the stringstream
}

inline void decode(stringstream& f, float& data)
{
    f.read((char*)&data, 4); //read value into float type
}

inline void code(stringstream& f, char data)
{
    f.write((char*)&data, 1); //write char type into the stringstream
}

inline void decode(stringstream& f, char& data)
{
    f.read((char*)&data, 1); //read value into short type
}

inline void code(stringstream& f, string data)
{
    int len = data.length();
    code(f, len);
    f.write((char*)data.data(), len); //write string type into the stringstream
}

inline void decode(stringstream& f, string& data)
{
    int len;
    decode(f, len);
    data.resize(len);
    f.read((char*)data.data(), len); //read value into string type
}

template<typename T>
inline void code(stringstream& f, vector<T> data)
{
    int size = data.size();
    code(f, size); //store the size
    for (int i = 0; i < size; i++)
        code(f, data[i]); //call the corresponding serialization function
}

template <typename T>
inline void decode(stringstream& f, vector<T>& data)
{
    int size;
    decode(f, size); //read the size
    for (int i = 0; i < size; i++)
    {
        T x;
        decode(f, x); //call the corresponding deserialization function
        data.push_back(x);
    }
}

template<typename T, typename S>
inline void code(stringstream& f, map<T, S> data)
{
    int size = data.size();
    code(f, size); //store the size
    for (auto i = data.begin(); i != data.end(); i++)
    {
        //call the corresponding serialization function
        code(f, i -> first);
        code(f, i -> second);
    }
}

template <typename T, typename S>
inline void decode(stringstream& f, map<T, S>& data)
{
    int size;
    decode(f, size); //read the size
    for (int i = 0; i < size; i++)
    {
        T x;
        S y;
        //call the corresponding deserialization function
        decode(f, x);
        decode(f, y);
        data[x] = y;
    }
}

template<typename T>
inline void code(stringstream& f, set<T> data)
{
    int size = data.size();
    code(f, size); //store the size
    for (auto i = data.begin(); i != data.end(); i++)
        code(f, *i); //call the corresponding serialization function
}

template <typename T>
inline void decode(stringstream& f, set<T>& data)
{
    int size;
    decode(f, size); //read the size
    for (int i = 0; i < size; i++)
    {
        T x;
        decode(f, x); //call the corresponding deserialization function
        data.insert(x);
    }
}

template<typename T>
inline void code(stringstream& f, list<T> data)
{
    int size = data.size();
    code(f, size); //store the size
    for (auto i = data.begin(); i != data.end(); i++)
        code(f, *i); //call the corresponding serialization function
}

template <typename T>
inline void decode(stringstream& f, list<T>& data)
{
    int size;
    decode(f, size); //read the size
    for (int i = 0; i < size; i++)
    {
        T x;
        //call the corresponding deserialization function
        decode(f, x);
        data.push_back(x);
    }
}

template<typename T, typename S>
inline void code(stringstream& f, pair<T, S> data)
{
    //call the corresponding serialization function
    code(f, data.first);
    code(f, data.second);
}

template <typename T, typename S>
inline void decode(stringstream& f, pair<T, S>& data)
{
    T a;
    S b;
    //call the corresponding deserialization function
    decode(f, a);
    decode(f, b);
    data = make_pair(a, b);
}

template <typename T>
void Serialize(T x, string f)
{
    fstream file;
    file.open(f);
    stringstream s;
    code(s, x); //call the corresponding serialization function
    file << s.str(); //write stringsteam into the file
    file.close();
}
template <typename T>
void Deserialize(T& x, string f)
{
    fstream file;
    file.open(f);
    stringstream s;
    s << file.rdbuf(); //read stringsteam from the file
    decode(s, x);//call the corresponding deserialization function
    file.close();
}
}