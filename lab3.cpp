#include <iostream>
#include <cctype>
void completion(double *arr, uint16_t n) {
	std::cout << "Enter elements \n";
	for (int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
		
	}
}
void sum(double * arr, uint16_t n) {
	double sum1 = 0;
	for (int i = 1; i < n; i +=2)
	{
		sum1 += arr[i];
	}
	std::cout << "Asddition result = " << sum1 << '\n';
}
void new_arr(double* arr, uint16_t n) {
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < 1 && arr[i] > -1)
		{
			arr[i] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] == 0)
			{
				arr[j] = arr[j + 1];
				arr[j + 1] = 0;
			}
		}
	}
	std::cout << "array = ";
	for (int i = 0; i < n; ++i)
	{
		std::cout << arr[i] << " ";
	}
	return;
}
void composition(double* arr, uint16_t n) {
	 double composition1 = 1;
	 int first = 0, last = 0, temp = 0, counter = 0;;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] < 0) {
			counter++;
		}
	}
	for (int i = 0; i < n; ++i)
	{

		if (arr[i] < 0) {
			last = i;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] < 0) {
			first = i;
			break;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (arr[i] > 0 )
		{
			temp++;

		}
	}
	for (int i = 0; i < n; ++i) {
		if (arr[i] < 0 && arr[i + 1] < 0)
		{
			temp = 1;

		}
	}
	if (temp == n )
	{
		std::cout << "No negative elements" <<'\n';
	}
	if (temp == n - 1) {
		std::cout << " 1 negatve element"<<'\n';
	}
	if(temp < n-1) {
		for (int i = first + 1; i < last; ++i)
		{
			composition1 *= arr[i];
		}
		std::cout << "Composition result = " << composition1 << '\n';
	}
}
void random(double * arr, uint16_t n) {
	double left_border = 0, right_border = 0;
	std::cout << "indicate boundaries from = ";
	std::cin >> left_border;
	std::cout << "before = ";
	std::cin >> right_border;
	if (left_border >= right_border) {
		std::cout << "incorrect range";
	}
	else {
		for (int i = 0; i < n; ++i)
		{   
			arr[i] = left_border + rand() * (right_border - left_border) / RAND_MAX;
		}
	}
	return;
}
void arr_dis(double* arr, uint16_t n) {
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
		}
	std::cout << '\n';
	return;
}
void fill_option(double * arr, uint16_t n) {
	size_t op;
	std::cout << "If you want to fill the array automatically, enter (0) and specify the bounds, otherwise enter (1) and fill the array \n";
	std::cin >> op;
	switch (op)
	{
	default:
		std::cout << " 0 and 1 !!!!";
		break;
	case 0: random(arr, n);
		break;
	case 1: completion(arr, n);
		break;
	}
}
int enter_n(uint16_t& n, const int16_t N) {
	std::cout << "Enter the number of array elements \n";
	std::cin >> n;
	if (n <= 0 || n > N) {
		std::cout << "incorrect data" << '\n';
		return enter_n(n, N);
	}
	else {
		return n;
	}
}
int main()
{  
	const int16_t N = 1000;
	double arr[N];
	uint16_t n = 0;
	srand(time(0));
	enter_n(n, N);
	fill_option(arr, n);
	arr_dis(arr, n);
	sum(arr, n);
	composition(arr, n);
	new_arr(arr, n);
	return 0;
}