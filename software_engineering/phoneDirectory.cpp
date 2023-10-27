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

class Contact
{
public:
    string name;
    vector<string> phoneNumbers;
    Contact(string name, vector<string> phoneNumbers)
    {
        this->name = name;
        this->phoneNumbers = phoneNumbers;
    }
    Contact() {}
};

class PhoneDirectory
{
    map<string, Contact> directory;
    Trie *names;

public:
    PhoneDirectory()
    {
        names = new Trie();
        directory.clear();
    }
    void createContact(Contact contact)
    {
        string name = contact.name;
        directory[name] = contact;
        names->insertWord(name);
    }

    void updateContact(string name, Contact contact)
    {
        directory[contact.name] = contact;
    }

    bool isPresent(string name)
    {
        return directory.count(name) != 0;
    }

    vector<Contact> searchContact(string name)
    {
        vector<Contact> searchResults;
        vector<string> namesList = names->getWordsForPrefix(name);
        for (string name : namesList)
        {
            searchResults.push_back(directory[name]);
        }
        return searchResults;
    }

    void deleteContact(string name)
    {
        names->deleteWord(name);
        directory.erase(directory.find(name));
    }

    void showDirectory()
    {
        cout << "Name"
             << "\t|\t"
             << "Numbers" << endl;
        for (pair<string, Contact> it : directory)
        {
            cout << it.first << '\t';
            for (string number : it.second.phoneNumbers)
            {
                cout << number << ',';
            }
            cout << endl;
        }
    }
};

int main()
{
    cout << "-----------------------------" << endl;
    cout << "Welcome to phone directory..." << endl;
    cout << "-----------------------------" << endl;

    PhoneDirectory directory;

    while (true)
    {
        cout << "Options: \n 1. Create \n 2. Update \n 3. Delete \n 4. Search \n 5. Show \n 6. Exit" << endl;
        cout << "Select an option: ";
        int i;
        cin >> i;
        if (i == 1)
        {
            // create
            cout << "Enter the following details: " << endl;
            string name, number;
            vector<string> numbers;
            int cnt;
            cout << "Enter the name: ";
            cin >> name;
            cout << "Enter the count of numbers: ";
            cin >> cnt;
            for (int i = 0; i < cnt; i++)
            {
                cout << "Number " << i << ": ";
                cin >> number;
                numbers.push_back(number);
            }
            Contact newContact = Contact(name, numbers);
            directory.createContact(newContact);
            cout << "Contact created" << endl;
        }
        else if (i == 2)
        {
            // update
            cout << "Name of contact to be updated: ";
            string name;
            cin >> name;
            if (directory.isPresent(name))
            {
                cout << "Saved details: " << endl;
                vector<Contact> contact = directory.searchContact(name);
                cout << contact[0].name << ": ";
                for (auto num : contact[0].phoneNumbers)
                {
                    cout << num << ", ";
                }
                cout<<endl;
            }
            else
            {
                cout << "No contact with that name." << endl;
                continue;
            }
            cout << "Enter new details: " << endl;
            directory.deleteContact(name);
            cout << "Name: ";
            cin >> name;
            cout << "Enter the count of numbers: ";
            int cnt;
            string number;
            vector<string> numbers;
            cin >> cnt;
            for (int i = 0; i < cnt; i++)
            {
                cout<<"Number "<<i+1<<": ";
                cin >> number;
                numbers.push_back(number);
            }
            Contact newContact = Contact(name, numbers);
            directory.createContact(newContact);
            cout << "Contact updated" << endl;
        }
        else if (i == 3)
        {
            // delete
            cout << "Enter the name of contact: ";
            string name;
            cin >> name;
            if (directory.isPresent(name))
            {
                directory.deleteContact(name);
            }
            else
            {
                cout << "No contact with that name." << endl;
                continue;
            }
            cout << "Contact deleted" << endl;
        }
        else if (i == 4)
        {
            // search
            cout << "Enter the name prefix: " << endl;
            string name;
            cin >> name;
            cout << "Search results" << endl;
            vector<Contact> results = directory.searchContact(name);
            cout << "Name"
                 << "\t|\t"
                 << "Numbers" << endl;
            for (Contact result : results)
            {
                cout << result.name << "\t|\t";
                for (auto num : result.phoneNumbers)
                {
                    cout << num << ", ";
                }
                cout << endl;
            }
        }
        else if (i == 6)
        {
            cout << "-------" << endl;
            cout << "Bye bye" << endl;
            break;
        }
        else if (i == 5)
        {
            directory.showDirectory();
        }
        else
        {
            cout << "Please enter a vaild option" << endl;
        }
    }

    return 0;
}