class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int result = 0;
        int lastIndex = -1;

        map<char, int> currentSubstring;

        for(int i = 0; i < s.length(); ++i){
            if(currentSubstring.find(s.at(i)) != currentSubstring.end()){
                int tmp = currentSubstring.at(s.at(i));
                if(tmp > lastIndex){
                    lastIndex = tmp;
                }
                currentSubstring[s.at(i)] = i;
            }
            else{
                currentSubstring.emplace(s.at(i), i);
            }
            if(i - lastIndex > result){
                    result = i - lastIndex;
            }
        }

        return result;
        
    }
};
