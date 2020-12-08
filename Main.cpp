#include <iostream>

class ListItem {
  
  private:

    const char* item;
    ListItem* next = nullptr;
    
  public:
    
    ListItem(const char *newItem) {
      item = newItem;
      next = nullptr;
    }

    ListItem* nextItem() {
      return next;
    }

    void setNextItem(ListItem* new_next) {
      next = new_next;
    }

    void setFirstItem(ListItem* new_first, ListItem* first){
       first = new_first;
    }

    const char* view() {
      return item;
    }

  

};

class LinkedList {

  private:

    ListItem* first_item;
    int list_length;
  
    void deleteItem(ListItem* parent, ListItem* item) {
      parent->setNextItem(item->nextItem());
      delete item;
    }

  public:

    LinkedList(const char *newItem) {
      first_item = new ListItem(newItem);
      list_length = 1;
    }

    void addListItem(const char *newItem) {
      ListItem* new_item = new ListItem(newItem);
      ListItem* current_item = first_item;
      ListItem* next_item = first_item->nextItem();
      while (next_item != nullptr) {
        current_item=next_item;
        next_item = current_item->nextItem();
      }
      current_item->setNextItem(new_item);
      list_length += 1;
    }

  

    int length() {
      return list_length;
    }

    void outputLength() {
      std::cout << length() << std::endl;
    }

    void outputList() {
      std::cout << first_item->view() << std::endl;
      ListItem* next_item = first_item->nextItem();
      while (next_item != nullptr) {
        std::cout << next_item->view() << std::endl;
        next_item = next_item->nextItem();
      }
    }

    void outputFirstItem() { // outputs the first item of the list
      std::cout << first_item->view() << std::endl;
     }

    void deleteSecondItem() { // deletes second item and moves third to second
      ListItem* next_item = first_item->nextItem();
      ListItem* new_next = next_item->nextItem();
      delete next_item;
      first_item->setNextItem(new_next);
     }

    

     

    
    


 

   

};

int main() {
  LinkedList l("sam");
  l.outputList();
  l.outputLength();
  l.addListItem("bob");
  l.addListItem("terry");
  l.outputList();
  l.outputLength();
  l.outputFirstItem();
  l.deleteSecondItem();
  l.outputList();
  
  
  
}