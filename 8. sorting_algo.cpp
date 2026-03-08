#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdio>
#include <stdint.h>
#include <stdlib.h>
#include <cstring>
#include <cstddef>
#include <algorithm>
#include <bits/stl_algo.h>
#include <memory>
#include <stack>
#include <queue>

using namespace std;

#define container_of(ptr, type, member) \
    (reinterpret_cast<type *>(reinterpret_cast<char *>(ptr) - offsetof(type, member)))

// This offset will give how many elements are there in a structure
#define OFFSET(struct_name, field_name) \
    (char)(&((struct_name *)NULL)->field_name)

// Address will provide you the actual address of the element
#define Address(struct_name, field_name) \
    (char)(&(struct_name)->field_name)

#define VALUEx(struct_name, struct_obj, field_name) \
    Address(struct_name, field_name) - OFFSET(struct_obj, field_name)
// (*(char *)(struct_name)->field_name) - (&((struct_name *)NULL)->field_name)

void print(const vector<int> nums)
{
    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;
}

void insertion_sort(vector<int> &nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        int key = nums[i];
        int j = i - 1;

        while (j >= 0 && (nums[j] > key))
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }
}

void bubble_sort(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            if (nums[i] > nums[j])
            {
                swap(nums[i], nums[j]);
            }
        }
    }
}

void selection_sort(vector<int> &nums)
{
    for (int i = 0; i < nums.size() - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[min_index])
            {
                min_index = j;
            }
        }
        swap(nums[i], nums[min_index]);
    }
}

void merge(vector<int> &nums, int first, int mid, int last)
{
    vector<int> temp(last - first + 1, 0);
    int i = first, j = mid + 1, k = 0;

    while (i <= mid && j <= last)
    {
        if (nums[i] < nums[j])
        {
            temp[k++] = nums[i++];
        }
        else
        {
            temp[k++] = nums[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = nums[i++];
    }
    while (j <= last)
    {
        temp[k++] = nums[j++];
    }

    for (auto i = 0; i < temp.size(); i++)
    {
        nums[first + i] = temp[i];
    }
}

void merge_sort(vector<int> &nums, int first, int last)
{
    if (first >= last)
    {
        return;
    }
    int mid = first + (last - first) / 2;
    merge_sort(nums, first, mid);
    merge_sort(nums, mid + 1, last);
    merge(nums, first, mid, last);
}

int partition(vector<int> &nums, int first, int last)
{
    // int pivot = nums[last];
    // int i = first - 1;

    // for (int j = first; j < last; j++)
    // {
    //     if (pivot > nums[j])
    //     {
    //         i++;
    //         swap(nums[i], nums[j]);
    //     }
    // }
    // swap(nums[i + 1], nums[last]);
    // return i + 1;
    int pivot = nums[first];
    int i = first + 1;
    for (int j = first + 1; j <= last; j++)
    {
        if (pivot > nums[j])
        {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    swap(nums[first], nums[i - 1]);
    return i - 1;
}

void quick_sort(vector<int> &nums, int first, int last)
{
    if (first >= last)
    {
        return;
    }
    int pivot = partition(nums, first, last); // first is always 0
    quick_sort(nums, first, pivot - 1);       // first is always 0
    quick_sort(nums, pivot + 1, last);
}

void count_sort(vector<int> &nums)
{
    if (nums.empty())
        return;
    int minv = *min_element(nums.begin(), nums.end());
    int maxv = *max_element(nums.begin(), nums.end());
    int range = maxv - minv + 1;

    vector<int> count(range, 0), output(nums.size());
    for (int x : nums)
    {
        ++count[x - minv];
        cout << "x: " << x << " count[x - minv]: " << count[x - minv] << endl;
    }
    cout << "\ncumulative count: " << endl;
    for (int i = 1; i < range; ++i)
    {
        count[i] += count[i - 1];
        cout << "i: " << i << " count[i]: " << count[i] << endl;
    }
    cout << "\noutput: " << endl;
    for (int i = (int)nums.size() - 1; i >= 0; --i)
    {
        int x = nums[i];
        output[--count[x - minv]] = x;
        cout << "x: " << x << " output[--count[x - minv]]: " << output[--count[x - minv]] << endl;
    }
    nums = std::move(output);
}

int main()
{
    vector<int> nums = {4, 2, 2, 8, 3, 3, 1};
    // vector<int> nums = {2, 5, 9, 13, 17, 14, 11, 4, 8, 10};
    // insertion_sort(nums);
    // bubble_sort(nums);
    // selection_sort(nums);
    // merge_sort(nums, 0, nums.size() - 1);
    // quick_sort(nums, 0, nums.size() - 1);
    count_sort(nums);
    print(nums);
    return 0;
}
