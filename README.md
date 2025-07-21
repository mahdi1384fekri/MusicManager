# 🎵 Playlist Manager Console App (C++ / Sparse Set)

This console-based C++ application allows users to manage artists, songs, and playlists using efficient data structures such as **Sparse Set**, **Linked List**, and **Suffix Array** for optimized text search.

---

## ⚙️ Project Features

- Manage artists and their songs using a Sparse Set
- Each artist has a list of songs implemented via linked list
- Efficient word search in lyrics using **Suffix Array** (`O(m log n)`)
- Song, playlist, and artist management through text commands
- Playlist sorting using in-place **Quick Sort** based on release year
- Playback queue implemented with array-based circular queue
- All interactions are done via a simple command-line interface

---

## 🧩 Data Structures Used

- **Sparse Set**: For managing artists and playlists efficiently
- **Linked List**: For storing each artist’s songs
- **Suffix Array**: To support fast substring search in song lyrics
- **Array-based Queue**: For handling playback of multiple playlists

## 💻 Console Commands



## 🏆 Bonus Features

- **Suffix Array Build**: `O(n log² n)` (or `O(n log n)` for extra credit)
- **Generic Data Structures**: Designed for reusability and flexibility
- **Optimized Search**: Faster data retrieval than naive implementations

📦 PlaylistManager/
 ┣ 📄 main.cpp
 ┣ 📄 Artist.h / Artist.cpp
 ┣ 📄 Song.h / Song.cpp
 ┣ 📄 SongList.h / SongList.cpp
 ┣ 📄 PlayList.h / PlayList.cpp
 ┣ 📄 Spars.h / Spars.cpp
 ┣ 📄 Spars_PL.h / Spars_PL.cpp
 ┣ 📄 Queue.h / Queue.cpp
 ┣ 📄 README.md

## 🚀 How to Compile and Run

Use the following command to compile the project:

```bash
g++ -std=c++17 main.cpp Artist.cpp PlayList.cpp Queue.cpp Song.cpp SongList.cpp Spars.cpp Spars_PL.cpp -o playlist_manager
./playlist_manager
