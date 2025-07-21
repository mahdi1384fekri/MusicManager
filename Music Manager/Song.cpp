#include "Song.h"
int My_Song::song_counter = 1;
My_Song::My_Song(int year, const string& name, const string& lyrisc):song_id(song_counter++),song_year(year),song_name(name), Lyrics(lyrisc)
{
}

My_Song::My_Song():song_id(-1),song_name(""),song_year(-1),Lyrics("")
{
}

int My_Song::get_id() const
{
	return song_id;
}

string& My_Song::get_name() 
{
	return song_name;
}

int My_Song::get_year()
{
	return song_year;
}

string& My_Song::get_lyrics()
{
	return Lyrics;
}

void My_Song::set_name(const string& name)
{
	song_name = name;
}

void My_Song::set_id(int id)
{
	song_id = id;
}

void My_Song::set_Lyrics(const string& Lyrics_)
{
	Lyrics = Lyrics_;
}
