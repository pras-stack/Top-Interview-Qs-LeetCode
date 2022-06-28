Approach 1: Brute Force
The brute force approach is simple. Loop through each element x and find if there is another value that equals to target - x.
  
    Complexity Analysis

    Time complexity : O(n^2). For each element, we try to find its complement by looping through the rest of array which takes O(n) time.
    Therefore, the time complexity is O(n^2).
    Space complexity : O(1).

  
Approach 2: Two pointer
To implement this techniques array should be sorted then point front to begging of the array & rear to end of the array. 
Loop through array until front less than rear. Sum up array[front] + array[rear] and check if it matches to target we are looking for.
  
     Complexity Analysis:

      Time complexity : O(nlog(n)). sort function takes nlog(n) time.
      Space complexity : O(1).
  
Approach 3: Hash Table
Extra memory needed for this approach. While we iterate and inserting elements into the table,
we also look back to check if current element's complement already exists in the table. If it exists, we have found a solution and return immediately.
      Complexity Analysis:

      Time complexity : O(n). We traverse the list containing n elements only once. Each look up in the table costs only O(1) time.
      Space complexity : O(n). The extra space required depends on the number of items stored in the hash table, which stores at most n elements.
        
        
 CODE :
 #include<bits/stdc++.h>

using namespace std;

//two pointer solution
vector<int> twoSum(vector<int>& nums, int target) {
    int front = 0, rear = nums.size() - 1;
    sort(nums.begin(), nums.end());
    while(front < rear) {
      int sum = nums[front] + nums[rear];
      if (sum == target)
        break;
      else if (sum > target)
        rear--;
      else
        front++;
    }
    return {front, rear};
};

//brute force solution
vector<int> twoSum(vector<int>& nums, int target) {
    int len = nums.size();
    for(int i = 0; i < len; i++) {
        for(int j = i + 1; j < len; j++) {
            if(nums[j] == target - nums[i])
                return { i, j };
        }
    }
    return {-1, -1};
};
// hash map solution
vector<int> twoSum(vector<int>& nums, int target) {
      map<int, int> map;
      vector<int> pairs;
      for(int i = 0; i < nums.size(); i++) {
          int complement = target - nums[i];
          if(map.find(complement) != map.end()) {
              pairs.push_back(map.find(complement)->second);
              pairs.push_back(i);
              break;
          }
          map.insert(pair<int, int>(nums[i], i));
      }
      return pairs;
};

int main() {
  vector<int>nums = {1,4,3,6,5,8};
  vector<int>pair = twoSum(nums,4);
  cout << "pair indices are : " << pair[0] << " " << pair[1] << endl;
  return 0;
}
