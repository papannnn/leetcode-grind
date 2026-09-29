class NumArray {
public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size());

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            prefix[i] = sum;
        }
    }
    
    int sumRange(int left, int right) {
        int rightVal = prefix[right];
        int leftMinus = 0;
        if (left != 0) {
            leftMinus = prefix[left - 1];
        }
        return rightVal - leftMinus;
    }

private:
    vector<int> prefix;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */