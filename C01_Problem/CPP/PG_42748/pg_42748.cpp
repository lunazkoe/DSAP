#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int t1 = 0; t1 < commands.size(); t1++) {
        int i = commands[t1][0];
        int j = commands[t1][1];
        int k = commands[t1][2];
        
        vector<int> tmp;
        for (int t2 = i - 1; t2 <= j - 1; t2++) {
            tmp.push_back(array[t2]);
        }
        
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[k - 1]);
    }
    
    return answer;
}