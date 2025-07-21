#include "SongList.h"

Node::Node(My_Song& song):song_data(song),next(nullptr)
{
}

Node::~Node()
{
	next = nullptr;
}

My_Song& Node::get_song()
{
	return song_data;
}

void Node::set_song(const My_Song songdata)
{
	song_data = songdata;
}

Node* Node::get_next() const
{
	return next;
}

void Node::Set_next(Node* nextnode)
{
	next = nextnode;
}

Song_list::Song_list():head(nullptr),tail(nullptr)
{
}

//Song_list::~Song_list()
//{
//}

void Song_list::add_song(My_Song song)
{
	Node* new_node = new Node(song);
	if (!head)
	{
		head = tail = new_node;
	}
	else {
		tail->Set_next(new_node);
		tail = new_node;

	}
}

bool Song_list::remove_song(int songID)
{
	Node* current = head;
	Node* previous = nullptr;
	while (current)
	{

		if (current->get_song().get_id() == songID)
		{
			if (previous)
			{
				previous->Set_next(current->get_next());
			}
			else
				head = head->get_next();
			if (current == tail)
			{
				tail = previous;
			}
			delete current;
			return true;
		}
		previous = current;
		current = current->get_next();
	}
	return false;

}


My_Song* Song_list::find_song_(string& song_name_) 
{
	Node* current = head;
	while (current)
	{
		if (current->get_song().get_name() == song_name_)
		{
			return const_cast<My_Song*>(&current->get_song());
		}
		current = current->get_next();
	}
	return nullptr;
}

My_Song* Song_list::find_song_id(int song_id_)
{
	Node* current = head;
	while (current)
	{
		if (current->get_song().get_id() == song_id_)
		{
			return const_cast<My_Song*>(&current->get_song());
		}
		current = current->get_next();
	}
	return nullptr;
}

void Song_list::display() const
{	
	Node* current = head;
	
	while (current!=nullptr)
	{
		My_Song& song = current->get_song();
		cout << "Song name:" << song.get_name() <<
			"\tsong id:" << song.get_id() << "\t" <<
			"song year:" << song.get_year() << endl <<
			"song lyrisc:" << song.get_lyrics() << endl;
		current = current->get_next();	

	}
}

void Song_list::quick_sort()
{
	head = qiuck_sort_recur(head, get_tail(head));
}

Node* Song_list::partition(Node* start, Node* end, Node** newhead, Node** newend)
{
	/*Node* pivot = end;
	Node* prev = nullptr;
	Node* current = start;
	Node* tai = pivot;
	while (current!= pivot)
	{
		if (current->get_song().get_year()< pivot->get_song().get_year())
		{
			if (*newhead == nullptr)
			{
				*newhead = current;
			}
			prev = current;
			current = current->get_next();
		}
		else
		{
			if (prev)
			{
				prev->Set_next(current->get_next());
			}
			Node* temp = current->get_next();
			current->Set_next(nullptr);
			tai->Set_next(current);
			tai = current;
			current = temp;
		}
	}
	if (newhead == nullptr)
	{
		*newhead = pivot;
	}
	*newend = tai;
	return pivot;*/
	Node* pivot = end;
	Node* prev = nullptr;
	Node* current = start;
	Node* tai = pivot;

	while (current != pivot) // بررسی نال بودن current
	{
		if (current->get_song().get_year() < pivot->get_song().get_year())
		{
			if (*newhead == nullptr)
			{
				*newhead = current;
			}
			prev = current;
			current = current->get_next();
		}
		else
		{
			if (prev) 
			{
				prev->Set_next(current->get_next());
			}
			Node* temp = current->get_next();
			current->Set_next(nullptr);
			tai->Set_next(current);
			tai = current;
			current = temp;
		}
	}

	if (*newhead == nullptr) 
	{
		*newhead = pivot;
	}

	*newend = tai;
	return pivot;
}

Node* Song_list::qiuck_sort_recur(Node* start, Node* end)
{
	/*if (!start || start==nullptr)
	{
		return start;
	}
	Node* newhead = nullptr;
	Node* newend = nullptr;
	Node* pivot = partition(start, end, &newhead, &newend);
	if (newhead!= pivot)
	{
		Node* temp = newhead;
		while (temp->get_next()!= pivot)
		{
			temp = temp->get_next();
		}
		temp->Set_next(nullptr);
		newhead = qiuck_sort_recur(newhead, temp);
		temp = get_tail(newhead);
		temp->Set_next(pivot);
	}
	pivot->Set_next(qiuck_sort_recur(pivot->get_next(), newend));
	return newhead;*/
	if (!start || start == nullptr) 
	{
		return start;
	}

	Node* newhead = nullptr;
	Node* newend = nullptr;

	Node* pivot = partition(start, end, &newhead, &newend);

	if (newhead != pivot) 
	{
		Node* temp = newhead;
		while ( temp->get_next() != pivot) 
		{
			temp = temp->get_next();
		}

		

			temp->Set_next(nullptr);
		

		newhead = qiuck_sort_recur(newhead, temp);

		
		
			//temp = get_tail(newhead);
			temp = newhead;

			//if (temp != nullptr) 
			//{
			//	temp->Set_next(pivot);
			//}
			while (temp->get_next())
			{
				temp = temp->get_next();
			}
			temp->Set_next(pivot);
	}
	pivot->Set_next(qiuck_sort_recur(pivot->get_next(), newend));
	return newhead;
}

	



Node* Song_list::get_tail(Node* curr)
{
	while (curr != nullptr && curr->get_next() != nullptr) {
		curr = curr->get_next();
	}
	return curr;
}

//Node* Song_list::partition(Node* head_, Node* tail_)
//{
//	Node* pivot = head_;
//	Node* pre = head_;
//	Node* curr = head_;
//
//	while (curr!= tail_->get_next())
//	{
//		if (curr->get_song().get_id() < pivot->get_song().get_id())
//		{
//			
//		}
//	}
//}
