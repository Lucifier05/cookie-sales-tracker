/*******
    Name:- KRISH SHASTRI
    I'd:-200521905
    Date:-11/03/2024
    Assignment#3
    main.cpp
******/
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include "UnsortedList.h"
#include "ItemType.h"

void processInput(UnsortedListType& salesList);
void findWinners(UnsortedListType& salesList, std::vector<int>& winners, int& maxBoxes);
void writeReport(UnsortedListType& salesList, const std::vector<int>& winners, int maxBoxes);

int main() 
{
    UnsortedListType salesList;
    std::vector<int> winners;
    int maxBoxes = 0;

    // Process all sales data
    processInput(salesList);
    
    // Find the winning class(es)
    findWinners(salesList, winners, maxBoxes);
    
    // Generate and write the report
    writeReport(salesList, winners, maxBoxes);
    
    std::cout << "Report has been written to 'boxesSold' file.\n";
    return 0;
}

void processInput(UnsortedListType& salesList)
 {
    int classId, boxes;
    
    std::cout << "Enter class ID and boxes sold (enter -1 for class ID to finish):\n";
    while (true) {
        std::cout << "Class ID: ";
        std::cin >> classId;
        if (classId == -1) break;
        
        std::cout << "Boxes sold: ";
        std::cin >> boxes;
        
        // Process sale
        ItemType searchItem(classId, 0);
        bool found;
        salesList.RetrieveItem(searchItem, found);
        
        if (found) {
            // Update existing class
            ItemType updatedItem(classId, searchItem.GetTotalBoxes() + boxes);
            salesList.DeleteItem(searchItem);
            salesList.InsertItem(updatedItem);
        } else {
            // Add new class
            ItemType newItem(classId, boxes);
            if (!salesList.IsFull()) {
                salesList.InsertItem(newItem);
            } else {
                std::cout << "Error: Maximum number of classes reached.\n";
                break;
            }
        }
    }
}

void findWinners(UnsortedListType& salesList, std::vector<int>& winners, int& maxBoxes) {
    ItemType item;
    salesList.ResetList();
    
    for (int i = 0; i < salesList.LengthIs(); i++) {
        salesList.GetNextItem(item);
        if (item.GetTotalBoxes() > maxBoxes) {
            maxBoxes = item.GetTotalBoxes();
            winners.clear();
            winners.push_back(item.GetClassId());
        } else if (item.GetTotalBoxes() == maxBoxes) {
            winners.push_back(item.GetClassId());
        }
    }
}

void writeReport(UnsortedListType& salesList, const std::vector<int>& winners, int maxBoxes) {
    std::ofstream outFile("boxesSold");
    if (!outFile) {
        std::cout << "Error opening output file\n";
        return;
    }
    
    // Write header
    outFile << "Cookie Sales Report\n";
    outFile << "==================\n\n";
    
    // Write sales totals
    outFile << "Total Boxes Sold by Each Class:\n";
    outFile << "--------------------------------\n";
    ItemType item;
    salesList.ResetList();
    
    for (int i = 0; i < salesList.LengthIs(); i++) {
        salesList.GetNextItem(item);
        outFile << "Class " << std::setw(2) << item.GetClassId() 
                << ": " << std::setw(4) << item.GetTotalBoxes() << " boxes\n";
    }
    
    // Write winners
    outFile << "\nWinning Class(es):\n";
    outFile << "----------------\n";
    for (int winnerId : winners) {
        outFile << "Class " << winnerId << " with " << maxBoxes << " boxes\n";
    }
    
    outFile.close();
}