class Solution {
public:
    int romanToInt(string s) {

        int sum = 0;
        int tmp1;
        int tmp2;
        int i = 0;

        while(i < s.length() - 1){
            tmp1 = LetterToValue(s.at(i));
            tmp2 = LetterToValue(s.at(i + 1));

            if(tmp1 < tmp2){
                sum += (tmp2 - tmp1);
                ++i;
            }
            else{
                sum += tmp1;
            }
            ++i;
        }
        if(i == s.length() - 1){
            sum += LetterToValue(s.at(i));
        }

        return sum;
    }

    int LetterToValue(char c){
        switch(c){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M': 
                return 1000;
            default:
                return 0;
        }
    }
};
