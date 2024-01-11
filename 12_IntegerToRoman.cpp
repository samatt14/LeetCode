class Solution {
public:
    string intToRoman(int num) {
        string ans = "";

        int n = num/1000;

        for(int i = 0; i < n; ++i){
            ans += "M";
        }
        num -= n*1000;

        if(num - 900 >= 0){
            ans += "CM";
            num -= 900;
        }

        n = num/500;

        for(int i = 0; i < n; ++i){
            ans += "D";
        }
        num -= n*500;

        if(num - 400 >= 0){
            ans += "CD";
            num -= 400;
        }

        n = num/100;

        for(int i = 0; i < n; ++i){
            ans += "C";
        }
        num -= n*100;

        if(num - 90 >= 0){
            ans += "XC";
            num -= 90;
        }

        n = num/50;

        for(int i = 0; i < n; ++i){
            ans += "L";
        }
        num -= n*50;

        if(num - 40 >= 0){
            ans += "XL";
            num -= 40;
        }

        n = num/10;

        for(int i = 0; i < n; ++i){
            ans += "X";
        }
        num -= n*10;

        if(num - 9 >= 0){
            ans += "IX";
            num -= 9;
        }

        n = num/5;

        for(int i = 0; i < n; ++i){
            ans += "V";
        }
        num -= n*5;

        if(num - 4 >= 0){
            ans += "IV";
            num -= 4;
        }

        for(int i = 0; i < num; ++i){
            ans += "I";
        }

        return ans;
    }
};
