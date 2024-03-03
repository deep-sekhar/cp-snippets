#include <bits/extc++.h>
using namespace __gnu_pbds;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// =================================
// use the tree like below:

// In this code, "order_of_key()"" is a function provided by the tree container from the GNU PBDS (Policy-Based Data Structures) library. It's used to find the number of elements in the tree that are "strictly less than" the given key. 

// The "find_by_order()"" function is used to find the k-th smallest element in the tree (0-based index). eg: t1.find_by_order(0) will return the smallest element in the tree.

// The "insert()"" function is used to insert an element into the tree.

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> r1, r2;
        r1.push_back(nums[0]); r2.push_back(nums[1]);
        Tree<array<int,2>> t1, t2;
        t1.insert({nums[0],0}); t2.insert({nums[1],1});
        
        int x;
        for(int i = 2; i<n; i++)
        {
            x = nums[i];
            int count1 = t1.size() - t1.order_of_key({x+1,-1});
            int count2 = t2.size() - t2.order_of_key({x+1,-1});
            if(count1 > count2){
                r1.push_back(nums[i]); t1.insert({nums[i],i});
            }else if(count1 < count2){
                r2.push_back(nums[i]); t2.insert({nums[i],i});
            }else{
                if(t1.size() < t2.size()){
                    r1.push_back(nums[i]); t1.insert({nums[i],i});
                }else if(t1.size() > t2.size()){
                    r2.push_back(nums[i]); t2.insert({nums[i],i});
                }else{
                    r1.push_back(nums[i]); t1.insert({nums[i],i});
                }
            }
        }
        for(auto &i: r2) r1.push_back(i);
        return r1;
    }
};