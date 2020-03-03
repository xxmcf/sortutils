#include "commonutils.h"
#pragma execution_character_set("utf-8")
#include <QDebug>
#include <sstream>

using std::stringstream;



void CommonUtils::print_array(const char*content, int a[], int n)
{
    stringstream ostr;
    ostr << content << "\n";



    for (int i = 0; i<n; i++)
    {
        ostr << a[i] << " ";
    }
    clog("%s", ostr.str().c_str());
}

void CommonUtils::print_vector(const char*content, vector<int>& vec)
{
    stringstream ostr;
    ostr << content << "\n";
    for (auto v : vec)
    {
        ostr << v << " ";
    }
    clog("%s", ostr.str().c_str());
}

void CommonUtils::print_deque(const char*content, deque<int>& vec)
{
    stringstream ostr;
    ostr << content << "\n";
    for (auto v : vec)
    {
        ostr << v << " ";
    }
    clog("%s", ostr.str().c_str());
}

void CommonUtils::print_list(const char*content, list<int>& vec)
{
    stringstream ostr;
    ostr << content << "\n";
    for (auto v : vec)
    {
        ostr << v << " ";
    }
    clog("%s", ostr.str().c_str());
}

void CommonUtils::print_map(const char*content, map<string, int>& vmap)
{
    stringstream ostr;
    ostr << content << "\n";
    for (auto v : vmap)
    {
        ostr << v.first << " : " << v.second  << "\n";
    }
    clog("%s", ostr.str().c_str());
}

void CommonUtils::print_map(const char*content, map<string, int, std::greater<string>>& vmap)
{
    stringstream ostr;
    ostr << content << "\n";
    for (auto v : vmap)
    {
        ostr << v.first << " : " << v.second  << "\n";
    }
    clog("%s", ostr.str().c_str());
}

void CommonUtils::print_multimap(const char*content, multimap<string, int>& vmap)
{
    stringstream ostr;
    ostr << content << "\n";
    for (auto v : vmap)
    {
        ostr << v.first << " : " << v.second  << "\n";
    }
    clog("%s", ostr.str().c_str());
}

void CommonUtils::print_multimap(const char*content, multimap<string, int, std::greater<string>>& vmap)
{
    stringstream ostr;
    ostr << content << "\n";
    for (auto v : vmap)
    {
        ostr << v.first << " : " << v.second  << "\n";
    }
    clog("%s", ostr.str().c_str());
}

void CommonUtils::print_unordered_map(const char*content, unordered_map<string, int, str_hash>& vmap)
{
    stringstream ostr;
    ostr << content << "\n";
    for (auto v : vmap)
    {
        ostr << v.first << " : " << v.second  << "\n";
    }
    clog("%s", ostr.str().c_str());
}

void CommonUtils::print_set(const char*content, set<int>& vset)
{
    stringstream ostr;
    ostr << content << "\n";
    for (auto v : vset)
    {
        ostr << v << " ";
    }
    clog("%s", ostr.str().c_str());
}

void CommonUtils::print_set(const char*content, set<int, std::greater<int>>& vset)
{
    stringstream ostr;
    ostr << content << "\n";
    for (auto v : vset)
    {
        ostr << v << " ";
    }
    clog("%s", ostr.str().c_str());
}

void CommonUtils::print_multiset(const char*content, multiset<int>& vset)
{
    stringstream ostr;
    ostr << content << "\n";
    for (auto v : vset)
    {
        ostr << v << " ";
    }
    clog("%s", ostr.str().c_str());
}

void CommonUtils::print_multiset(const char*content, multiset<int, std::greater<int>>& vset)
{
    stringstream ostr;
    ostr << content << "\n";
    for (auto v : vset)
    {
        ostr << v << " ";
    }
    clog("%s", ostr.str().c_str());
}

void CommonUtils::print_string(const char*content, string& s)
{
    stringstream ostr;
    ostr << content << "\n" << s;
    clog("%s", ostr.str().c_str());
}
