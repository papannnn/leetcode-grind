class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (target == nums[mid]) {
                return mid;
            }

            if (target == nums[l]) {
                return l;
            }

            if (target == nums[r]) {
                return r;
            }
            
            if (nums[l] < nums[mid]) {

                if (nums[l] <= target && nums[mid] >= target) {
                    
                    if (nums[mid] < target) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }

                } else {
                    l = mid + 1;
                }

            } else {
                
                if (nums[mid] <= target && nums[r] >= target) {
                    
                    if (nums[mid] < target) {
                        l = mid + 1;
                    } else {
                        r = mid - 1;
                    }

                } else {
                    r = mid - 1;
                }
            }
        }   
        
        return -1;
    }
};
