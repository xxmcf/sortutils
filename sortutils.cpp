#include "sortutils.h"
#include <time.h>
#include "commonutils.h"
#include <algorithm>

SortUtils::SortUtils()
{

}

void SortUtils::QuikSort(vector<int>& lst, bool asc/*=true*/)
{
    QQuikSort(lst, 0, lst.size()-1, asc);
}

//快速排序
void SortUtils::QQuikSort(vector<int>& lst, int left, int right, bool asc)
{
    if (0==lst.size()) return;
    if (left >= right) return;

    int len = right - left;
    //防止有序队列导致快速排序效率降低
    srand((unsigned)time(NULL));
    int base_index = rand() % (len+1) + left;
    std::swap(lst[left], lst[base_index]);
    int key = lst[left];

    int i = left, j = right;
    while(i<j)
    {
        if (asc)
        {
            while(lst[j] >= key && i<j) j--;
            if (i!=j) lst[i] = lst[j];
            while(lst[i] < key && i<j) i++;
            if (i!=j) lst[j] = lst[i];
        }
        else
        {
            while(lst[j] < key && i<j) j--;
            if (i!=j) lst[i] = lst[j];
            while(lst[i] >= key && i<j) i++;
            if (i!=j) lst[j] = lst[i];
        }


    }
    lst[i] = key;

    clog("key=%d, keyIndex=%d, sortIndex=%d, left=%d, right=%d", key, base_index, i, left, right);
    CommonUtils::print_vector("lst=", lst);
    QQuikSort(lst, left, i-1, asc);
    QQuikSort(lst, i+1, right, asc);
}

//冒泡排序
void SortUtils::BubbleSort(vector<int>& lst, bool asc/*=true*/)
{
    if(lst.empty()) return;
    int len = lst.size();
    if (asc)
    {
        for(int i=0;i<len-1;++i)
            for(int j=len-1;j>i;--j)
                if(lst[j]<lst[j-1])
                    std::swap(lst[j],lst[j-1]);
    }
    else
    {
        for(int i=0;i<len-1;++i)
            for(int j=len-1;j>i;--j)
                if(lst[j]>lst[j-1])
                    std::swap(lst[j],lst[j-1]);
    }
}

//选择排序
void SortUtils::SelectSort(vector<int>& lst, bool asc/*=true*/)
{
    if (lst.empty()) return;
    int len = lst.size();
    int index = 0;

    if (asc)
    {
        for (int i=0; i<len-1; i++)
        {
            index = i;
            for (int j=i+1; j<len; j++)
            {
                if (lst[i] > lst[j])
                    index = j;
            }
            if (index != i)
                std::swap(lst[i], lst[index]);
        }
    }
    else
    {
        for (int i=0; i<len-1; i++)
        {
            index = i;
            for (int j=i+1; j<len; j++)
            {
                if (lst[i] < lst[j])
                    index = j;
            }
            if (index != i)
                std::swap(lst[i], lst[index]);
        }
    }
}

//插入排序
void SortUtils::InsertSort(vector<int>& lst, bool asc/*=true*/)
{
    if(lst.empty()) return;
    int len = lst.size();

    if (asc)
    {
        for (int i=1; i<len; i++)
        {
            for (int j=i; j>0; j--)
            {
                if (lst[j] < lst[j-1])
                    std::swap(lst[j], lst[j-1]);
                else
                    break;
            }
            CommonUtils::print_vector("lst=", lst);
        }
    }
    else
    {
        for (int i=1; i<len; i++)
        {
            for (int j=i; j>0; j--)
            {
                if (lst[j] > lst[j-1])
                    std::swap(lst[j], lst[j-1]);
                else
                    break;
            }
            CommonUtils::print_vector("lst=", lst);
        }

    }
}

//希尔排序
void SortUtils::ShellSort(vector<int>& lst, bool asc/*=true*/)
{
    if (lst.empty()) return;

    int len = lst.size();

    if (asc)
    {
        for (int div=len/2; div>=1; div/=2)
        {
            for (int k=0; k<div; k++)
            {
                for (int i=div+k; i<len; i+= div)
                {
                    for (int j=i; j>k; j-=div)
                    {
                        if (lst[j] < lst[j-1])
                        {
                            std::swap(lst[j], lst[j-1]);
                        }
                    }
                }
            }
        }
    }
    else
    {
        for (int div=len/2; div>=1; div/=2)
        {
            for (int k=0; k<div; k++)
            {
                for (int i=div+k; i<len; i+= div)
                {
                    for (int j=i; j>k; j-=div)
                    {
                        if (lst[j] > lst[j-1])
                        {
                            std::swap(lst[j], lst[j-1]);
                        }
                    }
                }
            }
        }
    }

}

//归并排序
void SortUtils::MergeSort(vector<int>& lst, bool asc/*=true*/)
{
    if (lst.empty()) return;
    vector<int> temp;
    temp.resize(lst.size());

    MMergeSort(lst, 0, lst.size()-1, temp, asc);
    lst.assign(temp.begin(), temp.end());
}


void SortUtils::MMergeSort(vector<int>& lst, int left, int right, vector<int>& temp, bool asc/*=true*/)
{
    if (left < right)
    {
        int mid = (right + left) / 2;
        MMergeSort(lst, left, mid, temp, asc);
        MMergeSort(lst, mid+1, right, temp, asc);
        MMergeArray(lst, left, mid, right, temp, asc);
    }
}

