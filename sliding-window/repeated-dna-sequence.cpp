#include <unordered_map>
#include <string>
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        //slide the window and store each window in a hashMap
        //record the count for each window in the hashMap
        // iterate through hashMap and see which strings have greater than 1 frequency and store strings in result vector
        unordered_map<string, int> window_frequency;
        std::vector<string> result;

    if (s.size() <= 10) {
        return result;
    }

    int left = 0;
    for (int right = 9; right < s.size(); right++) {
        string window = s.substr(left, 10);
        window_frequency[window]++;
        left++;
    }

    for (const auto& pair : window_frequency) {
        if (pair.second > 1) {
            result.push_back(pair.first);
        }
    }

    return result;

        
    }
};
