#include "mystring.h"
#include <string>
#include "commonutils.h"
#include "darray.h"
#include "sortutils.h"

void datastruct_test()
{
    clog("\n<<<<<< mystring test");
    String s("Hello World!");
    String s1;
    String s2(s1);
    clog("s=%s", s.c_str());
    clog("s1=%s", s1.c_str());
    clog("s2=%s", s2.c_str());
    s2 = s;
    clog("s2=%s", s2.c_str());

    clog("\n<<<<<< DArray test");

    DArray da;
    da.push_back(1);
    da.push_back(10);
    da.push_back(100);
    da.push_back(1000);
    da.push_back(10000);
    da.push_back(100000);
    da.push_back(1000000);
    da.push_back(10000000);
    da.push_back(100000000);
    da.push_back(1);
    clog("da size=%d, capacity=%d", da.size(), da.capacity());
    clog("da = %s", da.toString().c_str());
    da.erase(1);
    clog("删除2个元素之后， da=%s", da.toString().c_str());
    da.remove(1);
    clog("删除值为1的元素之后， da=%s", da.toString().c_str());
    da.insert(3, 9999);
    clog("在第4个位置添加值为99999的元素之后， da=%s", da.toString().c_str());
    clog("da size=%d, capacity=%d", da.size(), da.capacity());

    clog("\n<<<<<< QuickSort test");
    vector<int> v_quick = {20, 40, 50, 10, 60};
    CommonUtils::print_vector("v_quick=", v_quick);
    SortUtils::QuikSort(v_quick);
    vector<int> v_quick2 = {20, 40, 50, 10, 60};
    CommonUtils::print_vector("v_quick2=", v_quick2);
    SortUtils::QuikSort(v_quick2, false);

    clog("\n<<<<<< 冒泡排序 test");
    vector<int> v_bubble = {20, 40, 50, 10, 60};
    CommonUtils::print_vector("v_bubble=", v_bubble);
    SortUtils::BubbleSort(v_bubble);
    CommonUtils::print_vector("冒泡排序后v_bubble=", v_bubble);
    vector<int> v_bubble2 = {20, 40, 50, 10, 60};
    CommonUtils::print_vector("v_bubble2=", v_bubble2);
    SortUtils::BubbleSort(v_bubble2, false);
    CommonUtils::print_vector("冒泡排序降序后v_bubble2=", v_bubble2);

    clog("\n<<<<<< 选择排序 test");
    vector<int> v_select = {20, 40, 50, 10, 60};
    CommonUtils::print_vector("v_select=", v_select);
    SortUtils::SelectSort(v_select);
    CommonUtils::print_vector("选择排序后v_select=", v_select);
    vector<int> v_select2 = {20, 40, 50, 10, 60};
    CommonUtils::print_vector("v_select2=", v_select2);
    SortUtils::SelectSort(v_select2, false);
    CommonUtils::print_vector("选择排序降序后v_select2=", v_select2);

    clog("\n<<<<<< 插入排序 test");
    vector<int> v_insert = {89, 45, 54, 29, 90, 34, 68};
    CommonUtils::print_vector("v_insert=", v_insert);
    SortUtils::InsertSort(v_insert);
    CommonUtils::print_vector("插入排序后v_insert=", v_insert);
    vector<int> v_insert2 = {89, 45, 54, 29, 90, 34, 68};
    CommonUtils::print_vector("v_insert2=", v_insert2);
    SortUtils::InsertSort(v_insert2, false);
    CommonUtils::print_vector("插入排序降序后v_insert2=", v_insert2);

    clog("\n<<<<<< 希尔排序 test");
    vector<int> v_shell = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
    CommonUtils::print_vector("v_shell=", v_shell);
    SortUtils::ShellSort(v_shell);
    CommonUtils::print_vector("希尔排序后v_shell=", v_shell);
    vector<int> v_shell2 = {8, 9, 1, 7, 2, 3, 5, 4, 6, 0};
    CommonUtils::print_vector("v_insert2=", v_shell2);
    SortUtils::ShellSort(v_shell2, false);
    CommonUtils::print_vector("希尔排序降序后v_shell2=", v_shell2);

    clog("\n<<<<<< 归并排序 test");
    vector<int> v_merge = {8, 4, 5, 7, 1, 3, 6, 2};
    CommonUtils::print_vector("v_merge=", v_merge);
    SortUtils::MergeSort(v_merge);
    CommonUtils::print_vector("归并排序后v_merge=", v_merge);
    vector<int> v_merge2 = {8, 4, 5, 7, 1, 3, 6, 2};
    CommonUtils::print_vector("v_merge2=", v_merge2);
    SortUtils::MergeSort(v_merge2, false);
    CommonUtils::print_vector("归并排序降序后v_merge2=", v_merge2);

    clog("\n<<<<<< 堆排序test");
    vector<int> v_heap = {7,3,8,5,1,4,9,10,11,6,15,12,2};
    CommonUtils::print_vector("v_heap=", v_heap);
    SortUtils::HeapSort(v_heap);
    CommonUtils::print_vector("堆排序后v_heap=", v_heap);
    vector<int> v_heap2 = {7,3,8,5,1,4,9,10,11,6,15,12,2};
    CommonUtils::print_vector("v_heap2=", v_heap2);
    SortUtils::HeapSort(v_heap2, false);
    CommonUtils::print_vector("堆排序降序后v_heap2=", v_heap2);


    clog("\n<<<<<< 基数排序LSD test");
    vector<int> v_radix_lsd = {50, 123, 543, 187, 49, 30, 0, 2, 11, 100};
    CommonUtils::print_vector("v_radix_lsd=", v_radix_lsd);
    SortUtils::RadixSort_LSD(v_radix_lsd);
    CommonUtils::print_vector("堆排序后v_radix_lsd=", v_radix_lsd);
    vector<int> v_radix_lsd2 = {50, 123, 543, 187, 49, 30, 0, 2, 11, 100};
    CommonUtils::print_vector("v_radix_lsd2=", v_radix_lsd2);
    SortUtils::RadixSort_LSD(v_radix_lsd2, false);
    CommonUtils::print_vector("堆排序降序后v_radix_lsd2=", v_radix_lsd2);


    clog("\n<<<<<< 基数排序MSD test");
    vector<int> v_radix_msd = {50, 123, 543, 187, 49, 30, 0, 2, 11, 100};
    CommonUtils::print_vector("v_radix_msd=", v_radix_msd);
    SortUtils::RadixSort_MSD(v_radix_msd);
    CommonUtils::print_vector("堆排序后v_radix_msd=", v_radix_msd);
    vector<int> v_radix_msd2 = {50, 123, 543, 187, 49, 30, 0, 2, 11, 100};
    CommonUtils::print_vector("v_radix_msd2=", v_radix_msd2);
    SortUtils::RadixSort_MSD(v_radix_msd2, false);
    CommonUtils::print_vector("堆排序降序后v_radix_msd=", v_radix_msd2);

}
