#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <Windows.h>

using namespace std;

//Each cup of coffee needs: 1 cup of water and 2 oz of grounds ()

int totalOrders;
int totalWaterNeeded;
int totalGroundsNeeded;


//Get total amount of orders
int GetOrders()
{
    //Reads input.txt file
    std::ifstream infile("input.txt");

    //Contents of each line, in this case, the customer's order is saved in line
    std::string line;

    std::string fileContent;

    //Loop that goes through all 40 lines in the input file
    while (std::getline(infile, line))
    {
        fileContent += line;
        fileContent.push_back('n');
        if (infile.good())
        {
            //The content of "line" - the number of cups of coffee being ordered - is converted from a string to an int and added to the order total
            totalOrders += stoi(line);
        }
    }

    infile.close();

    return totalOrders;
}

//Gets amount of cups of water needed to complete the day's orders
int GetTotalWater()
{
    //Each cup needs 1 cup of water, so the total orders can be multiplied by 1 in order to get the total cups of water needed
    totalWaterNeeded = totalOrders * 1;

    return totalWaterNeeded;
}

//Gets amount of ounces of coffee grounds needed to complete the day's orders
int GetTotalGrounds()
{
    //Since each cup needs 2 ounces of grounds, the total orders are multiplied by 2
    totalGroundsNeeded = totalOrders * 2;

    return totalGroundsNeeded;
}

std::string GetTotalIngredients()
{
    GetOrders();
    GetTotalWater();
    GetTotalGrounds();

    std::string totalIngredients;

    std::string totalCups;

    totalIngredients += "\nTotal number of cups of coffee today: " + std::to_string(totalOrders) + "\n";
    totalIngredients += "\nCups of water needed: " + std::to_string(totalWaterNeeded) + "\nOunces of grounds needed: " + std::to_string(totalGroundsNeeded) + "\n";

    return totalIngredients;
}

int main()
{
    std::cout << GetTotalIngredients() << std::endl;

    return 0;
}
