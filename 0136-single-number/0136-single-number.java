class Solution {
    public int singleNumber(int[] nums) {
        HashMap<Integer, Integer> m = new HashMap<Integer, Integer>();
        for (int elem : nums) {
            if (m.containsKey(elem)) {
                m.put(elem, m.get(elem) + 1);
            } else {
                m.put(elem, 1);
            }
        }
        for (Map.Entry<Integer, Integer> elem : m.entrySet()) {
            if (elem.getValue() == 1) {
                return elem.getKey();
            }
        }
        return 0;
    }
}