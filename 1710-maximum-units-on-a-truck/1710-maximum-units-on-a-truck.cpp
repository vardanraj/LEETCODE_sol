class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](vector<int>& a, vector<int>& b){
            return a[1] > b[1];
        });


        int ans = 0;
        for(auto c : boxTypes){
            int boxes = c[0];
            int units = c[1];

            if(truckSize >= boxes){
                ans+= boxes*units;
                truckSize -= boxes;
            }
            else{
                ans += truckSize*units;
                return ans;
            }
        }
        return ans;
    }
};