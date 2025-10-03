class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;
        int size= s.size();
        for(int i=0;i<size;i++){
            char ch=s[i];
            st.push(ch);
        }
       
     for(int i=0;i<size;i++){
        s[i] = st.top();
        st.pop();
       }
    }
};