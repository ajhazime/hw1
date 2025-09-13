#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

#include <iostream>

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

/**
 * Adds a new value to the back of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::push_back(const std::string &val)
{
  /*
  Does a node exist exist?
  if it does:
    does last == ARRSIZE?
    if it does:
      create a new node;
      point tail_->next to new node
      point tail_ to new node
      add value to first spot in new node
      increment last by 1
    if it doesnt:
      put value in last
      increase last by 1

  if it doesnt:
    call push_Front;
    return;
  increase size_ by 1;
  */

  if (!head_ || !tail_)
  {
    push_front(val); // size updated in push_front
    return;
  }
  if (tail_->last == ARRSIZE)
  {
    Item *newNode = new Item();
    newNode->prev = tail_;
    newNode->next = nullptr;
    tail_->next = newNode;
    tail_ = newNode;
    std::cout << tail_ << std::endl;
    tail_->first = 0;
    tail_->last = 0;
    tail_->next = newNode;
    tail_ = newNode;
    tail_->val[tail_->last] = val;
    tail_->last++;
    size_++;
    std::cout << "head after push back new item: " << head_ << " tail after push back: " << tail_ << std::endl;
    return;
  }
  else
  {
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  size_++;
  std::cout << "head after push back: " << head_ << " tail after push back: " << tail_ << std::endl;
  return;
}

/**
 * Removes a value from the back of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::pop_back()
{

  /*
  Check if there is a value at back
  if there is:
  does back == front+1?
  if it does:
    move tail to previous node
    update tail_->next to nullptr;
    delete the node
  if it doesn't:
    subtract 1 from back;

  decrease size_ by 1
*/
  if (!tail_)
  { // nothing to pop
    std::cout << "nothing to pop" << std::endl;
    return;
  }

  if (tail_->last > tail_->first)
  { // if there is more than 1 element in the list
    std::cout << "there is more than 1 element in the list" << std::endl;
    tail_->last--; // shift left one
    size_--;       // dec size
    if (tail_->last == tail_->first)
    { // If we need to remove the node
      std::cout << "we need to remove the node" << std::endl;
      Item *remove = tail_;
      tail_ = tail_->prev;
      if (tail_)
      {
        tail_->next == nullptr;
      }
      else
      {
        std::cout << "list is now empty" << std::endl;
        head_ = nullptr;
      }
      delete remove;
    }
    return;
  }

  // If the list is already empty
  std::cout << "the list is already empty" << std::endl;
  Item *remove = tail_;
  tail_ = tail_->prev;
  if (tail_)
  {
    tail_->next = nullptr;
  }
  else
  {
    head_ = nullptr;
  }
  delete remove;
}

/**
 * Adds a new value to the front of the list.
 * If there is room before the 'first' value in
 * the head node add it there, otherwise,
 * allocate a new head node.
 *   - MUST RUN in O(1)
 */
void ULListStr::push_front(const std::string &val)
{
  /*List is Empty*/
  if (!head_)
  {
    head_ = tail_ = new Item();          // Create new Node and set head and tail to it
    head_->prev = head_->next = tail_->prev = tail_->next = nullptr; // only 1 node, set prev and next to nullptr;
    head_->first = 0;                    // Set first index (0) as first
    head_->last = 1;                     // set last index to 1 since exclusive
    head_->val[head_->first] = val;      // update array at first/last spot.
    size_++;
    std::cout << "head_ after push front empty list = " << head_ << std::endl;
    std::cout << "tail_ after push front empty list = " << tail_ << std::endl;
    return;
  }

  /*Node exists*/
  /*
    check if first == last // this means there is no room
    if it is:
      create a new node and put item at the back of new array
    if it isn't:
      subtract 1 from first
      update value of the updated first "slot"

    increase size_ by 1
  */
  if (head_)
  {
    if (head_->first > 0)
    {                              //first elemetn isnt in 0th index 
      head_->first--;
      head_->val[head_->first] = val;  
      size_++;       
      return;
    }  
    
    Item *newNode = new Item();
    newNode->prev = nullptr;
    newNode->next = head_;
    newNode->first = ARRSIZE - 1;
    newNode->last = ARRSIZE;
    newNode->val[newNode->first] = val;

    head_->prev = newNode;
    head_ = newNode;
    size_++;
    std::cout << "head after push front: " << head_ << " tail after push front: " << tail_ << std::endl;
    return;
  }
  std::cout << "head after push front: " << head_ << " tail after push front: " << tail_ << std::endl;
  return;
}

/**
 * Removes a value from the front of the list
 *   - MUST RUN in O(1)
 */
void ULListStr::pop_front()
{
  if (!head_)
  { // list is empty before poping
    return;
  }
  std::cout << "size of pop front" << size_ << std::endl;
  std::cout << "tail before pop:" << tail_ << std::endl;
  head_->first++; // first index++
  size_--;        // decrease size of list

  if (head_->first == head_->last)
  {                      // If list is empty after pop action, move head to next node
    Item *temp = head_;  // store head
    head_ = head_->next; // traverse to next node
    if (head_)
    { // IF nodes remaining > 0
      head_->prev = nullptr;
    }
    else
    { // popping removed final node
      tail_ = nullptr;
      head_ = nullptr;
    }
    delete temp; // delete old head
  }
  std::cout << "head after popping: " << head_ << " tail after popping: " << tail_ << std::endl;
  return;
}

/**
 * Returns a const reference to the back element
 *   - MUST RUN in O(1)
 */
const std::string &ULListStr::back() const
{
  return tail_->val[tail_->last - 1];
}

/**
 * Returns a const reference to the front element
 *   - MUST RUN in O(1)
 */
const std::string &ULListStr::front() const
{
  return head_->val[head_->first];
}

/**
 * Returns a pointer to the item at index, loc,
 *  if loc is valid and NULL otherwise
 *   - MUST RUN in O(n)
 */
std::string *ULListStr::getValAtLoc(size_t loc) const
{
  /*

    if loc >= size_ OR head/tail doesnt exist:
      location is invalid
    Walk the list
    size_t countdown = loc;
      Item* temp = head_;
      difference = (temp->last - temp->first);
      if difference > countdown:
        temp->first + countdown = value to be returned
      else
        go to next node.
  */

  if (loc >= size_ || !head_)
  {
    return nullptr;
  }
  size_t countdown = loc;
  Item *temp = head_;
  size_t difference = 0;
  while (temp)
  {
    difference = (temp->last - temp->first);
    if (difference > countdown)
    {
      return &temp->val[temp->first + countdown];
    }
    else
    {
      countdown -= difference;
      temp = temp->next;
    }
  }

  return nullptr;
}

void ULListStr::set(size_t loc, const std::string &val)
{
  std::string *ptr = getValAtLoc(loc);
  if (ptr == NULL)
  {
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string &ULListStr::get(size_t loc)
{
  std::string *ptr = getValAtLoc(loc);
  if (ptr == NULL)
  {
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

const std::string &ULListStr::get(size_t loc) const
{
  std::string *ptr = getValAtLoc(loc);
  if (ptr == NULL)
  {
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while (head_ != NULL)
  {
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
