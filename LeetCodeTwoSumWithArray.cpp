/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 

Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity */

#include <cmath>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int calcIndex;
        vector<int> result;

        if (nums.size()>=2 && nums.size()<=pow(10, 4) && 
            target >=pow(-10, 9) && target <=pow(10, 9))
        {
            for(int i=0; i < nums.size(); i++) {
                if(nums[i] >=pow(-10, 9) && nums[i] <=pow(10, 9)) {
                    for(int j=1; j < nums.size(); j++) {
                        if(i != j) {
                            calcIndex = nums[i] + nums[j];
                            if(calcIndex == target) {
                                result.push_back(i);
                                result.push_back(j);
                                break;
                            }
                        }
                    }
                    if(calcIndex == target) {
                        break;
                    }
                }
                
            }
        }
        
        return result;
    }
};


////////////////////// OPTIMZES
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        // Create an unordered_map to store the indices of the elements we have seen
        std::unordered_map<int, int> indices;
        // Create a vector to store the resulting indices
        std::vector<int> result;

        // Iterate through the elements of the nums vector
        for (int i = 0; i < nums.size(); i++) {
            // Calculate the complement of the current element needed to achieve the target
            int complement = target - nums[i];
            // Check if the complement exists in the unordered_map
            if (indices.find(complement) != indices.end()) {
                // If the complement is found, push the indices to the result vector
                result.push_back(indices[complement]);
                result.push_back(i);
                // Break out of the loop since we have found the solution
                break;
            }
            // If the complement does not exist in the unordered_map, store the current element and its index
            indices[nums[i]] = i;
        }

        // Return the resulting indices
        return result;
    }
};

