#include "bits/stdc++.h"
using namespace std;

using i64 = long long;

constexpr int ALPHABET_SIZE = 26;

vector<vector<int>> buildAutomata(const string &pattern)
{
    int m = size(pattern);
    auto longestSuffixWhichIsPrefixOfPattern = [&](string &s)
    {
        int sz = size(s);
        for (int len = sz - 1; len > 0; len--)
        {
            if (s.substr(sz - len, len) == pattern.substr(0, len))
                return len;
        }

        return 0;
    };

    auto getNextState = [&](int state, int x)
    {
        char ch = char(x + 'a');
        if (pattern[state] == ch)
            return state + 1;

        // Find longest suffix of s = (pattern[0...state] + x) 
        // which is a prefix of pattern.
        auto s = pattern.substr(0, state);
        s += ch;
        return longestSuffixWhichIsPrefixOfPattern(s);
    };

    vector aut(m, vector(ALPHABET_SIZE, 0));
    for (int i = 0; i < m; i++)
    {
        for (int ch = 0; ch < 26; ch++)
            aut[i][ch] = getNextState(i, ch);
    }

    return aut;
}

int finiteAutomataStringMatching(string text, string pattern)
{
    int n = size(text);
    int m = size(pattern);

    auto aut = buildAutomata(pattern);
    int state = 0;

    vector<int> matches;
    for (int i = 0; i < n; i++)
    {
        state = aut[state][text[i] - 'a'];
        if (state == m)
            return i  - m + 1;
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string text, pattern;
    cin >> text >> pattern;

    int match = finiteAutomataStringMatching(text, pattern);
    if (match == -1)
        cout << "Not Found\n";
    else
        cout << "Match found at index: " << match << "\n";
    
    return 0;
}