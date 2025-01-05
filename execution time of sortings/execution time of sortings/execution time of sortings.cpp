#include<iostream>
#include<chrono>
using namespace std;


// Providing all the sortings




//selection sort 



// (wrong code)

void wrong_select_sort(int ar[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ar[i] > ar[j]) {
				swap(ar[i], ar[j]);
			}
		}
	}
}



// (correct code)

void correct_select_sort(int ar[],int n) {

	for (int i = 0; i < n - 1; i++) {
		int min_idx = i;

		for (int j = i + 1; j < n; j++) {
			if (ar[j] < ar[min_idx]) {
				min_idx = j;

			}
		}

		if (ar[i] > ar[min_idx]) {
			swap(ar[i], ar[min_idx]);
		}
	}
}


//insertion sort

void insertion_sort(int ar[],int n) {
	int x;
	int j;

	for (int i = 1; i < n; i++) {
		j = i - 1;
		x = ar[i];

		while (j > -1 && ar[j] > x) {				
			ar[j + 1] = ar[j];
			j--;
		}

		ar[j + 1] = x;
	}
}




//bubble sort

void bubble_sort(int ar[], int n) {
	int flag;

	for (int i = 0; i < n - 1; i++) {
		flag = 0;
		for (int j = 0; j < n - 1 - i; j++) {
			if (ar[j] > ar[j + 1]) {
				swap(ar[j], ar[j + 1]);
				flag = 1;

			}
		}

		if (flag == 0) {
			break;
		}
	}
}


	const int n = 5;

	int main() {


		double sum_rand_wrongselect = 0;
		double sum_asc_wrongselect = 0;
		double sum_des_wrongselect = 0;
		double sum_rand_correctselect = 0;
		double sum_asc_correctselect = 0;
		double sum_des_correctselect = 0;
		double sum_rand_bubble = 0;
		double sum_asc_bubble = 0;
		double sum_des_bubble = 0;
		double sum_rand_insertion = 0;
		double sum_asc_insertion = 0;
		double sum_des_insertion = 0;


		for (int i = 0; i < 10; i++) {



			//Making an array for random values
			int rand_ar[n];

			for (int i = 0; i < n; i++) {
				rand_ar[i] = rand() % 1000;

			}



			//making an array of ascending numbers



			int asc_array[n];
			int num = 0;
			for (int i = 0; i < n; i++) {
				asc_array[i] = num++;
			}



			//making an arary for descending numbers

			int des_array[n];
			num = n - 1;

			for (int i = 0; i < n; i++) {
				des_array[i] = num--;
			}



			//making duplicates for all the sortings
			int copy_rand1[n];
			int copy_rand2[n];
			int copy_rand3[n];
			int copy_rand4[n];
			int copy_rand5[n];

			int copy_asc1[n];
			int copy_asc2[n];
			int copy_asc3[n];
			int copy_asc4[n];

			int copy_des1[n];
			int copy_des2[n];
			int copy_des3[n];
			int copy_des4[n];









			for (int i = 0; i < n; i++) {


				copy_rand1[i] = rand_ar[i];


				copy_rand2[i] = rand_ar[i];


				copy_rand3[i] = rand_ar[i];


				copy_rand4[i] = rand_ar[i];



				copy_asc1[i] = asc_array[i];

				copy_asc2[i] = asc_array[i];

				copy_asc3[i] = asc_array[i];

				copy_asc4[i] = asc_array[i];



				copy_des1[i] = des_array[i];
				copy_des2[i] = des_array[i];
				copy_des3[i] = des_array[i];
				copy_des4[i] = des_array[i];


			}


		

			//Finding the execution time as given in the link sir provided us with


			//for selection sort ( wrong )


			//random array

			{
				auto start = chrono::steady_clock::now();


				wrong_select_sort(copy_rand1, n);


				auto end = chrono::steady_clock::now();

				chrono::duration<double> elapsed_seconds{ end - start };

				cout << "wrong select sort took " << elapsed_seconds.count() << " on random array " << endl << endl;
				sum_rand_wrongselect += elapsed_seconds.count();
				cout << "-----------------------------------------------------------------------------------------------------" << endl;

			}

			// On ascending array
			{
				auto start = chrono::steady_clock::now();


				wrong_select_sort(copy_asc1, n);


				auto end = chrono::steady_clock::now();

				chrono::duration<double> elapsed_seconds{ end - start };

				cout << "wrong select sort took " << elapsed_seconds.count() << " on ascending  array " << endl << endl;

				sum_asc_wrongselect += elapsed_seconds.count();

				cout << "-----------------------------------------------------------------------------------------------------" << endl;

			}

			//On decending array

			{
				auto start = chrono::steady_clock::now();


				wrong_select_sort(copy_des1, n);


				auto end = chrono::steady_clock::now();

				chrono::duration<double> elapsed_seconds{ end - start };

				cout << "wrong select sort took " << elapsed_seconds.count() << " On descending array " << endl << endl;

				sum_des_wrongselect += elapsed_seconds.count();

				cout << "-----------------------------------------------------------------------------------------------------" << endl;

			}


			//now doing all of this on the correct selection sort


			//random array

			{
				auto start = chrono::steady_clock::now();


				correct_select_sort(copy_rand2, n);


				auto end = chrono::steady_clock::now();

				chrono::duration<double> elapsed_seconds{ end - start };

				cout << "correct select sort took " << elapsed_seconds.count() << " On random array " << endl << endl;

				sum_rand_correctselect += elapsed_seconds.count();

				cout << "-----------------------------------------------------------------------------------------------------" << endl;

			}



			// ascneding array

			{
				auto start = chrono::steady_clock::now();


				correct_select_sort(copy_asc2, n);


				auto end = chrono::steady_clock::now();

				chrono::duration<double> elapsed_seconds{ end - start };

				cout << "correct select sort took " << elapsed_seconds.count() << " On ascending array " << endl << endl;

				sum_asc_correctselect += elapsed_seconds.count();

				cout << "-----------------------------------------------------------------------------------------------------" << endl;

			}


			//descending array
			{
				auto start = chrono::steady_clock::now();


				correct_select_sort(copy_des2, n);


				auto end = chrono::steady_clock::now();

				chrono::duration<double> elapsed_seconds{ end - start };

				cout << "correct select sort took " << elapsed_seconds.count() << " On descending array " << endl << endl;

				sum_des_correctselect += elapsed_seconds.count();

				cout << "-----------------------------------------------------------------------------------------------------" << endl;


			}

			//Now doing this on bubble sort


			//random array

			{
				auto start = chrono::steady_clock::now();


				bubble_sort(copy_rand3, n);


				auto end = chrono::steady_clock::now();

				chrono::duration<double> elapsed_seconds{ end - start };

				cout << "bubble sort took " << elapsed_seconds.count() << " On random array " << endl << endl;

				sum_rand_bubble += elapsed_seconds.count();

				cout << "-----------------------------------------------------------------------------------------------------" << endl;


			}
			//ascending array
			{

				auto start = chrono::steady_clock::now();


				bubble_sort(copy_asc3, n);


				auto end = chrono::steady_clock::now();

				chrono::duration<double> elapsed_seconds{ end - start };

				cout << "bubble sort took " << elapsed_seconds.count() << " On ascending array " << endl << endl;

				sum_asc_bubble += elapsed_seconds.count();

				cout << "-----------------------------------------------------------------------------------------------------" << endl;


			}
			//descending array
			{
				auto start = chrono::steady_clock::now();


				bubble_sort(copy_des3, n);


				auto end = chrono::steady_clock::now();

				chrono::duration<double> elapsed_seconds{ end - start };

				cout << "bubble sort took " << elapsed_seconds.count() << " On descendig array " << endl << endl;
				sum_des_bubble += elapsed_seconds.count();

				cout << "-----------------------------------------------------------------------------------------------------" << endl;

			}


			//For insertion Sort


			//for random array

			{
				auto start = chrono::steady_clock::now();


				insertion_sort(copy_rand4, n);


				auto end = chrono::steady_clock::now();

				chrono::duration<double> elapsed_seconds{ end - start };

				cout << "Insertion sort took " << elapsed_seconds.count() << " On random array " << endl << endl;

				sum_rand_insertion += elapsed_seconds.count();

				cout << "-----------------------------------------------------------------------------------------------------" << endl;

			}


			//for ascending array

			{
				auto start = chrono::steady_clock::now();


				insertion_sort(copy_asc4, n);


				auto end = chrono::steady_clock::now();

				chrono::duration<double> elapsed_seconds{ end - start };

				cout << "Insertion sort took " << elapsed_seconds.count() << " On ascending array " << endl << endl;

				sum_asc_insertion += elapsed_seconds.count();

				cout << "-----------------------------------------------------------------------------------------------------" << endl;

			}



			//for descending array
			{
				auto start = chrono::steady_clock::now();


				insertion_sort(copy_des4, n);


				auto end = chrono::steady_clock::now();

				chrono::duration<double> elapsed_seconds{ end - start };

				cout << "Insertion sort took " << elapsed_seconds.count() << " On descending array " << endl << endl;
				sum_des_insertion += elapsed_seconds.count();

				cout << "-----------------------------------------------------------------------------------------------------" << endl;

			}

		}


		cout << "The average time for the wrong select sort on random array is " << sum_rand_wrongselect / 10 << endl;

		cout << "The average time for the wrong select sort on ascending array is " << sum_asc_wrongselect / 10 << endl;


		cout << "The average time for the wrong select sort on descending array is " << sum_des_wrongselect / 10 << endl;


		cout << "The average time for the correct select sort on random array is " << sum_rand_correctselect / 10 << endl;


		cout << "The average time for the correct select sort on ascending array is " << sum_asc_correctselect / 10 << endl;


		cout << "The average time for the correct select sort on descending array is " << sum_des_correctselect / 10 << endl;


		cout << "The average time for the bubble sort on random array is " << sum_rand_bubble / 10 << endl;


		cout << "The average time for the bubble sort on ascending array is " << sum_asc_bubble / 10 << endl;


		cout << "The average time for the bubble sort on descending array is " << sum_des_bubble / 10 << endl;


		cout << "The average time for the insertion sort on random array is " << sum_rand_insertion / 10 << endl;


		cout << "The average time for the insertion sort on ascending array is " << sum_asc_insertion / 10 << endl;


		cout << "The average time for the insertion sort on desending array is " << sum_des_insertion / 10 << endl;




		



	}