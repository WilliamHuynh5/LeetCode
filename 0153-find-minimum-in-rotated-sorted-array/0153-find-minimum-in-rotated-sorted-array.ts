function findMin(nums: number[]): number {
    // Find point of inflection and its index
    // do regular binary search, but substitute the half with POI
    
    let min: number = nums[0];
    
    function bs (lo: number, hi: number) {  
        if (lo > hi) {
            return min;
        }
        
        let mid = Math.floor((lo + hi)/2)

        
        if (nums[mid] >= nums[lo]){
            if (nums[mid + 1] < min) {
                min = nums[mid + 1];
            }
            return bs(mid+1, hi);
        } else {
            if (nums[mid - 1] < min) {
                min = nums[mid - 1];
            }
            return bs(0, mid - 1);
        }
    }
    bs(0, nums.length - 1);
    return min;
    
};