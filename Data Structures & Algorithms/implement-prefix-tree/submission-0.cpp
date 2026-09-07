class PrefixTree {
public:

    PrefixTree* child[26];
    bool end;

    PrefixTree() {
        end=false;
        for(int i=0; i<26; i++){
            child[i]=NULL;
        }
    }
    
    void insert(string word) {
        PrefixTree* curr=this;
        for(char c: word){
            int x=c-'a';
            if(curr->child[x]==NULL){
                curr->child[x]=new PrefixTree();
            }
            curr=curr->child[x];
        }
        curr->end=true;
    }
    
    bool search(string word) {
        PrefixTree* curr = this;
        for(char c : word) {
            int x = c - 'a';
            if(curr->child[x] == NULL)
                return false;
            curr = curr->child[x];
        }
        return curr->end;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* cur = this;
        for(char c : prefix) {
            int x = c - 'a';
            if(cur->child[x] == NULL)
                return false;
            cur = cur->child[x];
        }
        return true;
    }
};
