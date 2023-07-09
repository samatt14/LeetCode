class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> returnVec;

        map<int, int> map;

        for(int  i = 0; i != nums.size(); ++i){
            int solution = target - nums.at(i);

            if(map.find(solution) == map.end()){
                map[nums.at(i)] = i;
            }
            else{
                returnVec.push_back(map[solution]);
                returnVec.push_back(i);
                return returnVec;
            }
        }
        return returnVec;
    }
};
