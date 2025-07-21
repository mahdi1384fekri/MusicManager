#pragma once
#include<iostream>
#include "Artist.h"
using namespace std;
class sparse_Artist {
private:
	int sparse[1000];
	int dense[1000];
	int maxval;
	int size;
	Artist art[1000];
public:
	sparse_Artist(int maxval_);
	void add_to_sparse(Artist& item);
	void remove_from_sparse(int item);
	Artist& find(int item);
	bool exists(int item);
	void clear();
	void prints_all_artists();
	My_Song* find_song_in_spars(string song_name_);
	My_Song* find_song_in_spars_id(int song_id_);

	void remove_song(int songID);
	void add_songTO_artist();
};


