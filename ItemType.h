/*******
    Name:- KRISH SHASTRI
    I'd:-200521905
    Date:-11/03/2024
    Assignment#3
    ItemType.h
*******/
#ifndef ITEM_TYPE_H
#define ITEM_TYPE_H

class ItemType
{
    public:
        ItemType();//default constructor
        ItemType(int id,int boxes);//parameterised constructor

        //GETTERES
        int GetClassId() const;
        int GetTotalBoxes() const;

        //Operations
        void AddBoxes(int boxes);

    private:
    int classId;
    int totalBoxes;
};

#endif
