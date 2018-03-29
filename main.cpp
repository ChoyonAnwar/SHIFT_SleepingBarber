#include "std_lib_facilities.h"
#include <thread>
#include <deque>
#include <mutex>

deque<int> id;							// the queue line for customers
mutex mu;
condition_variable cond;

void Customer(int M) {					// produces Customers
	int customer = 1;
	while (true)
	{
		unique_lock<mutex> locker(mu);
		if (id.size() < M)				// (< 4) creates 3 waiting seats
		{
			id.push_front(customer);
		}
		else
		{
			cout << "Customer " << customer << " is leaving." << endl;
		}
		locker.unlock();
		cond.notify_one();
		this_thread::sleep_for(chrono::seconds(3));
		customer++;
	}
}

void Barbershop() {						// uses Customer
	int cutting = 0;
	while (true)
	{
		unique_lock<mutex> locker(mu);
		cond.wait(locker);
		cutting = id.back();
		id.pop_back();
		locker.unlock();
		cout << "Barber got customer: " << cutting << endl;
		cout << "Waiting room: ";
		for (int i = 0; i < id.size(); i++)
		{
			cout << id[i] << " ";
		}
		cout << endl << endl;
		this_thread::sleep_for(chrono::seconds((rand() % 5) + 1));		// I use rand() to make the random number generation quick although I remember being told that it is not the best method.
	}
}


int main()
{
	int M;
	cout << "Number of seats: "; cin >> M; cout << endl;

	cout << "Barber is sleeping." << endl;			// The start of the program barber is sleeping and waiting room empty.
	cout << "Waiting room: " << endl << endl;

	thread t1(Customer, M+1);							// Making the two functions into threads. 
	thread t2(Barbershop);

	t1.join();										// Joining the threads to run together. 
	t2.join();

	keep_window_open();
	return 0;
}
