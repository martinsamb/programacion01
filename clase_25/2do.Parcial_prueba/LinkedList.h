#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;


//Publicas
LinkedList* ll_newLinkedList(void);//-1
int ll_len(LinkedList* this);//-2
Node* test_getNode(LinkedList* this, int nodeIndex);//-3
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);//-4
int ll_add(LinkedList* this, void* pElement);//-5
void* ll_get(LinkedList* this, int index);//-6
int ll_set(LinkedList* this, int index,void* pElement);//-7
int ll_remove(LinkedList* this,int index);//-7
int ll_clear(LinkedList* this);//-8
int ll_deleteLinkedList(LinkedList* this);//-9
int ll_indexOf(LinkedList* this, void* pElement);//-10
int ll_isEmpty(LinkedList* this);//-11
int ll_push(LinkedList* this, int index, void* pElement);//-12
void* ll_pop(LinkedList* this,int index);//-13
int ll_contains(LinkedList* this, void* pElement);//-14
int ll_containsAll(LinkedList* this,LinkedList* this2);//-15
LinkedList* ll_subList(LinkedList* this,int from,int to);//-16
LinkedList* ll_clone(LinkedList* this);//-17
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);//-18




#endif // LINKEDLIST_H_INCLUDED
