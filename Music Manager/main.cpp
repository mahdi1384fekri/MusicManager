#include"Artist.h"
#include "Spars.h"
#include"Spars_PL.h"
#include "Queue.h"
#include<sstream>
using namespace std;
template<typename T>
class Vector_ {
    T* data;
    int size;
    int capacity;
    void setnull() {
        for (int i = 0; i < capacity; i++)
        {
            new(&data[i]) T();
        }
    }
public:

    Vector_(int capa = 1) :capacity(capa), size(0) {
        data = new T[capacity];
        setnull();
    }
    void resize(int newcapacity) {
        T* newarr = new T[capacity];
        for (int i = 0; i < capacity; i++)
        {
            newarr[i] = data[i];
        }
        delete[] data;
        data = new T[newcapacity];
        setnull();
        for (int i = 0; i < capacity; i++)
        {
            data[i] = newarr[i];
        }
        capacity = newcapacity;
    }
    T& operator[](int index) {
        size = max(size, index + 1);
        return data[index];
    }
    const T& operator[](int index) const {
        //size = max(size, index + 1);
        return data[index];
    }
    Vector_(const Vector_& other) :capacity(other.capacity), size(other.size) {
        data = new T[capacity];
        /*if (!data)
        {
            throw bad_alloc;
        }*/
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    /* Vector_(const Vector_&& other) noexcept :capacity(other.capacity), data(other.data) {
         other.data = nullptr;
         other.capacity = 0;
         cout << "Move constructor called" << endl;
     }*/
    void pushback(T Val) {
        if (size >= capacity)
        {
            resize(capacity * 2);
        }
        data[size] = Val;
        size++;
    }
    int get_capacity() {
        return capacity;
    }
    int size_() {
        return size;
    }
    T* begin() {
        return data;
    }

    T* end() {
        return data + size;
    }

};
int customSize(const std::string& str) {
    int length = 0;
    for (char c : str) {
        (void)c;
        ++length;
    }
    return length;
}
template<typename Iterator, typename Compare>
void customSort(Iterator begin, Iterator end, Compare cmp) {
    if (begin >= end || begin + 1 == end) {
        return;
    }

    auto pivot = *(begin + (end - begin) / 2); // انتخاب pivot
    Iterator left = begin;
    Iterator right = end - 1;

    while (left <= right) {
        while (cmp(*left, pivot)) ++left;
        while (cmp(pivot, *right)) --right;

        if (left <= right) {
            std::swap(*left, *right);
            ++left;
            --right;
        }
    }

    customSort(begin, right + 1, cmp); // مرتب‌سازی بخش چپ
    customSort(left, end, cmp);       // مرتب‌سازی بخش راست
}


//std::string customSubstr(const std::string& str, size_t offset, size_t length) {
//    if (offset >= str.size()) {
//        return ""; 
//    }
//
//    size_t actualLength = std::min(length, str.size() - offset);
//
//    std::string result;
//    result.reserve(actualLength); 
//
//    for (size_t i = 0; i < actualLength; ++i) {
//        result += str[offset + i]; 
//    }
//
//    return result;
//}

//int customCompare(const std::string& str, size_t offset, size_t length, const std::string& right) {
//    if (offset >= str.size()) {
//        return -1; 
//    }
//
//    size_t actualLength = std::min(length, str.size() - offset);
//
//    for (size_t i = 0; i < actualLength && i < right.size(); ++i) {
//        if (str[offset + i] < right[i]) {
//            return -1; 
//        }
//        else if (str[offset + i] > right[i]) {
//            return 1;
//        }
//    }
//
//    if (actualLength < right.size()) {
//        return -1; 
//    }
//    else if (actualLength > right.size()) {
//        return 1; 
//    }
//
//    return 0; 
//}

struct suffix
{
    int index;
    int rank[2];
};

int cmp(struct suffix a, struct suffix b)
{
    return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1 : 0) :
        (a.rank[0] < b.rank[0] ? 1 : 0);
}

