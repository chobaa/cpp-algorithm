#include <iostream>
#include <stack>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    stack<int> st;
    while(n--){
        int op;
        cin >> op;
        if(op == 1){
            int temp;
            cin >> temp;
            st.push(temp);
        }
        else if(op == 2){
            if(st.empty()) cout << -1 << "\n";
            else {
                cout << st.top() << "\n";
                st.pop();
            }
        }
        else if(op == 3){
            cout << st.size() << "\n";
        }
        else if(op == 4){
            if(st.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
        else if(op == 5){
            if(st.empty()) cout << -1 << "\n";
            else cout << st.top() << "\n";
        }
    }
}