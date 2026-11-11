class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        for(int i = nums.size() - 2; i >= 0; i--) {
            if(i + nums[i] >= goal) { // if can reach end from this (dist + jump_size) >= (dist needed)
                goal = i; // set goal to new point we need to reach
            }
        }

        return goal == 0;
    }
};
