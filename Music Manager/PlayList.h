#pragma once
#include"SongList.h"

class PlayList {
private:
	int PL_id;
	string PL_name;
	Song_list PL_songs;

public:
	PlayList(const string& name);
	PlayList();
	int static PL_counter;
	string& get_name();
	int get_id() const;
	void songs_list();
	My_Song* find_song(int songID);
	void remove_song(int songID);
	void add_song(My_Song& song);
};