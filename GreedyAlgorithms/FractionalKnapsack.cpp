#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int cost;
    int weight;
};

bool compareCostWeightRatio(Item i1, Item i2) {
    double ratio1 = (double)i1.cost / i1.weight;
    double ratio2 = (double)i2.cost / i2.weight;

    return ratio1 > ratio2;
}

double maximumLoot(int capacity, std::vector<Item>& items) {
    std::sort(items.begin(), items.end(), compareCostWeightRatio);

    double totalValue = 0.0;
    int currentWeight = 0;

    for(int i=0; i < items.size(); i++) {
        if(currentWeight + items[i].weight <= capacity) {
            currentWeight += items[i].weight;
            totalValue += items[i].cost;
        }
        else {
            int remainingWeight = capacity - currentWeight;
            totalValue += items[i].cost * ((double)remainingWeight/items[i].weight);
            break;
        }
    }

    return totalValue;
}

int main()
{
    int n, capacity;
    std::cin >> n >> capacity;

    std::vector<Item> items(n);
    for(int i=0; i<n; ++i) {
        std::cin >> items[i].cost >> items[i].weight;
    }   
    double result = maximumLoot(capacity, items);
    std::cout << std::fixed;
    std::cout.precision(4);
    std::cout << result << '\n';
    return 0;
}