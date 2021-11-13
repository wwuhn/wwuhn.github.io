#include <stdio.h>
#include <iostream>
using namespace std;

struct Node{
    int n;
    struct Node * next;
    //Node(int i):n(i){next=NULL;} // 定义了构造，则是类，类不能整体赋值，结构体可以
};


void initList(Node*& head)  // 头节点是空节点
{ 
    for(int i=0;i<10;i++)
    {
        Node * newNode = new Node;
        newNode->n = i+1*10;
        newNode->next = NULL;
        
        if(i==0)
            head->next = newNode;
        else
            newNode->next = head->next;
        head->next = newNode;
    }
}

void insert(Node*& head, int i)  // 头节点是空节点
{ 

        Node * newNode = new Node;
        newNode->n = i;
        newNode->next = NULL;
        
        if(i==0)
            head->next = newNode;
        else
            newNode->next = head->next;
        head->next = newNode;

}

void initList2(Node*& head)  // 头节点是实节点
{
    Node * tailNode;  
    for(int i=0;i<10;i++)
    {
        Node * newNode = new Node;
        newNode->n = i+1*10;
        newNode->next = NULL;
        
        if(i==0)
            head = newNode;
        else
            tailNode->next = newNode;
        tailNode = newNode; // 头节点以后首次也指向了头指点
    }
}

void showList(Node* head)   // 头节点是空节点
{
    Node* pMove = head->next;
    while(pMove != NULL)
    {
        cout<<pMove->n<<" ";
        pMove = pMove->next;
    }
    cout<<endl;
}

void showList2(Node* head)  // 头节点是实空节点
{
    Node* pMove = head;
    while(pMove != NULL)
    {
        cout<<pMove->n<<" ";
        pMove = pMove->next;
    }
    cout<<endl;
}

int main()
{
    Node *head = new Node;
    initList(head);
    insert(head,999);
    showList(head);
    Node *head2;
    initList2(head2);
    showList2(head2);
restart:   

	
    goto restart;
    return 0;
}
/*
#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
    printf("");
    while(1); // pause
    cin.ignore(32767, '\n'); // ignore up to 32767 characters until a \n is removed
    system("pause");
    getchar();
*/