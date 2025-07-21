#include "Queue.h"

Queue::Queue(int capacity_):capacity(capacity_){
	queue_ = new PlayList[capacity];
	rear = -1;
	front = 0;
	count_member = 0;
}

Queue::~Queue()
{
	delete[] queue_;
}

bool Queue::empty()
{
	return count_member == 0;
}

bool Queue::isfull()
{
	return count_member== capacity;
}

void Queue::enqueue(PlayList e)
{
	if (isfull())
	{
		//
		return;
	}
	
	rear = (rear + 1)% capacity;
	queue_[rear] = e;
	count_member++;

}

PlayList Queue::dequeue()
{
	if (empty())
	{
		//
	}
	PlayList item = queue_[front];;
	front = (front + 1) % capacity;
	count_member--;
	return item;
}

void Queue::display()
{

	if (empty()) {
		//cout << "!" << endl;
		return;
	}

	cout << "Queue members:" << endl;
	for (int i = front; i <= rear; i++)
	{
		cout << "PlayList name:" << queue_[i].get_name() << endl << "PlayList ID:" << queue_[i].get_id() << endl;
		cout << "playlist songs:";
		queue_[i].songs_list();
		cout << " " << endl;
	}
	cout << endl;

}

int Queue::size()
{
	return count_member;
}

PlayList Queue::peek()
{
	if (empty())
	{
//
		
	}
	return queue_[front];
}

