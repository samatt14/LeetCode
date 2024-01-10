#include <queue>
#include <cmath>

//TODO: Edit for faster runtime

class Solution {
public:
    int reverse(int x) {
        queue<int> q;

        if(x < 0){
            if(x == -2147483648){
                return 0;
            }
            x*=-1;
            while(x > 0){
                q.push(x%10);
                x = x/10;
            }

            while (!q.empty()) {
                if( ((pow(2,31) - 1)/10) < x){
                    return 0;
                }
                x = x*10;
                x += q.front();
                q.pop();
            }

            return x*=-1;
        }

        while(x > 0){
            q.push(x%10);
            x = x/10;
        }

        while (!q.empty()) {
            if( ((pow(2,31) - 1)/10) < x){
                return 0;
            }
            x = x*10;
            x += q.front();
            q.pop();
        }

        return x;
    }
};
