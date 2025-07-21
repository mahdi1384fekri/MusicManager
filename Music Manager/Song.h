#pragma once

#include<iostream>
#include<string>
using namespace std;
class My_Song
{
public:
	int static song_counter;
	My_Song(int year,const string& name,const string& lyrisc);
	My_Song();
	//~My_Song();
	int get_id() const;
	
	string& get_name() ;
	int get_year();
	string& get_lyrics();
	void set_name(const string& name);
	void set_id(int id);
	void set_Lyrics(const string& Lyrics_);



private:
	int song_id;
	string song_name;
	int song_year;
	string Lyrics;


};


