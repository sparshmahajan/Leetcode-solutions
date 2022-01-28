class WordDictionary {
    unordered_map<int,vector <string>> words;
    
    bool isEqual(string str1,string str2){
        for(int i=0;i<str2.length();i++){
            if(str2[i]=='.') continue;
            if(str1[i] != str2[i]) return false;
        }
        return true;
    }
    
public:
    WordDictionary() {
    }
    
    void addWord(string word) {
        words[word.length()].push_back(word);
    }
    
    bool search(string word) {
        for(auto &&s : words[word.length()])
            if(isEqual(s,word)) return true;
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */