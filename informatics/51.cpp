#include <iostream>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

int main()
{
    const char * open  = "[{(";
    const char * close = "]})";
    stack<char> st;
    string s;
    getline(cin, s);
    for(char c: s)
    {
        if (strchr(open,c)) st.push(c); 
        else if (const char * cp = strchr(close,c); cp)
        {
            if (st.empty() || ((strchr(open,st.top()) - open) != (cp - close))) 
            { st.push(c); break; }
            st.pop();
        }
    }
    cout << (st.empty() ? "yes" : "no");
}