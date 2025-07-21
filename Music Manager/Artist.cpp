#include "Artist.h"
int Artist::counter_artist = 1;
Artist::Artist(const string& name) :artist_name(name), artist_id(counter_artist++){}

Artist::Artist():artist_name(""),artist_id(-1)
{
}


const string& Artist::get_name() const 
{
	return this->artist_name;
}

int Artist::get_id() const
{
	return this->artist_id;
}

void Artist::songs_list()
{
	songs.display();
}

My_Song* Artist::find_song(string song_name_)
{
	return songs.find_song_(song_name_);
}

My_Song* Artist::find_song_id(int song_id_)
{
	return songs.find_song_id(song_id_);
}

void Artist::remove_song(int songID)
{
	if (songs.remove_song(songID))
	{
		cout << "Successfull" << endl;
	}
	else
		cout << "song not found or song not exist" << endl;
}

void Artist::add_song(My_Song& song)
{
	songs.add_song(song);
}

