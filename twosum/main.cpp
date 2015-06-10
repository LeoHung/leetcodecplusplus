#include<iostream>
#include<vector>
#include<map>
using namespace std;
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, vector<int>* > cache;
    vector<int> ret; 
    for (int n_i = 0; n_i < nums.size(); n_i++) {
      if (cache[nums[n_i]] == NULL) {
        cache[nums[n_i]] = new vector<int>();
      }
      cache[nums[n_i]]->push_back(n_i);
    }

    for (int n_i = 0; n_i < nums.size(); n_i++) {
      int n2 = target - nums[n_i];
      if (cache[n2] == NULL) {
        continue;
      }
      if (cache[n2]->size() >= 2) {
        ret.push_back(n_i+1);
        ret.push_back((*cache[n2])[1]+1);
        return ret;
      }else if (cache[n2]->size() == 1 && (*cache[n2])[0] != n_i) {
        ret.push_back(n_i+1);
        ret.push_back((*cache[n2])[0]+1);
        return ret;
      }
    }
    return ret;
  }
};

void test(int test[], int tN, int target) {
  vector<int> nums;
  for(int i = 0; i < tN; i++) nums.push_back(test[i]);

  vector<int> ret = Solution().twoSum(nums, target);

} 

int main(){
  /*
  int input[] = {2, 7, 11, 15};
  vector<int> nums;
  for(int i = 0; i < 4; i++) nums.push_back(input[i]);

  vector<int> ret = Solution().twoSum(nums, 9);
  cout << ret[0] << "\t" << ret[1] << endl;
  */
  int input_1[] = {2, 7, 11, 15};
  test(input_1, 4, 9);
  int input_2[] = {3, 2, 4};
  test(input_2, 3, 6);
}
