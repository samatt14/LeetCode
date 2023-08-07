class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        int i = 0;
        int j = 0;
        int lastindex = -1;
             
        //create a new sorted array
        vector<int> v(size1 + size2, 0);
        
        while(i < size1 && j < size2)
        {
            ++lastindex;
            if(nums1[i]<=nums2[j]){
                v[lastindex] = nums1[i];
                i++;
            }
            else{
                v[lastindex]=nums2[j];
                j++;
            }
        }
        
        //apend what's left of the new arrays to the new array
        while(i < size1){
            ++lastindex;
            v[lastindex]=nums1[i];
            i++;
        }
        while(j < size2){
            ++lastindex;
            v[lastindex]=nums2[j];
            j++;
        }
        
        if((size1 + size2)%2 == 0){
            return (v[(size1 + size2) / 2] + v[((size1 + size2) / 2) - 1]) / 2.0;
        }
        else{
            return v[(size1 + size2) / 2];
        }
        
    }
};
