class Solution {
public:
    string convert(string s, int numRows) {

        int length = s.length();

        vector<char> V[numRows];

        int currRow = 0;
        bool dir = true;

        if(numRows == 1){
            return s;
        }

        for(int i = 0; i < length; ++i){
            V[currRow].push_back(s.at(i));
            if(currRow == 0){
                dir = true;
            }
            if(currRow == numRows - 1){
                dir = false;
            }
            if(dir == true){
                currRow = currRow + 1;
            }
            else{ //dir == false;
                currRow = currRow - 1;
            }
        }

        string returnString = "";

        for(int i = 0; i < numRows; ++i){
            for(auto it = V[i].begin(); it!=V[i].end(); it++) {
                returnString += *it;
            }
        }

        return returnString;
        
    }
};
