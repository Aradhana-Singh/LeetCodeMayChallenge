/* Ransom Note*/

/* Given an arbitrary ransom note string and another string containing letters 
from all the magazines, write a function that will 
return true if the ransom note can be constructed from the magazines ; 
otherwise, it will return false.
Each letter in the magazine string can only be used once in your ransom note.*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> vct(26,0);
        for(int i = 0; i<ransomNote.size(); i++){
            vct[ransomNote[i]-'a']++;
        }
        for(int i = 0; i<magazine.size(); i++){
            vct[magazine[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(vct[i]>0) return false;
        }
        return true;
    }
};