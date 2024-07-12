class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_count = 0;
        int one_count = 0;
        int two_count = 0;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                zero_count++;
            }
            else if (nums[i] == 1){
                one_count++;
            }
            else if (nums[i] == 2){
                two_count++;
            }
        }
        
        int j = 0;
        for(; j < zero_count; j++){
            nums[j] = 0;
        }
        for(; j < zero_count + one_count; j++){
            nums[j] = 1;
        }
        for(; j < nums.size(); j++){
            nums[j] = 2;
        }
    }
};
