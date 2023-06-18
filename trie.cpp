class Node
{
public:
    bool end;
    Node *links[26];
    Node()
    {
        end = false;
        for (int i = 0; i < 26; i++)
            links[i] = NULL;
    }
    void setend()
    {
        this->end = true;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *temp = root;
        int i = 0, n = word.length();
        while (i < n)
        {
            if (temp->links[word[i] - 'a'] == NULL)
                temp->links[word[i] - 'a'] = new Node();
            temp = temp->links[word[i] - 'a'];
            i++;
        }
        temp->setend();
    }

    bool search(string word)
    {
        Node *temp = root;
        int i = 0, n = word.size();
        while (i < n)
        {
            if (temp->links[word[i] - 'a'] == NULL)
            {
                return false;
            }
            temp = temp->links[word[i] - 'a'];
            i++;
        }
        return temp->end;
    }

    bool startsWith(string word)
    {
        Node *temp = root;
        int i = 0, n = word.size();
        while (i < n)
        {
            if (temp->links[word[i] - 'a'] == NULL)
                return false;
            temp = temp->links[word[i] - 'a'];
            i++;
        }
        return true;
    }
};
