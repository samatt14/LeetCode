class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);

        if(str.size() == 0){
            return false;
        }

        int i = 0;
        int j = str.size() - 1;

        while(i <= j){
            if(str.at(i) != str.at(j)){
                return false;
            }

            i = i + 1;
            j = j - 1;
        }

        return true;
        
    }
};
