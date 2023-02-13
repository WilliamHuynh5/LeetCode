class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] sorted = new int[nums.length];
        System.arraycopy(nums, 0, sorted, 0, nums.length);
        int[] res = new int[nums.length];
        Arrays.sort(sorted);
        int i = 0;
        for (int elem : nums) {
            int idx = getIndex(sorted, elem);
            res[i] = idx;
            i++;
        }
        return res;
    }
    
    public int getIndex(int[] nums, int target) {
        int i = 0;
        for (int elem : nums) {
            if (elem == target) {
                return i;
            }
            i++;
        }
        return -1;
    }
}