#pragma once
#include <iostream>
#include "Song.h"


class Node
{
public:
	Node(My_Song& song);
	~Node();
	My_Song& get_song();
	void set_song(const My_Song songdata);
	Node* get_next() const;
	void Set_next(Node* nextnode);	

private:
	My_Song song_data;
	Node* next;
};


class Song_list {
public:


	Song_list();
	//~Song_list();
	void add_song(My_Song song);
	bool remove_song(int songID);
	My_Song* find_song_(string& song_name_);
	My_Song* find_song_id(int song_id_);

	void display() const;
	void quick_sort();
	//Node* partition(Node* head_, Node* tail_);
private:
	Node* partition(Node* start, Node* end, Node** newhead, Node** newend);
	Node* qiuck_sort_recur(Node* start, Node* end);
	Node* get_tail(Node* curr);
	Node* head;
	Node* tail;
};