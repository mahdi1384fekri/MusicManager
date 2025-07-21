#include "PlayList.h"
int PlayList::PL_counter = 1;
PlayList::PlayList(const string& name):PL_name(name),PL_id(PL_counter++)
{
}

PlayList::PlayList():PL_name(""),PL_id(-1)
{
}

string& PlayList::get_name() 
{
	return PL_name;
}

int PlayList::get_id() const
{
	return PL_id;
}

void PlayList::songs_list()
{
	PL_songs.quick_sort();
	PL_songs.display();
}

My_Song* PlayList::find_song(int songID)
{
	return PL_songs.find_song_id(songID);
}

void PlayList::remove_song(int songID)
{
	if (PL_songs.remove_song(songID))
	{
		cout << "Successfull" << endl;
	}
	else
		cout << "song not found or song not exist" << endl;
}

void PlayList::add_song(My_Song& song)
{
	PL_songs.add_song(song);
	//PL_songs.quick_sort();

}
