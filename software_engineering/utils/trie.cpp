#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    vector<TrieNode *> children;
    bool isTerminal;
    TrieNode()
    {
        children.resize(26);
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insertWord(string word)
    {
        TrieNode *temp = root;
        for (char itr : word)
        {
            if (temp->children[itr - 'a'])
                temp = temp->children[itr - 'a'];

            else
            {
                temp->children[itr - 'a'] = new TrieNode();
                temp = temp->children[itr - 'a'];
            }
        }
        temp->isTerminal = 1;
    }

    bool isPresent(string word)
    {
        return isPresent(root, word);
    }

    vector<string> getWordsForPrefix(string word)
    {
        vector<string> contacts;
        if (word.length() == 0)
        {
            return contacts;
        }
        TrieNode *curr = root;
        for (auto ch : word)
        {
            TrieNode *next = curr->children[ch - 'a'];
            if (next == NULL)
            {
                return contacts;
            }
            curr = next;
        }
        bool flag = false;
        for (int i = 0; i < 26; i++)
        {
            if (curr->children[i] != NULL)
            {
                flag = true;
            }
        }
        if (flag)
        {
            findAllWordForPrefixRecursively(word, curr, contacts);
        }
        else
        {
            if (curr->isTerminal)
            {
                contacts.push_back(word);
            }
        }
        return contacts;
    }

    void deleteWord(string word)
    {
        deleteWord(root, word);
    }

private:
    bool isEmpty(TrieNode *root)
    {
        for (int i = 0; i < 26; i++)
            if (root->children[i])
                return false;
        return true;
    }
    TrieNode *deleteWord(TrieNode *root, string word, int depth = 0)
    {
        if (!root)
        {
            return NULL;
        }

        if (depth == word.size())
        {
            if (root->isTerminal)
            {
                root->isTerminal = false;
            }
            if (isEmpty(root))
            {
                delete (root);
                root = NULL;
            }
            return root;
        }

        int index = word[depth] - 'a';
        root->children[index] = deleteWord(root->children[index], word, depth + 1);

        if (isEmpty(root) && root->isTerminal == false)
        {
            delete (root);
            root = NULL;
        }
        return root;
    }
    bool isPresent(TrieNode *root, string key)
    {
        TrieNode *pCrawl = root;
        for (int i = 0; i < key.length(); i++)
        {
            int idx = key[i] - 'a';
            if (!pCrawl->children[idx])
            {
                return false;
            }
            pCrawl = pCrawl->children[idx];
        }
        return pCrawl->isTerminal;
    }
    void findAllWordForPrefixRecursively(string prefix, TrieNode *node, vector<string> &words)
    {
        if (node->isTerminal)
        {
            words.push_back(prefix);
        }
        bool flag = false;
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i] != NULL)
            {
                flag = true;
            }
        }
        if (!flag)
        {
            return;
        }

        for (int i = 0; i < 26; i++)
        {
            if (node->children[i] != NULL)
            {
                TrieNode *c = node->children[i];
                char ch = 'a' + i;
                findAllWordForPrefixRecursively(prefix + ch, node->children[i], words);
            }
        }
    }
};

int main()
{
    Trie *dict = new Trie();
    dict->insertWord("harsh");
    dict->insertWord("harasees");
    dict->insertWord("harpreet");
    dict->insertWord("hemant");
    vector<string> v = dict->getWordsForPrefix("d");
    cout<<v.size()<<endl;
    for(auto i : v) {
        cout<<i<<endl;
    }
    return 0;
}