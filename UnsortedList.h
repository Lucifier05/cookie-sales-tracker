/*******
    Name:- KRISH SHASTRI
    I'd:-200521905
    Date:-11/03/2024
    Assignment#3
    UnsortedList.h
*******/
#ifndef UNSORTEDLIST_H
#define UNSORTEDLIST_H

#include"ItemType.h"

const int MAX_ITEMS=10;

class UnsortedListType
{
    public:
        UnsortedListType();//constructor
        
        //Operations
        bool IsFull() const;
        int LengthIs() const;
        void RetrieveItem(ItemType& item, bool& found);
        void InsertItem(ItemType item);
        void DeleteItem(ItemType item);
        void ResetList();
        void GetNextItem(ItemType& item);

    private:
        int length;
        ItemType info[MAX_ITEMS];
        int currentPos;
};

#endif

