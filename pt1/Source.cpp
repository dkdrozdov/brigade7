#include <stdio.h>

const char separator = ' ';
const char endchar = '.';

struct list {
	char elem;
	list *next;
	bool isHead;

	list(bool _isHead = false, list* _next = NULL, char _elem = 0) :
		elem(_elem), next(_next), isHead(_isHead) {}

	list* FindElem(char _elem, char stop) {
		list* current = isHead ? next : this;
		while (current != NULL && current->elem != _elem && current->elem != stop)
		{
			current = current->next;
		}

		return current == NULL || current->elem == stop ? NULL : current;
	}

	list* GetStringEnd() 
	{
		list *current = this;
		while (current->next != NULL && 
				current->next->elem != separator && 
				current->next->elem != endchar) {
			current = current->next;
		}
		return current;
	}

	list* GetPrevious(list *head)
	{
		list *current = head;

		while (current != NULL && current->next != this)
		{
			current = current->next;
		}
		return current;
	}

	void Print() {
		list *current = this->isHead ? next : this;
		while (current != NULL) {
			printf_s("%c", current->elem);
			current = current->next;
		}
	}

} *p = new list(true, new list);

int Input() 
{
	FILE* pFile;
	fopen_s(&pFile, "test.txt", "r");
	if (pFile == 0) {
		return 1;
	}
	list* current = p->next;
	if (pFile != NULL)
	{
		while (fread(&current->elem, sizeof(char), 1, pFile) == 1) {
			current->next = new list;
			current = current->next;
		}
	}
	fclose(pFile);

	return 0;
}

int main()
{
	if (Input() != 0)
		return 0;

	char c = 'x';
	list *matched = new list(true);
	list *prev = p;
	list *current = p->FindElem(c, endchar);
	
	while (current != NULL && current->elem != endchar) {
		while (current != NULL) {
			prev = current->GetPrevious(p);
			prev->next = current->next;
			current->next = NULL;
			matched->GetStringEnd()->next = current;
			current = prev->FindElem(c, separator);
		}

		matched->GetStringEnd()->next = prev->GetStringEnd()->next;
		prev->GetStringEnd()->next = matched->next;
		matched->next = NULL;
		current = prev->GetStringEnd()->next->FindElem(c, endchar);
	}

	p->Print();
	
	return getchar();
}