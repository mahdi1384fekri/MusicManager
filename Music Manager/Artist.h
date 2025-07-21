#pragma once
#include<iostream>
#include <string>
#include"SongList.h"
using namespace std;
class Artist
{
public:
	static int counter_artist;
	Artist(const string & name);
	Artist();
	//~Artist();
	const string& get_name() const ;
	int get_id() const;
	void songs_list();
	My_Song* find_song(string song_name_);
	My_Song* find_song_id(int song_id_);

	void remove_song(int songID);
	void add_song(My_Song& song);
	/////
   /* int customSize(const std::string& str);*/

private:
	int artist_id;	
	string artist_name;
	Song_list songs;


};
