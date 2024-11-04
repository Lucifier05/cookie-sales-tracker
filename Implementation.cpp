/*******
    Name:- KRISH SHASTRI
    I'd:-200521905
    Date:-11/03/2024
    Assignment#3
    Implementation.h
*******/
#include "ItemType.h"
#include "UnsortedList.h"

//Itemtype implementation
ItemType::ItemType() : classId(0),totalBoxes(0){}
ItemType::ItemType(int id, int boxes) : classId(id), totalBoxes(boxes){}

int ItemType::GetClassId() const
{
    return classId;
}

int ItemType::GetTotalBoxes() const
{
    return totalBoxes;
}

 void ItemType::AddBoxes(int boxes) 
{
  totalBoxes+=boxes;
}

//UnsortedListType implementation
UnsortedListType::UnsortedListType()
{
    length=0;
    currentPos=-1;
}

bool UnsortedListType::IsFull() const
{
    return (length==MAX_ITEMS);
}

int UnsortedListType::LengthIs() const 
{
    return length;
}

void UnsortedListType::RetrieveItem(ItemType& item, bool& found)
{
found=false;
for (int i=0; i<length; i++)
  {
    if(info[i].GetClassId() == item.GetClassId())
    {
        item=info[i];
        found=true;
        break;
    }
  } 
}

void UnsortedListType::InsertItem(ItemType item)
{
    if(!IsFull())
    {
        info[length]=item;
        length++;
    }
}
 
void UnsortedListType::DeleteItem(ItemType item)
{
    int i=0;
    while(i<length && info[i].GetClassId() != item.GetClassId())
    {
        i++;
        if(i<length)
        {
            info[i-1]=info[i];
            length--;
        }
    }
}

void UnsortedListType::ResetList()
{
    currentPos=-1;
}

void UnsortedListType::GetNextItem(ItemType& item)
{
    currentPos++;
    item=info[currentPos];
}