#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

template <typename IT1, typename IT2, typename IO>
IO Union(IT1 input1Begin, IT1 input1End,
    IT2 input2Begin, IT2 input2End,
    IO outputBegin)
{
    for (; input1Begin != input1End; outputBegin++)
    {
        if (input2Begin == input2End)
            return std::copy(input1Begin, input1End, outputBegin);
        if (*input1Begin < *input2Begin)
            *outputBegin = *input1Begin++;
        else
        {
            *outputBegin = *input2Begin;
            if (!(*input2Begin < *input1Begin))
                input1Begin++;
            input2Begin++;
        }
    }
    return std::copy(input2Begin, input2End, outputBegin);
}

template <typename IT1, typename IT2, typename IO>
IO Intersection(IT1 input1Begin, IT1 input1End,
    IT2 input2Begin, IT2 input2End,
    IO outputBegin)
{
    while (input1Begin != input1End && input2Begin != input2End)
    {
        if (*input1Begin < *input2Begin)
            input1Begin++;
        else 
        {
            if (*input2Begin == *input1Begin)
                *outputBegin++ = *input1Begin++;
            input2Begin++;
        }
    }
    return outputBegin;
}

int main()
{
    std::set<int> set1{ 1, 3, 5, 6, 8, 9 };
    std::set<int> set2{ 2, 3, 4, 6, 7 };
    // 1, 2, 3, 4, 5, 6, 7, 8, 9
    // 3, 6
    std::vector<int> result;

    /*Union(set1.begin(), set1.end(),
        set2.begin(), set2.end(),
        std::back_inserter(result));*/

    Intersection(set1.begin(), set1.end(),
        set2.begin(), set2.end(),
        std::back_inserter(result));

    for (auto item : result)
        std::cout << item << " ";
    std::cout << "\n";
}