Vector_<int> buildSuffixArray(const string& txt)
{
    int n = customSize(txt);
    Vector_<suffix> suffixes(n);

    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].rank[0] = txt[i];
        suffixes[i].rank[1] = ((i + 1) < n) ? txt[i + 1] : -1;
    }

    customSort(suffixes.begin(), suffixes.end(), cmp);

    Vector_<int> ind(n);

    for (int k = 4; k < 2 * n; k = k * 2)
    {
        int rank = 0;
        int prev_rank = suffixes[0].rank[0];
        suffixes[0].rank[0] = rank;
        ind[suffixes[0].index] = 0;

        for (int i = 1; i < n; i++)
        {
            if (suffixes[i].rank[0] == prev_rank &&
                suffixes[i].rank[1] == suffixes[i - 1].rank[1])
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = rank;
            }
            else
            {
                prev_rank = suffixes[i].rank[0];
                suffixes[i].rank[0] = ++rank;
            }
            ind[suffixes[i].index] = i;
        }

        for (int i = 0; i < n; i++)
        {
            int nextindex = suffixes[i].index + k / 2;
            suffixes[i].rank[1] = (nextindex < n) ?
                suffixes[ind[nextindex]].rank[0] : -1;
        }

        customSort(suffixes.begin(), suffixes.end(), cmp);
    }

    Vector_<int> suffixArr(n);
    for (int i = 0; i < n; i++) {
        suffixArr[i] = suffixes[i].index;
        //cout << suffixArr[i] << endl;
    }


    return suffixArr;
}

//void printArr(const Vector_<int>& arr)
//{
//    for (auto & i:arr)
//    {
//        cout << i << " ";
//    }
//}


std::string customSubstr(const std::string& str, size_t offset) {
    if (offset >= customSize(str)) {
        return "";
    }
    std::string result;
    for (size_t i = offset; i < customSize(str); ++i) {
        result += str[i];
    }
    return result;
}

int customCompare(const std::string& left, const std::string& right) {
    if (left == right) {
        return 0;
    }
    else if (left < right) {
        return -1;
    }
    else {
        return 1;
    }
}

