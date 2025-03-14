class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        return isValid(derived, 0, n) || isValid(derived, 1, n);
    }
    
private:
    bool isValid(vector<int>& derived, int first, int n) {
        vector<int> original(n);
        original[0] = first;
        
        // Build the original array using XOR logic
        for (int i = 1; i < n; i++) {
            original[i] = original[i - 1] ^ derived[i - 1];
        }
        
        // Check circular condition: original[n-1] ⊕ original[0] == derived[n-1]
        return (original[n - 1] ^ original[0]) == derived[n - 1];
    }
};
