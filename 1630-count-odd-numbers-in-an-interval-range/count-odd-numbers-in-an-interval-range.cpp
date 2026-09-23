class Solution {
public:
    int countOdds(int low, int high) {
        int c=0,i=low;
        while(i<=high){
            if(i%2==1){
                c++;
            }
            i++;
        }return c;
    }
};