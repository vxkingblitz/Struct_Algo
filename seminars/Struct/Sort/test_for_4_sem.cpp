#include <gtest/gtest.h>
#include <fstream>

using namespace std;


//fourth sem
#include "natural_merge_sort.h"
#include "merge_one_phase.h"
#include "merge_sort.h"


TEST(Natural_Merging_SortTest, SingleElementArray) {
    string filename = "FILE.txt";
    ofstream input("FILE.txt");
    input << "5";
    input.close();

    Natural_Merging_Sort(filename);
    ifstream output("FILE.txt");
    vector<int> data;
    int value;
    while (output >> value) {
        data.push_back(value);
    }
    size_t size = data.size();
    output.close();
    vector<int> expected = { 5 };
    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(data[i], expected[i]);
    }

}


TEST(Natural_Merging_SortTest, SortedArray) {
    ofstream input("FILE.txt");
    input << "1 2 3 4 5 6 7";
    input.close();

    Natural_Merging_Sort("FILE.txt");
    ifstream output("FILE.txt");
    vector<int> data;
    int value;
    while (output >> value) {
        data.push_back(value);
    }
    size_t size = data.size();
    output.close();
    vector<int> expected = { 1, 2, 3, 4, 5, 6, 7 };
    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(data[i], expected[i]);
    }
}

TEST(Natural_Merging_SortTest, ReversedArray) {
    ofstream input("FILE.txt");
    input << "9 8 7 6 5 4 3 2";
    input.close();

    Natural_Merging_Sort("FILE.txt");
    ifstream output("FILE.txt");
    vector<int> data;
    int value;
    while (output >> value) {
        data.push_back(value);
    }
    size_t size = data.size();
    output.close();
    vector<int> expected = { 2, 3, 4, 5, 6, 7, 8, 9 };
    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(data[i], expected[i]);
    }

}


TEST(Natural_Merging_SortTest, AllSameElements) {
    ofstream input("FILE.txt");
    input << "7 7 7 7";
    input.close();

    Natural_Merging_Sort("FILE.txt");
    ifstream output("FILE.txt");
    vector<int> data;
    int value;
    while (output >> value) {
        data.push_back(value);
    }
    size_t size = data.size();
    output.close();
    vector<int> expected = { 7, 7, 7, 7 };
    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(data[i], expected[i]);
    }
}

TEST(Natural_Merging_SortTest, ArrayWithNegativeNumbers) {
    ofstream input("FILE.txt");
    input << "-4 -6 -56 -7 -774 -62";
    input.close();

    Natural_Merging_Sort("FILE.txt");
    ifstream output("FILE.txt");
    vector<int> data;
    int value;
    while (output >> value) {
        data.push_back(value);
    }
    size_t size = data.size();
    output.close();
    vector<int> expected = { -774, -62, -56, -7, -6, -4 };
    for (int i = 0; i < size; i++)
    {
        EXPECT_EQ(data[i], expected[i]);
    }
}

