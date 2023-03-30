//Question 2
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int num;  //getting the length of the array
    cout <<"Enter the number of elements:";
    cin >> num;
    cout <<endl;

    vector<int> lst;  //creating the array
    for (int i = 0; i < num; i++) {
        int n;
        cin >> n ;
        lst.push_back(n); //adding elements to the array

        // sort the vector array
        sort(lst.begin(), lst.end());

        // calculate the median
        int size = lst.size();
        double median;
        if (size % 2 == 0) {
            median = (double)(lst[size/2 - 1] + lst[size/2]) / 2;
        } else {
            median = (double)lst[size/2];
        }

        //printing the list
        cout <<"[ ";
        for(auto i: lst){
        cout<<i<<", ";
        }
        cout <<"]" <<"\t";
        
        cout << fixed << setprecision(1) << median << endl;
    }

    return 0;
}
