#include "Spars_PL.h"

Spars_PL::Spars_PL(int maxval_) :maxval(maxval_), size(0) {
	for (int i = 0; i < maxval; i++)
	{
		sparse[i] = -1;
	}
}


void Spars_PL::add_to_sparse(PlayList& item)
{
	/*if (exists(item.get_id())) {
		throw std::runtime_error("Artist already exists in SparseSet.");
	}
	if (size >= maxval) {
		throw std::runtime_error("SparseSet is full.");
	}
	sparse[item.get_id()] = size;
	dense[size] = item.get_id();
	PL[size] = item;
	size++;*/
	if (exists(item.get_id())) {
		throw std::runtime_error("Artist already exists in SparseSet.");
	}

	int pos = 0;
	while (pos < size && dense[pos] < item.get_id()) {
		pos++;
	}

	for (int i = size; i > pos; i--) {
		dense[i] = dense[i - 1];
		sparse[dense[i]] = i;
		PL[i] = PL[i - 1];
	}

	dense[pos] = item.get_id();
	sparse[item.get_id()] = pos;
	PL[pos] = item;

	size++;
}

void Spars_PL::remove_from_sparse(int item)
{

	if (!exists(item)) {
		throw std::runtime_error("Artist not found in SparseSet.");
	}
	int removed_index = sparse[item];
	/*int last_index = size - 1;
	dense[removed_index] = dense[last_index];
	sparse[dense[last_index]] = removed_index;
	PL[removed_index] = PL[last_index];*/
	for (int i = removed_index; i < size-1; i++)
	{
		dense[i] = dense[i + 1];
		sparse[dense[i]] = i;
		PL[i] = PL[i + 1];
	}
	sparse[item] = -1;
	size--;
}

PlayList& Spars_PL::find(int item)
{
	/*if (!exists(item)) {
		throw std::runtime_error("Artist not found in SparseSet.");
	}

	return PL[sparse[item]];*/
	int left = 0, right = size - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (dense[mid] == item) {
			return PL[mid]; 
		}
		else if (dense[mid] < item) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	throw std::runtime_error("Artist not found in SparseSet.");
}

bool Spars_PL::exists(int item)
{
	return  item >= 0 && item < maxval && sparse[item] != -1;
}

void Spars_PL::clear()
{
	for (int i = 0; i < size; i++)
	{
		sparse[dense[i]] = -1;
	}
	size = 0;
}

void Spars_PL::prints_all_artists()
{
	if (size == 0) {
		std::cout << "No Playlist available in the SparseSet." << std::endl;
		return;
	}

	std::cout << "======= All PlayList Information =======" << std::endl;

	for (int i = 0; i < size; i++) {
		PlayList& playlist = PL[i];

		// Print artist details
		std::cout << "PlayList Name: " << playlist.get_name()
			<< "\nPlayList ID: " << playlist.get_id() << std::endl;

		// Print songs list
		std::cout << "Songs:" << std::endl;
		playlist.songs_list(); // Assuming this function prints all songs of the artist

		std::cout << "---------------------------------------" << std::endl;
	}
}

My_Song* Spars_PL::find_song_in_spars(int songID)
{
	for (int i = 0; i < size; i++)
	{
		PlayList pl_find = PL[i];
		My_Song* song_find = pl_find.find_song(songID);
		if (song_find != nullptr)
			return song_find;
	}
	cout << "song not exist" << endl;
	return nullptr;
}

void Spars_PL::remove_song(int songID)
{
	for (int i = 0; i < size; i++)
	{
		PlayList pl_find = PL[i];
		My_Song* song_find = pl_find.find_song(songID);
		if (song_find != nullptr)
		{
			pl_find.remove_song(songID);
			PL[i] = pl_find;
			cout << "remove song in playlist successfuly" << endl;
			return;
		}
	}
	cout << "remove song in playlist onsuccessfuly" << endl;
}

void Spars_PL::add_songTO_playlist()
{
	string song_name, song_lyrics;
	int song_year;
	string artist_name;
	cout << "Enter song name:";
	cin >> song_name;
	cout << "Enter song lyrics:";
	cin >> song_lyrics;
	cout << "Enter song year:";
	cin >> song_year;
	cout << "Enter Artist name:";
	cin >> artist_name;
	for (int i = 0; i < size; i++)
	{
		PlayList artist_find = PL[i];
		if (artist_find.get_name() == artist_name)
		{
			My_Song song(song_year, song_name, song_lyrics);
			artist_find.add_song(song);
			PL[i] = artist_find;
			cout << "Added successfully" << endl;
			return;
		}
	}
	cout << "Added onsuccessfully" << endl;
}
