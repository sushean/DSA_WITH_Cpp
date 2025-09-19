class Solution {
public:
    bool isAnagram(string s, string t) {
        
        transform(s.begin(),s.end(),s.begin(),::tolower);
        transform(t.begin(),t.end(),t.begin(),::tolower);

        s.erase(remove_if(s.begin(),s.end(),[](char c){return isspace(c);}),s.end());
        t.erase(remove_if(t.begin(),t.end(),[](char c){return isspace(c);}),t.end());

        if (s.size() != t.size()) return false;

        int buck_array[26] = {0};
        int x = 0; 
        for(char i :s )
        {
            buck_array[i -'a']++;
            buck_array[t[x] -'a']--;
            x++;
        }
        for (int i :buck_array) {
            if (i != 0) return false;
        }
        return true; 

    }
};