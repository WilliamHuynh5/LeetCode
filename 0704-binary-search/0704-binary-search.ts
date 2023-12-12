function search(nums: number[], target: number): number {
    
    function bs(lo: number, hi: number): number {
        if (lo > hi) {
            return -1;
        }
        
        const mid: number = Math.floor((lo + hi) / 2);
        if (target > nums[mid]) {
            return bs(mid + 1, hi);
        } else if (target < nums[mid]) {
            return bs(lo, mid - 1);
        } else {
            return mid;
        }
    }
    return bs(0, nums.length - 1);
};