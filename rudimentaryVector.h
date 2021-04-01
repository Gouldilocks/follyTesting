//
// Created by christian on 3/31/21.
//

#ifndef FOLLYTESTING_RUDIMENTARYVECTOR_H
#define FOLLYTESTING_RUDIMENTARYVECTOR_H
namespace bad {
	template<class t>
	class rudimentaryVector {
	public:
		/**
		 * default constructor. Initializes cap to 10
		 */
		rudimentaryVector<t> () {
			// set default size of 10
			size = 0;

			// dynamically allocate data
			this->data = new t[10];
		}

		/**
		 * pre-sized constructor. Initializes size to start
		 * @param start - the size which the vector will start at
		 */
		rudimentaryVector<t> (const int &start) {
			// set the size of the vector
			this->size = 0;

			// dynamically allocate data
			this->data = new t[start];
		}

		/**
		 * copy constructor. Initializes size to the size of the
		 * parameter, and copies all elements dynamically allocating each
		 * @param copy - the vector desired to be copied
		 */
		rudimentaryVector<t> (const rudimentaryVector<t> &copy) {
			// copy the size
			this->size = copy.size;

			// dynamically allocate data
			this->data = new t[copy.getCapacity()];

			// copy all elements from "copy"
			for (int i = 0; i < size; ++i) {
				this->data[ i ] = copy.data[ i ];
			}
		}

		/**
		 * destructor. deletes all dynamically allocated memory
		 */
		~rudimentaryVector () {
			// delete the array "data"
			delete[] data;
		}

		/**
		 * assignment operator. dynamically copies all elements from rhs and puts them into
		 * this object, and copies the size as well
		 * @param rhs - This is the source vector from which the copying will take place.
		 */
		rudimentaryVector<t> &operator= (const rudimentaryVector<t> &rhs) {
			// delete previously dynamically allocated array
			delete[] data;

			// set the new size of this vector
			this->size = rhs.size;

			// reallocate data dynamically
			this->data = new t[rhs.getCapacity()];

			// copy over each of the elements from "rhs"
			for (int i = 0; i < size; ++i) {
				this->data[ i ] = rhs.data[ i ];
			}
		}

		/**
		 * quick function which calculates the total capacity of the vector
		 * @returns the maximum number of elements which can be put into "data"
		 */
		int getCapacity () {
			return (sizeof (data) / sizeof (data[ 0 ]));
		}

		/**
		 * function which doubles the capacity of the vector
		 * Only called when size is the same as capacity of the array
		 */
		void resize () {
			// dynamically allocate a new array
			t *newArray = new t[2 * getCapacity()];

			// copy over the old elements
			for (int i = 0; i < size; ++i) {
				newArray[ i ] = data[ i ];
			}

			// delete the old array
			delete[] data;

			// make data point to the new array
			data = newArray;
		}

		/**
		 * pushes back an element "push" to the back of the vector
		 * @param push - new element to be added to the vector
		 */
		void push_back (const t &push) {
			// check that there is space in the vector, if there is not, then resize
			if (size == getCapacity ()) {
				resize ();

				// if there is space in the vector, put the new element in and increment size
			} else {
				data[ size++ ] = push;
			}
		}

		/**
		 * insertion operator. Gets an element at a certain index
		 * @param index - the index where the element will be gathered from
		 * @return the element in the vector at "index"
		 */
		t &operator[] (const int &index) {
			// return the element at specified index
			return data[ index ];
		}

		/**
		 * removes an element at a specified index
		 * @param remove - the index which the user wishes to remove
		 */
		void remove (const int &remove) {
			// initialize the new array
			t *newArr = new t[getCapacity ()];

			// copy all elements exept the remove one
			for (int i = 0, j = 0; i < size && j < size - 1; ++i, ++j) {
				if (i == remove) continue;
				newArr[ j ] = data[ i ];
			}

			// update to new size
			size--;

			// delete the old data
			delete[]data;

			// make data point to the new array
			data = newArr;
		}
		/**
		 * clears the array of all elements, making it empty again. Resets initial size
		 */
		 void clear(){
		 	// delete the current data
		 	delete[] this->data;

		 	// reset size
		 	this->size = 0;

		 	// make the new vector
		 	this->data = new t[10];
		 }
	private:
		t *data;/*> the array which will be manipulated though the life of the vector*/
		int size;/*> the current number of elements in the vector*/
	};

}
#endif //FOLLYTESTING_RUDIMENTARYVECTOR_H
