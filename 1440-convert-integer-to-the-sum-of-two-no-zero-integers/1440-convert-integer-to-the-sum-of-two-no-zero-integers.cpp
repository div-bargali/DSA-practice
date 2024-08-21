class Solution {
public:
    bool isNon(int n){
        while(n){
            if(n%10==0) return false;
            n/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> v;
        for(int i=1;i<=n/2;i++){
            if(isNon(i)&&isNon(n-i)){
                v={i,n-i};
                return v;
            }
        }
        return v;
    }
};