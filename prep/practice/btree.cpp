#include <bits/stdc++.h>
using namespace std;

class BTreeNode
{
    int *keys;
    int t;
    BTreeNode **children;
    int n;
    bool leaf;

public:
    BTreeNode(int _t, bool _leaf);
    void traverse();
    BTreeNode *search(int k);
    friend class BTree;
};

class BTree
{
    BTreeNode *root;
    int t;

public:
    BTree(int _t)
    {
        root = nullptr;
        t = _t;
    }

    void traverse()
    {
        if (root != nullptr)
        {
            root->traverse();
        }
        BTreeN
    }
};