int searchPattern(const string& txt, const Vector_<int>& suffixArr, const std::string& pattern) {
    int n = customSize(txt);
    int m = customSize(pattern);
    int l = 0, r = n - 1;
    int maxindex = -1;
    int mid = 0;

    while (l <= r) {
        mid = l + (r - l) / 2;
        string suffix = customSubstr(txt, suffixArr[mid]);

        if (customCompare(suffix.substr(0, m), pattern) == 0) {
            maxindex = std::max(mid, maxindex);
            l = mid + 1;
        }
        else if (suffix > pattern) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    int minIndex = customSize(txt);
    l = 0;
    r = customSize(txt) - 1;

    while (r >= l) {
        mid = l + (r - l) / 2;
        std::string suffix = customSubstr(txt, suffixArr[mid]);

        if (customCompare(suffix.substr(0, m), pattern) == 0) {
            minIndex = std::min(mid, minIndex);
            r = mid - 1;
        }
        else if (suffix > pattern) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    if (maxindex < 0 || minIndex >= customSize(txt)) {
        return -1;
    }

    int minValue = customSize(txt);
    for (int i = minIndex; i <= maxindex; i++) {
        minValue = min(suffixArr[i], minValue);
    }

    return minValue;
}

int count_pattern(const string& txt, const Vector_<int>& suffixArr, const std::string& pattern) {
    int n = customSize(txt);
    int m = customSize(pattern);
    int l = 0, r = n - 1;
    int maxindex = -1;
    int mid = 0;

    while (l <= r) {
        mid = l + (r - l) / 2;
        string suffix = customSubstr(txt, suffixArr[mid]);

        if (customCompare(suffix.substr(0, m), pattern) == 0) {
            maxindex = std::max(mid, maxindex);
            l = mid + 1;
        }
        else if (suffix > pattern) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    int minIndex = customSize(txt);
    l = 0;
    r = customSize(txt) - 1;

    while (r >= l) {
        mid = l + (r - l) / 2;
        std::string suffix = customSubstr(txt, suffixArr[mid]);

        if (customCompare(suffix.substr(0, m), pattern) == 0) {
            minIndex = std::min(mid, minIndex);
            r = mid - 1;
        }
        else if (suffix > pattern) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    if (maxindex < 0 || minIndex >= customSize(txt)) {
        return -1;
    }

    int minValue = customSize(txt);
    for (int i = minIndex; i <= maxindex; i++) {
        minValue = min(suffixArr[i], minValue);
    }

    return maxindex - minIndex + 1;
}
int main() {
	////cout << "mahdi" << endl;
	//Artist artist("mahdi");
	//Artist artist2("paya");

	///*My_Song song(1,4,"m","m");
	//artist.add_song(song);*/
	////cout << artist.get_id();
	////My_Song song(11,"m","mm");
	////cout << song.get_id() << endl << song.get_lyrics() << endl << song.get_name() << endl << song.get_year() << endl;
	////artist.add_song(song);
	////artist2.add_song(song);
	////artist.songs_list();
	//sparse_Artist mahdi(100);
	//mahdi.add_to_sparse(artist);
	//mahdi.add_to_sparse(artist2);
	////Artist m  = mahdi.find(artist.get_id());
	///*artist.remove_song(2);*/
	////mahdi.remove_from_sparse(m.get_id());
	////cout << mahdi.exists(m.get_id());
	////artist.remove_song(1);*/
	///*My_Song *song_find =  artist.find_song(1);
	//cout<<song_find->get_name() << endl;*/
	////mahdi.clear();
	//mahdi.prints_all_artists();
	//cout << endl << endl << endl << endl;
	///*My_Song* song_ = mahdi.find_song_in_spars(1);
	//cout << song.get_year()
	//	<< "\t" << song_->get_name()<<song_->get_lyrics() << endl;*/
	////mahdi.add_songTO_artist();
	//My_Song song_2(15, "paya2", "alireze2");
	//My_Song song_3(4, "paya3", "alireze3");
	//My_Song song_4(78, "paya4", "alireze4");
	//My_Song song_5(19, "paya5", "alireze5");
	//My_Song song_6(2, "paya6", "alireze6");
	//My_Song song_7(1, "paya7", "alireze7");
	//artist.add_song(song_2);
	//artist.add_song(song_3);

	////artist.add_song(song);
	//mahdi.add_songTO_artist();
	//mahdi.prints_all_artists();
	//cout << endl << endl << endl << endl;

	//artist.remove_song(song_2.get_id());
	//PlayList spotify("spotify");
	//PlayList spotify2("spotify2");
	//PlayList spotify3("spotify3");


	//Spars_PL pl_sparse(100);
	//spotify.add_song(song_2);
	//spotify.add_song(song_3);
	//spotify.add_song(song_4);


	//spotify2.add_song(song_2);
	//spotify3.add_song(song_2);
	//spotify.add_song(song_5);

	//pl_sparse.add_to_sparse(spotify);
	//pl_sparse.add_to_sparse(spotify2);
	//pl_sparse.add_to_sparse(spotify3);


	//pl_sparse.prints_all_artists();
	//cout << endl << endl << endl << endl;
	//spotify.remove_song(song_3.get_id());
	//Queue my_q(10);;
	//my_q.enqueue(spotify);
	////my_q.dequeue();
	//my_q.display();
	//cout << endl << endl << endl << endl;
	////pl_sparse.remove_from_sparse(spotify2.get_id());
	//PlayList mahdi12 = pl_sparse.find(spotify2.get_id());
	//cout << mahdi12.get_id() << endl;
	//pl_sparse.prints_all_artists();
	string command;
	sparse_Artist Artists(100);
	Spars_PL PlayLists(100);
	Queue Main_Queue(10);
	//یک چیز خیلی مهم اینه که من وقتی میام اهنگی رو
	// اصافه کنم یا حذف کنم تو بعضی مواقع نیاز بع آپدیت کردن هست و 
	// باید بیام اونا رو آپدیت کنم
	do
	{
		cin >> command;
		if (command=="adds")
		{
			string name;
			cin >> name;
			Artist mahdi(name);
			Artists.add_to_sparse(mahdi);
			cout << "=======Adding  Artist  was successful=======" << endl;
		}
		else if (command=="dels")
		{
			int id_dels; cin >> id_dels;
			Artists.remove_from_sparse(id_dels);
			cout << "=======Removing  Artist  was successful=======" << endl;

		}
		else if (command=="find")
		{
			// بررسی شود اینجا باید بیام تمامی اطلاعات یک خواننده رو چاپ کنم
			int id_find;
			cin >> id_find;
			Artist finded = Artists.find(id_find);
			std::cout << "---------------------------------------" << std::endl;
			cout << "Artist name:" << finded.get_name() << endl
				<< "Artist ID:" << finded.get_id() << endl;
			finded.songs_list();
			std::cout << "---------------------------------------" << std::endl;

		}
		else if (command=="prints")
		{
			Artists.prints_all_artists();
		}
		else if (command=="cls")
		{
			Artists.clear();
			std::cout << "---------------------------------------" << std::endl;
			cout << "======= All information has been erased =======" << endl;
			std::cout << "---------------------------------------" << std::endl;
		}
		else if (command=="findm")
		{
			string findm_name;
			cin >> findm_name;
			My_Song *findm_song = Artists.find_song_in_spars(findm_name);
			std::cout << "======= Song  Information =======" << std::endl;
			cout << "Song Name:" << findm_song->get_name() << endl;
			cout << "Song ID:" << findm_song->get_id() << endl;
			cout << "Song Lyrics:" << findm_song->get_lyrics() << endl;
			cout << "Song Year:" << findm_song->get_year() << endl;
			std::cout << "---------------------------------------" << std::endl;

		}
		else if (command =="delm")
		{
			int delm_artist_id;
			int delm_music_id;
			cin >> delm_artist_id;
			cin >> delm_music_id;
			std::cout << "---------------------------------------" << std::endl;
			Artists.remove_song(delm_music_id);
			PlayLists.remove_song(delm_music_id);
			cout << "======= Removing  Music  was successful======= " << endl;

			std::cout << "---------------------------------------" << std::endl;

		}
		else if (command=="addms")
		{
			/*string addms_music_name;
			int addms_music_year;
			cin >> addms_music_name;
			cin >> addms_music_year;*/
            
			std::cout << "---------------------------------------" << std::endl;
			Artists.add_songTO_artist();
			cout << "======= Adding  Music was successful======= " << endl;

			std::cout << "---------------------------------------" << std::endl;

		}
		else if (command=="addp")
		{
			string addp_name;
			cin >> addp_name;
			PlayList addp(addp_name);
			std::cout << "---------------------------------------" << std::endl;
			PlayLists.add_to_sparse(addp);
			cout << "======= Adding  PlayList  was successful======= " << endl;
			std::cout << "---------------------------------------" << std::endl;

		}
		else if (command =="addmp")
		{
			int music_id_addmp, addmp_playlist_id;
			cin >> music_id_addmp >> addmp_playlist_id;
			std::cout << "---------------------------------------" << std::endl;
			PlayList pl_addmp =  PlayLists.find(addmp_playlist_id);
			My_Song *song_addmp = Artists.find_song_in_spars_id(music_id_addmp);
			pl_addmp.add_song(*song_addmp);
			PlayLists.find(addmp_playlist_id) = pl_addmp;
			cout << "======= Adding Music to PlayList  was successful======= " << endl;
			std::cout << "---------------------------------------" << std::endl;

		}
		else if (command=="searchp")
		{
			int searchp_id;
			cin >> searchp_id;
			std::cout << "---------------------------------------" << std::endl;

			PlayList searchp_pl =  PlayLists.find(searchp_id);
			cout << "PLaylist Name:" << searchp_pl.get_name() << endl
				<< "Playlist ID:" << searchp_pl.get_id() << endl;
			searchp_pl.songs_list();
			std::cout << "---------------------------------------" << std::endl;

		}
		else if (command =="searchm")
		{
			int playlist_id, music_id;
			cin >> playlist_id >> music_id;
			PlayList pl_searchm =  PlayLists.find(playlist_id);
			My_Song *music_searchm =  pl_searchm.find_song(music_id);
			std::cout << "======= Song  Information =======" << std::endl;
			cout << "Song Name:" << music_searchm->get_name() << endl;
			cout << "Song ID:" << music_searchm->get_id() << endl;
			cout << "Song Lyrics:" << music_searchm->get_lyrics() << endl;
			cout << "Song Year:" << music_searchm->get_year() << endl;
			std::cout << "---------------------------------------" << std::endl;

		}
		else if (command =="delm")
		{
			int playlist_id, music_id;
			cin >> playlist_id >> music_id;
			std::cout << "---------------------------------------" << std::endl;
			PlayList pl_searchm = PlayLists.find(playlist_id);
			pl_searchm.remove_song(music_id);
			PlayLists.find(playlist_id) = pl_searchm;
			cout << "======= Removing  PLayList from Playlist was successful======= "<< endl;
			std::cout << "---------------------------------------" << std::endl;


		}
		else if (command=="showp")
		{
			int playlist_id;
			cin >> playlist_id;
			std::cout << "---------------------------------------" << std::endl;
			cout << "PlayList Songs:" << endl;
			PlayList pl_showp = PlayLists.find(playlist_id);
			pl_showp.songs_list();
			std::cout << "---------------------------------------" << std::endl;

		}
		else if (command=="addqp")
		{
			int id_addqp;
			cin >> id_addqp;
			std::cout << "---------------------------------------" << std::endl;

			PlayList addqp_pl = PlayLists.find(id_addqp);
			Main_Queue.enqueue(addqp_pl);
			cout << "======= Adding  PlayList to Queue  was successful======= " << endl;
			std::cout << "---------------------------------------" << std::endl;


		}
		else if (command== "pop")
		{
			std::cout << "---------------------------------------" << std::endl;
			Main_Queue.dequeue();
			cout << "======= Removing  PLayList from Queue was successful======= " << endl;
			std::cout << "---------------------------------------" << std::endl;

		}
        else if (command=="search")
        {
            int search_id, search_m_id;
            cin >> search_id >> search_m_id;
            Artist search_artist = Artists.find(search_id);
            My_Song *search_song = search_artist.find_song_id(search_m_id);
            string suff = search_song->get_lyrics();
            //cout << search_song->get_lyrics();
            string word;
            cin >> word;
            string line;
            std::stringstream ss(suff);
            int flag = 0;
            while (getline(ss,line))
            {
                //cout << line << endl;
                Vector_<int> suffixArr = buildSuffixArray(line);
                int size_line = customSize(line);
                if (searchPattern(line,suffixArr,word)<0)
                {
                    flag += size_line + 1;
                    continue;
                }
                cout << "First index is :" << searchPattern(line, suffixArr, word)+flag << endl;
                break;

            } 
                
            

            //cout<<searchPattern()
        }
        else if (command=="countw")
        {
            int search_id, search_m_id;
            cin >> search_id >> search_m_id;
            Artist search_artist = Artists.find(search_id);
            My_Song* search_song = search_artist.find_song_id(search_m_id);
            string suff = search_song->get_lyrics();
            //cout << search_song->get_lyrics();
            string word;
            cin >> word;
            string line;
            std::stringstream ss(suff);
            int flag = 0;
            while (getline(ss, line))
            {
                //cout << line << endl;
                Vector_<int> suffixArr = buildSuffixArray(line);
                int size_line = customSize(line);
                if (count_pattern(line, suffixArr, word) > 0)
                {
                    flag += count_pattern(line,suffixArr,word);
                }
               

            }
            cout << "Number of words:" << flag << endl;
           
        }

	} while (command!="end");

}
//:mahdiifejjj fejjjjj
