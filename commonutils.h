#ifndef COMMONUTILS_H
#define COMMONUTILS_H

#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <functional>
//#include <hash_map>
#include <unordered_map>
#include <QDebug>

using std::vector;
using std::list;
using std::string;
using std::map;
using std::set;
using std::multiset;
using std::multimap;
using std::deque;
//using std::hash_map;
using std::unordered_map;
#define clog qDebug

struct str_hash
{
    size_t operator()(const string& str) const
    {
        unsigned long __h = 0;
        for (size_t i = 0 ; i < str.size() ; i ++)
        __h = 5*__h + str[i];
        return size_t(__h);
    }
};

class CommonUtils
{
public:
    static void print_array(const char*content, int a[], int n);
    static void print_vector(const char*content, vector<int>& vec);
    static void print_list(const char*content, list<int>& vec);
    static void print_deque(const char*content, deque<int>& vec);
    static void print_map(const char*content, map<string, int>& vmap);    
    static void print_map(const char*content, map<string, int, std::greater<string>>& vmap);
    static void print_multimap(const char*content, multimap<string, int>& vmap);
    static void print_multimap(const char*content, multimap<string, int, std::greater<string>>& vmap);
    static void print_unordered_map(const char*content, unordered_map<string, int, str_hash>& vmap);
    static void print_set(const char*content, set<int>& vset);
    static void print_set(const char*content, set<int, std::greater<int>>& vset);
    static void print_multiset(const char*content, multiset<int>& vset);
    static void print_multiset(const char*content, multiset<int, std::greater<int>>& vset);
    static void print_string(const char*content, string& s);
};

#endif // COMMONUTILS_H
