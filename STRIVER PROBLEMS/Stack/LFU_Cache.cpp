struct Node
{
    int key, val, cnt;
    Node *next;
    Node *prev;
    Node(int _key, int _val)
    {
        key = _key;
        val = _val;
        cnt = 1;
    }
};

struct List
{
    int size;
    Node *head;
    Node *tail;
    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        size++;
    }

    void removeNode(Node *delnode)
    {
        Node *delprev = delnode->prev;
        Node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCache
{
    map<int, Node *> keyNode;
    map<int, List *> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;

public:
    LFUCache(int capacity)
    {
        maxSizeCache = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void update(Node *node)
    {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
        {
            minFreq++;
        }

        List *nexthigher = new List();
        if (freqListMap.find(node->cnt + 1) != freqListMap.end())
        {
            nexthigher = freqListMap[node->cnt + 1];
        }
        node->cnt += 1;
        nexthigher->addFront(node);
        freqListMap[node->cnt] = nexthigher;
        keyNode[node->key] = node;
    }

    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            int val = node->val;
            update(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (maxSizeCache == 0)
        {
            return;
        }
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            node->val = value;
            update(node);
        }
        else
        {
            if (curSize == maxSizeCache)
            {
                List *listFreq = freqListMap[minFreq];
                keyNode.erase(listFreq->tail->prev->key);
                freqListMap[minFreq]->removeNode(listFreq->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;
            List *listfreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end())
            {
                listfreq = freqListMap[minFreq];
            }
            Node *node = new Node(key, value);
            listfreq->addFront(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listfreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */