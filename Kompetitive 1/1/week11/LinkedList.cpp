#include <stdio.h>

using namespace std;

class Node
{
public:
    int info;
    Node *next;

    Node()
    {
        info = 0;
        next = NULL;
    }

    Node(int _info)
    {
        info = _info;
        next = NULL;
    }
};

/*
    isinya terurut, dan unik
*/
class LinkedList
{
public:
    Node *head;
    int size;

    LinkedList()
    {
        head = NULL;
        size = 0;
    }

    void print();
    bool insert(int newInfo);
    bool remove(int info);
    bool find(int info);
};

int main()
{
    LinkedList linkedList;

    linkedList.insert(10);
    linkedList.insert(10);
    linkedList.insert(3);
    linkedList.insert(2);
    linkedList.insert(4);
    linkedList.insert(10);
    linkedList.insert(7);
    linkedList.insert(7);
    linkedList.insert(2);
    linkedList.insert(2);

    printf("REMOVE 10: %d\n", linkedList.remove(10));
    printf("REMOVE 2: %d\n", linkedList.remove(2));
    printf("REMOVE 11: %d\n", linkedList.remove(11));

    linkedList.insert(11);

    printf("FIND 4: %d\n", linkedList.find(4));
    printf("FIND 10: %d\n", linkedList.find(10));

    linkedList.print();
}

void LinkedList::print()
{
    Node *curNode = head;

    while (curNode != NULL)
    {
        printf("%d ", curNode->info);
        curNode = curNode->next;
    }
    printf("\n");
}

bool LinkedList::insert(int newInfo)
{
    Node *newNode = new Node(newInfo);

    if (head == NULL)
    {
        head = newNode;
    }
    else if (head->info >= newInfo)
    {
        if (head->info == newInfo)
            return false;
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    else
    {
        Node *smallerIdx = head;
        Node *biggerIdx = head->next;

        while (biggerIdx != NULL && biggerIdx->info < newInfo)
        {
            smallerIdx = biggerIdx;
            biggerIdx = biggerIdx->next;
        }

        if (biggerIdx == NULL)
        {
            smallerIdx->next = newNode;
            return true;
        }

        if (biggerIdx->info == newInfo)
            return false;

        newNode->next = biggerIdx;
        smallerIdx->next = newNode;
    }

    return true;
}

bool LinkedList::remove(int deleteInfo)
{
    Node *beforeCur = head;
    Node *curNode = head;

    while (curNode != NULL && curNode->info < deleteInfo)
    {
        beforeCur = curNode;
        curNode = curNode->next;
    }

    if (curNode == NULL || curNode->info != deleteInfo)
        return false;

    beforeCur->next = curNode->next;
    return true;
}

bool LinkedList::find(int findInfo)
{
    Node *curNode = head;

    while (curNode != NULL && curNode->info < findInfo)
        curNode = curNode->next;

    if (curNode == NULL)
        return false;

    return curNode->info == findInfo;
}
