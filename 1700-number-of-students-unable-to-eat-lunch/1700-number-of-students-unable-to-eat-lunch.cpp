class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        for (int i = 0; i < sandwiches.size();) {
            if (students.front() == sandwiches[i]) {
                students.erase(students.begin());
                i++;
                continue;
            } else {
                auto temp = students.front();
                students.erase(students.begin());
                students.push_back(temp);
            }
            cout << i << "\n";
            if (accumulate(students.begin(), students.end(), 0) == students.size() && sandwiches[i] == 0) {
                return students.size();
            } else if (accumulate(students.begin(), students.end(), 0) == 0 && sandwiches[i] == 1) {
                return students.size();
            }
            
        }
        return 0;
    }
};