#include<algorithm>
#include<map>//�õ�hash map 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        std::map<int, int> map1;
        for (int i = 0; i < nums.size(); i++) {
        	map1.insert(make_pair(nums[i], i));//map��insert key-value��ʱ��ע����Ҫ����ת��Ϊ pair �ſ��Բ��� 
    	}
        for(int i = 0;i<nums.size();i++)
        {   
         int complement = target - nums[i];
        if (map1.count(complement) && map1[complement] != i) {
            result.push_back(i);
            result.push_back(map1[complement] );
            
            return  result;}
                    
            }
        }
        
};