void SortUtils::MMergeArray(vector<int>& lst, int left, int mid, int right, vector<int>& temp, bool asc/*=true*/)
{
    int i = left, j = mid+1, k = 0;

    if (asc)
    {
        while(i<=mid && j<=right)
        {
            if (lst[j] <= lst[i])
                temp[k++] = lst[j++];
            else
                temp[k++] = lst[i++];

        }
    }
    else
    {
        while(i<=mid && j<=right)
        {
            if (lst[j] > lst[i])
                temp[k++] = lst[j++];
            else
                temp[k++] = lst[i++];

        }
    }

    while(i<=mid)
        temp[k++] = lst[i++];

    while(j<=right)
        temp[k++] = lst[j++];

    std::copy(temp.begin(), temp.begin()+k, lst.begin()+left);
}

void SortUtils::HeapSort(vector<int>& lst, bool asc/*=true*/)
{
    if (lst.empty()) return;
    MakeHeap(lst, lst.size(), asc);
    CommonUtils::print_vector("MakeHeap=", lst);
    for (int i=lst.size()-1; i>=0; --i)
    {
        std::swap(lst[i], lst[0]);
        AdjustHeap(lst, 0, i, asc);
        CommonUtils::print_vector("AdustHeap=", lst);

    }

}

void SortUtils::AdjustHeap(vector<int> &lst, int startIndex, int len, bool asc)
{
    int child = 2*startIndex + 1;

    if (asc)
    {
        while(child < len)
        {
            if (child+1 < len && lst[child] <= lst[child+1])
            {
                child++;
            }
            if (lst[startIndex] >= lst[child]) break;
            std::swap(lst[startIndex], lst[child]);
            startIndex = child;
            child = 2*startIndex+1;
        }
    }
    else
    {
        while(child < len)
        {
            if (child+1 < len && lst[child] > lst[child+1])
            {
                child++;
            }
            if (lst[startIndex] < lst[child]) break;
            std::swap(lst[startIndex], lst[child]);
            startIndex = child;
            child = 2*startIndex+1;
        }
    }

}

void SortUtils::MakeHeap(vector<int> &lst, int len, bool asc)
{
    for (int i=len/2; i>=0; --i)
    {
        AdjustHeap(lst, i, len, asc);
    }
}

void SortUtils::RadixSort_LSD(vector<int>& lst, bool asc/*=true*/)
{
    if (lst.empty()) return;

    int digit = GetMaxDigit(lst);

    int count[10];
    int len = lst.size();
    vector<int> temp(len);

    if (asc)
    {
        for (int i = 1; i <= digit; i++)
        {
            std::fill_n(count, 10, 0);

            for (int j=0; j<len; j++)
            {
                int r = GetRiminder(lst[j], i);
                count[r]++;
            }

            for (int j=1; j<10; j++)
            {
                count[j] += count[j-1];
            }

            for (int j=len-1; j>=0; j--)
            {
                int r = GetRiminder(lst[j], i);
                int index = count[r];
                temp[index-1] = lst[j];
                count[r]--;
            }

            std::copy(temp.begin(), temp.end(), lst.begin());
            CommonUtils::print_vector("整理以后", lst);
        }
    }
    else
    {
        for (int i = 1; i <= digit; i++)
        {
            std::fill_n(count, 10, 0);

            for (int j=0; j<len; j++)
            {
                int r = GetRiminder(lst[j], i);
                count[r]++;
            }

            for (int j=8; j>=0; j--)
            {
                count[j] += count[j+1];
            }

            for (int j=len-1; j>=0; j--)
            {
                int r = GetRiminder(lst[j], i);
                int index = count[r];
                temp[index-1] = lst[j];
                count[r]--;
            }

            std::copy(temp.begin(), temp.end(), lst.begin());

            CommonUtils::print_vector("整理以后", lst);
        }
    }
}


void SortUtils::RadixSort_MSD(vector<int>& lst, bool asc/*=true*/)
{
    if (lst.empty()) return;
    int digit = GetMaxDigit(lst);
    vector<int> temp(lst.size());

    RRadixSort_MSD(lst, 0, lst.size()-1, digit, temp, asc);
}

void SortUtils::RRadixSort_MSD(vector<int>& lst, int beg, int end, int digit, vector<int>& temp, int asc/*=true*/)
{
    if (beg >= end) return;
    if (digit < 1) return;

    int count[10], start[10] = {0}; //T start 会全是0

    std::fill_n(count, 10, 0);
    std::fill_n(start, 10, 0);

    int len = end - beg+1;
    for (int i=beg; i<=end; i++)
    {
        int r = GetRiminder(lst[i], digit);
        count[r]++;
    }

    std::copy(count, count+10, start);

    if (asc)
    {
        for (int i=1; i<10; i++)
        {
            start[i] += start[i-1];
        }
    }
    else
    {
        for (int i=8; i>=0; i--)
        {
            start[i] += start[i+1];
        }
    }



    for (int i=end; i>= beg; i--)
    {
        int r = GetRiminder(lst[i], digit);
        int index = start[r];
        temp[index-1] = lst[i];
        start[r]--;
    }

    std::copy(temp.begin(), temp.begin()+len, lst.begin()+beg); //TODO: len会不会越界
    CommonUtils::print_vector("整理以后", lst);

    for (int i=0; i<10; i++)
    {
        if (count[i]>1)
        {
            RRadixSort_MSD(lst, start[i], start[i]+count[i]-1, digit-1, temp, asc);
        }
    }
}

int SortUtils::GetMaxDigit(vector<int>& lst)
{
    if (lst.empty()) return 0;

    int max_v = lst[0];
    for (int i=1; i<lst.size(); i++)
    {
        if (max_v < lst[i])
        {
            max_v = lst[i];
        }
    }

    int digit = 0;
    while(max_v!=0)
    {
        max_v /= 10;
        digit++;
    }

    return digit;
}

int SortUtils::GetRiminder(int value, int digit)
{
    while(digit>1)
    {
        value /= 10;
        digit--;
    }

    return value % 10;
}
































