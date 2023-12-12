function search(nums: number[], target: number): number {
    let min: number = Infinity;
    let minIndex = 0;
    
    function findInflection(lo: number, hi: number) {
        if (lo > hi) {
            return minIndex;
        }
        
        const mid = Math.floor((lo + hi)/2)

        if (nums[mid] >= nums[lo]) {
            if (nums[mid + 1] < min) {
                min = nums[mid + 1];
                minIndex = mid + 1;
            }
            return findInflection(mid + 1, hi);
        } else {
            if (nums[mid - 1] < min) {
                min = nums[mid - 1];
                minIndex = mid - 1;
            }
            return findInflection(0, mid - 1);
        }
        
    }
    const poi = findInflection(0, nums.length - 1);

    // find the appropriate lo and hi
    let lo = 0;
    let hi = nums.length - 1;
    if (target >= nums[lo] && target <= nums[poi - 1]) {
        hi = poi - 1;
    } else if (target <= nums[hi] && target >= nums[poi + 1]) {
        lo = poi + 1;
    } else if (target === nums[poi]) {
        return poi;
    }
    // console.log(lo + " " + hi);
    function bs(lo: number, hi: number) {
        console.log(lo, hi);
        if (lo > hi) {
            return -1;
        }
        
        const mid = Math.floor((lo + hi)/2);
        console.log(mid);
        if (target > nums[mid]) {
            return bs(mid + 1, hi);
        } else if (target < nums[mid]) {
            return bs(lo, mid - 1);
        } else {
            return mid;
        }
    }
    
    return bs(lo, hi);
};