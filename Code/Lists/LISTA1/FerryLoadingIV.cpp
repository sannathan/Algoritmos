#include <iostream>
#include "../../../DataStructures/Queue.h"

using namespace std;

int main()
{
  int c;

  cin >> c;

  for (int i{}; i < c; i++)
  {
    float l, m;

    cin >> l >> m;

    int ferryCapacityCm = l * 100;

    AQueue<float> rightQueue(m);
    AQueue<float> leftQueue(m);

    for (int j{}; j < m; j++)
    {
      int carSize;
      string carSide;

      cin >> carSize >> carSide;

      if (carSide == "left")
      {
        leftQueue.enqueue(carSize);
      }
      else {
        rightQueue.enqueue(carSize);
      }
    }
    int crossTimes = 0;
    string ferrySide = "left";

    while (leftQueue.length() > 0 || rightQueue.length() > 0)
    {
      int carsLoaded = 0;
      int availableSpace = ferryCapacityCm;

      if(ferrySide == "left")
      {
        while(leftQueue.length() > 0 && leftQueue.frontValue() <= availableSpace)
        {
          int carSize = leftQueue.dequeue();
          availableSpace -= carSize;
          carsLoaded++;
        }

        if(carsLoaded > 0 || rightQueue.length() > 0)
        {
          crossTimes++;
          ferrySide = "right";
        }
      }
      else{
        while(rightQueue.length() > 0 && rightQueue.frontValue() <= availableSpace)
        {
          int carSize = rightQueue.dequeue();
          availableSpace -= carSize;
          carsLoaded++;
        }

        if(carsLoaded > 0 || leftQueue.length() > 0)
        {
          crossTimes++;
          ferrySide = "left";
        }
      }
    }


    cout << crossTimes << endl;
  }

  return 0;
}
