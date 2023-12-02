type Fn = (n: number, i: number) => any

function filter(arr: number[], fn: Fn): number[] {
	let res: number[] = [];
    
    for (const index in arr) {
        if (fn(arr[index], parseInt(index))) {
            res.push(arr[index]);
        }
    }
    return res;
};