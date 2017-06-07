#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP

#include <cstddef>
#include <iterator>

//List.hpp

template <typename T> 
class List;

template <typename T>
struct ListNode
{
    //default constructor
    ListNode() : 
        m_value (), 
        m_prev(nullptr), 
        m_next(nullptr) {}

    //user defined constructor
    ListNode(T const& v, ListNode* prev, ListNode* next) : 
        m_value(v), 
        m_prev(prev), 
        m_next(next) {}

    T m_value;
    ListNode* m_prev;
    ListNode* m_next;
};


template<typename T> 
struct ListConstIterator
{
    friend class List <T>;
public:
    // not implemented yet
private:
    ListNode<T>* m_node = nullptr;
};


template <typename T>
struct ListIterator
{
typedef ListIterator<T> Self;
typedef T value_type;
typedef T* pointer;
typedef T& reference;
typedef ptrdiff_t difference_type;
typedef std::forward_iterator_tag iterator_category;
friend class List <T>;

ListIterator():
    m_node()
    {}

ListIterator(ListNode<T>* n):
    m_node(n)
    {}

reference operator *() const{
    return m_node->m_value;
}

pointer operator ->() const{
    return &(m_node->m_value);
}

Self& operator++(){        // ++i
    *this=next();
    return *this;
} 

Self operator++(int){      // i++
    Self temp = *this;
    ++ *this;
    return temp;
}

bool operator==(const Self& x) const{
    return(m_node == x.m_node);
}

bool operator!=(const Self& x) const{
    return(m_node != x.m_node);
}

Self next() const{
    if(m_node)
        return ListIterator(m_node->m_next);
    else
        return ListIterator(nullptr);
}

private:
// The Node the iterator is pointing to
ListNode<T>* m_node = nullptr;
};


template <typename T> 
class List
{
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef ListIterator<T> iterator;
    typedef ListConstIterator<T> const_iterator;

    friend class ListIterator<T>;
    friend class ListConstIterator<T>;

    List():                         //Default-Konstruktor
        m_size(),
        m_first(),
        m_last(){}

    List<T>(List<T> const& liste): // Copy-Konstruktor
	m_size(0), 
	m_first(nullptr), 
	m_last(nullptr) {
    for (auto it=liste.begin(); it != liste.end(); it++){
			push_back(*it);
		}
	}

    List<T>(List<T> && liste):      //Move-Konstruktor
        m_size(liste.m_size),
	    m_first(liste.m_first),
        m_last(liste.m_last)
	{
		liste.m_size=0;
		liste.m_first=nullptr;
		liste.m_last=nullptr;
	}


    bool empty() const{
        return (m_first == nullptr);
    }

    std::size_t size() const{
        return m_size;
    }

    T& front(){
        return m_first->m_value;
    }
    
    T& back(){
        return m_last->m_value;
    }

    void push_front(T const& node){
        if(empty()){
			ListNode <T>* newnode = new ListNode<T> {node, nullptr, nullptr};
			m_first=newnode;
			m_last=newnode;
		}
        else
		{
			ListNode <T>* newnode= new ListNode<T>{node, nullptr, m_first};
			m_first->m_prev=newnode;
			m_first=newnode;
		}
		++m_size;
    }

    void push_back(T const& node){
		if(empty())
		{
			ListNode <T>* newnode= new ListNode<T>{node, nullptr, nullptr};
			m_first=newnode;
			m_last=newnode;
		}
        else
		{
			ListNode <T>* newnode= new ListNode<T>{node, m_last, nullptr};
			m_last->m_next=newnode;
			m_last=newnode;
		}
		++m_size;
    }

    void pop_front(){
        if(m_size==1)
		{
			delete m_first;
			m_first=nullptr;
			m_last=nullptr;
			--m_size;
		}else if(!empty())
		{
			auto temp = m_first->m_next;
			temp->m_prev=nullptr;
            delete m_first;
			m_first=temp;
			--m_size;
		}
    }

    void pop_back(){
        if(m_size==1){
            pop_front();
        }
        else if (!empty())
        {
            auto tmp = m_last->m_prev;
            delete m_last;
            tmp->m_next=nullptr;
            m_last=tmp;
            --m_size;
        }
    }

void clear(){
    while (!empty()){
        pop_front();
    }
}

~List<T>(){
    clear();
    }

iterator begin() const {
	return m_first;
	}

iterator end() const{
	return iterator();
	}

iterator insert(iterator it, T const& v){
	if (it==begin()){
    	push_front(v);
		return begin();
	}
	else if(it==end()){
		push_back(v);
		return end();
	}
	else {
		ListNode<T>* newnode= new ListNode<T>{v, it.prev().m_node, it.m_node};
		it.prev().m_node->m_next = newnode;
		it.m_node->m_prev = newnode;
		m_size++;
		return { newnode };
	}
}

void reverse(){
	for (auto n=m_last; n!=nullptr; n=n->m_next){
		std::swap(n->m_prev, n->m_next);
	}
	std::swap(m_first, m_last);
}

private:
    std::size_t m_size = 0;
    ListNode<T>* m_first = nullptr ;
    ListNode<T>* m_last = nullptr ;
};

template <typename T>
bool operator == (List<T> const& rhs, List<T> const& lhs){

ListIterator<T> itr = rhs.begin(); 
ListIterator<T> itl = lhs.begin(); 
bool ergebnis = true;
	
if(rhs.size() != lhs.size()) { ergebnis=false; }
else{
	unsigned int count =0;
	while ((ergebnis==true)&(count<(rhs.size()))){
		if(*itr != *itl){ergebnis = false;}
		else {itr++; itl++;}
		count++;
		}
	}
return ergebnis;
}


template <typename T>
List <T> reverse(List <T> list){
	list.reverse();
	return list;
}

# endif // # define BUW_LIST_HPP