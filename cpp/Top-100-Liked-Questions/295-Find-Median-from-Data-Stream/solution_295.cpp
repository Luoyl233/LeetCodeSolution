/*
 * 295. Find Median from Data Stream
 */


#include "common.h"


#if LEET_CODE == 295

class Bigger {
public:
    bool operator() (int x, int y) {
        return x > y;
    }
};

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if (maxHeap.size() < minHeap.size()-1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        int n = maxHeap.size() + minHeap.size();
        if (n % 2 == 0) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else {
            return minHeap.top();
        }
    }

private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, Bigger> minHeap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main()
{
    cout << "295. Find Median from Data Stream" << endl;

    return 0;
}


#endif
