#pragma once
#include<iostream>
#include "Song.h"
#include"PlayList.h"
using namespace std;
class Spars_PL {
private:
	int sparse[1000];
	int dense[1000];
	int maxval;
	int size;
	PlayList PL[1000];


public:
	Spars_PL(int maxval_);
	void add_to_sparse(PlayList& item);
	void remove_from_sparse(int item);
	PlayList& find(int item);
	bool exists(int item);
	void clear();
	void prints_all_artists();
	My_Song* find_song_in_spars(int songID);
	void remove_song(int songID);
	void add_songTO_playlist();

};
