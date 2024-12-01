#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <fstream>

using namespace std;

int main() {

    // accessing input from input.in
    vector<int> list1;
    vector<int> list2;

    ifstream inputFile("input.in");  

    if (!inputFile) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    int num1, num2;
    while (inputFile >> num1 >> num2) {
        list1.push_back(num1);
        list2.push_back(num2);
    }

    inputFile.close();

    // algorithm
    sort(list1.begin(),list1.end());
    sort(list2.begin(),list2.end());
    
    long long total_distance =0;
    long long reps =0;
    int n = list1.size();
    for(int i=0;i<n;i++)
    {
        long long to_find = list1[i];
        reps =0;
        for(int j=0;j<n;j++)
        {
            if(to_find==list2[j])
            {
                reps++;
            }
        }
        total_distance += to_find * reps;
    }

    cout << total_distance<<endl;

    return 0;
}
