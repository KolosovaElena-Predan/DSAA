///Автор: Колосова Е.К.
///Класс описывающий тип очередь. Реализованы функции добавление в очередь(enqueue), 
///удаление из очереди(dequeue), проверка на то пустая ли очередь (isEmpty), 
/// возвращение размера(size), возвращение значения элемента из начала очереди(Peek),
/// очистка очереди (clear)
#include <assert.h>
#include <string>
#include "Queue.h"

///Тест функций класса Queue
void Test_queue_functions() {
	Test();

	//проверка работы isEmpty на пустой очереди
	Queue<int> S;
	assert(S.size() == 0);
	assert(S.isEmpty() == true);

	//добавляем элемент в очередь
	S.enqueue(5);
	assert(S.isEmpty() == false); //проверка, что стек теперь не пустой
	assert(S.size() == 1);//кол-во элементов стало равно 1

	//заполнение очереди
	S.enqueue(3);
	assert(S.size() == 2);
	S.enqueue(9);
	assert(S.size() == 3);
	S.enqueue(8);
	assert(S.size() == 4);
	S.enqueue(12);
	assert(S.size() == 5);

	//очередь имеет вид 5 3 9 8 12
	assert(S.Peek() == 5);
	assert(S.dequeue() == 5);
	assert(S.size() == 4);
	assert(S.Peek() == 3);
	assert(S.dequeue() == 3);
	assert(S.size() == 3);
	assert(S.Peek() == 9);
	assert(S.dequeue() == 9);
	assert(S.size() == 2);
	assert(S.Peek() == 8);
	assert(S.dequeue() == 8);
	assert(S.size() == 1);
	assert(S.Peek() == 12);
	assert(S.dequeue() == 12);
	assert(S.size() == 0);
	assert(S.isEmpty() == true);

	//проверка на то, что было брошено исключение при попытке 
	//удалить элемент из пустой очереди
	try {
		int a=S.dequeue();
		assert(false);
	}
	catch (std::invalid_argument const& ex) {
		std::string s = ex.what();
		assert(s == "The queue contains no elements");
	}
	
	//проверка на то, что было брошено исключение при попытке 
	//вернуть значение первого элемента из пустой очереди
	try {
		int a=S.Peek();
		assert(false);
	}
	catch (std::invalid_argument const& ex) {
		std::string s = ex.what();
		assert(s == "The queue contains no elements");
	}

	//проверка работы isEmpty на пустой очереди
	Queue<double> S1;
	assert(S1.size() == 0);
	assert(S1.isEmpty() == true);

	//добавляем элемент в очередь
	S1.enqueue(-5.7);
	assert(S1.isEmpty() == false); //проверка, что стек теперь не пустой
	assert(S1.size() == 1);//кол-во элементов стало равно 1

	//заполнение очереди
	S1.enqueue(3.233);
	assert(S1.size() == 2);
	S1.enqueue(23.9);
	assert(S1.size() == 3);
	S1.enqueue(8.53);
	assert(S1.size() == 4);
	S1.enqueue(121.2);
	assert(S1.size() == 5);

	S1.Clear();
	assert(S1.size() == 0);

	//проверка на то, что было брошено исключение при попытке 
	//удалить элемент из пустой очереди
	try {
		int a = S1.dequeue();
		assert(false);
	}
	catch (std::invalid_argument const& ex) {
		std::string s = ex.what();
		assert(s == "The queue contains no elements");
	}

	//проверка на то, что было брошено исключение при попытке 
	//вернуть значение первого элемента из пустой очереди
	try {
		int a = S1.Peek();
		assert(false);
	}
	catch (std::invalid_argument const& ex) {
		std::string s = ex.what();
		assert(s == "The queue contains no elements");
	}


}
