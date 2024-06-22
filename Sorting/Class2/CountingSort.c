class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        int n = nums.size();

        int size = mx - mn + 2;
        vector<int> cnt(size, 0);
        for(int i=0; i<n; i++) {
            cnt[nums[i] - mn]++;
        }

        int ind = 0;
        for(int i=0; i<size; i++) {
            if(cnt[i] > 0) {
                for(int j=0; j<cnt[i]; j++) {
                    nums[ind] = i + mn;
                    ind++;
                }
            }
        }
        return nums;
    }
};