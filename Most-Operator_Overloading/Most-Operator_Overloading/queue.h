#pragma once

class queue
{
	class queuenode *front , *rear;
	int size;
public:
	queue();
	bool isEmpty(queue *);
	bool isFull(queue *);
	void Enqueue(void *, queue *, int );
	void Dequeue(void *, queue *, int );
	~queue();
};

