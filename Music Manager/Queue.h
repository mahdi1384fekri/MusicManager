#pragma once
#include<iostream>
#include"PlayList.h"
class Queue {
private:
	int capacity;
	PlayList* queue_;
	int front;
	int rear;
	int count_member;
public:
	Queue(int capacity_);
	~Queue();
	bool empty();
	bool isfull();
	void enqueue(PlayList e);
	PlayList dequeue();
	void display();
	int size();
	PlayList peek();

};
