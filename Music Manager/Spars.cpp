#include "Spars.h"
sparse_Artist::sparse_Artist(int maxval_):maxval(maxval_),size(0) {
	for (int i = 0; i < maxval; i++)
	{
		sparse[i] = -1;
	}
}

void sparse_Artist::add_to_sparse(Artist& item)
{
	if (exists(item.get_id())) {
		throw std::runtime_error("Artist already exists in SparseSet.");
	}
	if (size >= maxval) {
		throw std::runtime_error("SparseSet is full.");
	}
	sparse[item.get_id()] = size;
	dense[size] = item.get_id();
	art[size] = item;
	size++;

}	

void sparse_Artist::remove_from_sparse(int item)
{
	if (!exists(item)) {
		throw std::runtime_error("Artist not found in SparseSet.");
	}
	int removed_index = sparse[item];
	int last_index = size - 1;
	dense[removed_index] = dense[last_index];
	sparse[dense[last_index]] = removed_index;
	art[removed_index] = art[last_index];
	sparse[item] = -1;
	size--;
}

Artist& sparse_Artist::find(int item)
{
	//if (!exists(ID) {
	//	//throw run

	//}
	if (!exists(item)) {
		throw std::runtime_error("Artist not found in SparseSet.");
	}
	  
	return art[sparse[item]];
}

bool sparse_Artist::exists(int item)
{
	return  item >= 0 && item < maxval && sparse[item] != -1;
}

void sparse_Artist::clear()
{
	for (int i = 0; i < size; i++)
	{
		sparse[dense[i]] = -1;
	}
	size = 0;

}

void sparse_Artist::prints_all_artists() {
	if (size == 0) {
		std::cout << "No artists available in the SparseSet." << std::endl;
		return;
	}

	std::cout << "======= All Artist Information =======" << std::endl;

	for (int i = 0; i < size; i++) {
		Artist& artist = art[i];

		// Print artist details
		std::cout << "Artist Name: " << artist.get_name()
			<< "\nArtist ID: " << artist.get_id() << std::endl;

		// Print songs list
		std::cout << "Songs:" << std::endl;
		artist.songs_list(); // Assuming this function prints all songs of the artist

		std::cout << "---------------------------------------" << std::endl;
	}
}

My_Song* sparse_Artist::find_song_in_spars(string song_name_)
{
	for (int i = 0; i < size; i++)
	{
		Artist artist_find = art[i];
		My_Song* song_find = artist_find.find_song(song_name_);
		if (song_find != nullptr)
			return song_find;
	}
	cout << "song not exist" << endl;
	return nullptr;
}

My_Song* sparse_Artist::find_song_in_spars_id(int song_id_)
{
	for (int i = 0; i < size; i++)
	{
		Artist artist_find = art[i];
		My_Song* song_find = artist_find.find_song_id(song_id_);
		if (song_find != nullptr)
			return song_find;
	}
	cout << "song not exist" << endl;
	return nullptr;
}

void sparse_Artist::remove_song(int songID)
{
	for (int i = 0; i < size; i++)
	{
		Artist artist_find = art[i];
		My_Song* song_find =  artist_find.find_song_id(songID);
		if (song_find!=nullptr)
		{
			artist_find.remove_song(songID);
			art[i] = artist_find;
			cout << "remove song successfuly" << endl;
			return;
		}
	}
	cout << "remove song onsuccessfuly" << endl;

}

void sparse_Artist::add_songTO_artist()
{
	string song_name, song_lyrics = "";
	string input;
	int song_year;
	string artist_name;
	//cout << "Enter song name:";
	std::cin >> song_name;
	//cout << "Enter song year:";
	std::cin >> song_year;
	cin.ignore();
	cout << "Enter song lyrics(Enter ''_end_'' to Finish):";
	while (true)
	{
		getline(std::cin, input);
		if (input == "end")
		{
			break;
		}
		song_lyrics += input + "\n";

	}
	
	//cout << "Enter Artist name:";
	std::cin >> artist_name;
	for (int i = 0; i < size; i++)
	{
		Artist artist_find = art[i];
		if (artist_find.get_name() == artist_name)
		{
			My_Song song(song_year, song_name, song_lyrics);
			artist_find.add_song(song);
			art[i] = artist_find;
			cout << "Added successfully" << endl;
			return;
		}
	}
	cout << "Added onsuccessfully" << endl;
	
}

