#ifndef SORTUTILS_H
#define SORTUTILS_H

#include <vector>
#include <string>
using std::vector;
using std::string;

class SortUtils
{
public:
    SortUtils();

    //快速排序
    static void QuikSort(vector<int>& lst, bool asc=true);
    //冒泡排序
    static void BubbleSort(vector<int>& lst, bool asc=true);
    //选择排序
    static void SelectSort(vector<int>& lst, bool asc=true);
    //插入排序
    static void InsertSort(vector<int>& lst, bool asc=true);
    //希尔排序
    static void ShellSort(vector<int>& lst, bool asc=true);
    //归并排序
    static void MergeSort(vector<int>& lst, bool asc=true);
    //堆排序
    static void HeapSort(vector<int>& lst, bool asc=true);
    //基数排序LSD
    static void RadixSort_LSD(vector<int>& lst, bool asc=true);
    //基数排序MSD
    static void RadixSort_MSD(vector<int>& lst, bool asc=true);

private:
    static void QQuikSort(vector<int>& lst, int left, int right, bool asc=true);
    static void MMergeSort(vector<int>& lst, int left, int right, vector<int>& temp, bool asc=true);
    static void MMergeArray(vector<int>& lst, int left, int mid, int right, vector<int>& temp, bool asc=true);
    static void AdjustHeap(vector<int>& lst, int startIndex, int len, bool asc=true);
    static void MakeHeap(vector<int>& lst, int len, bool asc=true);
    static int GetMaxDigit(vector<int>& lst);
    static int GetRiminder(int value, int digit);
    static void RRadixSort_MSD(vector<int>& lst, int beg, int end, int digit, vector<int>& temp, int asc=true);
};

#endif // SORTUTILS_H
