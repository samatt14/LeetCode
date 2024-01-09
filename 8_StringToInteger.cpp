class Solution {
public:
    int myAtoi(string s) {
        bool posOrNeg = true; //assume positive
        string tmp = "";
        int ans = 0;
        int firstIndex = 0;

        for(int i = 0; i < s.length(); i++){
            if(s.at(i) == ' '){
                ++firstIndex;
            }
            else{
                break;
            }
        }

        if(firstIndex >= s.length()){
            return 0;
        }

        if(s.at(firstIndex) == '+'){
            firstIndex += 1;
        }
        else if(s.at(firstIndex) == '-'){
            posOrNeg = false; 
            firstIndex += 1;
        }

        for(int i = firstIndex; i < s.length(); i++){
            if(s.at(i) >= '0' && s.at(i) <= '9'){
                tmp += s.at(i);
            }
            else{
                break;
            }
        }
        if(tmp == ""){
            return 0;
        }

        for(int i = 0; i < tmp.length(); i++){
            int num = tmp.at(i) - '0';
            int64_t result = (int64_t)ans * 10;
            result += num;
            if(posOrNeg && result >= INT_MAX){
                return INT_MAX;
            }   
            if(!posOrNeg && (result * -1) <= INT_MIN){
                return INT_MIN;
            }    
            ans = result;
        }

        if(posOrNeg == false){
            ans = ans * -1;
        }
        return ans;
    }
};
