impl Solution {
    pub fn find_middle_index(nums: Vec<i32>) -> i32 {
        let initial_sum:i32 = nums.iter().sum();
        let mut ret_val:i32 = -1;

        let mut sum: i32 = 0;

        for(i, el) in nums.iter().enumerated() {
            if sum == (initial_sum - sum - nums[i]) {
                ret_val = i as i32;
                break;
            }

            sum += nums[i];
        }

        ret_val
    }
}