#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;

//Overloaded Operator
ostream& operator<<(ostream& os, const vector<int>& vec){
    for(int element : vec){
        os << element << " ";
    }
    return os;
}

int binarySearch(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    
    while (low <= high)
    {
        // Get middle of the high and low
        int mid = low + (high - low) / 2;
        // return is mid index equals target
        if (arr[mid] == target){
            return mid;
        }
        else if (arr[mid] < target)
        { // Change lower to mid + 1 if mid is less then target
           low = mid + 1 ;
        }
        else
        { // Change high to mid -1 if mid is larger then target.
            high = mid - 1;
        }
        
    }
    return -1;
}


int main(){
    string input;
    cout << "Enter array with spaces: ";
    getline(cin, input);
    vector<int> arr;
    // Take input and separate it into numbers
    stringstream ss(input);
    int number;

    while (ss >> number)
    {
        arr.push_back(number);
    }

    sort(arr.begin(), arr.end());
    cout << arr << endl;
    
    cout << "Target:";
    int target; cin >> target;
    
    int result = binarySearch(arr, target);

    cout << result;
    return 0;

}