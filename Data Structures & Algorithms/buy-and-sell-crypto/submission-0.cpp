class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0;
        int sell = 0;
        int currentTransaction = 0;
        int maxProfit = 0;
        int n = prices.size();
        for(int i=0;i<n-1;i++){
            buy = prices[i];
            for(int j=i+1;j<n;j++){
                sell = prices[j];
                currentTransaction = sell-buy;
                maxProfit = max(currentTransaction,maxProfit);
            }
        }
        return maxProfit;
        
    }
};
