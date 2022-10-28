
#pragma once
enum RelationType {LESS, EQUAL, GREATER};
template <class ItemType> struct NodeType;
template <class ItemType>
class SortedType
{
public:
    SortedType();  // class constructor
    ~SortedType(); // class destructor

    bool IsFull() const;
    int GetLength() const;
    void MakeEmpty();
    ItemType GetItem(ItemType item);
    void PutItem(ItemType item);
    void DeleteItem(ItemType item);
    void ResetList();
    ItemType GetNextItem();
    RelationType ComparedTo(ItemType value, ItemType otherItem);
 private : 
    NodeType<ItemType> *listData;
    int length;
    NodeType<ItemType> *currentPos;
};
/*
template <class ItemType>
void FindItem(NodeType<ItemType> *listData, ItemType item,
              NodeType<ItemType> *&location, NodeType<ItemType> *&predLoc, bool &found)
{
    bool moreToSearch = true;

    location = listData->next;
    predLoc = listData;
    found = false;
    while
}*/
template <class ItemType>
struct NodeType
{
    ItemType info;
    NodeType<ItemType> *next;
};
template <class ItemType>
SortedType<ItemType>::SortedType()
{
    length = 0;
    listData = NULL;
}

template <class ItemType>
bool SortedType<ItemType>::IsFull() const
{
    NodeType<ItemType>* location;
    try
    {
        location = new NodeType<ItemType>;
        delete location;
        return false;
    }
    catch (std::bad_alloc exception)
    {
        return true;
    }
}

template <class ItemType>
int SortedType<ItemType>::GetLength() const
{
    return length;
}

template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
{
    NodeType<ItemType> *tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}

template <class ItemType>
ItemType SortedType<ItemType>::GetItem(ItemType item)
{
    bool moreToSearch;
    NodeType<ItemType>* location;

    location = listData;
    bool found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found)
    {
        switch (ComparedTo(item, location->info))
        {
        case GREATER:
            location = location->next;
            moreToSearch = (location != NULL);
            break;
        case EQUAL:
            found = true;
            item = location->info;
            break;
        case LESS:
            moreToSearch = false;
            break;
        }
    }
    return item;
}

template <class ItemType>
void SortedType<ItemType>::PutItem(ItemType item)
{
    NodeType<ItemType> *newNode;
    NodeType<ItemType> *predLoc;
    NodeType<ItemType> *location;
    bool moreToSearch;

    location = listData;
    predLoc = NULL;
    moreToSearch = (location != NULL);
    // find insertion point
    while (moreToSearch)
    {
        switch (ComparedTo(item, location->info))
        {
        case GREATER:
            predLoc = location;
            location = location->next;
            moreToSearch = (location != NULL);
            break;
        case LESS:
            moreToSearch = false;
            break;
        }
    }
    newNode = new NodeType<ItemType>;
    newNode->info = item;
    if (predLoc == NULL)
    {
        newNode->next = listData;
        listData = newNode;
    }
    else
    {
        newNode->next = location;
        predLoc->next = newNode;
    }
    length++;
}
template <class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item)
{
    NodeType<ItemType> *location = listData;
    NodeType<ItemType> *tempLocation;

    // Locate node to be deleted.
    if (ComparedTo(item, listData->info) == EQUAL)
    {
        tempLocation = location;
        listData = listData->next; // Delete first Node
        length--;
    }
    else
        while (location->next != NULL)
        {
            while (ComparedTo(item, (location->next)->info) != EQUAL || location->next != NULL)
            {
                location = location->next;
            }
            if (ComparedTo(item, (location->next)->info) == EQUAL)
            {
                tempLocation = location->next;
                location->next = (location->next)->next;
                length--;
            }
        }
    delete tempLocation;
}
template <class ItemType>
void SortedType<ItemType>::ResetList()
{
    currentPos = NULL;
}
template <class ItemType>
SortedType<ItemType>::~SortedType()
{
    NodeType<ItemType> *tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
}
template<class ItemType>
RelationType SortedType<ItemType>::ComparedTo(ItemType value, ItemType otherItem)
{

    if (value < otherItem)
    {
        return LESS;
    }
    else if (value > otherItem)
    {
        return GREATER;
    }
    else
        return EQUAL;
}
;
/*
void MergeList(SortedType list1, SortedType list2, SortedType &result)
{
    // Get List Lengths
    int list1Length = list1.GetLength();
    int list2Length = list2.GetLength();
    // set locations to 0
    int list1Location = 0;
    int list2Location = 0;
    // set current position to beginning of list
    list1.ResetList();
    list2.ResetList();

    // declare temporary item types and get values
    ItemType tempItem1 = list1.GetNextItem();
    ItemType tempItem2 = list2.GetNextItem();

    while (list1Length >= list1Location && list2Length >= list2Location)
    {
        switch (tempItem1.ComparedTo(tempItem2))
        {
        case LESS:
            result.PutItem(tempItem1);
            if (list1Location < list1Length)
            {
                tempItem1 = list1.GetNextItem();
                list1Location++;
            }
            break;
        case GREATER:
            result.PutItem(tempItem2);
            if (list1Location < list2Length)
            {
                tempItem2 = list2.GetNextItem();
                list2Location++;
            }
            break;
        }
    }
}
*/
